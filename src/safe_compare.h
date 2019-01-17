#ifndef ALGORITHM_LIBRARY_SRC_SAFE_COMPARE_H_
#define ALGORITHM_LIBRARY_SRC_SAFE_COMPARE_H_

#include <stddef.h> // size_t
#include <stdint.h> // int8_t

#include <type_traits> // std::false_type

#include "src/type_traits.h"

namespace rtc {

namespace safe_cmp_impl {
template <size_t N>
// typedef integral_constant<bool,false> false_type;
struct LargerIntImpl : std::false_type {};

template <>
struct LargerIntImpl<sizeof(int8_t)> : std::true_type {
  using type = int16_t;
};

template <>
struct LargerIntImpl<sizeof(int16_t)> : std::true_type {
  using type = int32_t;
};

template <>
struct LargerIntImpl<sizeof(int32_t)> : std::true_type {
  using type = int64_t;
};


template <typename T1, typename T2>
struct LargerInt
    : LargerIntImpl<sizeof(T1) < sizeof(T2) || sizeof(T1) < sizeof(int*)
                        ? sizeof(T1)
                        : 0> {};

template <typename T>
constexpr typename std::make_unsigned<T>::type MakeUnsigned(T a) {
  return static_cast<typename std::make_unsigned<T>::type>(a);
}

// Overload for when both T1 and T2 have the same signedness.
template <typename Op,
          typename T1,
          typename T2,
          typename std::enable_if<std::is_signed<T1>::value ==
                                  std::is_signed<T2>::value>::type* = nullptr>
constexpr bool Cmp(T1 a, T2 b) {
  return Op::Op(a, b);
}

// Overload for signed - unsigned comparison that can be promoted to a bigger
// signed type.
template <typename Op,
          typename T1,
          typename T2,
          typename std::enable_if<std::is_signed<T1>::value &&
                                  std::is_unsigned<T2>::value &&
                                  LargerInt<T2, T1>::value>::type* = nullptr>
constexpr bool Cmp(T1 a, T2 b) {
  return Op::Op(a, static_cast<typename LargerInt<T2, T1>::type>(b));
}

// Overload for unsigned - signed comparison that can be promoted to a bigger
// signed type.
template <typename Op,
          typename T1,
          typename T2,
          typename std::enable_if<std::is_unsigned<T1>::value &&
                                  std::is_signed<T2>::value &&
                                  LargerInt<T1, T2>::value>::type* = nullptr>
constexpr bool Cmp(T1 a, T2 b) {
  return Op::Op(static_cast<typename LargerInt<T1, T2>::type>(a), b);
}

// Overload for signed - unsigned comparison that can't be promoted to a bigger
// signed type

template <typename Op,
          typename T1,
          typename T2,
          typename std::enable_if<std::is_signed<T1>::value &&
                                  std::is_unsigned<T2>::value &&
                                  !LargerInt<T2, T1>::value>::type* = nullptr>
constexpr bool Cmp(T1 a, T2 b) {
  return a < 0 ? Op::Op(-1, 0) : Op::Op(safe_cmp_impl::MakeUnsigned(a), b);
}

// Overload for unsigned - signed comparison that can't be promoted to a bigger
// signed type.
template <typename Op,
          typename T1,
          typename T2,
          typename std::enable_if<std::is_unsigned<T1>::value &&
                                  std::is_signed<T2>::value &&
                                  !LargerInt<T1, T2>::value>::type* = nullptr>
constexpr bool Cmp(T1 a, T2 b) {
  return b < 0 ? Op::Op(0, -1) : Op::Op(a, safe_cmp_impl::MakeUnsigned(b));
}

#define RTC_SAFECMP_MAKE_OP(name, op)        \
  struct name {                              \
    template <typename T1, typename T2>      \
    static constexpr bool Op(T1 a, T2 b) {   \
      return a op b;                         \
    }                                        \
  };

/*
EqOp
Struct EqOp {
  template<typename T1, typename T2>
  static constexpr bool ==(T1 a, T2 b) {
    return a == b;
  }
};
*/

RTC_SAFECMP_MAKE_OP(EqOp, ==)
RTC_SAFECMP_MAKE_OP(NeOp, !=)
RTC_SAFECMP_MAKE_OP(LtOp, <)
RTC_SAFECMP_MAKE_OP(LeOp, <=)
RTC_SAFECMP_MAKE_OP(GtOp, >)
RTC_SAFECMP_MAKE_OP(GeOp, >=)

#undef RTC_SAFECMP_MAKE_OP









}  // namespace safe_cmp_impl

#define RTC_SAFECMP_MAKE_FUN(name)                                            \
  template <typename T1, typename T2>                                         \
  constexpr                                                                   \
    typename std::enable_if<IsIntlike<T1>::value && IsIntlike<T2>::value,     \
    	                    bool>::type Safe##name(T1 a, T2 b) {              \
    /* Unary plus here turns enums into real integral types. */               \
    return safe_cmp_impl::Cmp<safe_cmp_impl::name##Op>(+a, +b);               \
  }                                                                           \
  template <typename T1, typename T2>                                         \
  constexpr                                                                   \
    typename std::enable_if<!IsIntlike<T1>::value || !IsIntlike<T2>::value,   \
                            bool>::type Safe##name(const T1& a,               \
                            	                   const T2& b) {             \
    return safe_cmp_impl::name##Op::Op(a, b);                                 \
  }

RTC_SAFECMP_MAKE_FUN(Eq)
RTC_SAFECMP_MAKE_FUN(Ne)
RTC_SAFECMP_MAKE_FUN(Lt)
RTC_SAFECMP_MAKE_FUN(Le)
RTC_SAFECMP_MAKE_FUN(Gt)
RTC_SAFECMP_MAKE_FUN(Ge)

#undef RTC_SAFECMP_MAKE_FUN

}  // namespace rtc

#endif  // ALGORITHM_LIBRARY_SRC_SAFE_COMPARE_H_
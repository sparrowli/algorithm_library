#ifndef ALGORITHM_LIBRARY_SRC_CHECKS_H_
#define ALGORITHM_LIBRARY_SRC_CHECKS_H_

// Annotate a function that will not return control flow to the caller.
#if defined(_MSC_VER)
#define RTC_NORETURN __declspec(noreturn)
#elif defined(__GNUC__)
#define RTC_NORETURN __attribute__ ((__noreturn__))
#else
#define RTC_NORETURN
#endif

#include <string>

#include "src/safe_compare.h"

#if defined(__MSC_VER)

#define RTC_FORCE_INLINE __forceinline
#define RTC_NO_INLINE __declspec(noinline)

#elif defined(__GNUC__)

#define RTC_FORCE_INLINE __attribute__((__always_inline__))
#define RTC_NO_INLINE __attribute__((__noinline__))

#else

#define RTC_FORCE_INLINE
#define RTC_NO_INLINE

#endif

// The macros here print a message to stderr and abort under various
// conditions. All will accept additional stream messages. e.g.
// RTC_DCHECK_EQ(foo, bar) << "I'm printed when foo != bar.";
// - RTC_CHECK(x) is an assertion that x is always true, and that if it isn't,
//   it's better to terminate the process than to continue. During development,
//   the reason that it's better to terminate might simply be that the error 
//   handling code isn't in place yet; in production, the reason might be that 
//   the author of the code truly believes that x will always be true, but that
//   she recognizes that if she is wrong, abrupt and unpleasant process
//   termination is still better that carrying on with the assumption violated.
//
//   RTC_CHECK always evaluates its argument, so it's OK for x to have side
//   effects.
//
// - FATAL() aborts unconditionally.
namespace rtc {

namespace webrtc_checks_impl {

enum class CheckArgType : int8_t {
  kEnd = 0,
  kInt,
  kLong,
  kLongLong,
  kUInt,
  kULong,
  kULongLong,
  kDouble,
  kLongDouble,
  kCharP,
  kStdString,
  kVoidP,
  /* kCheckOp doesn't represent an argument type. Instead, It is sent as the 
  ** first argument from RTC_CHECK_OP to make FatalLog use the next two
  ** arguments to build the special CHECK_OP error message
  ** (the "a == b (1 vs. 2)" bit).
  */
  kCheckOp,
};

RTC_NORETURN void FatalLog(const char* file,
                           int line,
                           const char* message,
                           const CheckArgType* fmt,
                           ...);

// Wrapper for log arguments. Only ever make values of this type with the \
// MakeVal() functions.
template <CheckArgType N, typename T>
struct Val {
  static constexpr CheckArgType Type() { return N; }
  T GetVal() const { return val; }
  T val;
};

inline Val<CheckArgType::kInt, int> MakeVal(int x) {
  return {x};
}

inline Val<CheckArgType::kLong, long> MakeVal(long x) {
  return {x};
}

inline Val<CheckArgType::kLongLong, long long> MakeVal(long long x) {
  return {x};
}

inline Val<CheckArgType::kUInt, unsigned int> MakeVal(unsigned int x) {
  return {x};
}

inline Val<CheckArgType::kULong, unsigned long> MakeVal(unsigned long x) {
  return {x};
}

inline Val<CheckArgType::kULongLong, unsigned long long> MakeVal(
    unsigned long long x) {
  return {x};
}

inline Val<CheckArgType::kDouble, double> MakeVal(double x) {
  return {x};
}

inline Val<CheckArgType::kLongDouble, long double> MakeVal(long double x) {
  return {x};
}

inline Val<CheckArgType::kCharP, const char*> MakeVal(const char* x) {
  return {x};
}

inline Val<CheckArgType::kStdString, const std::string*> MakeVal(
    const std::string& x) {
  return {&x};
}

inline Val<CheckArgType::kVoidP, const void*> MakeVal(const void* x) {
  return {x};
}

// Ephemeral type that represents the result of the logging << operator.
template <typename... Ts>
class LogStreamer;

  // Base case: Before the first << argument.
template<>
class LogStreamer<> final {
 public:
  template <
      typename U,
      typename std::enable_if<std::is_arithmetic<U>::value>::type* = nullptr>
  RTC_FORCE_INLINE LogStreamer<decltype(MakeVal(std::declval<U>()))> operator<<(
      U arg) const {
    return LogStreamer<decltype(MakeVal(std::declval<U>()))>(MakeVal(arg),
                                                             this);
  }

  template <
      typename U,
      typename std::enable_if<!std::is_arithmetic<U>::value>::type* = nullptr>
    RTC_FORCE_INLINE LogStreamer<decltype(MakeVal(std::declval<U>()))> operator<<(
        const U& arg) const {
    return LogStreamer<decltype(MakeVal(std::declval<U>()))>(MakeVal(arg),
                                                             this);  
  }

  template <typename... Us>
  RTC_NORETURN RTC_FORCE_INLINE static void Call(const char* file,
                                                 const int line,
                                                 const char* message,
                                                 const Us&... args) {
    static constexpr CheckArgType t[] = {Us::Type()..., CheckArgType::kEnd};
    FatalLog(file, line, message, t, args.GetVal()...);
  }

  template <typename... Us>
  RTC_NORETURN RTC_FORCE_INLINE static void CallCheckOp(const char* file, 
                                                        const int line,
                                                        const char* message,
                                                        const Us&... args) {
    static constexpr CheckArgType t[] = {CheckArgType::kCheckOp, Us::Type()...,
                                         CheckArgType::kEnd};
    FatalLog(file, line, message, t, args.GetVal()...);
  }
};

// Inductive case: We've already seen at least one << argument. The most recent
// one had type `T`, and the earlier ones had types `Ts`.

template <typename T, typename... Ts>
class LogStreamer<T, Ts...> final {
 public:
  RTC_FORCE_INLINE LogStreamer(T arg, const LogStreamer<Ts...>* prior)
      : arg_(arg), prior_(prior) {}

  template <
      typename U,
      typename std::enable_if<std::is_arithmetic<U>::value>::type* = nullptr>
  RTC_FORCE_INLINE LogStreamer<decltype(MakeVal(std::declval<U>())), T, Ts...>
  operator<<(U arg) const {
    return LogStreamer<decltype(MakeVal(std::declval<U>())), T, Ts...>(
        MakeVal(arg), this);
  }

  template <
      typename U,
      typename std::enable_if<!std::is_arithmetic<U>::value>::type* = nullptr>
  RTC_FORCE_INLINE LogStreamer<decltype(MakeVal(std::declval<U>())), T, Ts...>
  operator<<(const U& arg) const {
    return LogStreamer<decltype(MakeVal(std::declval<U>())), T, Ts...>(
        MakeVal(arg), this);
  }

  template <typename... Us>
  RTC_NORETURN RTC_FORCE_INLINE void Call(const char* file,
                                          const int line,
                                          const char* message,
                                          const Us&... args) const {
    prior_->Call(file, line, message, arg_, args...);
  }

  template <typename... Us>
  RTC_NORETURN RTC_FORCE_INLINE void CallCheckOp(const char* file,
                                                 const int line,
                                                 const char* message,
                                                 const Us&... args) const {
    prior_->CallCheckOp(file, line, message, arg_, args...);
  }

 private:
  // The most recent argument.
  T arg_;

  // Earlier arguments.
  const LogStreamer<Ts...>* prior_;
};

template <bool isCheckOp>
class FatalLogCall final {
 public:
  FatalLogCall(const char* file, int line, const char* message)
      : file_(file),
        line_(line),
        message_(message) {}

  // This can be any binary operator with precedence lower than <<.
  template <typename... Ts>
  RTC_NORETURN RTC_FORCE_INLINE void operator&(
      const LogStreamer<Ts...>& streamer) {
    isCheckOp ? streamer.CallCheckOp(file_, line_, message_)
              : streamer.Call(file_, line_, message_);
  }

 private:
  const char* file_;
  int line_;
  const char* message_;
};
}  // namespace webrtc_checks_impl

#define RTC_CHECK_OP(name, op, val1, val2)                               \
  while (!rtc::Safe##name((val1), (val2)))                               \
  rtc::webrtc_checks_impl::FatalLogCall<true>(__FILE__, __LINE__,        \
                                              #val1 " " #op " " #val2) & \
      rtc::webrtc_checks_impl::LogStreamer<>() << (val1) << (val2)

  

#define RTC_CHECK_GE(val1, val2) RTC_CHECK_OP(Ge, >=, val1, val2)
#define RTC_CHECK_GT(val1, val2) RTC_CHECK_OP(Gt, >, val1, val2)

}  // namespace rtc

#endif  // ALGORITHM_LIBRARY_SRC_CHECKS_H_
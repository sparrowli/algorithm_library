
class Solution:
  def GenerateParentheses(self, n):
    res = []
    self.dfs(n, n, "", res)
    return res

  def dfs(self, left, right, p_str, res):
    if left == 0 and right == 0:
      res.append( p_str )
      return

    if left > 0:
      self.dfs(left - 1, right, p_str + "(", res)

    if right > left:
      self.dfs(left, right - 1, p_str + ")", res)


gp = Solution()
str_list = gp.GenerateParentheses(3)
for one in str_list:
  print(one)


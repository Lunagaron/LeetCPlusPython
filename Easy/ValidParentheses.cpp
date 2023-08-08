/*
  20. Valid Parentheses

  Given a string s containing just the characters '(', ')', '{', '}', '[' and
  ']', determine if the input string is valid.

  An input string is valid if:

  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Every close bracket has a corresponding open bracket of the same type.

  Example 1:
  Input: s = "()"
  Output: true
*/

class Solution {
public:
  // Solution involves maintaining a stack to keep track of the most recently
  // used bracket. This has a worst time complexity of O(n).
  bool isValid(string s) {
    // Create a stack to keep track of the top bracket
    stack<char> bracketStack;
    char pop_bracket;
    for (char bracket : s) {
      if (bracket == '(' || bracket == '{' || bracket == '[') {
        bracketStack.push(bracket);
      } else if (bracket == ')') {
        if (bracketStack.empty() || bracketStack.top() != '(') {
          return false;
        }
        bracketStack.pop();
      } else if (bracket == '}') {
        if (bracketStack.empty() || bracketStack.top() != '{') {
          return false;
        }
        bracketStack.pop();
      } else if (bracket == ']') {
        if (bracketStack.empty() || bracketStack.top() != '[') {
          return false;
        }
        bracketStack.pop();
      }
    }
    if (!bracketStack.empty()) {
      return false;
    }
    return true;
  }
};
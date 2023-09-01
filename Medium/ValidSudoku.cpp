/*
 36. Valid Sudoku

 Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 validated according to the following rules:

  Each row must contain the digits 1-9 without repetition.
  Each column must contain the digits 1-9 without repetition. Each of the nine 3
  x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

  Note: A Sudoku board (partially filled) could be valid but is not necessarily
  solvable. Only the filled cells need to be validated according to the
  mentioned rules.

  Example 1:
  Input: board =
  [["5","3",".",".","7",".",".",".","."]
  ,["6",".",".","1","9","5",".",".","."]
  ,[".","9","8",".",".",".",".","6","."]
  ,["8",".",".",".","6",".",".",".","3"]
  ,["4",".",".","8",".","3",".",".","1"]
  ,["7",".",".",".","2",".",".",".","6"]
  ,[".","6",".",".",".",".","2","8","."]
  ,[".",".",".","4","1","9",".",".","5"]
  ,[".",".",".",".","8",".",".","7","9"]]
  Output: true
*/
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    // Create a set for each dimension of the sudoku board to be checked
    std::unordered_set<char> rows[9];    // 9 sets for 9 rows
    std::unordered_set<char> columns[9]; // 9 sets for 9 columns
    std::unordered_set<char> boxes[9];   // 9 sets for 9 boxes

    // Loop through and add each element into each of the dimensions
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        // Individually get each character of the board
        char currentChar = board[i][j];
        // If the current character is a placeholder, continue
        if (currentChar == '.') {
          continue;
        }
        // Conduct a search for duplicates in rows, else append
        if (rows[i].find(currentChar) != rows[i].end()) {
          // std::cout << "Row failure" << std::endl;
          return false;
        } else {
          rows[i].insert(currentChar);
        }
        // Conduct a search for duplicates in columns, else append
        if (columns[j].find(currentChar) != columns[j].end()) {
          // std::cout << "Column failure" << std::endl;
          return false;
        } else {
          columns[j].insert(currentChar);
        }
        // Conduct a search for duplicates in the boxes, else append
        int index = (i / 3) * 3 + (j / 3);
        if (boxes[index].find(currentChar) != boxes[index].end()) {
          // std::cout << "Box failure" << std::endl;
          return false;
        } else {
          boxes[index].insert(currentChar);
        }
      }
    }
    return true;
  }
};
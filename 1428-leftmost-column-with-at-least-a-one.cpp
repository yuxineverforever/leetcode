/**
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1.
For each individual row of the matrix, this row is sorted in non-decreasing
order.

Given a row-sorted binary matrix binaryMatrix,
return leftmost column index(0-indexed) with at least a 1 in it.
If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.
You may only access the matrix using a BinaryMatrix interface:

 - BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y)
(0-indexed).

 - BinaryMatrix.dimensions() returns a list of 2 elements [m, n], which means
the matrix is m * n.

Submissions making more than 1000 calls to BinaryMatrix.get() will be judged
Wrong Answer.

Also, any solutions that attempt to circumvent the judge will result in
disqualification.


For custom testing purposes you're given the binary matrix mat as input in the
following four examples. You will not have access the binary matrix directly.
**/

class Solution {
public:
  int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
    std::list<int> dimension = binaryMatrix.dimensions();
    int m = dimension.get(0);
    int n = dimension.get(1);
    int res = -1;
    int row = 0;
    int col = n - 1;
    while (row < m && col >= 0) {
      if (binaryMatrix.get(row, col) == 1) {
        res = col;
        col--;
      } else {
        row++;
      }
    }
    return res;
  }
};
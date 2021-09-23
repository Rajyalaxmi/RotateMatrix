# RotateMatrix

Input is the matrix of only 1s and 0s.
First Rotate the matrix clockwise
And next move the all 0's in the each column to the up side. Means, after this operation all 0s are upside and all 1s are downside in the all columns.

Example1:
Input:
  1 1 0
  0 0 1
  1 1 0

Output:
  0 0 0
  1 0 1
  1 1 1

Explaination:

After clockwise rotation, the matrix is:
  1 0 1
  1 0 1
  0 1 0
  
After moving the all 0s to the upside, the matrix is:
  0 0 0
  1 0 1
  1 1 1

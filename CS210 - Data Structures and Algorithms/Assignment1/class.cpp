#include <iostream>
using namespace std;
#include "class.h"



//Default constructor: for MatrixType class, rows and columns are set to 0.
MatrixType::MatrixType()
{
  numRows = 0;
  numCols = 0;
}

//SetSize: Sets the rows and columns within the matrix.
void MatrixType::SetSize(int rowSize, int colSize)
{
  numRows = rowSize;
  numCols = colSize; 
  
}

//StoreItem: Stores our row and col inside the item.
void MatrixType::StoreItem(int item, int row, int col)
{
  for (int row; row >= 0; row++)
  {
    for (int col; col >= 0; col++)
    {
      values[row][col] = item;
    }
  }
}

//ADD: Adds the new matrix to our original matrix and the answer of this operation is stored in a third matrix.
void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
{
  result.SetSize(numRows, numCols);

  for (int  i = 0; i <numRows; i++)
  {
    for (int j = 0; j <numCols;j++)
    {
      result.values[i][j] = otherOperand.values[i][j] + values[i][j];
    }
  }
}

//Sub: Function subtracts the orginal matrix from the new matrix and holds the result in a newly created matrix
void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
{
   result.SetSize(numRows, numCols);

  for (int  i = 0; i <numRows; i++)
  {
    for (int j = 0; j <numCols;j++)
    {
      result.values[i][j] = otherOperand.values[i][j] - values[i][j];
    }
  }
}

//Mult: Multiplies the second matrix with the original matrix.
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
{
   result.SetSize(numRows, numCols);

  for (int  i = 0; i <numRows; i++)
  {
    for (int j = 0; j <numCols;j++)
    {
      result.values[i][j] = otherOperand.values[i][j] * values[i][j];
    }
  }
}

//Print: In this function, the current values that are stored are printed.
void MatrixType::Print()
{
  for (int  i = 0; i <numRows; i++)
  {
    for (int j = 0; j <numCols;j++)
    {
      cout << values[i][j]<< " "<<endl;
    }
  }
  cout << endl;
}

//AddSubCompatible: Checker function to check if the given matrix can be added or subtracted with the second matrix.
bool MatrixType::AddSubCompatible(MatrixType otherOperand)
{
  if (numRows == otherOperand.numRows)
  {
    return numRows;
  
  }
  if (numCols == otherOperand.numCols)
  {
    return numCols;
  
  }
  return true;
}

// MultCompatible: Checks if the given matrix can be multiplied with a second matrix.
bool MatrixType::MultCompatible(MatrixType otherOperand)
{
  if (numCols == otherOperand.numRows)
  {
    return numCols;
  }
  return false;
}

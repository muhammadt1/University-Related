#include <iostream>
#include "class.h"
using namespace std;

int main() 
{
  MatrixType m[10];
  int num1,num2,num3,option;
  int row,col;
  MatrixType createdMatrix;
  
  cout << "Choose one of the following options: "<<endl;
  cout <<endl;

  cout << "Option 1: Get a new matrix."<<endl;
  cout << "Option 2: Add two matrices."<<endl;
  cout << "Option 3: Subtract a matrix from another matrix."<<endl;
  cout << "Option 4: Multiply two matrices."<<endl;
  cout << "Option 5: Print matrix."<<endl;
  cout << "Option 6: End program"<<endl;
  cin >> option;

  
  MatrixType resultOfSub;
  MatrixType resultOfAdd;
  MatrixType resultOfMult;

  
  switch (option)
  {
    case 1:
      
      cout << "0x0 Matrix created. Enter rows and columns for matrix: "<<endl;

      for (int i=0; i < row;i++)
      {
        for (int j = 0; j < col; j++)
        {
          cout << "Rows: ";
          cin >> row;
          cout << "Col: ";
          cin >> col;
          createdMatrix.SetSize(row, col);
        }
      }
      break;
    case 2:

      int add1, add2;

      cout << "Suppose that you want to perform C=A+B. Enter A, B and C: "<<endl;
      
      cout << "Enter Matrix 1: ";
      cin >>add1;

      cout << "Enter Matrix 2: "<<endl;
      cin >>add2;

      if (m[add1].AddSubCompatible(m[add2])!= true)
      {
        cout << "Matrices are not compaitble to be added."<<endl;
      }

      m[add1].Add(m[add2],resultOfAdd);

      cout << "Sum Matrix: "<<endl;
      resultOfAdd.Print();

      break;

    case 3:

      int sub1, sub2;
      
      cout << "Enter Matrix 1: ";
      cin >>sub1;

      cout << "Enter Matrix 2: ";
      cin >>sub2;

      if (m[sub1].AddSubCompatible(m[sub2]))
      {
        cout << "Matrices are not compaitble to be subtracted."<<endl;
      }

      m[sub1].Sub(m[sub2],resultOfSub);

      cout << "Subtracted Matrix: "<<endl;
      resultOfSub.Print();

      break;
    

    case 4:
      int mult1,mult2;

      cout << "Enter Matrix 1: ";
      cin >>mult1;

      cout << "Enter Matrix 2: ";
      cin >>mult2;

      if (m[mult1].MultCompatible(m[mult2]))
      {
        cout << "Matrices are not compaitble to be Multiploed."<<endl;
      }
      
      m[mult1].Mult(m[mult2],resultOfMult);

      cout << "Multiplied Matrix: ";
      resultOfMult.Print();


      break;
      
    
    case 5:

      int prnt;
      
      cout << "Enter the matrix number for printing: ";
      cin >> prnt;

      if (prnt < 0)
      {
        cout << "Invalid Entry"<<endl;
      }

      m[prnt].Print();

      break;

    case 6:
      break;

      
      


    
  }
  
}
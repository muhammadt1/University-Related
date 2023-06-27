#include <iostream>
#include "class.h"
using namespace std;

int main() 
{
  tree t;

  int init,entry, insert,del,entry1 = 0;

  cout << "Initially, how many integers do you want: ";
  cin >>init;

  cout << "Enter your integers: ";
  for (int i = 0; i < init;i++)
  {
    cin >>entry;
    t.ins(entry);
  }

  while (entry1!=6)
  {
    cout <<"Press 1 for inorder traverse"<<endl;
    cout << "Press 2 for preorder traverse"<<endl;
    cout << "Press 3 for postorder traverse"<<endl;
    cout <<"Press 4 for inserting item"<<endl;
    cout <<"Press 5 for deleting an item"<<endl;
    cout <<"Press 6 to exit"<<endl;
    cin >> entry1;


    if (entry1 ==1)
    {
      cout << "Inorder traverse: ";
      t.inTrav();
    }
    else if (entry1 == 2)
    {
      cout << "Preorder traverse: ";
      t.preTrav();
    }
    else if (entry1 == 3)
    {
      cout << "Postorder traverse: ";
      t.posTrav();
    }
    else if (entry1 == 4)
    {
      cout << "Enter an item you want to insert: ";
      cin >> insert;
      t.ins(insert);
    }
    else if (entry1 == 5)
    {
      cout << "Enter an item you want to deletes: ";
      cin >> del;
      t.rem(del);
    }
    else if (entry1 == 6)
    {
      cout <<"Quit"<<endl;
    }
    
    
    
  }


  
}
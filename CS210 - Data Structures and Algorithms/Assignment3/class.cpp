#include <iostream>
#include "class.h"
using namespace std;

node::node (int numVal)
{
  num = numVal;
  l = nullptr;
  r = nullptr;
}


node* tree::recur(node* curr, int datum)
{
  if (curr == nullptr)
  {
    curr = new node(datum);
  }
  if (datum < curr->num)
  {
    curr->l = recur(curr->l,datum);
  }
  else if (datum > curr->num)
  {
    curr->r = recur(curr->r,datum);
  }
  else
  {
    cout<<"Item already exists."<<endl;
  }

  return curr;
}



node* tree::dele(node* curr, int datum)
{
  if (curr == nullptr) 
  {
    return curr;
  }
  
  if (datum < curr->num)
  {
    curr->l = dele(curr->l,datum);
  }
  else if(datum >curr->num)
  {
    curr->r = dele(curr->r,datum);
  }
  else
  {
    if (curr->l  == nullptr && curr->r == nullptr)
    {
      return nullptr;
    }
    else if (curr->l== nullptr)
    {
      node* tempptr = curr->r;
      delete curr;
      return tempptr;
    }
     else if (curr->r== nullptr)
    {
      node* tempptr = curr->l;
      delete curr;
      return tempptr;
    }
    
    
  }

  return curr;
}


node* tree::min(node* j)
{
  node* tempptr = j;

  while (tempptr->l != nullptr)
  {
    tempptr = tempptr->l;
  
  }

  return tempptr;
  
}




void tree::in(node* j)
{
  if (j != nullptr)
  {
    in(j->l);

    cout <<j->num<<" ";

    in(j->r);
  }
}

void tree::pre(node* k)
{
  if (k != nullptr)
  {
    cout <<k->num<<" "<<endl;
    pre(k->l);
    pre(k->r);
    
  }
}

void tree:: post(node* z)
{
  if (z!= nullptr)
  {
    pre(z->l);
    pre(z->r);
    cout <<z->num<<" "<<endl;
    
    
  }
}

void tree::ins(int datum)
{
  
  base = recur(base,datum);
}

void tree::rem(int datum)
{
  base = dele(base,datum);
}

void tree::inTrav()
{
  in(base);

}

void tree:: preTrav()
{
  pre(base);
}

void tree::posTrav()
{
  post(base);
}






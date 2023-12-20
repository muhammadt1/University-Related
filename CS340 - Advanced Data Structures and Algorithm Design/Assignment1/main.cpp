#include <iostream>
using namespace std;
#include <stack>
#include <string>

struct Node {
  Node *left;
  Node *right;
  string v;

  // Definition
  Node(string va) {
    left = nullptr;
    right = nullptr;

    v = va;
  }
};

//Function Prototypes
int preced(char oper);
bool oper(char sign);
string infToPos(string inf);
Node *expTreeConv(string pstf);
int expTreeEval(Node* base);
void print(Node* base);
void inor(Node* base);
void postor(Node* base);
void preord(Node* base);


//Function Definitions
int preced(char oper) 
{
  if (oper == '+' || oper == '-') {
    return 1;
  } else {
    return 2;
  }
}

bool oper(char sign) 
{
  if (sign == '+' || sign == '-' || sign == '*' || sign == '/') 
  {
    return true;
  }
  else
  {
    return false;
  }
}

string infToPos(string inf) 
{
  stack<char> opS;
  string post;

  for (int i = 0; i < inf.length(); i++) {
    char ind = inf[i];

    if (isalnum(ind)) {
      post = post + ind;
    } else if (ind == '(') {
      opS.push(ind);
    } else if (ind == ')') {
      while (opS.empty() != true && opS.top() != '(') {
        ind = ind + opS.top();
        opS.pop();
      }
    } else {
      while (opS.empty() != true && opS.top() != '(' &&
             preced(ind) < preced(opS.top())) {
        post = post + opS.top();
        opS.pop();
      }
      opS.push(ind);
    }
  }
  while (!opS.empty()) {
    post += opS.top();
    opS.pop();
  }

  return post;
}

Node *expTreeConv(string pstf) 
{
  stack<Node *> stk;
  string sym;
  size_t i = 0;

  while (pstf.length() > i) 
  {
    char co = pstf[i];
    if (co == pstf[i]) 
    {
      i++;
      continue;
    }
    if (isalnum(co)) 
    {
      while (isalnum(co)) 
      {
        sym = sym + co;
        co = pstf[++i];
      }
      stk.push(new Node(sym));
    } 
    else 
    {
      Node *right = stk.top();
      stk.pop();
      Node *left = stk.top();
      stk.pop();
      
      Node* opN = new Node(string(1, co));
      opN->left = left;
      opN->right = right;

      stk.push(opN);
      i++;
    }
  }
  return stk.top();

}
int expTreeEval(Node* base)
{
  double l = expTreeEval(base->left);
  double r = expTreeEval(base->right);

  char oper = base->v[0];

  if (oper == '+') 
  {
    return l+r;
  } 
  else if (oper == '-') 
  {
    if (r>l)
      return r-l;
    else
      return l-r;
  } 
  else if (oper == '*') 
  {
    return l*r;
  } 
  else if (oper == '/') 
  {
    if (r>l)
      return r/l;
    else
      return l/r;
  } 
  else 
  {
    cerr << "Error" << endl;
  }

  return 0;
}



void print(Node* base)
{
  if (base)
  {
    print(base -> left);
    print(base -> right);
    cout << base -> v<< " ";
  }
}
void inor(Node* base)
{
  if (base)
  {
    print(base->left);
    cout << base -> v<< " ";
    print(base->right);
  }
}
void postor(Node* base)
{
  if (base)
  {
    print(base->left);
    print(base->right);
    cout << base -> v<< " ";
  }
}

void preord(Node* base)
{
  if (base)
  {
    cout << base -> v<< " ";
    print(base->left);
    print(base->right);
  }
}

int main() 
{ 

  while (true)
  {
    string userInf, userPostf;

    cout << "Enter Infix Expression or Type quit to exit: ";
    cin >> userInf;
    cout <<endl;

    if (userInf == "quit" || userInf == "Quit")
    {
      break;
    }
  
    userPostf = infToPos(userInf);
  
    cout << "Infix: "<< userInf<<endl;
    cout << "Postfix" << userPostf<<endl;
    Node* n = expTreeConv(userPostf);

    cout << "Inorder: ";
    inor(n);
    cout <<endl;
    
    cout << "Preorder: ";
    preord(n);
    cout <<endl;
    
    cout << "Post: ";
    postor(n);
    cout <<endl;
    
    cout << "Your final result is: "<<expTreeEval(n)<<endl;
  }

}
#include <iostream>
using namespace std;

class node {
public:
  int num;
  node *l;
  node *r;

  node();
  node(int numVal);
};

class tree {
public:
  void ins(int datum);
  void rem(int datum);
  void inTrav();
  void preTrav();
  void posTrav();

private:
  node *base;

  node *recur(node *curr, int datum);
  node *dele(node *curr, int datum);
  node *min(node *j);

  void in(node *j);
  void pre(node *k);
  void post(node *z);
};
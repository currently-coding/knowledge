#include <iostream>

class Bintree
{

private:
  Bintree *left_;
  Bintree *right_;
  std::string value;
  static int numID;
  int id_;

public:
  Bintree(std::string val) : value(val), left_(nullptr), right_(nullptr), id_(numID) { numID++; }

  ~Bintree()
  {
    delete left_;
    delete right_;
    numID = 0;
  }

  void insert(Bintree &sub);
  void insert(std::string value);
  void print();
};

int Bintree::numID = 0;

void Bintree::insert(Bintree &sub)
{
  if (sub.value < value)
  {
    if (left_)
    {
      left_->insert(sub);
    }
    else
    {
      left_ = &sub;
    }
  }
  else
  {
    if (right_)
    {
      right_->insert(sub);
    }
    else
    {
      right_ = &sub;
    }
  }
}

void Bintree::insert(std::string value)
{
  Bintree *newNode = new Bintree(value);
  insert(*newNode);
}

void Bintree::print()
{
  std::cout << "(";
  if (left_)
  {
    left_->print();
  }
  std::cout << id_ << ":" << value;
  if (right_)
  {
    right_->print();
  }
  std::cout << ")";
}

int main()
{
  {
    Bintree t("abr");
    t.insert("ra");
    t.insert("aca");
    t.insert("dab");
    t.print();
    std::cout << std::endl;
  }
  Bintree *tp = new Bintree("abr");
  tp->insert("ra");
  tp->insert("aca");
  tp->insert("dab");
  tp->print();
  std::cout << std::endl;

  delete tp;
  return 0;
}
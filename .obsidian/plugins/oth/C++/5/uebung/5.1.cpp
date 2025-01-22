#include <iostream>
#include <iterator>

class bintree {
private:
  bintree *left_;
  bintree *right_;
  static int id;
  int id_;
public:
  std::string const value;

  bintree(bintree *left, bintree *right, const std::string value)
      : left_(left), right_(right), value(value), id_(id++) {}
  bintree(const std::string value) : left_(nullptr), right_(nullptr), value(value), id_(id++) {}

  
  ~bintree() {
    delete left_;
    left_ = nullptr;
    delete right_;
    right_ = nullptr;
  }
  
  void print();
  
  static int getStaticID() {
    return id;
  }

  void insert(bintree &sub) {
    if (sub.value < value) {
      if (left_) {
        left_->insert(sub);
      } else {
        left_ = &sub;
      }
    } else {
      if (right_) {
        right_->insert(sub);
      } else {
        right_ = &sub;
      }
    }
  }

  void insert(std::string value) {
    bintree tree = bintree(nullptr, nullptr, value);
    insert(tree);
  }

};

void bintree::print() {
  std::cout << "(";
  if (bintree::left_) {
    bintree::left_->print();
  }
  std::cout << id_ << ":" << value;
  if (bintree::right_) {
    right_->print();
  }
  std::cout << ")";
}
int bintree::id = 0;

int main() {
  bintree t = bintree("abr");
  t.insert("ra");
  t.insert("aca");
  t.insert("dab");
  t.print();
  std::cout << std::endl;
  bintree* tp = new bintree("abr");
  tp->insert("ra");
  tp->insert("aca");
  tp->insert("dab");
  tp->print();
  std::cout << std::endl;
  delete tp;
  return 0;
}
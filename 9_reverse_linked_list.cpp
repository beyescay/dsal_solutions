#include <memory>
#include <vector>
#include <iostream>
#include <random>

class Node {

public:
  Node(int value) : value_(value) {}

  int value() const { return value_; }

  std::shared_ptr<Node> next() { return next_; }
  void set_next(std::shared_ptr<Node> next) { next_ = next; }

private:
  int value_;
  std::shared_ptr<Node> next_ = nullptr;

};

class LinkedList {

public:
  void Append(const int& value);
  void Reverse();
  void Print();
  std::shared_ptr<Node> head() const { return head_; }
  std::shared_ptr<Node> tail() const { return tail_; }

private:
  std::shared_ptr<Node> head_ = nullptr;
  std::shared_ptr<Node> tail_ = nullptr;

};

void LinkedList::Append(const int& value) {

  auto node_ptr = std::make_shared<Node>(value);

  if (this->head_ == nullptr) {
    this->head_ = node_ptr;
    this->tail_ = node_ptr;
  }
  else {
    auto prevtail_ = this->tail_;
    prevtail_->set_next(node_ptr);
    this->tail_ = node_ptr;
  }

}

void LinkedList::Reverse() {

  if (this->head_ == nullptr || this->head_ == this->tail_) {
    return;
  }
  else {
    auto curr_ptr = this->head_->next();
    auto prev_ptr = this->head_;

    while(curr_ptr != nullptr) {
      auto next_ptr = curr_ptr->next();
      curr_ptr->set_next(prev_ptr);
      prev_ptr = curr_ptr;
      curr_ptr = next_ptr;
    }
    std::swap(this->head_, this->tail_);
    this->tail_->set_next(nullptr);
  }

}

void LinkedList::Print() {

  std::cout << "LinkedList: ";

  if (this->head_ == nullptr) {
    return;
  }

  auto curr_ptr = this->head_.get();

  while(curr_ptr != this->tail_.get()) {
    std::cout << curr_ptr->value() << "->";
    curr_ptr = curr_ptr->next().get();
  }
  std::cout << this->tail_->value() << std::endl;

}

std::shared_ptr<LinkedList> CreateRandomLinkedList(int num_elements) {

  auto ll_ptr = std::make_shared<LinkedList>();

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(1, num_elements);
  for(int i = 0; i < num_elements; ++i) {
    auto new_val = distr(gen);
    ll_ptr->Append(new_val);
  }

  return ll_ptr;

}

std::vector<int> CreateVectorFromLinkedList(LinkedList* ll_ptr) {

  std::vector<int> ll_vec;
  auto curr_ptr = ll_ptr->head().get();

  while(curr_ptr != nullptr) {
    ll_vec.push_back(curr_ptr->value());
    curr_ptr = curr_ptr->next().get();
  }

  return ll_vec;

}

void PrintVector(std::vector<int> v) {

  std::cout << "Vector: ";

  for(auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

int main() {

  int num = 10;
  auto ll_ptr = CreateRandomLinkedList(num);
  ll_ptr->Print();
  auto ll_vec = CreateVectorFromLinkedList(ll_ptr.get());
  PrintVector(ll_vec);

  ll_ptr->Reverse();
  auto ll_vec_reversed = CreateVectorFromLinkedList(ll_ptr.get());
  std::reverse(ll_vec.begin(), ll_vec.end());

  std::cout << "\nAfter Reversing" << std::endl;
  ll_ptr->Print();
  PrintVector(ll_vec_reversed);

  if (ll_vec != ll_vec_reversed) {
    std::cout << "\nReverse failed!" << std::endl;
  }
  else {
    std::cout << "\nReverse successful" << std::endl;
  }

}

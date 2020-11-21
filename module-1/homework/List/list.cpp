#include "list.h"

namespace task {

Node::Node() {
  data = 0;
  prev = nullptr;
  next = nullptr;
}

Node::Node(const int& data_, Node* prev_, Node* next_) {
  data = data_;
  prev = prev_;
  next = next_;
}

Node::~Node() {
  if (next) {
    delete next;
  }
}

list::list() {
  size_ = 0;
  first = nullptr;
  last = nullptr;
}

list::list(size_t count, const int& value) {
  size_ = 0;
  first = nullptr;
  last = nullptr;
  for (int i = 0; i < count; i++) {
    push_back(value);
  }
}

int& list::front() { return first->data; }

const int& list::front() const { return first->data; }

int& list::back() { return last->data; }

const int& list::back() const { return last->data; }

bool list::empty() const { return size_ == 0; }

size_t list::size() const { return size_; }

void list::clear() {
  if (first) {
    delete first;
  }
  first = nullptr;
  last = nullptr;
  size_ = 0;
}

void list::push_back(const int& value) {
  Node* tmp = new Node(value, last, nullptr);
  last = tmp;
  size_++;
  if (size_ == 1) first = last;
}

void list::pop_back() {
  if (size_ == 1) {
    first = nullptr;
  }
  Node* tmp = last->prev;
  delete last;
  last = tmp;
  size_--;
}
void list::push_front(const int& value) {
  Node* tmp = new Node(value, nullptr, first);
  first = tmp;
  size_++;
  if (size_ == 1) last = first;
}
void list::pop_front() {
  if (size_ == 1) {
    last = nullptr;
  }
  Node* tmp = first->next;
  delete first;
  first = tmp;
  size_--;
}
void list::resize(size_t count) {
  if (count < size_) {
    while (count != size_) {
      pop_back();
      size_--;
    }
  } else {
    while (count != size_) {
      push_back(int());
      size_++;
    }
  }
}
void list::swap(list& other) {
  int tmp = size_;
  size_ = other.size_;
  other.size_ = tmp;
  Node* tmp_ = first;
  first = other.first;
  other.first = tmp_;
  tmp_ = last;
  last = other.last;
  other.last = tmp_;
}
void list::remove(const int& value) {
  Node* current = first;
  while (current) {
    Node* next = current->next;
    if (current->data == value) {
      if (current->prev) {
        current->prev->next = current->next;
      }
      if (current->next) {
        current->next->prev = current->prev;
      }
      current->next = nullptr;
      current->prev = nullptr;
      delete current;
      size_--;
    }
    current = next;
  }
}
void list::unique() {
  Node* current = first;
  while (current) {
    Node* next = current->next;
    if (current->prev && current->prev->data == current->data) {
      if (current->prev) {
        current->prev->next = current->next;
      }
      if (current->next) {
        current->next->prev = current->prev;
      }
      current->next = nullptr;
      current->prev = nullptr;
      delete current;
      size_--;
    }
    current = next;
  }
}

void list::sort() {
  for (int i = 0; i < size_; i++) {
    Node* current = first;
    while (current) {
      Node* next = current->next;
      if (current->next && current->data > current->next->data) {
        int tmp = current->data;
        current->data = current->next->data;
        current->next->data = tmp;
      }
      current = next;
    }
  }
}

}  // namespace task
#ifndef GUARD_Listy_h
#define GUARD_Listy_h

#include <memory>

template <class T>
class Node {
 public:
  Node() : data(NULL), next(NULL), previous(NULL){};
  Node(T val) : next(NULL), data(val){};

  Node<T>* next;
  Node<T>* previous;
  T data;
};

template <class T>
class NodeIterator {
 public:
  NodeIterator(Node<T>* node) : iter(node){};
  //
  NodeIterator& operator++() {
    iter = iter->next;
    return *this;
  }
  NodeIterator& operator--() {
    iter = iter->previous;
    return *this;
  }
  // C++ has a kludge for the first problem. When operator++() is used postfix,
  // the compiler generates a call with a dummy integer. This integer has no
  // useful value. It's simply there so that you can define operator++( int ) to
  // handle the postfix case, and keep it separate from the code for the prefix
  // case.
  // https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
  bool operator!=(NodeIterator& rhs) const { return this->data != rhs.data; }
  T& operator*() const { return this->data; }

 private:
  Node<T>* iter;
};

template <class T>
class LList {
 public:
  typedef NodeIterator<T> iterator;
  typedef const NodeIterator<T> const_iterator;
  typedef size_t size_type;
  typedef T value_type;

  LList() : head(NULL), tail(NULL), s(0) {}
  explicit LList(size_type s, const T& t = T()) { create(s, t); }
  LList(const LList& l) { create(l.begin(), l.end()); }

  LList& operator=(const LList&);
  ~LList() { uncreate(); }

  size_type size() const { return s; }
  iterator begin() { return iterator(head); }
  iterator end() { return iterator(tail); }
  const_iterator begin() const { return iterator(head); }
  const_iterator end() const { return iterator(tail); }

  void push_back(const T& t) { append(t); }

 private:
  Node* head;
  Node* tail;
  size_type s;

  std::allocator<Node<T>> alloc;

  void create(size_type, const T&);
  void create(iterator, iterator);
  void append(const T&);
  void uncreate();
};

template <class T>
LList<T>& LList<T>::operator=(const LList& l) {
  if (this != &l) {
    uncreate();
    create(l.begin(), l.end());
  }
  return *this;
}

template <class T>
void LList<T>::create(size_type s, const T& v) {
  for (size_type i = 0; i < s; i++) {
    append(t);
  }
}

template <class T>
void LList<T>::create(iterator b, iterator e) {
  while (b != e) {
    append(*b++);
  }
}

template <class T>
void LList<T>::uncreate() {
  Node<T>* node = back;
  while (node != NULL) {
    Node<T>* del_node = node;
    node = node->previous;
    delete del_node;
  }
  front = back = NULL;
  s = 0;
}

template <class T>
void LList<T>::append(const T& v) {
  Node<T>* node = new Node<T>(v);
  if (s == 0) {
    front = node;
  } else if (s == 1) {
    node->previous = front;
    back = node;
    front->next = node;
  } else {
    back->next = node;
    node->previous = back;
    back = node;
  }
  s++
}

#endif
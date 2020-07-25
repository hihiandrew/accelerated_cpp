#ifndef GUARD_Listy_h
#define GUARD_Listy_h

#include <memory>

template <class T>
class Node{
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    // constructor
    Node(){create();}
    Node(const T& val){create(val);}
    // copy constructor / initialization
    Node(const Node& n){create(n.value());}
  private:

}

template <class T>
class Listy{
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // constructor
    
    // copy constructor

    // assignment operator
    
    // destructor

    // size, empty, index

    // iterator returning functions

    // push_back
  private:
    iterator data;
}


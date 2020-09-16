#include <stdexcept>

template <class T>
class Handle {
 public:
  Handle() : p(0){};
  Handle(const Handle& s) : p(0) {
    if (s.p) p = s.p->clone();
  };
  Handle& operator=(const Handle& rhs);
  ~Handle() { delete p; };

  Handle(T* t) : p(t){};

  operator bool() const { return p; };
  T& operator*() const;
  T* operator->() const;

 private:
  T* p;
};

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs) {
  if (&rhs != this) {
    delete p;
    // cannot assume the rhs is initialized
    // expects all objects to have a clone() method
    p = rhs.p ? rhs.p->clone() : 0;
  }
  return *this;
}

// calling * on Handle object will yield the obj that the pointer points at.
// eg: Handle<Core> student(new Grade); *student == *(student.p) == the Grad obj
template <class T>
T& Handle<T>::operator*() const {
  if (p) return *p;
  throw std::runtime_error("unbound Handle");
}

// x->y == (x.operator->())->y. behaves different to other binary operators.
// must return a value that can be treated as a pointer and can be dereferenced
// student->y == (student.operator->())->y == student.p->y
template <class T>
T* Handle<T>::operator->() const {
  if (p) return p;
  throw std::runtime_error("unbound Handle");
}

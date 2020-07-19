#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <string>
#include <cstddef>

void create(){
}

template <class T>
class Vec{
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    // constructor / destructor 
    Vec(){create();}
    explicit Vec(size_type n, const T& val=T()){create(n,val);}

    // new operations: size and index
    size_type size() const {return limit - data;}
    T& operator[](size_type i){return data[i];}            // read+write
    const T& operator[](size_type i)const{return data[i];} // read only

    void push_back(T elem){
      if(size==max){
        resize();
      }
      vec[size++] = elem; 
    };
    
    // functions that return iterators
    iterator begin(){return data;}
    iterator end(){return limit;}
    const_iterator begin()const{return data;}
    const_iterator end()const{return data;}
  private:
    // first and last pointers 
    iterator data;
    iterator limit;

    typename T::size_type size;
    typename T::size_type max;

    void resize(){
      // create larger container
      max *= 2;
      T* copy = new T[max];

      // copy to new container, cleanup
      for(std::size_t i=0; i<size; i++){
        copy[i] = vec[i];
      }
      delete[] vec;
      vec = copy;
    }

};

#endif

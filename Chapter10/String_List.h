#ifndef GUARD_String_List_h
#define GUARD_String_List_h

#include <string>
class String_List{
  private:
    // l: a pointer;*l: string element
    std::string *l; 
    std::string::size_type max,size;
    void resize();
  public:
    typedef std::string* iterator; // creates ::iterator
    String_List();
    String_List(std::string);
    ~String_List(); //destructor
    void push_back(std::string);
    // returns pointer to a string
    std::string* begin(){return l;}; 
    std::string* end(){return l+size;}
};

#endif

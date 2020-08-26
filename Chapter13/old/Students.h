#ifndef GUARD_Students_h
#define GUARD_Students_h

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Core {
  friend class Student_info;

 public:
  // constructors
  Core() : midterm(0), final(0){};
  Core(std::istream& is) { read(is); };
  // destructor made virtual for the purpose of handles class
  // delete cp knowing which synthesize destructor to run
  virtual ~Core(){};
  // accessors
  virtual std::string name() const;
  virtual double grade() const;
  virtual std::istream& read(std::istream&);

 protected:
  // handle class assignment/copy requires clone functionality
  virtual Core* clone() { return new Core(*this); };
  // derived classes have access to these private members
  std::istream& read_common(std::istream&);
  std::istream& read_hw(std::istream&, std::vector<double>&);
  std::vector<double> homework;
  double midterm, final;

 private:
  std::string n;
};

class Grad : public Core {
 public:
  // constructors
  Grad() : thesis(0){};
  Grad(std::istream& is) { read(is); };
  // accessors
  double grade() const override;
  std::istream& read(std::istream&) override;

 protected:
  // handle class assignment/copy requires clone functionality
  Core* clone() override { return new Core(*this); };

 private:
  double thesis;
};

class Student_info {
 public:
  // constructors
  Student_info() : cp(0){};
  Student_info(std::istream& is) : cp(0) { read(is); };
  Student_info(const Student_info& rhs);
  // destructor
  ~Student_info() { delete cp; }
  // operators
  Student_info& operator=(const Student_info&);
  // utility
  std::istream& read(std::istream&);
  std::string name() const {
    if (cp)
      return cp->name();
    else
      throw std::runtime_error("uninitialised Student");
  };
  double grade() const {
    if (cp)
      return cp->grade();
    else
      throw std::runtime_error("uninitialized Student");
  };
  static bool compare(const Student_info& a, const Student_info& b) {
    return a.name() < b.name();
  };

 private:
  Core* cp;
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);
std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double median(std::vector<double>);

#endif
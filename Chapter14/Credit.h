#include "Core.h"

class Credit : public Core {
 public:
  // constructors
  Credit(){};
  Credit(std::istream& is) : Core(is){};
  // inherited destructor
  // accessors
  double grade() const override;
  bool passed() const { return grade() >= 60; };
  // read is inherited
  bool valid() const { return true; };
  bool complete() const override { return true; };

 protected:
  Core* clone() override { return new Credit(*this); };
};
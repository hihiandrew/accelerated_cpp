#include "Core.h"

class Audit : public Core {
 public:
  // constructors
  Audit(){};
  Audit(std::istream& is) : Core(is){};
  // inherited destructor
  // accessors
  double grade() const override { return 0.0; };
  bool valid() const { return true; };
  bool complete() const override { return true; }

 protected:
  Core* clone() override { return new Audit(*this); };
};
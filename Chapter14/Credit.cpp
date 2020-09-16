#include "Credit.h"

double Credit::grade() const {
  if (!homework.empty())
    return Core::grade();
  else
    return (final + midterm) / 2.0;
}
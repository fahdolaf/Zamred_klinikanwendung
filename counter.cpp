#include "counter.h"

#include <stdio.h>

int Counter::Incr() {
  return counter_++;
}


int Counter::value() {
  return counter_;
}

#ifndef NDEBUG
#include "monitoring.h"
#endif

#include <iostream>

int main() {
  void *p = malloc(1024);
  free(p);

#ifndef NDEBUG
  EnableMonitoring();
#endif
  void *p2 = malloc(222);
  free(p2);
  return 0;
}

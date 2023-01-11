#include "monitoring.h"
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <unistd.h>

extern "C" {
void *malloc(size_t size) {
  static void *original_malloc = dlsym(RTLD_NEXT, "malloc");
  assert(original_malloc);
  auto *original_malloc_fn =
      reinterpret_cast<decltype(&::malloc)>(original_malloc);

  void *ret = original_malloc_fn(size);
  if (MemoryMonitoringEnabled()) {
    fprintf(stderr, "%zu %p\n", size, ret);
  }
  return ret;
}
}

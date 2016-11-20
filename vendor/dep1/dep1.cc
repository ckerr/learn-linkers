#include "dep1.h"
#include "dep2.h"

namespace dep1 {
  int Dep1::add(int x) {
    dep2::Dep2 d;
    return d.add(x);
  };
}

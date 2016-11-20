#include <iostream>
#include "caps.h"
#include "dep1.h"
#include "dep2.h"

using namespace std;

int main() {
   myproject::A a(new string("hello world"));
   dep1::Dep1 d1;
   dep2::Dep2 d2;

   cout << "Hello, world!" << endl;
   cout << a.name() << endl;
   cout << d1.add(2) << endl;
   cout << d2.add(1) << endl;

   return 0;
}

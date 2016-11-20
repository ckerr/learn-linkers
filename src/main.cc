#include <iostream>
#include "caps.h"

using namespace std;

int main() {
   myproject::A a(new string("hello world"));

   cout << "Hello, world!" << endl;
   cout << a.name() << endl;

   return 0;
}

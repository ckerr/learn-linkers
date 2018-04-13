#include <iostream>
#include "macros.h"

using std::cout;
using std::endl;

class NotCopyable {
private:
  DISALLOW_COPY_AND_ASSIGN(NotCopyable);
public:
  const int id;
  
  NotCopyable(int id): id(id) {
    cout << "NotCopyable(" << id << ")" << endl;
  }

  ~NotCopyable() {
    cout << "~NotCopyable(" << id << ")" << endl;
  }
};

void testNotCopyable() {
  NotCopyable nc1(1);

  // TODO: print the id of the object
  // printId(nc1);

  // TODO: create a new not-copyable
  // NotCopyable* nc2 = makeNotCopyable(2);
};

int main() {
  testNotCopyable();

  return 0;
};

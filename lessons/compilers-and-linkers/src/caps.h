#include <string>

using std::string;

namespace myproject {

  class A {
  private:
    string *str;
  public:
    A(string* s): str(s) {};

    string* name();
  };

}

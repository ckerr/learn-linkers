#define DISALLOW_COPY(TypeName) \
  TypeName(const TypeName&) = delete

#define DISALLOW_ASSIGN(TypeName) TypeName& operator=(const TypeName&) = delete

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  DISALLOW_COPY(TypeName);                 \
  DISALLOW_ASSIGN(TypeName)

#define DISALLOW_IMPLICIT_CONSTRUCTORS(TypeName) \
  TypeName() = delete;                           \
  DISALLOW_COPY_AND_ASSIGN(TypeName)


#include <iostream>

using std::cout;
using std::endl;

#define PRINT(Str) \
  cout << Str << endl;
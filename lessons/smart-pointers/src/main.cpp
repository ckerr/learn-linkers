#include <iostream>
#include "macros.h"

class A {
private:
    DISALLOW_COPY_AND_ASSIGN(A);
public:
    const int id;
    A(int id): id(id) {
        std::cout << "A(" << id << ")" << std::endl;
    }
    ~A() {
        std::cout << "~A(" << id << ")" << std::endl;
    }
};

class SmartPointer {
public:
    A* a;
    SmartPointer(A* a); // TODO
    A* operator->(); // TODO
};

void printId(SmartPointer sp) {
    std::cout << "ID: " << sp->id << std::endl;
}

void print2(SmartPointer sp) {
    printId(sp);
}

SmartPointer make(int id) {
    return SmartPointer(new A(id));
}

int main() {
    // TEST
    SmartPointer sp(new A (1));
    printId(sp);

    // TEST
    {
        SmartPointer sp(new A (2));
    }

    // TEST
    {
        SmartPointer sp(new A (3));
        print2(sp);
    }

    // TEST
    {
        SmartPointer spA(new A (4));
        SmartPointer spB(new A (5));

        spA = spB;
    }

    // TEST
    {
        SmartPointer spA = make(6);
    }

    return 0;
}

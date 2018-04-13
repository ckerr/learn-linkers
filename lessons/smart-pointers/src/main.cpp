#include <iostream>
#include "macros.h"

#define TEST(name) std::cout << "TEST: " << name << std::endl;
#define INFO(name) std::cout << "INFO: " << name << std::endl;

class A {
private:
    DISALLOW_COPY_AND_ASSIGN(A);
public:
    const int id;
    A(int id): id(id) {
        std::cout << "DATA: A(" << id << ")" << std::endl;
    }
    ~A() {
        std::cout << "DATA: ~A(" << id << ")" << std::endl;
    }
};

class PointerBox {
public:
    PointerBox(A* a);
};

class SmartPointer {
private:
    PointerBox* pb;
public:
    SmartPointer();
    SmartPointer(A* a): pb(new PointerBox(a)) {}
    A* operator->();
    SmartPointer operator=(const SmartPointer& p);
    SmartPointer(const SmartPointer& p);
};

void printId(SmartPointer sp) {
    std::cout << "INFO: " << sp->id << std::endl;
}

void print2(SmartPointer sp) {
    printId(sp);
}

SmartPointer make(int id) {
    return SmartPointer(new A(id));
}

int main() {
    TEST(1)
    {
        SmartPointer sp(new A (1));
        printId(sp);
    }

    TEST(2)
    {
        SmartPointer sp(new A (2));
    }

    TEST(3)
    {
        SmartPointer sp(new A (3));
        print2(sp);
    }

    TEST(4)
    {
        SmartPointer spA(new A (4));
        SmartPointer spB(new A (5));

        spA = spB;
        
        INFO("A(4) Should be deleted");
    }

    TEST(4)
    {
        SmartPointer spA(new A (6));

        spA = spA;
        INFO("A(6) Should not be deleted");
    }

    TEST(5)
    {
        SmartPointer spA = make(7);
    }

    TEST(6)
    {
        SmartPointer spA;
        SmartPointer spB;

        spA = make(8);
        spB = spA;

        INFO("A(8) Should not be deleted");
    }

    TEST(7)
    {
        SmartPointer spA = make(9);
        SmartPointer spB;

        spA = spB;

        INFO("A(9) Should be deleted");
    }

    return 0;
}

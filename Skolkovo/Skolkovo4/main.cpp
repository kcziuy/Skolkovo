#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class A {
public:
    int f1;
    A() { cout << "A()" << endl; }

     ~A() { cout << "~A()" << endl; }
};

class B : public A {
public:
    int* f2;
    B() {
        f2 = new int[200];
        cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl;
        delete f2;
    }
};

int main()
{
    //Вариант, где не нужен виртуальный деструктор
    //B b;

    //Вариант, где нужен виртуальный деструтор
    A * pA = new B;
    delete pA;

    return EXIT_SUCCESS;
}

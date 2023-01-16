
#include <iostream>
#include <functional>
#include "Delegate.h"
using namespace std;
class TestA {

public:
    void Func1() { cout << " TestA" << endl; }
};

class TestB {

public:
    void Func1() { cout << " TestB" << endl; }
};

class TestC {

public:
    void Func1() { cout << " TestC" << endl; }
};

int main()
{
    TestA AA;
    TestB BB;
    TestC CC;

    FDelegate<> CallBackFuncs;
    CallBackFuncs += bind(&TestA::Func1, &AA);
    CallBackFuncs += bind(&TestB::Func1, &BB);
    CallBackFuncs += bind(&TestC::Func1, &CC);

    CallBackFuncs();
    CallBackFuncs -= bind(&TestB::Func1, &BB);

    CallBackFuncs();
    CallBackFuncs -= bind(&TestB::Func1, &BB);

    CallBackFuncs();

}

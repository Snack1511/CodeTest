#include <iostream>
#include <typeinfo>
using namespace std;

class A 
{
	virtual void AF() {}
public:
	size_t Get_Hash() { return typeid(*this).hash_code(); }
	const char* Get_Name() { return typeid(*this).name(); }
};

class B : public A {};
class C : public A {};
class D : public A {};


int main()
{
	B b = B();
	C c = C();
	D d = D();
	A a = A();

	

	if (typeid(B).hash_code() == b.Get_Hash())
		cout << "B·Î ³ª¿È" << endl;
	else
		cout << b.Get_Name() << endl;

	return 0;
}
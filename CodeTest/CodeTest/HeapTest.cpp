
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW

#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif
#endif

#include <iostream>
#include <map>
using namespace std;

template<typename T>
void Safe_Delete_Array(T& Temp)
{
	if (Temp)
	{
		delete[] Temp;
		Temp = nullptr;
	}
}

class A {
public:
	A() {}
	~A() {}
private:
	int b = 0;


};
int main()
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

	map<const char*, A*> _mapTest;
	
	while (_mapTest.size() < 3)
	{
		char* pstr = new char[512];
		cin >> pstr;
		_mapTest.emplace(pstr, new A);
	}

	for (auto& mapValue : _mapTest)
	{
		delete[] mapValue.first;
		//Safe_Delete_Array(mapValue.first);
		delete mapValue.second;
	}
	
	
	//int* a = new int[512];
	//A* b = new A[512];
	return 0;
}
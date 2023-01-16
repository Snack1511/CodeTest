#include <iostream>
#include <tuple>
#include<windows.h>
#include <thread>
using namespace std;

int main()
{
	//tuple<INT, INT32, INT64, DWORD_PTR, WCHAR, thread, BYTE, HRESULT, HWND> Test;
	//cout << typeid(get<0>(Test)).name() << endl;
	//cout << typeid(get<1>(Test)).name() << endl;
	//cout << typeid(get<2>(Test)).name() << endl;
	//cout << typeid(get<3>(Test)).name() << endl;
	//cout << typeid(get<4>(Test)).name() << endl;
	//cout << typeid(get<5>(Test)).name() << endl;
	//cout << typeid(get<6>(Test)).name() << endl;
	//cout << typeid(get<7>(Test)).name() << endl;
	//cout << typeid(get<8>(Test)).name() << endl;
	tuple<int, bool, float> Test;
	Test = make_tuple(0, true, 3.0f);
	get<1>(Test) = false;

	cout << get<1>(Test) << endl;

}

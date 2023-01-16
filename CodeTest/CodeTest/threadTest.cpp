#include <iostream>
#include <thread>
#include <vector>
#include <functional>
using namespace std;

void func(int minNum, int maxnum, int* pReturn, int ThreadNum) {
	for (int i = minNum; i < maxnum; ++i) {
		*pReturn += i;
		std::cout << "쓰레드 "<< ThreadNum << " 작동중!\n";
	}
}

int main()
{

	vector<shared_ptr<thread>> ThreadArr;
	shared_ptr<int> ResultPtr(new int[100], [](int* p) {delete[]p; });
	//function<void(int, int, int, int&)> funtional = bind(func, placeholders::_1, placeholders::_2, placeholders::_3, placeholders::_4);
	//funtional(0, 100, Index, iResult1);
	int LimitValue = 10000;
	for (int i = 0; i < 100; ++i)
	{
		ThreadArr.push_back(make_shared<thread>(func, LimitValue * i, LimitValue *(i +1), ResultPtr.get()+i, i));
	}
	for (auto& Thread : ThreadArr)
	{
		Thread.get()->join();
	}
	int Result = 0;
	for (int i = 0; i < 100; ++i)
	{
		Result += ResultPtr.get()[i];
	}

	cout << Result << endl;

	ThreadArr.clear();
	ResultPtr.reset();


	return 0;
}


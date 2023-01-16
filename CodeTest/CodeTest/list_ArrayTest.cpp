#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	int* pInt1 = new int(1);
	int* pInt2 = new int(2);
	int* pInt3 = new int(3);
	int* pInt4 = new int(4);
	int* pInt5 = new int(5);

	list<int*> pintlist;
	pintlist.push_back(pInt1);
	pintlist.push_back(pInt2);
	pintlist.push_back(pInt3);
	pintlist.push_back(pInt4);
	pintlist.push_back(pInt5);

	list<int> intList;
	for (int i = 0; i < 10; ++i)
		intList.push_back(i);

	vector<int> intArr;
	for (int i = 0; i < 10; ++i)
		intArr.push_back(i);

	cout << *((&intArr[0]) + 1) << endl;
	cout << *(&(intList.front()) + 1) << endl;

	delete pInt1;
	delete pInt2;
	delete pInt3;
	delete pInt4;
	delete pInt5;
	return 0;
}
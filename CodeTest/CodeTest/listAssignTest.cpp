#include <iostream>
#include <list>

using namespace std;

void main() 
{
	list<int> List0To9;
	list<int> List10To19;
	for (int i = 0; i < 10; ++i)
	{
		List0To9.push_back(i);
	}

	for (int i = 10; i < 20; ++i)
	{
		List10To19.push_back(i);
	}

	list<int> Total;
	list<int> reverse;

	Total.merge(List0To9);
	Total.merge(List10To19);
	reverse.assign(List0To9.rbegin(), List0To9.rend());

	for (auto& value : Total)
	{
		cout << value << " ";
	}
	cout << endl;

	for (auto& value : reverse)
	{
		cout << value << " ";
	}
	cout << endl;
}
#include <vector>
#include <iostream>
using namespace std;

struct test 
{
	vector<int> vect;
};

int main() {
	test Test;
	cout << sizeof(test) << endl;
	for (int i = 0; i < 10; ++i) {
		Test.vect.push_back(i);
	}
	for (int i = 0; i < 10; ++i) {
		cout << Test.vect[i] << endl;
	}

	return 0;
}
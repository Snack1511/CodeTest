#include<iostream>
#include<functional>
#include <Windows.h>
using namespace std;

int main() {

	string teststr = "";
	teststr = "123456";
	size_t hashsize = hash<string>()(teststr);
	teststr = "134336";
	size_t hashsize2 = hash<string>()(teststr);

	cout << hashsize << ", " << hashsize2 << endl;;

	return 0;
}
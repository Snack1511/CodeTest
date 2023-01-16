#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;

void SaveTest() 
{
	ofstream writeFile;
	writeFile.open("../Test/TestSave.bin", ios::binary);

	char* Bumb1 = new char[4];
	char* Bumb2 = new char[11];

	char* Bumb3 = new char[16];

	char* Bumb4 = new char[4];
	char* Bumb5 = new char[4];
	char* Bumb6 = new char[4];
	char* Bumb7 = new char[4];
	char* Bumb8 = new char[4];

	char* Bumb9 = new char[4500208];

	char* Bumb10 = new char[180000];
	char* Bumb11 = new char[540000];

	char* Bumb12 = new char[300];
	char* Bumb13 = new char[600];


	char* Bumb14 = new char[540000];
	memset(Bumb1, 1, sizeof(char) * 4);
	memset(Bumb2, 1, sizeof(char) * 11);

	memset(Bumb3, 1, sizeof(char) * 16);

	memset(Bumb4, 1, sizeof(char) * 4);
	memset(Bumb5, 1, sizeof(char) * 4);
	memset(Bumb6, 1, sizeof(char) * 4);
	memset(Bumb7, 1, sizeof(char) * 4);
	memset(Bumb8, 1, sizeof(char) * 4);

	memset(Bumb9, 1, sizeof(char) * 4500208);
	memset(Bumb10, 1, sizeof(char) * 180000);
	memset(Bumb11, 1, sizeof(char) * 540000);
	memset(Bumb12, 1, sizeof(char) * 300);
	memset(Bumb13, 1, sizeof(char) * 600);
	memset(Bumb14, 1, sizeof(char) * 540000);


	writeFile.write(Bumb1, sizeof(char) * 4);
	writeFile.write(Bumb2, sizeof(char) * 11);
	writeFile.write(Bumb3, sizeof(char) * 16);
	writeFile.write(Bumb4, sizeof(char) * 4);
	writeFile.write(Bumb5, sizeof(char) * 4);
	writeFile.write(Bumb6, sizeof(char) * 4);
	writeFile.write(Bumb7, sizeof(char) * 4);
	writeFile.write(Bumb8, sizeof(char) * 4);
	writeFile.write(Bumb9, sizeof(char) * 4500208);
	writeFile.write(Bumb10, sizeof(char) * 180000);
	writeFile.write(Bumb11, sizeof(char) * 540000);
	writeFile.write(Bumb12, sizeof(char) * 300);
	writeFile.write(Bumb13, sizeof(char) * 600);
	writeFile.write(Bumb14, sizeof(char) * 540000);

	writeFile.close();

	delete[] Bumb1;
	delete[] Bumb2;
	delete[] Bumb3;
	delete[] Bumb4;
	delete[] Bumb5;
	delete[] Bumb6;
	delete[] Bumb7;
	delete[] Bumb8;
	delete[] Bumb9;
	delete[] Bumb10;
	delete[] Bumb11;
	delete[] Bumb12;
	delete[] Bumb13;
	delete[] Bumb14;
}
void LoadTest() 
{
	ifstream readFile;
	readFile.open("../Test/TestSave.bin", ios::binary);

	char* Bumb1 = new char[4];
	char* Bumb2 = new char[11];

	char* Bumb3 = new char[16];

	char* Bumb4 = new char[4];
	char* Bumb5 = new char[4];
	char* Bumb6 = new char[4];
	char* Bumb7 = new char[4];
	char* Bumb8 = new char[4];

	char* Bumb9 = new char[4500208];

	char* Bumb10 = new char[180000];
	char* Bumb11 = new char[540000];

	char Bumb12[300] = "";
	char Bumb13[600] = "";


	char* Bumb14 = new char[540000];
	memset(Bumb1, 0, sizeof(char) * 4);
	memset(Bumb2, 0, sizeof(char) * 11);
					  
	memset(Bumb3, 0, sizeof(char) * 16);
					  
	memset(Bumb4, 0, sizeof(char) * 4);
	memset(Bumb5, 0, sizeof(char) * 4);
	memset(Bumb6, 0, sizeof(char) * 4);
	memset(Bumb7, 0, sizeof(char) * 4);
	memset(Bumb8, 0, sizeof(char) * 4);

	memset(Bumb9, 0, sizeof(char) * 4500208);
	memset(Bumb10, 0, sizeof(char) * 180000);
	memset(Bumb11, 0, sizeof(char) * 540000);
	memset(Bumb12, 0, sizeof(char) * 300);
	memset(Bumb13, 0, sizeof(char) * 600);
	memset(Bumb14, 0, sizeof(char) * 540000);


	readFile.read(Bumb1, sizeof(char) * 4);
	readFile.read(Bumb2, sizeof(char) * 11);
	readFile.read(Bumb3, sizeof(char) * 16);
	readFile.read(Bumb4, sizeof(char) * 4);
	readFile.read(Bumb5, sizeof(char) * 4);
	readFile.read(Bumb6, sizeof(char) * 4);
	readFile.read(Bumb7, sizeof(char) * 4);
	readFile.read(Bumb8, sizeof(char) * 4);
	readFile.read(Bumb9, sizeof(char) * 4500208);
	readFile.read(Bumb10, sizeof(char) * 180000);
	readFile.read(Bumb11, sizeof(char) * 540000);
	readFile.read(Bumb12, sizeof(char) * 300);
	readFile.read(Bumb13, sizeof(char) * 600);
	readFile.read(Bumb14, sizeof(char) * 540000);

	readFile.close();

	delete[] Bumb1;
	delete[] Bumb2;
	delete[] Bumb3;
	delete[] Bumb4;
	delete[] Bumb5;
	delete[] Bumb6;
	delete[] Bumb7;
	delete[] Bumb8;
	delete[] Bumb9;
	delete[] Bumb10;
	delete[] Bumb11;
	delete[] Bumb14;
}

int main() 
{
	SaveTest();
	LoadTest();
}
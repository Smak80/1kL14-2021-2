#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	//Простой пример работы с бинарными файлами

	ofstream f;
	f.open("data.txt", ios_base::binary);
	if (f.is_open()) {
		int value = 15687696;
		f.write((const char*)&value, sizeof(value));
		f.close();
	}
	ifstream rf;
	rf.open("data.txt", ios_base::binary);
	if (rf.is_open()) {
		int value;
		rf.read((char*)&value, sizeof(value));
		cout << value;
		rf.close();
	}
}
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	struct man {
		char lastname[30];
		char firstname[30];
		char birth[11];
		char address[100];
		char tel[13];
		int ege = 250;
	};
	man m1 = {
		"������", 
		"����", 
		"12.12.2012", 
		"������, �����������, 18", 
		"+79271110500",
		243
	};
	m1.ege = 234; //��������� � ���� ��������� �� ��������
	man* pm = &m1;
	pm->ege = 298;//��������� � ���� ��������� �� ���������
	ofstream wf;
	wf.open("anketa.dat", ios_base::binary);
	if (wf.is_open()) {
		wf.write((const char*)pm, sizeof(man));
		wf.close();
	}
	ifstream rf;
	man m2;
	rf.open("anketa.dat", ios_base::binary);
	if (rf.is_open()) {
		rf.read((char*)&m2, sizeof(man));
		rf.close();
	}
	cout << m2.address << endl << m2.ege << endl;
}
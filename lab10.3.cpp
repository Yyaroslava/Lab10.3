#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip>
#include <Windows.h>

using namespace std;

void CreateTXT(char* fname) // ��������� ����� � �������� �����
{
	ofstream fout(fname); // ������� ���� ��� ������
	char ch; // ������� �����������, �� ������������ ��������
	string s; // �������� ������������ �����
	do {
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "������ ����� ����������� ������ ��������: ";
		getline(cin, s);
		fout << s << " "; // �������� ���� � ����
		cout << "������ ����� �������� ������ ��������: ";
		getline(cin, s);
		fout << s << " ";
		cout << "������ ����� ��������: ";
		int n;
		cin >> n;
		fout << n << endl;
		cout << "������ ������ �� ���� �������? (y/n): ";
		cin >> ch;
	}
	while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname); // ������� ���� ��� ����������
	string s; // ���������� �����
	while (getline(fin, s)) // ���� ����� ��������� �����
	{
		cout << s << endl; // �������� ���� �� �����
	}
}

void AddTXT(char* fname) {
	ofstream fout(fname, ios::app);
	char ch;
	string s;

	if (!fout) {
		cerr << "��������� ������� ����" << endl;
		return;
	}
	do {
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "������ ����� ����������� ������ ��������: ";
		getline(cin, s);
		fout << s << " "; // �������� ���� � ����
		cout << "������ ����� �������� ������ ��������: ";
		getline(cin, s);
		fout << s << " ";
		cout << "������ ����� ��������: ";
		int n;
		cin >> n;
		fout << n << endl;
		cout << "������ ������ �� ���� �������? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void SearchTXT(char* fname)
{
	ifstream fin(fname); 
	string start, end;
	int number, find_number;
	cin.get(); 
	cin.sync();
	cout << "������ ����� ��������: ";
	cin >> find_number;
	int k = -1;
	while (fin >> start >> end >> number) { 
		if (number == find_number) {
			cout << "�������� ������� �� " << start << " �� " << end << endl;
			return;
		}
	}
	cout << "������� �� ��������." << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[100] = "";
	int choice;
	do {
		cout << "������ ����� ������� �������:" << endl << endl;
		cout << " [1] - ������ ����" << endl;
		cout << " [2] - �������� ���� �� ������ ��� �� ���������" << endl;
		cout << " [3] - ����������� ����" << endl;
		cout << " [4] - ��������� ����" << endl;
		cout << " [5] - ������ ������� �� �������" << endl;
		cout << endl;
		cout << " [0] - ����� �� ��������" << endl << endl;
		cout << "������ ����� �������: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			cout << "������ ����� �����: ";
			cin >> fname;
			break;
		case 2:
			if (fname == "") {
				cout << "������ ����� �����: ";
				cin >> fname;
			}
			CreateTXT(fname);
			break;
		case 3:
			if (fname == "") {
				cout << "������ ����� �����: ";
				cin >> fname;
			}
			PrintTXT(fname);
			cout << endl;
			break;
		case 4:
			if (fname == "") {
				cout << "������ ����� �����: ";
				cin >> fname;
			}
			AddTXT(fname);
			break;
		case 5:
			if (fname == "") {
				cout << "������ ����� �����: ";
				cin >> fname;
			}
			SearchTXT(fname);
			cout << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ������������ ����� ������� " << endl;
		}
	} while (choice != 0);
	return 0;
}

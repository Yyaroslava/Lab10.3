#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <iomanip>
#include <Windows.h>

using namespace std;

void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача, чи продовжувати введення
	string s; // введений користувачем рядок
	do {
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "Введіть назву початкового пункту маршруту: ";
		getline(cin, s);
		fout << s << " "; // записали його у файл
		cout << "Введіть назву кінцевого пункту маршруту: ";
		getline(cin, s);
		fout << s << " ";
		cout << "Введіть номер маршруту: ";
		int n;
		cin >> n;
		fout << n << endl;
		cout << "Хочете ввести ще один маршрут? (y/n): ";
		cin >> ch;
	}
	while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
}

void AddTXT(char* fname) {
	ofstream fout(fname, ios::app);
	char ch;
	string s;

	if (!fout) {
		cerr << "Неможливо відкрити файл" << endl;
		return;
	}
	do {
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "Введіть назву початкового пункту маршруту: ";
		getline(cin, s);
		fout << s << " "; // записали його у файл
		cout << "Введіть назву кінцевого пункту маршруту: ";
		getline(cin, s);
		fout << s << " ";
		cout << "Введіть номер маршруту: ";
		int n;
		cin >> n;
		fout << n << endl;
		cout << "Хочете ввести ще один маршрут? (y/n): ";
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
	cout << "Введіть номер маршруту: ";
	cin >> find_number;
	int k = -1;
	while (fin >> start >> end >> number) { 
		if (number == find_number) {
			cout << "Знайдено маршрут від " << start << " до " << end << endl;
			return;
		}
	}
	cout << "Маршрут не знайдено." << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[100] = "";
	int choice;
	do {
		cout << "Оберіть номер потрібної команди:" << endl << endl;
		cout << " [1] - Обрати файл" << endl;
		cout << " [2] - Створити файл та ввести дані із клавіатури" << endl;
		cout << " [3] - Переглянути файл" << endl;
		cout << " [4] - Доповнити файл" << endl;
		cout << " [5] - Знайти маршрут за номером" << endl;
		cout << endl;
		cout << " [0] - Вихід із програми" << endl << endl;
		cout << "Введіть номер команди: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			cout << "Введіть назву файла: ";
			cin >> fname;
			break;
		case 2:
			if (fname == "") {
				cout << "Введіть назву файла: ";
				cin >> fname;
			}
			CreateTXT(fname);
			break;
		case 3:
			if (fname == "") {
				cout << "Введіть назву файла: ";
				cin >> fname;
			}
			PrintTXT(fname);
			cout << endl;
			break;
		case 4:
			if (fname == "") {
				cout << "Введіть назву файла: ";
				cin >> fname;
			}
			AddTXT(fname);
			break;
		case 5:
			if (fname == "") {
				cout << "Введіть назву файла: ";
				cin >> fname;
			}
			SearchTXT(fname);
			cout << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели неправильний номер команди " << endl;
		}
	} while (choice != 0);
	return 0;
}

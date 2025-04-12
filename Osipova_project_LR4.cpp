#include <iostream>

#include <map>

#include <string>

#include <functional>

using namespace std;





//проверка корректности вводимых данных 

bool UserChar(string input) {

	//если строка пустая - ввод некорректен

	if ((input.empty()) || (input.length() != 1)) return false;



	return true;

}





bool UserInput(string input) {

	//если строка пустая - ввод некорректен

	if ((input.empty()) && (input.length() != 1)) return false;

	//попытаться

	try {

		//преобразование введенного значения в тип int

		int number = stoi(input);

		if (number < 0) return false;

	}

	catch (...) //если возникла ошибка в блоке try

	{

		return false;

	}

	return true;

}



//функция ввода данных для выбора варианта



void enterNumber(int& varLink, string label)

{

	string str_input;

	cout << label << " - ";

	//ввод значения в текстовом виде

	getline(cin, str_input);

	//пока ввод некорректен

	while (!UserInput(str_input)) {

		cout << label << " = ";

		//ввод значения в текстовом виде

		getline(cin, str_input);

	}

	//присвоение переменной varLink преобразованного 

	// в тип int 

	//правильно введенного текстового значения 

	varLink = stoi(str_input);

}



//функция ввода данных

void enterChar(char& varLink, string label)

{

	string str_input;

	cout << label << " - ";

	//ввод значения в текстовом виде

	getline(cin, str_input);

	//пока ввод некорректен

	while (!UserChar(str_input)) {

		cout << label << " = ";

		//ввод значения в текстовом виде

		getline(cin, str_input);

	}

	//присвоение переменной varLink преобразованного 

	// в тип int 

	//правильно введенного текстового значения 

	varLink = str_input[0];

}



//глобальные переменные

char ch1, ch2;



void inputFirstChar() {
	enterChar(ch1, "Введите первый символ");

		//branch_fun_1

}



// Функция для ввода второго символа

void inputSecondChar() {
	enterChar(ch2, "Введите второй символ");


	//branch_fun_2

}





// Функция для вывода символа и его кода ASCII

void printCharAndAscii() {



	//branch_fun_3

}



// Функция для вывода суммы кодов ASCII

void printAsciiSum() {


	//branch_fun_4



}



struct MenuItem {

	string title;

	function<void()> action;

};



int main() {

	setlocale(LC_ALL, "ru");

	map<int, MenuItem> menu = 

	{

		{ 1,{" Ввести первый символ", inputFirstChar } },

		{2, {" Ввести второй символ", inputSecondChar}},

		{3, {" Вывести каждый символ и код ASCII", printCharAndAscii}},

		{4, {" Вывести сумму кодов ASCII символов ch1 и ch2", printAsciiSum}},

	};

	int choice = 0;



	while (true) {

		cout << "Меню:" << endl;

		for (const auto& item : menu) {

			cout << "Task " << item.first << ". " << item.second.title << endl;

		}

		cout << "0. Выход" << std::endl;

		enterNumber(choice, "Введите пункт из меню ");

		if (choice == 0) {

			cout << "© 2025 FirstName LastName" << endl;

			break;

		}

		cout << endl;

		if (menu.find(choice) != menu.end()) {

			menu[choice].action();

		}

		else {

			cout << "Некорректный ввод.";

		}

		cout << endl;

	}

	return 0;

}
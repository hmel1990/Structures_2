#include <iostream>
#include<string>
using namespace std;

/*
struct Jar;

void test(Jar * param)
{
	Jar* jar = param;
}

int main()
{
	Jar* param = new Jar;
	test(param);

	struct Jar
	{
		double heigt;
		double width;
	};

}
*/

enum class Materials { GLASS, IRON, STEEL, WOOD, CLAY, PLASTIC, CERAMICS };
struct Date 
{
	int day;
	int month;
	int year;
};

struct Manufacturer 
{
	string name;
	Date since;
	string country;
};
struct Jar {
	double height = 26;
	double diameter = 20;
	double volume = 5;
	Manufacturer manufacturer;
	string description; // описание
	long long article; // id, code
	string* photo_urls; // динамический массив
	Materials* materials; // если материалов несколько, и сами типы материалов нужно ограничить
	string category; // категория товара
	double price;
	bool has_hydrozatvor; // либо есть, либо нет
	double weight;
	string* additions = nullptr;
	string* recommendations;
	string* feedback;
};

//int main() 
//{
//
//	setlocale(0, "");

	/*
	//создание объекта типа Jar
	cout << sizeof(Jar) << "\n"; // 800272
	Jar jar; // создание на стеке
	//Jar jar2;
	Jar* j = new Jar(); // объект создаётся в хипе

	Jar* j2 = new Jar(); // 4 банки в хипе
	Jar* j3 = new Jar(); // 4 указателя на стеке
	Jar* j4 = new Jar();
	*/
	

	/*	
	//____________________________________________________________________________________________
	//разреженный массив (указатель на массив указателей каждый из которых указывает на один объект)
 
Jar **
 
int main() {

	Jar jar; // создание 1 объекта на стеке

	Jar* j = new Jar(); // создание 1 объекта в хипе (+ указатель на стеке)

	Jar* ptr; // здесь нет объекта

	Jar star[100]; // создание 100 объектов типа структуры на стеке

	int size = 100;

	Jar* dynar = new Jar[size]; // создание динамического массива 
	*/

	/*
		Jar jar = { 26, 20, 5, {"Manuf1", {4, 10, 2024}, "Украина"}, "описание баночки..." };
	cout << jar.height << "\n"; // после описания все поля будут равны 0
	cout << jar.diameter << "\n";
	*/


	/*
	struct Jar //можно сразу указывать в структуре значение поля по умолчанию
	{
		double height = 26;
		double diameter = 20;
		double volume = 5;
	}
	*/

	/*
			//Jar jar;
		string lenta = "red";
		jar.additions = &lenta;

		jar.manufacturer.since.day = 1;
		jar.manufacturer.since.month = 1;
		jar.manufacturer.since.year = 1970;

		jar.manufacturer.country = "Украина";

		//jar.manufacturer.name = "Зелёный ёжик";
		cout << "Укажите имя производителя";
		getline(cin, jar.manufacturer.name);
		cout << jar.manufacturer.name << "\n";

		Manufacturer m;
		jar.manufacturer = m;
		// если нужно скопировать один объект структуры в другой,
		// то достаточно применить оператор =, копировать элементы поштучно из одной структуры в другую не нужно
		

		//____________________________________________________________________________________________________________________________________________________________________________________________

		cout << "And now - height: ";
		cin >> jar.height;
		cout << jar.height << "\n";

		cin.ignore(); // очистка буфера (если сначала идет ввод при помощи cin >> а потом при помощи getline(cin, jar.description) нужно почистить буфер от команды cin >>)

		cout << "Please tell some words about this jar: ";
		// jar.description = "my favourite jar!";
		// cin >> jar.description;
		getline(cin, jar.description);
		cout << jar.description << "\n";


		cout << "OK!\n";

	*/
	
//} 
 
//(функция main одна для всех блоков /* */ )_______________________



//____________________________________________________________________________________________________________________________________________________________________________________________
//____________________________________________________________________________________________________________________________________________________________________________________________



void jar_user_input(Jar& j) {
	cout << "Please, enter description for jar: ";
	getline(cin, j.description);
	cout << "Please, enter price of jar: ";
	cin >> j.price;
	cout << "Please, enter height of jar: ";
	cin >> j.height;
	cout << "Please, enter diameter of jar: ";
	cin >> j.diameter;
	// ... etc TODO
	cin.ignore();
}

void jar_random_fill(Jar& j) {
	j.description = "...";
	j.article = rand() % 100000;
	j.diameter = rand() % 100 + 1; // 1-100
	j.height = rand() % 200 + 1; // 1-200
	j.price = rand() % 1000000 + (rand() % 10 / 10.0);
	j.weight = rand() % 5 + 0.01;
	j.manufacturer.name = "Alex";
	j.manufacturer.since.day = rand() % 28 + 1; // 1-28
	j.manufacturer.since.month = rand() % 12 + 1; // 1-12
	j.manufacturer.since.year = rand() % 55 + 1970; // 1970-2024
	// ...
}

void jar_print(const Jar& j) {
	cout << "====================================\n\n";
	cout << "Description: " << j.description << "\n";
	cout << "Height: " << j.height << "\n";
	cout << "Diameter: " << j.diameter << "\n";
	cout << "Price: " << j.price << "\n";
	cout << "Manufacturer: " << j.manufacturer.name << ", since " <<
		j.manufacturer.since.day << "." <<
		j.manufacturer.since.month << "." <<
		j.manufacturer.since.year << "\n";
	// ... etc
	cout << "\n====================================\n\n";
}

Jar go_to_store() {
	Jar jar;
	jar_random_fill(jar);
	return jar;
}

void start_randomize() {
	srand(time(0));
	rand();
}

int main() {
	start_randomize();

	Jar jar = go_to_store();
	jar_print(jar);
	// jar_free(jar);

	// 1) заполнение вручную пользователем - функция
	// 2) заполнение случайным образом - функция
	// 3) заполнение значениями по умолчанию - функция
	// 4) заполнение значениями, переданными через аргументы - несколько функций
	// 5) показ состояния объекта - функция
	// 6) сохранение в файл
	// 7) загрузка данных из файла
	// 8) отправка в БД
	// 9) извлечение из БД
	// 10) отправка по сети на сервер
	// 11) получение ответа от сервера


}
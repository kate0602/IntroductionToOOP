#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

class String;
String operator+(const String& left, const String& right);


class String
{
	int size;  //razmer stroki v baitah
	char* str;   //adres stroki v dinamic pamyati

public:
	int get_size()const
	{
		return size;
	}
	     
	const char* get_str()const
	{
		return str;
	}
	
	char* get_str()
	{
		return str;
	}

	// Constructor

	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}

	String(const char str[]) :size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;	//Поскольку класс хранит размер в Байтах, +1 нужен для хранения NULL-terminator
		//this->str = new char[size] {};	//Выделяем память под строку
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}

	String(const String& other) :size(other.size), str(new char[size] {})
	{
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}


	String(String&& other) :size(other.size), str(other.str)
	{
		//Shallow copy:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;

	}
	~String()
	{
		delete[] this->str;
	    cout << "Destructor: \t" << this << endl;

	}
	           
	//            Operator


	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
		if (this == &other)return *this;
		delete[] str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;

	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	

	char& operator[](int i)
	{
		return str[i];
	}


	//MeTod

	void print()const
	{
		cout << "Size " << size << endl;
		cout << "Str " << str << endl;
		
	}
};


String operator+(const String& left, const String& right)
{

	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];

	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];

	return cat;
}


std::ostream& operator <<(std::ostream& os, const String& obj)

{
	return os << obj.get_str();


}

#define HOME_WORK
//#define CONSTRUCTORS_CALLING

void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello String" << endl;
	//String str1;
	//str1.print();

	//String str = "Hello";
	//str.print();
	//cout << str << endl;


#ifdef HOME_WORK
	String str1 = "Hello";
	str1.print();
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	String str3 = str1 + str2;
	//String str3;
	//str3 = str1 + str2;
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;


#endif // HOME_WORK


#ifdef CONSTRUCTORS_CALLING
	String str1;		//Default constructor
	str1.print();

	String str2(22);	//Single-Argument constructor 'int'
	str2.print();

	String str3 = "Hello";//Single-Argument constructor 'const char*'
	str3.print();

	String str4();	//DefaultConstructor НЕВОЗМОЖЕНО вызвать таким образом.

	//str4.print();
	//Если нужно явно вызвать конструктор по умолчаниию, то это можно сделать так:

	String str5{};	//Default constructor
	str5.print();

	String str6{ "World" };
	str6.print();

	String str7 = str3;	//CopyConstructor
	str7.print();

	String str8;
	str8 = str6;	//CopyAssignment
	str8.print();
#endif // CONSTRUCTORS_CALLING

	





}
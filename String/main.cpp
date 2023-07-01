#include<iostream>
using namespace std;

class String
{
	int size;  //razmer stroki v baitah
	char* str;   //adres stroki v dinamic pamyati

public:
	      // Constructor

	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
	    cout << "Destructor: \t" << this << endl;
	}
	           //MeTod

	void print()const
	{
		cout << "Size " << size << endl;
		cout << "Str " << str << endl;
		
	}
};

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello String" << endl;
	String str1;
	str1.print();
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define delimiter "\n-------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}

	int get_numerator()const
	{
		return numerator;
	}

	int get_denominator()const
	{
		return denominator;
	}


	void set_integer(int integer)
	{
		this->integer = integer;

	}

	void set_numerator(int numerator)
	{
		this->numerator = numerator;

	}

	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//Constructor:

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}

	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:    \t" << this << endl;
	
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:    \t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)

	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:   \t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:   \t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:        \t" << this << endl;
	}

	//Operators
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction&operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigtment:  \t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}

	Fraction& operator /=(const Fraction& other)
	{
		return *this = *this / other;

	}


	//Increment/Decrement

	Fraction& operator++() //Prefix
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction operator++(int)//Postfix (Suffix) increment
	{
		to_proper();
		Fraction old = *this;
		integer++;
		return old;

	}
	             //Type-case
	explicit operator int()
	{
		to_proper();
		return integer;
	}
	operator double()
	{
		return integer + (double)numerator / denominator;
	}


	//Metod:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
		return inverted;
	}

	Fraction& reduce()
	{
		int more, less,rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;   // GCD наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
			return *this;
	}

	
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/

	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator()* right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(), 
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		right.get_numerator() * left.get_denominator()
	).to_proper();*/
		
	return left * right.inverted();
}


bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}

bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
	//return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)

{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
#ifdef SIMPLE_INPUT
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	/*obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	obj(integer, numerator, denominator);
#endif // SIMPLE_INPUT

	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;

	is.getline(buffer, SIZE);

	int number[3] = {};
	int n = 0;	//количество введенных чисел
	char delimiters[] = "() /";

	
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[n++] = atoi(pch);
	}
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]); break;
	}
	
	return is;
}

//#define CONSTRUCTOR_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT
//#define ISTREAM_OPERATOR
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSIONS_FROM_OTHER_TO_CLASS


void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHECK

	int a;
	Fraction A;
	A.print();

	Fraction B = 5; //Single-argument
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3);
	D.print();


#endif // CONSTRUCTOR_CHECK


#ifdef ARITHMETICAL_OPERATORS_CHECK



	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*double a = 2;
	double b = 5;
	double c = a * b;

	Fraction C = A * B;
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();*/


	A *= B;
	A.print();

	A /= B;
	A.print();

#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef DEBINCREMENT_DECREMENTUG

	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";

	}
	cout << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
	
#endif // DEBINCREMENT_DECREMENTUG


	//Fraction A(2, 3, 4);
	//cout << A << endl;
	// 
	//cout <<(2=2) <,endl;
	 
	//cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	//cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 2) > Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 2) < Fraction(5, 10)) << endl;
	//cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;
	//cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;

#ifdef DISTREAM_OPERATOREBUG
	Fraction A(2, 3, 4);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;
#endif // DISTREAM_OPERATOREBUG

#ifdef TYPE_CONVERSIONS_BASICS
	int a = 2;
	double b = 3;
	int c = a + b;
	int d = 8.3;
	cout << d << endl;
#endif // TYPE_CONVERSIONS_BASICS


#ifdef CONVERSIONS_FROM_OTHER_TO_CLASSUG
	//cout << sizeof(Fraction) << endl;
	Fraction A = (Fraction)5;
	cout << A << endl;
	cout << delimiter << endl;

	Fraction B;			//Default constructor
	B = Fraction(8);
	cout << B << endl;
#endif // CONVERSIONS_FROM_OTHER_TO_CLASSUG

	Fraction A(2, 3, 4);
	//A.to_improper();
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double b = A;
	cout << b << endl;


}
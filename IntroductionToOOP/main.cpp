#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;

public:

	double get_x()const
	{
		return x;

	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this -> y = 0;
		cout << "1ArgConstructor:\t" << this << endl;

	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	//metod
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};



//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT

    int a;
	Point A;

	A.x = 2;
	A.y = 3;

	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl;
	
	Point* pA = &A;
    cout << pA->x << "\t" << pA->y << endl;

#endif  // STRUCT_POINT

	Point A;
	//A.set_x(2);
	//A.set_y(3);
	A.print();
	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	//cout << A.get_x() << "\t" << A.get_y() << endl;

} 
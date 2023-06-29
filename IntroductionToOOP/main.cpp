﻿#include<iostream>
using namespace std;
#define delimiter "\n------------------------------------------------------------------------------\n"

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

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t" << this << endl;

	}

	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}


	// operators
	
	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: \t" << this << endl;
		return *this;
	}


	//Метод
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	//metod
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};


//Функция
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define CONSTRACTOR_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK


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
#ifdef CONSTRACTOR_CHECK

 // CONSTRACTOR_CHECK

	Point A;
	//A.set_x(2);
	//A.set_y(3);
	A.print();

	Point B = 5; // Single-argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; // copy constructor
	D.print();

	Point E;  // copy assignment
	E = D;


	//cout << A.get_x() << "\t" << A.get_y() << endl;
#endif

#ifdef DISTANCE_CHECK



	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	cout << delimiter << endl;
	cout << "Растояние от точки А до точки В:      " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Растояние от точки B до точки A:      " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками А до точки В: " << distance(A,B) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точками B до точки A: " << distance(A,B) << endl;
	cout << delimiter << endl;

#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // #define ASSIGNMENT_CHECK


} 
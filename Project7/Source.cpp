#include <iostream>
#include <vector>
#include<conio.h>
using namespace std;

template <class T>
struct Point
{
	T x;
	T y;
	void display()
	{
		cout << "(" << x << "," << y << ")";
	}
};
template <class T>
struct Array
{
	vector<T> data;
	void Add(T item)
	{
		data.push_back(item);
	}
	void display()
	{
		for (auto var : data)
			cout << var << " ";
	}
};
template <template<class> class T, class T1>
struct Some
{
	T<T1> data;
	void Add(T1 item)
	{
		data.Add(item);
	}
	void display()
	{
		data.display();
		cout << "\n";
	}
};

int main()
{
	Some<Point, int> intPoint;
	intPoint.data.x = 1;
	intPoint.data.y = 1;
	intPoint.display();


	Some<Point, double> doublePoint;
	doublePoint.data.x = 10.01;
	doublePoint.data.y = 0.02;
	doublePoint.display();


	Some<Array, int> intArray;
	intArray.Add(1);
	intArray.Add(3);
	intArray.Add(5);
	intArray.display();

	return 0;
}
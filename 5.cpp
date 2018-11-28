#include <iostream>

using namespace std;

class Point
{
public:
	Point() {
		x = 0;
		y = 0;
	}
	~Point() {
	}
	void Add() {
		cin >> x >> y;
		cout << endl;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
private:
	int x, y;
};

const double EPS = 0.00001;

void main()
{
	cout << "Enter the number of steps for \"t\"" << endl;
	int numberSteps;
	cin >> numberSteps;
	double valueSteps = 1.0 / numberSteps;

	Point A;
	cout << "Enter the coordinates of point A (x, y)" << endl;
	A.Add();

	Point B;
	cout << "Enter the coordinates of point B (x, y)" << endl;
	B.Add();

	Point C;
	cout << "Enter the coordinates of point C (x, y)" << endl;
	C.Add();

	double *t = new double[numberSteps + 1];

	for (size_t i = 0; i <= numberSteps; ++i)
		t[i] = valueSteps * i;

	double *x = new double[numberSteps + 1];
	double *y = new double[numberSteps + 1];

	cout << "t\t\t\t" << "X\t\t\t" << "Y\t\t\t" << endl << endl;
	for (size_t i = 0; i <= numberSteps; ++i)
	{
		x[i] = pow(1 - t[i], 2) * A.GetX() + 2 * (1 - t[i]) * t[i] * B.GetX() + pow(t[i], 2) * C.GetX();
		y[i] = pow(1 - t[i], 2) * A.GetY() + 2 * (1 - t[i]) * t[i] * B.GetY() + pow(t[i], 2) * C.GetY();
		if (abs(x[i]) - int(abs(x[i])) <= EPS)
			cout << t[i] << "\t\t\t" << x[i] << "\t\t\t" << y[i] << "\t\t\t" << endl;
	}
	delete[] y;
	delete[] x;
	delete[] t;
}
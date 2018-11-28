#include <iostream>
#include <ctime>

using namespace std;

void FillArray(int * const arr, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
		arr[i] = rand() + 2;
}

void PrintArray(const int * const arr, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
		cout << arr[i] << "\t";
	cout << endl;
}

void bubbleSort(int * const arr, const size_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
		for (size_t j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}

void main()
{
	srand(time(NULL));

	size_t sizeA;
	cout << "Enter size of A = ";
	cin >> sizeA;

	size_t sizeB;
	cout << "\nEnter size of B = ";
	cin >> sizeB;

	int *A = new int[sizeA];
	FillArray(A, sizeA);

	int *B = new int[sizeB];
	FillArray(B, sizeB);

	cout << "\nA:" << endl;
	PrintArray(A, sizeA);

	cout << "\nB:" << endl;
	PrintArray(B, sizeB);

	int *C = new int[sizeA + sizeB];

	double sumLog = 0;

	for (size_t i = 0; i < sizeA + sizeB; ++i)
	{
		if (i < sizeA)
			C[i] = A[i];
		else
			C[i] = B[i - sizeA];
		sumLog += log10(C[i]);
	}
	delete[] B;
	B = nullptr;
	delete[] A;
	A = nullptr;

	cout << "\nold C:" << endl;
	PrintArray(C, sizeA + sizeB);

	bubbleSort(C, sizeA + sizeB);

	cout << "\nnew C:" << endl;
	PrintArray(C, sizeA + sizeB);

	cout << "\nMin element = " << C[0] << endl;
	cout << "\nMax element = " << C[sizeA + sizeB - 1] << endl;

	delete[] C;
	C = nullptr;

	sumLog = pow(10, sumLog / (sizeA + sizeB));
	cout.precision(20);
	cout << "\nGeometric mean = " << sumLog << endl << endl;;
}
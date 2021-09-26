#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
void printMatrix(int** matrix, size_t n, size_t m)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)

			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void insertArray(int**& array, size_t n, size_t m, size_t index, int value[])
{
	
	
		int** copy = new int* [n];
		for (int i = 0; i < n; i++)
		{ 
			copy[i] = new int[m];
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
				copy[i][j] = array[i][j];

			copy[i][index] = value[i];
				for (int j = 0; j < index; j++)
				{
					copy[i][j] = array[i][j - 1];
				}
			
		}

	for (size_t i = 0; i < n; i++)
		delete[] array[i];
	delete[]array;
	array = copy;
}

void valueCol(int array[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter value: ";
		cin >> array[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Ru");
	
	size_t n;
	cout << "Enter amount of n in matrix: ";
	cin >> n;
	size_t m;
	cout << "Enter amount of m in matrix: ";
	cin >> m;
	int** matrix = new int* [n];
	for (size_t i = 0; i < n; i++)
		matrix[i] = new int[m];

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			cout << "Enter " << j << " element of " << i << " n: ";
			cin >> matrix[i][j];
		}
	printMatrix(matrix, n, m);
	cout<<"====================================="<< endl;
	
	size_t index;
	cout << "Enter index: ";
	cin >> index;

	int* value=new int[n];
	valueCol(value, n);
	
	insertArray(matrix, n, m, index,value);
	
	printMatrix(matrix, n, m);
	for (size_t i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	delete[]value;
	return 0;



}
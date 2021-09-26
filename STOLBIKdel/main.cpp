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

void DelArray(int**& array, size_t n, size_t m, size_t index)
{
	index--;
	m++;
	int** copy = new int* [n];
	for (int i = 0; i < n; i++)
	{
		copy[i] = new int[m];
	}
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j <= index; j++)
			copy[i][j] = array[i][j];

		for (int j = m-1 ; j > index; --j)
		{
			copy[i][j-1] = array[i][j];
		}

	}

	for (size_t i = 0; i < n; i++)
		delete[] array[i];
	delete[]array;
	array = copy;
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
	cout << "=====================================" << endl;
	m--;
	size_t index;
	cout << "Enter index: ";
	cin >> index;
	DelArray(matrix, n, m, index);
	printMatrix(matrix, n, m);
	for (size_t i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	
	return 0;



}
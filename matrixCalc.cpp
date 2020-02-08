// Ryan Butler
// This program will calculate addition, subtraction, or multiplication
// of two compatible matrices with dimensions and array elements provided by the user

#include <iostream>
using namespace std;

// Function prototypes
void add(int rowA, int rowB, int colA, int colB,
         int matrixA[10][10], int matrixB[10][10], int matrixC[10][10]);
void sub(int rowA, int rowB, int colA, int colB,
         int matrixA[10][10], int matrixB[10][10], int matrixC[10][10]);
void multiply(int rowA, int rowB, int colA, int colB,
              int matrixA[10][10], int matrixB[10][10], int matrixC[10][10]);

int main()
{
	// Declare variables for row and column size, matrices, and operation char
	int rowA, colA, rowB, colB;
	int matrixA[10][10];
	int matrixB[10][10];
	int matrixC[10][10];
	char operation;
    
	
	// Ask user for dimenstions and elements for Matrix A
    cout << "Enter dimensions for Martix A:" << endl;
	cin >> rowA;
	cin >> colA;
    cout << "Enter values for Matrix A:" << endl;
	for (int r = 0; r < rowA; ++r)
	{
		for (int c = 0; c < colA; ++c)
		{
			cin >> matrixA[r][c];
		}
	}
	
	// Ask user for dimensions and elements for Matrix B
    cout << "Enter dimensions for Martix B:" << endl;
	cin >> rowB;
	cin >> colB;
    cout << "Enter values for Matrix B:" << endl;
	for (int r = 0; r < rowB; ++r)
	{
		for (int c = 0; c < colB; ++c)
		{
			cin >> matrixB[r][c];
		}
	}
	
	// Ask user for operation
	cout << "Choose your operation (A for addition, S for subtraction, M for multiplication)" << endl;
	cin >> operation;
	
	// Call functions depending on operation
	if (operation == 'A' || operation == 'a' || operation == '+')
	{
        operation = 'A';
		add(rowA, rowB, colA, colB, matrixA, matrixB, matrixC);
	}
	else if (operation == 'S' || operation == 's' || operation == '-')
	{
        operation = 'S';
		sub(rowA, rowB, colA, colB, matrixA, matrixB, matrixC);
	}
	else if (operation == 'M' || operation == 'm' || operation == '*')
	{
        operation = 'M';
		multiply(rowA, rowB, colA, colB, matrixA, matrixB, matrixC);
	}
	else
	{
		cout << "Invalid operation" << endl;
        return 0;
	}
	
	// Output Matix C, if applicable
	if (((operation == 'A'  || operation == 'S')
         && rowA == rowB && colA == colB) || (operation == 'M' && colA == rowB))
	{
        cout << "Matrix C is:" << endl;
		if (operation == 'A' || operation == 'S')
		{
			for (int r = 0; r < rowA; ++r)
			{
				for (int c = 0; c < colA; ++c)
				{
					cout << matrixC[r][c] << " ";
				}
				cout << endl;
			}
		}
		else if (operation == 'M')
		{
			for (int r = 0; r < rowA; ++r)
			{
				for (int c = 0; c < colB; ++c)
				{
					cout << matrixC[r][c] << " ";
				}
				cout << endl;
			}
		}
	}
	else
		cout << "Invalid dimensions" << endl;
}



// Add Function
void add(int rowA, int rowB, int colA, int colB,
         int matrixA[10][10], int matrixB[10][10], int matrixC[10][10])
{
	if (rowA == rowB && colA == colB)
	{
		for (int r = 0; r < rowA; ++r)
		{
			for (int c = 0; c < colA; ++c)
			{
				matrixC[r][c] = matrixA[r][c] + matrixB[r][c];
			}
		}
	}
}

// Subtract Function
void sub(int rowA, int rowB, int colA, int colB,
         int matrixA[10][10], int matrixB[10][10], int matrixC[10][10])
{
	if (rowA == rowB && colA == colB)
	{
		for (int r = 0; r < rowA; ++r)
		{
			for (int c = 0; c < colA; ++c)
			{
				matrixC[r][c] = matrixA[r][c] - matrixB[r][c];
			}
		}
	}
}

// Multiply Function
void multiply(int rowA, int rowB, int colA, int colB,
              int matrixA[10][10], int matrixB[10][10], int matrixC[10][10])
{
	if (colA == rowB)
	{
		for (int i = 0; i < rowA; ++i)
		{
			for (int j = 0; j < colB; ++j)
			{
				matrixC[i][j] = 0;
				for (int k = 0; k < colA; ++k)
				{
					matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
				}
			}
		}
	}
}



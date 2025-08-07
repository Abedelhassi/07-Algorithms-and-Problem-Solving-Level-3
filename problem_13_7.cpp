#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//printf(" %0*d ", 2, arr[i][j]);
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
bool  IsIdentityMatrix(int Matrix1[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (i == j && Matrix1[i][j] !=1) {
				return false;
			}
			else if (i != j && Matrix1[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	//int Matrix[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int Matrix[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix, 3, 3);
	if (IsIdentityMatrix(Matrix, 3, 3))
		cout << "\nYes,Matrix is identify";
	else
		cout << "\n,No,Matrix ix NOT identify";
	system("pause>0");
}
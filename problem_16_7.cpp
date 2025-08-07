#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
// space matrix: 3dd 0 aktr mn 3dd lar9am
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
short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols) {
	short NumberCount = 0;
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			if (Matrix[i][j] == Number) {
				NumberCount++;
			};
		}
	}
	return NumberCount;
}
bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols) {
	short MatrixSize = Rows * Cols;
	return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)MatrixSize / 2));

}
int main() {
	int Matrix1[3][3] = { {0,0,12},{9,9,1},{0,0,9} };
	cout << "\nMatrix1: \n";
	PrintMatrix(Matrix1, 3, 3);
	if (IsSparseMatrix(Matrix1, 3, 3)) 
		cout << "yes,it is sparse \n ";
	else 
		cout << "Nope,not sparse \n ";
	system("pause>0");


	}




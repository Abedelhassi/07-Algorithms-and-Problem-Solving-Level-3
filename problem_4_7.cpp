#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << arr[i][j] << "  ";
		}
		cout << "\n";
	}
}
int ColsSum(int arr[3][3], short RowNumber, short ColNumber) {
	int Sum = 0;
	for (short i = 0; i <= RowNumber- 1; i++) {
		Sum += arr[i][ColNumber];
	}
	return Sum;

}
void PrintEachColomSum(int arr[3][3], short Rows, short Cols) {
	cout << "\nThe following are the sum of each row in the matrix:\n";
	for (short j = 0; j< Rows; j++) {
		cout << "Row" << j + 1 << " Sum= " << ColsSum(arr, Rows, j) << endl;

	}

}

int main() {
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "\n the following is 3*3 random matrix: \n"; \
		PrintMatrix(arr, 3, 3);
	PrintEachColomSum(arr, 3, 3);
	system("pause>0");
}
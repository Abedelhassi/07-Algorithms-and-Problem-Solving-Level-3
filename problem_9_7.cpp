#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From;
	return randNum;

 }
void FillMatrixWithRandomNumber(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			arr[i][j] = RandomNumber(1, 10);

		}
	}
}
void PrintMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			printf(" %0*d   ", 2, arr[i][j]);// ki ma ndirch space f %d y5rjou las9in fi b3dahm 
			//cout<<setw(3)<<arr[i][j];
		}
		cout << "\n";
	}
}
void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols) {
	short MiddleRow = Rows / 2;
	for (short j = 0; j < Cols; j++) {
		printf(" %0*d   ", 2, arr[MiddleRow][j]);
	}
	cout << "\n";

}
void PrintMiddleColomOfMatrix(int arr[3][3], short Rows, short Cols) {
	short MiddleCols = Cols / 2;
	for (short j = 0; j < Rows; j++) {
		printf(" %0*d   ", 2, arr[j][MiddleCols]);

	}
	cout << "\n";
}
int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3];
	FillMatrixWithRandomNumber(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMiddle Row of Matrix1 is : \n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);
	cout << "\nMiddle Colom of Matrix 1 is : \n";
	PrintMiddleColomOfMatrix(Matrix1, 3, 3);
	system("pause>0");

}

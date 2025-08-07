#include<iostream>
#include<string>
using namespace std;
string ReadString() {
	string S1;
	cout << "Please enter Your String: \n";
	getline(cin, S1); // drk win tfkrt getline (cin,var) fi blast cin
	return S1;
}
string UpperFirstLetterOfEachWord(string S1) {
	bool isFirstLetter = true;
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ' && isFirstLetter) {
			S1[i] = toupper(S1[i]);  // function y7wl l 7rf s4ir ll kbir 
		}
		isFirstLetter = (S1[i] == ' ' ? true : false); // fi blast if else 
	}
	return S1;
}
int main() {
	string S1 = ReadString();
	cout << "\nString after conversation : \n";
	S1 = UpperFirstLetterOfEachWord(S1);
	cout << S1 << endl;
	system("pause>0");


}
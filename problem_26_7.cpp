#include<iostream>
#include<string>
using namespace std;
string ReadString() {
	string S1;
	cout << "please enter your string ?  \n";
	getline(cin, S1);
	return S1;
}
string UpperAllString(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = toupper(S1[i]);
	}
	return S1;
}
string DownAllString(string S1) { //  hadi fun t3 klch . t3 9bl kant t3 l7rf lwl 
	for (short i = 0; i < S1.length(); i++) {
		S1[i] = tolower(S1[i]);
	}
	return S1;
}
int main() {
	string S1 = ReadString();
	cout << "\nString after upper : \n";
	S1 = UpperAllString(S1);
	cout << S1 << endl;
	cout << "\nString After Lower: \n";
	S1 = DownAllString(S1);
	cout << S1 << endl;
	system("pause>0");

}
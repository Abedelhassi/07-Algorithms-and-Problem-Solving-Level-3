#include<iostream>
#include<string>
using namespace std;
string ReadString() {
	string S1;
	cout << "please enter your string :\n";
	getline(cin, S1);
	return S1;
}
short CountWords(string S1) {
	string delim = " ";
	short Counter = 0;
	short pos = 0;
	string sWord; // define dtring var
	while ((pos = S1.find(delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);// store the word 
		if (sWord != "") {
			Counter++;
		}
		S1.erase(0, pos + delim.length()); // erase and move 

	}
	if (S1 != "") {
		Counter++;
	}
	return Counter;
}
int main() {
	string S1 = ReadString();
	cout << "\nThe number of words in your string is : ";
	cout << CountWords(S1);
	system("pause>0");

}
#include<iostream>
#include<string>
using namespace std;
string ReadString() { 
	string S1;
	cout << "plesee rnter string ";
	getline(cin, S1);
	return S1;
}
void PrintEachWordInString(string S1)
{
	string delim = " ";//farGH 
	cout << "\nYour string words are : \n\n";
	short pos = 0;
	string sWord;
	while ((pos = S1.find(delim)) != std::string::npos) {//5dm b =  bach t5zn 
		sWord = S1.substr(0, pos);//npos : no positioon 
		// awl klma fi sword 
		if (sWord != "") {// hl sWord =? faragh 
			cout << sWord << endl;
		}
		S1.erase(0, pos + delim.length());// im7i mn ll postion + toul faraghh 

	}
	if (S1 != "") {
		cout << S1 << endl;
	}
}
int main() {
	PrintEachWordInString(ReadString());
	system("pause>0");

}
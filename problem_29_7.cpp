#include<iostream>
#include<string>
using namespace std;
string ReadString() {
	string S1;
	cout << "please rnter your string : \n";
	getline(cin, S1);
	return S1;
 }
enum enWhatToCount {SmallLetters=0,CapitalLetters=1,All=3};
short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {
	if (WhatToCount == enWhatToCount::All) {
		return S1.length();
	}
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			Counter++;
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			Counter++;


	}
	return Counter;
}
short CountSmallLetters(string S1) {
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (islower(S1[i]))
			Counter++;
	}
	return Counter;
}
short CountCapitalLetters(string S1) {
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (isupper(S1[i]))
			Counter++;
	}
	return Counter;

}
int main() {
	string S1 = ReadString();
	cout << "\nStringLength= " << S1.length();
	cout << "\nCapiltl Letters Ciunt = " << CountCapitalLetters(S1);
	cout << "\nSmall Letter Count =" << CountSmallLetters(S1);
	cout << "\n\n 2nd method :\n";
	cout << "\nString Length = " << CountLetters(S1);
	cout << "\nCapital Letters Count= " << CountLetters(S1,
		enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count= " <<
		CountLetters(S1, enWhatToCount::SmallLetters);
	system("pause>0");


}

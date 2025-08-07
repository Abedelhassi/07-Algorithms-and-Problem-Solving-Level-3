#include<iostream>
#include<string> 
#include<vector>
#include<fstream>
using namespace std;
struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
 };
vector <string> SplitString(string S1, string Delim) {
	vector <string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord); 
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {  
		vString.push_back(S1);
	}
	return vString;
}
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#") {
	sClient Client;
	vector <string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//stod: string  to double
	return Client;
}
void PrintClientToRecord(sClient Client) {
	cout << "\n\nThe following is the extracted client record :\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code      :" << Client.PinCode;
	cout << "\nName           :" << Client.Name;
	cout << "\nPhone            :" << Client.Phone;
	cout << "\nAccount Balance     :" << Client.AccountBalance;
}


int main() {
	string stline = "A150#//#1234#//#Hassib#//#0667691889#//#2000";
	cout << "\nLine Record is :\n";
	cout << stline;
	sClient Client = ConvertLinetoRecord(stline);
	PrintClientToRecord(Client);     
	system("pause>0");
	return 0;

 }
 
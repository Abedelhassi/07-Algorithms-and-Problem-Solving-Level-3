#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
const string ClientsFileName = "Clients.txt"; // lism t3  file ykoun string 
struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
sClient ReadNewClient() {
	sClient Client;
	cout << "Enter Account Number: ";
	// ws:wehitespace character
	getline(cin >> ws, Client.AccountNumber); // cin >> ws  cin m3a getline twli kayna t5rbit fl buffer , n5dmou ws bch nn7ou lmchkl 
	cout << "Enter PinCode:";
	getline(cin, Client.PinCode);
	cout << "enter name:";
	getline(cin, Client.Name);
	cout << "Enter Phone : ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance:";
		cin >> Client.AccountBalance;
		return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}
void AddDataLineToFile(string FileName, string stDataLine) {
	fstream MyFile;//fstream t3 file . ifile tt3rf fl c++ b fstream 
	MyFile.open(FileName, ios::out | ios::app);// ida file mwjoud y3ml append 3la aa5rou . hadi t5l  file 
	if (MyFile.is_open()) {
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}
void AddNewClient() {
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddClients() {
	char AddMore = 'Y';
	do {
		system("cls");// ym7i chacha // clear screen 
		cout << "Adding New Clients:\n\n";
		AddNewClient();
		cout << "\nClient Added Succefuly , do you want to add more clients(Y/N)";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y'); // toupper t5wl l7rouf lkll ll kbira 
}
int main() {
	AddClients();
	system("pause>0");
	return 0; 


}
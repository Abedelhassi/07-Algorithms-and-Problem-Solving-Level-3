#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;
const string ClientFileName = "Clients.txt"; // ki drt client.txt g3dt  sa3a ana m3ah w ma hbch ymchi whya nsit S hhhhh
// hadi n3rfou baha file name brk( const string FileName = "filename.txt";
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
		if (S1 != "") {
			vString.push_back(sWord);

		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "") {
		vString.push_back(S1);
	}
	return vString;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#") {
	sClient Client;
	vector <string> vClientData;
	vClientData = SplitString(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	return Client;
}
vector <sClient > LoadClientsDataFromFile(string FileName) {
	vector <sClient> vCLients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open()) {
		string Line;
		sClient Client;
		while (getline(MyFile, Line)) {
			Client = ConvertLineToRecord(Line);
			vCLients.push_back(Client);

		}
		MyFile.close();

	}
	return vCLients;
}
void PrintClientCard(sClient Client) {
	cout << "\nThe following are the client details : \n";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPin Code         : " << Client.PinCode;
	cout << "\nName             : " << Client.Name;
	cout << "\nPhone              :" << Client.Phone;
	cout << "\nAccount Balance :     " << Client.AccountBalance;
}
bool FindClientByAccountNumber(string AccountNumber, sClient& Client) {
	vector <sClient> vClients = LoadClientsDataFromFile(ClientFileName);
	for (sClient C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C; 
			return true;
		}
	}
	return false;

}
string ReadClientAccountNumber() {
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
}
int main() {
	sClient Client;
	string AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, Client)) {
		PrintClientCard(Client);

	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber << ") is not fond . ";
	}
	system("pause>0");
	return 0;
}


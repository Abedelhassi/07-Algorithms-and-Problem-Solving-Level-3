#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip >
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};
vector<string>SplitString(string S1, string Delim) {
	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos) {
		sWord = S1.substr(0, pos);
		if (sWord != "") {
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
	vector<string> vClientData;
	vClientData = SplitString(Line, Seperator); //3ytna 3la fun t3 split w 7tinah fl vector 
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);//stod : string to double 
	return Client;

}
vector<sClient>LoadClientsDataFromFile(string FileName) {
	vector <sClient> vClients;
	fstream MyFile; // t3rf file b fsrtream 
	MyFile.open(FileName, ios::in);// ios::in : read mode t3 y9ra file 
	
	if (MyFile.is_open()) { 
		string Line;
		sClient Client;
		while (getline(MyFile, Line)) { 
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();

	}
	return vClients;
}
void PrintClientRecord(sClient Client) {
	cout << "|" << setw(15) << left << Client.AccountNumber;
	cout << "|" << setw(10) << left << Client.PinCode;
	cout << "|" << setw(40) << left << Client.Name;
	cout << "|" << setw(12) << left << Client.Phone;
	cout << "|" << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientData(vector<sClient> vClients)
{
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << "nClient(s).";
	cout << "\n___________________________________________";
	cout << "________________________________________\n" << endl;
	 
	cout << "| " << left << setw(15) << "Accout Number";  // left m3naha ttktb 3la left 
	cout << "| " << left << setw(10) << "Pin Code";    
	cout << "| " << left << setw(40) << "Client Name";  
	cout << "| " << left << setw(12) << "Phone";   
	cout << "| " << left << setw(12) << "Balance"; 
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (sClient Client : vClients) {
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "\n_______________________________________________________";   
	cout << "_________________________________________\n" << endl;
}
int main() {
	vector <sClient>vClients = LoadClientsDataFromFile(ClientsFileName);
	PrintAllClientData(vClients);
	system("pause>0");
	return 0;
}

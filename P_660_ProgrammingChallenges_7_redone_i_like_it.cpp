// P_660_ProgrammingChallenges_7_redone.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

//////////// structure area //////////
struct Account
{
	string name;
	string adress;
	string password;
	/*string city;
	string state;
	string zip;
	string telephoneNumber;
	int accountBlanace;
	string dateOfLastPayment;*/
};

struct AccountChangeLogger
{
	vector<string> AdressChanges;
	vector<string> NameChanges;

};

void UserChoice(char&);
void AccountCreation(Account[],const int SIZE);
string AccountCreationName();
string AccountCreationAddress();
string AccountPasswordCreation();
void AlterAccount(Account[],int,AccountChangeLogger[]);
int FindAccount(Account[],const int);
//void PrintLogs();

int main()
{
	const int SIZE = 5;
	Account Accounts[SIZE];
	AccountChangeLogger Logs[SIZE];
	char Choice;
	
	do {
		UserChoice(Choice);
		if (Choice == 'N')
			AccountCreation(Accounts, SIZE);
		if (Choice == 'C') 
			AlterAccount(Accounts, FindAccount(Accounts, SIZE), Logs);   //this does not feel or look right. Prob better way (account prob does not need to be passed so much)
	} while ((toupper(Choice) == 'N' || toupper(Choice) == 'C') && toupper(Choice) != 'Q'); //add c

	for (int count = 0; count < SIZE; count++)
	{
		if (!(Logs[count].AdressChanges.empty()))
		{
			cout << "\nAdress change Logs for account #" << count + 1 << endl;
			for (auto p : Logs[count].AdressChanges)
			{
				cout << p << endl;
			}
			cout << "\n--------------------------------------------";
		}

		if (!(Logs[count].NameChanges.empty()))
			{
				cout << "\nName change Logs for account #" << count + 1 << endl;
				for (auto p : Logs[count].NameChanges)
				{
					cout << p << endl;
				}
				cout << "\n--------------------------------------------";
			}
		}
	}

////////// Function 1 ////////// 
void UserChoice(char& choice) {
	string temp;
	do {
		cout << "Enter \"N\" for a new account \"C\" to adjust a exsisting account and \"Q\" to quit: ";
		getline(cin, temp);

	} while (toupper(temp[0]) != 'N' && toupper(temp[0]) != 'C' && toupper(temp[0]) != 'Q' || temp.length() != 1);
	choice = toupper(temp[0]);
}

////////// Function 2 ////////// 
void AccountCreation(Account accounts[], const int SIZE) {

	static int NumOfAccounts = 0;
	if (NumOfAccounts == SIZE)
	{
		cout << "Limit reached: Unable to create new accounts:\n";
		return;
	}
	accounts[NumOfAccounts].name = AccountCreationName();
	accounts[NumOfAccounts].adress = AccountCreationAddress();
	accounts[NumOfAccounts].password = AccountPasswordCreation();

	cout << "\n";
	cout << "Account name = " << accounts[0].name << endl;
	cout << "Account adress = " << accounts[0].adress << endl;
	cout << "Account password = " << accounts[0].password << endl;

	NumOfAccounts++; //NOT TO PASS the array size;
}

////////// Function 3 ////////// 
string AccountCreationName() {
	string tempString;
	bool valid;

	do
	{
		valid = true;

		cout << "Enter Name: ";
		getline(cin, tempString);
		if (tempString.length() < 2 && valid == true)
		{
			cout << "To small: ";
			valid = false;
		}
		if (tempString.length() > 11 && valid == true)
		{
			cout << "To large: ";
			valid = false;
		}
		for (int counter = 0; counter < tempString.length(); counter++)
		{
			if (!(isalpha(tempString[counter])) && valid == true) {
				cout << "Only letters allowed: ";
				valid = false;
				break;
			}
		}
	} while (valid != true);

	return tempString;
}

//////////  Functin 4 ////////// 
string AccountCreationAddress() {
	string tempString2;
	string tempString3;
	bool valid;

	do {
		valid = true;
		cout << "Enter your Adress number: ";
		getline(cin, tempString2);
		if (tempString2.length() != 4 && valid == true)
		{
			cout << "Adress # must be 4 digits: ";
			valid = false;
		}
		for (int c = 0;c < tempString2.length();c++)
		{
			if (!(isdigit(tempString2[c])) && valid == true)
			{
				cout << "Only numbers for your adress: ";
				valid = false;
				break;
			}
		}
	} while (valid != true);

	do {
		valid = true;
		cout << "Enter your street name: ";
		getline(cin, tempString3);

		if (tempString3.length() < 5 && valid == true)
		{
			cout << "Street name must be more then 5 character: ";
			valid = false;
		}
		if (tempString3.length() > 20 && valid == true)
		{
			cout << "Street name must be less then 20 characters: ";
			valid = false;
		}

		for (int count = 0; count < tempString3.length();count++)
		{
			if (!(isalpha(tempString3[count])) && valid == true)
			{
				cout << "Street name must only contain letters: ";
				valid = false;
				break;
			}
		}

	} while (valid != true);
	string space = " ";

	tempString2 = tempString2 + space + tempString3;
	
	return tempString2;
}

////////// Function 5 ////////// 
string AccountPasswordCreation() {
	string tempPasswordString;
	bool valid;

	do {
		valid = true;

		cout << "Enter a password for your account: ";
		getline(cin, tempPasswordString);

		if (tempPasswordString.length() < 5 && valid == true)
		{
			cout << "Password must be more then 5 character: ";
			valid = false;
		}
		if (tempPasswordString.length() > 20 && valid == true)
		{
			cout << "Password must be less then 20 characters: ";
			valid = false;
		}

		for (int count = 0; count < tempPasswordString.length();count++)
		{
			if (!(isalpha(tempPasswordString[count])) && (!(isdigit(tempPasswordString[count])) && valid == true ))
			{
				cout << "Street name must only contain letters: ";
				valid = false;
				break;
			}
		}
	} while (valid != true);
	return tempPasswordString;
}

////////// Function 6 ////////// 
void AlterAccount(Account account[], int accountNum, AccountChangeLogger logs[]) {
	string selection;
	string log1; //before change
	string log2; //after change
	bool valid;

	do {
		valid = true;

		cout << "Which account element do you want to change?\n";
		cout << "\"N\" to change name: \n";
		cout << "\"A\" to change adress: \n";
		cout << "Choice: ";
		getline(cin, selection);
		if (selection.length() != 1)
			valid = false;
		if((toupper(selection[0]) != 'N' && toupper(selection[0]) != 'A') || valid == false)
			valid = false;

	} while (valid != true);

	switch (toupper(selection[0]))
	{
	case 'A':
		log1 = account[accountNum].adress;
		account[accountNum].adress = AccountCreationAddress();
		log2 = account[accountNum].adress;
		if (log1 != log2)
		{
			logs[accountNum].AdressChanges.push_back("Account Adress changed from: " + log1 + " to: "+ log2);
		}
	break;

	case 'N':
		log1 = account[accountNum].name;
		account[accountNum].name = AccountCreationName();
		log2 = account[accountNum].name;
		if (log1 != log2)
		{
			logs[accountNum].NameChanges.push_back("Account Name changed from: " + log1 + " to: " + log2);
		}
		break;
	}
}

////////// Function 7 ////////// 
int FindAccount(Account accounts[] ,const int SIZE) {
	
	string nameSearch;
	string passWord;
	int attempts = 3;
	cout << "Enter the name and password for the Account you wish to change:\n";

	while (attempts != 0)
	{
		do
		{
			cout << "Name: ";
			getline(cin, nameSearch);
			if (nameSearch.length() < 2)
				cout << "Name was to short: ";
		} while (nameSearch.length() < 2);
		do
		{
			cout << "\nPassword: ";
			getline(cin, passWord);
			if (passWord.length() < 5)
				cout << "\nPassword did not meet minimum length:";
		} while (passWord.length() < 5);
		for (int count = 0; count < SIZE; count++)
		{
			if (accounts[count].name == nameSearch && accounts[count].password == passWord)
			{
				cout << "Login Success: ";
				return count;
			}
		}
		attempts--;
		if (attempts != 0)
		{
			cout << "No account found: \n";
			cout << "Try again:\n ";
		}
	}
	
	if (attempts == 0)
	{
		cout << "Max attempts reached: ";
		exit(EXIT_FAILURE);   ///hmm
	}
}
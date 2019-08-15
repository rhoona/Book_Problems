#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Machine
{
	string drink_name;
	double drink_cost;
	int numOf_drinks;
};



int main() {

	Machine machines[5]; // array of 5 Machine
	machines[0].drink_name = "Cola";
	machines[0].drink_cost = .75;
	machines[0].numOf_drinks = 20;

	machines[1].drink_name = "Root Beer";
	machines[1].drink_cost = .75;
	machines[1].numOf_drinks = 20;

	machines[2].drink_name = "Lemon-Lime";
	machines[2].drink_cost = .75;
	machines[2].numOf_drinks = 20;

	machines[3].drink_name = "Grape Soda";
	machines[3].drink_cost = .80;
	machines[3].numOf_drinks = 20;

	machines[4].drink_name = "Cream Soda";
	machines[4].drink_cost = .80;
	machines[4].numOf_drinks = 20;

	string choice;
	cout << "Choose a drink or press Q to quit!\n";
	for (int count = 0; count < 5;count++)
	{
		cout << "choice: " << count + 1 << " " << machines[count].drink_name << endl;
	}
	do
	{
		cin >> choice;
	} while (choice.length() > 1);
	if (toupper(choice[1]) == 'Q')
	{
		exit(EXIT_SUCCESS);
	}
	switch (choice[1])
	{
	case '0':
		cout << "You selected " << machines[0].drink_name << " cost: " << machines[0].drink_cost;
		break;
	case '1':
		cout << "You selected " << machines[1].drink_name << " cost: " << machines[1].drink_cost;
		break;
	};

	string money;
	cout << "Amount input: ";
	cin >> money;
	cout << money;
	double money_Dbl;
	string money2;

	for (int count = 0; count < money.length(); count++)
	{
		if (money[count] == '.')
		{
			count += 2;
			money2.assign(money, 0, count);
			money_Dbl = stod(money2);

		}

	}
	if (money_Dbl < 0)
	{
		money_Dbl = money_Dbl * -1;
	}
	if (money_Dbl > machines[choice[1]].drink_cost)
	{
		cout << "Your change is: " << money_Dbl - machines[choice[1]].drink_cost;
		machines[choice[1]].numOf_drinks -= 1;
	}
}


#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
using namespace std;

struct MonthlyBudget
{
	double Housing = 500.00;
	double Utilities = 150.00;
	double HouseHoldExp = 65.00;
	double Transportation = 50.00;
	double Food = 250.00;
	double Medical = 30.00;
	double Insurance = 100.00;
	double Entertainment = 150.00;
	double Clothing = 75.00;
	double Miscellaneous = 50.00;
};

void MonthlyExps(unique_ptr<MonthlyBudget>&); //Used to get user spending input
void BudgetReport(unique_ptr<MonthlyBudget>&); //Prints out a report and details of the budget/spending uses BudgetReport2 for reptive output.
void BudgetReport2(const double*, const double*); //helper function for BudgetReport. Just outputs repeatative text.
double Str2Double(unique_ptr<string>&); //Function for converting the string input to double. Also searches for decimal point.
bool NotNeg(unique_ptr<string>&); //make sure user input does not have a negative sign.

int main() {
	unique_ptr<MonthlyBudget> Budget(new MonthlyBudget);
	cout << fixed << showpoint << setprecision(2);

	MonthlyExps(Budget);
	BudgetReport(Budget);
}

void MonthlyExps(unique_ptr<MonthlyBudget>& Budget) {
	unique_ptr<string> Amount(new string); //just wanted to practice working with unique_ptr
	do
	{
		cout << "Housing exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Housing -= Str2Double(Amount);

	do
	{
		cout << "Utilities exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Utilities -= Str2Double(Amount);

	do
	{
		cout << "House Hold exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->HouseHoldExp -= Str2Double(Amount);

	do
	{
		cout << "Transportation exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Transportation -= Str2Double(Amount);

	do
	{
		cout << "Food exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Food -= Str2Double(Amount);

	do
	{
		cout << "Medical exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Medical -= Str2Double(Amount);

	do
	{
		cout << "Insurance exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Insurance -= Str2Double(Amount);

	do
	{
		cout << "Entertainment exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Entertainment -= Str2Double(Amount);

	do
	{
		cout << "Clothing exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Clothing -= Str2Double(Amount);

	do
	{
		cout << "Misc exp: ";
		cin >> *Amount;
	} while (NotNeg(Amount) == false);
	Budget->Miscellaneous -= Str2Double(Amount);
}

double Str2Double(unique_ptr<string>& Amount1) {
	string newString;
	int length;
	length = Amount1->length();

	for (int count = 0; count < length; count++)
	{
		if ((*Amount1)[count] == '.')
		{
			newString.assign(*Amount1, 0, count += 3);  // not sure why needs += 3 instesd of += 2;
			return stod(newString);  //decimal was found so new string is copyed two 2 places after decimal
		}
	}
	return stod(*Amount1); //no decimal found 
}

void BudgetReport(unique_ptr<MonthlyBudget>& Budget) {
	const unique_ptr<MonthlyBudget> CleanBudget(new MonthlyBudget); //made a new fresh one that will have unaltered default values
	double BudgetTotal_After;
	double BudgetTotal_Before;

	BudgetTotal_Before = CleanBudget->Housing + CleanBudget->Clothing + CleanBudget->Entertainment + CleanBudget->Food + CleanBudget->HouseHoldExp + CleanBudget->Insurance +
		CleanBudget->Medical + CleanBudget->Miscellaneous + CleanBudget->Transportation + CleanBudget->Utilities;

	BudgetTotal_After = Budget->Housing + Budget->Clothing + Budget->Entertainment + Budget->Food + Budget->HouseHoldExp + Budget->Insurance +
		Budget->Medical + Budget->Miscellaneous + Budget->Transportation + Budget->Utilities;

	cout << "\n********* Budget Report **********\n";
	cout << "Housing Budgeted : "; BudgetReport2(&CleanBudget->Housing, &Budget->Housing);
	cout << "Utilities Budgeted: "; BudgetReport2(&CleanBudget->Utilities, &Budget->Utilities);
	cout << "House Hold Budget: "; BudgetReport2(&CleanBudget->HouseHoldExp, &Budget->HouseHoldExp);
	cout << "Transportation Budgeted: ";BudgetReport2(&CleanBudget->Transportation, &Budget->Transportation);
	cout << "Food Budgeted: ";BudgetReport2(&CleanBudget->Food, &Budget->Food);
	cout << "Medical Budgeted: ";BudgetReport2(&CleanBudget->Medical, &Budget->Medical);
	cout << "Insurance Budgeted: "; BudgetReport2(&CleanBudget->Insurance, &Budget->Insurance);
	cout << "Entertainment Budgeted: ";BudgetReport2(&CleanBudget->Entertainment, &Budget->Entertainment);
	cout << "Clothing Budgeted: ";BudgetReport2(&CleanBudget->Clothing, &Budget->Clothing);
	cout << "Misc Budgeted: "; BudgetReport2(&CleanBudget->Miscellaneous, &Budget->Miscellaneous);

	cout << "Total spent: " << BudgetTotal_Before - BudgetTotal_After << " Total Budgeted: " << BudgetTotal_Before << " Balance: " << BudgetTotal_After << endl;
}

void BudgetReport2(const double* CleanBudget, const double* Budget) {
	cout << *CleanBudget << "      spent: " << (*CleanBudget) - (*Budget) << "     Results: " << *CleanBudget - ((*CleanBudget) - (*Budget)) << endl;
}

bool NotNeg(unique_ptr<string>& Amount) {
	int length = Amount->length();

	for (int count = 0; count < length; count++)
	{
		if ((*Amount)[count] == '-')
		{
			cout << "\nNegative numbers are not allowed:\n ";
			return false;
		}
	}
	return true;
}
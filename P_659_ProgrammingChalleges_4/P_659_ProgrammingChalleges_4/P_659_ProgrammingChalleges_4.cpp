#include <iostream>
#include <string>
#include <iomanip> //for set precision and prob other stuff
using namespace std;
//Enum with dates, is passed to function DisplayMonthName later to Print the names
enum date {January, February, March, April, May, June, July, August, September, October, November, December };

//Strucute to hold be used to get/hold the desired info
struct WeatherData
{
	string month;
	double TotalRainfall = 0;
	double HighTemperature = 0;
	double LowTemperature = 0;
};

//a second structure used to record specific info gained from the previous WeatherData structure.
struct recordStats
{
double YearRainTotal = 0;
double YearRainAverage = 0;
 double HighestTemp = 0;
 double LowestTemp = 0;
 string HightempMonth ;
 string LowestTempMonth;
};

//Creates & Returns a temp WeatherData structure that will initialize a WeatherData structure in main
//This function calls the DisplayMonthName function within by reusing the enum date typ original passed to it
//in order to access and display month names
WeatherData GetData(date); 
//contains a switch function which returns a string that contains the actuarl month name that corrosponds to
//the enum date number passed to it. EX: 0 = January, 3 = April, 11 = December
string DisplayMonthName(date); //

int main() {
	date Months = January; //Initalized to the first month of the year & first element in the date enum. aka 0 which = January
	const int SIZE = 12; //12 elements for an array for 12 months of the year.
	WeatherData Data[SIZE]; //Data array will hold 12 WeatherData structures
	recordStats Record; //A structure for holding and storeing specific informtion and stats from the 12 WeatherData strcutres

	cout << fixed << showpoint << setprecision(2);//Just want to see two points after the decimal precision

	//Loop to start filling the 12 WeatherData structures by using the GetData function.
	for (int count = 0; count < SIZE; count++)
		Data[count] = GetData(static_cast<date>(Months + count)); //Static cast loop for incrementing through the eum Date

	Record.LowestTemp = Data[0].LowTemperature; //Initalizing the lowest temp to the first element before the loop to check
	Record.HighestTemp = Data[0].HighTemperature;//Initalizing the Highest temp to the first element before the loop to check

	for (int count = 0; count < SIZE; count++) //Start of the loop to check all 12 WeatherData structures
	{
		Record.YearRainTotal += Data[count].TotalRainfall; //As we loop through all the strucures, each months rainfall is accumulated here for the years

		if (Data[count].HighTemperature == Record.HighestTemp) //ADDED LAST SECOND, MULTIBLE MONTHS WITH SAME TEMPERATURE FUNCTIONALITY
		{
			string StringSpace = " ";
			Record.HightempMonth = Record.HightempMonth + StringSpace + DisplayMonthName(static_cast<date>(Months + count));
		}

		if (Data[count].HighTemperature > Record.HighestTemp) //Looping through all the structures in search of a Months temp that was higher then the default first month's
		{
			Record.HighestTemp = Data[count].HighTemperature; //As we loop through all the structures, if a higher temp is found, the years Highest temp changes
			Record.HightempMonth = DisplayMonthName(static_cast<date>(Months + count)); //Passing which number / month  in the looop a higher temp was found to the DisplayMonthName to record which month it was found in
		}
		

		if (Data[count].LowTemperature == Record.LowestTemp)
		{
			string StringSpace = " ";
			Record.LowestTempMonth = Record.LowestTempMonth + StringSpace + DisplayMonthName(static_cast<date>(Months + count));
		}


		if (Data[count].LowTemperature < Record.LowestTemp)//Looping through all the structures in search of a Months temp that was Lower then the default first month's
		{
			Record.LowestTemp = Data[count].LowTemperature;//As we loop through all the structures, if a Lower temp is found, the years Lower temp changes
			Record.LowestTempMonth = DisplayMonthName(static_cast<date>(Months + count));//Passing which number / month  in the looop a Lower temp was found to the DisplayMonthName to record which month it was found in
		}
	}

	Record.YearRainAverage = (Record.YearRainTotal / 12);//Divide the total yearly rain recorded by the number of months in a year (12)

	//Posting the Information that was Found  in the WeatherData strucutres and saved in the RecordStats structure
	cout << "Highest Yearly temperature was: " << Record.HighestTemp << " In: " << Record.HightempMonth;
	cout << "\nLowest temp was: " << Record.LowestTemp << " In: " << Record.LowestTempMonth;
	cout << "\nTotal yearly rain fall was " << Record.YearRainTotal;
	cout << "\nThe Yearly Average rain fall was " << Record.YearRainAverage;
}
//Function that asks user for the data per month, it is passed the "date" type "Month", which will in return be passed to 
//the DisplayMonthName function to retrieve the names of the months of the year in a string.
WeatherData GetData(date Month) {
	WeatherData tempWeatherDATA; //Temp WeatherData structure to be filled and returned to fill the Array of WeatherData structures in main
	tempWeatherDATA.month = DisplayMonthName(Month); //The date(motnh) for the Temp WeatherData struct is retrieved / returned by the DisplayMonthName function

	//Used to get the amount of rain for each month
	cout << "Enter the Total Rain fall for " << tempWeatherDATA.month << " ";
	cin >> tempWeatherDATA.TotalRainfall;
	while (tempWeatherDATA.TotalRainfall < 0) //Cant have negative rainfall, user must put either 0 or a positive amount of rainfall.
	{
		cout << "Cannot have Negative rain fall....";
		cin >> tempWeatherDATA.TotalRainfall;
	}
	//Get the Highest temp for each month
	cout << "Enter the Highest temperature for " << tempWeatherDATA.month << " ";
	cin >> tempWeatherDATA.HighTemperature;
	while (tempWeatherDATA.HighTemperature < -100 || tempWeatherDATA.HighTemperature > 140) //Temps cannot be less than -100 or higher than 140
	{
		cout << "Data input must be betwee (-100) and (140) ";
		cin >> tempWeatherDATA.HighTemperature;
	}
	//Get the Lowest temp for each month
	cout << "Enter the Lowest temperatue for " << tempWeatherDATA.month << " ";
	cin >> tempWeatherDATA.LowTemperature;
	while (tempWeatherDATA.LowTemperature < -100 || tempWeatherDATA.LowTemperature > 140) //Temps cannot be less than -100 or higher than 140
	{
		cout << "Data input must be betwee (-100) and (140) ";
		cin >> tempWeatherDATA.LowTemperature;
	}
	return tempWeatherDATA; //returns the tempWeatherDATA which is a WeatherData type, in order to intialize and fill an array of WeatherData types in main
}

//This function sole purpose is to use a switch case to return a string name of a month that corrosponds to the "date" type passed to it.
//EX: When passed the number "0" of the "enum date" type, it will return the string "January" 
string DisplayMonthName(date MN) {

	switch (MN)
	{
	case January: return "January";  //returns if a 0 is passed 
		break;
	case February: return "February"; //returns if a 1 is passed
		break;
	case March: return "March"; //returns if a 2 is passed... ext... ext
		break;
	case April: return "April";
		break;
	case May: return "May";
		break;
	case June: return "June";
		break;
	case July: return "July";
		break;
	case August:return "August";
		break;
	case September: return "September";
		break;
	case October: return "October";
		break;
	case November: return "November";
		break;
	case December: return "December";
		break;

	}
}
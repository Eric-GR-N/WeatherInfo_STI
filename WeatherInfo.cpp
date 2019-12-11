#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct WeatherData {
	string date = "0";
	double temperature = 0;
	double insideTemp = 0;
	double insideHum = 0;
	double humidity = 0;
	double mold = 0;
	double insideMold = 0;
};
bool compareInsideTemp(WeatherData a, WeatherData b) //Sort functions for struct
{
	if (a.insideTemp < b.insideTemp) { return 1; }
	else { return 0; }
}
bool compareInsideHum(WeatherData a, WeatherData b)
{
	if (a.insideHum < b.insideHum) { return 1; }
	else { return 0; }
}

bool compareTemp(WeatherData a, WeatherData b)
{
	if (a.temperature < b.temperature) { return 1; }
	else { return 0; }
}
bool compareHum(WeatherData a, WeatherData b)
{
	if (a.humidity < b.humidity) { return 1; }
	else { return 0; }
}
bool compareMold(WeatherData a, WeatherData b)
{
	if (a.mold < b.mold) { return 1; }
	else { return 0; }
}
bool compareInsideMold(WeatherData a, WeatherData b)
{
	if (a.insideMold < b.insideMold) { return 1; }
	else { return 0; }
}
void frontEnd();

void readInput(string dateArray [], double tempArray[], double humidityArray [], double insideTempArray [], double insideHumArray []);//Arrays for input
void getAutumn(string dateArray[], double tempArray[], string& autumn);
void getWinter(string dateArray[], double tempArray[], string& winter);


int main()
{
	WeatherData finalArray[130]; //Variables used.
	string day;
	string dateArray[130]; 
	double tempArray[130];
	double insideTempArray[130];
	double insideHumArray[130];
	double humidityArray[130];
	string winter = "0";
	string autumn = "0";
	char choice = '0';
	char answer = '0';

	readInput(dateArray, tempArray, humidityArray, insideTempArray, insideHumArray); // Reads input from the file.
	getAutumn(dateArray, tempArray, autumn);
	getWinter(dateArray, tempArray, winter);


	for (int i = 0; i < 130; i++) //Stores the final values in a struct.
	{
		finalArray[i].date = dateArray[i];
		finalArray[i].temperature = tempArray[i];
		finalArray[i].insideTemp = insideTempArray[i];
		finalArray[i].humidity = humidityArray[i];
		finalArray[i].insideHum = insideHumArray[i];

		if (finalArray[i].insideTemp > 0 && finalArray[i].insideHum > 78)
		{
			finalArray[i].insideMold = finalArray[i].insideTemp + finalArray[i].insideHum;
		}
		else
		{
			finalArray[i].insideMold = 0;
		}
		if (finalArray[i].temperature > 0 && finalArray[i].humidity > 78)
		{
			finalArray[i].mold = finalArray[i].temperature + finalArray[i].humidity;
		}
		else
		{
			finalArray[i].mold = 0;
		}
	}


	frontEnd();//Function for design


	cout << "                                       Hello and welcome to WeatherData, please make your choice below:" << endl; //Interface
	cout << endl;
	cout << "                                       OUTSIDE" << endl;
	cout << endl;
	cout << "                                       Warmest days [1]" << endl;
	cout << "                                       Coldest days [2]" << endl;
	cout << "                                       Days with the highest Humidity [3]" << endl;
	cout << "                                       Days with the lowest Humidity [4]" << endl;
	cout << "                                       Autumn [5]" << endl;
	cout << "                                       Winter [6]" << endl;
	cout << "                                       Highest risk of mold [7]" << endl;
	cout << "                                       Middle temperature for a day of choice [8]" << endl;
	cout << endl;
	cout << "                                       INSIDE" << endl;
	cout << endl;
	cout << "                                       Warmest days inside [a]" << endl;
	cout << "                                       Coldest days inside [b]" << endl;
	cout << "                                       Highest humidity inside [c]" << endl;
	cout << "                                       Lowest humidity inside [d]" << endl;
	cout << "                                       Highest risk of mold inside [e]" << endl;
	cout << "                                       Middle temperature for a day of choice inside [f]" << endl;


	
	do//This Do While-loop runs the program again if the user chooses 'y'.
	{
	cin >> choice;

	switch (choice)//Switch section to give the user choices for action.
	{
	case '1':
		cout << "The five warmest days were: " << endl;
		sort(finalArray, finalArray + 130, compareTemp);
		for (int i = 129; i > (129-5); i--)
		{
			cout << "Date: " << finalArray[i].date << " Temperature: " << finalArray[i].temperature << " Degrees Celcius" << endl;
		}
	break;
	case '2':
		cout << "The five coldest days were: " << endl;
		sort(finalArray, finalArray + 130, compareTemp);
		for (int i = 0; i < 5; i++)
		{
			cout << "Date: " << finalArray[i].date << " Temperature: " << finalArray[i].temperature << " Degrees Celcius" << endl;
		}
		break;
	case '3':
		cout << "The five days with the highest Humidity were: " << endl;
		sort(finalArray, finalArray + 130, compareHum);
		for (int i = 129; i > 129-5; i--)
		{
			cout << "Date: " << finalArray[i].date << " Humidity: " << finalArray[i].humidity << " %" <<  endl;
		}
		break;
	case '4':
		cout << "The five days with the lowest Humidity were: " << endl;
		sort(finalArray, finalArray + 130, compareHum);
		for (int i = 0; i < 5; i++)
		{
			cout << "Date: " << finalArray[i].date << " Humidity: " << finalArray[i].humidity << " %" << endl;
		}
		break;
	case '5':
		cout << "The first date of Autumn was: " << autumn << endl;
		break;
	case '6':
		cout << "There was no meteorological winter 2016.\nThe longest streak under 0 degrees celcius lasted four days and started: " << winter <<  endl;
		break;
	case '7':
		sort(finalArray, finalArray + 130, compareMold);
		cout << "The date : " << finalArray[129].date << " had the highest risk of mold - Humidity: " << finalArray[129].humidity << "% and Temperature: " << finalArray[129].temperature << " Degrees Celcius" << endl;
		break;
	case '8':
		cout << "Please choose a date (xxxx-xx-xx): ";
		cin >> day;
		for (int i = 0; i < 130; i++)
		{
			if (day == finalArray[i].date)
			{
				cout << "Date: " << finalArray[i].date << " - Temperature: " << finalArray[i].temperature << " Degrees Celcius" << endl;
				break;
			}
		}
		break;
	case 'a':
		cout << "The five warmest days inside were: " << endl;
		sort(finalArray, finalArray + 130, compareInsideTemp);
		for (int i = 129; i > (129 - 5); i--)
		{
			cout << "Date: " << finalArray[i].date << " Temperature: " << finalArray[i].insideTemp << " Degrees Celcius" << endl;
		}
		break;
	case 'b':
		cout << "The five coldest days inside were: " << endl;
		sort(finalArray, finalArray + 130, compareInsideTemp);
		for (int i = 0; i < 5; i++)
		{
			cout << "Date: " << finalArray[i].date << " Temperature: " << finalArray[i].insideTemp << " Degrees Celcius" << endl;
		}
		break;
	case 'c':
		cout << "The five days with the highest Humidity inside were: " << endl;
		sort(finalArray, finalArray + 130, compareInsideHum);
		for (int i = 129; i > 129 - 5; i--)
		{
			cout << "Date: " << finalArray[i].date << " Humidity: " << finalArray[i].insideHum << " %" << endl;
		}
		break;
	case 'd':
		cout << "The five days with the lowest Humidity inside were: " << endl;
		sort(finalArray, finalArray + 130, compareInsideHum);
		for (int i = 0; i < 5; i++)
		{
			cout << "Date: " << finalArray[i].date << " Humidity: " << finalArray[i].insideHum << " %" << endl;
		}
		break;
	case 'e':
		sort(finalArray, finalArray + 130, compareInsideMold);
		cout << "The date : " << finalArray[129].date << " had the highest risk of mold - Humidity: " << finalArray[129].insideHum << "% and Temperature: " << finalArray[129].insideTemp << " Degrees Celcius" << endl;
		break;
	case 'f':
		cout << "Please choose a date (xxxx-xx-xx): ";
		cin >> day;
		for (int i = 0; i < 130; i++)
		{
			if (day == finalArray[i].date)
			{
				cout << "Date: " << finalArray[i].date << " - Temperature: " << finalArray[i].insideTemp << " Degrees Celcius" << endl;
				break;
			}
		}
		break;
	default:
		cout << "Invalid input" << endl;
		break;
	}

	cout << "\nWould you like to run the program again?(y/n): ";
	cin >> answer;

	} while (answer == 'y' || answer == 'Y');

	return 0;
}
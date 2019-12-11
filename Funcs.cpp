#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void readInput(string dateArray[], double tempArray[], double humidityArray[], double insideTempArray [], double insideHumArray [])
{
	string inDate, inTime, inInOut, inTemp, inHum;

	ifstream text("Weatherdata.txt"); //Reads input from file
	double outsideMiddle = 0;
	double insideMiddle = 0;
	double insideHum = 0;
	double middleHum = 0;
	string datecheck = "2016-05-31";
	dateArray[0] = "2016-05-31";
	int i = 0; //Temp
	int j = 1; //Date
	int outCounter = 0; //Inside Counter
	int inCounter = 0;


	if (text.is_open())//Algorithm to read the file and input it to array.
	{
		while (!text.eof())
		{
			getline(text, inDate, ' ');
			getline(text, inTime, ',');
			getline(text, inInOut, ',');
			getline(text, inTemp, ',');
			getline(text, inHum);

			if (inInOut == "Ute")
			{
				outCounter++;
				outsideMiddle += stod(inTemp);
				middleHum += stod(inHum);
			}
			if (inInOut == "Inne")
			{
				inCounter++;
				insideMiddle += stod(inTemp);
				insideHum += stod(inHum);
			}

			if (datecheck != inDate)//For every new date, the information below executes.
			{
				humidityArray[i] = (middleHum / outCounter);
				insideHumArray[i] = (insideHum / inCounter);
				tempArray[i] = (outsideMiddle / outCounter);
				insideTempArray[i] = (insideMiddle / inCounter);
				dateArray[j] = inDate;
				i++;
				if (j < 130) { j++; };
				datecheck = inDate;
				outCounter = 0;
				inCounter = 0;
				insideMiddle = 0;
				outsideMiddle = 0;
				middleHum = 0;
				insideHum = 0;
			}

			if (inDate == "2016-12-23")
			{
				if (text.eof())//At the end of the file, this algorithm assigns the values to the last element of the arrays.
				{
					humidityArray[i] = middleHum / outCounter;
					insideHumArray[i] = insideHum / inCounter;
					tempArray[i] = outsideMiddle / outCounter;
					insideTempArray[i] = insideMiddle / inCounter;
				}
			}
		}
	}
}
void getAutumn(string dateArray[], double tempArray[], string& autumn)//Function to collect the date of autumn and change it to the right value.
{
	for (int i = 0; i < 130; i++)
	{

	    if (tempArray[i]>=0 && tempArray[i] < 10 && tempArray[i + 1] < 10 && tempArray[i + 2] < 10 && tempArray[i + 3] < 10 && tempArray[i + 4] < 10)
			
		{
			if (tempArray[i + 1] < tempArray[i] && tempArray[i + 2] < tempArray[i + 1] && tempArray[i + 3] < tempArray[i + 2] && tempArray[i + 4] < tempArray[i + 3])
			{
			autumn = dateArray[i];
			break;
			}
		}
	}
}
void getWinter(string dateArray[], double tempArray[], string& winter)//Function to collect the date of winter and change it to the right value.
{
	for (int i = 0; i < 130; i++)
	{
		if (tempArray[i] < 0 && tempArray[i + 1] < 0 && tempArray[i + 2] < 0 && tempArray[i + 3] < 0)
		{
				winter = dateArray[i];
				break;
		}
	}
}



void frontEnd()
{
		cout << "***       ***    ***       ***   ***********          **          *******************    ***        ***     ***********     ***********" << "*            *" << endl;
		cout << "***       ***  ***       ***    ***********         *****        *******************    ***        ***     ***********     ************" << "     *" <<  endl;
		cout << "***       ******       ***     ***                *** ***               ***            ***        ***     ***             ***       ***" << "           *" << endl;
		cout << "***       ****       ***      ***                ***  ***              ***            ***        ***     ***             ***       ***" << "   *"  << endl;
		cout << "***      ****      ***       ***********        *********             ***            **************     ***********     ************* " << "               *"  << endl;
		cout << "***    ******    ***        ***********       ***********            ***            **************     ***********     *************" << "          *"  << endl;
		cout << "***  ***  ***  ***         ***               ***      ***           ***            ***        ***     ***             ***       ***" << "*"  << endl;
		cout << "******    ******          ***               ***       ***          ***            ***        ***     ***             ***         ***" << "       *"  << endl;
		cout << "***        ***           ***********       ***        ***         ***            ***        ***     ***********     ***           ***" << "         *      *"  << endl;
		cout << "*          *            ***********       ***         ***        ***            ***        ***     ***********     ***             ***" << "  *         *"  << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
}


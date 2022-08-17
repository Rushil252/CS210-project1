/*
Chada Clock.cpp

created on: july 14,2022
Author: Rushil Patel
*/


// Explaination of the code written below

// The code is a class that displays the time in hours and minutes.
// The code has two classes, one for 12 hour format and one for 24 hour format.
// Each class has an add_hour() function which adds the number of hours to the current time.
// The display() function takes two objects of these classes as parameters and prints them out on screen using cout().
// The code is used to display the time of day in 12-hour and 24-hour formats.

#pragma warning(disable: 4996)
#include<iostream>
#include<ctime>
#include<iomanip>
using namespace std;

class time_sim {
public:
	int hour;
	int minute;
	int seconds;
};

// The code is a class that displays the time in hours and minutes.

class hours_12_format :public time_sim {
public:
	string meridian;
	hours_12_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
		if (hour >= 12)
		{
			meridian = "P M";
			hour -= 12;
		}
		else
			meridian = "A M";

	}
	void add_hour(int h)
	{
		hour += h;
		if (hour > 12)
		{
			hour -= 12;
		}
		else if (hour >= 12)
		{
			if (meridian == "A M")
			{
				meridian = "P M";
			}
			else if (meridian == "P M")
			{
				meridian = "A M";
			}
		}

	}
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	void add_seconds(int sec)
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};

class hours_24_format :public time_sim {
public:
	int hour;
	int minute;
	int seconds;
	hours_24_format()
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		hour = ltm->tm_hour;
		minute = ltm->tm_min;
		seconds = ltm->tm_sec;
	}
	void add_hour(int h)
	{
		hour += h;
		if (hour >= 24)
		{
			hour -= 24;
		}
	}
	void add_minute(int min)
	{
		minute += min;
		if (minute >= 60)
		{
			int h = minute / 60;
			minute -= 60 * h;
			add_hour(h);
		}
	}

	void add_seconds(int sec) // This code will 
	{
		seconds += sec;
		if (seconds >= 60)
		{
			int m = seconds / 60;
			seconds -= 60 * m;
			add_minute(m);
		}
	}
};

void display(hours_12_format h1, hours_24_format h2) // The code is used to display the time of day in 12-hour and 24-hour formats.
{
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
	cout << "\t\t*\t12-Hour Clock\t*\t\t";
	cout << "*\t24-Hour Clock\t*\n";
	cout << "\t\t*\t" << setw(2) << setfill('0') << h1.hour << ":" << setw(2) << setfill('0') << h1.minute << ":" << setw(2) << setfill('0') << h1.seconds << " " << h1.meridian << "\t*\t\t";
	cout << "*\t" << setw(2) << setfill('0') << h2.hour << ":" << setw(2) << setfill('0') << h2.minute << ":" << setw(2) << setfill('0') << h2.seconds << "\t*\n";
	cout << "\t\t*************************\t\t";
	cout << "*************************\n";
}

int main() // Main file to add time to the clock or exit program
{
	hours_12_format h1;
	hours_24_format h2;
	display(h1, h2);
	int choice = 0;
	while (choice != 4)
	{
		cout << "\n\n*************************\n";
		cout << "* 1 - Add One Hour\t*\n";
		cout << "* 2 - Add One Minute\t*\n";
		cout << "* 3 - Add One Second\t*\n";
		cout << "* 4 - Exit Program\t*\n";
		cout << "*************************\n";
		cin >> choice;
		switch (choice)
		{
		case 1: h1.add_hour(1);
			h2.add_hour(1);
			break;
		case 2: h1.add_minute(1);
			h2.add_minute(1);
			break;
		case 3: h1.add_seconds(1);
			h2.add_seconds(1);
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Enter Correct Choice!!\n";
		}
		system("cls");
		display(h1, h2);
	}
}


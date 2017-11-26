#include <iostream>
#include <string>
#include <signal.h>
#include <locale>
#include "data.h"
using namespace std;

bool start = false;

void mainMenu();
void addStudent();
void removeStudent();
void editEntry();
void searchEntry();
void searchingFunct();
void addingFunction();

void addStudent()
{
	cout << "Okay lets add a new student." << endl;
	addingFunction();
	addData();
	string status = "";
	cout << endl;
	cout << "Would you like to add, go to menu, or exit: ";
	cin >> status;

	if(status == "menu")
	{
		mainMenu();
	}
	else if(status == "add")
	{
		addStudent();
	}
	else
		exit(1);
}

void removeStudent()
{
	string status = "";
	cout << "Okay lets remove an exsisting student." << endl;
	removeData();
	cout << endl;
	cout << "Would you like to remove, go to menu, or exit: ";
	cin >> status;
	if(status == "menu")
	{
		mainMenu();
	}
	if (status == "remove")
	{
		addStudent();
	}
	else
		exit(1);
}

void searchingFunct()
{
	while(true)
	{
		cout << " ";
	}
}

void editEntry()
{
	cout << "Okay lets edit an exsisting students file." << endl;
	editData();
	string status = "";
	cout << "Would you like to return to edit, go to menu, or exit: ";
	cin >> status;

	if(status == "menu")
	{
		mainMenu();
	}
	else if(status == "edit")
	{
		addStudent();
	}
	else
		exit(1);
}

void searchEntry()
{
	string identifier = "";
	string status = "";
	cout << "Okay lets search for a student." << endl;
	SearchData();
	cout << endl;

	cout << "Would you like to return to search, go to menu, or exit: ";
	cin >> status;

	if(status == "menu")
	{
		mainMenu();
	}
	else if(status == "search")
	{
		addStudent();
	}
	else
		exit(1);
}

void addingFunction()
{
	int x = 0;
	x = x+1;

	if(start == true)
	{
		exit(0);
	}
	else
		addingFunction();
}
void mainMenu()
{
	string option = "";
	cout << endl << "Welcome to the Mangos Coorperation Class Roster System" << endl << endl;
	cout << "This application has multiple functions, you can add, " << endl;
	cout << "remove, edit, or search entries in the system." << endl;
	cout << endl;
	cout << "Please type what you wish to do (add, remove, edit, or search): ";
	cin >> option;
	cout << endl;
	searchingFunct();

	if(option == "add")
	{
		addStudent();
	}
	else if(option == "remove")
	{
		removeStudent();
	}
	else if(option == "search")
	{
		searchEntry();
	}
	else if(option == "edit")
	{
		editEntry();
	}
	else
	{
		cout << "Sorry Please enter a valid input next time" << endl;
		exit(1);
	}
}
int main()
{
	VecMaker();
	mainMenu();
	return 0;
}

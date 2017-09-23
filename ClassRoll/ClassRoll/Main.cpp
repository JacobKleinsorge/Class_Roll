#include <iostream>
#include <string.h>
#include <string>

#define CLASS_SIZE 50

using namespace std;

class student
{
public:
	int usfid;
	int presGrade;
	int essGrade;
	int projGrade;
	string name;
	string email;
};

int main(int argc, const char * argv[]) {
	int numStudents = 0;
	student roll[CLASS_SIZE];
	
	cout << "Welcome to our class roll system.";
	helpText();

	while (true) {

	}



}

void helpText() {
	cout << endl << "Commands:" << endl;
	cout << "    - " << "Add" << "               // Adds student(s) manually or from a file" << endl;
	cout << "    - " << "Delete" << "               // Deletes a student from the system" << endl;
	cout << "    - " << "List" << "               // Lists the students by last name" << endl;
	cout << "    - " << "Search" << "               // Search through students by name, ID, or email" << endl;
	cout << "    - " << "Update" << "               // Update any of the student fields" << endl;
	cout << "    - " << "Help" << "               // Lists these commands" << endl;
}

void listStudents(student* roll, int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << roll[i].lastName << ", " << roll[i].firstName << endl;
	}

	return;
}

#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <istream>

#define CLASS_SIZE 50
using namespace std;

class student
{
public:
	int usfid;
	int presGrade;
	int essGrade;
	int projGrade;
	string firstName;
	string lastName;
	string email;
};

int addStudent(student* roll, int numStudents);
int deleteStudent(student* roll, int numStudents);
void listStudents(student* roll, int numStudents);
void helpText();

void main(int argc, const char * argv[]) {
	int numStudents = 0;
	student roll[CLASS_SIZE];

	cout << "Welcome to our class roll system.";
	char input;

	while (true) {
		helpText();
		cin >> input;

		switch (input) {
		case 'a':
			numStudents = addStudent(roll, numStudents);
			break;
		case 'd':
			numStudents = deleteStudent(roll, numStudents);
			break;
		case 'l':
			listStudents(roll, numStudents);
			break;
		/*case 's':
			Search();
			break;
		case 'u':
			Update();
			break;*/
		case 'h':
			helpText();
			break;
		case 'q':
			return;
			break;
		default:
			cout << endl << "Incorrect input, please use one of the following commands: " << endl;
			helpText();
		}
	}
}

void helpText() {
	cout << endl << "Commands:" << endl;
	cout << "    - " << "a" << "               // Adds student(s) manually or from a file" << endl;
	cout << "    - " << "d" << "               // Deletes a student from the system" << endl;
	cout << "    - " << "l" << "               // Lists the students by last name" << endl;
	cout << "    - " << "s" << "               // Search through students by name, ID, or email" << endl;
	cout << "    - " << "u" << "               // Update any of the student fields" << endl;
	cout << "    - " << "h" << "               // Lists these commands" << endl;
	cout << "    - " << "q" << "               // Quits the system" << endl;
}

void listStudents(student* roll, int numStudents)
{
	cout << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << roll[i].lastName << ", " << roll[i].firstName << endl;
	}

	return;
}

int addStudent(student* roll, int numStudents) {
	char input = ' ';
	string strInput;

	if (numStudents == CLASS_SIZE) {
		cout << "There are already the maximum number of students in the class, please delete one to add another." << endl;
		return numStudents;
	}

	cout << "You can add one student manually, or multiple from a text file." << endl;
	cout << "Enter 'm' for manual input or 'f' for file input or 'q' for quit: ";

	while (input != 'q') {

		cin >> input;
		if (input == 'q') {
			return numStudents;
		}

		if (input == 'f') {
			cout << endl << "Text file input selected." << endl;
			cout << "Files should be formatted as: usfid last-name first-name email presentation-grade essay-grade project-grade " << endl;
			cout << "There should be one student per line." << endl;
			cout << "** Note: There are a maximum number of fifty students in the class" << endl;
			cout << "Please enter the name of the file to read from (inlcuding the extension): ";
			cin >> strInput;

			ifstream studentFile;
			studentFile.open(strInput);

			if (!studentFile.is_open()) {
				do {
					cout << "Error reading file, please check your filename and try again." << endl;
					cout << "** Note: Be sure the file is in the same folder or include the path" << endl;
					cout << "Please enter the name of the file to read from (inlcuding the extension): ";
					cin >> strInput;

					studentFile.open(strInput);
				} while (!studentFile.is_open());
			}

			string line;
			while (getline(studentFile, line) && numStudents < CLASS_SIZE) {
				istringstream iss(line);
				vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());

				roll[numStudents].usfid = stoi(results[0]);
				roll[numStudents].lastName = results[1];
				roll[numStudents].firstName = results[2];
				roll[numStudents].email = results[3];
				roll[numStudents].presGrade = stoi(results[4]);
				roll[numStudents].essGrade = stoi(results[5]);
				roll[numStudents].projGrade = stoi(results[6]);

				numStudents++;
			}
			return numStudents;
		}
		else if (input == 'm') {
			cout << "Enter the student's USF ID number: ";
			cin >> roll[numStudents].usfid;
			cout << "Enter the student's last name: ";
			cin >> roll[numStudents].lastName;
			cout << "Enter the student's first name: ";
			cin >> roll[numStudents].firstName;
			cout << "Enter the student's mail: ";
			cin >> roll[numStudents].email;
			cout << "Enter the student's presentation grade: ";
			cin >> roll[numStudents].presGrade;
			cout << "Enter the student's essay grade: ";
			cin >> roll[numStudents].essGrade;
			cout << "Enter the student's project grade: ";
			cin >> roll[numStudents].projGrade;
			
			numStudents++;
			return numStudents;
		}
		else {
			cout << "Invalid input, please enter either 'f' for file input or 'm' for manual input or 'q' for quit";
		}
	}
}

int deleteStudent(student* roll, int numStudents) {
	string input;
	cout << "Enter the USF ID number of the student you wish to delete (or 'q' for quit): ";

	while (true) {
		cin >> input;

		if (input == "q") {
			return numStudents;
		}
		for (int i = 0; i < numStudents; i++) {
			if (roll[i].usfid == stoi(input)) {
				roll[i].usfid = 0;
				roll[i].firstName = "";
				roll[i].lastName = "";
				roll[i].email = "";
				roll[i].presGrade = 0;
				roll[i].essGrade = 0;
				roll[i].projGrade = 0;
				--numStudents;
				return numStudents;
			}
		}
		cout << "Student ID not found, please try again (or 'q' to quit)";
	}
}




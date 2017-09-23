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

int addStudent();
void listStudents();
void helpText();

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

int main(int argc, const char * argv[]) {
	int numStudents = 0;
	student roll[CLASS_SIZE];
	
	cout << "Welcome to our class roll system.";
	helpText();
	
	char input;
	
	while (true) {
		cin >> input;
		
		switch (input) {
			case 'a':
				addStudent(studentCount);
				break;
			case 'd':
				Delete();
				break;
			case 'l':
				listStudents();
				break;
			case 's':
				Search();
				break;
			case 'u':
				Update();
				break;
			case 'h':
				helpText();
				break;
			case 'q':
				return;
				break;
			default:
				cout << "Incorrect input, please use one of the following commands: ";
				helpText();

		}
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

int addStudent(int studentCount) {
	char input;
	string strInput;

	if (studentCount == 50) {
		cout << "There are already the maximum number of students in the class, please delete one to add another.";
		return;
	}
	
	cout << "You can add one student manually, or multiple from a text file." << endl;
	cout << "Enter 'm' for manual input or 'f' for file input or 'q' for quit: ";
	
	while (input != 'q') {

		cin >> input;
		if (input == 'q') {
			return studentCount;
		}

		if (input == 'f') {
			cout << endl << "Text file input selected." << endl;
			cout << "Files should be formatted as: usfid last-name first-name email presentation-grade essay-grade project-grade ";
			cout << "There should be one student per line." << endl;
			cout << "** Note: There are a maximum number of fifty students in the class";
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
			while (getline(studentFile, line) && studentCount < 50) {
				istringstream iss(line);
				vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());

				roll[studentCount].usfid = stoi(results[0]);
				roll[studentCount].lastname = results[1];
				roll[studentCount].firstname = results[2];
				roll[studentCount].email = results[3];
				roll[studentCount].presGrade = stoi(results[4]);
				roll[studentCount].essGrade = stoi(results[5]);
				roll[studentCount].projGrade = stoi(results[6]);

				studentCount++;
			}
			return studentCount;
		}
		else if (input == 'm') {
			cout << "Enter the student's USF ID number: ";
			cin >> roll[studentCount].usfid;
			cout << "Enter the student's last name: ";
			cin >> roll[studentCount].lastname;
			cout << "Enter the student's first name: ";
			cin >> roll[studentCount].firstname;
			cout << "Enter the student's mail: ";
			cin >> roll[studentCount].email;
			cout << "Enter the student's presentation grade: ";
			cin >> roll[studentCount].presGrade;
			cout << "Enter the student's essay grade: ";
			cin >> roll[studentCount].essGrade;
			cout << "Enter the student's project grade: ";
			cin >> roll[studentCount].projGrade;
			return studentCount;
		}
		else {
			cout << "Invalid input, please enter either 'f' for file input or 'm' for manual input or 'q' for quit";
		}
	}
}

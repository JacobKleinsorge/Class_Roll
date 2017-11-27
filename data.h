#include <iostream>
#include <signal.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

vector<string> firstNames;
vector <string> lastNames;
vector<string> ID;
vector<string> emails;
vector<string> essayGrade;
vector<string> presentation;
vector<string> project;

string Firstnames,Lastnames,id,email,essay,pres,proj,nme,NEM,firstname,lastname;
int location;
bool inVec = false;
bool rs = false;

void VecMaker()
{
  ifstream FirstnameFile("firstNames.txt");
  ifstream LastnameFile("lastNames.txt");
  ifstream idFile("ID.txt");
  ifstream emailFile("emails.txt");
  ifstream essayFile("essay.txt");
  ifstream presFile("presentation.txt");
  ifstream projFile("Project.txt");

    while (getline(FirstnameFile, Firstnames))
    {
        firstNames.push_back(Firstnames);
    }
    while (getline(LastnameFile, Lastnames))
    {
        lastNames.push_back(Lastnames);
    }
    while (getline(idFile, id))
    {
        ID.push_back(id);
    }
    while (getline(emailFile, email))
    {
        emails.push_back(email);
    }
    while (getline(essayFile, essay))
    {
        essayGrade.push_back(essay);
    }
    while (getline(presFile, pres))
    {
        presentation.push_back(pres);
    }
    while (getline(projFile, proj))
    {
        project.push_back(proj);    
    }
}

void saveFile()
{
    ofstream FirstnameFile("firstNames.txt");
    ofstream LastnameFile("lastNames.txt");
    ofstream idFile("ID.txt");
    ofstream emailFile("emails.txt");
    ofstream essayFile("essay.txt");
    ofstream presFile("presentation.txt");
    ofstream projFile("Project.txt");

    for(int i = 0; i < firstNames.size(); i++)
    {
        FirstnameFile << firstNames[i] << endl;
    }
    FirstnameFile.close();

    for(int i = 0; i < lastNames.size(); i++)
    {
        LastnameFile << lastNames[i] << endl;
    }
    LastnameFile.close();

    for(int i = 0; i < ID.size(); i++)
    {
        idFile << ID[i] << endl;
    }
    idFile.close();

    for(int i = 0; i < emails.size(); i++)
    {
        emailFile << emails[i] << endl;
    }
    emailFile.close();

    for(int i = 0; i < essayGrade.size(); i++)
    {
        essayFile << essayGrade[i] << endl;
    }
    essayFile.close();

    for(int i = 0; i < presentation.size(); i++)
    {
        presFile << presentation[i] << endl;
    }
    presFile.close();

    for(int i = 0; i < project.size(); i++)
    {
        projFile << project[i] << endl;
    }
    projFile.close();
}


int SearchVectors(string nme, string NEM)
{
    string upper = nme;
    string lower = nme;

    string upper2 = NEM;
    string lower2 = NEM;


    if(inVec == false){
        for(int i = 0; i < firstNames.size(); i++){
            if((upper == firstNames[i] || lower == firstNames[i]) && (upper2 == lastNames[i] || lower2 == lastNames[i])){
                location = i;
                inVec = true;
                raise(SIGSEGV);
                return location;
            }
        }
    }
    if(inVec == false)
    {
        for(int i = 0; i < ID.size(); i++)
        {
            if(upper == ID[i] || lower == ID[i])
            {
                location = i;
                raise(SIGSEGV);
                return location;
            }
        }
    }

    if(inVec == false)
    {
        for(int i = 0; i < emails.size(); i++)
        {
            if(upper == emails[i] || lower == emails[i])
            {
                location = i;
                raise(SIGSEGV);
                return location;
            }
        }
    }

    raise(SIGSEGV);
    return 0;
}


int SearchData(){

    string choice = "";
    string first = "";
    string last = "";
    NEM = "";
    int result;

    cout << "Would you like to search by name, email, or id: ";
    cin >> choice;
    if(choice == "name")
    {
        cout << "Please enter students first name: ";
        cin >> first;
        cout << "Please enter students last name: ";
        cin >> last;
        result = SearchVectors(first,last);
    }
    else if(choice == "id" || choice == "email")
    {
        cout << "Please enter students email or id: ";
        cin >> nme;
        result = SearchVectors(nme, NEM);
    }
    else
    {
        SearchData();
    }

    if(inVec == false)
    {
        cout << endl;
        cout << "Sorry that name does not exsist, try agian!" << endl;
        rs = false;
    }
    else
    {
        cout << endl;
        cout << "First Name: " << firstNames[result] << endl;
        cout << "Last Name: " << lastNames[result] << endl;
        cout << "Email: " << emails[result] << endl;
        cout << "Presentation Grade: " << presentation[result] << endl;
        cout << "Essay Grade: " << essayGrade[result] << endl;
        cout << "Project Grade: " << project[result] << endl;
        inVec = false;
        rs = true;
        return result;
        cout << endl;
    }
    return 0;
}



int removeData()
{
    string answer = "";
    int result = SearchData();
    if(rs == true)
    {
        raise(SIGSEGV);
        cout << endl;
        cout << "Is this the correct student (y/n) or exit: ";
        cin >> answer;

        if(answer == "y")
        {
            firstNames.erase(firstNames.begin() + result);
            ID.erase(ID.begin() + result);
            emails.erase(emails.begin() + result);
            essayGrade.erase(essayGrade.begin() + result);
            presentation.erase(presentation.begin() + result);
            project.erase(project.begin() + result);
            cout << endl;
            cout << "Okay, the entry has been erased!" << endl;
        }
        else if(answer == "n")
        {
            return(1);
        }
        else if(answer == "exit")
        {
            exit(1);
        }
        else
        {
            removeData();
        }
    }
    return 0;
}



void addData()
{
    string Firstname = "";
    string Lastname = "";
    string id = "";
    string email = "";
    string option = "";
    string status = "";
    string answer = "";
    string grade = "";

    cout << "What is the students first name: ";
    cin >> Firstname;
    cout << endl;
    firstNames.push_back(Firstname);

    cout << "What is the students last name: ";
    cin >> Lastname;
    cout << endl;
    lastNames.push_back(Lastname);

    cout << "What is the students ID: ";
    cin >> id;
    cout << endl;
    ID.push_back(id);

    cout << "What is the students email: ";
    cin >> email;
    cout << endl;
    emails.push_back(email);

    cout << "Are we adding any grades (y/n): ";
    cin >> answer;
    cout << endl;
    if(answer == "y")
    {
        cout << "Are we adding a presentation grade (y/n): ";
        cin >> option;
        cout << endl;
        if(option == "y")
        {
            cout << "What is this students presentation grade: ";
            cin >> grade;
            cout << endl;
            presentation.push_back(grade);
        }
        else
        {
            presentation.push_back("None");
        }
        cout << "Are we adding an essay grade (y/n): ";
        cin >> option;
        cout << endl;
        //raise(SIGSEGV);


        if(option == "y")
        {
            cout << "What is this students essay grade: ";
            cin >> grade;
            cout << endl;
            presentation.push_back(grade);
        }
        else
        {
            essayGrade.push_back("None");
        }
        cout << "Are we adding a project grade (y/n): ";
        cin >> option;
        cout << endl;

        if(option == "y")
        {
            cout << "What is this students project grade: ";
            cin >> grade;
            cout << endl;
            project.push_back(grade);
        }
        else
        {
            project.push_back("None");
        }
    }
    else
    {
        essayGrade.push_back("None");
        project.push_back("None");
        presentation.push_back("None");
    }
}
int editData()
{
    string name = "";
    string id = "";
    string email = "";
    string option = "";
    string status = "";
    string answer = "";
    string grade = "";
    int result = SearchData();


    if(rs == true)
    {
        cout << endl;
        cout << "Is this the correct student (y/n) or exit: ";
        cin >> answer;
        cout << endl;

        if(answer == "y")
        {
            cout << "Are we changing this students name (y/n): ";
            cin >> answer;
            cout << endl;

            if(answer == "y")
            {
                cout << "Whats the students new first name: ";
                cin >> name;
                cout << endl;
                firstNames[result - 1] = name;
                cout << "Whats the students new last name: ";
                cin >> name;
                cout << endl;
                lastNames[result - 3] = name;
            }

            else
            {
                exit(1);
            }

            cout << "Are we changing this students ID (y/n): ";
            cin >> answer;
            cout << endl;

            if(answer == "y")
            {
                cout << "Whats the students new ID: ";
                cin >> id;
                cout << endl;
                ID[result] = id;
            }
            else
            {
                exit(1);
            }

            cout << "Are we changing this students email (y/n): ";
            cin >> answer;
            cout << endl;


            if(answer == "y")
            {
                cout << "Whats the students new email: ";
                cin >> email;
                cout << endl;
                emails[result - 2] = email;
            }
            else
            {
                exit(1);
            }
                cout << "Are we changing any grades (y/n): ";
                cin >> answer;
                cout << endl;

            if(answer == "y")
            {
                cout << "Are we changing the presentation grade (y/n): ";
                cin >> option;
                cout << endl;

                if(option == "y")
                {
                    cout << "What is this students new presentation grade: ";
                    cin >> grade;
                    cout << endl;
                    presentation[result - 1] = grade;
                }
                else
                {
                    exit(1);
                }

                    cout << "Are we changing the essay grade (y/n): ";
                    cin >> option;
                    cout << endl;

                if(option == "y")
                {
                    cout << "What is this students new essay grade: ";
                    cin >> grade;
                    cout << endl;
                    essayGrade[result - 2] = grade;
                }
                else
                {
                exit(1);
                }
                    cout << "Are we changing the project grade (y/n): ";
                    cin >> option;
                    cout << endl;

                if(option == "y")
                {
                    cout << "What is this students new project grade: ";
                    cin >> grade;
                    cout << endl;
                    project[result - 1] = grade;
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                exit(1);
            }
        }
        else if(answer == "n")
        {
            return(1);
        }
        else
            editData();
    }
    return 0;
}

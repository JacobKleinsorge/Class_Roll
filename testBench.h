#include <iostream>
#include "data.h"

using namespace std;

void searchName()
{
    ofstream resultsInputCorrect("SearchResultsCorrect.txt");
    ofstream resultsInputIncorrect("SearchResultsIncorrect.txt")
    
    //Correct input
    for (int i = 0; i < firstNamesCorrect->size(); i++)
    {
        index = searchVectors(firstNamesCorrect[i], lastNamesCorrect[i]);
        
        if (firstNamesCorrect[i] == firstNames[index])
        {
            resultsInputCorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    //Incorrect input
    for (int i = 0; i < firstNamesIncorrect->size(); i++)
    {
        index = searchVectors(firstNamesIncorrect[i], lastNamesIncorrect[i]);
        
        if (firstNamesIncorrect[i] == firstNames[index])
        {
            resultsInputIncorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    resultsInputCorrect.close();
    resultsInputIncorrect.close();
}

void searchEmail()
{
    ofstream resultsInputCorrect("SearchResultsCorrect.txt");
    ofstream resultsInputIncorrect("SearchResultsIncorrect.txt")
    
    //Correct input
    for (int i = 0; i < emailsCorrect->size(); i++)
    {
        index = searchVectors(emailsCorrect[i], "");
        
        if (emailsCorrect[i] == emails[index])
        {
            resultsInputCorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    //Incorrect input
    for (int i = 0; i < emailsIncorrect->size(); i++)
    {
        index = searchVectors(emailsIncorrect[i], "");
        
        if (emailsIncorrect[i] == emails[index])
        {
            resultsInputIncorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    resultsInputCorrect.close();
    resultsInputIncorrect.close();
}

void searchID()
{
    ofstream resultsInputCorrect("SearchResultsCorrect.txt");
    ofstream resultsInputIncorrect("SearchResultsIncorrect.txt")
    
    //Correct input
    for (int i = 0; i < IDCorrect->size(); i++)
    {
        index = searchVectors(IDCorrect[i], "");
        
        if (IDCorrect[i] == ID[index])
        {
            resultsInputCorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    //Incorrect input
    for (int i = 0; i < IDIncorrect->size(); i++)
    {
        index = searchVectors(IDIncorrect[i], "");
        
        if (IDIncorrect[i] == ID[index])
        {
            resultsInputIncorrect << firstNames[index] << " "
                                 << lastNames[index] << " "
                                 << ID[index] << " "
                                 << emails[index] << " "
                                 << essayGrade[index] << " "
                                 << presentation[index] << " "
                                 << project[index]
                                 << endl;
        }
        else
        {
            cout << "Descrepancy in results, search stopped" << endl;
            break;
        }
    }
    
    resultsInputCorrect.close();
    resultsInputIncorrect.close();
}

void testSearch()
{
    char choice = '';
    
    cout << "Search by (enter number):" << endl
         << "1) name" << endl
         << "2) email" << endl
         << "3) ID" << endl
         <<endl;
    cin >> choice;
    
    if (choice == '1')
    {
        searchName()
    }
    else if (choice == '2')
    {
        searchEmail();
    }
    else if (choice == '3')
    {
        searchID();
    }
}

int runTestBench()
{
    while (true)
    {
        char input = '';
        char choice = '';
        
        cout << "Run search fucntionality test bench? (y/n): ";
        cin >> input;
        if (input == 'n')
        {
            return 1;
        }
        
        testSearch();
    }
    
    return 0;
}

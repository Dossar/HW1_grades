/* 
 * File:   gradelogger.cpp
 * Author: Roy Van Liew
 *
 * Created on January 29, 2014, 12:01 PM
 */

// Code works but calc_ave and calc_letter are not void.

#include <iostream>
#include <string>
using namespace std;

class Student
{
    
public:           
    void input();
    void output();	

private:
    int qgrade[4]; // Each array cell indicates the quiz number's grade.
    int qweight[4]; // Each array cell indicates the quiz number's weight.
    // 0 for quiz1, 1 for quiz2, 2 for midterm, 3 for final exam.
    double avweight;
    char lettergrade;

    void calc_ave();
    void calc_letter();

};
	

// Input grades and weights
void Student::input(){
    
    int i; // i is for number of exam grades.
    int addup = 1;
    int gradeadd, weightadd;
    while(addup == 1)
    {
        gradeadd = 0;
        weightadd = 0;
        for ( i = 0 ; i < 4 ; i++ )
        {
            if(i<2){
                cout << "Input grade for quiz #" << (i+1) << ": ";
                cin >> Student::qgrade[i];
                cout << "Input weight for quiz #" << (i+1) << ": ";
                cin >> Student::qweight[i];
            }
            else if(i==2){
                cout << "Input grade for midterm exam: ";
                cin >> Student::qgrade[i];
                cout << "Input weight for midterm exam: ";
                cin >> Student::qweight[i];
            }
            else if(i==3){
                cout << "Input grade for final exam: ";
                cin >> Student::qgrade[i];
                cout << "Input weight for final exam: ";
                cin >> Student::qweight[i];
            }          
        }
        for( i = 0 ; i < 4 ; i++ )
        {
            gradeadd += Student::qgrade[i];
            weightadd += Student::qweight[i];
        }
        if( gradeadd > 400 || gradeadd < 0 )
        {
            cout << "Grades entered are less than 0 or over 100 percent. Try again.\n\n";
        }
        else if( weightadd != 100 )
        {
            cout << "Weights entered do not total up to 100 percent. Try again.\n\n";
        }
        else
            addup = 0;
        
    }
    
    calc_ave();
    calc_letter();
    
}

// Output all the students' grades.
void Student::output(){
    
    cout << "Quiz 1: " << Student::qgrade[0] << " weighted " << Student::qweight[0] << "%\n";
    cout << "Quiz 2: " << Student::qgrade[1] << " weighted " << Student::qweight[1] << "%\n";
    cout << "Miderm Exam: " << Student::qgrade[2] << " weighted " << Student::qweight[2] << "%\n";
    cout << "Final Exam: " << Student::qgrade[3] << " weighted " << Student::qweight[3] << "%\n";
    cout << "This student scored " << Student::avweight << " and got a "
            << Student::lettergrade << " grade for the course.\n";
    
}

// Calculate average weighted grade
void Student::calc_ave(){

    int i;
    for (i = 0; i < 4; i++) {
        avweight += (double) (Student::qgrade[i] * (Student::qweight[i] / 100.0)); // Add up all weighted scores
    }
}

// Calculate final letter grade
void Student::calc_letter(){
    if( avweight < 65.0 )
        lettergrade = 'F';
    else if( avweight >= 65.0 && avweight < 70.0 )
        lettergrade = 'D';
    else if( avweight >= 70.0 && avweight < 80.0 )
        lettergrade = 'C';
    else if( avweight >= 80.0 && avweight < 90.0 )
        lettergrade = 'B';
    else if( avweight >= 90.0 && avweight <= 100.0 )
        lettergrade = 'A';
}

/*
 * 
 */
int main() {
    
    Student sGrade[3]; // Three students are getting grades evaluated
    int s; // For the students in the loops

    int choice = 1;  // This is to get the while loop working
    while (choice != 0)
    {
        cout << "\nStudent Grade Evaluator\n";
        cout << "This program enters grades for 3 students and calculates them.\n";
        cout << "0 - Quit Program\n";
        cout << "1 - Input Grades\n";
        cout << "2 - Output Grades\n";		

        cout << "Please select an item from the menu list: ";
        cin >> choice;

        switch (choice)
        {
        case 0:	
            cout << "Thank you for your time.\n";
			break;
        case 1:	
            for( s = 0 ; s < 3 ; s++ )
            {
                cout << "\nPlease input student " << (s+1) << "'s grades.\n";
                cout << "Grades and weight should be integers between 0 and 100.\n";
                sGrade[s].input();
                cout << "Student " << (s+1) << "'s grades successfully entered.\n";
            }
			break;
	
        case 2:	
            for( s = 0 ; s < 3 ; s++ )
            {
                cout << "\nStudent " << (s+1) << "'s grades are:\n";
                sGrade[s].output();
            }
			break;
		
        default:
            cout << "\nInvalid input.\n";
        }
    }
    
    return 0;
}


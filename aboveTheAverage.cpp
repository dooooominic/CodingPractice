#include<iostream>
using namespace std;

/*
Uses array to store input student grades and computes the average, and also displays all grades higher than the average!
*/

const int MAX_CLASS_SIZE = 60;

int main(){
    int numOfStudents;
    int gradesList[MAX_CLASS_SIZE]; //creates an array with 60 spaces!
    int currGrade;
    double average;


    cout<<"Please enter the number of students in the class (no more than " << MAX_CLASS_SIZE <<"): ";
    cin>> numOfStudents;

    cout<<"Please enter the grades of students, separated by a space: " <<endl;
    for(int i=0; i<numOfStudents; i++){
        cin>>currGrade;
        gradesList[i] = currGrade;
    }

    int sum = 0;
    for(int i=0; i<numOfStudents; i++){
        sum +=gradesList[i];
    }   
    average = (double)sum/(double)numOfStudents;
    cout<< "The average of all students grades is: " << average <<endl;

    cout<< "The grades above the average are: " <<endl;
    for(int i=0; i<numOfStudents; i++){
        if(gradesList[i]>average){
            cout<< gradesList[i] << " ";
        }
    }
    cout<<endl;

return 0;
}
#include<iostream>
using namespace std;

int main(){
    int numOfStudents;
    int count;
    int curr, sum;
    double average;

    cout<< "Please enter the number of students: " <<endl;
    cin >> numOfStudents;

    cout<<"Please enter the students' grades, separated by a space: " <<endl;

    for (count = 1; count <= numOfStudents; count++){
        cin >>curr;
        sum +=curr;
    }

    average = (double)sum/(double)numOfStudents; //need to cast both sum and numOfStudents to double for the double average!
    cout <<"The average is: " << average;

return 0;
}
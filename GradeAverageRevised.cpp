#include<iostream>
using namespace std;

int main(){

bool seenEndOfInput; //flag variable
int curr, sum, numOfStudents;
double average;

cout <<"Please enter the grades separated by a space " <<endl;
cout <<"End the sequence by pressing -1: " <<endl;

seenEndOfInput = false;
sum = 0;
numOfStudents = 0;

while (seenEndOfInput == false){ //while the flag is down, take in inputs 
    cin >>curr;

    if (curr == -1){
        seenEndOfInput = true; //only raise the flag when user inputs -1, meaning no more students to input. 
    }
    else{
        sum +=curr; //while the flag is down, take the inputs and calculate sum and increment numOfStudents.
        numOfStudents ++;
    }
}

average = (double)sum/(double)numOfStudents; //after the while loop ends, print average and stuff as needed. 
cout<<"You have " <<numOfStudents << " students" <<endl;
cout<<"The average is: " <<average <<endl;

return 0;

}
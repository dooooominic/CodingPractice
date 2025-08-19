#include<iostream>
#include<string>
using namespace std;

int main(){

string firstName, middleName,lastName;

cout<<"Please enter your name in the following format: "<<endl;
cout<< "FIRST MIDDLE LAST. Separated by a space in between each:" <<endl;
cin>> firstName >> middleName>> lastName;

string firstMiddleInitial = firstName + " "+ middleName[0]+".";

cout<< "Your name is: " << lastName << ", " << firstMiddleInitial;
}


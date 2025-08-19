#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void openInputFile(ifstream& inFile);


class Student{
public:
    int id;
    double score;
    string name;
};

int main(){
    ofstream outFile;
    outFile.open("file.txt"); //creating output file outFile in current directory if it doesn't exist already
    outFile<<"Hello World!"<<endl;


    ifstream inFile;
    Student temp;
    inFile.open("file.txt");
    //this line does both a check for valid input and a reading from inFile stream!
    while(inFile>>temp.id){ //have to be public to access them! Otherwise use setters. int id ... setID(int id);

        inFile>>temp.score;
        inFile.ignore(9999,'\t'); //ignores up to 9999 characters, until the first tab character. 
        inFile.ignore(9999, ' '); //can skip everything up to a blank space like this. Or just inFile.ignore(); default is skipping 1 space/character!
        getline(inFile, temp.name); //gets everything after the tab character up to which we ignored from line above
    }
}

void openInputFile(ifstream& inFile){
    string fileName;
    cout<<"What's the name of your file?"<<endl;
    cin>> fileName;
    inFile.open(fileName);
    while(!inFile){
        cout<<"Error! Your file could not be opened."<<endl;
        cout<<"What's the name of your file?"<<endl;
        cin>>fileName;
        inFile.clear(); //good practice to clear any flags that may have been raised from not opening properly
        inFile.open(fileName);
    }
}
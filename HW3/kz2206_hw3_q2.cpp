#include<iostream>
#include<string>
using namespace std;

int main(){
string name,status;
int graduationYear, currentYear;

    cout<<"Please enter your name: " <<endl;
    cin >>name;
    cout<<"Please enter your graduation year: "<<endl;
    cin >>graduationYear;
    cout<<"Please enter current year: " <<endl;
    cin >>currentYear;

    if (graduationYear-currentYear >4){
        status = " not in college yet";
    }
    else if (graduationYear-currentYear ==4){
        status = "are a freshman ";
    }
    else if(graduationYear-currentYear == 3){
        status = "are a sophomore ";
    }
    else if(graduationYear-currentYear ==2){
        status = "are a junior ";
    }
    else if(graduationYear-currentYear ==1){
        status = "are a senior ";
    }
    else{
        status = "have graduated!";
    }

    cout << name << ", you " << status << endl;

    return 0;

}
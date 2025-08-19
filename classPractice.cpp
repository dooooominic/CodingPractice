#include<iostream>
using namespace std;

class Date{
private: //internal attributes/elements of this "object"
    int day;
    int month;
    int year;

public:
    void setDay(int newDay){ //You can declare function inside class like this that can be accessed outside (in main?)
        if(newDay>0 && newDay<=31)
            day = newDay;
    }

    void setMonth(int newMonth);

    void setYear(int newYear){
        year = newYear;
    }

    int getDay()const{ //const function because we are not changing anything! Just accessing. 
        return day;
    }

    int getMonth()const{ //we are not using these?
        return month;
    }
    int getYear()const{
        return year;
    }

    void displayDate()const{ //a CONST function in the class that can print the date we set.
        cout<<month<<"/" <<day <<"/"<< year<<endl;
    }
};

void Date::setMonth(int newMonth){ //Or you can call class and declare the function this way!
    if(newMonth>=1 && newMonth <=12){
        month = newMonth; //can access private member variable month here, because we are using Date:: setMonth and in the Date class. 
    } 
}


int main(){
    Date birthday;
    birthday.setDay(15);
    birthday.setMonth(2);
    birthday.setYear(1999);

    cout<< "Very important date: ";
    birthday.displayDate();
    cout<<"The year is: " << birthday.getYear();
}

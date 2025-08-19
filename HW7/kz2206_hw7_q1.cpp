#include<iostream>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
/*Prints the monthly calendar given an integer number of days in the month, as well as a corresponding integer for the day
of the week for the starting day in that month. Returns a number that represents the day of the week of the last day
in that month.
*/
void calendarHeader();
/*Prints the calendar header line with texts of Mon, Tue, Wed, etc. */

bool isLeapYear(int year);
/*Returns true if the integer year variable is a leap year, returns false if the year is not a leap year.*/

void printYearCalender(int year, int startingDay);


const int JANUARY = 31;
const int MARCH = 31;
const int APRIL = 30;
const int MAY = 31;
const int JUNE = 30;
const int JULY = 31;
const int AUGUST = 31;
const int SEPTEMBER = 30;
const int OCTOBER = 31;
const int NOVEMBER = 30;
const int DECEMBER = 31;


int main(){
    int year, startingDay;
    cout<< "Please enter the year of which you would like to see the calendar of: ";
    cin>> year;
    cout<< "Please enter the day of the week for January 1st of the year (1 for Monday, 2 for Tuesday, etc.): ";
    cin>> startingDay;
    printYearCalender(year,startingDay);

}

int printMonthCalendar(int numOfDays, int startingDay){
    calendarHeader();
    //first line of calendar:
    for(int i=1; i<=7; i++){
        if(i<startingDay){
            cout<<" \t ";
        }
        else{
            cout<< i+1-startingDay<<"\t";
        }
    }
   cout<<endl;

    //rest of the calendar: 
    for(int i=7-startingDay+2; i<=numOfDays-(startingDay+1)+7;i+=7){ //initial i: +1 for offset and +1 for next day. = +2.
        for(int j=i; j< i+7;j++){
            if(j>numOfDays){
                break;
            }
            else{
                cout<< j <<"\t";
            }
        }
        cout<<endl;
    }
    return ((numOfDays%7)+startingDay)%7; //returns the day of the week for the last day of the month.

    //if else statement to check if im starting at the right number
}

void calendarHeader(){

    cout<< "Mon \t Tue \t Wed \t Thu \t Fri \t Sat \t Sun \t" <<endl;

}

bool isLeapYear(int year){
    if(year%4==0 && year%100 !=0){
        return true;
    }
    else if(year%100==0 && year%400==0){
        return true;
    }
    else{
        return false;
    }
}


void printYearCalender(int year, int startingDay){
    int february;

    cout<< "January " << year <<endl;
    int nextday = printMonthCalendar(JANUARY, startingDay);
    
    cout<< "February " << year <<endl;
    if(isLeapYear(year)){
        february = 29;
    }
    else{
        february = 28;
    }
    nextday = printMonthCalendar(february, nextday);

    cout<< "March " << year <<endl;
    nextday = printMonthCalendar(MARCH, nextday);

    cout<< "April " << year <<endl;
    nextday = printMonthCalendar(APRIL, nextday);

    cout<< "May " << year <<endl;
    nextday = printMonthCalendar(MAY, nextday);

    cout<< "June " << year <<endl;
    nextday = printMonthCalendar(JUNE, nextday);

    cout<< "July " << year <<endl;
    nextday = printMonthCalendar(JULY, nextday);

    cout<< "August " << year <<endl;
    nextday = printMonthCalendar(AUGUST, nextday);

    cout<< "September " << year <<endl;
    nextday = printMonthCalendar(SEPTEMBER, nextday);

    cout<< "October " << year <<endl;
    nextday = printMonthCalendar(OCTOBER, nextday);

    cout<< "November " << year <<endl;
    nextday = printMonthCalendar(NOVEMBER, nextday);

    cout<< "December " << year <<endl;
    nextday = printMonthCalendar(DECEMBER, nextday);
}
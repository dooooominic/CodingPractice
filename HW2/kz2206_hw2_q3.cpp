#include<iostream>
using namespace std;

int main(){
int daysJohn, hoursJohn, minutesJohn, daysBill, hoursBill, minutesBill;
int totalDays, totalHours, totalMinutes;

cout << "Please enter the number of days John has worked: " <<endl;
cin >> daysJohn;

cout << "Please enter the number of hours John has worked: " <<endl;
cin >> hoursJohn;

cout << "Please enter the number of minutes John has worked: " <<endl;
cin >> minutesJohn;

cout << "Please enter the number of days Bill has worked: " <<endl;
cin >> daysBill;

cout << "Please enter the number of hours Bill has worked: " <<endl;
cin >> hoursBill;

cout << "Please enter the number of minutes Bill has worked: " <<endl;
cin >> minutesBill;

totalMinutes = (minutesJohn + minutesBill)%60; 
totalHours = (hoursJohn + hoursBill + (minutesJohn + minutesBill)/60)%24;
totalDays = daysJohn + daysBill + (hoursJohn + hoursBill + (minutesJohn + minutesBill)/60)/24;


cout << "The total time both of them worked together is: " << totalDays << " days, " <<totalHours << " hours, and " 
<< totalMinutes << " minutes. " << endl;

return 0;

}
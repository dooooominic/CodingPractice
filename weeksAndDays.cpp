#include <iostream>
using namespace std;

int main(){
    int daysTraveled;
    int fullWeeks, remainingDays;

    cout<<"Please enter number of days you traveled:" <<endl;
    cin >> daysTraveled;
    fullWeeks = daysTraveled/7;
    remainingDays = daysTraveled%7;
    cout<< daysTraveled << " days are " << fullWeeks << " weeks and " << remainingDays << " days. " << endl;
    return 0;

}
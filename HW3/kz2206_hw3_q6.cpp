#include<iostream>
#include<string>
using namespace std;

int main(){
    int hour, min, callLength;
    string dayOfWeek;
    char colon;
    double cost;
    const double weekendPrice = 0.15; //weekend call price regardless of hour
    const double weekDayDuring = 0.40; //cost of call on a weekday during 8am-6pm
    const double weekDayOutside = 0.25; // cost of call on a weekday outside of 8am-6pm
    
    cout<< "Input call start time in 24-hour format: e.g. 13:35" <<endl;
    cin>> hour >> colon >> min;

    cout <<"Please enter the day of the week this call started (Mo/Tu/We/Th/Fr/Sa/Su): " <<endl;
    cin >> dayOfWeek;

    cout<< "Please enter the length of your call rounded up to the nearest minute: " <<endl;
    cin >>callLength;

    if (dayOfWeek == "Sa" || dayOfWeek == "Su"){
        cost = callLength * weekendPrice;
        cout << "Your call cost $" << cost <<endl;
    }

    else if (dayOfWeek == "Mo" || dayOfWeek == "Tu" || dayOfWeek ==  "We" || dayOfWeek ==  "Th" || dayOfWeek == "Fr"){
        if (hour < 8 || hour >=18){
            cost = callLength * weekDayOutside;
        }
        else{
            cost = callLength * weekDayDuring;
        }
    cout<< "Your call cost $" << cost <<endl;
    }

    else{
        cout <<"You've entered an invalid option. Please try again." <<endl;
    }

return 0;
}
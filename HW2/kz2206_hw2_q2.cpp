#include<iostream>
using namespace std;

int main(){
    int numberOfQuarters, numberOfDimes, numberOfNickles, numberOfPennies, totalDollars, totalCents;

    cout<< "Please enter your amount in the format of dollars and cents separated by a space" << endl;
    cin >> totalDollars >> totalCents;

    numberOfQuarters = totalDollars*4 + totalCents/25;

    numberOfDimes = (totalCents%25)/10;

    numberOfNickles = ((totalCents%25)-(numberOfDimes*10))/5;

    numberOfPennies = (totalCents%25)-(numberOfDimes*10)-(numberOfNickles*5);

    cout << numberOfQuarters << " quarters " << numberOfDimes << " dimes " << numberOfNickles << " nickles " 
    << numberOfPennies << " pennies " << endl;

    //I suppose it probably would've been easier to convert the total amount into tens and hundreds of cents and then divide that way!

return 0;

}
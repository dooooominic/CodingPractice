#include<iostream>
using namespace std;

int main(){

int numberOfQuarters, numberOfDimes, numberOfNickles, numberOfPennies;
double totalValue;

cout<< "Please enter number of coins: " << endl;
cout << "# of quarters: " << endl;
cin >> numberOfQuarters;

cout<< "# of dimes: " << endl;
cin >> numberOfDimes;

cout<< "# of nickles: " << endl;
cin >> numberOfNickles;

cout<< "# of pennies: " << endl;
cin >> numberOfPennies;

totalValue = (numberOfQuarters*0.25) + (numberOfDimes*0.10) + (numberOfNickles*0.05) + (numberOfPennies)*0.01;

cout<<"The total is " << (int)totalValue << " dollars and " << 100*(totalValue-(int)totalValue) << " cents." <<endl;
    return 0;
}
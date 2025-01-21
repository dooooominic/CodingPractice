#include<iostream>
using namespace std;

int main(){
    double tempF, tempC;
    cout << "Please enter a temperature in Fahrenheit scale: " <<endl;
    cin >> tempF;

    tempC = (tempF - 32)*(5.0/9);

    cout<< tempF << " degrees Fahrenheit is equal to " << tempC << " degrees Celsius. " << endl;

    return 0;
}
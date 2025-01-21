#include <iostream>
using namespace std;

int main(){
    char inputChar;
    int asciiValue;

    cout << "Enter your character: " << endl;
    cin >> inputChar;

    asciiValue = (int)inputChar; //case the inputChar into an int and store it in asciiValue!

    cout <<"Your input character is equivalent to the ASCII value of " << asciiValue << endl;
    return 0;
}
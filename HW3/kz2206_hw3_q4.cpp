#include<iostream>
using namespace std;

int main(){

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int choice;
double inputNumber, result, decimalPart;

cout<<"Please enter a real number: " <<endl;
cin >> inputNumber;

cout<<"Choose your rounding method: " <<endl;
cout<<"1. Floor round" <<endl;
cout<<"2. Ceiling round"<<endl;
cout<<"3. Round to the nearest whole number" <<endl;

cin>>choice;

switch(choice){

case 1:
    result = (int)inputNumber;
    cout <<result;
break;

case 2:
    result = (int) (inputNumber+1.0);
    cout<<result; 
break;


case 3: 
decimalPart = inputNumber - (int)inputNumber; //had to put this line inside the case rather than before case 3. Why? 
    if (decimalPart < 0.5){
        result = (double)((int)inputNumber);
        cout <<result;
    }
    else {
        result = (int)(inputNumber+1.0);
        cout <<result;
    }
break;

default:
    cout<<"Invalid input. Try again. "<<endl;
break;

}

return 0;
}
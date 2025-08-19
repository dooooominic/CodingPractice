#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

void randomAssign(int arr[]);
//Uses srand and rand to assign random values between 1 to 3 to each digit.

void printArray(int arr[], int arrSize);
//Helper function for printing arrays.

int getActualPin(int arr[], int &actualPin);
//Helper function to calculate the correct PIN given the randomization to each digits in randomAssign.


const int PIN_NUMBER = 83783; //This is the PIN number I have set and am using for this program. 

int main(){
    int digits[10]={0,1,2,3,4,5,6,7,8,9};
    int pinNums[10];

    randomAssign(pinNums);

    cout<<"Please enter your PIN according to the following mapping: " <<endl;
    cout<< "PIN: \t"; 
    printArray(digits, 10);
    cout<<endl;
    cout << "NUM: \t"; 
    printArray(pinNums,10);
    cout<<endl;

    int actualPin, enteredPin;
    getActualPin(pinNums,actualPin);

    cin>> enteredPin;
    if(enteredPin==actualPin){
        cout<<"Your PIN is correct.";
    }
    else{
        cout<< "Your PIN is not correct. ";
    }

return 0;
}

void randomAssign(int arr[]){
    srand(time(0));
    for(int i=0; i<10;i++){
        arr[i]=(rand()%3)+1;
    }
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++) {
    cout<<arr[i]<<' ';
 }
    cout<<endl;
}

int getActualPin(int arr[], int &actualPin){

    actualPin = pow(10,4)*arr[8]+pow(10,3)*arr[3]+pow(10,2)*arr[7]+pow(10,1)*arr[8]+pow(10,0)*arr[3]; 
    //calculating using my actual pin 83783
    return actualPin;
}

#include<iostream>
using namespace std;

int main(){
//HW4 Question 6: printing all numbers from 1 to input that have more even digits than odd digits. 
int input;
int currDigit, evenCounter, digitCounter;
cout<<"Enter a positive integer: "<<endl;
cin>>input;


for(int i=1; i<=input; i++){
    //reset counters for each loop:
    digitCounter=0; //counting total number of digits for each number
    evenCounter=0; //counting number of even digits for each number
    int num = i; //need a temporary variable to hold the value of each i! Otherwise input gets changed inside loop.
    while(num>0){
        currDigit = num%10;
        if(currDigit%2==0){
            evenCounter ++;
        }
    digitCounter++;
    num = num/10;
    }
    if(digitCounter-evenCounter<evenCounter){
        cout<<i<<endl;
    }
}

return 0;
}



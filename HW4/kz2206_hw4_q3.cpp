#include<iostream>
using namespace std;

//HW4 Question 3: decimal to binary, without strings!

int main(){

int input, output;

cout<<"Enter decimal number: "<<endl;
cin >> input;

output = 0;

for(int i=1; i>0; i=i*10){
    if(input>0){
        int remainder = input%2;
        output = output+ remainder*i; //adding the decimal equivalent amount to the right place
        input = input/2;
    }
}
cout<<output<<endl;
}



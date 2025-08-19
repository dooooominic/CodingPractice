#include<iostream>
#include<string>
using namespace std;

//roman numeral conversion question

int main(){

const int I = 1, V=5, X=10,L=50,C=100,D=500,M=1000;
int input, inputCopy;
string outputString = "";

cout<<"Enter decimal number: " <<endl;
cin >>input;
inputCopy = input;

while(input/M>=1){
    outputString = outputString + "M";
    input= input-1000;
}
while(input/D>=1){
    outputString = outputString + "D";
    input = input-500;
}
while(input/C>=1){
    outputString = outputString + "C";
    input = input-100;
}
while(input/L>=1){
    outputString = outputString + "L";
    input = input-50;
}
while(input/X>=1){
    outputString = outputString + "X";
    input = input-10;
}
while(input/V>=1){
    outputString = outputString + "V";
    input = input-5;
}
while(input/I>=1){
    outputString = outputString + "I";
    input = input-1;
}

cout<<inputCopy<< " is " << outputString <<endl;
}
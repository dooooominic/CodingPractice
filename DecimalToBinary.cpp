#include<iostream>
#include<string>
using namespace std;

int main(){

int input;
string binaryString = "";

cout<<"Enter a number in decimal representation: " <<endl;
cin >>input;

while (input >0){
    int remainder = input %2; //algorithm from week 1 on converting binary! 
    binaryString = to_string(remainder) + binaryString;
    input = input/2; //input/=2; 
}
cout << binaryString;

return 0;
}

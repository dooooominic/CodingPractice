#include<iostream>
#include<cmath>
using namespace std;

//HW4 Question 4

int main(){
cout<<"Sectio 1: " <<endl;
int length;
double curr, product, power, geometricMean;

product = 1.0;
cout<<"Please enter the length of the sequence: " <<endl;
cin>> length;

cout<<"Please enter your sequence: "<<endl;

for (int i=1; i<=length;i++){
    cin>> curr;
    product= product* curr;
}

power = 1.0/length; //setting the n-th root power to 1.0/length to get a type double result
geometricMean = pow(product, power);
cout<<"The geometric mean is: " << geometricMean <<endl;


cout <<"Section 2: " <<endl;
cout<< "Please enter a non-empty sequence of positive integers, each one in a separate line. End your"; 
cout << "sequence by typing -1: " <<endl;

product = 1.0; //reset variable!!
bool seenEndOfSequence = false;
int counter =0;

while (seenEndOfSequence == false){
    cin>> curr;
    if(curr == -1){
        seenEndOfSequence = true;
        break;
    }
    else{
        product = product*curr;
        counter +=1;
    }
}
power = 1.0/counter;
geometricMean = pow(product, power);
cout<< "The geometric mean is: "<< geometricMean <<endl;

return 0;
}


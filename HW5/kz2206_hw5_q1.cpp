#include<iostream>
using namespace std;

//HW5 Question 1

int main(){

int input;
cout<< "Please enter a positive integer: "<<endl;
cin>> input;

    for(int i=1;i<=input;i++){
        for(int j=1; j<=input;j++){
            cout<<i*j << "\t" ;
        }
        cout<< endl;
    }



}
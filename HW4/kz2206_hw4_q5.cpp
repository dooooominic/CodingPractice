#include<iostream>
using namespace std;
//HW4 Question 5

int main(){

int input;

cout<<"Please input a positive integer: " <<endl;
cin >>input;

for(int n=input; n>=1;n--){ //vertical traversal
    for(int l=1;l<=input-n;l++){ //drawing spaces before asterisks.
            cout<<" ";
        }
    for(int m=1; m<=2*n-1;m++){ //horizontal traversal and drawing
        cout<<"*";
    }
    cout<<endl;
}

//for the second/bottom half: 

for(int a=1;a<=input;a++){ //vertical traversal
    for(int c=input-a; c>=1;c--){ //drawing spaces before asterisks.
            cout<<" ";
        }
    for(int b=1; b<=2*a-1;b++){ //horizontal traversal and drawing
        cout<<"*";
    }
    cout<<endl;
}

}
#include<iostream>
using namespace std;

int main(){
int input;
cout<< "Enter a positive integer: " <<endl;
cin>> input;

char currChar = 'a';
char out = currChar;

    for(int i=1;i<=input;i++){ //top half
        for (int k=input-i; k>=1;k--) //blanks in beginning
            cout<<" ";

        cout<<currChar; //print out first instance of the letter
        if(i>1){ //spaces in between two letters
            for(int a=1; a<=2*i-3;a++){
                cout<<" ";
            }
        cout<<currChar; //print out second instance of the letter
        }
        currChar = currChar+1; //increment for next cycle
        cout<<endl;
        }

//bottom half:
currChar =currChar-2; //reset to second to last char to print. since last char does not repeat. 
    for(int a=input-1;a>=1;a--){
        for(int b=input-1;b>=a;b--){
            cout<<" ";
        }
    cout<<currChar;
    if (a>1){
        for(int c=1;c<=2*a-3;c++){
            cout<<" ";
        }
    cout<< currChar;
    }
    currChar = currChar-1;
    cout<<endl;    
    }
    

}


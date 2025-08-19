#include<iostream>
#include<cmath>

void printDivisors(int num);
/*This function takes an integer input, and prints all of its divisors in ascending order. 
Runs on Theta(sqrt(n)) time for each for loop, which in total runs in theta(2*sqrt(n)) time, which is still theta(sqrt(n)) time!
*/

int main(){
    using namespace std;
    int input;
    cout<< "Please enter a positive integer >=2: ";
    cin>> input;
    printDivisors(input);

}

void printDivisors(int num){
    using namespace std;
    for(int i=1; i<=sqrt(num);i++){
        if(num%i==0){
            cout<< i<<" ";
        }
    }

    for(int i=sqrt(num);i>=1;i--){ 
        if(i !=sqrt(num) && num%i==0){
            cout<< num/i << " ";
        }
    }

}
#include<iostream>
#include<cmath>
using namespace std;

bool palindrome(int n); //theta(log n) time! Depending on the number of digits of the input!

int main(){
    int input;
    cout<< "Enter a positive integer: " <<endl;
    cin >> input;
    cout<< palindrome(input);

}


bool palindrome(int n){
    int originalNum = n;
    int rev = 0;

    while(n>0){
        rev = rev*10 + (n%10);
        n = n/10;
    }

    return(originalNum==rev);
        
}
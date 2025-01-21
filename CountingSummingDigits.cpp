#include<iostream>
using namespace std;

int main(){
    int num, num1;
    int countDigits,sumDigits,currDigit;

    cout<< "Please enter a number: "<<endl;
    cin >> num;

    num1=num;
    countDigits = 0;
    sumDigits = 0;

    while (num>0){
        currDigit = num%10;
        countDigits++;
        sumDigits += currDigit;
        num = num/10;
    }
    cout << num1 << " has " << countDigits <<" digits, and their sum is " << sumDigits <<endl;

return 0;

}
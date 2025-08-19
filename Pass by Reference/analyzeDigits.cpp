#include<iostream>
using namespace std;

int analyzeDigits(int num, int&outSumDigs);

int main(){
    int num;
    int countDigs, sumDigs;
    cout<<"Please enter a positive integer: " <<endl;
    cin >> num;

    countDigs = analyzeDigits(num, sumDigs);
    cout<< num << " has " << countDigs <<" digits, and their sum is " << sumDigs <<endl;


}

int analyzeDigits(int num, int&outSumDigs){
    int count, sum;
    count = 0;
    sum = 0;
    while (num>0){
        sum += num%10;
        count++;
        num = num/10;
    }

    outSumDigs = sum;
    return count;
}
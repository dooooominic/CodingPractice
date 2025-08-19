#include<iostream>
#include<cmath>
using namespace std;

void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs); 
/*
Analyzes the divisors of the input integer, and updates two output parameters that are the number of the number's proper
divisors and the sum of those proper divisors. 
*/
bool isPerfect(int num); //Checks if the input integer is a perfect number. Returns true if the input is a perfect number. 

int main(){ 
/*
Interacts with the user, takes in an input of a positive integer and prints all perfect numbers between 2 and the input,
as well as all pairs of amicable numbers between 2 and the input. 
*/

int countDivs =0;
int sumDivs = 0;
int input;

cout<< "Please enter a positive integer >=2: " <<endl;
cin >> input;

cout<< "The perfect number between 2 and your number are: " <<endl;
for(int i=2; i<=input; i++){
    if(isPerfect(i)){
        cout<< i << endl;
    }
}
cout<< "The pairs of amicable numbers between 2 and your number are: " <<endl;
for(int i=2; i<=input; i++){
    if(isPerfect(i)==false){
        analyzeDivisors(i,countDivs,sumDivs);
        int sum = sumDivs;
    if(sum>i && sum <=input) //get rid of duplicate pairs of amicable numbers (220-284, 284-220)
        analyzeDivisors(sumDivs,countDivs,sumDivs);
        if(i == sumDivs){
            cout << i << " and " << sum << endl;
        }
    }
}

}

void analyzeDivisors(int num, int &outCountDivs, int &outSumDivs){
    int countDivs, sumDivs;
    countDivs = 0;
    sumDivs = 0;
    for(int i=1; i<=sqrt(num);i++){
        if(num%i==0){
            countDivs ++;
            sumDivs += i;

        }
    }
    for(int i=sqrt(num);i>1;i--){
        if((num%i==0)&&(i!=sqrt(num))){
            countDivs++;
            sumDivs += (num/i);
        }
    }
    outCountDivs = countDivs;
    outSumDivs = sumDivs;
}

bool isPerfect(int num){
    int countDivs, sumDivs;
    analyzeDivisors(num, countDivs, sumDivs);
    if(num == sumDivs){
        return true;
    }
    else{
        return false;
    }
}
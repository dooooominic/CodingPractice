#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int num);

int main(){

    int input;
    cout<<"Please enter a positive integer to be tested for prime: " <<endl;
    cin >> input;

    cout<< isPrime(input) <<endl;

}



bool isPrime(int num){
    int countDivs = 0;
    for(int i=1; i<=sqrt(num);i++){
        if(num%i==0){
            countDivs++;
        }
    }

    if(countDivs==1){
        return true;
    }
    else{
        return false;
    }


}
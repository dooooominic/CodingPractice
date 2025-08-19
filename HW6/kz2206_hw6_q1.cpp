#include<iostream>

int fib(int n); //takes an input of integer n and returns the n'th number in the Fibonacci sequence. 

int main(){
    using namespace std;

    int input; 
    cout << "Please enter a positive integer: "; 
    cin >> input; 
    cout<< fib(input)<<endl;
}



int fib(int n){
    int fib_n, fib_n_1, fib_next;
    fib_n_1 = 1; //first and second term of the series are both 1. 
    fib_n = 1;
    fib_next = 0; //initializing to 0 before use

    if (n ==1 || n ==2){
        return fib_n;
    }
    else{
        for(int i =3; i<=n; i++){
        fib_next = fib_n_1+fib_n;
        fib_n_1= fib_n;
        fib_n = fib_next;
    }
        return fib_next;

    }

}
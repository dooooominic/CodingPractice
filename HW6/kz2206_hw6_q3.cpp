#include<iostream>

double factorial(int num); //This function computes the factorial of the number num;

double eApprox(int n);
/*
This function is given a positive integer n, and returns an approximation of e, calculated by the
sum of the first (n+1) addends of the infinite sum above. Theta(n) time complexity. 
*/

int main(){
/*Main written to print out the estimation of euler's number using a range of 1 to 15 terms in the infinite series*/
    using namespace std;
    cout.precision(30);

    for(int n=1; n<=15; n++){
        cout<<"n = " <<n << '\t' <<eApprox(n)<<endl;
    }

}

double eApprox(int n){
    using namespace std;
    double sum = 1.0;
    for(int i=1; i<=n;i++){
        sum = sum+ 1.0/factorial(i);
    }

return sum;
}

double factorial(int num){ //factorial function from Module 8 video, changed to double 
    using namespace std;
    double factRes=1.0;
    for (int i=1; i<=num;i++){
        factRes *=i;
    }
    return factRes;
}
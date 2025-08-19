#include<iostream>
using namespace std;

int factorial(int num);
int kCombination(int n, int k);

int main(){
    int n, k;
    int k_comb;
    cout<<"Please enter non-zero integers n and k (n >=k):" <<endl;
    cin>> n>>k;

    k_comb = kCombination(n,k);

    cout<<n <<" choose " << k << " is " << k_comb<<endl;

return 0;
}

int factorial(int num){ //first function!!! Yay!!!
    int factRes=1;
    for (int i=1; i<=num;i++){
        factRes *=i;
    }
    return factRes;
}

int kCombination(int n, int k){
    int nFact, kFact, n_kFact;
    nFact = factorial(n);
    kFact = factorial(k);
    n_kFact = factorial(n-k);

    return (nFact/(kFact*n_kFact));
    
}
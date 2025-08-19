#include<iostream>
using namespace std;

long long factorial(int n);
long long permutation(int n, int k);
long long combination(int n, int r);


int main(){

char input;
    cout<< "Permutation or Combination? Please enter P or C: ";
    cin >> input;

    if(input == 'P' || input =='p'){
        int n, k;
        cout<< "Please enter values for n and k: " <<endl;
        cin>> n >> k;
        cout <<"P("<< n<<","<<k<<") = " <<permutation(n,k)<<endl;
    return 0;
    }
    else if(input == 'C' || input == 'c'){
        int n, r;
        cout<<"Please enter values for n and r: " <<endl;
        cin >> n >> r;
        cout <<"C("<< n<<","<<r<<") = " <<combination(n,r)<<endl;
    return 0;
    }
    else{
        cout<< "Invalid input. Please try again. The program will terminate now."<<endl;
    return 0;
    }
}


long long permutation(int n, int k){
    int permRes = 0;
    permRes = factorial(n)/(factorial(n-k)); //why do they only work sometimes???
return permRes;
}

long long combination(int n, int r){
    int combRes;
    int denom = factorial(r)*factorial(n-r);
    combRes = factorial(n)/denom;
return combRes;
}

long long factorial(int n){
    int factRes = 1;
    for (int i=1; i<=n; i++){
        factRes *=i;
    }

return factRes;
}
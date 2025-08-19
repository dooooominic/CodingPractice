#include<iostream>
using namespace std;

int main(){

int n;
cout<<"Enter a positive integer: " <<endl;
cin>> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
        cout<<" ";
    }
        cout<<"/";
        for(int j=1; j<=i;j++){
      if(i<n){
        cout<<" ";
      }
    else{
      cout<<"_";
    }
      cout<< "|" <<endl;
        }
    }
}
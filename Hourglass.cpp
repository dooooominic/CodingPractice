#include<iostream>
using namespace std;

int main(){
int input;

cout<< "Please enter a positive integer: "<<endl;
cin >>input;

for(int n=input; n>=1;n--){
    for(int m=0; m<input-n;m++){
        cout<<" ";
    }
    for(int l=1;l<=2*n-1;l++){
        cout<< "*";
    }
    cout<<endl;
}

for(int a=2; a<=input;a++){
    for(int b=1; b<=input-a;b++){
        cout<<" ";
    }
    for(int c=1; c<=2*a-1;c++){
        cout<<"*";
    }
    cout<<endl;
}


}
#include<iostream>
using namespace std;

int main(){
    int input;
    cout<<"Please enter a positive integer: "<<endl;
    cin>> input;

    // for(int i=1;i<=2*input;i++){
    //     for(int j=1;j<=2*input;j++){
    //         if (i+j>=2*input+1){
    //             cout<<"*";
    //         }
    //         else
    //             cout<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=2*input;i++){
        for(int j=1;j<=2*input-i;j++){
            cout<<" ";
        }
        for(int j=1; j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

}
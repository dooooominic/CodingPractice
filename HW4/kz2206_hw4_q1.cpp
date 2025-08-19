#include<iostream>
using namespace std;

int main(){

int input, testVariable;

cout<<"Section 1"<<endl;

cout<<"Please enter a positive integer: " <<endl;
cin >> input;

testVariable =1;

while(testVariable<=input){
    cout<<testVariable*2<<endl;
    testVariable++;
}

cout<<"Section 2" <<endl;

cout<<"Please enter a positive integer: " <<endl;
cin >> input;

for(int i=1;i<=input;i++){
    cout<<i*2<<endl;
}

}


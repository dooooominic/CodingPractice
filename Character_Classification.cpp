#include<iostream>
using namespace std;

int main(){
char userInput;

cout<<"Please input a character: " <<endl;
cin >> userInput;

if(userInput>= 'a' && userInput <='z')
    cout << userInput << " is a lower case letter." <<endl;
else if(userInput >= 'A' && userInput<='Z')
    cout<< userInput << " is an upper case letter." <<endl;
else if(userInput >= '0' && userInput <= '9')
    cout<<userInput << " is a digit. " <<endl;
else
    cout <<userInput << " is a non alpha-numeric character. " << endl;

return 0;
}
#include <iostream>
using namespace std;

int main(){
char lowerCaseLetter, upperCaseLetter;
int offset;

cout <<"Please input your lower case letter: " <<endl;
cin >> lowerCaseLetter;

offset = (int)(lowerCaseLetter - 'a'); //Casting into int for offset
upperCaseLetter = (char)('A' + offset); //Casting into char for the letter output

cout <<"The upper case letter of " <<lowerCaseLetter << " is " << upperCaseLetter << endl;

return 0;

}
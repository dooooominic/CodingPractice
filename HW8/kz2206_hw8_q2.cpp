#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str);
//Returns true if the input string is a palindromic word, and false if not. 

int main(){

string word;
cout<<"Please enter a word: ";
cin>> word;
if(isPalindrome(word))
    cout<< word <<" is a palindrome.";
else{
    cout<< word <<" is not a palindrome.";
}

return 0;
}

bool isPalindrome(string str){
    int length = str.length();
    for(int i=0; i<length/2;i++){
        if(str[i]!=str[length-1-i]){ //can access string by index
            return false;
        }
    }
    return true;
}
#include<iostream>
#include<string>
using namespace std;

void replaceNums(string &str, int length);

bool isNumber(char character);

bool isSpace(char character);

int main(){

string sentence;
int sentenceLength;
cout<<"Please enter a line of text: " <<endl;
getline(cin,sentence);

sentenceLength = sentence.length();

replaceNums(sentence, sentenceLength);

cout<< sentence;

}

void replaceNums(string &str, int length){
    string copy = str;
    for(int i=0; i<length; i++){
        if(isNumber(str[i])){
            int a = i-1;
            int b = i+1;
            while(isNumber(str[a])){
                a--;
            }
            while(isNumber(str[b])){
                b++;
            }
            if(isSpace(str[a]) && isSpace(str[b])){
                copy[i]= 'x';
            } 
        }
    }
    str = copy;
}

bool isNumber(char character){
    if (character>='0' && character<='9'){
        return true;
    }
    else{
        return false;
    }
}


bool isSpace(char character){
    if(character == ' '){
        return true;
    }
    else{
        return false;
    }
}

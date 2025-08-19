#include<iostream>
#include<string>

using namespace std;

void wordCount(string sentence);
void letterCount(string sentence);


int main(){ //Theta(n)

     cout<<"Please enter a line of text: " <<endl;
     string sentence; 
     getline(cin, sentence);
     wordCount(sentence); //Theta(n)
     letterCount(sentence); //Theta(n)

}

void wordCount(string sentence){
    int length = sentence.length();
    int wordCount=0;
    for(int i=0; i<length; i++){
        if(sentence[i] ==' '||sentence[i]==',' || sentence[i]=='.'){
            wordCount++;
        }
    }

    cout<< wordCount << "\t words." <<endl;

}

void letterCount(string sentence){ //use array with all letters?
    int length = sentence.length();

    int arr[26];
    for(int i=0; i<26; i++){ //Theta(1)
        arr[i]=0;
    }
    
    for(int i=0; i<length;i++){ //Theta(n)
        char currentChar = sentence[i];
        if(currentChar>='a' && currentChar<='z'){
            arr[sentence[i]-97]++;
        }
        else if(currentChar>='A' && currentChar<='Z'){
            arr[sentence[i]-65]++;
        }
    }
    
    for(int i=0;i<26;i++){
        if(arr[i]!=0){
            cout<<arr[i]<< "\t " << (char)(i+97)<< endl;
        }
    }
}
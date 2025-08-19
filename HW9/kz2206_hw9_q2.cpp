#include<iostream>
#include<string>

using namespace std;

bool letterCount(string sentence1, string sentence2);
/*
This function takes two input strings, and checks if they are anagrams of each other or not. Must be compiled every time to reset arrays. 
*/

int main(){

    string sentence1, sentence2;
    cout<<"Please enter your first sentence: "<<endl;
    getline(cin, sentence1);

    cout<<"Please enter your second sentence: " <<endl;
    getline(cin, sentence2); 
    
    cout<< letterCount(sentence1,sentence2); //Theta(3n) = Theta(n)

    
}

bool letterCount(string sentence1, string sentence2){ 
    int length1 = sentence1.length();
    int length2 = sentence2.length();

    int arr1[26], arr2[26],zeroArray[26];
    for(int i=0; i<26; i++){ //Theta(1)
        arr1[i]=0;
        arr2[i]=0;
        zeroArray[i]=0; //an array where every entree is 0. 
    }
    
    for(int i=0; i<length1;i++){ //Theta(n)
        char currentChar = sentence1[i];
        if(currentChar>='a' && currentChar<='z'){
            arr1[sentence1[i]-97]++;
        }
        else if(currentChar>='A' && currentChar<='Z'){
            arr1[sentence1[i]-65]++;
        }
    }

    for(int i=0; i<length2;i++){ //Theta(n)
        char currentChar = sentence2[i];
        if(currentChar>='a' && currentChar<='z'){
            arr2[sentence2[i]-97]++;
        }
        else if(currentChar>='A' && currentChar<='Z'){
            arr2[sentence2[i]-65]++;
        }
    }
    
   for(int i=0; i<26; i++){ //Theta(1)
        if(arr1[i]-arr2[i]!= zeroArray[i]){
            return false;
        }
   }

    return true;


return 0;
}
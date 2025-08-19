#include<iostream>
#include<string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize); 
/*This function gets a string sentence containing a sentence.
When called, it creates and returns a new array (of strings), that contains all the
words in sentence. The function also updates the output parameter,
outWordsArrSize, with the logical size of the new array that was created.*/

int main(){

    
     
    string sentence = "You can do it";
    int size;
    string* words = createWordsArray(sentence, size);
    
    for(int i=0; i<size; i++){
        cout<< words[i] << " ";
    }
    cout<<endl;
    cout<< "The size is: " << size <<endl;

    delete[] words;
    words = nullptr;

return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){
    outWordsArrSize = 0;
    for(int i=0; i<sentence.length(); i++){ //Theta(n)
        if(sentence[i]==' '){
            outWordsArrSize++;
        } 
    }
    outWordsArrSize++; //Add one more for the end of the sentence. Since no punctuation besides spaces in the middle of sentences.

    string* outWords = new string[outWordsArrSize]; //Creating a dynamic string array on the heap. 

    int j=0;
    int startingIndex = 0;
    for(int i=startingIndex; i<sentence.length();i++){
        int spaceIndex = sentence.find(' ', startingIndex); 

        if (spaceIndex == -1) { // If no more spaces found, extract the last word
            outWords[j] = sentence.substr(startingIndex);
            break; //end at last word of sentence
        }

        outWords[j]=sentence.substr(startingIndex, spaceIndex-startingIndex);
        startingIndex = spaceIndex+1;
        j++;
    }

return outWords;
}
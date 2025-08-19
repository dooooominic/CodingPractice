#include<iostream>
#include<fstream>
#include<stack>
#include<string>

using namespace std;

void openInputFile(ifstream& inFile);
bool symbolBalanceCheck(ifstream& inFile);


int main(){

ifstream inFile;
openInputFile(inFile);
cout<<symbolBalanceCheck(inFile);

}

void openInputFile(ifstream& inFile){
    string filename;
    cout<<"What's the file name?"<<endl;
    cin>> filename;
    inFile.open(filename);
    while(!inFile){
        cout<<"Invalid file name!"<<endl;
        cout<<"What's the file name?"<<endl;
        cin>>filename;
        inFile.clear(); //remember to call clear to get rid of error flag
        inFile.open(filename);
    }

}

bool symbolBalanceCheck(ifstream& inFile){
    stack<char> tracker;
    char temp;
    string checker;
    inFile>>checker;
    if(checker != "begin"){
        cout<<"Missing 'begin' keyword. Error!"<<endl;
    return false;
    }

    while(inFile>>temp){
        if(temp == '('||temp == '{'||temp == '['){
            tracker.push(temp);
            continue;
        }
        else if(temp == ')'){
            char copy;
            copy = tracker.top();
            tracker.pop();
            if(copy=='('){
                continue;
            }
            else{
                return false;
            }
        }
        else if(temp == ']'){
            char copy;
            copy = tracker.top();
            tracker.pop();
            if(copy=='['){
                continue;
            }
            else{
                return false;
            }
        }
        else if(temp == '}'){
            char copy;
            copy = tracker.top();
            tracker.pop();
            if(copy=='{'){
                continue;
            }
            else{
                return false;
            }
        }
        else{
            continue;
        }
    }
    
    //checking for the "end" word 
    inFile.clear(); //clear end of file flag and reread through the file to make sure end is there...
    inFile.seekg(0);
    string curr;
    string lastWord;
    while(inFile>>curr){
        lastWord = curr;
    }
    if(lastWord!="end"){
        cout<<"Missing the final 'end' word!"<<endl;
        return false;
    }
    else{
        if(tracker.empty()){
            return true;
        }
        else{
            return false;
        }
    }
}

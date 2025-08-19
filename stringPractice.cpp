#include<iostream>
#include<string>
using namespace std;

int main(){
    // string userName;
    // string reversedName;

    // cout<<"Please enter your name: " <<endl;
    // getline(cin, userName);

    // for(int ind = userName.length()-1; ind>=0; ind--){
    //     reversedName += userName[ind]; //can just add onto the reversed string that's empty!! 
    //     //or: just do cout<< userName[ind];
    // }
    // cout<< reversedName;
    // cout<<endl;

    string sentence;
    cout<<"Please enter a sentence: " <<endl;
    getline(cin,sentence);
    cout<< "Your sentence is: " << sentence <<endl;
    cout<< "It has " <<sentence.length() << " characters." << endl;


return 0;
}
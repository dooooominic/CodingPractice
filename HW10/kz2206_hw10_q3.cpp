#include<iostream>
#include<vector>

using namespace std;

void main1(); //dynamic heap array implementation. Interacts with user, gets inputs, and returns the lines where the input appears. 
void main2(); //vector implementation of the same program in main1(), using vector rather than a dynamic array on the heap. 
void getNums(vector<int> &entries); // Function used in main2() to interact with user. 




int main(){
    //main1(); //Call main1() to test function implemented without vectors, using doubling strategy to keep track an array on the heap

    main2(); //Call main2() to test function implemented with vector. 

return 0;
}


void main1(){ //no vector

    int input =0;
    int searchTarget =0;
    int actualSize = 1;
    int* entries = new int[actualSize];
    int index = 0;


    cout<< "Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<< "End your input by typing -1."<<endl;
    cin>>input;

    while(input!= -1){ //Theta(n)*
        if(index== actualSize){
            int* newArr = new int [actualSize*2];
            for(int i=0; i<actualSize;i++){
                newArr[i] = entries[i];
            }
            actualSize *=2;
            delete[] entries;
            entries = newArr;
        }
        
        entries[index] = input;
        index++;
        cin>>input;
    }

    cout<<"Please enter a number you want to search." <<endl;
    cin>> searchTarget;

    cout<< searchTarget << " shows in lines ";

    bool comma = false;
    bool found = false;
    for(int i=0; i<index; i++){ //Theta(n)
        if(entries[i]== searchTarget){
            if(comma == true){
                cout<<",";
            }
            cout<< i+1;
            comma = true;
            found = true;
        }
    }
    if(!found){
        cout<< "ERROR! Your target number is not found";
    }
    cout<<"."<<endl;

    delete[] entries;
    entries = nullptr;
}

void main2(){ //vector
    int target;
    vector<int> entries;
    getNums(entries);

    cout<<"Please enter a number you want to search." <<endl;
    cin>> target;

    cout<< target << " shows in lines ";

    bool comma = false;
    bool found = false;
    for(int i=0; i<entries.size();i++){
        if(entries[i]==target){
            if(comma == true){
                cout<< ",";
            }
            cout<< i+1;
            comma = true;
            found = true;
        }
    }
    if(!found){
        cout<<"ERROR! Your target number is not found";
    }
    cout<< "." <<endl;

}

void getNums(vector<int> &entries){ //Theta(n)*
    //vector<int> entries;
    int input;
    cout<< "Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<< "End your input by typing -1."<<endl;
    cin>> input;

    while(input!= -1){
        entries.push_back(input); //Basically the same as part a
        cin>> input;
    }
}
#include<iostream>
using namespace std;

// int main(){

// int input;
// cout<<"Please enter a positive integer: "<<endl;
// cin >> input;

// for(int i=1;i<=input;i++){
//     cout<<"#";
// }
// cout<<endl;

// for(int i=1;i<=input/2;i++){
//     cout<<"#"; //initial # for left border //why doesn't this iterate input-many times?? I think I know now...
//     for(int j=1; j<=i;j++){
//         cout<<" ";
//     }
//     cout<<"$";
//     for(int j=1;j<=input-2-2*(i-1);j++){
//         cout<<" ";
//     }
//     cout<<"$";
//     for(int j=1; j<=i;j++){
//         cout<<" ";
//     }
//     cout<<"#";
//     cout<<endl;
// }

// for(int i=input/2;i>=1;i--){
//     cout<<"#";
//     for(int j=1; j<=i;j++){
//         cout<<" ";
//     }
//     cout<<"$";
//     for(int j=1; j<=input-2-2*(i-1);j++){
//         cout<<" ";
//     }
//     cout<<"$";
//     for(int j=1; j<=i;j++){
//         cout<<" ";
//     }
//     cout<<"#";
//     cout<<endl;
// }

// for(int i=1;i<=input;i++){
//     cout<<"#";
// }

// }

int main(){
    int input;
    char frame = '#';
    char planks = '$';
    char space = ' ';

    cout<<"Enter positive integer: "<<endl;
    cin>>input;

    for (int i=0;i<input;i++){
        for(int j=0;j<input;j++){
            if(j==0||j==input-1||i==0||i==input-1){ //this is what my brain wanted to do!!!!
                cout<<frame;
            }
            else if(i==j||i+j==input-1){
                cout<<planks;
            }
            else{
                cout<<space;
            }
        }
        cout<<endl;
    }
    
}
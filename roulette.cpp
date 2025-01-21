#include<iostream>
using namespace std;

int main(){
    int pocketNumber;

    cout<<"Enter a pocket number: " <<endl;
    cin >> pocketNumber;


    
    if (pocketNumber ==0){
        cout<<"Green" <<endl;
    }
    else if ((pocketNumber >=1 && pocketNumber<=10 )|| (pocketNumber >=19 && pocketNumber<=28)){
        if (pocketNumber%2 ==0){
            cout << "Black" <<endl;
        }
        else{
            cout <<"Red" <<endl;
        }
    }
    
    else if ((pocketNumber>=11 && pocketNumber <=18)||(pocketNumber>=29 && pocketNumber<=36)){
        if (pocketNumber%2 ==0){
            cout << "Red" <<endl;
        }
        else{
            cout <<"Black" <<endl;
        }
    }
    else{
        cout <<"Error. Your pocket number is invalid. Please try again." <<endl;
    }

    return 0;

}
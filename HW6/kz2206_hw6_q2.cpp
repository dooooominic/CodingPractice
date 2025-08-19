#include<iostream>

void printShiftedTriangle(int n, int m, char symbol); 
/*
Takes input of integer n and m, and a character symbol. 
Prints an n-line triangle with the symbol character, shifted m spaces from the left on the bottommost line.  
Each line has (2*line number -1) number of symbol characters. 
*/

void printPineTree(int n, char symbol);
/*
Takes input of integer n and a character symbol. 
Prints a pine tree that calls the printShiftedTriangle function and prints n number of triangles with increasing sizes. 
*/


int main(){
    using namespace std;
    int num; 
    char symbol;
    cout<< "Please enter the number of triangles in the tree: ";
    cin>> num;
    cout<< "Please enter the character you want to use to fill the tree (e.g. +): ";
    cin >> symbol;
    printPineTree(num,symbol);

return 0;
}

void printShiftedTriangle(int n, int m, char symbol){
    using namespace std;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=n+m-i;j++){
            cout<< " ";
        }
        for(int j=1; j<=2*i-1;j++){
            cout<< symbol; 
        }
        cout<<endl;
    }
}

void printPineTree(int n, char symbol){
    using namespace std;

    for(int i=2; i<=2+n-1;i++){
        printShiftedTriangle(i,n-i+1, symbol);
        //cout<<endl;
    }
        
}
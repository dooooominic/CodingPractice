#include<iostream>

using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main(){
    int input;
    cout<< "Enter a number n to print the triangle or ruler:" <<endl;
    cin>> input;
    //printOppositeTriangles(input);
    printRuler(input);


}

void printTriangle(int n){
    if(n==0){
        return;
    }
    else{
        printTriangle(n-1); //Prints the smaller triangle
        for(int i=1; i<=n;i++){ //Prints the final line of n asterisks. 
            cout<<"*";
        }
        cout<<endl;
}
}

void printOppositeTriangles(int n){
    if(n==0){
        return;
    }
    else{
        for(int i=1; i<=n;i++){
            cout<<"*";
        }
        cout<<endl;

        printOppositeTriangles(n-1);

        for(int i=1; i<=n;i++){
            cout<<"*";
        }
        cout<<endl;

    }
}

void printRuler(int n){
    if(n==0){ //can do 0 because 1 is covered in else!
        return;
    }
    else{

        printRuler(n-1);

        for(int i=1;i<=n;i++){ //draw this out!!!!!!!!!!!!
            cout<<"-";
        }
        cout<<endl;

        printRuler(n-1);
    
    }



}
#include<iostream>
using namespace std;

void swap(int &a, int &b); //function with pass by refenrece!!!
void get_numbers(int &a, int&b);

int main(){

    int a,b;
    get_numbers(a,b);

    cout << "a = " <<a << " and b = " << b <<endl;

    swap(a,b);

    cout << "After swap, a = " <<a << " and b = " << b <<endl;


}

void swap (int &a, int &b){ //We need to pass by REFERENCE to gain access to variables outside of the function frame, and to 
                            // affect the main frame so we can swap a and b in the main frame! Using pointers! int &a,etc. !
    int temp;
    temp = a;
    a = b;
    b = temp;

}


void get_numbers(int &a, int&b){
    cout<< "blah";
    cin >> a >> b;

}
#include<iostream>
#include<vector>
using namespace std;

void resizeArray(int* &arr, int currentSize, int newSize);

int main(){
    // int x = 100;
    // int* ptr = &x; //creating an integer pointer variable, int*, that is set to the memory address of x, which is &x. 
    // cout<< *ptr <<endl; //we can print out the value of x by printing *ptr, which dereferences the pointer variable and accesses
    //                     // the variable at the memory address of which it is pointing to. 

    // *ptr = 200;         // We can change the variable at the memory address at which ptr is pointing to, by dereferencing it
    //                     // *ptr =200; is directly changing the value of x to 200. 

    // cout<< "Now, the value of x is : " << *ptr;





    //-------------------------------------------------------------------------------------
    // vector<int> v; //heap dyanmic array. but can just use vector<data_type> name; 
    // for(int i=0; i<100; i++){
    //     v.push_back(i*100); //push_back() adds elements
    // }

    // // for(int i=0; i<v.size();i++){
    // //     cout<< v[i]<<endl; 

    // //or: the ranged for loop for output:

    // for(int i:v){ //traversing through the entire range of v, and i represents v[0], v[1], v[2], etc.
    //     cout<< i <<endl;
    // }
    




    //-------------------------------------------------------------------------------------
    //implementing heap dynamic array and resizing: 

    int size = 10;
    int* arr = new int[size];
    for(int i=0; i<size; i++){
        arr[i] = i*2;
    }

    int newSize = 20;
    resizeArray(arr, size, newSize);
    arr[15] = 20;
    for(int i=0; i<newSize;i++){
        cout<<arr[i]<<endl;
    }


}

void resizeArray(int* &arr, int currentSize, int newSize){
    int* temp = new int[newSize];
    for(int i=0; i<currentSize; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}


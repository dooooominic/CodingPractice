#include<iostream>
using namespace std;

int search(int arr[], int logical_size, int x);
int main(){

int data[5]={10,5,7,6,2};
cout<< search(data,5,15);



}

int search(int arr[], int logical_size, int x){
    for(int i=0; i<logical_size;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
    
    }


#include<iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
//Takes an input intger array and its size, then reverses the array in O(n) time. 

void printArray(int arr[], int arrSize);
//Prints the input integer array.

void removeOdd(int arr[], int& arrSize);
//Goes through the array, removing all the odd elements, and updating the size of the array after each removal.

void splitParity(int arr[], int arrSize);
//Moves all the odd elements to the first/left half of the array, and all the even elements to the second/right half.

int main(){

int arr1[10] = {9, 2, 14, 12, -3};
 int arr1Size = 5;

 int arr2[10] = {21, 12, 6, 7, 14};
 int arr2Size = 5;

 int arr3[10] = {3, 6, 4, 1, 12};
 int arr3Size = 5;

 reverseArray(arr1, arr1Size);
 printArray(arr1, arr1Size);

 removeOdd(arr2, arr2Size);
 printArray(arr2, arr2Size);

 splitParity(arr3, arr3Size);
 printArray(arr3, arr3Size);

 return 0;
}

void reverseArray(int arr[], int arrSize){
    int temp =0;
    for(int i=0;i<arrSize/2;i++){
        temp = arr[i];
        arr[i]=arr[arrSize-i-1];
        arr[arrSize-i-1] = temp;
    }
}

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++) {
    cout<<arr[i]<<' ';
 }
    cout<<endl;
}


void removeOdd(int arr[], int& arrSize){
    int index =0;
    for(int i=0; i<arrSize; i++){
        if(arr[i]%2==0){
            arr[index] = arr[i];
            index++;
        }
    }
    arrSize = arrSize-index+1;
}

void splitParity(int arr[], int arrSize){
    int frontIndex=0;
    int backIndex = arrSize-1;

    while(frontIndex<backIndex){
        while(arr[frontIndex]%2==1){
            frontIndex++;
        }
        while(arr[backIndex]%2==0){
            backIndex--;
        }
        //swap the two once we found them: 
        int temp = 0;
        temp = arr[frontIndex];
        arr[frontIndex] = arr[backIndex];
        arr[backIndex] = temp;
        
        frontIndex++;
        backIndex--;
    }
    
    }



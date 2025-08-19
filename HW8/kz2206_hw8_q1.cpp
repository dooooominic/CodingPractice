#include<iostream>
using namespace std;

int minInArray(int arr[], int arrSize);
//Finds and returns the minimum element in a given integer array.

void getArray(int arr[], int arrSize);
//Interacts with the user and gets the data to fill in the input array.

void getIndex(int arr[], int arrSize, int value);
//Searches through the array for the input value and prints out the indices where the value is/are.

const int ARRAY_SIZE = 20; //20 integers as stated in the question

int main(){
    int nums[ARRAY_SIZE];
    getArray(nums,ARRAY_SIZE);

    int minValue = minInArray(nums, ARRAY_SIZE);
    cout<< "The minimum value is " << minValue << ", and it is located in the following indices: ";
    getIndex(nums,ARRAY_SIZE,minValue);

}

int minInArray(int arr[], int arrSize){
    int minValue = arr[0];
    for(int i=1; i<arrSize; i++){
        if(arr[i]<minValue){
            minValue = arr[i];
        }
    }
    return minValue;
}

void getArray(int arr[], int arrSize){
    int currValue;
    cout<<"Please enter 20 integers separated by a space: "<<endl;

    for(int i=0; i<arrSize;i++){
        cin>>currValue;
        arr[i] = currValue;
    }

}

void getIndex(int arr[], int arrSize, int value){
    for(int i=0; i<arrSize;i++){
        if(arr[i]== value)
            cout<< i << " ";
    }
}
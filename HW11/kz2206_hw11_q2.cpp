#include<iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(){
    int arr[4] = {2,-1,3,10};
    int arrSize = 4;
    //cout<< sumOfSquares(arr,arrSize);

    int arr2[4] = {1,1,2,3};
    cout<< isSorted(arr2,arrSize);
}

int sumOfSquares(int arr[], int arrSize){
    int sum = 0;
    if(arrSize == 1){
        int temp = arr[0];
        return temp*temp;
    }
    else{
        int temp = arr[arrSize-1];
        sum = sumOfSquares(arr,arrSize-1);
        return (temp*temp+sum);
    }

}

bool isSorted(int arr[], int arrSize){ 

    if(arrSize==1 || arrSize==0){ //make sure we test 1 and 0 for base cases
        return true;
    }
    else{
         
        return (isSorted(arr,arrSize-1)&&(arr[arrSize-2]<=arr[arrSize-1])); //<= for case where we have repeated entries
    }

}
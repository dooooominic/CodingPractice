#include<iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
/*When called, the function reorders the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).*/

int main(){

int arr[] = {5,2, 11, 7, 6,4};
oddsKeepEvensFlip(arr, 6); //size is 6 in this example input array.

for(int i=0; i<6; i++){
    cout<< arr[i] <<" ";
}

return 0;

}

void oddsKeepEvensFlip(int arr[], int arrSize){
    int* organizedArr = new int[arrSize];

    int frontIndex=0, backIndex = arrSize-1;
    for(int i=0; i<arrSize;i++){
        if(arr[i]%2==1){
            organizedArr[frontIndex]=arr[i];
            frontIndex++;
        }
        else if(arr[i]%2==0){
            organizedArr[backIndex] = arr[i];
            backIndex--;
        }
    }

    for(int i=0; i<arrSize;i++){ //Printing out the sorted result: move to main
        arr[i]=organizedArr[i];
    }

    delete[] organizedArr;
    organizedArr = nullptr;
}
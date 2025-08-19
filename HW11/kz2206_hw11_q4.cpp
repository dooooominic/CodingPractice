#include<iostream>

using namespace std;

/* HW11 Q4: Jump It*/

int lowestJumpCost(int arr[], int arrSize);

int main(){

int arr[6]= {0, 3, 80, 6, 57, 10};
int size = 6;

cout<< lowestJumpCost(arr, size);

}

int lowestJumpCost(int arr[], int arrSize){
    if(arrSize ==1){
        return arr[0];
    }
    else if(arrSize ==2){
        return arr[0]+arr[1];
    }
    else{
        int min;
        if (lowestJumpCost(arr, arrSize-1)<= lowestJumpCost(arr,arrSize-2)){
            min = lowestJumpCost(arr,arrSize-1);
        }
        else{
            min = lowestJumpCost(arr,arrSize-2);
        }
        return min+ arr[arrSize-1];
    }

}

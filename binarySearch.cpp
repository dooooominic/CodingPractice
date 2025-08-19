#include<iostream>

using namespace std;

int binarySearch(int arr[], int arrSize, int val);
//Given a sorted array, return the index of the element val we are searching for, or return -1 if it does not exist. 

int main(){

    int array[10] = {0, 1, 4, 6, 7,10, 12, 65, 90, 100};
    cout<< binarySearch(array, 10, 4);
    cout<< binarySearch(array, 10, 65);
    cout<< binarySearch(array, 10, 13);

}


int binarySearch(int arr[], int arrSize, int val){
    int low = 0;
    int high = arrSize-1;
    bool found = false;
    int mid;
    int ind;

    while((found == false) && (low<=high)){ //need the second condition to ensure loop ends if val doesn't exist in array
        mid = (low+high)/2;
        if(arr[mid] == val){
            found = true;
            ind = mid;
        }
        else if(val>arr[mid]){
            low = mid+1;
        }
        else{ //val<arr[mid]
            high = mid-1;
        }
    }
    if (found==true){
        return ind;
    }
    else{
        return -1;
    }

}
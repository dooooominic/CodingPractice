#include<iostream>

using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int lowLeft, int highLeft, int highRight);
int main(){
    int arr[5] = {10, 5, 7, 13, 55};
    mergeSort(arr, 0, 4);
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }

}

void mergeSort(int arr[], int low, int high){
    int mid;
    if(low ==high){
        return;
    }
    else{
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft+1;
    int size = highRight-lowLeft+1;
    int* mergedArr;
    mergedArr = new int[size];
    int iLeft, iRight, iRes; //keeping track of current element in each half
    iLeft = lowLeft;
    iRight = lowRight;
    iRes=0;
    while(iLeft<=highLeft && iRight<=highRight){
        if(arr[iLeft]<arr[iRight]){
            mergedArr[iRes] = arr[iLeft];
            iLeft++;
            iRes++;
        }
        else{
            mergedArr[iRes] = arr[iRight];
            iRight++;
            iRes++;
        }
    }
    while(iLeft<=highLeft){ //add on the rest of the array once the other array is finished. 
        mergedArr[iRes] = arr[iLeft];
        iLeft++;
        iRes++;
    }
    while(iRight<=highRight){
        mergedArr[iRes] = arr[iRight];
        iRight++;
        iRes++;
    }
    int i, iArr;
    for(i=0, iArr=lowLeft; i<size; i++, iArr++){ //write over the original array!
        arr[iArr] = mergedArr[i];
    }

    delete[] mergedArr;

}
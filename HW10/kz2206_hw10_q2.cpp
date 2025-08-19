#include<iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
/*This function gets an array of integers arr and its logical size n. All elements in arr are
in the range {0, 1, 2, … , n}. When called, it creates and return a new array, that contains all the numbers in
range {0, 1, 2, … , n} that are not in arr. The function also updates the output
parameter, resArrSize, with the logical size of the new array that was created.*/

int main(){

int size = 0;
int arr[6] = {3,1,3,0,6,4};

int* missingArr = findMissing(arr, 6, size);

for(int i=0; i<size; i++){
    cout<< missingArr[i] << " ";
}
    cout<< endl;
    cout<< "The size of resArrSize is : " << size << endl;

    delete[] missingArr;
    missingArr = nullptr;

return 0;
}

int* findMissing(int arr[], int n, int& resArrSize){
    int key[n+1];
    resArrSize = 0;

    for(int i=0; i<=n;i++){ //Theta(n): Make every item in key = 0
        key[i]=0;
    }

    for(int i=0; i<n;i++){ //Theta(n): go through the entire array and tally accordingly in key.
        key[arr[i]]++;
    }

    for(int i =0; i<=n; i++){ //Theta(n): go through key and count number of items missing from array
        if(key[i]==0){
            resArrSize++;
        }
    }
    int* outMissing = new int[resArrSize];

    int j=0;
    for(int i=0; i<=n;i++){ //Theta(n): go through key and add every missing number to return array.
        if(key[i]==0){
            outMissing[j] = i;
            j++;
        }
    }

return outMissing;
}
#include<iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
//Part a returns the base address of the array (containing the positive numbers), and updates
//the output parameter outPosArrSize with the array’s logical size.

int* getPosNums2(int* arr, int arrSize, int* outPosArrPtr);
//Part b returns the base address of the array (containing the positive numbers), and uses
//the pointer outPosArrSizePtr to update the array’s logical size.

void getPosNums3(int* arr, int arrSize, int* &outPosArr, int& outPosArrSize);
//Part c updates the output parameter outPosArr with the base address of the array
//(containing the positive numbers), and the output parameter outPosArrSize with
//the array’s logical size.

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
//Part d uses the pointer outPosArrPtr to update the base address of the array (containing
//the positive numbers), and the pointer outPosArrSizePtr to update the array’s
//logical size.

int main(){ //Everything in main is commented out. Use specific lines to test. 
    int posArrSize = 0;

    int arr[6] = {3, -1, -3, 0, 6, 4};
    int* arrPtr = nullptr;
    arrPtr = arr; //Can just assign the pointer to the array directly! Since arr is already a pointer!
   
   // int* ptr = nullptr;

   //int* posArrPtr = getPosNums1(arrPtr, 6, posArrSize);  //Part a 
    /*have to create a new integer pointer posArrPtr and set it equal to the returned address of the 
    heap dynamic array that holds all the positive integers. */

    //int* posArrPtr = getPosNums2(arrPtr, 6, &posArrSize); //Part b


    //getPosNums3(arrPtr, 6, ptr, &posArrSize) //part c

    //getPosNums4(arrPtr, 6, &ptr, &posArrSize); //part d

    

    // for(int i=0; i<posArrSize; i++){
    //     cout<<ptr[i]<<endl; 
    // }

    // delete[] ptr;
    // ptr = nullptr;
    

return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){

    outPosArrSize = 0;
    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){ //Can use index here! 
            outPosArrSize++;
        }
    }
    
    
    int* posArrPtr = new int[outPosArrSize]; //Creating heap dynamic array using pointer to reference it. 
    int j =0; //Set j=0 before the loop, to track posArrPtr.

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){ //Can use index here! 
            posArrPtr[j] = arr[i];
            j++;
        }
    }
    
return posArrPtr;

}


int* getPosNums2(int* arr, int arrSize, int* outPosArrPtr){

    //*outPosArrPtr = 0; //dereference outPosArrPtr and set its value to 0 to start.  Same as line 24

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){ //Can use index here! 
            (*outPosArrPtr)+=1; //increment the size directly via pointer.
        }
    }
    
    
    int* posArrPtr = new int[*outPosArrPtr]; //Creating heap dynamic array using pointer to reference it. 
    int j =0; //Set j=0 before the loop, to track posArrPtr.

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){ //Can use index here! 
            posArrPtr[j] = arr[i];
            j++;
        }
    }
    
return posArrPtr;

}

void getPosNums3(int* arr, int arrSize, int* &outPosArr, int &outPosArrSize){
    outPosArrSize = 0;
    int j=0;

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){
            outPosArrSize++;
        }
    }
    outPosArr = new int[outPosArrSize];

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){
            outPosArr[j]=arr[i];
            j++;
        }
    }

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){ //Can use index here! 
            (outPosArrSizePtr)+=1; //increment the size directly via pointer.
        }
    }
    int j = 0;
   *outPosArrPtr = new int[*outPosArrSizePtr];

    for(int i=0; i<arrSize; i++){
        if(arr[i]>0){
            *outPosArrPtr[j] = arr[i];
            j++;
        }
    }
    

}
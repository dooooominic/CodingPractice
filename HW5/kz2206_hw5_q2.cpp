#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main(){

    srand(time(0));
    int target = rand()%100+1;
    int guess, currMin,currMax,numGuessLeft,guessNumber;

    currMin = 1; currMax=100;
    numGuessLeft=5;
    guessNumber=1;

    cout<<"I thought of a number between 1 and 100! Try to guess it." <<endl; 
    //cout<<target; //I used this line to test the code. Maybe you will use it to grade? So I'm leaving it here! :)  
    cout<< "Range: ["<<currMin<<","<<currMax<<"]. Number of guesses left: " << numGuessLeft<<endl;
    cout<<"Your guess: ";
    cin>> guess;

    while(numGuessLeft>0){
        if (guess == target){
            cout<<"Congrats! You guessed my number in "<< guessNumber<<" guesses." <<endl;
            return 0; //end it immediately after getting right guess! break doesn't work inside of while.

        }
        
        else if(guess<target){
            cout<<"Wrong! My number is bigger." <<endl;
            currMin= guess+1;
            cout<<endl;
        }
        else{
            cout<<"Wrong! My number is smaller." <<endl;
            currMax= guess-1;
            cout<<endl;
        }

        numGuessLeft -=1;
        guessNumber+=1;

        if (numGuessLeft == 0){ //to stop the next cin
            break; 
        }
        cout<< "Range: ["<<currMin<<","<<currMax<<"]. Number of guesses left: " << numGuessLeft<<endl;
        cout<<"Your guess: ";
        cin>> guess;
        }
    cout<<"Out of guesses! My number is: "<<target<<endl;

    
return 0;
}

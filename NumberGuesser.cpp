#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    int randomNumber; 
    int guess;
    bool correctGuess;
    srand(time(0));
    randomNumber = rand() % 100 +1;

    cout << "Let's play number guesser! I have a number between 1 and 100. What's your guess? " <<endl;
    
    correctGuess = false;

    while (correctGuess == false){
        cin>> guess;
        if(guess == randomNumber){
            correctGuess = true; 
        }

        else if (guess < randomNumber){
            cout<< "Secret number is larger than your guess. Please try again." <<endl;
        }
        else if(guess > randomNumber){
            cout <<"Secret number is less than your guess. Please try again." <<endl;
        }
    }
    cout<<"Congratulations! You guessed my number!" <<endl;
    cout <<"Would you like to play again? " <<endl;

return 0;
}
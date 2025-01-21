#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

//counting number of even numbers entered: 
int main(){

    //counting even numbers 
    // int count, curr;
    // count = 0;
    // bool isEvenNumber;

    // isEvenNumber = true;

    // cout <<"Please enter a list of positive even numbers, and enter any odd number to end the list: " <<endl;

    // // while (isEvenNumber == true){
    // //     cin >> curr;
    // //     if(curr%2 !=0){
    // //         isEvenNumber = false;
            
    // //     }
    // //     else{
    // //         count ++;
    // //     }
    // // }

    // cin >>curr;
    // while (curr%2 ==0){
    //     count ++;
    //     cin >>curr;
    // }
    
    // cout<< "There are " << count << " even numbers you just entered." << endl;


// -------------------------------------------------------------------------------------------------------------------
    //creating multiplication table 
    // int n,m;
    // for (n=1; n<=9; n++){
    //     for (m=1; m<=9; m++){
    //         cout <<n<<" times " <<m << " = " << n*m <<endl;
    //     }
    // }

// -------------------------------------------------------------------------------------------------------------------
    int randomNumber; 
    int guess;
    bool correctGuess;
    srand(time(0));
    randomNumber = rand() % 100;

    cout << "Let's play number guesser! I have a number between 0 and 99. What's your guess? " <<endl;
    
    correctGuess = false;

    while (correctGuess == false){
        cin>> guess;
        if(guess == randomNumber){
            correctGuess = true; 
        }

        else if (guess < randomNumber){
            cout<< "Too low. Please try again." <<endl;
        }
        else if(guess > randomNumber){
            cout <<"Too high. Please try again." <<endl;
        }
    }
    cout<<"Congratulations! You guessed my number!" <<endl;
    cout <<"Would you like to play again? " <<endl;

return 0;
}
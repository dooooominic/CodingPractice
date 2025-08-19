#include<iostream>
#include<vector>

using namespace std;


int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

class Money{
public:
    friend Money operator+(const Money& amount1, const Money& amount2); //all friend functions are NON-MEMBER functions!
    //returns the sum of the variables of amount 1 and amount 2

    friend Money operator-(const Money& amount1, const Money& amount2);
    //returns the difference of amount 1 minus amount 2

    friend Money operator-(const Money& amount);

    friend bool operator ==(const Money& amount1, const Money& amount2);

    friend bool operator <(const Money& amount1, const Money& amount2);

    friend Money& operator +=(Money& lhs, const Money& rhs); //pass Money object by reference

    friend Money& operator -=(Money& lhs, const Money& rhs);

    Money(long dollars, int cents); //constructor

    Money(long dollars); //constructor

    Money();

    double get_value()const{ return (all_cents*0.01);};

    void set_value(long cents_in);

    void set_value(double amount);

    friend istream& operator >>(istream& ins, Money& amount);

    friend ostream& operator <<(ostream& uots, const Money& amount);

private:
    long all_cents;
};

class Check{

    int checkNumber;
    Money checkAmount;
    bool isCashed; //1 or 0, boolean in array.

public:
    //Getters:
    int getCheckNumber() const;
    Money getCheckAmount() const;
    bool getCheckStatus() const;

    //Constructors:
    Check():checkNumber(0), checkAmount(Money(0)), isCashed(false){}; //can use initialization list like this! 
    Check(int checkNumber=0, Money checkAmount=0, bool isCashed=false):checkNumber(checkNumber), //this technically covers both cases
    checkAmount(checkAmount), isCashed(isCashed){} 
    //same as: Check(const int& newcheckNumber, const Money& newcheckAmount, bool isitCashed): //you can use const & here!! Faster!
        //checkNumber(newcheckNumber), checkAmount(checkAmount), isCashed(isitCashed){}


    //setters?
    void setCheck(int checkNumber, Money checkAmount, bool cashedState);


};


int main(){

    vector<Check> checkbook;
    //vector<Check> depositedChecks; //maybe just use checkStatus getter to iterate through checkbook!
    int numOfChecks, checkNumber, numOfDeposits;
    Money balance, checkAmount, depositAmount, totalDepositAmount=0; 
    bool hasBeenCashed;


    cout<< "Please enter your current balance in the account, in the form of $D.CC. Enter .00 for exact integer amount: ";
    cin>> balance; 

    cout<<"Please enter the number of deposits you would like to make today: ";
    cin>>numOfDeposits;
    cout<<"You will now enter your deposits, in the form of $D.CC. Enter .00 for exact integer amount, and press enter after each deposit: "<<endl;
    for(int i=0; i<numOfDeposits;i++){
        cin>> depositAmount;
        totalDepositAmount += depositAmount;
        balance+=depositAmount; //this is overloaded in Money
    }

    cout<< "Your new balance is now: " << balance<<endl;


    cout<< "Please enter the number of checks you would like to update today: " <<endl;
    cin>> numOfChecks;

    cout<<"You will now enter the checks you would like to update: "<<endl;

    for(int i=0; i<numOfChecks; i++){
        cout<<"Please enter your check number: ";
        cin>>checkNumber;
        cout<<"Please enter your corresponding check amount, in the form of $D.CC. Enter .00 for exact integer amount: " ;
        cin>>checkAmount;
        //Constructor vs assignment. Maybe overload assignment operator for Money? Make sure this works

        cout<<"Has this check been cashed? Enter 1 for yes and 0 for no: ";
        cin>> hasBeenCashed;

        checkbook.push_back(Check(checkNumber, checkAmount, hasBeenCashed)); //collecting the checks!

        if(i!=numOfChecks-1){
            cout<<"Great. Onto the next check!"<<endl;
            cout<<endl;
        }
    }

    cout<<"The checks cashed are: "<<endl;
    for(int i=0; i<checkbook.size(); i++){
        if(checkbook[i].getCheckStatus() == true){
            cout<<"Check Number: " << checkbook[i].getCheckNumber()<< "\t" << "Check Amount: " << checkbook[i].getCheckAmount()<<endl;
            balance-=checkbook[i].getCheckAmount();
        }
    }
    cout<<endl;

    cout<<"The checks not yet cashed are: " <<endl;
    for(int i=0; i<checkbook.size(); i++){
        if(checkbook[i].getCheckStatus() ==false){
            cout<<"Check Number: " << checkbook[i].getCheckNumber()<< "\t" << "Check Amount: " << checkbook[i].getCheckAmount()<<endl;
        }
    }
    cout<<endl;

    cout<< "You have deposited a total of: " << totalDepositAmount <<endl;
    cout<<"After your deposits and cashed checks, your new balance is: " << balance<<endl;
    cout<<endl;

    cout<<"When all your uncashed checks are cashed, your total balance would be: ";
    Money totalUncashed;
    for(int i=0; i<checkbook.size();i++){
        if(checkbook[i].getCheckStatus()==false){
            totalUncashed+= checkbook[i].getCheckAmount();
        }
    }
    cout<<(balance-totalUncashed)<<endl;

    cout<<"Compared to your current balance, that is a difference of: " << totalUncashed<<endl;


    //Bubble sort for the check number part for EC. Perhaps custom sorting for check objects

    return 0;
}



Money::Money(long dollars, int cents){
    if (dollars * cents < 0) // If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100){
    // Body intentionally blank.
}

Money::Money() : all_cents(0)
{
    // Body intentionally blank.
}

void Money::set_value(long cents_in)
{
    all_cents = cents_in;
}

void Money::set_value(double amount)
{
    all_cents = amount * 100;
}

Money operator+(const Money&amount1, const Money&amount2){ //Not Money Money::operator... because friend means not a member function!
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents; //can still access private all_cents because it is a friend function
    return temp;
}

Money operator-(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator - (const Money& amount){
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money& amount1, const Money& amount2){
    return (amount1.all_cents < amount2.all_cents);
}


istream& operator >>(istream& ins, Money& amount){
    char one_char, decimal_point,
        digit1, digit2; // digits for the amount of cents
    long dollars;
    int cents;
    bool negative; // set to true if input is negative.
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; // read '$'
    }
    else
        negative = false;
    // if input is legal, then one_char == '$'
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    return ins;
}

// Uses cstdlib and iostream:
ostream &operator<<(ostream &outs, const Money &amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "− $" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

Money& operator +=(Money& lhs, const Money& rhs){ 
    lhs.all_cents +=rhs.all_cents;
    return lhs;
}

Money& operator -=(Money& lhs, const Money& rhs){
    lhs.all_cents -= rhs.all_cents;
    return lhs;
}

int Check::getCheckNumber() const{ //can be const because getter method!
    return checkNumber;
}

Money Check::getCheckAmount() const{ 
    return checkAmount;
}

bool Check::getCheckStatus() const{
    return isCashed;
}

void Check::setCheck(int newCheckNumber, Money newCheckAmount, bool cashedState){
    this->checkNumber = newCheckNumber;
    this->checkAmount = newCheckAmount;
    this->isCashed = cashedState;
}
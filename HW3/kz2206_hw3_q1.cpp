#include<iostream>
using namespace std;

int main(){

    double price1, price2, taxRate, discountedPrice, finalPrice;
    char answer;
    bool discount;

    cout<<"Enter price of first item: " <<endl;
    cin >>price1;
    cout<<"Enter price of second item: " <<endl;
    cin >>price2;

    cout<<"Does customer have a club card? (Y/N): " <<endl;
    cin >> answer;

    //could probably also use switch statements here? Probably would be messier. 
    if (answer == 'y' || answer == 'Y'){
        discount = true; //have to use = instead of ==. Compiler found the error.  
    }
    else if(answer == 'n' || answer == 'N'){
        discount = false;
    }

    cout<<"Enter tax rate: e.g. 5.5 for 5.5% tax: " <<endl;
    cin >> taxRate;

    //magical formula:
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "Base price: " << price1+price2 <<endl;

    //finding out which one is half off:
    if(price1 <= price2){
        price1 = price1*0.5;
    }
    else if(price2< price1){
        price2 = price2*0.5;
    }
    //applying 10% membership discount 
    if (discount){
        discountedPrice = (price1+price2)*0.9;
    }
    else{
        discountedPrice = price1+price2;
    }
    cout<< "Price after discounts: " <<discountedPrice<<endl;

    //magical formula:
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    finalPrice = discountedPrice*((100+taxRate)/100);
    cout<<"Total price: " << finalPrice <<endl;


    return 0;
}
//Determine which of two pizza sizes is the best to buy.

#include<iostream>
using namespace std;

double unitprice(int diameter, double price);

int main(){
    int diameter_small, diameter_large;
    double price_small, price_large, unitprice_small, unitprice_large;

    cout<< "Welcome to the pizza pricing calculator." <<endl;
    cout<< "Enter diameter of the small pizza (in inches): " << endl;
    cin >> diameter_small;
    cout<< "Enter the price of the small pizza: $";
    cin>> price_small; 
    cout<< "Enter diameter of the large pizza (in inches): " <<endl;
    cin>> diameter_large;
    cout<< "Enter the price of the large pizza: $";
    cin >> price_large;

    unitprice_small = unitprice(diameter_small, price_small);
    unitprice_large = unitprice(diameter_large, price_large);

    cout<< "Small pizza: \n";
    cout<< "Diameter = " <<diameter_small << " inches \n";
    cout<< "Price = $" << price_small << endl; 
    cout<<"Per square inch = $ " << unitprice_small <<endl;

    cout<< "Large pizza: \n";
    cout<< "Diameter = " <<diameter_large << " inches \n";
    cout<< "Price = $" << price_large << endl; 
    cout<<"Per square inch = $ " << unitprice_large <<endl;

    if(unitprice_large < unitprice_small){
        cout<< "The large one is the better buy." <<endl;
    }
    else
        cout<< "The small one is the better buy." <<endl; 

    cout<< "Buon Appetito! \n";
    return 0;
}



double unitprice(int diameter, double price){
    const double PI = 3.14159;
    double radius, area;

    radius = diameter/static_cast<double>(2); //type casting the 2 into double so that radius is a correct double value
    area = PI * radius * radius;
    return (price/area);
}
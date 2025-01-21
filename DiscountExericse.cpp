#include<iostream>
using namespace std;

int main(){
    int numOfPackage;
    double discount, totalCost;
    cout <<"Please enter the number of packages purchased: " <<endl;
    cin >> numOfPackage;

    

    if (numOfPackage>0 && numOfPackage<=10){
        discount = 0.0;
        totalCost = 99*numOfPackage*((100-discount)/100);
        cout <<"No discount." <<endl;
        cout<<"The total cost is: $" << totalCost<<endl;
    }
    
    else if(numOfPackage>10 && numOfPackage<=19){
        discount = 0.1;
        totalCost = 99.0*numOfPackage*(1.0-discount);
        cout << "The discount is "<< discount*100 <<"%. " <<endl;
        cout <<"The total cost is: $" << totalCost <<endl;
    }
    else if(numOfPackage >=20 && numOfPackage <=49){
        discount = 0.2;
        totalCost = 99.0*numOfPackage*(1.0-discount);
        cout << "The discount is "<< discount*100 <<"%. " <<endl;
        cout <<"The total cost is: $" << totalCost <<endl;
    }
    else if(numOfPackage >=50 && numOfPackage<=99){
        discount = 0.3;
        totalCost = 99.0*numOfPackage*(1.0-discount);
        cout << "The discount is "<< discount*100 <<"%. " <<endl;
        cout <<"The total cost is: $" << totalCost <<endl;
    }
    else if (numOfPackage >=100){
        discount = 0.4;
        totalCost = 99.0*numOfPackage*(1.0-discount);
        cout << "The discount is "<< discount*100 <<"%. " <<endl;
        cout <<"The total cost is: $" << totalCost <<endl;
    }
    else{
        cout <<"Your input number is invalid. Please try again." <<endl;
    }

    return 0;

}



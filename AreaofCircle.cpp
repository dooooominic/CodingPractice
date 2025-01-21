#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double radius;
    double area;

    cout<<"Please input the radius of your circle:" << endl;
    cin >> radius;

    area = M_PI*radius * radius;
    cout <<"The area of your circle is: " << area << endl;

    return 0;

}
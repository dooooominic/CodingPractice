#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double a, b, c;
    cout<<"Please enter the value of a: " <<endl;
    cin >>a;
    cout<<"Please enter the value of b: "<<endl;
    cin >>b;
    cout<<"Please enter the value of c: " <<endl;
    cin >>c;

    if (a==0 && b==0 && c==0){
        cout<<"Infinite number of solutions. " <<endl;
    }
    else if(a==0 && b==0 && c!=0){ //quite a few edge cases to cover? 
        cout <<"No solution. " <<endl;
    }
    else if (a==0 && c==0){
        cout<<"One solution. x= 0." <<endl;
    }
    else if(a==0 && b!=0 && c!=0){
        cout<<"One solution. x= " << -c/b <<endl;
    }
    else if(b*b-4*a*c<0){
        cout<<"No real solution. "<<endl;
    }
    else if(b*b-4*a*c==0){
        cout<< "One real solution. x = " << -b/(2*a) <<endl;
    }
    else if(b*b-4*a*c>0){
        cout<< "Two real solutions. x1= " << (-b+sqrt(b*b-4*a*c))/(2*a) << " and x2= " <<(-b-sqrt(b*b-4*a*c))/(2*a) <<endl;
    }

return 0;
}
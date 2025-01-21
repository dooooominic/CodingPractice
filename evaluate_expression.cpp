#include<iostream>
using namespace std;

int main(){
double arg1, arg2, res;
char op;

cout<< "Please input a mathematical expression in the form of arg1 op arg 2" << endl;
cin >> arg1 >> op >> arg2;

switch(op){
    case '+':
        res = arg1 + arg2;
        cout<<res<<endl;
        break;
    case '-':
        res = arg1 - arg2;
        cout<< res<<endl;
        break;
    case '*':
        res = arg1 * arg2;
        cout<<res<<endl;
        break;
    case '/':
        if (arg2 !=0){
            res = arg1/arg2;
            cout<<res<<endl;
        }
        else
            cout <<"Illegal expression! Please try again." <<endl;
        
        break;
    default:
        cout<<"Illegal expression! Please try again." <<endl;
        break;
}

return 0;

}
#include<iostream>
using namespace std;

int main(){

int num1, num2;
int sum, diff, product, div, mod;
double quotient;

cout << "Please enter two positive integers, separated by a space: " <<endl;

cin >> num1 >> num2;

sum = num1 + num2;
diff = num1 - num2;
product = num1*num2;
quotient = ((double)num1)/((double)num2);
div = num1/num2;
mod = num1%num2;



cout << num1 <<"+" <<num2 << " = " << sum <<endl;
cout << num1 <<"-" <<num2 << " = " << diff <<endl;
cout << num1 <<"*" <<num2 << " = " << product <<endl;
cout << num1 <<"/" <<num2 << " = " << quotient <<endl;
cout << num1 <<" div " <<num2 << " = " << div <<endl;
cout << num1 <<" mod " <<num2 << " = " << mod <<endl;

return 0;
}
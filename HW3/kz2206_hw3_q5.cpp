#include<iostream>
#include<string>
using namespace std;

int main(){

double BMI, weightInKilo, weightInPound, heightInMeter, heightInInches;
string weightStatus;

cout<<"Please enter weight (in pounds): " <<endl;
cin >> weightInPound;

cout<<"Please enter height (in inches): "<<endl;
cin >> heightInInches;

//Unit conversion:
weightInKilo = weightInPound*0.453592;
heightInMeter = heightInInches*0.0254;

//BMI Calculation:
BMI = weightInKilo /(heightInMeter*heightInMeter);

if (BMI< 18.5){
    weightStatus = "Underweight";
}
else if (BMI >=18.5 && BMI <25){
    weightStatus = "Normal";
}
else if(BMI>=25 && BMI<30){
    weightStatus = "Overweight";
}
else{
    weightStatus = "Obese";
}

cout <<"The weight status is: " << weightStatus <<endl;

return 0;
}
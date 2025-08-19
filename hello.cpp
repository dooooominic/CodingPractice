#include <iostream>
#include<string>
using namespace std;

// int getMax(int arr[], int size){
//     int max=0;
//     for(int i=0; i<size;i++){
//         if(arr[i]>max){
//             max = arr[i];
//         }
//     }
// return max;
// }

// int main() {
//     int data[] = {1,2,5,100,7,1000};
//     cout<<getMax(data,6);

//     return 0;
// }

void calculate(int num1, int num2, char op){
    if(op=='+'){cout<<num1+num2;}
    else if(op=='-'){cout<<num1-num2;}
    else if(op=='*'){cout<<num1*num2;}
    else if(op=='/'){cout<<num1/num2;}
    else{cout<<"Invalid operator! Try again.";}
}
int main(){
    int input1, input2;
    char op;
    cout<<"Enter first number:";
    cin>> input1;
    cout<<"Enter operator:";
    cin>>op;
    cout<<"Enter second number:";
    cin>>input2;
    calculate(input1, input2, op);
}

class Student{
    string name;
    int age;
    string major;
public:
    Student(){name = ""; age = 0; major = "";}
    Student(string newName,int newAge, string newMajor): name(newName), age(newAge), major(newMajor){}
    string getMajor()const{return major;}
    void changeMajor(string newMajor){major = newMajor;}
};

Student Dominic = Student("Dom", 26, "CS");

class Children: public Student{ //can inherit in C++ like this! 


};
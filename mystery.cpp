#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    ofstream outFile;
    outFile.open("SecretMessage.txt");
    for(int i=0; i<100; i++)
        outFile << "I love you askim!"<<endl;
    outFile.close();

}
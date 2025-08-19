#include<iostream>
using namespace std;

int main(){
    for (int i=1;i<=19;i++){ 
        if (i==17){ //or: if (i==17) || (i%2==0){continue}, cout all the rest. 
            continue;
        }
        else if(i%2!=0){
            cout<<i<<endl;
        }
    }

return 0;


}
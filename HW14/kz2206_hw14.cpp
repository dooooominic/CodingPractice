#include<iostream>
#include<vector>
using namespace std;

vector<int> MaxAndMin(vector <int> &data, int start, int end);
//The function takes in an integer vector data by reference, as well as the starting and ending index. It returns an integer vector
//with two elements. The first element is the minimum of the input data vector, and the second element is the maximum of the input data vector. 

int main(){
    //FOR TESTING:
    srand(time(NULL));

    vector<int> v;
    for(int i=0; i<10; i++){
        v.push_back(rand()%100);
        cout<<v[i]<<", ";
    }

    cout<<endl;

    vector<int> result = MaxAndMin(v, 0, v.size()-1);
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }

return 0;
}

vector<int> MaxAndMin(vector <int>&data, int start, int end){
    vector<int> result;
    int localMax =0;
    int localMin =0;
    if(start == end){
        localMax = data[start];
        localMin = data[end];
    }
    else if(end == start+1){
        if(data[start]<=data[end]){
            localMax = data[end];
            localMin = data[start];
        }
        else{
            localMax = data[start];
            localMin = data[end];
        }
    }
    else{
        int mid = (start+end)/2;
        vector<int> v1= MaxAndMin(data, start, mid);
        vector<int> v2= MaxAndMin(data, mid+1, end);
        if(v1[0]<=v2[0]){ //compares for the min
            localMin=v1[0];
        }
        else{
            localMin=v2[0];
        }
        if(v1[1]>=v2[1]){ //compares for the max!
            localMax=v1[1];
        }
        else{
            localMax=v2[1];
        }
    }
    result.push_back(localMin); //first element is min
    result.push_back(localMax); //second element is max

return result;
}
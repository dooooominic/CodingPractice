#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Queue{
    vector<T> data;
    //T* start; doesn't work apparently because vector dynamic resizing can be weird
    int frontIndex;
public:
    Queue():frontIndex(0){}
    void enqueue(T newData){data.push_back(newData);}
    void dequeue();
    T top() const{return data[frontIndex];}
    bool isEmpty() const{return frontIndex>=data.size();} //if frontIndex equals or moves past size, we have dequeued everything!
    void clear(){data.clear();}
    int size() const {return data.size()-frontIndex;}

    int getDataSize() const{ return data.size();} //for testing
    int getFrontIndex() const{return frontIndex;} //for testing
};


int main(){
    Queue<int> queue1;
    for(int i=1; i<=5;i++){
        queue1.enqueue(i);
        cout<< queue1.getDataSize()<<endl;
    }

    
    queue1.dequeue();
    queue1.dequeue();
    queue1.dequeue();
    queue1.dequeue();
    queue1.dequeue();

    cout<< queue1.size()<<endl;
    cout<<"Front index is: "<<endl;
    cout<< queue1.getFrontIndex()<<endl;
    cout<< "Vector size is:" << queue1.getDataSize();


}

template<class T>
void Queue<T>::dequeue(){
    if(this->size()==0){ //should check if entering particular loops while writing 
        cout<<"Invalid dequeue! The queue is currently empty."<<endl;
    }
    else if(this->size()==1){
        frontIndex = 0;
        data.clear();
    }
    else{
        frontIndex++;
    }
}

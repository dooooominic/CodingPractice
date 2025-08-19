#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class LinkedList;
void openFile(ifstream& inFile);

class Node{
    double amount;
    string name;
    Node* next;
    friend class LinkedList;

public:
    //Node():amount(0),name(""), next(nullptr){} //don't need this if we have the following line to do both!
    Node(double newAmount=0, string newName="", Node* newPtr=nullptr): amount(newAmount), name(newName), next(newPtr){}

    void setAmount(double newAmount){amount = newAmount;}
    void setName(string newName){name = newName;}
    double getAmount(){return amount;}
    string getName(){return name;} //do we need these??? make LinkedList a friend class so we don't! 

};

class LinkedList{
    Node* head;
    //Node* recursiveCopy(Node* rhs);
public:
    LinkedList(): head(nullptr){}
    // LinkedList(const LinkedList& rhs):head(nullptr){*this=rhs;} //copy constructor
    // LinkedList& operator=(const LinkedList& rhs);//assignment operator
    // ~LinkedList(){clear();}
    bool isEmpty()const{return head==nullptr;}
    void insertAtHead(double newAmount, string newName);
    void insertAtEnd(double newAmount, string newName);
    //int size() const;
    void printList() const;

};


int main(){

    ifstream inFile;
    openFile(inFile); //filename: data.txt

    LinkedList people;
    int currAmount;
    string currName;

    while(inFile>>currAmount){
        inFile.ignore(); //ignore one space
        getline(inFile, currName);
        people.insertAtEnd(currAmount, currName);
    }

    people.printList();

return 0;
}


void openFile(ifstream& inFile){
    string filename;
    cout<<"What's the file name?"<<endl;
    cin>>filename;
    inFile.open(filename);
    while(!inFile){
        cout<<"What's the file name?"<<endl;
        cin>>filename;
        inFile.clear();
        inFile.open(filename);
    }
}

void LinkedList::insertAtHead(double newAmount, string newName){
    Node* tempPtr;
    tempPtr= new Node;
    tempPtr->amount = newAmount;
    tempPtr->name = newName;
    tempPtr->next = head; //setting the next node to be what head is currently pointing to. nullptr if empty list
    head = tempPtr; //head now points to this new node! 
}

void LinkedList::insertAtEnd(double newAmount, string newName){
    if(isEmpty()){
        insertAtHead(newAmount, newName);
        return;
    }
    else{
        Node* tempPtr;
        tempPtr = new Node(newAmount, newName);
        Node* end = head;
        while(end->next !=nullptr){
            end = end->next;
        }
        end->next = tempPtr;
    }
}

void LinkedList:: printList() const{
    Node* iter;
    for(iter = head; iter!=nullptr; iter=iter->next){
        cout<<iter->getAmount() <<" " << iter->getName()<<endl;
    }

}
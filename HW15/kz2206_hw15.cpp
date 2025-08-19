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
     ~LinkedList(){clear();}
    bool isEmpty()const{return head==nullptr;}
    void insertAtHead(double newAmount, string newName);
    void insertAtEnd(double newAmount, string newName);
    //int size() const;
    void printList() const; 
    double getAverageAmount() const;
    void printReimbursement(double averageAmount);
    void clear();

};


int main(){

    ifstream inFile;
    openFile(inFile); //filename: data.txt

    LinkedList people;
    double currAmount;
    string currName;

    while(inFile>>currAmount){
        inFile.ignore(); //ignore one space
        getline(inFile, currName);
        people.insertAtEnd(currAmount, currName);
    }

    double average = people.getAverageAmount();
    people.printReimbursement(average);
    cout<<"In the end, you should all have spent $" << average <<endl;
    cout<<"Process finished. " <<endl;

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

void LinkedList::clear(){
    Node* temp = head;
    while(temp!=nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
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

double LinkedList::getAverageAmount() const{
    Node* iter;
    double sum = 0;
    int count = 0;
    double average;
    for(iter=head; iter!=nullptr; iter=iter->next){
        sum+=iter->getAmount();
        count++;
    }
    if(count ==0){
        return 0;
    }
    else{
        average = sum/((double)count);
    }
return average;
}

void LinkedList::printReimbursement(double averageAmount){
    Node* payer = head;
    Node* toPay;
    for(payer = head, toPay=head; payer!=nullptr;){
        if(toPay==nullptr){
            payer = payer->next; //have to increment payer after the previous payer has been handled. Edge case!!
            cout<<payer->name<<", you don't need to do anything."<<endl;
            return;
        }
        if(payer==toPay){
            if(payer->amount >= averageAmount){
                cout<<payer->name<<", you don't need to do anything."<<endl;
                payer=payer->next;
            }
            else{
                if(toPay->next== nullptr){
                    return;
                }
                toPay = toPay->next;
            }
        }

        if(toPay== nullptr){
            return;
        }
        cout<<payer->name<<", "; 
        if(payer->amount>= averageAmount){
            cout<<"you don't need to do anything."<<endl;
            payer=payer->next;
        }
        else{ //owe money
            double owed = averageAmount - payer->amount;
            double canAccept = toPay->amount - averageAmount;
            if(canAccept>=owed){
                cout<<"you give " << toPay->name << " $"<< owed<<endl;
                toPay->amount -=owed;
                canAccept -= owed;
                payer->amount+=owed;
                payer=payer->next;
                if(canAccept == averageAmount){
                    toPay = toPay->next;
                    if(toPay==nullptr){
                        return;
                    }
                }
            }
            else{
                cout<<"you give " << toPay->name << " $" << canAccept<<endl;
                payer->amount += canAccept;
                toPay->amount -= canAccept; //instead of owed
                toPay=toPay->next;
                //do not increment the iter pointer so we do this again!
                // if(toPay==nullptr){
                //     return;
                // }
            }
        }
    }

return;
}
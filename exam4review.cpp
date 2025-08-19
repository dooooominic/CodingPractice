#include<iostream>
#include<string>
#include<stack>

using namespace std;

//const int NORTH = 1; can define constant variables like this 

//template <class T>
class Node{
    int data;
    Node* parent;
    Node* left;
    Node* right;
    friend class BST; //now BST can access node->left, etc. directly! 
public:
    Node(){}
    Node(int newdata=0, Node* newParent = nullptr, Node* newLeft = nullptr, Node* newRight = nullptr):
        data(newdata), parent(newParent), left(newLeft), right(newRight){}
    int getData() const{return data;}
    void setData(int newData){data = newData;}
    void setLeft(Node* l){left = l;}
    void setRight(Node* r){right = r;}
};

class BST{
    Node* root;
public:
    BST(){root = nullptr;}
    void addLeft(int data, Node* parent);
    void getInOrder(Node* node);


};


class Pet{
    string name;
    string species;
    int ID;
    int age;
public:
    Pet(string newname = "no name", string newspecies = "no species", int newID = 0000, int newage = 0):name(newname), species(newspecies), ID(newID), age(newage){}
    string getName() const{return name;}
    void setName(string newname){name = newname;}
    string getSpecies() const{return species;}
    int getID() const{return ID;}
    void setID(int newID){ID = newID;}
    int getAge() const{return age;}
    void setAge(int newage){age = newage;}
    void printPetInfo()const{cout<< "This pet is named " << this->getName()<< " and they are a "<< this->getSpecies()<<", who has an ID of "<<this->getID()<<
        ", and is "<< this->getAge()<< " years old!"<<endl;}

};
class Dog:public Pet{
public:
    Dog():Pet("no name", "Dog"){}




};


int main(){

    Pet* Toby = new Pet("Toby", "Dog", 1001, 5);
    Toby->printPetInfo();//can use pointer version here! Then can use polymorphism and virtual functions to override functions. 

    stack <Pet*> Pets;
    Pets.push(Toby);
    cout<<Pets.top()->getName();

}

void BST::addLeft(int data, Node* parent){
    Node* newNode = new Node(data, parent);
    parent->setLeft(newNode);
}

void BST::getInOrder(Node* node){ //quick recursive check
    if(node != nullptr){
        getInOrder(node->left);
        cout<< node->data;
        getInOrder(node->right);
    }
}
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

void printGrid(char (&grid)[20][20]);

const int UP = 1;
const int DOWN = -1;
const int LEFT = -1;
const int RIGHT = 1;

//constants for doodlebug breeding period and such 


// class Grid{
// private:
//     Organism* grid[20][20];

// public:
// //have print functions and update functions for movements and such here
//     Grid(){}

//need the big 3  to delete objects and set pointers to nullptr;

// };




class Organism{ //base class
public:
    virtual void move(char (&grid)[20][20])=0;
    virtual void breed(char (&grid)[20][20])=0;
    virtual void starve(char (&grid)[20][20])=0; //MUST have same parameter as derived class(vice versa) to OVERRIDE!
    //define virtual checkNeighbors()=0;

    Organism(){}

    //another Organism constructor that takes in location and timestep...

protected: //Otherwise do I have to use getters and setters through the derived class?
//private: private in base and derived class gets them through getters but has no direct access
    int location_x;
    int location_y;
    int timestep;
};

class Ant: public Organism{ //Ants is a derived class of base class Organism

public:
    void move(char (&grid)[20][20]);
    void breed(char (&grid)[20][20]);
    
    Ant() : Organism(){ //derived class constructor MUST call base class constructor! Can't define this outside though? 
        location_x =rand()%20;
        location_y = rand()%20;
        timestep = 0;
    }

    //additional constructor that takes in location and type for breeding 

    int getLocationX() const;
    int getLocationY() const;
    void setLocationX(int newLocationX);
    void setLocationY(int newLocationY);

};

class Doodlebug: public Organism{

public:
    void move(char (&grid)[20][20]);
    void breed(char (&grid)[20][20]);
    void starve(char (&grid)[20][20]);
    Doodlebug() : Organism(){
        location_x =rand()%20;
        location_y = rand()%20;
        timestep = 0;
    }

    int getLocationX() const;
    int getLocationY() const;
    void setLocationX(int newLocationX);
    void setLocationY(int newLocationY);

};


int main(){

    //Grid grid; //using Grid class instantiation
    srand(time(0));


    char grid[20][20]; //initializes grid

   // Organism* grid[20][20]; //do it this way instead! null if not ants or doodlebugs TRY THIS WAY?



    for(int i=0; i<20;i++){
        for(int j=0; j<20;j++){
            grid[i][j]= '-'; //Or should I do 2D array for Organism? And have null everywhere that's not ant or doodlebug? 
        }
    }
    //array of Organisms* 

    

    vector<Ant> ants(100);
    vector<Doodlebug> doodlebugs(5);

    for(int i=0; i<ants.size(); i++){
        grid[ants[i].getLocationX()][ants[i].getLocationY()] = 'o';
    }

    for(int i=0; i<doodlebugs.size(); i++){
        grid[ants[i].getLocationX()][ants[i].getLocationY()] = 'X';
    }
    
    //printGrid(grid);

    //iterate through all organisms looking for ants, move, then iterate again for doodlebugs
    
    

} //-------------------------------------------end of main ----------------------------------------------

void printGrid(char (&grid)[20][20]){
    for(int i=0; i<20;i++){
        for(int j=0; j<20;j++){
            cout<<grid[i][j]<<' ';
        }
        cout<< endl;
    }
}


int Ant::getLocationX() const{
    return location_x;
}

int Ant::getLocationY() const{
    return location_y;
}

void Ant:: setLocationX(int newLocationX){
    location_x=newLocationX;
}

void Ant:: setLocationY(int newLocationY){
    location_y=newLocationY;
}

void Ant::move(char (&grid)[20][20]){
    int option = 0;
    if(getLocationX()==0){
        if(getLocationX()+1=='-' && getLocationY()+1=='-' && getLocationY()-1=='-'){
            option = rand()%4; //way too many options to check! Maybe another function? 
        }

    }

    grid[getLocationX()][getLocationY()]='-'; //setting actual grid

    

}

void Ant::breed(char (&grid)[20][20]){

    //blah blah blah
}


int Doodlebug::getLocationX() const{
    return location_x;
}

int Doodlebug::getLocationY() const{
    return location_y;
}

void Doodlebug:: setLocationX(int newLocationX){
    location_x=newLocationX;
}

void Doodlebug:: setLocationY(int newLocationY){
    location_y=newLocationY;
}

void Doodlebug::move(char (&grid)[20][20]){

    //blah blah blah
}

void Doodlebug::breed(char (&grid)[20][20]){

    //blah blah blah
}

void Doodlebug::starve(char (&grid)[20][20]){

    //blah blah blah
}
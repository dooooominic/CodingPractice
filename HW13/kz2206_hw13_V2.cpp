#include<iostream>
#include<vector>
#include<string>

using namespace std;

const char ANT = 'o';
const char DOODLEBUG = 'X';
const char EMPTY = '-';
const int ANT_BREEDING_TIME = 3;
const int DOODLEBUG_BREEDING_TIME = 8;
const int DOODLEBUG_STARVE_TIME = 3;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

class Grid; 
class Organism{ //base class
public:
    virtual void move(Organism* (&grid)[20][20])=0;
    //virtual void breed(Organism* (&grid)[20][20])=0; done in Grid class
    //MUST have same parameter as derived class(vice versa) to OVERRIDE!
    virtual char getType() const {return type;};
    int getLocationX()const {return location_x;};
    int getLocationY()const {return location_y;};
    void setLocationX(int newX){location_x = newX;};
    void setLocationY(int newY){location_y = newY;};
    void incrementTimeStep(){timestep++;};
    int getTimeStep()const{return timestep;};
    void setTimeStep(int newTimeStep){timestep = newTimeStep;};
    bool getDeadState() const{return isDead;};
    void setDead(){isDead=true;};
    bool hasMoved()const{return moved;};
    void setMoved(bool newmoved){moved = newmoved;};
    Organism(){}
    Organism(int locationX, int locationY, int newTimeStep, char newType, bool isDead=false, bool moved= false){
        location_x = locationX;
        location_y = locationY;
        timestep = newTimeStep;
        type = newType;
    }
private:
    int location_x;
    int location_y;
    int timestep;
    char type;
    bool isDead;
    bool moved;
};

class Ant: public Organism{ //Ants is a derived class of base class Organism

public:
    void move(Organism* (&grid)[20][20]);
    //void breed(Organism* (&grid)[20][20]); done in Grid class
    
    Ant() : Organism(rand()%20, rand()%20, 0, ANT){}
        //additional constructor that takes in location and type for breeding 
    
    Ant(int locationX, int locationY):Organism(locationX, locationY, 0, ANT, false, false){}

};

class Doodlebug: public Organism{

public:
    void move(Organism* (&grid)[20][20]);
    //void breed(Organism* (&grid)[20][20]); done in Grid class
    void starve(Organism* (&grid)[20][20]);
    Doodlebug() : Organism(rand()%20, rand()%20, 0, DOODLEBUG), breedingTime(0){}
    Doodlebug(int newX, int newY): Organism(newX, newY, 0, DOODLEBUG, false, false), breedingTime(0){}
    void incrementBreedingTime(){breedingTime++;};
    int getBreedingTime(){return breedingTime;};
    void setBreedingTime(int newTime){breedingTime = newTime;};
private:
    int breedingTime;

};

class Grid{
private:
    Organism* grid[20][20];
    vector<Ant> ants;
    vector<Doodlebug> doodlebugs;
public: 
    Grid();
    void printGrid() const;
    void antsMove();
    void doodlebugsMove();
    void antsBreed();
    void doodlebugsBreed();
    void doodlebugsStarve();
    void replaceDead();
};

int main(){//------------------------------------------- start of main ----------------------------------------------
    srand(time(0));
    Grid world;
    int time = 0;
    world.printGrid();
    cout<<"Please press enter to move forward in time: " <<endl;
    string input;
    getline(cin,input);
    while(input == ""){
        world.doodlebugsMove();
        world.doodlebugsBreed();
        world.doodlebugsStarve();

        world.antsMove();
        world.antsBreed();

        world.printGrid();
        cout<<"Currently on step: "<<++time;
        getline(cin, input);
    }
    cout<<"The simulation has ended.";
}//-------------------------------------------end of main ----------------------------------------------

void Grid::printGrid()const{
    for(int i=0; i<20; i++){
        for(int j=0; j<20;j++){
            if(grid[i][j]== nullptr){
                cout<<EMPTY<<" ";
            }
            else{
                cout<< grid[i][j]->getType() <<" ";
            }
        }
        cout<<endl;
    }

}

Grid::Grid(){
    ants.reserve(400);
    doodlebugs.reserve(400); //need to make sure there is no reallocation during push_backs!!! Fixes segmentation fault. 

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            grid[i][j] = nullptr;
        }
    }
    for(int i=0; i<100;){
        Ant currAnt = Ant();

        int locationX = currAnt.getLocationX();
        int locationY = currAnt.getLocationY();

        if(grid[locationX][locationY] == nullptr){
            ants.push_back(currAnt);
            grid[locationX][locationY] = &ants.back();
            i++; //increment only when the ant is pushed in
        }
    }

    for(int i=0; i<5;){
        Doodlebug currBug = Doodlebug();
        int locationX = currBug.getLocationX();
        int locationY = currBug.getLocationY();
        if(grid[locationX][locationY] == nullptr){
            doodlebugs.push_back(currBug);
            grid[locationX][locationY] = &doodlebugs.back();
            i++;
        }
    }
}

void Ant:: move(Organism* (&grid)[20][20]){
    int choice = rand()%4+1;
    int currX = getLocationX();
    int currY = getLocationY();
    incrementTimeStep();
    switch(choice){
        case UP:{
        int newY = currY + 1;
        if(newY<20 && grid[currX][newY] == nullptr){
            grid[currX][newY]=this;
            grid[currX][currY] = nullptr;
            setLocationY(newY);
            setMoved(true);
            break;
        }
        else
            break;
        }

        case DOWN:{
        int newY = currY -1;
        if(newY>=0 && grid[currX][newY] == nullptr){
            grid[currX][newY]=this;
            grid[currX][currY] = nullptr;
            setLocationY(newY);
            setMoved(true);
            break;
        }
        else
            break;
        }
    
        case LEFT:{
        int newX = currX -1;
        if(newX>=0 && grid[newX][currY] == nullptr){
            grid[newX][currY]=this;
            grid[currX][currY] = nullptr;
            setLocationX(newX);
            setMoved(true);
            break;
        }
        else
            break;
        }

        case RIGHT:{
        int newX = currX +1;
        if(newX<20 && grid[newX][currY] == nullptr){
            grid[newX][currY]=this;
            grid[currX][currY] = nullptr;
            setLocationX(newX);
            setMoved(true);
            break;
        }
        else
            break;
        }
    }

}
void Doodlebug::move(Organism* (&grid)[20][20]){
    int currX = getLocationX();
    int currY = getLocationY();
    int newX, newY;
    incrementTimeStep(); //starve timer increments
    incrementBreedingTime(); //breeding timer increments
    //search for ants nearby: 

    int direction[4]={UP,DOWN,RIGHT,LEFT};
    for(int i=3; i>0; i--){ //have to shuffle for doodlebug
        int j = rand()%(i+1);
        int temp = direction[i];
        direction[i]=direction[j];
        direction[j]=temp;
    }
    for (int i=0; i<4; i++){
        switch(direction[i]){
            case RIGHT:{
                if(currX+1<20 && grid[currX+1][currY]!=nullptr && grid[currX+1][currY]->getType()==ANT){
                    newX = currX+1;
                    grid[newX][currY]->setDead(); //updates the ant to be eaten as dead
                    grid[newX][currY] = this; //overwrites that pointer with pointer to current doodlebug!
                    setLocationX(newX);
                    grid[currX][currY] = nullptr; 
                    setMoved(true);
                    setTimeStep(0);
                return;
            }
        break;
        }
            case LEFT:{
                if(currX-1>=0 && grid[currX-1][currY]!= nullptr && grid[currX-1][currY]->getType()==ANT){
                    newX = currX-1;
                    grid[newX][currY]->setDead(); 
                    grid[newX][currY] = this; 
                    setLocationX(newX);
                    grid[currX][currY] = nullptr; 
                    setMoved(true);
                    setTimeStep(0);
                return;
            }
        break;
        }
            case UP:{
                if(currY+1<20 && grid[currX][currY+1]!=nullptr && grid[currX][currY+1]->getType()==ANT){
                    newY = currY+1;
                    grid[currX][newY]->setDead();
                    grid[currX][newY]=this;
                    setLocationY(newY);
                    grid[currX][currY] = nullptr;
                    setMoved(true);
                    setTimeStep(0);
                return;
            }
        break;
    }
            case DOWN:{
                if(currY-1>=0 && grid[currX][currY-1]!=nullptr && grid[currX][currY-1]->getType()==ANT){
                    newY = currY-1;
                    grid[currX][newY]->setDead();
                    grid[currX][newY]=this;
                    setLocationY(newY);
                    grid[currX][currY] = nullptr;
                    setMoved(true);
                    setTimeStep(0);
                return;
            }
        break;
            }
        }
    }
        int choice = rand()%4+1;

    switch(choice){
        case UP:{
        int newY = currY + 1;
        if(newY<20 && grid[currX][newY] == nullptr){
            grid[currX][newY]=this;
            grid[currX][currY] = nullptr;
            setLocationY(newY);
            setMoved(true);
            break;
        }
        else
            break;
        }

        case DOWN:{
        int newY = currY -1;
        if(newY>=0 && grid[currX][newY] == nullptr){
            grid[currX][newY]=this;
            grid[currX][currY] = nullptr;
            setLocationY(newY);
            setMoved(true);
            break;
        }
        else
            break;
        }
    
        case LEFT:{
        int newX = currX -1;
        if(newX>=0 && grid[newX][currY] == nullptr){
            grid[newX][currY]=this;
            grid[currX][currY] = nullptr;
            setLocationX(newX);
            setMoved(true);
            break;
        }
        else
            break;
        }

        case RIGHT:{
        int newX = currX +1;
        if(newX<20 && grid[newX][currY] == nullptr){
            grid[newX][currY]=this;
            grid[currX][currY] = nullptr;
            setLocationX(newX);
            setMoved(true);
            break;
        }
        else
            break;
        }
    break;
    }
}
        
void Doodlebug::starve(Organism* (&grid)[20][20]){
    if(getTimeStep()==DOODLEBUG_STARVE_TIME){
        this->setDead();

        grid[getLocationX()][getLocationY()] = nullptr;
    }
}

void Grid::antsMove(){
    for(int i=0; i<ants.size(); i++){
        ants[i].setMoved(false);
        if(ants[i].getDeadState()==true){
            int remove = i;
            ants.erase(ants.begin()+remove);
            i--;
        }
        if(ants[i].getDeadState()==false){
            ants[i].move(grid); //check this
        }
    }

}

void Grid::doodlebugsMove(){
    for(int i=0; i<doodlebugs.size();i++){
        doodlebugs[i].setMoved(false);
        if(doodlebugs[i].getDeadState()==true){
            int remove = i;
            doodlebugs.erase(doodlebugs.begin()+remove);
            i--;
        }

        if(doodlebugs[i].getDeadState()==false && doodlebugs[i].hasMoved()==false){
            doodlebugs[i].move(grid);
        }


    }
}

void Grid::antsBreed(){
    for(int i=0; i<ants.size();i++){
        if((ants[i].hasMoved() == true) && (ants[i].getDeadState() == false) && ants[i].getTimeStep()>=ANT_BREEDING_TIME){ //any other requirements here?
            ants[i].setTimeStep(0);
            int currX = ants[i].getLocationX();
            int currY = ants[i].getLocationY();
            int newX, newY;
            bool bred = false;
            int attempts = 0;
            while(bred == false && attempts<4){
                attempts++;
            int option = rand()%4+1;
            switch(option){
                case UP:{
                    newY = currY+1;
                    if(newY<20&& grid[currX][newY]==nullptr){
                        Ant newAnt = Ant(currX, newY);
                        ants.push_back(newAnt);
                        grid[currX][newY]=&ants.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case DOWN:{
                    newY = currY-1;
                    if(newY>=0 && grid[currX][newY]==nullptr){
                        Ant newAnt = Ant(currX, newY);
                        ants.push_back(newAnt);
                        grid[currX][newY]=&ants.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case LEFT:{
                    newX = currX-1;
                    if(newX>=0 && grid[newX][currY]==nullptr){
                        Ant newAnt = Ant(newX, currY);
                        ants.push_back(newAnt);
                        grid[newX][currY]=&ants.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case RIGHT:{
                    newX = currX+1;
                    if(newX<20 && grid[newX][currY]==nullptr){
                        Ant newAnt = Ant(newX, currY);
                        ants.push_back(newAnt);
                        grid[newX][currY]=&ants.back();
                        bred = true;
                        break;
                    }
                    break;
                }
            }
        }
    }
    }

}

void Grid::doodlebugsBreed(){
    for(int i=0; i<doodlebugs.size();i++){
        if((doodlebugs[i].hasMoved() == true) && (doodlebugs[i].getDeadState() == false) && doodlebugs[i].getBreedingTime()>=DOODLEBUG_BREEDING_TIME){ //any other requirements here?
            doodlebugs[i].setBreedingTime(0);
            int currX = doodlebugs[i].getLocationX();
            int currY = doodlebugs[i].getLocationY();
            int newX, newY;
            bool bred = false;
            int attempts = 0;
            while(bred == false && attempts<4){
                attempts++;
            int option = rand()%4+1;
            switch(option){
                case UP:{
                    newY = currY+1;
                    if(newY<20&& grid[currX][newY]==nullptr){
                        Doodlebug newDoodlebug = Doodlebug(currX, newY);
                        doodlebugs.push_back(newDoodlebug);
                        grid[currX][newY]=&doodlebugs.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case DOWN:{
                    newY = currY-1;
                    if(newY>=0 && grid[currX][newY]==nullptr){
                        Doodlebug newDoodlebug = Doodlebug(currX, newY);
                        doodlebugs.push_back(newDoodlebug);
                        grid[currX][newY]=&doodlebugs.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case LEFT:{
                    newX = currX-1;
                    if(newX>=0 && grid[newX][currY]==nullptr){
                        Doodlebug newDoodlebug = Doodlebug(newX, currY);
                        doodlebugs.push_back(newDoodlebug);
                        grid[newX][currY]=&doodlebugs.back();
                        bred = true;
                        break;
                    }
                    break;
                }
                case RIGHT:{
                    newX = currX+1;
                    if(newX<20 && grid[newX][currY]==nullptr){
                        Doodlebug newDoodlebug = Doodlebug(newX, currY);
                        doodlebugs.push_back(newDoodlebug);
                        grid[newX][currY]=&doodlebugs.back();
                        bred = true;
                        break;
                    }
                    break;
                }
            }
        }
    }
    }
}

void Grid::doodlebugsStarve(){
    for(int i=0; i<doodlebugs.size();i++){
        doodlebugs[i].starve(grid);
    }
}

// void Grid::replaceDead(){
//     /*
//     new ant vector;
//     new doodlebug vector;
//     iterate through ant: if not dead -- add to ant vector;
//     new ant = ant vector;
    
    
    
//     */

// }
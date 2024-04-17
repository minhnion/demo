#include "Point.cpp"

class Ward{
private: 
string name;   
Point entrant;
Point exit;
vector<Point> walls; // toa do cac buc tuong

public:
    Ward(){};
    // Setters with input validation (optional, adjust validation as needed)
    void setName(string s){
        name = s;
    }

    void setEntrant(const Point& newEntrant) {
        entrant = newEntrant;
    }

    void setExit(const Point& newExit) {
        exit = newExit;
    }

    void addWall(const Point& newWall) {
        // Check for duplicate walls (optional)
        // if (std::find(walls.begin(), walls.end(), newWall) != walls.end()) {
        //     // Handle duplicate wall case (e.g., throw an exception)
        // }
        walls.push_back(newWall);
    }

    // Getters
    const Point& getEntrant() const {
        return entrant;
    }

    const Point& getExit() const {
        return exit;
    }

    const vector<Point>& getWalls() const {
        return walls;
    }
    string getName(){
        return name;
    }
};
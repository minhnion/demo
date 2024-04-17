#include "Pedestrian.cpp"

class Visitor : public Pedestrian{
private:
    Walkability walkability;
public:
    void setWalkability(Walkability w){
        walkability = w;
    }
    Walkability getWalkability(){
        return walkability;
    }
    std::string getType() const override{
        return "Visitor";
    }
};
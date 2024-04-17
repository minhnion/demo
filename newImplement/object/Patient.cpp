#include "Pedestrian.cpp"
class Patient : public Pedestrian{
private:
    Walkability walkability;
pulic:
    void setWalkability(Walkability w){
        walkability = w;
    }
    Walkability getWalkability(){
        return walkability;
    }
    std::string getType() const override{
        return "Patient";
    }
};
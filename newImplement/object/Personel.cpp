#include "Pedestrian.cpp";
class Personnel : public Pedestrian {
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
        return "Personel";
    }
};

class Point{
private:
    double x;
    double y;
public:
    Point(){

    }
    Point(double x,double y){
        this->x = x;
        this->y = y;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }
};
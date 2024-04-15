
class Point{
private:
    double x;
    double y;
public:
    Point(){

    }
    Point(int x,int y){
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
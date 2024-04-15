
class Emotion{
    private:
        double pleasure = 0.75;
        double surprise = 0.5;
        double anger = -0.2;
        double fear = -0.2;
        double hate = -0.4;
        double sad = -0.4;
    public:
        double getPleasure(){return pleasure;}
        double getSurprise(){return surprise;}
        double getAnger(){return anger;}
        double getFear(){return fear;}
        double getHate(){return hate;}
        double getSad(){return sad;}
        double setPleasure(double pls){
            pleasure = pls;
        }
        double setSurprise(double surp ){
            surprise = surp;
        }
        double setAnger(double agr){
            anger = agr;
        }
        double setFear(double fear){
            this->fear = fear;
        }
        double setHate(double h){
            hate = h;
        }
        double setSad(double sd){
            sad = sd;
        }

};
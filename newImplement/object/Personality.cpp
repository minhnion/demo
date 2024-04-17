class Personality{
private:
    int lambda;
    double positiveEmotionThreshold;
    double negativeEmotionThreshold;
public:
    Personality(){}
    Personality(int l, double p, double n): lamda(l), positiveEmotionThreshold(p), negativeEmotionThreshold(n){
        
    }
    void setLambda(int l){
        lambda = l;
    }
    int getLambdad(){
        return lambda;
    }
    void setPositiveEmotionThreshold(double positiveEmotionThreshold){
        this->positiveEmotionThreshold = positiveEmotionThreshold;
    }
    double getPositiveEmotionThreshold(){
        return positiveEmotionThreshold;
    }
    void setNegativeEmotionThreshold(double negativeEmotionThreshold){
        this->negativeEmotionThreshold = negativeEmotionThreshold;
    }
    double getNegativeEmotionThreshold(){
        return negativeEmotionThreshold;
    }
};
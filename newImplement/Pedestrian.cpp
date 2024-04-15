#pragma once
#include "Ward.cpp";
#include "Personality.cpp";
#include "Event.cpp";
#include "Point.cpp";
#include "Emotion.cpp";
#include "AGVEvent.cpp";
#include <vector>

enum Walkability {
    noDisability,
    crutches,
    sticks,
    wheelchairs,
    blind
};

class Pedestrian{
private:
    int ID;
    Ward start;
    Ward end;
    std::vector <Ward> journey;
    double velocity;
    Personality personality;
    Emotion emotion;
    std::vector <Event> events;
    double walkingTime;
    double distance;
    double age;
    AGVEvent impactOfAGV;
    Point tempPoints;
public:
    virtual std::string getType() const = 0;
    int getID(){  
        return ID;
    }
    void setID(int id){
        ID = id;
    }
    Ward getStart(){
        return start;
    }
    Ward getEnd(){
        return end;
    }
    void setStart(const Ward& s){
        start = s;
    }
    void setEnd(const Ward& e){
        end = e;
    }
    // Setter và getter cho journey
  void setJourney(const std::vector<Ward>& journeyPath) {
    journey = journeyPath;
  }
  std::vector<Ward> getJourney() const {
    return journey;
  }

  // Setter và getter cho velocity
  void setVelocity(double speed) {
    velocity = speed;
  }
  double getVelocity() const {
    return velocity;
  }

  // Setter và getter cho personality
  void setPersonality(const Personality& pers) {
    personality = pers;
  }
  Personality getPersonality() const {
    return personality;
  }

  // Setter và getter cho emotion
  void setEmotion(const Emotion& emot) {
    emotion = emot;
  }
  Emotion getEmotion() const {
    return emotion;
  }

  // Setter và getter cho events
  void setEvents(const std::vector<Event>& evts) {
    events = evts;
  }
  std::vector<Event> getEvents() const {
    return events;
  }
  void setWalkingTime(double time) {
    walkingTime = time;
  }
  double getWalkingTime() const {
    return walkingTime;
  }

  // Setter và getter cho distance
  void setDistance(double dist) {
    distance = dist;
  }
  double getDistance() const {
    return distance;
  }

  // Setter và getter cho age
  void setAge(double ageValue) {
    age = ageValue;
  }
  double getAge() const {
    return age;
  }

  // Setter và getter cho impactOfAGV
  void setImpactOfAGV(const AGVEvent& agvEvent) {
    impactOfAGV = agvEvent;
  }
  AGVEvent getImpactOfAGV() const {
    return impactOfAGV;
  }

  // Setter và getter cho tempPoints
  void setTempPoints(const std::vector<Point>& points) {
    tempPoints = points;
  }
  std::vector<Point> getTempPoints() const {
    return tempPoints;
  }
  
  Json::Value toJSON() const {
        Json::Value pedestrianJson;
        pedestrianJson["ID"] = ID;

        return pedestrianJson;
    }
};
#pragma once
#include <fstream>
#include <random>
#include "object/Pedestrian.cpp"
#include "object/Visitor.cpp"
#include "object/Personel.cpp"
#include "object/Patient.cpp"
#include <cstdlib>
#include <ctime>
#include <json/json.h>
#include <vector>
void bai3(){
    srand(time(NULL));
    json inputJson;
    int numNoDisability = 0;
    int numPersonel = 0;
    


    inputJson = int(inputData["numOfAgents"]["value"]);
    int M = inputJson;
    int numOfAgents = inputJson;
    vector<Pedestrian*> pedestrians(numOfAgents);
    for (int i=0;i<numOfAgents;++i){
        pedestrians[i]->id = i; // gan id
        // random nguoi di chuyen la personel, visitor hay patient
        int randomNumber = rand() % 3 + 1;
        if (randomNumber == 1) {
            // personel luon < Nodisability
            // còn yếu tố không có personel nào có tuổi dưới 23 và có tuổi trên 61
            // chỉnh lại sau khi cài đặt về age
            
                pedestrians[i] = new Personel();
                ++numPersonel;
        }
        else if (randomNumber == 2) {
            pedestrians[i] = new Visitor();
            // cai dat start va end
            //Ward temp = new Ward
            pedestrian[i]->setStart();
        }
        else {
            pedestrians[i] = new Patient();
        }
        // cai dat Ward start cho pedestrian
        
        // cai dat walkability
        if (pedestrians[i]->getType() == "Personel") {
            randomNumber = rand() % 2;
            pedestrians[i]->setWalkability(randomNumber? noDisabilityNoOvertaking:noDisabilityOvertaking);
            ++numNoDisability;
        }
        else {
            // chưa đúng cách sinh giá trị ngẫu nhiên
            // phải dựa vào mã python của thầy
            randomNumber = rand() % 6 ;
            if (randomNumber == 0 || randomNumber == 1) ++numNoDisability;
            pedestrians[i]->setWalkability = static_cast<Walkability>(randomNumber);
        }
        // cai dat gia tri cam xuc emotion ban dau
        pedestrian[i]->emotion = new Emotion();
        // cai dat veclocity 
        if (pedestrians[i]->getWalkability() == blind) {
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["blind"]["veclocity"]));
        }  
        if (pedestrians[i]->getWalkability() == wheelchairs) {
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["wheelchairs"]["veclocity"]));
        }
        if (pedestrians[i]->getWalkability() == sticks) {
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["sticks"]["veclocity"]));
        }
        if (pedestrians[i]->getWalkability() == crutches) {
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["crutches"]["veclocity"]));
        }
        if (pedestrians[i]->getWalkability() == noDisabilityNoOvertaking) {
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["noDisabilityNoOvertaking"]["veclocity"]));
        }
        if (pedestrians[i]->getWalkability() == noDisabilityOvertaking){
            pedestrians[i]->setVeclocity(double(inputData["walkability"]["noDisabilityOvertaking"]["veclocity"]));
        }
    }
    // cai dat Personality
    int *arrT = new int[numOfAgents]; // cap phat bo nho dong 
    do {  
        // random giữa 2 tính cách open và neurotic sao cho tỉ lệ cả 2 xấp xỉ 50%  
        // còn yếu tố không người nào dưới 11 tuổi có tính cách neurotic 
        // sau khi xong cài đặt dữ liệu về age sửa lại hàm random này.
        int countOpen = 0;
        int countNeurotic = 0;
        for (int i=0;i<numOfAgents;++i){
            int randomNumber = rand() % 2;
            arrT[i] = randomNumber;
            if (randomNumber == 0) countOpen++;
            if (randomNumber == 1) countNeurotic++;
        }
        double openRatio = (double)countOpen/numOfAgents *100;
        double neuroticRatio = (double)countNeurotic/numOfAgents *100;
        
    }while ( abs(openRatio-50) >= 5);
    for (int i=0;i<numOfAgents;++i){
        if (arrT[i] == 0){
            Personality p = new Personality(int(inputdata["personalityDistribution"]["distribution"]["open"]["lambda"]),
            double (inputdata["personalityDistribution"]["distribution"]["open"]["positiveEmotionThreshold"]),
            double (inputdata["personalityDistribution"]["distribution"]["open"]["negativeEmotionThreshold"]));
            pedestrians[i]->setPersonality(p);
        }
        else {
            Personality p = new Personality(int(inputdata["personalityDistribution"]["distribution"]["neurotic"]["lambda"]),
            double (inputdata["personalityDistribution"]["distribution"]["neurotic"]["positiveEmotionThreshold"]),
            double (inputdata["personalityDistribution"]["distribution"]["neurotic"]["negativeEmotionThreshold"]));
            pedestrians[i]->setPersonality(p);
        }
    }
    delete []arrT; // giai phong bo nho dong




    std::vector<Event> allEvents;
    std::vector<double> allTimeDistances;
    Pedestrians::vector<Event> event;
    for (int i=0; i<20; i++) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 19);
        int x=dis(gen);
        
        Event ev;
        ev.setIntensity(allEvent[x].getIntensity());
        ev.setTime(allEvent[x].getTime());
        ev.setTimeDistance(allTimeDistances[x]);
        event.emplace_back(ev);
    }

    std::ofstream outputFile("output.txt");

    for (const auto& pedestrian : pedestrians) {
        Json::StreamWriterBuilder builder;
        builder["indentation"] = "";
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(pedestrian.toJSON(), &outputFile);
        outputFile << std::endl;
    }

    outputFile.close();
    std::cout << "Successfully wrote JSON data to file." << std::endl;
}

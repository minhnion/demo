#pragma once
#include <fstream>
#include <random>
#include "Pedestrian.cpp"
#include "Visitor.cpp"
#include "Personel.cpp"
#include "Patient.cpp"
#include <cstdlib>
#include <ctime>
#include <json/json.h>
#include <vector>
void bai3(){
    srand(time(NULL));
    json inputJson;
    int numNoDisability = 0;
    int numPersonel = 0;
    int numNoDisability = 0;
    
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
            if (i==numOfAgents-1 && numPersonel == numNoDisability) randomNumber = rand() % 2 + 2; 
            else {
                pedestrians[i] = new Personel();
                ++numPersonel;
            }
        }
        if (randomNumber == 2) {
            pedestrians[i] = new Visitor();
            // cai dat start va end
            //Ward temp = new Ward
            pedestrian[i]->setStart();
        }
        if(randomNumber == 3){
            pedestrians[i] = new Patient();
        }
        // cai dat Ward start cho pedestrian
        
        // cai dat walkability
        if (pedestrians[i]->getType() == "Personel") {
            pedestrians[i]->setWalkability(noDisability);
            ++numNoDisability;
        }
        else {
            // chưa đúng cách sinh giá trị ngẫu nhiên
            // phải dựa vào mã python của thầy
            randomNumber = rand() % 5 ;
            if (randomNumber == 0) ++numNoDisability;
            pedestrians[i]->setWalkability = static_cast<Walkability>(randomNumber);
        }
        // cai dat gia tri cam xuc emotion ban dau
        pedestrian[i]->emotion = new Emotion();
        // cai dat veclocity
        if (pedestrians[i]->getWalkability() == blind) {
            pedestrians[i]->veclocity = double(inputData["walkability"]["blind"]["veclocity"]);
        }  
        if (pedestrians[i]->getWalkability() == wheelchairs) {
            pedestrians[i]->veclocity = double(inputData["walkability"]["wheelchairs"]["veclocity"]);
        }
        if (pedestrians[i]->getWalkability() == sticks) {
            pedestrians[i]->veclocity = double(inputData["walkability"]["crutche"]["veclocity"]);
        }
        if (pedestrians[i]->getWalkability() == noDisability) {
            // noDisability co the lay input tu noDisabilityNoOvertaking hoac noDisabilityOvertaking
            pedestrians[i]->veclocity = double(inputData["walkability"]["noDisabilityNoOvertaking"]["veclocity"]);
        }
    }
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
    // cài đặt các thông số liên quan đến tính cách
    for (int i=0;i<numOfAgents;++i){
        if (arrT[i] == 0){
            pedestrians[i]->person = 
            new Personality(int(inputdata["personalityDistribution"]["distribution"]["open"]["lambda"]),
            double (inputdata["personalityDistribution"]["distribution"]["open"]["positiveEmotionThreshold"]),
            double (inputdata["personalityDistribution"]["distribution"]["open"]["negativeEmotionThreshold"]) );
        }
        else {
            pedestrians[i]->person = 
            new Personality(int(inputdata["personalityDistribution"]["distribution"]["neurotic"]["lambda"]),
            double (inputdata["personalityDistribution"]["distribution"]["neurotic"]["positiveEmotionThreshold"]),
            double (inputdata["personalityDistribution"]["distribution"]["neurotic"]["negativeEmotionThreshold"]));
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
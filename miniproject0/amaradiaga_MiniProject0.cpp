#include "amaradiaga_MiniProject0.hpp"

/*
Name: Anya Maradiaga
Date: 02/18/22
Description: The following file defines the functions from header file and creates program entry point
*/

int::Hacking::TimeHacking::setTimeToHack(int seconds){
    this -> time_to_hack =seconds;
}

int Hacking::TimeHacking::getTimeToHack(){
	return (this-> time_to_hack);
}

string Hacking::TimeHacking::getObjectToHack(){
	return (this->objectToHack);
}

int Hacking::TimeHacking::hackTime(){
    sleep(time_to_hack);
}

int main(){

	std::cout << "What object do you want to hack?\n";
	std::string object_tohack;
	std::getline(std::cin, object_tohack); //get object to hack

    int time_to_hack; 
    std::cout << "How many seconds do you want to hack this object for?\n";
    std::cin >> time_to_hack; //get time to hack

    Hacking::TimeHacking TimeHacking(object_tohack); 
    
    TimeHacking.setTimeToHack(time_to_hack); //set time to hack
    object_tohack = TimeHacking.getObjectToHack(); //get object to hack
    TimeHacking.getTimeToHack(); //get time to hack; 

    std::cout << "\n--- The User Input:" << object_tohack <<","<< time_to_hack<< "The hacking is in progress..."<< TimeHacking.hackTime()<<"\n\n";
    


}
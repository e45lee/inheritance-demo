#include <string>
#include <iostream>
#include <vector>
using namespace std;

class PassengerTrain {
private:
  std::string from;
  std::string destination;
  std::vector<std::string> intermediates;
  
  int speed;
  int passengers;
public:
  PassengerTrain(std::string from, std::string destination, int passengers)
    : from(from), destination(destination), passengers(passengers) {}

  void Stop() { speed = 0; }
  void Go() { speed = 60; }
  void PrintStatus() {
    cout << "Speed: " << speed << endl;
    cout << "From: " << from << endl;
    cout << "Destination: " << destination << endl;
  }
};

class FreightTrain {
private:
  std::string from;
  std::string destination;
  std::vector<std::string> intermediates;

  int speed;
  std::string cargo;
public:
  FreightTrain(std::string from, std::string destination, std::string cargo)
    : from(from), destination(destination), cargo(cargo) {}
  void Stop() { speed = 0; }
  void Go() { speed = 60; }
  void PrintStatus() {
    cout << "Speed: " << speed << endl;
    cout << "From: " << from << endl;
    cout << "Destination: " << destination << endl;
  }
};

class HighSpeedTrain {
private:
  int speed;
  int passengers;
  std::string from;
  std::string destination;
  
public:
  HighSpeedTrain(std::string from, std::string destination, int passengers)
    : from(from), destination(destination), passengers(passengers) {}
  void Stop() { speed = 0; }
  void Go() { speed = 60; }
  void PrintStatus() {
    cout << "Speed: " << speed << endl;
    cout << "From: " << from << endl;
    cout << "Destination: " << destination << endl;
  }
};


struct Train {
  enum {Passenger, Freight, HighSpeed} type;
  union {
    PassengerTrain* passengerTrain;
    FreightTrain* freightTrain;
    HighSpeedTrain* highSpeedTrain;
  };
};


void PrintStatus(Train* train) {
  switch (train->type) {
  case Train::Passenger:
    train->passengerTrain->PrintStatus();
    break;
  case Train::Freight:
    train->freightTrain->PrintStatus();
    break;
  case Train::HighSpeed:
    train->highSpeedTrain->PrintStatus();
    break;
  }
}


void PrintStatusV(void* train) {
  // What sort of train do we have?  Oh well...​
  ((PassengerTrain*)train)->PrintStatus();
}

int main() {
  HighSpeedTrain t {"Waterloo", "Toronto", 100};
  PrintStatusV(&t);
  return 0;
}

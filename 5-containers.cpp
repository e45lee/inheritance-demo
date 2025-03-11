#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Train {
private:
  std::string from;
  std::string destination;
  int speed;

public:
  void Stop() { speed = 0; }
  void Go() { speed = 60; }
  void PrintStatus() {
    cout << "Speed: " << speed << endl;
    cout << "From: " << from << endl;
    cout << "Destination: " << destination << endl;
  }
};

class PassengerTrain : public Train {
private:
  int passengers;
public:
};

class FreightTrain : public Train {
private:
  std::string cargo;
public:
};

class HighSpeedTrain : public Train {
private:
  int passengers;
public:
};

class RailYard {
public:
  std::vector<Train*> trains;
};

int main() {
  RailYard yard;
  yard.trains.push_back(new PassengerTrain);
  yard.trains.push_back(new FreightTrain);
  yard.trains.push_back(new HighSpeedTrain);
  for (auto train : yard.trains) {
      train->PrintStatus();
  }

  return 0;
}
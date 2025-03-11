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
  Train(const std::string& from, const std::string& destination) :
    from(from), destination(destination) {}
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
  PassengerTrain(const std::string& from, const std::string& destination, int passengers) :
    Train(from, destination), passengers(passengers) {}
};

class FreightTrain : public Train {
private:
  std::string cargo;
public:
  FreightTrain(const std::string& from, const std::string& destination, const std::string& cargo) :
    Train(from, destination), cargo(cargo) {}
};

class HighSpeedTrain : public Train {
private:
  int passengers;
public:
  HighSpeedTrain(const std::string& from, const std::string& destination, int passengers) :
    Train(from, destination), passengers(passengers) {}
};

class RailYard {
public:
  std::vector<Train*> trains;
};

int main() {
  RailYard yard;
  yard.trains.push_back(new PassengerTrain {"Chicago", "New York", 100});
  yard.trains.push_back(new FreightTrain {"Chicago", "Los Angeles", "Coal"});
  yard.trains.push_back(new HighSpeedTrain {"Chicago", "Miami", 200});
  for (auto train : yard.trains) {
      train->PrintStatus();
  }

  return 0;
}
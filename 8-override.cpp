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
  int speedLimit() const { return 60; }
};

class PassengerTrain : public Train {
private:
  int passengers;
public:
  PassengerTrain(const std::string& from, const std::string& destination, int passengers) :
    Train(from, destination), passengers(passengers) {}
  int speedLimit() const { return 100; }
};

class FreightTrain : public Train {
private:
  std::string cargo;
public:
  FreightTrain(const std::string& from, const std::string& destination, const std::string& cargo) :
    Train(from, destination), cargo(cargo) {}
  int speedLimit() const { return 80; }
};

class HighSpeedTrain : public Train {
private:
  int passengers;
public:
  HighSpeedTrain(const std::string& from, const std::string& destination, int passengers) :
    Train(from, destination), passengers(passengers) {}
  int speedLimit() const { return 500; }
};

int main() {
  HighSpeedTrain h {"Toronto", "Waterloo", 1000};
  PassengerTrain t {"Waterloo", "Toronto", 1000};
  FreightTrain f {"Toronto", "Waterloo", "Coal"};
  cout << h.speedLimit() << endl;
  cout << t.speedLimit() << endl;
  cout << f.speedLimit() << endl;
  return 0;
}
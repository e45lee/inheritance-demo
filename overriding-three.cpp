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
  virtual void Stop() { speed = 0; }
  virtual void Go() { speed = 60; }
  virtual void PrintStatus() {
    cout << "Speed: " << speed << endl;
    cout << "From: " << from << endl;
    cout << "Destination: " << destination << endl;
  }
  virtual int speedLimit() const { return 60; }
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
  int speedLimit() const { return 60; }
};

class HighSpeedTrain : public Train {
private:
  int passengers;
public:
  HighSpeedTrain(const std::string& from, const std::string& destination, int passengers) :
    Train(from, destination), passengers(passengers) {}
  int speedLimit() const { return 50; }
};

void printTrackTime(Train *t, int tracklength) {
  std::cout << "Time to travel " << 
    tracklength << " miles of track is " <<
    tracklength / (float)t->speedLimit() << 
    " hours" << std::endl;
}

int main() {
  PassengerTrain t {"Waterloo", "Toronto", 180};
  printTrackTime(&t, 180);
  return 0;
}
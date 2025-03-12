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

class LightRailTrain : public Train {
public:
  LightRailTrain(const std::string& from, const std::string& destination) :
    Train(from, destination) {}};

int main() {
  LightRailTrain l {"St. George", "Scarborough"};
  cout << l.speedLimit() << endl;
  return 0;
}
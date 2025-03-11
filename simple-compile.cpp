#include <string>
#include <string>
using namespace std;

class Train {
private:
  string from;
  string to;
public:
  int speedLimit() { return 60; }
  void go() {}
};

int main() {
  Train* t = new Train();
  return t->speedLimit();
}

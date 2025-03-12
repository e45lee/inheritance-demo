#include <string>
#include <string>
using namespace std;

class Train {
private:
  string from;
  string to;
public:
  int speedLimit();
};

int Train::speedLimit() { return 60; }
int main() {
  Train* t = new Train();
  return t->speedLimit();
}

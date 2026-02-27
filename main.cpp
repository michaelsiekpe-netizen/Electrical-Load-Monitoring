#include <iostream>
using namespace std;

class Appliance {
private:
    string name;
    float powerRating;
    float usageHours;

public:
    Appliance(string n, float p, float u) {
        name = n;
        powerRating = p;
        usageHours = u;
    }

    void display() {
        cout << "Appliance Name: " << name << endl;
        cout << "Power Rating (W): " << powerRating << endl;
        cout << "Usage Hours per Day: " << usageHours << endl;
    }
};

int main() {

    Appliance a1("Fan", 75, 5);
    a1.display();

    return 0;
}
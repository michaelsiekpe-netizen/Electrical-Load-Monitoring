
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
        cout << "\nAppliance Details\n";
        cout << "Name: " << name << endl;
        cout << "Power (W): " << powerRating << endl;
        cout << "Hours/Day: " << usageHours << endl;
    }
};

int main() {

    string name;
    float power, hours;

    cout << "Enter appliance name: ";
    cin >> name;

    cout << "Enter power rating (W): ";
    cin >> power;

    cout << "Enter usage hours per day: ";
    cin >> hours;

    Appliance a1(name, power, hours);
    a1.display();

    return 0;
}
#include <iostream>
#include <vector>
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
        cout << "\nName: " << name
             << " | Power: " << powerRating
             << "W | Hours: " << usageHours << endl;
    }
};

int main() {

    vector<Appliance> appliances;

    int n;
    cout << "How many appliances? ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string name;
        float power, hours;

        cout << "\nEnter appliance name: ";
        cin >> name;

        cout << "Enter power rating (W): ";
        cin >> power;

        cout << "Enter usage hours/day: ";
        cin >> hours;

        appliances.push_back(Appliance(name, power, hours));
    }

    cout << "\n--- Appliance List ---\n";

    for (Appliance a : appliances)
        a.display();

    return 0;
}
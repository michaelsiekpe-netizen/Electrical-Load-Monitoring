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
        cout << "Name: " << name
             << " | Power: " << powerRating
             << "W | Hours: " << usageHours << endl;
    }
};

vector<Appliance> appliances;

void registerAppliance() {

    string name;
    float power, hours;

    cout << "Enter appliance name: ";
    cin >> name;

    cout << "Enter power rating (W): ";
    cin >> power;

    cout << "Enter usage hours/day: ";
    cin >> hours;

    appliances.push_back(Appliance(name, power, hours));

    cout << "Appliance added successfully.\n";
}

void viewAppliances() {

    if (appliances.empty()) {
        cout << "No appliances available.\n";
        return;
    }

    for (Appliance a : appliances)
        a.display();
}

int main() {

    int choice;

    do {
        cout << "\n1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerAppliance();
            break;
        case 2:
            viewAppliances();
            break;
        case 3:
            cout << "Goodbye\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 3);

    return 0;
}
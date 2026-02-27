#include <iostream>
#include <vector>
#include <iomanip>
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

    float calculateEnergy() {
        return (powerRating * usageHours) / 1000.0;
    }

    void display() {
        cout << left << setw(15) << name
             << setw(12) << powerRating
             << setw(12) << usageHours
             << setw(12) << calculateEnergy() << endl;
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
}

void viewAppliances() {

    if (appliances.empty()) {
        cout << "No appliances available.\n";
        return;
    }

    cout << left << setw(15) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours"
         << setw(12) << "Energy(kWh)" << endl;

    for (Appliance a : appliances)
        a.display();
}

float calculateTotalEnergy() {

    float total = 0;

    for (Appliance a : appliances)
        total += a.calculateEnergy();

    return total;
}

int main() {

    int choice;

    do {
        cout << "\n1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Calculate Total Energy\n";
        cout << "4. Exit\n";
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
            cout << "Total Energy: "
                 << calculateTotalEnergy()
                 << " kWh\n";
            break;
        case 4:
            cout << "Goodbye\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}

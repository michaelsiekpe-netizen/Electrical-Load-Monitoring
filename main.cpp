#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// File storage
const string FILE_NAME = "appliances.txt";

// Appliance Class
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

    string getName() {
        return name;
    }

    float getPower() {
        return powerRating;
    }

    float getHours() {
        return usageHours;
    }

    // Energy calculation
    float calculateEnergy() {
        return (powerRating * usageHours) / 1000.0;
    }
};

// Store appliances
vector<Appliance> appliances;

// Register appliance
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

// View appliances (Updated with energy column)
void viewAppliances() {

    if (appliances.empty()) {
        cout << "No appliances available.\n";
        return;
    }

    cout << "\nAppliance List\n";

    cout << left << setw(15) << "Name"
         << setw(12) << "Power(W)"
         << setw(12) << "Hours"
         << setw(12) << "Energy(kWh)" << endl;

    for (Appliance a : appliances) {
        cout << left << setw(15) << a.getName()
             << setw(12) << a.getPower()
             << setw(12) << a.getHours()
             << setw(12) << a.calculateEnergy() << endl;
    }
}

// Calculate total energy
float calculateTotalEnergy() {

    float total = 0;

    for (Appliance a : appliances)
        total += a.calculateEnergy();

    return total;
}

// Billing calculation
void calculateBilling() {

    float tariff;

    cout << "Enter tariff per kWh: ";
    cin >> tariff;

    float totalEnergy = calculateTotalEnergy();
    float cost = totalEnergy * tariff;

    cout << "\nBilling Summary\n";
    cout << "Total Energy: " << totalEnergy << " kWh\n";
    cout << "Tariff: " << tariff << endl;
    cout << "Total Cost: " << cost << endl;
}

// Save appliances
void saveAppliances() {

    ofstream file(FILE_NAME);

    for (Appliance a : appliances) {

        file << a.getName() << " "
             << a.getPower() << " "
             << a.getHours() << endl;
    }

    file.close();
}

// Load appliances
void loadAppliances() {

    ifstream file(FILE_NAME);

    string name;
    float power, hours;

    while (file >> name >> power >> hours)
        appliances.push_back(Appliance(name, power, hours));

    file.close();
}

// MAIN FUNCTION
int main() {

    // Load saved data
    loadAppliances();

    int choice;

    do {

        cout << "\n===== SMART ENERGY SYSTEM =====\n";
        cout << "1. Register Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Calculate Total Energy\n";
        cout << "4. Calculate Billing\n";
        cout << "5. Exit\n";

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
            calculateBilling();
            break;

        case 5:
            saveAppliances();
            cout << "Goodbye\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Planet {
private:
    string name;
    double distance;
    static int count;

public:
    Planet(string n, double d) : name(n), distance(d) {
        count++;
    }

    void display() const {
        cout << "Planet: " << name
             << " | Distance from Sun: " << distance
             << " million km\n";
    }

    static int getCount() {
        return count;
    }
};

int Planet::count = 0;

int main() {
    vector<Planet> planets;

    int n;

    cout << "=== Space Explorer ===\n";

    cout << "How many planets do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        double distance;

        cout << "\nEnter planet " << i + 1 << " name: ";
        cin >> name;

        cout << "Enter distance from Sun: ";
        cin >> distance;

        planets.push_back(Planet(name, distance));
    }

    cout << "\n=== Planet List ===\n";

    for (int i = 0; i < planets.size(); i++) {
        cout << i + 1 << ". ";
        planets[i].display();
    }

    int choice;

    cout << "\nChoose a planet number: ";
    cin >> choice;

    if (choice >= 1 && choice <= planets.size()) {
        cout << "\nSelected planet:\n";
        planets[choice - 1].display();
    }
    else {
        cout << "Invalid choice.\n";
    }

    cout << "\nTotal planets: " << Planet::getCount() << '\n';

    return 0;
}

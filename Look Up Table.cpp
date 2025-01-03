#include <iostream>
#include <string>
using namespace std;

struct data {
    string name;
    int rno;
    char div;
};

class lookuptable {
public:
    data Nithish;
    data Saideep;
    data Swajeet;
    data Pranav;
    data Chirag;
    data match(string input);
    void display(data d);
    void addData();
    lookuptable();
};

lookuptable::lookuptable() {
    bhoomika = {"Nithish", 528, 'E'};
    amogh = {"Saideep", 529, 'E'};
    saanvi = {"Swajeet", 509, 'E'};
    ramya = {"Pranav", 538, 'E'};
}

data lookuptable::match(string input) {
    if (input == bhoomika.name)
        return bhoomika;
    if (input == amogh.name)
        return amogh;
    if (input == saanvi.name)
        return saanvi;
    if (input == ramya.name)
        return ramya;

    return {"", 0, ' '};
}

void lookuptable::display(data d) {
    if (d.name != "") {
        cout << "Name: " << d.name << endl;
        cout << "Roll Number: " << d.rno << endl;
        cout << "Division: " << d.div << endl;
    } else {
        cout << "Data not found." << endl;
    }
}

void lookuptable::addData() {
    string name;
    int rno;
    char div;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rno;
    cout << "Enter Division: ";
    cin >> div;

    if (name == bhoomika.name) {
        bhoomika = {name, rno, div};
    } else if (name == amogh.name) {
        amogh = {name, rno, div};
    } else if (name == saanvi.name) {
        saanvi = {name, rno, div};
    } else if (name == ramya.name) {
        ramya = {name, rno, div};
    } else {
        cout << "Name not recognized. Data not added." << endl;
    }
}

int main() {
    lookuptable database;
    int choice;
    string input;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Data" << endl;
        cout << "2. Search Data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                database.addData();
                break;
            case 2:
                cin.ignore();
                cout << "Enter the name to search: ";
                getline(cin, input);
                database.display(database.match(input));
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

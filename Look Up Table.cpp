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
    Nithish = {"Nithish", 122, 'F'};
    Saideep = {"Saideep", 134, 'F'};
    Swajeet = {"Swajeet",132, 'F'};
    Pranav  = {"Pranav",157, 'F'};
    Chirag  = {"Chirag",102,'F'};
}

data lookuptable::match(string input) {
    if (input == Nithish.name)
        return Nithish;
    if (input == Saideep.name)
        return Saideep;
    if (input == Swajeet.name)
        return Swajeet;
    if (input == Pranav.name)
        return Pranav;
    if (input == Chirag.name)
        return Chirag;
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

    if (name == Nithish.name) {
        Nithish = {name, rno, div};
    } else if (name ==Saideep.name) {
        Saideep = {name, rno, div};
    } else if (name == Swajeet.name) {
        Swajeet = {name, rno, div};
    } else if (name ==Pranav.name) {
        Pranav = {name, rno, div};
    } else if (name ==Chirag.name) {
       Chirag = {name, rno, div};
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

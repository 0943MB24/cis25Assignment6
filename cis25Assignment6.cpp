#include <iostream> 
#include <fstream> 
#include <string> 
#include <algorithm>
using namespace std;

class Items {
public:
    string name = "";
    int quantity;

    void saveToFile() {
        ofstream out("items.txt");
        if (out.is_open()) {
            out << name << ", " << quantity << endl;
            out.close();
            cout << "\nItem 'Bread' saved to file. Exiting Program.." << endl;
        } else {
            cout << "\nUnable to open file for writing." << endl;
        }
    }
    void loadFromFile() {
        ifstream in("items.txt");
        if (in.is_open()) {
            string line;
            while (getline(in, line)) {
                cout << "\nFile Content: " << line << endl;
            }
            in.close();
                
            } else {
            cout << "\nUnable to open file for writing." << endl;
        }
    }
};

void displayMenu() {
    cout << "Save item 'Bread' to file or load item from file? \n\nTo save item, enter 'Save', \n\nEnter 'Load' to load item, \n\nOr enter 'Quit' to exit program.";
    cout << "\n\n";
}

    int main() {
        Items food;
        food.name = "Bread";
        food.quantity = 6;
        string option;

        do {
            displayMenu();
            cin >> option;
            transform(option.begin(), option.end(), option.begin(), ::tolower);

            if (option == "save") {
                food.saveToFile();
                return 0;

            } else if (option == "load") {
                food.loadFromFile();
                return 0;

            } else if (option == "quit") {
                cout << "\nQuitting Program..\n";

            } else {
                cout << "\nInvalid choice. Try again.\n\n\n";
            }

            } while (option != "quit");

        return 0;
}
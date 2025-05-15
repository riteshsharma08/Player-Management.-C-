#include <iostream>
#include <string>
using namespace std;

const int MAX = 12;

class Player {
public:
    int jerseyNumber;
    string name;
    int runs;
    int wickets;
    int matches;

    void input() {
        cout << "Enter Jersey Number: ";
        cin >> jerseyNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Runs: ";
        cin >> runs;
        cout << "Enter Wickets: ";
        cin >> wickets;
        cout << "Enter Matches Played: ";
        cin >> matches;
    }

    void display() const {
        cout << "Jersey: " << jerseyNumber
             << ", Name: " << name
             << ", Runs: " << runs
             << ", Wickets: " << wickets
             << ", Matches: " << matches << endl;
    }
};

Player players[MAX];
int playerCount = 0;

// Add Player
void addPlayer() {
    if (playerCount < MAX) {
        players[playerCount].input();
        playerCount++;
        cout << "Player added successfully.\n";
    } else {
        cout << "Player limit reached!\n";
    }
}

// Display All Players
void displayAll() {
    if (playerCount == 0) {
        cout << "No players to display.\n";
        return;
    }
    for (int i = 0; i < playerCount; i++) {
        players[i].display();
    }
}

// Search Player by Jersey or Name
void searchPlayer() {
    int choice;
    cout << "Search by: 1. Jersey Number  2. Name\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        int jersey;
        cout << "Enter Jersey Number: ";
        cin >> jersey;
        for (int i = 0; i < playerCount; i++) {
            if (players[i].jerseyNumber == jersey) {
                players[i].display();
                return;
            }
        }
    } else {
        string pname;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, pname);
        for (int i = 0; i < playerCount; i++) {
            if (players[i].name == pname) {
                players[i].display();
                return;
            }
        }
    }
    cout << "Player not found.\n";
}

// Remove Player by Jersey Number
void removePlayer() {
    int jersey;
    cout << "Enter Jersey Number to Remove: ";
    cin >> jersey;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jersey) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            cout << "Player removed successfully.\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

// Update Player Data
void updatePlayer() {
    int jersey;
    cout << "Enter Jersey Number to Update: ";
    cin >> jersey;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].jerseyNumber == jersey) {
            cout << "Enter new details:\n";
            players[i].input();
            cout << "Player updated successfully.\n";
            return;
        }
    }
    cout << "Player not found.\n";
}

// Display Top 3 Players by Runs and Wickets
void displayTop3() {
    if (playerCount < 3) {
        cout << "Not enough players to show top 3.\n";
        return;
    }

    // Sort by runs (descending)
    Player topRuns[3];
    Player temp[MAX];
    for (int i = 0; i < playerCount; i++) temp[i] = players[i];
    
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = i + 1; j < playerCount; j++) {
            if (temp[j].runs > temp[i].runs) {
                swap(temp[i], temp[j]);
            }
        }
    }

    cout << "\nTop 3 Players by Runs:\n";
    for (int i = 0; i < 3; i++) temp[i].display();

    // Sort by wickets (descending)
    for (int i = 0; i < playerCount - 1; i++) {
        for (int j = i + 1; j < playerCount; j++) {
            if (players[j].wickets > players[i].wickets) {
                swap(players[i], players[j]);
            }
        }
    }

    cout << "\nTop 3 Players by Wickets:\n";
    for (int i = 0; i < 3; i++) players[i].display();
}

// Menu
void menu() {
    int choice;
    do {
        cout << "\n--- Player Management System ---\n";
        cout << "1. Add Player\n2. Remove Player\n3. Search Player\n4. Update Player Data\n5. Display All Players\n6. Show Top 3 Players\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addPlayer(); break;
            case 2: removePlayer(); break;
            case 3: searchPlayer(); break;
            case 4: updatePlayer(); break;
            case 5: displayAll(); break;
            case 6: displayTop3(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

// Main
int main() {
    menu();
    return 0;
}


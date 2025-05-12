#include <iostream>         // For input/output operations
#include <vector>           // For using vector container
#include <string>           // For using string class
#include <cstdlib>          // For random functions and system calls
#include <ctime>            // For time function to seed random
#include <iomanip>          // For formatted output (not used directly here)
#include <utility>          // For using pair

using namespace std;

const int ROWS = 9;          // Number of rows in the seat grid
const int COLS = 9;          // Number of columns in the seat grid
const string PASSWORD = "2025"; // Default password for login
char seats[ROWS][COLS];     // 2D array to store seat status

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls");         // Windows command to clear screen
#else
    system("clear");       // Unix/Linux/Mac command to clear screen
#endif
}

// Initialize the seat grid and randomly fill 10 seats with '*'
void initSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-'; // Set all seats to available

    srand(time(0));             // Seed random generator
    int count = 0;
    while (count < 10) {        // Randomly book 10 seats
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*'; // Mark seat as booked
            count++;
        }
    }
}

// Display current seat layout, optionally with temporary '@' markings
void displaySeats(vector< pair<int, int> > temp = vector< pair<int, int> >()) {
    cout << "\\123456789\n"; // Column labels
    for (int i = ROWS - 1; i >= 0; i--) {
        cout << i + 1;          // Row labels
        for (int j = 0; j < COLS; j++) {
            bool marked = false;
            for (size_t k = 0; k < temp.size(); ++k) {
                if (temp[k].first == i && temp[k].second == j) {
                    cout << "@"; // Temporarily suggested seat
                    marked = true;
                    break;
                }
            }
            if (!marked) cout << seats[i][j]; // Show real seat status
        }
        cout << endl;
    }
}

// Login function to check password
bool login() {
    clearScreen();
    printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");
	printf("************************\n");
	printf("-----------------\n");

    int tries = 0;
    string input;
    while (tries < 3) {
        cout << "Enter 4-digit password: ";
        cin >> input;
        if (input == PASSWORD) {
            cout << "Access Granted!\n";
            return true; // Login successful
        } else {
            cout << "Incorrect password.\n";
            tries++;
        }
    }
    cout << "Too many failed attempts. Exiting.\n";
    return false; // Login failed
}

// Show the main menu
void showMenu() {
    cout << "----------[Booking System]----------\n";
    cout << "| a. Available seats               |\n";
    cout << "| b. Arrange for you              |\n";
    cout << "| c. Choose by yourself           |\n";
    cout << "| d. Exit                         |\n";
    cout << "------------------------------------\n";
    cout << "Choose option: ";
}

// Check if a seat is available
bool isAvailable(int row, int col) {
    return seats[row][col] == '-';
}

// Mark seats as booked
void bookSeats(vector< pair<int, int> > locations) {
    for (size_t i = 0; i < locations.size(); ++i)
        seats[locations[i].first][locations[i].second] = '*';
}

// Find consecutive available seats for automatic arrangement
vector< pair<int, int> > findConsecutive(int count) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - count; j++) {
            bool ok = true;
            for (int k = 0; k < count; k++) {
                if (seats[i][j + k] != '-') {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                vector< pair<int, int> > res;
                for (int k = 0; k < count; k++)
                    res.push_back(make_pair(i, j + k));
                return res; // Return consecutive seats
            }
        }
    }

    if (count == 4) { // Check 2x2 block for 4 seats
        for (int i = 0; i < ROWS - 1; i++) {
            for (int j = 0; j < COLS - 1; j++) {
                if (seats[i][j] == '-' && seats[i][j+1] == '-' &&
                    seats[i+1][j] == '-' && seats[i+1][j+1] == '-') {
                    vector< pair<int, int> > res;
                    res.push_back(make_pair(i, j));
                    res.push_back(make_pair(i, j+1));
                    res.push_back(make_pair(i+1, j));
                    res.push_back(make_pair(i+1, j+1));
                    return res;
                }
            }
        }
    }
    return vector< pair<int, int> >(); // Return empty if not found
}

// Handle automatic seat arrangement option
void optionB() {
    int count;
    cout << "How many seats do you need? (1-4): ";
    cin >> count;
    if (count < 1 || count > 4) {
        cout << "Invalid number.\n";
        return;
    }

    vector< pair<int, int> > result = findConsecutive(count);
    if (result.empty()) {
        cout << "No suitable seats available.\n";
        return;
    }

    displaySeats(result); // Show suggested seats
    char confirm;
    cout << "Do you accept these seats? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        bookSeats(result);
        clearScreen();
    } else {
        cout << "Returning to menu...\n";
    }
}

// Handle manual seat selection option
void optionC() {
    int count;
    cout << "How many seats to choose (1-4): ";
    cin >> count;

    vector< pair<int, int> > chosen;
    for (int i = 0; i < count; i++) {
        string input;
        cout << "Enter seat (row-col): ";
        cin >> input;

        if (input.find('-') == string::npos || input.size() < 3) {
            cout << "Invalid format!\n";
            return;
        }

        int row = input[0] - '1'; // Convert char to int
        int col = input[2] - '1';
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            cout << "Out of range.\n";
            return;
        }
        if (!isAvailable(row, col)) {
            cout << "Seat already taken.\n";
            return;
        }
        chosen.push_back(make_pair(row, col));
    }

    displaySeats(chosen); // Show selected seats
    cout << "Press enter to confirm.\n";
    cin.ignore(); cin.get();
    bookSeats(chosen);
    clearScreen();
}

// Handle exit option with confirmation
bool optionD() {
    char confirm;
    while (true) {
        cout << "Continue? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') return true;
        else if (confirm == 'n' || confirm == 'N') return false;
        else cout << "Invalid input.\n";
    }
}

// Main function
int main() {
    initSeats();                 // Initialize the seat layout
    if (!login()) return 0;     // Login check

    while (true) {
        showMenu();             // Show main menu
        char choice;
        cin >> choice;
        clearScreen();

        if (choice == 'a' || choice == 'A') {
            displaySeats();     // Show seat layout
            cout << "Press enter to return.\n";
            cin.ignore(); cin.get();
            clearScreen();
        } else if (choice == 'b' || choice == 'B') {
            optionB();          // Auto arrange seats
        } else if (choice == 'c' || choice == 'C') {
            optionC();          // Manual seat selection
        } else if (choice == 'd' || choice == 'D') {
            if (!optionD()) break; // Exit confirmation
            clearScreen();
        } else {
            cout << "Invalid option.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}


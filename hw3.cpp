#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>

using namespace std;

const int ROWS = 9;
const int COLS = 9;
const string PASSWORD = "2025";
char seats[ROWS][COLS];

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void initSeats() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = '-';

    srand(time(0));
    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

void displaySeats(vector< pair<int, int> > temp = vector< pair<int, int> >()) {
    cout << "\\123456789\n";
    for (int i = ROWS - 1; i >= 0; i--) {
        cout << i + 1;
        for (int j = 0; j < COLS; j++) {
            bool marked = false;
            for (size_t k = 0; k < temp.size(); ++k) {
                if (temp[k].first == i && temp[k].second == j) {
                    cout << "@";
                    marked = true;
                    break;
                }
            }
            if (!marked) cout << seats[i][j];
        }
        cout << endl;
    }
}

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
            return true;
        } else {
            cout << "Incorrect password.\n";
            tries++;
        }
    }
    cout << "Too many failed attempts. Exiting.\n";
    return false;
}

void showMenu() {
    cout << "----------[Booking System]----------\n";
    cout << "| a. Available seats               |\n";
    cout << "| b. Arrange for you              |\n";
    cout << "| c. Choose by yourself           |\n";
    cout << "| d. Exit                         |\n";
    cout << "------------------------------------\n";
    cout << "Choose option: ";
}

bool isAvailable(int row, int col) {
    return seats[row][col] == '-';
}

void bookSeats(vector< pair<int, int> > locations) {
    for (size_t i = 0; i < locations.size(); ++i)
        seats[locations[i].first][locations[i].second] = '*';
}

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
                return res;
            }
        }
    }

    if (count == 4) {
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
    return vector< pair<int, int> >();
}

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

    displaySeats(result);
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

        int row = input[0] - '1';
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

    displaySeats(chosen);
    cout << "Press enter to confirm.\n";
    cin.ignore(); cin.get();
    bookSeats(chosen);
    clearScreen();
}

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

int main() {
    initSeats();
    if (!login()) return 0;

    while (true) {
        showMenu();
        char choice;
        cin >> choice;
        clearScreen();

        if (choice == 'a' || choice == 'A') {
            displaySeats();
            cout << "Press enter to return.\n";
            cin.ignore(); cin.get();
            clearScreen();
        } else if (choice == 'b' || choice == 'B') {
            optionB();
        } else if (choice == 'c' || choice == 'C') {
            optionC();
        } else if (choice == 'd' || choice == 'D') {
            if (!optionD()) break;
            clearScreen();
        } else {
            cout << "Invalid option.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}

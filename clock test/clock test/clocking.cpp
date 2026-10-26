/**
        Eric J. Saavedra
		Program for Clocking
**/



#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Stores the current time
unsigned int hour = 12;
unsigned int minute = 0;
unsigned int second = 0;

// Function declarations
unsigned int getHour();
unsigned int getMinute();
unsigned int getSecond();

void setHour(unsigned int h);
void setMinute(unsigned int m);
void setSecond(unsigned int s);

void addOneHour();
void addOneMinute();
void addOneSecond();

string nCharString(size_t n, char c);
string twoDigitString(unsigned int n);
string formatTime12(unsigned int h, unsigned int m, unsigned int s);
string formatTime24(unsigned int h, unsigned int m, unsigned int s);

void displayClocks(unsigned int h, unsigned int m, unsigned int s);
void printMenu(char* strings[], unsigned int numStrings,
    unsigned char width);

unsigned int getMenuChoice(unsigned int maxChoice);
void mainMenu();

int main() {
    mainMenu();
    return 0;
}

// Getter functions
unsigned int getHour() {
    return hour;
}

unsigned int getMinute() {
    return minute;
}

unsigned int getSecond() {
    return second;
}

// Setter functions
void setHour(unsigned int h) {
    hour = h;
}

void setMinute(unsigned int m) {
    minute = m;
}

void setSecond(unsigned int s) {
    second = s;
}

void mainMenu() {
    unsigned int choice = 0;

    char option1[] = "Add One Hour";
    char option2[] = "Add One Minute";
    char option3[] = "Add One Second";
    char option4[] = "Exit Program";

    char* menuOptions[] = {
        option1,
        option2,
        option3,
        option4
    };

    while (choice != 4) {
        displayClocks(getHour(), getMinute(), getSecond());
        cout << endl;

        printMenu(menuOptions, 4, 26);

        cout << "Enter your choice: ";
        choice = getMenuChoice(4);

        switch (choice) {
        case 1:
            addOneHour();
            break;

        case 2:
            addOneMinute();
            break;

        case 3:
            addOneSecond();
            break;

        case 4:
            cout << "Program finished." << endl;
            break;
        }

        cout << endl;
    }
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');

    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;

    cout << endl;

    cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');

    cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;

    cout << nCharString(27, '*')  << nCharString(3, ' ')  << nCharString(27, '*') << endl;
}

unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;

    while (true) {
        if (cin >> choice && choice >= 1 && choice <= maxChoice) {
            return choice;
        }

        // Reset cin after letters or invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a number from 1 to " << maxChoice << ": ";
    }
}

void printMenu(char* strings[], unsigned int numStrings, unsigned char width) { 
        
    cout << nCharString(width, '*') << endl;

    for (unsigned int i = 0; i < numStrings; i++) {
        string itemNumber = to_string(i + 1);
        string menuItem = strings[i];

        unsigned int usedSpace =
            2 + itemNumber.length() + 3 + menuItem.length() + 1;

        unsigned int spaces = width - usedSpace;

        cout << "* "  << itemNumber << " - "  << menuItem << nCharString(spaces, ' ') << "*"  << endl;

        if (i < numStrings - 1) {
            cout << endl;
        }
    }

    cout << nCharString(width, '*') << endl;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    
    string period = (h < 12) ? "A M" : "P M";

    unsigned int hour12 = h % 12;

    if (hour12 == 0) {
        hour12 = 12;
    }

    return twoDigitString(hour12) + ":" +  twoDigitString(m) + ":" + twoDigitString(s) + " " + period;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }

    return to_string(n);
}

string nCharString(size_t n, char c) {
    return string(n, c);
}

void addOneSecond() {
    if (getSecond() < 59) {
        setSecond(getSecond() + 1);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}

void addOneMinute() {
    if (getMinute() < 59) {
        setMinute(getMinute() + 1);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}

void addOneHour() {
    if (getHour() < 23) {
        setHour(getHour() + 1);
    }
    else {
        setHour(0);
    }
}
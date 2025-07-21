#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to authenticate login
bool authenticate(string inputName, string inputPassword, double inputIndex, string storedName, string storedPassword, double storedIndex) {
    return (inputName == storedName && inputPassword == storedPassword && inputIndex == storedIndex);
}

int main() {
    // Declaring variables
    int level;
    double signupIndex, loginIndex;
    string signupName, loginName;
    string signupPassword, loginPassword;
    string programme;
    char confirmation;
    char result;

    // User sign-up
    cout << " ENTER YOUR NAME: " << endl;
    getline(cin, signupName);

    cout << " ENTER YOUR PROGRAM: " << endl;
    getline(cin, programme);

    cout << " ENTER YOUR PASSWORD: " << endl;
    getline(cin, signupPassword);

    cout << " ENTER YOUR LEVEL: " << endl;
    cin >> level;

    cout << " ENTER YOUR INDEX NUMBER: " << endl;
    cin >> signupIndex;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Confirmation step
    cout << "ENTER Y TO CONFIRM OR Z TO CANCEL [Y/Z]: " << endl;
    cin >> confirmation;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmation == 'Y' || confirmation == 'y') {
        cout << "************ YOUR SIGN UP ON THE STUDENT PORTAL WAS SUCCESSFUL **********" << endl;
    } else {
        cout << "** YOUR SIGN UP WAS NOT SUCCESSFUL. EXITING... **" << endl;
        return 0;
    }

    cout << endl << "******** PLEASE LOGIN INTO THE GCTU PORTAL *************\n" << endl;

    // Login section
    cout << " ENTER STUDENT NAME: " << endl;
    getline(cin, loginName);

    cout << " ENTER PASSWORD: " << endl;
    getline(cin, loginPassword);

    cout << " ENTER STUDENT INDEX NUMBER: " << endl;
    cin >> loginIndex;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (!authenticate(loginName, loginPassword, loginIndex, signupName, signupPassword, signupIndex)) {
        cout << "Invalid User. Access denied." << endl;
        return 0;
    }

    cout << "\n" << signupName << " WELCOME TO GCTU STUDENT PORTAL\n\n";

    cout << "DO YOU WANT TO CHECK YOUR RESULT FOR THE SEMESTER? (G/X):" << endl;
    cin >> result;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (result == 'G' || result == 'g') {
        cout << "\n  COURSE                                GRADE" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << " FOUNDATION OF COMPUTER SECURITY        A" << endl;
        cout << " ENTERPRISE INFORMATION SYSTEM          A" << endl;
        cout << " INTRODUCTION TO IT LAWS                A" << endl;
        cout << " PROGRAMMING WITH C++                   A" << endl;
        cout << " OPERATIONAL FRENCH                     A" << endl;
        cout << " PROBABILITY AND STATISTICS             B" << endl;
    } else {
        cout << "Sorry, try again." << endl;
    }

    return 0;
}

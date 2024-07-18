#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// Class to represent a User
class User {
public:
    string firstName;
    string lastName;
    int age;
    string gender;

    // Constructors
    User() {};
    User(string firstName, string lastName, int age, string gender) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
        this->gender = gender;
    }
};

// Global maps to store users and friendships
map<string, User> mapUserName;              // Maps username to User object
map<string, set<string>> Friends;           // Maps a user to their set of friends

// Function to add a user to the map
void addUser(string userName, User user) {
    if (mapUserName.find(userName) == mapUserName.end()) {
        mapUserName[userName] = user;       // Add user if username doesn't already exist
    } else {
        cout << "UserName Already Taken";    // Print error message if username is already taken
    }
}

// Function to make two users friends with each other
void makeThemFriend(string userName1, string userName2) {
    Friends[userName1].insert(userName2);   // Insert userName2 into userName1's set of friends
    Friends[userName2].insert(userName1);   // Insert userName1 into userName2's set of friends
}

// Function to remove friendship between two users
void removeFriendship(string userName1, string userName2) {
    if (Friends.find(userName1) != Friends.end() && Friends[userName1].count(userName2)) {
        Friends[userName1].erase(userName2); // Remove userName2 from userName1's set of friends
    }
    if (Friends.find(userName2) != Friends.end() && Friends[userName2].count(userName1)) {
        Friends[userName2].erase(userName1); // Remove userName1 from userName2's set of friends
    }
}

// Function to display all users
void displayAllUser() {
    for (auto i : mapUserName) {
        cout << "UserName: " << i.first << " " << i.second.firstName << "\n";
    }
}

// Function to display all friendships
void displayAllFriendships() {
    for (auto i : Friends) {
        cout << i.first << ":\n";
        set<string> friends = i.second;
        for (auto j : friends) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

// Function to display menu and handle user choices
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Friend\n";
    cout << "2. Remove Friend\n";
    cout << "3. View Friends\n";
    cout << "4. View All Users\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// Main function where the program starts execution
int main() {
    // Prompt the user to enter details for three users
    for (int i = 0; i < 5; ++i) {
        string firstName, lastName, gender;
        int age;

        cout << "Enter details for User " << i + 1 << ":\n";
        cout << "First Name: ";
        cin >> firstName;
        cout << "Last Name: ";
        cin >> lastName;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;

        User newUser(firstName, lastName, age, gender);
        string userName = firstName;  // Using first name as username for simplicity
        addUser(userName, newUser);
    }

    // Displaying all users after adding them
    cout << "\nAll Users:\n";
    displayAllUser();

    int choice;
    string userName1, userName2;

    // Menu-driven loop
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter two usernames to add them as friends:\n";
                cin >> userName1 >> userName2;
                makeThemFriend(userName1, userName2);
                cout << "Friendship added.\n";
                break;
            case 2:
                cout << "\nEnter two usernames to remove their friendship:\n";
                cin >> userName1 >> userName2;
                removeFriendship(userName1, userName2);
                cout << "Friendship removed.\n";
                break;
            case 3:
                cout << "\nAll Friendships:\n";
                displayAllFriendships();
                break;
            case 4:
                cout << "\nAll Users:\n";
                displayAllUser();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 5);

    return 0;  // End of main function
}

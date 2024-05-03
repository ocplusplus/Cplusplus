#include <iostream>
#include "age_list.h"

using namespace std;


AgeList::AgeList() : head(nullptr) {}

AgeList::~AgeList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void AgeList::insertAge(int newAge) {
    Node* newNode = new Node{ newAge, nullptr };

    if (head == nullptr || newAge < head->age) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->age < newAge) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

void AgeList::deleteAge(int targetAge) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->age != targetAge) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr) {
            head = current->next;
        }
        else {
            previous->next = current->next;
        }
        delete current;
    }
}

bool AgeList::searchAge(int targetAge) {
    Node* current = head;

    while (current != nullptr) {
        if (current->age == targetAge) {
            return true; // Age found
        }
        current = current->next;
    }

    return false; // Age not found
}

void AgeList::displayList() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->age << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    AgeList friendsList;

    // Insert some initial ages
    friendsList.insertAge(30);
    friendsList.insertAge(25);
    friendsList.insertAge(35);
    friendsList.insertAge(20);

    // Display the initial list
    cout << "Initial List: ";
    friendsList.displayList();

    int option;
    do {
        // Display the option menu
        cout << "Select an option:\n";
        cout << "1. Search an age\n";
        cout << "2. Add an age\n";
        cout << "3. Delete an age\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
        case 1: {
            // Search for an age
            int searchAge;
            cout << "Enter an age to search: ";
            cin >> searchAge;

            if (friendsList.searchAge(searchAge)) {
                cout << searchAge << " found in the list." << endl;
            }
            else {
                cout << searchAge << " not found in the list." << endl;
            }
            break;
        }
        case 2: {
            // Allow the user to input a new age
            int newAge;
            cout << "Enter a new age to insert: ";
            cin >> newAge;
            friendsList.insertAge(newAge);

            // Display the list after insertion
            cout << "List after insertion: ";
            friendsList.displayList();
            break;
        }
        case 3: {
            // Prompt the user to enter an age to delete
            int deleteAge;
            bool ageDeleted = false;

            do {
                cout << "Enter an age to delete: ";
                cin >> deleteAge;

                if (friendsList.searchAge(deleteAge)) {
                    friendsList.deleteAge(deleteAge);
                    ageDeleted = true;
                    cout << "List after deletion: ";
                    friendsList.displayList();
                }
                else {
                    cout << deleteAge << " not found in the list. Please try again.\n";
                }

            } while (!ageDeleted);

            break;
        }
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (option != 0);

    return 0;
}

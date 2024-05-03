#include "Tax.h"

int main() {
    int selectedRegion;

    int option;
    float amount;

    while (true) {
        // Prompt for region selection
        cout << "\nSelect your region:\n";
        cout << "1. Region 1\n";
        cout << "2. Region 2\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 3) {
            cout << "Exiting program. Goodbye!\n";
            return 0;
        }

        if (option != 1 && option != 2) {
            cout << "Invalid option. Please enter 1, 2, or 3 for exit.\n";
            continue;
        }

        selectedRegion = option;

        CustomizedTax customizedTax(0.08, 0.05, 0.03, selectedRegion);

        cout << "\nMenu:\n";
        cout << "1. Calculate Tax\n";
        cout << "2. Calculate Amount After Tax\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the amount to calculate tax: ";
                cin >> amount;
                cout << "Tax calculated: " << customizedTax.taxCalc(amount) << endl;
                break;

            case 2:
                cout << "Enter the amount to calculate amount after tax: ";
                cin >> amount;
                cout << "Amount after tax: " << customizedTax.amountAfterTax(amount) << endl;
                break;

            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}

#include "clinic.h"

int main() {
    ClinicManagementSystem clinicSystem;

    int choice;

    do {
        clinicSystem.displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                clinicSystem.addPatient();
                break;
            case 2:
                clinicSystem.viewPatients();
                break;
            case 3:
                clinicSystem.addAppointment();
                break;
            case 4:
                clinicSystem.viewAppointments();
                break;
            case 5:
                clinicSystem.cancelAppointment();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
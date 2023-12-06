#include "clinic.h"
#include <algorithm> // Add this line
ClinicManagementSystem::ClinicManagementSystem() : patientCount(0), appointmentCount(0) {}

ClinicManagementSystem::~ClinicManagementSystem() {
    cleanupMemory();
}

void ClinicManagementSystem::displayMenu()
{
    cout << "\n=== Clinic Management System ===\n";
    cout << "1. Add Patient\n";
    cout << "2. View Patients\n";
    cout << "3. Add Appointment\n";
    cout << "4. View Appointments\n";
    cout << "5. Cancel Appointment\n";
    cout << "6. Exit\n";
}

void ClinicManagementSystem::addPatient()
{
    Patient newPatient;
    cout << "Enter patient name: ";
    cin >> newPatient.name;
    cout << "Enter patient address: ";
    cin >> newPatient.address;
    cout << "Enter patient phone number: ";
    cin >> newPatient.phone;

    newPatient.id = ++patientCount;
    patients.push_back(newPatient);

    cout << "Patient added successfully. ID: " << newPatient.id << endl;
}

void ClinicManagementSystem::viewPatients() {
    cout << "\n=== Patients List ===\n";
    cout << "ID\tName\tAddress\t\tPhone\n";

    for (const auto& patient : patients) {
        cout << patient.id << "\t" << patient.name << "\t" << patient.address << "\t" << patient.phone << endl;
    }
}

void ClinicManagementSystem::addAppointment() {
    Appointment newAppointment;
    cout << "Enter patient ID for appointment: ";
    cin >> newAppointment.patientId;
    cout << "Enter appointment date: ";
    cin >> newAppointment.date;
    cout << "Enter appointment time: ";
    cin >> newAppointment.time;

    newAppointment.id = ++appointmentCount;
    appointments.push_back(newAppointment);

    cout << "Appointment added successfully. ID: " << newAppointment.id << endl;
}

void ClinicManagementSystem::viewAppointments() {
    cout << "\n=== Appointments List ===\n";
    cout << "ID\tPatient ID\tDate\t\tTime\n";

    for (const auto& appointment : appointments) {
        cout << appointment.id << "\t" << appointment.patientId << "\t\t" << appointment.date << "\t" << appointment.time << endl;
    }
}

void ClinicManagementSystem::cancelAppointment() {
    int appointmentId;
    cout << "Enter the ID of the appointment to cancel: ";
    cin >> appointmentId;

    auto it = find_if(appointments.begin(), appointments.end(), [appointmentId](const Appointment& a) {
        return a.id == appointmentId;
    });

    if (it != appointments.end()) {
        appointments.erase(it);
        cout << "Appointment canceled successfully. ID: " << appointmentId << endl;
    } else {
        cout << "Appointment with ID " << appointmentId << " not found.\n";
    }
}

void ClinicManagementSystem::cleanupMemory() {
    patients.clear();
    appointments.clear();
}
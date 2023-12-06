#ifndef CLINIC_H
#define CLINIC_H

#include <iostream>
#include <vector>

using namespace std;

struct Patient {
    int id;
    string name;
    string address;
    string phone;
};

struct Appointment {
    int id;
    int patientId;
    string date;
    string time;
};

class ClinicManagementSystem {
public:
    ClinicManagementSystem();
    ~ClinicManagementSystem();

    void displayMenu();
    void addPatient();
    void viewPatients();
    void addAppointment();
    void viewAppointments();
    void cancelAppointment();
    void cleanupMemory();

private:
    vector<Patient> patients;
    vector<Appointment> appointments;
    int patientCount;
    int appointmentCount;
};

#endif // CLINIC_H
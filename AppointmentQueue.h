#ifndef APPOINTMENT_QUEUE_H
#define APPOINTMENT_QUEUE_H

#include "Appointment.h"
#include <iostream>
using namespace std;

class AppointmentQueue {
private:
    Appointment* front;
    Appointment* rear;
public:
    AppointmentQueue() {
        front = rear = nullptr;
    }

    void enqueue(int id, string name, string date, string time, string specialty) {
        Appointment* newApp = new Appointment(id, name, date, time, specialty);
        if (!rear) {
            front = rear = newApp;
            return;
        }
        rear->next = newApp;
        rear = newApp;
    }

    Appointment* dequeue() {
        if (!front) return nullptr;
        Appointment* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        return temp;
    }

    void displayQueue() {
        Appointment* temp = front;
        if (!temp) {
            cout << "\nNo appointments scheduled.\n";
            return;
        }
        cout << "\n===== Appointments Queue =====\n";
        while (temp) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Date: " << temp->date
                 << " | Time: " << temp->time
                 << " | Specialty: " << temp->specialty
                 << "\n";
            temp = temp->next;
        }
    }
};

#endif

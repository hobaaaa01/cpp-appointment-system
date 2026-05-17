#ifndef COMPLETED_LIST_H
#define COMPLETED_LIST_H

#include "Appointment.h"
#include <iostream>
using namespace std;

class CompletedList {
private:
    Appointment* head;

public:
    CompletedList() { head = nullptr; }

    void addCompleted(Appointment* app) {
        app->next = nullptr; // Detach from previous chain
        if (!head) {
            head = app;
        } else {
            Appointment* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = app;
        }
    }

    void displayCompleted() {
        if (!head) {
            cout << "\n✅ No completed appointments yet.\n";
            return;
        }

        cout << "\n===== Completed Appointments =====\n";
        Appointment* temp = head;
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

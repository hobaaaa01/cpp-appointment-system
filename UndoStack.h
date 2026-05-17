#ifndef UNDO_STACK_H
#define UNDO_STACK_H

#include "Appointment.h"
#include <iostream>
using namespace std;

class UndoStack {
private:
    Appointment* top;
public:
    UndoStack() { top = nullptr; }

    void push(Appointment* app) {
        app->next = top;
        top = app;
    }

    Appointment* pop() {
        if (!top) return nullptr;
        Appointment* temp = top;
        top = top->next;
        return temp;
    }

    void displayStack() {
        Appointment* temp = top;
        if (!temp) {
            cout << "Undo stack is empty.\n";
            return;
        }
        cout << "\nUndo Stack (Last Deleted Appointments):\n";
        while (temp) {
            cout << "- ID: " << temp->id
                 << ", Name: " << temp->name
                 << ", Date: " << temp->date
                 << ", Time: " << temp->time
                 << ", Specialty: " << temp->specialty
                 << "\n";
            temp = temp->next;
        }
    }
};

#endif

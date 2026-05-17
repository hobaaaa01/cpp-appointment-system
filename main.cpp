#include <iostream>
#include "Appointment.h"
#include "AppointmentQueue.h"
#include "UndoStack.h"
#include "CompletedList.h"
#include "AppointmentTree.h"
using namespace std;

int main() {
    AppointmentQueue queue;
    UndoStack undo;
    CompletedList completed;
    AppointmentTree tree;

    int choice;
    int id = 1;

    while (true) {
        cout << "\n===== Appointment Booking System =====\n";
        cout << "1. Add New Appointment\n";
        cout << "2. View All Appointments (Queue)\n";
        cout << "3. Delete Oldest Appointment (Dequeue)\n";
        cout << "4. Undo Last Deletion\n";
        cout << "5. View Undo Stack\n";
        cout << "6. View Completed Appointments\n";
        cout << "7. View Appointments Sorted by Date (Tree)\n";
        cout << "8. Search Appointment by Date\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            string name, date, time, specialty;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter Time (e.g., 14:30): ";
            cin >> time;
            cin.ignore();
            cout << "Enter Specialty: ";
            getline(cin, specialty);

            Appointment* app = new Appointment(id++, name, date, time, specialty);

            queue.enqueue(app->id, app->name, app->date, app->time, app->specialty);
            tree.insertAppointment(new Appointment(app->id, app->name, app->date, app->time, app->specialty));
            cout << "✅ Appointment added successfully.\n";

        } else if (choice == 2) {
            queue.displayQueue();

        } else if (choice == 3) {
            Appointment* removed = queue.dequeue();
            if (removed) {
                completed.addCompleted(removed);
                undo.push(removed);
                cout << "🗑️ Appointment removed and added to completed list.\n";
            } else {
                cout << "❌ No appointments to delete.\n";
            }

        } else if (choice == 4) {
            Appointment* restored = undo.pop();
            if (restored) {
                queue.enqueue(restored->id, restored->name, restored->date, restored->time, restored->specialty);
                tree.insertAppointment(new Appointment(restored->id, restored->name, restored->date, restored->time, restored->specialty));
                cout << "🔄 Appointment restored from undo stack.\n";
            } else {
                cout << "⚠️ No actions to undo.\n";
            }

        } else if (choice == 5) {
            undo.displayStack();

        } else if (choice == 6) {
            completed.displayCompleted();

        } else if (choice == 7) {
            tree.displayAppointmentsInOrder();

        } else if (choice == 8) {
            string searchDate;
            cout << "Enter Date to Search (YYYY-MM-DD): ";
            cin >> searchDate;
            tree.searchByDate(searchDate);

        } else if (choice == 0) {
            cout << "👋 Exiting the system. Goodbye!\n";
            break;

        } else {
            cout << "❌ Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

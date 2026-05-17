#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <iostream>
#include <string>
using namespace std;

struct Appointment {
    int id;
    string name;
    string date;
    string time;
    string specialty;
    Appointment* next;

    Appointment(int _id, string _name, string _date, string _time, string _specialty) {
        id = _id;
        name = _name;
        date = _date;
        time = _time;
        specialty = _specialty;
        next = nullptr;
    }
};

#endif

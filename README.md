# Appointment Booking System (C++)

A simple yet structured appointment booking system developed in C++ as part of the CS2111 Data Structures & Algorithms course at Effat University, Spring 2025.

## 🔧 Features

- Add new appointments with ID, name, date, time, and specialty
- Manage appointments using:
  - Queue (FIFO) for active appointments
  - Stack for undo functionality
  - Linked List for completed appointments
  - Binary Search Tree (BST) for date-sorted viewing
- Search for appointments by date
- View all, completed, and sorted appointments

## 🧱 Data Structures Used

- **Array**: for storing queue data
- **Linked List**: for completed and undo stacks
- **Stack**: for undo deleted appointments
- **Queue**: for managing upcoming appointments
- **Binary Search Tree (BST)**: for storing and searching appointments by date

## 🧠 Concepts Covered

- Dynamic memory management
- Class and struct design
- Tree traversal and insertion
- Modular programming
- OOP in C++

## 📁 Project Structure

```
AppointmentSystemProject/
│
├── main.cpp
├── Appointment.h
├── AppointmentQueue.h
├── UndoStack.h
├── CompletedList.h
├── AppointmentTree.h
```

## 👨‍💻 Developer

**Name:** Abdulwahab Ghounim 
**Student ID:** S22107684  
**Email:** abaghounim@effat.edu.sa

---

## 📝 How to Run

1. Open terminal in project folder
2. Compile the code:
   ```
   g++ main.cpp -o main
   ```
3. Run the executable:
   ```
   ./main
   ```

---

## 📚 Course Info

- **Course:** CS2111 – Data Structures and Algorithms  
- **Instructor:** Dr. Naila Marir  
- **Semester:** Spring 2025  

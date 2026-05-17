#ifndef APPOINTMENT_TREE_H
#define APPOINTMENT_TREE_H

#include "Appointment.h"
#include <iostream>
using namespace std;

class TreeNode {
public:
    Appointment* data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Appointment* app) {
        data = app;
        left = right = nullptr;
    }
};

class AppointmentTree {
private:
    TreeNode* root;

    // Recursive insert based on date
    TreeNode* insert(TreeNode* node, Appointment* app) {
        if (!node) return new TreeNode(app);
        if (app->date < node->data->date)
            node->left = insert(node->left, app);
        else
            node->right = insert(node->right, app);
        return node;
    }

    // In-order traversal to print by ascending date
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->data->id
             << " | Name: " << node->data->name
             << " | Date: " << node->data->date
             << " | Time: " << node->data->time
             << " | Specialty: " << node->data->specialty
             << "\n";
        inorder(node->right);
    }

    // Internal recursive search
    Appointment* search(TreeNode* node, const string& targetDate) {
        if (!node) return nullptr;

        if (node->data->date == targetDate)
            return node->data;
        else if (targetDate < node->data->date)
            return search(node->left, targetDate);
        else
            return search(node->right, targetDate);
    }

public:
    AppointmentTree() { root = nullptr; }

    void insertAppointment(Appointment* app) {
        app->next = nullptr; // to be safe
        root = insert(root, app);
    }

    void displayAppointmentsInOrder() {
        if (!root) {
            cout << "\n🌳 No appointments in the tree.\n";
            return;
        }
        cout << "\n===== Appointments Sorted by Date (BST) =====\n";
        inorder(root);
    }

    void searchByDate(const string& targetDate) {
        Appointment* result = search(root, targetDate);
        if (result) {
            cout << "\n🔍 Appointment Found:\n";
            cout << "ID: " << result->id
                 << " | Name: " << result->name
                 << " | Date: " << result->date
                 << " | Time: " << result->time
                 << " | Specialty: " << result->specialty << "\n";
        } else {
            cout << "\n❌ No appointment found on date: " << targetDate << "\n";
        }
    }
};

#endif

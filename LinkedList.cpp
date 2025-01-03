#include <iostream>
using namespace std;

struct student {
    char sname[30];
    int rno;
    float cgpa;
    student *next;
    student *prev;
};

// Function prototypes
void display_dll(student *head);
student* insert_at_front(student *head);
student* insert_at_end(student *head);
student* delete_at_front(student *head);
student* delete_at_end(student *head);
student* insert_in_between(student *head);
student* delete_in_between(student *head);
int count(student *head);

int main() {
    student *head = nullptr;
    int ch;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display DLL\n";
        cout << "2. Insert at front\n";
        cout << "3. Exit\n";
        cout << "4. Insert at end\n";
        cout << "5. Delete at front\n";
        cout << "6. Delete at end\n";
        cout << "7. Count\n";
        cout << "8. Delete in between\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: display_dll(head); break;
            case 2: head = insert_at_front(head); break;
            case 3: exit(0);
            case 4: head = insert_at_end(head); break;
            case 5: head = delete_at_front(head); break;
            case 6: head = delete_at_end(head); break;
            case 7: count(head); break;
            case 8: head = delete_in_between(head); break;
            default: cout << "Invalid choice\n"; break;
        }
    }

    return 0;
}

void display_dll(student *head) {
    if (!head) {
        cout << "DLL is empty\n";
        return;
    }
    student *temp = head;
    while (temp) {
        cout << "Name: " << temp->sname << " Roll No: " << temp->rno << " CGPA: " << temp->cgpa << endl;
        temp = temp->next;
    }
}

student* insert_at_front(student *head) {
    student *ptr = new student();
    cout << "Enter name, roll no, and CGPA: ";
    cin >> ptr->sname >> ptr->rno >> ptr->cgpa;

    if (!head) {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        return ptr;
    }

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = nullptr;
    return ptr;
}

student* insert_at_end(student *head) {
    student *ptr = new student();
    cout << "Enter name, roll no, and CGPA: ";
    cin >> ptr->sname >> ptr->rno >> ptr->cgpa;

    if (!head) {
        ptr->next = nullptr;
        ptr->prev = nullptr;
        return ptr;
    }

    student *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = nullptr;
    return head;
}

student* delete_at_front(student *head) {
    if (!head) {
        cout << "DLL is empty\n";
        return nullptr;
    }

    student *temp = head;
    head = head->next;
    if (head) head->prev = nullptr;

    cout << "Deleted: Name: " << temp->sname << " Roll No: " << temp->rno << " CGPA: " << temp->cgpa << endl;
    delete temp;
    return head;
}

student* delete_at_end(student *head) {
    if (!head) {
        cout << "DLL is empty\n";
        return nullptr;
    }

    if (!head->next) {
        cout << "Deleted: Name: " << head->sname << " Roll No: " << head->rno << " CGPA: " << head->cgpa << endl;
        delete head;
        return nullptr;
    }

    student *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;

    cout << "Deleted: Name: " << temp->sname << " Roll No: " << temp->rno << " CGPA: " << temp->cgpa << endl;
    delete temp;
    return head;
}

int count(student *head) {
    int count = 0;
    student *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    cout << "Count: " << count << endl;
    return count;
}

student* insert_in_between(student *head) {
    int pos;
    cout << "Enter the position to insert: ";
    cin >> pos;

    if (pos < 1 || pos > count(head) + 1) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) {
        return insert_at_front(head);
    }

    if (pos == count(head) + 1) {
        return insert_at_end(head);
    }

    student *ptr = new student();
    cout << "Enter name, roll no, and CGPA: ";
    cin >> ptr->sname >> ptr->rno >> ptr->cgpa;

    student *temp = head;
    for (int i = 1; i < pos - 1; ++i) {
        temp = temp->next;
    }

    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    return head;
}

student* delete_in_between(student *head) {
    int pos;
    cout << "Enter the position to delete: ";
    cin >> pos;

    if (pos < 1 || pos > count(head)) {
        cout << "Invalid position\n";
        return head;
    }

    if (pos == 1) {
        return delete_at_front(head);
    }

    if (pos == count(head)) {
        return delete_at_end(head);
    }

    student *temp = head;
    for (int i = 1; i < pos; ++i) {
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    cout << "Deleted: Name: " << temp->sname << " Roll No: " << temp->rno << " CGPA: " << temp->cgpa << endl;
    delete temp;

    return head;
}

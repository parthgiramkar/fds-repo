#include <iostream>
using namespace std;

class Deque {
private:
    int* dequeArray;
    int front, rear, capacity;

public:
    // Constructor to initialize deque with a given capacity
    Deque(int size) {
        capacity = size;
        dequeArray = new int[capacity];
        front = -1;
        rear = -1;
    }

    

    // Function to check if the deque is full
    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (rear == (front - 1) % (capacity - 1));
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Insert an element at the rear of the deque
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full, cannot insert at rear.\n";
            return;
        }
        if (front == -1) {  // First element being inserted
            front = rear = 0;
        } else if (rear == capacity - 1 && front != 0) {
            rear = 0;  // Circularly move rear to the beginning
        } else {
            rear++;
        }
        dequeArray[rear] = value;
        cout << "Inserted " << value << " at the rear.\n";
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from rear.\n";
            return;
        }
        cout << "Deleted " << dequeArray[rear] << " from the rear.\n";
        if (front == rear) {  // Only one element in the deque
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;  // Circularly move rear to the end
        } else {
            rear--;
        }
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty, cannot delete from front.\n";
            return;
        }
        cout << "Deleted " << dequeArray[front] << " from the front.\n";
        if (front == rear) {  // Only one element in the deque
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;  // Circularly move front
        }
    }

    // Insert an element at the front of the deque
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full, cannot insert at front.\n";
            return;
        }
        if (front == -1) {  // First element being inserted
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;  // Circularly move front to the end
        } else {
            front--;
        }
        dequeArray[front] = value;
        cout << "Inserted " << value << " at the front.\n";
    }

    // Display the front element
    void displayFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Front element is: " << dequeArray[front] << endl;
    }

    // Display the rear element
    void displayRear() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Rear element is: " << dequeArray[rear] << endl;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of deque: ";
    cin >> size;

    Deque dq(size);

    while (true) {
        cout << "\nDeque Menu:\n";
        cout << "1. Insert at rear end\n";
        cout << "2. Delete from rear end\n";
        cout << "3. Delete from front end\n";
        cout << "4. Insert at front end\n";
        cout << "5. Display front\n";
        cout << "6. Display rear\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 2:
                dq.deleteRear();
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 5:
                dq.displayFront();
                break;
            case 6:
                dq.displayRear();
                break;
            case 7:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;    // Array to hold the orders
    int front, rear, size, capacity;

public:
    // Constructor to initialize the circular queue with a given capacity
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        queue = new int[capacity];
        front = rear = -1;
        size = 0;
    }


    // Function to check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Function to add a pizza order
    void addPizza(int orderNumber) {
        if (isFull()) {
            cout << "Sorry, the pizza parlor is at full capacity. Cannot take more orders.\n";
            return;
        }
        if (front == -1) {  // First order being placed
            front = 0;
        }
        rear = (rear + 1) % capacity;  // Move rear circularly
        queue[rear] = orderNumber;
        size++;
        cout << "Order " << orderNumber << " has been placed.\n";
    }

    // Function to serve (remove) a pizza order
    void servePizza() {
        if (isEmpty()) {
            cout << "No orders to serve. The queue is empty.\n";
            return;
        }
        int order = queue[front];
        cout << "Serving pizza with order number " << order << ".\n";
        front = (front + 1) % capacity;  // Move front circularly
        size--;
    }

    // Function to display all orders in the queue
    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders to display. The queue is empty.\n";
            return;
        }
        cout << "Current orders in the queue: ";
        int count = size;
        int tempFront = front;
        while (count--) {
            cout << queue[tempFront] << " ";
            tempFront = (tempFront + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can handle: ";
    cin >> maxOrders;

    PizzaParlor parlor(maxOrders);
    int choice, orderNumber;

    while (true) {
        cout << "\nPizza Parlor Menu:\n";
        cout << "1. Add a Pizza\n";
        cout << "2. Display the Orders\n";
        cout << "3. Serve a Pizza\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number: ";
                cin >> orderNumber;
                parlor.addPizza(orderNumber);
                break;
            case 2:
                parlor.displayOrders();
                break;
            case 3:
                parlor.servePizza();
                break;
            case 4:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

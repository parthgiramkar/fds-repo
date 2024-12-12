#include <iostream>
using namespace std;

// Define a node for the doubly linked list
struct Node {
    char bit;
    Node* prev;
    Node* next;
};

// Function to create a new node with a given bit value
Node* newNode(char bit) {
    Node* new_node = new Node();
    new_node->bit = bit;
    new_node->prev = new_node->next = nullptr;
    return new_node;
}

// Function to insert a bit at the end of the doubly linked list
void insertEnd(Node*& head, char bit) {
    Node* new_node = newNode(bit);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// Function to print the binary number stored in the doubly linked list
void printBinary(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->bit;
        temp = temp->next;
    }
    cout << endl;
}

// Function to compute 1's complement of a binary number
void onesComplement(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        temp->bit = (temp->bit == '0') ? '1' : '0'; // Flip the bits
        temp = temp->next;
    }
}

// Function to compute 2's complement of a binary number
void twosComplement(Node* head) {
    onesComplement(head); // First, find the 1's complement
    Node* temp = head;
    bool carry = true;

    // Add 1 to the 1's complement to get 2's complement
    while (temp != nullptr) {
        if (carry == true && temp->bit == '1') {
            temp->bit = '0';
        } else if (carry == true && temp->bit == '0') {
            temp->bit = '1';
            carry = false;
        }
        temp = temp->next;
    }
}

// Function to add two binary numbers
Node* addBinary(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    bool carry = false;

    // Traverse both lists and add corresponding bits
    while (temp1 != nullptr || temp2 != nullptr || carry) {
        int bit1 = (temp1 != nullptr) ? temp1->bit - '0' : 0;
        int bit2 = (temp2 != nullptr) ? temp2->bit - '0' : 0;

        int sum = bit1 + bit2 + carry;
        carry = sum / 2; // Calculate carry
        insertEnd(result, (sum % 2) + '0'); // Insert the sum bit

        if (temp1 != nullptr) temp1 = temp1->next;
        if (temp2 != nullptr) temp2 = temp2->next;
    }

    return result;
}

int main() {
    Node* binary1 = nullptr;
    Node* binary2 = nullptr;
    Node* sum = nullptr;

    // Input first binary number
    string input1;
    cout << "Enter first binary number: ";
    cin >> input1;
    for (char bit : input1) {
        insertEnd(binary1, bit);
    }

    // Input second binary number
    string input2;
    cout << "Enter second binary number: ";
    cin >> input2;
    for (char bit : input2) {
        insertEnd(binary2, bit);
    }

    // Print the original binary numbers
    cout << "First Binary Number: ";
    printBinary(binary1);

    cout << "Second Binary Number: ";
    printBinary(binary2);

    // Compute and print 1's complement of first binary number
    onesComplement(binary1);
    cout << "1's Complement of First Binary Number: ";
    printBinary(binary1);

    // Compute and print 2's complement of first binary number
    twosComplement(binary1);
    cout << "2's Complement of First Binary Number: ";
    printBinary(binary1);

    // Add the two binary numbers and print the result
    sum = addBinary(binary1, binary2);
    cout << "Sum of the two binary numbers: ";
    printBinary(sum);

    return 0;
}

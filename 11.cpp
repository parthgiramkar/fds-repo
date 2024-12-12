#include <iostream>
#include <queue>  // Queue data structure from STL
using namespace std;

class JobQueue {
private:
    queue<int> jobQueue;  // Queue to hold jobs
public:
    // Function to add a job to the queue
    void insertJob(int job) {
        jobQueue.push(job);
        cout << "Job " << job << " added to the queue." << endl;
    }

    // Function to delete a job from the queue (process the job)
    void deleteJob() {
        if (!jobQueue.empty()) {
            int job = jobQueue.front();  // Get the job at the front
            jobQueue.pop();              // Remove the job from the queue
            cout << "Job " << job << " has been processed and removed from the queue." << endl;
        } else {
            cout << "No jobs in the queue to process." << endl;
        }
    }

    // Function to display all jobs in the queue
    void displayJobs() {
        if (!jobQueue.empty()) {
            cout << "Jobs in the queue: ";
            queue<int> tempQueue = jobQueue;  // Use a temporary queue to display elements
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << endl;
        } else {
            cout << "No jobs in the queue." << endl;
        }
    }
};

int main() {
    JobQueue jq;
    int choice, job;

    while (true) {
        cout << "\nJob Queue Menu: \n";
        cout << "1. Insert Job\n";
        cout << "2. Process Job (Delete from queue)\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job number to insert: ";
                cin >> job;
                jq.insertJob(job);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayJobs();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

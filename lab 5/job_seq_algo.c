// Write a code to implement job sequencing algorithm with deadline

#include <stdio.h>

// Structure to represent a job
struct Job {
    char id;     // Job ID
    int deadline; // Deadline
    int profit;  // Profit
};
int i,j;
// Function to solve the Job Sequencing Problem with Deadlines
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs based on the profit in non-increasing order (using any sorting algorithm)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                // Swap jobs
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    int maxDeadline = 0;
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Initialize an array to keep track of time slots for each job
    char timeSlots[maxDeadline];
    for (i = 0; i < maxDeadline; i++) {
        timeSlots[i] = 0; // Initialize all slots as available
    }

    // Initialize variables to store the total profit and the number of jobs scheduled
    int totalProfit = 0;
    int scheduledJobs = 0;

    // Schedule jobs
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (timeSlots[j] == 0) {
                timeSlots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                scheduledJobs++;
                break;
            }
        }
    }

    // Print the scheduled jobs and the total profit
    printf("Scheduled Jobs: ");
    for (i = 0; i < maxDeadline; i++) {
        if (timeSlots[i] != 0) {
            printf("%c ", timeSlots[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Output of Job Sequencing Algorithm with deadline\n");
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    struct Job jobs[n];

    for (i = 0; i < n; i++) {
        
        printf("Enter job ID, deadline, and profit for job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}

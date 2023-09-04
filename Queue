#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For sleep function (POSIX systems)
#include <time.h>   // For srand and rand functions

// Define the structure for a customer
struct Customer {
    int customerID;
    char customerName[100];
};

// Define the structure for a node in the queue
struct Node {
    struct Customer data;
    struct Node* next;
};

// Define the structure for a queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(struct Customer data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue a customer into the queue
void enqueue(struct Queue* queue, struct Customer data) {
    struct Node* newNode = createNode(data);

    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a customer from the queue
void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to simulate handling a customer
void handleCustomer(struct Customer customer) {
    printf("Handling customer: %s\n", customer.customerName);
    printf("Service in progress...\n");
    sleep(2); // Sleep for 2 seconds to simulate service
    printf("Service completed.\n");
}

// Supermarket Checkout Lanes Logic
void supermarketCheckout() {
	int i;
    struct Queue checkoutLanes[10]; // 10 checkout lanes
    for ( i = 0; i < 10; i++) {
        initQueue(&checkoutLanes[i]);
    }

    int customerCounter = 1;
    int choice;

    do {
        printf("\nSupermarket Checkout Lanes:\n");
        printf("1. Customer Arrives at Checkout\n");
        printf("2. Process Checkout\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Customer newCustomer;
                newCustomer.customerID = customerCounter++;
                printf("Enter Customer Name: ");
                scanf("%s", newCustomer.customerName);
                int laneChoice;
                printf("Choose Checkout Lane (1-10): ");
                scanf("%d", &laneChoice);
                if (laneChoice >= 1 && laneChoice <= 10) {
                    enqueue(&checkoutLanes[laneChoice - 1], newCustomer);
                } else {
                    printf("Invalid lane choice. Customer not enqueued.\n");
                }
                break;
            }
            case 2: {
                for ( i = 0; i < 10; i++) {
                    while (!isEmpty(&checkoutLanes[i])) {
                        struct Customer currentCustomer = checkoutLanes[i].front->data;
                        printf("Processing checkout in lane %d:\n", i + 1);
                        printf("Customer ID: %d, Customer Name: %s\n",
                               currentCustomer.customerID, currentCustomer.customerName);
                        handleCustomer(currentCustomer);
                        dequeue(&checkoutLanes[i]);
                    }
                }
                printf("All checkouts processed.\n");
                break;
            }
            case 3:
                printf("Exiting the supermarket checkout simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

// Traffic Management at Intersections Logic
void trafficManagement() {
    struct Queue intersectionQueue;
    initQueue(&intersectionQueue);

    int vehicleCounter = 1;
    int choice;

    do {
        printf("\nTraffic Management at Intersections:\n");
        printf("1. Vehicle Arrives at Intersection\n");
        printf("2. Manage Traffic\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Customer newVehicle;
                newVehicle.customerID = vehicleCounter++;
                printf("Enter Vehicle Owner's Name: ");
                scanf("%s", newVehicle.customerName);
                enqueue(&intersectionQueue, newVehicle);
                break;
            }
            case 2: {
                while (!isEmpty(&intersectionQueue)) {
                    struct Customer currentVehicle = intersectionQueue.front->data;
                    printf("Next vehicle at intersection:\n");
                    printf("Vehicle ID: %d, Owner: %s\n",
                           currentVehicle.customerID, currentVehicle.customerName);
                    printf("Traffic management in progress...\n");
                    sleep(1); // Simulate traffic management for 1 second
                    dequeue(&intersectionQueue);
                }
                printf("All vehicles managed.\n");
                break;
            }
            case 3:
                printf("Exiting the traffic management.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

// Call Center Waiting Queue Logic
void callCenterQueue() {
    struct Queue callCenterQueue;
    initQueue(&callCenterQueue);

    int customerCounter = 1;
    int choice;

    do {
        printf("\nCall Center Waiting Queue:\n");
        printf("1. Customer Calls\n");
        printf("2. Process Customer Calls\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Customer newCustomer;
                newCustomer.customerID = customerCounter++;
                printf("Enter Customer Name: ");
                scanf("%s", newCustomer.customerName);
                enqueue(&callCenterQueue, newCustomer);
                break;
            }
            case 2: {
                while (!isEmpty(&callCenterQueue)) {
                    struct Customer currentCustomer = callCenterQueue.front->data;
                    printf("Processing customer call:\n");
                    printf("Customer ID: %d, Customer Name: %s\n",
                           currentCustomer.customerID, currentCustomer.customerName);
                    handleCustomer(currentCustomer);
                    dequeue(&callCenterQueue);
                }
                printf("All customer calls processed.\n");
                break;
            }
            case 3:
                printf("Exiting the call center simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

// Bank Customer Service Queue Logic
void bankCustomerService() {
    struct Queue bankQueue;
    initQueue(&bankQueue);

    int customerCounter = 1;
    int choice;

    do {
        printf("\nBank Customer Service Queue:\n");
        printf("1. Customer Arrives at Bank\n");
        printf("2. Process Bank Service\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Customer newCustomer;
                newCustomer.customerID = customerCounter++;
                printf("Enter Customer Name: ");
                scanf("%s", newCustomer.customerName);
                enqueue(&bankQueue, newCustomer);
                break;
            }
            case 2: {
                while (!isEmpty(&bankQueue)) {
                    struct Customer currentCustomer = bankQueue.front->data;
                    printf("Processing bank service:\n");
                    printf("Customer ID: %d, Customer Name: %s\n",
                           currentCustomer.customerID, currentCustomer.customerName);
                    handleCustomer(currentCustomer);
                    dequeue(&bankQueue);
                }
                printf("All bank services processed.\n");
                break;
            }
            case 3:
                printf("Exiting the bank customer service simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    int exampleChoice;

    do {
        printf("\nChoose an example:\n");
        printf("1. Supermarket Checkout Lanes\n");
        printf("2. Traffic Management at Intersections\n");
        printf("3. Call Center Waiting Queue\n");
        printf("4. Bank Customer Service Queue\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &exampleChoice);

        switch (exampleChoice) {
            case 1:
                supermarketCheckout();
                break;
            case 2:
                trafficManagement();
                break;
            case 3:
                callCenterQueue();
                break;
            case 4:
                bankCustomerService();
                break;
            case 5:
                printf("Exiting the simulation.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (exampleChoice != 5);

    return 0;
}

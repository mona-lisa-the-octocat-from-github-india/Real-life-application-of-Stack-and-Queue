#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

// Create structure for the stack
struct S {
    unsigned size;
    int *arr;
    int top;
};

// Function to create a stack
struct S *Stack(unsigned size) {
    struct S *disc_stack = (struct S *)malloc(sizeof(struct S));
    disc_stack->size = size;
    disc_stack->top = -1;
    disc_stack->arr = (int *)malloc(disc_stack->size * sizeof(int));
    return disc_stack;
}

// Check if stack is empty
int Empty(struct S *disc_stack) {
    return (disc_stack->top == -1);
}

// Check if stack is full
int Full(struct S *disc_stack) {
    return (disc_stack->top == disc_stack->size - 1);
}

// Push operation
void push(struct S *disc_stack, int disc) {
    if (Full(disc_stack))
        return;
    disc_stack->arr[++disc_stack->top] = disc;
}

// Pop operation
int pop(struct S *disc_stack) {
    if (Empty(disc_stack))
        return INT_MIN;
    return disc_stack->arr[disc_stack->top--];
}

// Function to implement the movement of discs from start to end using intermediate pillar
void move(char source, char destination, int d) {
    printf("Move the disc %d from peg %c to peg %c\n", d, source, destination);
}

// Function to show movement between two rods
void F1(struct S *from, struct S *to, char source, char destination, int *stepCount) {
    int p1Disc = pop(from);
    int p2Disc = pop(to);

    // When pillar 1 is empty
    if (p1Disc == INT_MIN) {
        push(from, p2Disc);
        move(destination, source, p2Disc);
        (*stepCount)++;
    }

    // When pillar 2 is empty
    else if (p2Disc == INT_MIN) {
        push(to, p1Disc);
        move(source, destination, p1Disc);
        (*stepCount)++;
    }

    // When top disc of P1 is greater than top disk of P2
    else if (p1Disc > p2Disc) {
        push(from, p1Disc);
        push(from, p2Disc);
        move(destination, source, p2Disc);
        (*stepCount)++;
    }

    // When top disc of P1 is smaller than top disc of P2
    else {
        push(to, p2Disc);
        push(to, p1Disc);
        move(source, destination, p1Disc);
        (*stepCount)++;
    }
}

// Tower of Hanoi
void TOH(int n, struct S *from, struct S *_using, struct S *to, int *stepCount) {
    int i;
    int total_moves = pow(2, n) - 1;
    char source = 'A', destination = 'C', intermediate = 'B';

    for (i = n; i >= 1; i--)
        push(from, i);

    for (i = 1; i <= total_moves; i++) {

        if (i % 3 == 0)
            F1(_using, to, intermediate, destination, stepCount);

        else if (i % 3 == 1)
            F1(from, to, source, destination, stepCount);

        else if (i % 3 == 2)
            F1(from, _using, source, intermediate, stepCount);
    }
}

int main() {
    unsigned n;
    // User Input
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    struct S *from, *_using, *to;

    // Creating three stacks
    from = Stack(n);
    _using = Stack(n);
    to = Stack(n);

    int stepCount = 0;
    TOH(n, from, _using, to, &stepCount);
    
    printf("Total steps taken: %d\n", stepCount);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        NUMBER,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION
    } type;
    union {
        int value;               // Used for NUMBER type
        struct Node* left;       // Used for operation types
        struct {
            struct Node* left;
            struct Node* right;
        };
    };
} Node;

// Arithmetic operation functions
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return 0;
}

// Function to create operation nodes
Node* makeFunc(enum TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    return node;
}

// Function to perform calculations based on node types
int calc(Node* node) {
    if (node == NULL) {
        return 0;
    }

    switch (node->type) {
        case NUMBER:
            return node->value;
        case ADDITION:
            return calc(node->left) + calc(node->right);
        case SUBTRACTION:
            return calc(node->left) - calc(node->right);
        case MULTIPLICATION:
            return calc(node->left) * calc(node->right);
        case DIVISION:
            return calc(node->left) / calc(node->right);
        default:
            return 0;
    }
}

int main() {
    Node* add = (*makeFunc(ADDITION))(10, 6);
    Node* mul = (*makeFunc(MULTIPLICATION))(5, 4);
    Node* sub = (*makeFunc(SUBTRACTION))(mul, add);
    Node* fibo = (*makeFunc(SUBTRACTION))(sub, NULL);

    printf("Addition: %d\n", calc(add));
    printf("Multiplication: %d\n", calc(mul));
    printf("Subtraction: %d\n", calc(sub));
    printf("Fibonacci: %d\n", calc(fibo));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}

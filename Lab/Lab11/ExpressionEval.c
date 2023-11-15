#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Stack {
    struct Node* tree_node;
    struct Stack* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Stack* createStack(struct Node* tree_node) {
    struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->tree_node = tree_node;
    newNode->next = NULL;
    return newNode;
}

void push(struct Stack** top, struct Node* tree_node) {
    struct Stack* newNode = createStack(tree_node);
    newNode->next = *top;
    *top = newNode;
}

struct Node* pop(struct Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Stack* temp = *top;
    *top = (*top)->next;
    struct Node* popped_tree_node = temp->tree_node;
    free(temp);
    return popped_tree_node;
}

struct Node* buildExpressionTree(char postfix[]) {
    struct Stack* stack = NULL;

    for (int i = 0; postfix[i]; i++) {
        if (isalnum(postfix[i])) {
            struct Node* tree_node = createNode(postfix[i]);
            push(&stack, tree_node);
        } else {
            struct Node* right = pop(&stack);
            struct Node* left = pop(&stack);

            struct Node* tree_node = createNode(postfix[i]);
            tree_node->right = right;
            tree_node->left = left;

            push(&stack, tree_node);
        }
    }

    return pop(&stack);
}

int evaluateExpressionTree(struct Node* root) {
    if (root) {
        if (isdigit(root->data)) {
            return root->data - '0';
        } else {
            int left_val = evaluateExpressionTree(root->left);
            int right_val = evaluateExpressionTree(root->right);

            switch (root->data) {
                case '+':
                    return left_val + right_val;
                case '-':
                    return left_val - right_val;
                case '*':
                    return left_val * right_val;
                case '/':
                    if (right_val == 0) {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    return left_val / right_val;
                default:
                    printf("Error: Invalid operator.\n");
                    exit(1);
            }
        }
    }
    return 0;
}

int main() {
    char postfixExpression[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    struct Node* root = buildExpressionTree(postfixExpression);
    printf("Expression Tree has been created.\n");

    int result = evaluateExpressionTree(root);
    printf("Result: %d\n", result);

    return 0;
}

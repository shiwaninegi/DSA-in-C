#include <stdio.h>
#include <stdlib.h>

typedef struct tree_type {
    int data;
    struct tree_type *left;
    struct tree_type *right;
} tree;

tree *createNode(int x) {
    tree *temp = (tree *)malloc(sizeof(tree));
    if (temp == NULL) {
        printf("No space available\n");
        return NULL;
    }
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

tree *insert(tree *root, int x) {
    if (root == NULL) {
        return createNode(x);
    }
    if (x > root->data) {
        root->right = insert(root->right, x);
    } else if (x < root->data) {
        root->left = insert(root->left, x);
    }
    return root;
}

tree *minValueNode(tree *node) {
    tree *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

tree *deleteNode(tree *root, int x) {
    if (root == NULL) {
        return root;
    }
    if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else {
        if (root->left == NULL) {
            tree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree *temp = root->left;
            free(root);
            return temp;
        }
        tree *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(tree *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void display(tree *root, int space) {
    if (root == NULL)
        return;

    space += 5;
    display(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    display(root->left, space);
}

int main() {
    tree *root = NULL;
    int choice, item;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete\n");
        printf("6. Display Tree\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the data to delete: ");
                scanf("%d", &item);
                root = deleteNode(root, item);
                break;
            case 6:
                printf("Tree Structure:\n");
                display(root, 0);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);

    return 0;
}

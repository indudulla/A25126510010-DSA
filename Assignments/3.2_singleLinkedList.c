#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL;

// Create a new node
struct Node* createNode(int roll) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    return newNode;
}

// Display the list
void display() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Student Roll Numbers: ");
    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at beginning
void insertBeginning(int roll) {
    struct Node *newNode = createNode(roll);

    newNode->next = head;
    head = newNode;

    printf("Inserted %d at beginning.\n", roll);
    display();
}

// Insert at end
void insertEnd(int roll) {
    struct Node *newNode = createNode(roll);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Inserted %d at end.\n", roll);
    display();
}

// Search for a roll number
void search(int roll) {
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->roll == roll) {
            printf("Roll number %d is available in the list.\n", roll);
            return;
        }
        temp = temp->next;
    }

    printf("Roll number %d is not available.\n", roll);
    display();
}

// Delete a roll number
void deleteRoll(int roll) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number %d is not available. Cannot delete.\n", roll);
        display();
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Deleted roll number %d.\n", roll);
    display();
}

int main() {
    int n, roll, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter roll numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &roll);
        insertEnd(roll);
    }

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search Roll Number\n");
        printf("4. Delete Roll Number\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertBeginning(roll);
                break;

            case 2:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                insertEnd(roll);
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &roll);
                search(roll);
                break;

            case 4:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteRoll(roll);
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program ended.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

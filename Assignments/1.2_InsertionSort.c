/*A teacher wants to arrange student marks in ascending order and also measure how much 
rearrangement is necessary. Write a C program using Insertion Sort that accepts n marks, displays 
the array after every pass, counts the total number of element count, and displays the final sorted 
list and shift count.*/
#include <stdio.h>

int main() {
    int n, i, j, key;
    int count = 0;

    printf("Enter number of marks: ");
    scanf("%d", &n);
    int marks[n];
    printf("Enter the marks:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }
    // Insertion Sort
    for (i = 1; i < n; i++) {
        key = marks[i];
        j = i - 1;
        // Shift elements greater than key
        while (j >= 0 && marks[j] > key) {
            marks[j + 1] = marks[j];
            j--;
            count++;
        }
        marks[j + 1] = key;
        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", marks[k]);
        }
        printf("\n");
    }
    printf("\nFinal sorted list: ");
    for (i = 0; i < n; i++) {
        printf("%d ", marks[i]);
    }
    printf("\nTotal number of count: %d\n", count);
    return 0;
}

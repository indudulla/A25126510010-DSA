/*A company stores employee IDs in ascending order. Write a C program that accepts n employee 
IDs, searches for a required ID using Binary Search, displays its position when found, reports 
when it is absent, and counts the number of comp. Test the program for both successful 
and unsuccessful searches.*/
#include <stdio.h>
int main() {
    int n, i, key;
    int st, end, mid;
    int comp = 0;
    int found = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    int id[n];
    printf("Enter employee IDs in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &key);
    st = 0;
    end = n - 1;
    while (st <= end) {
        mid = st + (end - st) / 2;
        comp++;
        if (id[mid] == key) {
            found = 1;
            printf("Employee ID %d found at position %d.\n", key, mid + 1);
            break;
        }
        else if (key < id[mid]) {
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    if (!found) {
        printf("Employee ID %d is absent.\n", key);
    }
    printf("Number of comparisons: %d\n", comp);
    return 0;
}

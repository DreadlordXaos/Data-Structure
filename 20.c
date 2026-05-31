#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], n;

// Function to create graph
void createGraph() {
printf("Enter number of vertices: ");
scanf("%d", &n);

printf("Enter adjacency matrix:\n");
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        scanf("%d", &adj[i][j]);
    }
}

}

// Function to display graph
void displayGraph() {
printf("\nAdjacency Matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
printf("%d ", adj[i][j]);
}
printf("\n");
}
}

// Main menu
int main() {
int choice;

do {
    printf("\n--- MENU ---\n");
    printf("1. Create Graph\n");
    printf("2. Display Graph\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createGraph();
            break;

        case 2:
            displayGraph();
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
    }

} while (choice != 3);

return 0;

}

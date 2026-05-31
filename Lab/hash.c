#include <stdio.h>

#define TS 17

int table[TS];

int hash(int x) {
    return x % TS;
}

void init() {
    for (int i = 0; i < TS; i++)
        table[i] = -1;
}

void insert(int x) {
    int base = hash(x);
    int probes = 0;

    for (int i = 0; i < TS; i++) {
        int idx = (base + i*i) % TS;
        probes++;

        if (table[idx] == -1 || table[idx] == -2) {
            table[idx] = x;
            printf("Inserted at index %d\n", idx);
            printf("Probes: %d\n", probes);
            return;
        }
    }

    printf("Insertion not possible\n");
}

void search(int x) {
    int base = hash(x);
    int probes = 0;

    for (int i = 0; i < TS; i++) {
        int idx = (base + i*i) % TS;
        probes++;

        if (table[idx] == -1) {
            printf("Not found\n");
            printf("Probes: %d\n", probes);
            return;
        }

        if (table[idx] == x) {
            printf("Found at index %d\n", idx);
            printf("Probes: %d\n", probes);
            return;
        }
    }

    printf("Not found\n");
    printf("Probes: %d\n", probes);
}

void deleteKey(int x) {
    int base = hash(x);
    int probes = 0;

    for (int i = 0; i < TS; i++) {
        int idx = (base + i*i) % TS;
        probes++;

        if (table[idx] == -1) {
            printf("Not found\n");
            printf("Probes: %d\n", probes);
            return;
        }

        if (table[idx] == x) {
            table[idx] = -2;
            printf("Deleted from index %d\n", idx);
            printf("Probes: %d\n", probes);
            return;
        }
    }

    printf("Not found\n");
    printf("Probes: %d\n", probes);
}

int main() {
    int ch, x;
    init();

    while (1) {
        printf("--------------- Choice ---------------");
        printf("\n 1.Insert");
        printf("\n 2.Delete");
        printf("\n 3.Search");
        printf("\n 4.Quit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter key: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2) {
            printf("Enter key: ");
            scanf("%d", &x);
            deleteKey(x);
        }
        else if (ch == 3) {
            printf("Enter key: ");
            scanf("%d", &x);
            search(x);
        }
        else if (ch == 4) {
            break;
        }
    }

    return 0;
}
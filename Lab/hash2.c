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
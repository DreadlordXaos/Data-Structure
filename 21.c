#include <stdio.h>

#define SIZE 10
#define EMPTY -1

int hash[SIZE];

void initialize() {

    for(int i = 0; i < SIZE; i++) {
        hash[i] = EMPTY;
    }
}

void insert() {

    int value, start;
    int key;

    printf("Enter a key that u want to insert:\n");
    scanf("%d", &key);

    value = key % SIZE;
    start = value;

    while(1) {

        if(hash[value] == EMPTY) {
            hash[value] = key;
            printf("Inserted\n");
            return;
        }

        value = (value + 1) % SIZE;

        if(value == start) {
            printf("Insertion not possible\n");
            return;
        }
    }
}

void search() {

    int key;
    int value, start;

    printf("Enter the key that u want to search:\n");
    scanf("%d", &key);

    value = key % SIZE;
    start = value;

    while(1) {

        if(hash[value] == key) {
            printf("Found at position %d\n", value);
            return;
        }

        if(hash[value] == EMPTY) {
            printf("Not found\n");
            return;
        }

        value = (value + 1) % SIZE;

        if(value == start) {
            printf("Not found\n");
            return;
        }
    }
}

void deleteKey() {

    int key;
    int value, start;

    printf("Enter the key that u want to delete:\n");
    scanf("%d", &key);

    value = key % SIZE;
    start = value;

    while(1) {

        if(hash[value] == key) {
            hash[value] = EMPTY;
            printf("Deleted\n");
            return;
        }

        if(hash[value] == EMPTY) {
            printf("Not found\n");
            return;
        }

        value = (value + 1) % SIZE;

        if(value == start) {
            printf("Not found\n");
            return;
        }
    }
}

void print() {

    for(int i = 0; i < SIZE; i++) {
        printf("%d|", hash[i]);
    }

    printf("\n");
}

int main() {

    int choice;

    initialize();

    do {

        printf("\n------------- Menu -------------\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Print\n");
        printf("5.Exit\n");
        printf("-----------------------------------\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                deleteKey();
                break;

            case 4:
                print();
                break;

            case 5:
                printf("Exiting the programme.....\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }

    } while(1);
}
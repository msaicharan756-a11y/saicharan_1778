#include <stdio.h>
#include <string.h>

#define MAX 100

struct Vehicle {
    char number[20];
    char model[50];
    char owner[50];
};

void addVehicle(struct Vehicle v[], int *n) {
    printf("\nEnter Vehicle Number: ");
    scanf("%s", v[*n].number);

    printf("Enter Vehicle Model: ");
    scanf("%s", v[*n].model);

    printf("Enter Owner Name: ");
    scanf("%s", v[*n].owner);

    (*n)++;
    printf("\nVehicle Added Successfully!\n");
}

void displayVehicles(struct Vehicle v[], int n) {
    if(n == 0) {
        printf("\nNo vehicles available.\n");
        return;
    }

    printf("\n--- Vehicle List ---\n");
    for(int i = 0; i < n; i++) {
        printf("\nVehicle %d:\n", i + 1);
        printf("Number : %s\n", v[i].number);
        printf("Model  : %s\n", v[i].model);
        printf("Owner  : %s\n", v[i].owner);
    }
}

void searchVehicle(struct Vehicle v[], int n) {
    char num[20];
    printf("\nEnter Vehicle Number to Search: ");
    scanf("%s", num);

    for(int i = 0; i < n; i++) {
        if(strcmp(v[i].number, num) == 0) {
            printf("\nVehicle Found!\n");
            printf("Number : %s\n", v[i].number);
            printf("Model  : %s\n", v[i].model);
            printf("Owner  : %s\n", v[i].owner);
            return;
        }
    }
    printf("\nVehicle Not Found!\n");
}

int main() {
    struct Vehicle vehicles[MAX];
    int n = 0, choice;

    while(1) {
        printf("\n---- Vehicle Management System ----\n");
        printf("1. Add Vehicle\n");
        printf("2. Display Vehicles\n");
        printf("3. Search Vehicle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addVehicle(vehicles, &n); break;
            case 2: displayVehicles(vehicles, n); break;
            case 3: searchVehicle(vehicles, n); break;
            case 4: return 0;
            default: printf("\nInvalid choice!\n");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a property
struct Property {
    int id;
    char type[100];
    char location[100];
    double price;
};

// Define an array to store property data
struct Property properties[100];
int propertyCount = 0;

// Function to display all properties
void display_prop() {
    if (propertyCount == 0) {
        printf("No properties available.\n");
        return;
    }

    printf("Properties:\n");
    for (int i = 0; i < propertyCount; i++) {
        printf("Property ID: %d\n", properties[i].id);
        printf("Type: %s\n", properties[i].type);
        printf("Location: %s\n", properties[i].location);
        printf("Price: %.2lf\n", properties[i].price);
        printf("----------------------------\n");
    }
}

// Function to display properties by type
void display_type_prop() {
    if (propertyCount == 0) {
        printf("No properties available.\n");
        return;
    }

    char type[100];
    printf("Enter the type of property: ");
    scanf("%s", type);

    printf("Properties of type '%s':\n", type);
    for (int i = 0; i < propertyCount; i++) {
        if (strcmp(properties[i].type, type) == 0) {
            printf("Property ID: %d\n", properties[i].id);
            printf("Type: %s\n", properties[i].type);
            printf("Location: %s\n", properties[i].location);
            printf("Price: %.2lf\n", properties[i].price);
            printf("----------------------------\n");
        }
    }
}

// Function to display the number of available properties
int display_number() {
    printf("Total number of properties available: %d\n", propertyCount);
    return propertyCount;
}

// Function to add a property
void add_prop() {
    if (propertyCount >= 100) {
        printf("Cannot add more properties. The limit is reached.\n");
        return;
    }

    printf("Enter property type: ");
    scanf("%s", properties[propertyCount].type);

    printf("Enter property location: ");
    scanf("%s", properties[propertyCount].location);

    printf("Enter property price: ");
    scanf("%lf", &properties[propertyCount].price);

    properties[propertyCount].id = propertyCount + 1;
    propertyCount++;

    printf("Property added successfully.\n");
}

// Function to remove a property by ID
void remove_prop() {
    if (propertyCount == 0) {
        printf("No properties available to remove.\n");
        return;
    }

    int idToRemove;
    printf("Enter the ID of the property to remove: ");
    scanf("%d", &idToRemove);

    int found = 0;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].id == idToRemove) {
            found = 1;
            for (int j = i; j < propertyCount - 1; j++) {
                properties[j] = properties[j + 1];
            }
            propertyCount--;
            printf("Property with ID %d removed successfully.\n", idToRemove);
            break;
        }
    }

    if (!found) {
        printf("Property with ID %d not found.\n", idToRemove);
    }
}

// Function to modify a property by ID
void modify_prop() {
    if (propertyCount == 0) {
        printf("No properties available to modify.\n");
        return;
    }

    int idToModify;
    printf("Enter the ID of the property to modify: ");
    scanf("%d", &idToModify);

    int found = 0;
    for (int i = 0; i < propertyCount; i++) {
        if (properties[i].id == idToModify) {
            found = 1;
            printf("Enter the updated property type: ");
            scanf("%s", properties[i].type);

            printf("Enter the updated property location: ");
            scanf("%s", properties[i].location);

            printf("Enter the updated property price: ");
            scanf("%lf", &properties[i].price);

            printf("Property with ID %d modified successfully.\n", idToModify);
            break;
        }
    }

    if (!found) {
        printf("Property with ID %d not found.\n", idToModify);
    }
}

int main() {
    int choice0, choice1;
    char m;

    printf("\t\t\t\t\t\tReal-estate Advisor\n\n\n\n");
    printf("Are you a buyer or seller?\n\n");
    printf("Enter 'b' for buyer or 's' for seller: ");
    scanf(" %c", &m);

    while (1) {
        if (m == 'b') {
            system("cls");
            printf("1 Display all properties\n");
            printf("2 Display by type of property\n");
            printf("3 Display number of properties available\n");
            printf("4 Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice0);

            switch (choice0) {
                case 1:
                    display_prop();
                    break;
                case 2:
                    display_type_prop();
                    break;
                case 3:
                    display_number();
                    break;
                case 4:
                    return 0;
                default:
                    printf("Invalid entry\n");
            }
        } else if (m == 's') {
            system("cls");
            printf("1 Add property for sale\n");
            printf("2 Remove property\n");
            printf("3 Modify property\n");
            printf("4 Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice1);

            switch (choice1) {
                case 1:
                    add_prop();
                    break;
                case 2:
                    remove_prop();
                    break;
                case 3:
                    modify_prop();
                    break;
                case 4:
                    return 0;
                default:
                    printf("Invalid entry\n");
            }
        } else {
            printf("Invalid choice\n");
            return 1;
        }
    }

    return 0;
}

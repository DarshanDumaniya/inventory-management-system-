#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

// Structure to represent an inventory item
typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount < MAX_ITEMS) {
        Item newItem;
        newItem.id = itemCount + 1;

        printf("Enter item name: ");
        scanf("%s", newItem.name);

        printf("Enter quantity: ");
        scanf("%d", &newItem.quantity);

        printf("Enter price: ");
        scanf("%f", &newItem.price);

        inventory[itemCount] = newItem;
        itemCount++;
        printf("Item added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void displayItems() {
    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    char searchName[NAME_LEN];
    printf("Enter the name of the item to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, searchName) == 0) {
            printf("Item found: ID: %d, Name: %s, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void updateItem() {
    int id;
    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    if (id > 0 && id <= itemCount) {
        printf("Enter new quantity: ");
        scanf("%d", &inventory[id-1].quantity);

        printf("Enter new price: ");
        scanf("%f", &inventory[id-1].price);

        printf("Item updated successfully!\n");
    } else {
        printf("Invalid ID!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            searchItem();
            break;
        case 4:
            updateItem();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
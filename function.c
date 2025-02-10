#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatype.h"
#include "function.h"

struct Category categories[MAX_CATEGORIES];
int category_count = 0;

// ********** MENU HIEN THI **********

// menu chuc nang quan ly
void startMenu() {
    int choice;
    do {
        printf("*** STORE MANAGEMENT SYSTEM USING C ***\n\n");
        printf("     CHOOSE YOUR ROLE\n");
        printf("===========================\n");
        printf("[1]. Portfolio Management\n");
        printf("[2]. Product Management\n");
        printf("[3]. Admin Authentication\n");
        printf("[0]. Exit the program\n");
        printf("===========================\n");
        printf("Please choose your role: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
            	//
            	break;
            case 3:
            	//
            	break;
            case 0:
                exit(1);
            default:
                printf("please choose again!\n");
                break;
        }
    } while (choice != 0);
}

// hien thi danh sach danh muc
void displayMenu() {
    int choice;
    do {
        printf("*** STORE MANAGEMENT SYSTEM USING C ***\n\n");
        printf("     CATEGORY MANAGEMENT\n");
        printf("===========================\n");
        printf("[1]. Show category list\n");
        printf("[2]. Add category\n");
        printf("[3]. Edit category\n");
        printf("[4]. Delete category\n");
        printf("[5]. Search category\n");
        printf("[6]. Sort categories by name\n");
        printf("[7]. Check data for category\n");
        printf("[8]. Save data\n");
        printf("[0]. Return\n");
        printf("===========================\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                showCategoryList();
                break;
            case 2:
                addCategoryList();
                break;
            case 3:
                editCategory();
                break;
            case 4:
                deleteCategory();
                break;
            case 5:
                searchCategory();
                break;
            case 6:
                sortCategories();
                break;
            case 7:
                // Check data for category function
                break;
            case 8:
                saveCategories();
                break;
            case 0:
                printf("\n_______________ RETURN _______________\n\n");
                break;
            default:
                printf("please choose again!\n");
                break;
        }
    } while (choice != 0);
}

// ********** CAC CHUC NANG TRONG MENU **********
// hien thi danh muc
void showCategoryList() {
    if (category_count == 0) {
        printf("No categories found.\n");
    } else {
        printf("\n");
        printf("+-----+---------------------------+\n");
        printf("| %-3s | %-25s |\n", "ID", "NAME");
        printf("+-----+---------------------------+\n");
        for (int i = 0; i < category_count; i++) {
            printf("| %-3s | %-25s |\n", categories[i].CategoryID, categories[i].CategoryName);
            printf("+-----+---------------------------+\n");
        }
    }
}

// them danh muc
void addCategoryList() {
    if (category_count >= MAX_CATEGORIES) {
        printf("Cannot add new category. The category limit has been reached.\n");
        return;
    }

    struct Category newCategory;
    printf("Enter category information\n");

    printf("Enter Category ID: ");
    scanf("%s", newCategory.CategoryID);

    printf("Enter Category Name: ");
    scanf("%s", newCategory.CategoryName);

    categories[category_count] = newCategory;
    category_count++;

    printf("Category added successfully.\n");
}

// sua danh muc
void editCategory() {
    char id[10];
    printf("Enter the id of the category to edit: ");
    scanf("%s", id);

    int index = findCategoryByID(id);
    if (index == -1) {
        printf("Category ID does not exist.\n");
        return;
    }

    printf("Current Category Name: %s\n", categories[index].CategoryName);
    printf("Enter new Category Name: ");
    scanf("%s", categories[index].CategoryName);

    printf("Category information updated successfully.\n");
}

// xoa danh muc
void deleteCategory() {
    char id[10];
    printf("Enter the id of the category to delete: ");
    scanf("%s", id);

    int index = findCategoryByID(id);
    if (index == -1) {
        printf("Category ID does not exist.\n");
        return;
    }

    for (int i = index; i < category_count - 1; i++) {
        categories[i] = categories[i + 1];
    }
    category_count--;

    printf("Category deleted successfully.\n");
}

// tim kiem danh muc theo id
int findCategoryByID(char *id) {
    for (int i = 0; i < category_count; i++) {
        if (strcmp(categories[i].CategoryID, id) == 0) {
            return i;
        }
    }
    return -1;
}

// tim kiem danh muc theo ten
void searchCategory() {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the category to search: ");
    scanf("%s", name);

    int found = 0;
    printf("\nSEARCH RESULTS\n");
    printf("+-----+---------------------------+\n");
    printf("| %-3s | %-25s |\n", "ID", "NAME");
    printf("+-----+---------------------------+\n");
    for (int i = 0; i < category_count; i++) {
        if (strstr(categories[i].CategoryName, name) != NULL) {
            printf("| %-3s | %-25s |\n", categories[i].CategoryID, categories[i].CategoryName);
            printf("+-----+---------------------------+\n");
            found = 1;
        }
    }

    if (!found) {
        printf("No categories found.\n");
    }
}

// sap xep danh muc
void sortCategories() {
    int order;
    printf("Choose the order to sort categories:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Your choice: ");
    scanf("%d", &order);

    for (int i = 0; i < category_count - 1; i++) {
        for (int j = i + 1; j < category_count; j++) {
            if ((order == 1 && strcmp(categories[i].CategoryName, categories[j].CategoryName) > 0) ||
                (order == 2 && strcmp(categories[i].CategoryName, categories[j].CategoryName) < 0)) {
                struct Category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }

    printf("Category list sorted successfully.\n");
    showCategoryList();
}

// mo va luu file
void loadCategories() {
    FILE *file = fopen("category.bin", "r");
    if (file == NULL) {
        printf("Cannot open data file.\n");
        return;
    }

    while (fscanf(file, "%s %s", categories[category_count].CategoryID, categories[category_count].CategoryName) != EOF) {
        category_count++;
    }

    fclose(file);
}

// dong va luu file
void saveCategories() {
    FILE *file = fopen("category.bin", "w");
    if (file == NULL) {
        printf("Cannot open file to save data.\n");
        return;
    }

    for (int i = 0; i < category_count; i++) {
        fprintf(file, "%s %s\n", categories[i].CategoryID, categories[i].CategoryName);
    }

    fclose(file);
}

//*********************************************

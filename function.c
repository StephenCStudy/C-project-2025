// noi trien khai cac ham
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"

// ********** MENU HIEN THI **********

// menu chuc nang quan ly
void startMenu() {
    int choice;
    do {
        printf("*** STORE MANAGEMENT SYSTEM USING C ***\n\n");
        printf("     CHOOSE YOUR ROLE\n");
        printf("===========================\n");
        printf("[1]. Portfolio Management\n");
        printf("[2]. Exit the program\n");
        printf("===========================\n");
        printf("Please choose your role: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                exit(0);
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
                //TODO
                break;
            case 2:
                addCategoryList();
                break;
            case 3:
                //TODO
                break;
            case 4:
                //TODO
                break;
            case 5:
                //TODO
                break;
            case 6:
                //TODO
                break;
            case 7:
                //TODO
                break;
            case 8:
                //TODO
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
// ********** ********** **********


// ********** THEM DANH MUC **********
void addCategoryList() {
    struct Category categoryList;
    printf("Enter category information\n");

    printf("Enter Category ID: ");
    scanf("%s", categoryList.CategoryID);

    printf("Enter Category Name: ");
    scanf("%s", categoryList.CategoryName);

    printf("\nCatalog information has been entered !\n");
    
}
// ********** ********** **********



// ********** SUA DANH MUC **********
void editCategory(){
	
	
	
	
}
// ********** ********** **********



// ********** DONG VA MO FILE **********
// mo va luu file
void loadCategories(){
	FILE *file = fopen("category.bin", "r");
	    if (file == NULL) {
	        printf("Cannot open data file.\n");
	        return;
	    }
	
//	    while (fscanf(file, "%s %s", categories[category_count].CategoryID, categories[category_count].CategoryName) != EOF) {
//	        category_count++
        fclose(file);
	    }

//dong va luu file
void saveCategories(){
	FILE *file = fopen("categories.txt", "w");
	    if (file == NULL) {
	        printf("Cannot open file to save data.\n");
	        return;
	    }
	
//	    for (int i = 0; i < category_count; i++) {
//	        fprintf(file, "%s %s\n", categories[i].CategoryID, categories[i].CategoryName);
//	    }
	
	    fclose(file);
};

// ********** ********** **********

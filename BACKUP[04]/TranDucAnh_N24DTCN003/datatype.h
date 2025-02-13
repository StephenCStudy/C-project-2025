// noi inprot thu vien, khai bao struct.
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>  // Thu vien de su dung getch()
#define MAX 100
#define MAX_NAME 50
#define MAX_PASS 20

//***** CAU TRUC DU LIEU *****

// ngay,thang,nam
struct Date {
	int month,day,year;
};

struct AdminLogin{
	char name[MAX_NAME];
	char pass[MAX_PASS];
};

// thong tin
struct Product{
	char productID[10];
	char categoryID[10];
    char productName[10];
    int  price;
};

// san pham
 struct Category{
 	char CategoryID[10];
 	char CategoryName[10]; 
 };



 // con lai
 struct Order{
 	char OrderID[10];
 	char customerID[20];
 	struct Date date;
 	struct Product product;
 };
 //***** ***** ***** ***** *****

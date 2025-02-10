// noi inprot thu vien, khai bao struct.
#include <stdio.h>
#include <stdbool.h>

//***** CAU TRUC DU LIEU *****

// ngay,thang,nam
struct Date {
	int month,day,year;
};

// thong tin

struct Product{
	char productID[10];
	char categoryID[10];
    char productName[10];
    int quantily;
    int price;
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

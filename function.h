// khai bao nguyen mau ham


// ***** MENU HIEN THI *****
void portfolioMenu();
void startMenu();
void productMenu();
void adminMenu();
// ********** ********** **********


// ***** CAC CHUC NANG TRONG PORFOLIO *****
// THEM DANH MUC
void addCategoryList();
// SUA DANH MUC
void editCategory();
// XOA DANH MUC
void deleteCategory();
// TIM KIEM THEO TEN
void searchCategory();
// SAP XEP DANH MUC
void sortCategories();
// HIEN THI DANH MUC
void showCategoryList();
//TIM KIEM DANH MUC THEO ID
int findCategoryByID(char *id);
// ----- check data ----- 
void checkInputData(char* id, char* name);
  int isUniqueID(char* id);
  int isUniqueName(char* name);
  int isValidLength(char* data);
// ----- ----- ----- ----- -----
// ----- MO,DONG FILE -----
// mo file
void loadCategories();
//dong file
void saveCategories();
// ----- ----- ----- ----- -----
// ********** ********** **********


// ***** CAC CHUC NANG TRONG PRODUCT *****
// HIEN THI SAN PHAM
void showProductList();
// THEM SAN PHAM
void addProduct();
// SUA SAN PHAM
void editProduct();
// XOA SAN PHAM
void deleteProduct();
// TIM KIEM SAN PHAM 
void searchProduct();
// SAP XEP SAN PHAM
void sortProducts();
//LOC SAN PHAM THEO GIA / DANH MUC
void filterProducts();
// ----- check data ----- 
void checkProductInput(char* id, char* name, float* price, char* categoryID);
   int findProductByID(char* id);
   int isUniqueProductID(char* id);
   int isUniqueProductName(char* name);
   int isValidLength(char* data);
// ----- ----- ----- ----- -----
// ----- MO,DONG FILE -----
// mo file
void loadProducts();
//dong file
void saveProducts();
// ----- ----- ----- ----- -----
// ********** ********** **********


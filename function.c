#include "datatype.h"
#include "function.h"

struct Category categories[MAX]; // cho {cau truc danh muc} toi da 100 phan tu 
int category_count = 0;  // bien dem biet co bao nhieu danh muc duoc tao
struct Product products[MAX];   // cho {cau truc thong tin} toi da 100 phan tu 
int product_count = 0;  // bien dem biet co bao nhieu thong tin duoc tao

//                                             ********** MENU HIEN THI **********
//------------------------------------------------menu chuc nang quan ly-------------------------------------------------------------------

void startMenu() {
    int choice;
    do {
        printf("                     *** STORE MANAGEMENT SYSTEM USING C ***\n\n");
        printf("                           CHOOSE YOUR ROLE\n");
        printf("                    ====================================\n");
        printf("                        [1]. Portfolio Management\n");
        printf("                        [2]. Product Management\n");
        printf("                        [3]. Admin Authentication\n");
        printf("                        [0]. Exit the program\n");
        printf("                    ====================================\n");
        printf("                    Please choose your role: ");
        scanf("%d", &choice);
        system("cls");
        switch (choice) {
            case 1:
                portfolioMenu();
                break;
            case 2:
            	productMenu();
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
//--------------------------------------------------hien thi danh sach danh muc------------------------------------------------------------------

void portfolioMenu() {
    int choice;
    do {
        printf("                     *** STORE MANAGEMENT SYSTEM USING C ***\n\n");
        printf("                           CATEGORY MANAGEMENT\n");
        printf("                    ====================================\n");
        printf("                        [1]. Show category list\n");
        printf("                        [2]. Add category\n");
        printf("                        [3]. Edit category\n");
        printf("                        [4]. Delete category\n");
        printf("                        [5]. Search category by name\n");
        printf("                        [6]. Sort categories by name\n");
        printf("                        [7]. Check data for category\n");
        printf("                        [8]. Save data\n");
        printf("                        [0]. Return\n");
        printf("                    ====================================\n");
        printf("                    Please choose an option: ");
        scanf("%d", &choice);
        system("cls");
        loadCategories();
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
                for (int i = 0; i < category_count; i++){
						checkInputData(categories[i].CategoryID, categories[i].CategoryName);
					}
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
//----------------------------------------------hien thi danh sach thong tin--------------------------------------------------------------------

void productMenu(){
	int choice;
	    do {
	        printf("                     *** STORE MANAGEMENT SYSTEM USING C ***\n\n");
	        printf("                             CATEGORY MANAGEMENT\n");
	        printf("                    ====================================\n");
	        printf("                        [1]. Show product list\n");
	        printf("                        [2]. Add more products\n");
	        printf("                        [3]. Edit products\n");
	        printf("                        [4]. Delete products\n");
	        printf("                        [5]. Search products by name\n");
	        printf("                        [6]. Sort categories by cost\n");
	        printf("                        [7]. Filter products by price or category\n");
	        printf("                        [8]. Check data for products\n");
	        printf("                        [9]. Save data\n");
	        printf("                        [0]. Return\n");
	        printf("                    ====================================\n");
	        printf("                    Please choose an option: ");
	        scanf("%d", &choice);
	        system("cls");
	        loadProduct();
	        switch (choice) {
	            case 1:
	                showProductList();
	                break;
	            case 2:
	                addProduct();
	                break;
	            case 3:
	                editProduct();
	                break;
	            case 4:
	                deleteProduct();
	                break;
	            case 5:
	                searchProduct();
	                break;
	            case 6:
	                sortProducts();
	                break;
	            case 7:
	            	//LOC SAN PHAM THEO GIA / DANH MUC
//	            	filterProducts();            		               
	                break;
	            case 8:
//	            	for (int i = 0; i < product_count; i++){
//			//				checkInputData(products[i].ProductID, product[i].CategoryId,product[i].productName,product[i].price);
//						}
					break;
	            case 9:
	            	saveProduct();
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
//----------------------------------------------hien thi adminLogin--------------------------------------------------------------------
void adminLogin() {
    char password[20];
    char correctPassword[20];
    char ch;
    int count_correctpassword;     // bien dem mat khau da luu va mat khau ng dung nhap tu ban phim
    system("color 0");
    loadPassword(correctPassword, sizeof(correctPassword));
    
    printf("                     *** STORE MANAGEMENT SYSTEM USING C ***\n\n");
    printf("                                     LOGIN                   \n");
    printf("                        ==================================     \n");
    printf("                         Email: TranDucAnh@gmail.com         \n");
    printf("                         Password: "                            );                 
    while (1) {
        count_correctpassword = 0;

        //----- Nhap tung ky tu va hien dau '*' -----
        while (1) {
            ch = getch();  // Lay ky tu tu ban phim ma khong hien ra man hinh

            if (ch == 13) {  // 13 la ma ASCII cua phim Enter
                password[count_correctpassword] = '\0';  // Ket thuc chuoi password
                break;
                //----- xoa ki tu vua moi nhap -----
            } else if (ch == 8) {  // 8 la ma ASCII cua phim Backspace
                if (count_correctpassword > 0) {
                    count_correctpassword--;  // Giam count_correctpassword de xoa ky tu cuoi
                    printf("\b \b");  // Xoa ky tu truoc do tren man hinh                                              
						// \b (Backspace): Di chuyen con tro ve vi tri truoc do
					    //  (Dau capach): Ghi de ky tu hien tai bang mot dau cach
					    //  \b (Backspace): Di chuyen con tro ve vi tri truoc do
                }
            } else {
                password[count_correctpassword++] = ch;  // Luu ky tu vua nhap vao  ham password va tang count_correctpassword
                printf("*");  // In dau '*' thay cho ky tu nhap vao
            }
        }

        printf("\n");

        // Kiem tra mat khau
        if (strcmp(password, correctPassword) == 0) {
        	system("cls");
            printf("                     ----- Login successfully! ----- \n");            
            startMenu();
            break;
        } else {
            printf("                    Incorrect password. Please try again.\n");
            printf("                        ----------------------------------     \n");
            printf("     Password: "); 
            
        }
    }
}

//                                               ********** CAC CHUC NANG TRONG MENU PORTPOLIO **********
//-------------------------------------------------hien thi danh muc-----------------------------------------------------------------------------

void showCategoryList() {
    if (category_count == 0) {
        printf("No categories found.\n");
    } else {
        printf("\n");
        printf("+------------+--------------------------------+\n");
        printf("| %-10s | %-30s |\n", "ID", "NAME");
        printf("+------------+--------------------------------+\n");
        for (int i = 0; i < category_count; i++) {
            printf("| %-10s | %-30s |\n", categories[i].CategoryID, categories[i].CategoryName);  //bien dem i gia tang de hien thi cho id,name
            printf("+------------+--------------------------------+\n");
        }
    }
}
//--------------------------------------------------------------them danh muc-------------------------------------------------------------------

void addCategoryList() {
    if (category_count >= MAX) {                                                     // cho toi da MAX=100 phan tu. mang tinh
        printf("Cannot add new category. The category limit has been reached.\n");
        return;
    }

    struct Category newCategory;                          // tao struct moi cho category
    printf("Enter category information\n");

    printf("Enter Category ID: ");                   // nhap id, name vao struct newCategory.
    scanf("%s", newCategory.CategoryID);

    printf("Enter Category Name: ");
    scanf("%s", newCategory.CategoryName);

    categories[category_count] = newCategory;   //Day la vitri tiep theo trong mang categories ma ban se luu tru danh muc moi (newCategory).
    category_count++;                // sau khi them danh muc moi thi tang bien kiem soat so luong danh muc len 1

    printf("Category added successfully.\n");
}
//-----------------------------------------------------sua danh muc-----------------------------------------------------------------------------

void editCategory() {
    char id[10];
    printf("Enter the id of the category to edit: ");
    scanf("%s", id);

    int indexCategory = findCategoryByID(id);                 // neu tim thay danh muc thi index == vitri id
    if (indexCategory == -1) {
        printf("Category ID does not exist.\n");
        return;
    }
//Hien thi ten hien tai cua danh muc de nguoi dung biet ho dang sua dung danh muc
    printf("Current Category Name: %s\n", categories[indexCategory].CategoryName); 
    printf("Enter new Category Name: ");
    scanf("%s", categories[indexCategory].CategoryName);

    printf("Category information updated successfully.\n");
}
//------------------------------------------------------xoa danh muc-----------------------------------------------------------------------------

void deleteCategory() {
    char id[10];                
    printf("Enter the id of the category to delete: ");              
    scanf("%s", id);                                           // cho nguoi dung nhap id muon xoa.

    int index = findCategoryByID(id);                  // vi tri la id duoc tim thay trong file bang ham findCategoryByID.
    if (index == -1) {
        printf("Category ID does not exist.\n");       // khong tim thay ( cho vitri = -1, no la gia tri khong xac dinh)
        return;
    }

    for (int i = index; i < category_count - 1; i++) {     // chay tu vitri ma id muon xoa den cuoi gia tri trong file.
        categories[i] = categories[i + 1];             // cho gia tri cua categories[i] tang len 1 don vi de thay the vitri mak id cu ton tai
    }
    category_count--;   // giam di so phan tu ton tai trong file

    printf("Category deleted successfully.\n");
}
//----------------------------------------------------tim kiem danh muc theo id-----------------------------------------------------------------------

int findCategoryByID(char *id) {                            // pointer id de tim kiem voi id trong file
    for (int i = 0; i < category_count; i++) {
        if (strcmp(categories[i].CategoryID, id) == 0) {    //compare id trong file voi id nhap vao --> true
            return i;                                       // tra ve gia tri id duoc tim thay
        }
    }
    return -1;         // khong tim thay ( cho no thanh -1, la gia tri khong xac dinh )
}
//----------------------------------------------------tim kiem danh muc theo ten-----------------------------------------------------------------

void searchCategory() {
    char name[MAX_NAME];
    printf("Enter the name of the category to search: ");
    scanf("%s", name);

    int found = 0;                                                              // cho bien tim thay la false
    printf("\nSEARCH RESULTS\n");
    printf("+------------+--------------------------------+\n");
    printf("| %-10s | %-30s |\n", "ID", "NAME");
    printf("+------------+--------------------------------+\n");
    for (int i = 0; i < category_count; i++) {                                     // chay full bien count duoc tao ra de tim kiem
        if (strstr(categories[i].CategoryName, name) != NULL) {      // neu so sanh thay name trong file == name duoc ghi --> found la true
            printf("| %-10s | %-30s |\n", categories[i].CategoryID, categories[i].CategoryName);
            printf("+------------+--------------------------------+\n");
            found = 1;
        }
    }

    if (!found) {                                                   // chay het chuong trinh, bien found == 0 thi khong tim thay.
        printf("No categories found.\n");
    }
}
//------------------------------------------------------sap xep danh muc------------------------------------------------------------------------
// sap xep theo ten
void sortCategories() {
    int sortChoice;
    printf("Choose the sortChoice to sort categories:\n");
    printf("1. Ascending(A-Z)\n");
    printf("2. Descending(Z-A)\n");
    printf("Your choice: ");
    scanf("%d", &sortChoice);

    for (int i = 0; i < category_count - 1; i++) {                             // bubble sort
        for (int j = 0; j < category_count -i -1; j++) {
            if ((sortChoice == 1 && strcmp(categories[j].CategoryName, categories[j+1].CategoryName) > 0) ||    //so sanh name voi name sau > 0
                (sortChoice == 2 && strcmp(categories[j].CategoryName, categories[j+1].CategoryName) < 0)) {    //so sanh name voi name sau < 0
                struct Category temp = categories[j];         // bien temp la gia tri danh muc dau
                categories[j] = categories[j+1];
                categories[j+1] = temp;
            }
        }
    }

    printf("Category list sorted successfully.\n");
    showCategoryList();
}
//--------------------------------------------------------kiem tra thong tin--------------------------------------------------------------------

void checkInputData(char* id, char* name) {
    while (1) {
        if (strlen(id) == 0 || strlen(name) == 0) { // kiem tra id va ten khong duoc empty
            printf("ID and Name cannot be empty. Please enter again.\n");
            printf("Enter Category ID: ");
            scanf("%s", id);
            printf("Enter Category Name: ");
            scanf("%s", name);
        } else if (!isValidLength(id) || !isValidLength(name)) { // kiem tra do dai hop le cua ten,id
            printf("ID and Name must have valid length. Please enter again.\n");
            printf("Enter Category ID: ");
            scanf("%s", id);
            printf("Enter Category Name: ");
            scanf("%s", name);
        } else if (!isUniqueID(id) || !isUniqueName(name)) { // kiem tra id va ten la duy nhat
            printf("ID and Name must be unique. Please enter again.\n");
            printf("Enter Category ID: ");
            scanf("%s", id);
            printf("Enter Category Name: ");
            scanf("%s", name);
        } else {
            break;
        }
    }
}
//                                 -------------------------------kiem tra id la duy nhat---------------------------------

int isUniqueID(char* id) {
    for (int i = 0; i < category_count; i++) {
        if (strcmp(categories[i].CategoryID, id) == 0) {
            return 0;
        }
    }
    return 1;
}
//                               -------------------------------kiem tra ten la duy nhat----------------------------------

int isUniqueName(char* name) {
    for (int i = 0; i < category_count; i++) {
        if (strcmp(categories[i].CategoryName, name) == 0) {
            return 0;
        }
    }
    return 1;
}
//                               -------------------------------kiem tra do dai hop le cua ten,id---------------------------

int isValidLength(char* data) {
    return strlen(data) > 0 && strlen(data) < MAX_NAME;
}
//----------------------------------------------------------------doc va luu file----------------------------------------------------------------

void loadCategories() {
    FILE *file;
    file = fopen("category.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "Cannot open data file.\n");
        return;
    }

//    category_count = 0; // Khoi tao lai bien danh muc

    while (fread(&categories[category_count], sizeof(categories), 1, file) == 1) {
        category_count++;
    }

    fclose(file);
    printf("                     ----- Categories loaded successfully. -----\n");
}

//---------------------------------------------------------------ghi va luu file-----------------------------------------------------------------

void saveCategories() {
    FILE *file;
    file = fopen("category.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file to save data.\n");
        return;
    }

    for (int i = 0; i < category_count; i++) {
        fwrite(&categories[i], sizeof(categories), 1, file);
    }

    fclose(file);
    printf("                     ----- Categories saved successfully. ----- \n");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//                                                   *********************************************


//                                              ********** CAC CHUC NANG TRONG MENU PRODUCT **********
//---------------------------------------------------------hien thi thong tin----------------------------------------------------------------
void showProductList(){
    if (product_count == 0) {
	        printf("No products found.\n");
	    } else {
	        printf("\n");
	        printf("+------------+------------+--------------------------------+------------+\n");
	        printf("| %-10s | %-10s | %-30s | %-10s |\n", "productID","categoryID","NAME","price");
	        printf("+------------+------------+--------------------------------+------------+\n");
	        for (int i = 0; i < product_count; i++) {
	            printf("| %-10s | %-10s | %-30s | %-10d |\n", products[i].productID,products[i].categoryID,products[i].productName,products[i].price);  //bien dem i gia tang de hien thi cho id,name
	            printf("+------------+------------+--------------------------------+------------+\n");
	    }
	}
}	
//----------------------------------------------------------them thong tin------------------------------------------------------------------
void addProduct() {
    if (product_count >= MAX) {
        printf("Cannot add more products. Product limit reached.\n");
        return;
    }
                                                        // giong voi tao moi Category.
    struct Product newProduct;
    printf("Enter product information\n");

    printf("Enter Product ID: ");
    scanf("%s", newProduct.productID);

    printf("Enter Category ID: ");
    scanf("%s", newProduct.categoryID);

    printf("Enter Product Name: ");
    scanf("%s", newProduct.productName);

    printf("Enter Product Price: ");
    scanf("%d", &newProduct.price);

    products[product_count] = newProduct;  //Day la vitri tiep theo trong mang product ma ban se luu tru danh muc moi (newproudct).
    product_count++;            // sau khi them thong tin moi thi tang bien kiem soat so luong thong tin len 1

    printf("                     ----- Product added successfully. ----- \n");
}

//---------------------------------------------------------chinh sua thong tin--------------------------------------------------------------------
void editProduct() {
    char id[10];
    printf("Enter the Product ID to edit: ");
    scanf("%s", id);                                           // giong voi ham cua Category.

    int indexProduct = findProductByID(id);
    if (indexProduct == -1) {
        printf("Product ID does not exist.\n");
        return;
    }

    printf("Current Product Name: %s\n", products[indexProduct].productName);        // hien thi xem thong tin co dung la thu muon chinh sua khong
    printf("Enter new Product Name: ");
    scanf("%s", products[indexProduct].productName);

    printf("Current Product Price: %d\n", products[indexProduct].price);
    printf("Enter new Product Price: ");
    scanf("%d", &products[indexProduct].price);

    printf("                     ----- Product information updated successfully. ----- \n");
}

//-------------------------------------------------------xoa thong tin-----------------------------------------------------------------
void deleteProduct() {
    char id[10];
    printf("Enter the Product ID to delete: ");
    scanf("%s", id);

    int indexProduct = findProductByID(id);
    if (indexProduct == -1) {
        printf("Product ID does not exist.\n");
        return;
    }

    for (int i = indexProduct; i < product_count - 1; i++) {
        products[i] = products[i + 1];
    }
    product_count--;

    printf("                     ----- Product deleted successfully. ----- \n");
}

//-------------------------------------------------------tim kiem thong tin-----------------------------------------------------------------
void searchProduct() {
    char name[MAX_NAME];
    printf("Enter the product name to search: ");
    scanf("%s", name);

    int found = 0;
    printf("\nSEARCH RESULTS\n");
    printf("+------------+------------+--------------------------------+------------+\n");
    printf("| %-10s | %-10s | %-30s | %-10s |\n", "ProductID", "CategoryID", "Product Name", "Price");
    printf("+------------+------------+--------------------------------+------------+\n");
    for (int i = 0; i < product_count; i++) {
        if (strstr(products[i].productName, name) != NULL) {
            printf("| %-10s | %-10s | %-30s | %-10d |\n", products[i].productID, products[i].categoryID, products[i].productName, products[i].price);
            found = 1;
        }
    }
    printf("+------------+------------+--------------------------------+------------+\n");

    if (!found) {
        printf("                     ----- No products found. -----\n");
    }
}

//-----------------------------------------------------sap xep thong tin-----------------------------------------------------------------
void sortProducts() {
    int sortChoice;
    printf("                    Choose the sorting option:\n");
    printf("                    [1]. Ascending by Price\n");
    printf("                    [2]. Descending by Price\n");
    printf("Your choice: ");
    scanf("%d", &sortChoice);

    for (int i = 0; i < product_count - 1; i++) {
        for (int j = 0; j < product_count - i - 1; j++) {
            if ((sortChoice == 1 && products[j].price > products[j + 1].price) || 
                (sortChoice == 2 && products[j].price < products[j + 1].price)) {
                struct Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    printf("                     ----- Product list sorted successfully. ----- \n");
    showProductList();
}
//---------------------------------------------------ghi vao file------------------------------------------------------
void saveProduct() {
    FILE *file;
    file = fopen("product.bin", "wb");
    if (file == NULL) {
        printf("Cannot open file to save data.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        fwrite(&products[i], sizeof(products), 1, file);
    }
    fclose(file);
    printf("                     ----- Products saved successfully. ----- \n");
}

//---------------------------------------------------doc va luu file---------------------------------------------------------------
void loadProduct() {
    FILE *file;
    file = fopen("product.bin", "rb");
    if (file == NULL) {
        printf("Cannot open data file.\n");
        return;
    }

//    product_count = 0;   // reset lai cac thong tin co san.
    while (fread(&products[product_count], sizeof(products), 1, file) == 1) {
        product_count++;
    }

    fclose(file);
    printf("                     ----- Products loaded successfully. ----- \n");
}

//------------------------------------------------tim kiem thong tin bang id----------------------------------------------------------
int findProductByID(char *id) {                            // pointer id de tim kiem voi id trong file
    for (int i = 0; i < product_count; i++) {
        if (strcmp(products[i].productID, id) == 0) {    //compare id trong file voi id nhap vao --> true
            return i;                                       // tra ve gia tri id duoc tim thay
        }
    }
    return -1;         // khong tim thay ( cho no thanh -1, la gia tri khong xac dinh )
}	
//-------------------------------------------------------------------------------------------------------------------------------------------
void savePassword(const char *password) {
    FILE *file = fopen("adminLogin.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file to save password.\n");
        return;
    }
    fwrite(password, sizeof(char), strlen(password) + 1, file);
    fclose(file);
    printf("                     ----- Password saved successfully. ----- \n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------
void loadPassword(char *correctPassword, size_t size) {
    FILE *file = fopen("adminLogin.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "Cannot open password file.\n");
        return;
    }
    fread(correctPassword, sizeof(char), size, file);
    fclose(file);

    correctPassword[strcspn(correctPassword, "\n")] = 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------


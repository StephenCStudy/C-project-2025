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
            	printf("Cooming soon");
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
	loadCategories();
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
//        printf("                        [7]. Check data for category\n");
        printf("                        [7]. Save data\n");
        printf("                        [0]. Return\n");
        printf("                    ====================================\n");
        printf("                    Please choose an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n'); // Xoa bo dem dau vao.
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
//            case 7:{
//            	int checkInput_count = 1;
//            	for (int i = 0; i < category_count; i++) {
//            	checkInput_count = checkInputData(categories[i].CategoryID, categories[i].CategoryName);
//                if(checkInput_count == 0){
//					continue;
//				} else{
//					printf("corret all \n");
//				}
//            	}
//            }
//                break;
                
            case 7:
                saveCategories();
                break;
            case 0:
                printf("\n                           _______________ RETURN _______________\n\n");
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
//	        printf("                        [8]. Check data for products\n");
	        printf("                        [8]. Save data\n");
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
	            	printf("Cooming soon");
	            	//LOC SAN PHAM THEO GIA / DANH MUC
//	            	filterProducts();            		               
	                break;
//	            case 8:
//	            	printf("Cooming soon");
////	            	for (int i = 0; i < product_count; i++){
////			//				checkInputData(products[i].ProductID, product[i].CategoryId,product[i].productName,product[i].price);
////						}
//					break;
	            case 8:
	            	saveProduct();
	            	break;
	            case 0:
	                printf("\n                           _______________ RETURN _______________\n\n");
	                break;
	            default:
	                printf("please choose again!\n");
	                break;
	        }
	    } while (choice != 0);
}
//----------------------------------------------hien thi adminLogin--------------------------------------------------------------------
void adminLogin() {
    char password[MAX_PASS];
    char correctPassword[MAX_PASS];
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
        count_correctpassword = 0; // bien dem ki tu la 0,moi lan nhap ki tu thi +1.

        //----- Nhap tung ky tu va hien dau '*' -----
        while (1) {
            ch = getch();  // Lay ky tu tu ban phim ma khong hien ra man hinh

            if (ch == 13) {  // 13 la ma ASCII cua phim Enter
                password[count_correctpassword] = '\0';  // Ket thuc chuoi password
                break;
            }  else {
                password[count_correctpassword++] = ch;  // Luu ky tu vua nhap vao  ham password va tang count_correctpassword
                printf("*");  // In dau '*' thay cho ky tu nhap vao
            }
        }

        printf("\n");

        // Kiem tra mat khau
        if (strcmp(password, correctPassword) == 0) {
        	system("cls");
            printf("                           ----- Login successfully! ----- \n");            
            startMenu();
            getchar();
            break;
        } else {
            printf("                       Incorrect password. Please try again.\n");
            printf("                        ----------------------------------     \n");
            printf("                         Password: "); 
            
        }
    }
}

//                                               ********** CAC CHUC NANG TRONG MENU PORTPOLIO **********
//-------------------------------------------------hien thi danh muc-----------------------------------------------------------------------------

void showCategoryList() {
    if (category_count == 0) {
        printf("                           No categories found.\n");
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
	        printf("                           Cannot add new category. The category limit has been reached.\n");
	        return;
	    }
	
	    struct Category newCategory;                          // tao struct moi cho category
	    printf(" ----- Enter category information ----- \n");
	
	    printf("Enter Category ID: ");                   // nhap id, name vao struct newCategory.
	    // fgets doc ca dau enter. nen phai dung getchar(). nhung lam vay de bi nuot kitu.	
	    fgets(newCategory.CategoryID, sizeof(newCategory.CategoryID), stdin);
	    newCategory.CategoryID[strcspn(newCategory.CategoryID, "\n")] = '\0'; // xoa ki tu xuong dong.
	    // Kiem tra neu ID trong
		    if (strlen(newCategory.CategoryID) == 0) {
		        printf("                           Error: Category ID cannot be empty!\n");
		        return;
		    }
		
		    // Kiem tra trung ID
		    for (int i = 0; i < category_count; i++) {
		        if (strcmp(categories[i].CategoryID, newCategory.CategoryID) == 0) {
		            printf("                           Error: Category ID already exists!\n");
		            return;
		        }
		    }
	    do {
	    printf("Enter Category Name: ");
	    fgets(newCategory.CategoryName, sizeof(newCategory.CategoryName), stdin);
	    newCategory.CategoryName[strcspn(newCategory.CategoryName, "\n")] = '\0'; // xoa ki tu xuong dong.
	    }while(strlen(newCategory.CategoryName) == 0); //nhap lai neu nhap rong.
	    
	    // Kiem tra va xac nhan du lieu.
	    if(checkInputData(newCategory.CategoryID, newCategory.CategoryName,category_count) != 0){
			categories[category_count] = newCategory;   //Day la vitri tiep theo trong mang categories ma ban se luu tru danh muc moi (newCategory).
				    category_count++;                // sau khi them danh muc moi thi tang bien kiem soat so luong danh muc len 1
				    printf("                           Category added successfully.\n");
				    saveCategories();
				    return;
		}
	    
	}
//-----------------------------------------------------sua danh muc-----------------------------------------------------------------------------

void editCategory() {
    char id[10];
    printf("                           Enter the id of the category to edit: ");
    scanf("%s", id);
    while (getchar() != '\n'); //xoa bo nho dem trong stdin.
    int indexCategory = findCategoryByID(id);
    if (indexCategory == -1) {
        printf("                           Category ID does not exist.\n");
        return;
    }

    printf("Current Category Name: %s\n", categories[indexCategory].CategoryName);
    
    // Kiem tra va xac nhan du lieu moi
    char newCategoryName[MAX_NAME];
    do{
    printf("Enter new Category Name: ");
    fgets(newCategoryName, sizeof(newCategoryName), stdin);
    newCategoryName[strcspn(newCategoryName, "\n")] = '\0';
    }while(strlen(newCategoryName) == 0); // lap lai neu nhap rong.
    
    // Dung ham checkInputData de kiem tra du lieu
    if(checkInputData(id, newCategoryName,indexCategory) == 1){
	// Cap nhat ten danh muc
	    strcpy(categories[indexCategory].CategoryName, newCategoryName);
	    printf("                           Category information updated successfully.\n");
	    saveCategories();
	} else{
		return;
	}    
}

//------------------------------------------------------xoa danh muc-----------------------------------------------------------------------------

void deleteCategory() {
    char id[10];                
    printf("                           Enter the id of the category to delete: ");              
    scanf("%9s", id);    // cho nguoi dung nhap id muon xoa. id duoc khai bao la 10--> "9s".
    while (getchar() != '\n');  // xoa bo nho dem.
    int index = findCategoryByID(id);                  // vi tri la id duoc tim thay trong file bang ham findCategoryByID.
    if (index == -1) {
        printf("                           Category ID does not exist.\n");       // khong tim thay ( cho vitri = -1, no la gia tri khong xac dinh)
        return;
    }
    char confirm; // bien xac nhan lua chon Y/N
    do{
    printf("                           Are you want to delete this category (Y/N): ");
    scanf("%c", &confirm);
    while (getchar() != '\n');	// xoa bo nho dem.
    }while (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n'); // lap cho toi khi chon y/n.
    if(confirm == 'Y' || confirm == 'y'){
    	// dich chuyen cac phan tu trong mang de ghi de phan tu bi xoa.
		for (int i = index; i < category_count - 1; i++) {     // chay tu vitri ma id muon xoa den cuoi gia tri trong file.
		        categories[i] = categories[i + 1];             // cho gia tri cua categories[i] tang len 1, de ghi de vitri mak id cu ton tai
		    }
		    category_count--;   // giam so luong danh muc.
		    saveCategories();
		    printf("                           Category deleted successfully.\n");
	}else{
		printf("                           \nCategory deletion cancelled.\n");
	}
    
}
//----------------------------------------------------tim kiem danh muc theo id-----------------------------------------------------------------------

int findCategoryByID(char *id) {                            // pointer id de tim kiem voi id trong file
    if (id == NULL) {
        return -1;  // Tranh loi khi tham so dau vao bi NULL.
    }
    if (category_count == 0) {
	        return -1;  // Neu khong co danh muc nao, khong can tim.
	}
	
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
    printf("                           Enter the name of the category to search: ");
    scanf("%29s", name); // cho MAX_NAME =30 --> "29s".
    while (getchar() != '\n'); // xoa bo nho dem.

    int found = 0;     // cho bien tim thay la false
    printf("\n                           SEARCH RESULTS\n");
    printf("+------------+--------------------------------+\n");
    printf("| %-10s | %-30s |\n", "ID", "NAME");
    printf("+------------+--------------------------------+\n");
    
    for (int i = 0; i < category_count; i++) {        // duyet qua tat ca danh muc.
        if (strstr(categories[i].CategoryName, name) != NULL) {      
		// kiem tra chuoi name trong[categories[i].CategoryName] --> tra ve vitri dau tien cua chuoi name trong[categories[i].CategoryName].
		// dk neu khong tim thay thi strstr tra ve null.
            printf("| %-10s | %-30s |\n", categories[i].CategoryID, categories[i].CategoryName);
            printf("+------------+--------------------------------+\n");
            found = 1;
        }
    }

    if (!found) {                      // chay het chuong trinh, bien found == 0 thi khong tim thay.
        printf("                           No categories found.\n");
    }
}
//------------------------------------------------------sap xep danh muc------------------------------------------------------------------------
// sap xep theo ten
void sortCategories() {
    int sortChoice;
    printf("                      Choose the sortChoice to sort categories:\n");
    printf("                        ==================================     \n");
    printf("                           [1]. Ascending(A-Z)\n");
    printf("                           [2]. Descending(Z-A)\n");
    printf("                        ==================================     \n");
    printf("                           Your choice: ");
    scanf("%d", &sortChoice);
    
    if (sortChoice != 1 && sortChoice != 2) {
	    printf("                           Invalid choice. Please choose 1 or 2.\n"); 
	return;
    } 
     // bubble sort
    // for1: dieu kien so lan lap qua mang.// for2: so sanh, hoan doi 2 phan tu lien ke
    for (int i = 0; i < category_count - 1; i++) {    //duyet qua tung phan tu.                        
        for (int j = 0; j < category_count -i -1; j++) { // so sanh, hoan doi.
        int compareName = strcmp(categories[j].CategoryName, categories[j+1].CategoryName); 
        
            if ((sortChoice == 1 && compareName > 0) || 
			// neu j lon hon j+1 [cmp>0]--> hoan doi vitri
                (sortChoice == 2 && compareName < 0)) {  
			//j nho hon j+1 [cmp<0] --> hoan doi vitri
                struct Category temp = categories[j];         // bien temp la gia tri danh muc dau
                categories[j] = categories[j+1];
                categories[j+1] = temp;
            }
        }
    }
    saveCategories();
    printf("                           Category list sorted successfully.\n");
    showCategoryList();
}
//--------------------------------------------------------kiem tra thong tin--------------------------------------------------------------------
// int indexCategory giup ham bo qua kiem tra danh muc o vi tri do. khong con la kiem tra tinh duy nhat (unique)
int checkInputData(char* id, char* name,int indexCategory) {  // ko sai con tro tai indexCategory vi chi can kiem tra phan tu hien tai trong categogries de xac dinh tinh duy nhat.

    if (strlen(id) == 0 || strlen(name) == 0) { // Kiem tra ID và ten khong duoc empty
        printf("                           ID and Name cannot be empty. Please enter again.\n");
        return 0;
    } else if (!isValidLength(id) || !isValidLength(name)) { // Kiem tra do dai hop le cua tên, ID, tra ve phu dinh.
        printf("                           ID and Name must have valid length. Please enter again.\n");
        return 0;
    } else if (!isUniqueID(id, indexCategory) || !isUniqueName(name, indexCategory)) { // Kiem tra ID va ten la duy nhat
        printf("                           ID and Name must be unique. Please enter again.\n");
        return 0;
    } else {
        printf("                           All data is correct.\n"); // Thong bao khi tat ca du lieu dung
        return 1;
    }
}

//                                 -------------------------------kiem tra id la duy nhat---------------------------------

int isUniqueID(char* id,int indexCategory) {
    for (int i = 0; i < category_count; i++) {
        if (i != indexCategory && strcmp(categories[i].CategoryID, id) == 0) {
            return 0;  // id da ton tai.
        }
    }
    return 1;  // id la duy nhat.
}
//                               -------------------------------kiem tra ten la duy nhat----------------------------------

int isUniqueName(char* name,int indexCategory) {
    for (int i = 0; i < category_count; i++) {
        if (i != indexCategory && strcmp(categories[i].CategoryName, name) == 0) { // i!= indexCategory : tranh kiem tra thong tin phan tu moi nhap vao.
            return 0; // ten da ton tai.
        }
    }
    return 1;  // ten le duy nhat.
}
//                               -------------------------------kiem tra do dai hop le cua ten,id---------------------------

int isValidLength(char* data) {
    return strlen(data) > 0 && strlen(data) < MAX_NAME; // tra ve 1 neu 2 dk dung.
}
//----------------------------------------------------------------doc va luu file----------------------------------------------------------------

void loadCategories() {
    FILE *file;
    file = fopen("category.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "                           Cannot open data file.\n");
        return;
    }

    // Doc so luong danh muc tu file
    fread(&category_count, sizeof(int), 1, file);

    // Doc mang danh muc tu file neu co danh muc de doc
    if (category_count > 0) {
        fread(categories, sizeof(struct Category), category_count, file);
    }

    fclose(file);
    printf("                           ----- Categories %d loaded successfully. -----\n", category_count); 
}


//---------------------------------------------------------------ghi va luu file-----------------------------------------------------------------

void saveCategories() {
    FILE *file;
    file = fopen("category.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "                           Cannot open file to save data.\n");
        return;
    }
    //ghi so luong danh muc vao file.
        fwrite(&category_count, sizeof(int), 1, file);  // -->kiem tra xem co giatri moi de luu
    if(category_count > 0){
    	// ghi mang danh muc vao file neu co san pham de luu.
		fwrite(categories,sizeof(struct Category),category_count,file); //sizeof(struct Category) cap phat bo nho {20byte}
	}                                                                    // category_count xem so phan tu de luu vao.
    fclose(file);
    printf("                           ----- Categories %d saved successfully. ----- \n", category_count);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//                                                   *********************************************


//                                              ********** CAC CHUC NANG TRONG MENU PRODUCT **********
//---------------------------------------------------------hien thi thong tin----------------------------------------------------------------
void showProductList(){
    if (product_count == 0) {
	        printf("                           No products found.\n");
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
        printf("                           Cannot add more products. Product limit reached.\n");
        return;
    }
                                                        // giong voi tao moi Category.
    struct Product newProduct;
    printf("                           Enter product information\n");
    
    

    printf("                           Enter Product ID: ");
    scanf("%s", newProduct.productID);
    fflush(stdin);

    printf("                           Enter Category ID: ");
    scanf("%s", newProduct.categoryID);
    fflush(stdin);

    printf("                           Enter Product Name: ");
    fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
    newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0';	

    printf("                           Enter Product Price: ");
    scanf("%d", &newProduct.price);
    fflush(stdin);

    products[product_count] = newProduct;  //Day la vitri tiep theo trong mang product ma ban se luu tru danh muc moi (newproudct).
    product_count++;            // sau khi them thong tin moi thi tang bien kiem soat so luong thong tin len 1
    saveProduct();
    printf("                           ----- Product added successfully. ----- \n");
}

//---------------------------------------------------------chinh sua thong tin--------------------------------------------------------------------
void editProduct() {
    char id[10];
    printf("                           Enter the Product ID to edit: ");
    scanf("%s", id);                                           // giong voi ham cua Category.
    fflush(stdin);

    int indexProduct = findProductByID(id);
    if (indexProduct == -1) {
        printf("                           Product ID does not exist.\n");
        return;
    }

    printf("Current Product Name: %s\n", products[indexProduct].productName);        // hien thi xem thong tin co dung la thu muon chinh sua khong
    printf("                           Enter new Product Name: ");
    fgets(products[indexProduct].productName, sizeof(products[indexProduct].productName), stdin);
    products[indexProduct].productName[strcspn(products[indexProduct].productName, "\n")] = '\0';  // xoa ki tu xuong dong

    printf("Current Product Price: %d\n", products[indexProduct].price);
    printf("                           Enter new Product Price: ");
    scanf("%d", &products[indexProduct].price);
    getchar();
    
    saveProduct();
    printf("                           ----- Product information updated successfully. ----- \n");
}

//-------------------------------------------------------xoa thong tin-----------------------------------------------------------------
void deleteProduct() {
    char id[10];
    printf("                           Enter the Product ID to delete: ");
    scanf("%s", id);
    fflush(stdin);

    int indexProduct = findProductByID(id);
    if (indexProduct == -1) {
        printf("                           Product ID does not exist.\n");
        return;
    }

    for (int i = indexProduct; i < product_count - 1; i++) {
        products[i] = products[i + 1];
    }
    product_count--;
    saveProduct();

    printf("                           ----- Product deleted successfully. ----- \n");
}

//-------------------------------------------------------tim kiem thong tin-----------------------------------------------------------------
void searchProduct() {
    char name[MAX_NAME];
    printf("                           Enter the product name to search: ");
    scanf("%s", name);
    fflush(stdin);

    int found = 0;
    printf("\n                           SEARCH RESULTS\n");
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
        printf("                           ----- No products found. -----\n");
    }
}

//-----------------------------------------------------sap xep thong tin-----------------------------------------------------------------
void sortProducts() {
    int sortChoice;
    printf("                           Choose the sorting option:\n");
    printf("                        ==================================     \n");
    printf("                           [1]. Ascending by Price\n");
    printf("                           [2]. Descending by Price\n");
    printf("                        ==================================     \n");
    printf("                           Your choice: ");
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

    printf("                           ----- Product list sorted successfully. ----- \n");
    showProductList();
}
//---------------------------------------------------ghi vao file------------------------------------------------------
void saveProduct() {
    FILE *file;
    file = fopen("product.bin", "wb");
    if (file == NULL) {
        fprintf(stderr, "                           Cannot open file to save data.\n");
        return;
    }

    // ghi so luong san pham vao file
    fwrite(&product_count, sizeof(int), 1, file);
    printf("                           Saving %d porduct.\n", product_count);
    
    // ghi mang san pham vao file neu co san pham de luu.
    if (product_count > 0) {
        fwrite(products, sizeof(struct Product), product_count, file); // sizeof(struct Product) : cap phat bo nho moi cho file
    }

    fclose(file);
    printf("                           ----- Products saved successfully. -----\n");
}


//---------------------------------------------------doc va luu file---------------------------------------------------------------
void loadProduct() {
    FILE *file;
    file = fopen("product.bin", "rb");
    if (file == NULL) {
        printf("                           Cannot open data file.\n");
        return;
    }

    // Doc so luong san pham tu file
    fread(&product_count, sizeof(int), 1, file);
    printf("                           Loading %d products.\n", product_count); // kiem tra 

    // Doc mang san pham tu file neu co san pham de doc
    if (product_count > 0) {
        fread(products, sizeof(struct Product), product_count, file);
    }

    fclose(file);
    printf("                           ----- Products loaded successfully. -----\n");
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
//----------------------------------------------------ghi mat khau vao file--------------------------------------------------------------
void savePassword(const char *password) {
    FILE *file = fopen("admin.bin", "wb");
//    if (file == NULL) {
//        fprintf(stderr, "Cannot open file to save password.\n");
//        return;
//    }
    fwrite(password, sizeof(char), strlen(password) + 1, file);  //strlen(password) + 1 : cong them ki tu null.
    fclose(file);
    printf("                           ----- Password saved successfully. ----- \n");
}
//----------------------------------------------------doc mat khau tu file---------------------------------------------------------------------
void loadPassword(char *correctPassword, size_t size) {
    FILE *file = fopen("admin.bin", "rb");
    if (file == NULL) {
        fprintf(stderr, "                           Cannot open password file.\n");
        return;
    }
    fread(correctPassword, sizeof(char), size, file);
    fclose(file);

    correctPassword[strcspn(correctPassword, "\n")] = 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------
//                                              *********************************************

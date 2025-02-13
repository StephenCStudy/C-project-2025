#include <stdlib.h>
#include "datatype.h"
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//int main(int argc, char *argv[]) {
//   loadCategories();
//	startMenu();
//
//	return 0;
//}
 int main (){
 	// tao va luu mat khau vao file nhi phan truoc khi chay chuong trinh 
 	char creatPassword[] = "003";
	savePassword(creatPassword);
 	adminLogin();
 	return 0;
 }

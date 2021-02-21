#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  
#include<ctype.h>                  
#include<dos.h>                    
#include<time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define BLACK 0
#define LIGHTGRAY 8
#define BLUE 9
#define GREEN 10
#define RED 12
#define YELLOW 14
#define WHITE 15
//color
void textColor(WORD color){
	HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//gotoxy
COORD coord = {0, 0};
void goToXY (int x, int y){
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//function
void passwordAdmin(void);
void t(void);
void mainMenu(void);
void adminMenu(void);
void finishProject(void);
void startProject(void);	
void addProduct(void);
void deleteProduct(void);
void editProduct(void);
void findProduct(void);
void sortProductPrice(void);
void sortProductName(void);
void customerMenu(void);
void buyProduct(void);
void printBill(void);
void voucher(void);
void gift(void);
void editGift(void);
void makeAccount(void);
void addMoney(void);
void luckyTicket(void);
void drawAnimation(void);
void congratulation(void);
void addVoucher(void);
void deleteVoucher(void);
void editVoucher(void);
void findVoucher(void);
void sortVoucherName(void);
void sortVoucher(void);
void customer(void);
void passwordCustomer(void);
void printCus(void);
void add(void);
void giveStar(void);
void feedback(void);
void readFeedback(void);
void changePass(void);
void animation(void);
void cart(void);
void mul(void);
void goodLuck(void);
void addCart(void);
void edit(void);
void deleteCart(void);
void confirm(void);
void deleteAll(void);
void animationPasswordAdmin(void);
void change(void);
int main(int argc, char *argv[]) {
	getch();
	startProject();
	getch();
	mainMenu();
	return 0;
}
//start project
void startProject(){
	goToXY(0, 8);
	t();
	goToXY(0, 10);
	printf("ADDRESS: FPT University, District 12, HCMC");
	textColor(10);
	goToXY(60, 20);
	printf("________   __________   _________     _________              _________  _________    ");
	goToXY(59, 21);
	printf("/          /         /  /             /           /        / /        / /        /");
	goToXY(58, 22);
	printf("/          /         /  /             /_________  /________/ /        / /________/        ");	
	goToXY(57, 23);
	printf("/________  /_________/  /_________    __________/ /        / /________/ /                ");
	textColor(14);
	//promotion 20% in fr
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		char product[200][20], checkFscanf;
		int i = 0, j;
		FILE *filePrint = fopen("listProduct.txt", "r");
		do{
			checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
			i++;
			if(checkFscanf == EOF) break;
		} while(checkFscanf != EOF);
		fclose(filePrint);
		for(j = 0; j < (i - 1) / 4; j++){
			itoa(atoi(product[4 * j + 2]) * 80 / 100, product[4 * j + 2], 10);
		}
		FILE *wr = fopen("listProduct.txt", "w");
		for(j = 0; j < i - 1; j++){
			fprintf(wr, product[j]);
			fprintf(wr, "\n");
		}
		fclose(wr);
	}
	//star
	char star[200][20], checkFscanfStar;
	int countStar = 0, k;
	float sum = 0;
	FILE *filePrintStar = fopen("star.txt", "r");
	do{
		checkFscanfStar = fscanf(filePrintStar, "%[^\n]%*c", star[countStar]);
		countStar++;
		if(checkFscanfStar == EOF) break;
	} while(checkFscanfStar != EOF);
	fclose(filePrintStar);
	for(k = 0; k < countStar - 1; k++){
		sum = sum + atoi(star[k]);
	}
	//average
	sum = sum / k;
	goToXY(80, 27);
	printf("SHOP IS EVALUATED: %.2f / 5 stars", sum);
	//loading
	textColor(15);
	animation();
}
//animation loading
void animation(){
	int i;
	goToXY(96, 29);
	printf(" 0%%");
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf("\xB2");
	}
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf(" ");
	}
	goToXY(96, 29);
	printf("25%%");
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf("\xB2");
	}
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf(" ");
	}
	goToXY(96, 29);
	printf("50%%");
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf("\xB2");
	}
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf(" ");
	}
	goToXY(96, 29);
	printf("75%%");
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf("\xB2");
	}
	goToXY(80, 29);
	for(i = 0; i < 33; i++){
		Sleep(50);
		printf(" ");
	}
	goToXY(96, 29);
	printf("100%%");
	goToXY(83, 35);
	printf("Press any key to start!!!");
}
//main menu
void mainMenu(){
	system("cls");
	goToXY(55, 20);
	textColor(10);
	printf("                           _____            _____   _____                    ____");
	goToXY(56, 21);
	printf("\\       /   \\       /    |        |       |       |     |    |  \\   /  |   |");
	goToXY(57, 22);
	printf("\\     /     \\     /     |_____   |       |       |     |    |   \\ /   |   |____");
	goToXY(58, 23);
	printf("\\   /       \\   /      |        |       |       |     |    |         |   |");
	goToXY(59, 24);
	printf("\\ /         \\ /       |_____   |____   |_____  |_____|    |         |   |____");
	goToXY(53, 26);
	textColor(15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 COC SHOP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 27);
	printf("1. ADMIN");
	goToXY(53, 29);
	printf("2. CUSTOMERS");
	goToXY(53, 31);
	printf("3. MAKE ACCOUNT");
	goToXY(53, 33);
	printf("4. CLOSE APPLICATION");
	goToXY(53, 34);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 39);
	printf("------> All products sale 20%% in every friday(not Fr 13th)!!!");
	goToXY(53, 40);
	printf("------> Sweepstake if you buy than 200000 or you buy in Sunday!!!");
	goToXY(53, 35);
	printf("Your choice is: ");
	switch(getch()){
		case '1' :
			animationPasswordAdmin();
			passwordAdmin();
			break;
		case '2' :
			passwordCustomer();
			customerMenu();
			break;
		case '4' :
			finishProject();
		case '3' :
			makeAccount();
		default :
			{
				goToXY(53, 35);
				printf("\aYour choice is invalid, please press any key and input again....");
				if(getch()){
					mainMenu();
				}
			}
	}
	
}
//admin menu
void adminMenu(){
	int choice, numFormat;
	char endChar;
	system("cls");
	goToXY(0, 8);
	t();
	//print list product
	char product[200][20], checkFscanf;
	int i = 0;
	FILE *filePrint = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	int j, k;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          PRICE                         QUATITY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(53, 12 + j);
		printf("%s", product[4 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", product[4 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", product[4 * j + 2]);
		goToXY(53 + 30 * 3, 12 + j);
		printf("%s", product[4 * j + 3]);
		if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
			goToXY(65 + 30 * 3, 12 + j);
			printf("-20%% in Fri");
		}
	}
	//print gift
	gift();
	//print menu
	goToXY(0, 14 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 16 + j);
	textColor(10);
	printf("ADMIN MENU");
	textColor(15);
	goToXY(53, 18 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 20 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1. Add products                                                \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5. Sort products");
	goToXY(53, 22 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2. Delete products                                             \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6. Go to...");
	goToXY(53, 24 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3. Edit list                                                   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 7. Exit");
	goToXY(53, 26 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4. Look up products                                            ");
	goToXY(53, 28 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	//get choice and check valid
	goToXY(53, 30 + j);
	printf("Get a choice: ");
	fflush(stdin);
	numFormat = scanf("%d%c", &choice, &endChar);
	if(numFormat != 2 || endChar != '\n' || choice < 1 || choice > 7){
		goToXY(53, 31 + j);
		printf("\aSorry! We don't have this choice. Please press any key to input a valid choice");
		if(getch()){
			adminMenu();
		}
	}
	if(choice == 6){
		goToXY(53, 34 + j);
		printf("1. Voucher menu");
		goToXY(53, 35 + j);
		printf("2. Customer menu");
		goToXY(53, 36 + j);
		printf("3. Main menu");
		switch(getch()){
			case '1':
				voucher();
				break;
			case '2':
				customer();
				break;
			case '3':
				mainMenu();
				break;
			default:
				goToXY(53, 37 + j);
				printf("\aInvalid Input!!! Press any key...");
				getch();
				adminMenu();
		}
	}
	if(choice == 7){
		finishProject();
	}
	if(choice == 1){
		addProduct();
	}
	if(choice == 2){
		deleteProduct();
	}
	if(choice == 3){
		editProduct();
	}
	if(choice == 4){
		findProduct();
		fflush(stdin);
		getch();
		adminMenu();
	}
	if(choice == 5){
		goToXY(0, 33 + (i - 1) / 4 - 1);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		goToXY(100, 35 + (i - 1) / 4 - 1);
		printf("SORT PRODUCT");
		goToXY(53, 38 + (i - 1) / 4 - 1);
		printf("1. Sort in Name");
		goToXY(53, 40 + (i - 1) / 4 - 1);
		printf("2. Sort in Price");
		switch(getch()){
			case '1':
				sortProductName();
				adminMenu();
			case '2': 
				sortProductPrice();
				adminMenu();
			default:
				{
				goToXY(53, 35 + j);
				printf("\aYour choice is invalid, please press any key and input again....");
				if(getch()){
					adminMenu();
				}
			}
		}
	}
	if(choice == 8){
		editGift();
	}
	
}
//animationPasswordAdmin
void animationPasswordAdmin(){
	system("cls");
	char strStart[17] = "ADMIN protection";
	int j;
	goToXY(53, 20);
	for(j = 0; j < 20; j++){
	Sleep(50);
	printf("_");
	}
	textColor(10);
	printf("\\\\ ");
	for(j = 0; j < 17; j++){
		Sleep(50);
		printf("%c", strStart[j]);
	}
	printf("//");
	textColor(15);
	for(j = 0; j < 20; j++){
		Sleep(50);
		printf("_");
	}
}

//password admin
void passwordAdmin(){
	system("cls");
	//read file password admin
	char passAdmin[20];
	FILE *fileInputAdminPass = fopen("passAdmin.txt", "r");
	fscanf(fileInputAdminPass, "%[^\n]%*c", passAdmin);
	fclose(fileInputAdminPass);
	char ch, pass[20], newPass[20];
	int i = 0, j;
	//go out with ESC
	printf("Press ESC to back to main menu");
	//animation
	char strStart[17] = "ADMIN protection";
	goToXY(53, 20);
	for(j = 0; j < 20; j++){
		printf("_");
	}
	textColor(10);
	printf("\\\\ ");
	for(j = 0; j < 17; j++){
		printf("%c", strStart[j]);
	}
	printf("//");
	textColor(15);
	for(j = 0; j < 20; j++){
		printf("_");
	}
	goToXY(53, 28);
	printf("Enter Password: ");
	//input password
	while(ch != 13){
		ch = getch();

		if(ch != 13 && ch != 8 && ch != 27){
			putch('*');
			pass[i] = ch;
			i++;
		}
		if(ch == 27){
			mainMenu();
		}
	}
	pass[i] = '\0';
	//check pass
	if(strcmp(pass, passAdmin) == 0){
		goToXY(53, 35);
		textColor(10);
		printf("____Hello Admin!!!_____");
		textColor(15);
		goToXY(53, 36);
		printf("1. Product menu                   2. Voucher menu");
		goToXY(53, 38);
		printf("3. Customer management            4. Edit password");
		goToXY(53, 40);
		printf("5. Main menu                      6. Exit");
		switch(getch()){
			case '1' :
				adminMenu();
				break;
			case '2' :
				voucher();
				break;
			case '4' :
				do{
					goToXY(53, 45);
					printf("                                             ");
					goToXY(53, 45);
					printf("New pass   : ");
					fflush(stdin);
					gets(newPass);
					if(strcmp(newPass, passAdmin) == 0){
						goToXY(53, 46);
						printf("New pass likes old pass");
					}
					if(strlen(newPass) == 0){
						goToXY(53, 46);
						printf("Please input....");
					}
					if(strlen(newPass) > 10){
						goToXY(53, 46);
						printf("The length of pass less than 11...");
					}
					if(!(strcmp(newPass, passAdmin) == 0 || strlen(newPass) == 0 || strlen(newPass) > 10)){
						goToXY(53, 46);
						printf("                                          ");
					}
				} while(strcmp(newPass, passAdmin) == 0 || strlen(newPass) == 0 || strlen(newPass) > 10);
				//input pass was changed
				FILE *inputNewPass = fopen("passAdmin.txt", "w");
				fprintf(inputNewPass, newPass);
				fclose(inputNewPass);
				goToXY(53, 47);
				printf("Data was saved...");
				goToXY(53, 48);
				printf("Press any key to back to main menu...");
				getch();
				mainMenu();
			case '5':
				mainMenu();
			case '6':
				finishProject();
			case '3':
				customer();
				break;
			default:
				{
				goToXY(53, 45);
				printf("\aYour choice is invalid, press any keys to input again....");
				if(getch()){
					passwordAdmin();
				}
			}
		}

	} else {
	goToXY(53, 39);
	printf("\aWarning!! Incorrect Password! Input again...");
	getch();
	passwordAdmin();
	}
}
//time
void t() {
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
}

//finish project
void finishProject(){
	system("cls");
	goToXY(53, 20);
	printf("_______GOODBYE AND SEE YOU LATER_________");
	goToXY(53, 22);
	t();
	goToXY(53, 24);
	printf("_________________________________________");
	goToXY(53, 30);
	printf("Close after 3s ....");
	//promotion
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		char product[200][20], checkFscanf;
		int i = 0, j;
		FILE *filePrint = fopen("listProduct.txt", "r");
		do{
			checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
			i++;
			if(checkFscanf == EOF) break;
		} while(checkFscanf != EOF);
		fclose(filePrint);
		for(j = 0; j < (i - 1) / 4; j++){
			itoa(atoi(product[4 * j + 2]) * 100 / 80, product[4 * j + 2], 10);
		}
		FILE *wr = fopen("listProduct.txt", "w");
		for(j = 0; j < i - 1; j++){
			fprintf(wr, product[j]);
			fprintf(wr, "\n");
		}
		fclose(wr);
	}
	Sleep(3000);
	exit(0);
}
//add product
void addProduct(){
	char product[5][20];
	int i, isNameCorrect = 1, isCodeCorrect = 1, coincideCode = 1, isPriceCorrect = 1, isQuantityCorrect = 1;
	//check code coincide
	char productInformation[200][20], checkFscanfInformation;
	int count = 0;
	FILE *fileCheckCode = fopen("listProduct.txt", "r"); 
	do{
		checkFscanfInformation = fscanf(fileCheckCode, "%[^\n]%*c", productInformation[count]); 
		count++;
		if(checkFscanfInformation == EOF) break;
	} while(checkFscanfInformation != EOF);
	fclose(fileCheckCode);
	goToXY(0, 33 + (count - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (count - 1) / 4 - 1);
	textColor(10);
	printf("ADD PRODUCT");
	goToXY(53, 37 + (count - 1) / 4 - 1);
	printf("Name    :                                                                           (Please input NAME don't have the special symbol and the length under 20)");
	goToXY(53, 39 + (count - 1) / 4 - 1);
	printf("Code    :                                                                           (CODE includes 3 numbers)");
	goToXY(53, 41 + (count - 1) / 4 - 1);
	printf("Price   :                                                                           (Only include numbers, not begin with 0, 0 < price < 10.000.000)");                                                                          
	goToXY(53, 43 + (count - 1) / 4 - 1);
	printf("Quantity:                                                                           (Only include numbers, not begin with 0, 0 < quantity < 1000)");
	textColor(15);
	//get name
	do{
		isNameCorrect = 1;
		goToXY(70, 37 + (count - 1) / 4 - 1);
		printf("                             ");
		goToXY(70, 37 + (count - 1) / 4 - 1);
		fflush(stdin);
		gets(product[0]);
		for(i = 0; product[0][i] != '\0'; i++){
			if((product[0][i] < 'A' || product[0][i] > 'Z') && (product[0][i] < 'a' || product[0][i] > 'z') && product[0][i] != ' '){
				isNameCorrect = 0;
			}
		}
		if(isNameCorrect == 0){
			goToXY(53, 38 + (count - 1) / 4 - 1);
			printf("Name only has lettes!!!                        ");      
		}
		if(strlen(product[0]) == 0){
			goToXY(53, 38 + (count - 1) / 4 - 1);
			printf("Input name, please!!!                          ");
		}
		if(strlen(product[0]) >= 20){
			goToXY(53, 38 + (count - 1) / 4 - 1);
			printf("The length of name unders 20 letters!!!        ");
		}
		if(!(isNameCorrect == 0 || strlen(product[0]) == 0 || strlen(product[0]) >= 20)){
			goToXY(53, 38 + (count - 1) / 4 - 1);
			printf("                                                               ");
		}
	} while(isNameCorrect == 0 || strlen(product[0]) == 0 || strlen(product[0]) >= 20);
	//get code
	do{
		isCodeCorrect = 1;
		coincideCode = 1;
		goToXY(70, 39 + (count - 1) / 4 - 1);
		printf("                   ");
		goToXY(70, 39 + (count - 1) / 4 - 1);
		fflush(stdin);
		gets(product[1]);
		for(i = 0; product[1][i] != '\0'; i++){
			if(product[1][i] < '0' || product[1][i] > '9'){
				isCodeCorrect = 0;
			}
		}
		for(i = 0; i < (count - 1) / 4; i++){
			if(strcmp(product[1], productInformation[4 * i + 1]) == 0){
				coincideCode = 0;
			}
		}
		if(isCodeCorrect == 0){
			goToXY(53, 40 + (count - 1) / 4 - 1);
			printf("CODE includes 3 numbers                                                               ");
		}
		if(coincideCode == 0){
			goToXY(53, 40 + (count - 1) / 4 - 1);
			printf("Code is available!!!                                                         ");
		}
		if(strlen(product[1]) == 0){
			goToXY(53, 40 + (count - 1) / 4 - 1);
			printf("Input code please...                                                                 ");
		}
		if(strlen(product[1]) == 2 || strlen(product[1]) == 1 || strlen(product[1]) > 3){
			goToXY(53, 40 + (count - 1) / 4 - 1);
			printf("The code includes 3 numbers                                                                                  ");
		}
		if(!(isCodeCorrect == 0 || coincideCode == 0 || strlen(product[1]) == 0 || strlen(product[1]) > 3 || strlen(product[1]) == 2 || strlen(product[1]) == 1)){
			goToXY(53, 40 + (count - 1) / 4 - 1);
			printf("                                                                                                    ");
		}
	} while(isCodeCorrect == 0 || coincideCode == 0 || strlen(product[1]) == 0 || strlen(product[1]) > 3 || strlen(product[1]) == 2 || strlen(product[1]) == 1);
	//get price
	do{
		isPriceCorrect = 1;
		goToXY(70, 41 + (count - 1) / 4 - 1);
		printf("                           ");
		goToXY(70, 41 + (count - 1) / 4 - 1);
		fflush(stdin);
		gets(product[2]);
		for(i = 0; product[2][i] != '\0'; i++){
			if(product[2][i] < '0' || product[2][i] > '9'){
				isPriceCorrect = 0;
			}
		}
		if(isPriceCorrect == 0){
			goToXY(53, 42 + (count - 1) / 4 - 1);
			printf("Price is positive number!!!                   ");
		}
		if(strlen(product[2]) == 0){
			goToXY(53, 42 + (count - 1) / 4 - 1);
			printf("Input price please!!!                            ");
		}
		if(strlen(product[2]) > 7){
			goToXY(53, 42 + (count - 1) / 4 - 1);
			printf("Prices are less than 10.000.000!!!               ");
		}
		if(product[2][0] == '0'){
			goToXY(53, 42 + (count - 1) / 4 - 1);
			printf("Invalid if price begins with 0!!!                ");
		}
		if(!(product[2][0] == '0' || strlen(product[2]) > 7 || strlen(product[2]) == 0 || isPriceCorrect == 0)){
			goToXY(53, 42 + (count - 1) / 4 - 1);
			printf("                                                     ");
		}
	} while(product[2][0] == '0' || strlen(product[2]) > 7 || strlen(product[2]) == 0 || isPriceCorrect == 0);
	//get quantity
	do{
		isQuantityCorrect = 1;
		goToXY(70, 43 + (count - 1) / 4 - 1);
		printf("                                      ");
		goToXY(70, 43 + (count - 1) / 4 - 1);
		fflush(stdin);
		gets(product[3]);
		for(i = 0; product[3][i] != '\0'; i++){
			if(product[3][i] < '0' || product[3][i] > '9'){
				isQuantityCorrect = 0;
			}
		}
		if(isQuantityCorrect == 0){
			goToXY(53, 44 + (count - 1) / 4 - 1);
			printf("Quantity is a positive number!!!                ");
		}
		if(strlen(product[3]) == 0){
			goToXY(53, 44 + (count - 1) / 4 - 1);
			printf("Input quantity please!!!                         ");
		}
		if(strlen(product[3]) > 3){
			goToXY(53, 44 + (count - 1) / 4 - 1);
			printf("Quantity are less than 1000!!!                   ");
		}
		if(product[3][0] == '0'){
			goToXY(53, 44 + (count - 1) / 4 - 1);
			printf("Invalid if quantity begins with 0!!!             ");
		}
		if(!((isQuantityCorrect == 0 || strlen(product[3]) == 0 || strlen(product[3]) > 3 || product[3][0] == '0'))){
			goToXY(53, 44 + (count - 1) / 4 - 1);
			printf("                                                   ");
		}
	} while(isQuantityCorrect == 0 || strlen(product[3]) == 0 || strlen(product[3]) > 3 || product[3][0] == '0');
	//promotion
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		itoa(atoi(product[2]) * 80 / 100, product[2], 10);
	}
	//print into file
	FILE *fileAdd = fopen("listProduct.txt", "a"); 
	for(i = 0; i < 4; i++){
		fprintf(fileAdd, product[i]);
		fprintf(fileAdd, "\n");
	}
	fclose(fileAdd);
	goToXY(53, 60 + (count - 1) / 4 - 1);
	printf("Data was saved !!!...");	
	goToXY(53, 61 + (count - 1) / 4 - 1);
	printf("Press any keys to display new product on screen...");
	getch();
	adminMenu();
}
//delete product;
void deleteProduct(){
	char product[200][20], checkFscanf, code[10];
	int isCode = 0;
	int i = 0, j, k;
	FILE *file = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	textColor(10);
	printf("DELETE PRODUCT");
	goToXY(53, 37 + (i - 1) / 4 - 1);
	printf("Please input code of product you want to delete: ");
	textColor(15);
	fflush(stdin);
	gets(code);
	for(j = 0; j < (i - 1) / 4; j++){
		if(strcmp(code, product[4 * j + 1]) == 0){
			isCode = 4 * j + 1;
			break;
		}
	}
	if(isCode == 0){
		goToXY(53, 39 + (i - 1) / 4 - 1);
		printf("We don't have this code...");
		goToXY(53, 43 + (i - 1) / 4 - 1);
		printf("Wait for 3s...");	
		goToXY(53, 44 + (i - 1) / 4 - 1);
		printf("Back to admin menu");
		Sleep(3000);
		adminMenu();	
	}
	if(isCode != 0){
		//delete
		for(j = isCode - 1; j < i - 1 - 4; j++){
			for(k = 0; k < 20; k++){
				product[j][k] = product[j + 4][k];
			}
			
		}
		//input new list to file
		FILE *fileDelete = fopen("listProduct.txt", "w");
		for(j = 0; j < i - 1 - 4; j++){
			fprintf(fileDelete, product[j]);
			fprintf(fileDelete, "\n");
		}
		fclose(fileDelete);
		goToXY(53, 43 + (i - 1) / 4 - 1);
		printf("Data was deleted...");	
		goToXY(53, 44 + (i - 1) / 4 - 1);
		printf("Press any key to edit information on screen...");
		getch();
		adminMenu();
	}
}
//edit product
void editProduct(){
	char product[200][20], checkFscanf;
	int i = 0, j, k;
	int isQuantityCorrect = 1, validNum2 = 1, isNameCorrect = 1, isPriceCorrect = 1;
	FILE *file = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	textColor(10);
	printf("EDIT PRODUCT");
	textColor(15);
	char newName[20], newPrice[20], newQuan[20], code[20];
	int isCode = 0;
	goToXY(53, 37 + (i - 1) / 4 - 1);
	printf("Please input code of product you want to edit: ");
	gets(code);
	for(j = 0; j < (i - 1) / 4; j++){
		if(strcmp(code, product[4 * j + 1]) == 0){
			isCode = 4 * j + 1;
			break;
		}
	}
	if(isCode == 0){
		goToXY(53, 39 + (i - 1) / 4 - 1);
		printf("We don't have this code...");
		goToXY(53, 43 + (i - 1) / 4 - 1);
		printf("Waiting for 3s...");	
		goToXY(53, 44 + (i - 1) / 4 - 1);
		printf("Back to admin menu...");
		Sleep(3000);
		adminMenu();
	}
	if(isCode != 0){
		textColor(10);
		goToXY(53, 39 + (i - 1) / 4 - 1);
		printf("New name:");
		goToXY(53, 41 + (i - 1) / 4 - 1);
		printf("New price:");
		goToXY(53, 43 + (i - 1) / 4 - 1);
		printf("New quantity:");
		textColor(15);
		//new name
		do{
			isNameCorrect = 1;
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                                                                     ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			fflush(stdin);
			gets(newName);
			for(j = 0; newName[j] != '\0'; j++){
				if((newName[j] < 'A' || newName[j] > 'Z') && (newName[j] < 'a' || newName[j] > 'z') && newName[j] != ' '){
					isNameCorrect = 0;
				}
			}
			if(isNameCorrect == 0){
				goToXY(53, 40 + (i - 1) / 4 - 1);
				printf("Name only has lettes!!!                        ");      
			}
			if(strlen(newName) == 0){
				goToXY(53, 40 + (i - 1) / 4 - 1);
				printf("Input name, please!!!                          ");
			}
			if(strlen(newName) >= 20){
				goToXY(53, 40 + (i - 1) / 4 - 1);
				printf("The length of name unders 20 letters!!!        ");
			}
			if(!(isNameCorrect == 0 || strlen(newName) == 0 || strlen(newName) >= 20)){
				goToXY(53, 40 + (i - 1) / 4 - 1);
				printf("                                                               ");
			}
		} while(isNameCorrect == 0 || strlen(newName) == 0 || strlen(newName) >= 20);	
		//new price
		do{
			isPriceCorrect = 1;
			goToXY(70, 41 + (i - 1) / 4 - 1);
			printf("                                                                     ");
			goToXY(70, 41 + (i - 1) / 4 - 1);
			fflush(stdin);
			gets(newPrice);
			for(j = 0; newPrice[j] != '\0'; j++){
				if(newPrice[j] < '0' || newPrice[j] > '9'){
					isPriceCorrect = 0;
				}
			}
			if(isPriceCorrect == 0){
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("Price is a positive number!!!                   ");
			}
			if(strlen(newPrice) == 0){
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("Input price please!!!                            ");
			}
			if(strlen(newPrice) > 7){
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("Prices are less than 10.000.000!!!               ");
			}
			if(newPrice[0] == '0'){
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("Invalid if price begins with 0!!!                ");
			}
			if(!(newPrice[0] == '0' || strlen(newPrice) > 7 || strlen(newPrice) == 0 || isPriceCorrect == 0)){
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("                                                     ");
			}
		} while(newPrice[0] == '0' || strlen(newPrice) > 7 || strlen(newPrice) == 0 || isPriceCorrect == 0);
		//new quan
		do{
			isQuantityCorrect = 1;
			goToXY(70, 43 + (i - 1) / 4 - 1);
			printf("                                                                     ");
			goToXY(70, 43 + (i - 1) / 4 - 1);
			fflush(stdin);
			gets(newQuan);
			for(j = 0; newQuan[j] != '\0'; j++){
				if(newQuan[j] < '0' || newQuan[j] > '9'){
					isQuantityCorrect = 0;
				}
			}
			if(isQuantityCorrect == 0){
				goToXY(53, 44 + (i - 1) / 4 - 1);
				printf("Quantity is a positive number!!!                ");
			}
			if(strlen(newQuan) == 0){
				goToXY(53, 44 + (i - 1) / 4 - 1);
				printf("Input quantity please!!!                         ");
			}
			if(strlen(newQuan) > 3){
				goToXY(53, 44 + (i - 1) / 4 - 1);
				printf("Quantity are less than 1000!!!                   ");
			}
			if(newQuan[0] == '0'){
				goToXY(53, 44 + (i - 1) / 4 - 1);
				printf("Invalid if quantity begins with 0!!!             ");
			}
			if(!((isQuantityCorrect == 0 || strlen(newQuan) == 0 || strlen(newQuan) > 3 || newQuan[0] == '0'))){
				goToXY(53, 44 + (i - 1) / 4 - 1);
				printf("                                                   ");
			}
		} while(isQuantityCorrect == 0 || strlen(newQuan) == 0 || strlen(newQuan) > 3 || newQuan[0] == '0');
		//promotion
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		itoa(atoi(newPrice) * 80 / 100, newPrice, 10);
		}
		//copy
		strcpy(product[isCode - 1], newName);
		strcpy(product[isCode + 1], newPrice);
		strcpy(product[isCode + 2], newQuan);
		//edit file
		FILE *fileEdit = fopen("listProduct.txt", "w");
		for(j = 0; j < i - 1; j++){
			fprintf(fileEdit, product[j]);
			fprintf(fileEdit, "\n");
		}
		fclose(fileEdit);
		goToXY(53, 45 + (i - 1) / 4 - 1);
		printf("Data was saved...");
		goToXY(53, 46 + (i - 1) / 4 - 1);
		printf("Press any keys to display new information on screen...");
		getch();
		adminMenu();	
	}
}
//find Product;
void findProduct(){
	char product[200][20], checkFscanf;
	int i = 0, j, k, height = 0, haveProduct = 0;
	FILE *file = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	textColor(10);
	printf("FIND PRODUCT");
	textColor(15);
	char letters[100];
	goToXY(53, 37 + (i - 1) / 4 - 1);
	printf("Letters to find: ");
	fflush(stdin);
	gets(letters);
	for(j = 0; j < (i - 1) / 4; j++){
		if(strstr(product[4 * j], letters) != NULL){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			textColor(10);
			printf("NAME                          CODE                          PRICE                         QUATITY");
			textColor(15);
			for(k = 0; k < 4; k++){
				goToXY(53 + 30 * k, 42 + height + (i - 1) / 4 - 1);
				printf("%s", product[4 * j + k]);
			}
			height++;
			haveProduct = 1;
		}
	}
	if(haveProduct == 0){
		goToXY(53, 40 + height + (i - 1) / 4 - 1);
		printf("Don't see information!");
		
	}
	goToXY(53, 45 + height + (i - 1) / 4 - 1);
	printf("Press any key to come back to menu");
}
//sort product price
void sortProductPrice(){
	system("cls");
	char copyChar, tmp0[20], tmp1[20], tmp2[20], tmp3[20];
	FILE *fileSource = fopen("listProduct.txt", "r");
	FILE *fileCopy = fopen("copy.txt", "w");
	do{
		copyChar = fgetc(fileSource);
		fputc(copyChar, fileCopy);
	} while(copyChar != EOF);
	fclose(fileSource);
	fclose(fileCopy);
	//read file
	char product[200][20], checkFscanf;
	int i = 0;
	FILE *fileSort = fopen("copy.txt", "r");
	do{
		checkFscanf = fscanf(fileSort, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileSort);
	//bubble sort
	int j, k;
	for(j = 0; j < (i - 1) / 4; j++){
		for(k = 0; k < (i - 1) / 4 - 1 - j; k++){
			if(atoi(product[4 * k + 2]) > atoi(product[4 * (k + 1) + 2])){
				strcpy(tmp0, product[4 * k]);
				strcpy(product[4 * k], product[4 * (k + 1)]);
				strcpy(product[4 * (k + 1)], tmp0);
				strcpy(tmp1, product[4 * k + 1]);
				strcpy(product[4 * k + 1], product[4 * (k + 1) + 1]);
				strcpy(product[4 * (k + 1) + 1], tmp1);
				strcpy(tmp2, product[4 * k + 2]);
				strcpy(product[4 * k + 2], product[4 * (k + 1) + 2]);
				strcpy(product[4 * (k + 1) + 2], tmp2);
				strcpy(tmp3, product[4 * k + 3]);
				strcpy(product[4 * k + 3], product[4 * (k + 1) + 3]);
				strcpy(product[4 * (k + 1) + 3], tmp3);
			}
		}
	}
	//promotion
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//print list
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          PRICE                         QUATITY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(53, 12 + j);
		printf("%s", product[4 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", product[4 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", product[4 * j + 2]);
		goToXY(53 + 30 * 3, 12 + j);
		printf("%s", product[4 * j + 3]);
		if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
			goToXY(65 + 30 * 3, 12 + j);
			printf("-20%% in Fri");
		}
	}
	goToXY(53, 16 + j);
	printf("Press any key to back");
	getch();
}
//sort product name
void sortProductName(){
	system("cls");
	char copyChar, tmp0[20], tmp1[20], tmp2[20], tmp3[20];
	FILE *fileSource = fopen("listProduct.txt", "r");
	FILE *fileCopy = fopen("copy.txt", "w");
	do{
		copyChar = fgetc(fileSource);
		fputc(copyChar, fileCopy);
	} while(copyChar != EOF);
	fclose(fileSource);
	fclose(fileCopy);
	//read file
	char product[200][20], checkFscanf;
	int i = 0;
	FILE *fileSort = fopen("copy.txt", "r");
	do{
		checkFscanf = fscanf(fileSort, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileSort);
	//bubble sort
	int j, k;
	for(j = 0; j < (i - 1) / 4; j++){
		for(k = 0; k < (i - 1) / 4 - 1 - j; k++){
			if(strcmp(strlwr(product[4 * k]), strlwr(product[4 * (k + 1)])) > 0){
				strcpy(tmp0, product[4 * k]);
				strcpy(product[4 * k], product[4 * (k + 1)]);
				strcpy(product[4 * (k + 1)], tmp0);
				strcpy(tmp1, product[4 * k + 1]);
				strcpy(product[4 * k + 1], product[4 * (k + 1) + 1]);
				strcpy(product[4 * (k + 1) + 1], tmp1);
				strcpy(tmp2, product[4 * k + 2]);
				strcpy(product[4 * k + 2], product[4 * (k + 1) + 2]);
				strcpy(product[4 * (k + 1) + 2], tmp2);
				strcpy(tmp3, product[4 * k + 3]);
				strcpy(product[4 * k + 3], product[4 * (k + 1) + 3]);
				strcpy(product[4 * (k + 1) + 3], tmp3);
			}
		}
	}
	//promotion
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	//print list
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          PRICE                         QUATITY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(53, 12 + j);
		printf("%s", product[4 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", product[4 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", product[4 * j + 2]);
		goToXY(53 + 30 * 3, 12 + j);
		printf("%s", product[4 * j + 3]);
		if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
			goToXY(65 + 30 * 3, 12 + j);
			printf("-20%% in Fri");
		}
	}
	goToXY(53, 16 + j);
	printf("Press any key to back");
	getch();
}
//gift
void gift(){
	goToXY(170, 1);
	textColor(8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(170, 2);
	printf("\xB2");
	goToXY(170, 3);
	printf("\xB2");	
	goToXY(170, 4);
	printf("\xB2");
	goToXY(170, 5);
	printf("\xB2");
	goToXY(170, 6);
	printf("\xB2");	
	goToXY(170, 7);
	printf("\xB2");	
	goToXY(170, 8);
	printf("\xB2");	
	goToXY(170, 9);
	printf("\xB2");	
	goToXY(170, 10);
	printf("\xB2");	
	goToXY(170, 11);
	printf("\xB2");	
	goToXY(170, 12);
	printf("\xB2");	
	goToXY(170, 13);
	printf("\xB2");	
	goToXY(170, 14);
	printf("\xB2");	
	goToXY(203, 2);
	printf("\xB2");
	goToXY(203, 3);
	printf("\xB2");	
	goToXY(203, 4);
	printf("\xB2");
	goToXY(203, 5);
	printf("\xB2");
	goToXY(203, 6);
	printf("\xB2");	
	goToXY(203, 7);
	printf("\xB2");	
	goToXY(203, 8);
	printf("\xB2");	
	goToXY(203, 9);
	printf("\xB2");	
	goToXY(203, 10);
	printf("\xB2");	
	goToXY(203, 11);
	printf("\xB2");	
	goToXY(203, 12);
	printf("\xB2");	
	goToXY(203, 13);
	printf("\xB2");	
	goToXY(203, 14);
	printf("\xB2");	
	goToXY(170, 15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(183, 2);
	textColor(10);
	printf("LIST GIFTS");
	//read file gift
	char gift[200][20], checkFscanf;
	int i = 0, j;
	FILE *fileGift = fopen("gift.txt", "r");
	do{
		checkFscanf = fscanf(fileGift, "%[^\n]%*c", gift[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileGift);
	for(j = 0; j < (i - 1) / 2; j++){
		textColor(10);
		goToXY(172, 4 + 2 * j);
		printf("%s", gift[2 * j]);
		textColor(15);
		goToXY(193, 4 + 2 * j);
		printf("%s", gift[2 * j + 1]);
	}
	goToXY(172, 5 + 2 * j);
	textColor(15);
	printf("8. EDIT GIFT");
}
//edit gift
void editGift(){
	//display
	char product[200][20], checkFscanf;
	int count = 0, isQuantityCorrect = 1;
	FILE *fileDisplay = fopen("listProduct.txt", "r"); 
	do{
		checkFscanf = fscanf(fileDisplay, "%[^\n]%*c", product[count]); 
		count++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileDisplay);
	goToXY(0, 33 + (count - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (count - 1) / 4 - 1);
	textColor(10);
	printf("EDIT GIFT");
	textColor(15);
	//read file gift
	char gift[200][20], checkFscanfGift, name[15], quantity[10];
	int i = 0, j, isName = - 1, k;
	FILE *fileGift = fopen("gift.txt", "r");
	do{
		checkFscanfGift = fscanf(fileGift, "%[^\n]%*c", gift[i]);
		i++;
		if(checkFscanfGift == EOF) break;
	} while(checkFscanfGift != EOF);
	fclose(fileGift);
	//input
	goToXY(53, 37 + (count - 1) / 4 - 1);
	printf("Please input the name of gift that you want to edit quantity: ");
	gets(name);
	for(j = 0; j < (i - 1) / 2; j++){
		if(strcmp(strlwr(name), gift[2 * j]) == 0){
			isName = 2 * j;
		}
	}
	if(isName == - 1){
		goToXY(53, 39 + (count - 1) / 4 - 1);
		printf("We don't have this gift.... press any key to back");
		getch();
		adminMenu();
	}
	if(isName != - 1){
		goToXY(53, 39 + (count - 1) / 4 - 1);
		printf("Input new quantity: ");
		do{
			isQuantityCorrect = 1;
			goToXY(90, 39 + (count - 1) / 4 - 1);
			printf("                                                                     ");
			goToXY(90, 39 + (count - 1) / 4 - 1);
			fflush(stdin);
			gets(quantity);
			for(k = 0; quantity[k] != '\0'; k++){
				if(quantity[k] < '0' || quantity[k] > '9'){
					isQuantityCorrect = 0;
				}
			}
			if(isQuantityCorrect == 0){
				goToXY(53, 40 + (count - 1) / 4 - 1);
				printf("quantity is a positive number!!!                   ");
			}
			if(strlen(quantity) == 0){
				goToXY(53, 40 + (count - 1) / 4 - 1);
				printf("Input quantity please!!!                            ");
			}
			if(strlen(quantity) > 3){
				goToXY(53, 40 + (count - 1) / 4 - 1);
				printf("quantity are less than 1000!!!               ");
			}
			if(quantity[0] == '0'){
				goToXY(53, 40 + (count - 1) / 4 - 1);
				printf("Invalid if quantity begins with 0!!!                ");
			}
			if(!(quantity[0] == '0' || strlen(quantity) > 7 || strlen(quantity) == 0 || isQuantityCorrect == 0)){
				goToXY(53, 40 + (i - 1) / 4 - 1);
				printf("                                                     ");
			}
		} while(quantity[0] == '0' || strlen(quantity) > 7 || strlen(quantity) == 0 || isQuantityCorrect == 0);
	}
	strcpy(gift[isName + 1], quantity);
	FILE *fileEditGift = fopen("gift.txt", "w");
		for(j = 0; j < i - 1; j++){
			fprintf(fileEditGift, gift[j]);
			fprintf(fileEditGift, "\n");
		}
		fclose(fileEditGift);
	goToXY(53, 42 + (count - 1) / 4 - 1);
	printf("Data was saved!!! Press any key to back...               ");
	goToXY(0, 33 + (count - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	getch();
	adminMenu();
}
//make account
void makeAccount(){
	char name[21], pass[21], rePass[21], money[11];
	int i = 34, isMoneyCorrect = 0, k;
	goToXY(0, 33 + (i - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 3 - 1);
	textColor(10);
	printf("MAKE ACCOUNT");
	textColor(15);
	goToXY(53, 37 + (i - 1) / 3 - 1);
	printf("Name             : ");
	goToXY(53, 39 + (i - 1) / 3 - 1);
	printf("Password         : ");
	goToXY(53, 41 + (i - 1) / 3 - 1);
	printf("Password again   : ");
	do{
		goToXY(53, 37 + (i - 1) / 3 - 1);
		printf("                                      ");
		goToXY(53, 37 + (i - 1) / 3 - 1);
		printf("Name             : ");
		fflush(stdin);
		gets(name);
		if(strlen(name) > 20){
			goToXY(53, 38 + (i - 1) / 3 - 1);
			printf("Name is maximum 20 letters!!!");
		}
		if(strlen(name) == 0){
			goToXY(53, 38 + (i - 1) / 3 - 1);
			printf("Please input!                    ");
		}
		if(!(strlen(name) > 20 || strlen(name) == 0)){
			goToXY(53, 38 + (i - 1) / 3 - 1);
			printf("                                      ");
		}
		
	} while(strlen(name) > 20 || strlen(name) == 0);
	do{
		goToXY(53, 39 + (i - 1) / 3 - 1);
		printf("                                      ");
		goToXY(53, 39 + (i - 1) / 3 - 1);
		printf("Password         : ");
		fflush(stdin);
		gets(pass);
		if(strlen(pass) > 20){
			goToXY(53, 40 + (i - 1) / 3 - 1);
			printf("Pass is maximum 20 letters!!!      ");
		}
		if(strlen(pass) == 0){
			goToXY(53, 40 + (i - 1) / 3 - 1);
			printf("Please input!                      ");
		}
		if(!(strlen(pass) > 20 || strlen(pass) == 0)){
			goToXY(53, 40 + (i - 1) / 3 - 1);
			printf("                                      ");
		}
		
	} while(strlen(pass) > 20 || strlen(pass) == 0);
	do{
		goToXY(53, 41 + (i - 1) / 3 - 1);
		printf("                                      ");
		goToXY(53, 41 + (i - 1) / 3 - 1);
		printf("Password again   : ");
		fflush(stdin);
		gets(rePass);
		if(strcmp(rePass, pass) != 0){
			goToXY(53, 42 + (i - 1) / 3 - 1);
			printf("Inputing pass again is wrong!!!");
		}
		if(strcmp(rePass, pass) == 0){
			goToXY(53, 42 + (i - 1) / 3 - 1);
			printf("                                       ");
		}
	} while(strcmp(rePass, pass) != 0);
	goToXY(53, 43 + (i - 1) / 3 - 1);
	printf("How much do you want to add into account?");
	do{
			isMoneyCorrect = 0;
			goToXY(53, 44 + (i - 1) / 3 - 1);
			printf("                       ");
			goToXY(53, 44 + (i - 1) / 3 - 1);
			printf("Money:     ");
			fflush(stdin);
			gets(money);
			for(k = 0; money[k] != '\0'; k++){
				if(money[k] < '0' || money[k] > '9'){
					isMoneyCorrect = - 1;
				}
			}
			if(strlen(money) > 10){
				goToXY(53, 45 + (i - 1) / 3 - 1);
				printf("The money is too much...                   ");
			}
			if(strlen(money) == 0){
				goToXY(53, 45 + (i - 1) / 3 - 1);
				printf("Please input...                          ");
			}
			if(money[0] == '0'){
				goToXY(93, 45 + (i - 1) / 3 - 1);
				printf("Not begin with 0...                    ");
			}
			if(isMoneyCorrect == - 1){
				goToXY(53, 45 + (i - 1) / 3 - 1);
				printf("Money is a positive number...                  ");
			}
			if(!(money[0] == '0' || isMoneyCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10)){
				goToXY(53, 45 + (i - 1) / 3 - 1);
				printf("                                              ");
			}
		} while(money[0] == '0' || isMoneyCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10);
	FILE *addAcc = fopen("customer.txt", "a");
	fprintf(addAcc, name);
	fprintf(addAcc, "\n");
	fprintf(addAcc, pass);
	fprintf(addAcc, "\n");
	fprintf(addAcc, money);
	fprintf(addAcc, "\n");
	fclose(addAcc);
	goToXY(55, 45 + (i - 1) / 3 - 1);
	printf("Data was saved....");
	goToXY(55, 46 + (i - 1) / 3 - 1);
	printf("Press any key to back to main menu");
	getch();
	mainMenu();
}
//password customer
void passwordCustomer(){
	system("cls");
	goToXY(0, 8);
	printf("Press ESC to back to main menu");
	goToXY(72, 22);
	textColor(10);
	printf("               CUSTOMER");
	textColor(15);
	goToXY(53, 24);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 COC SHOP \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 26);
	printf("\xB2\xB2\xB2\xB2\xB2 1. NAME        :   ");
	goToXY(53, 28);
	printf("\xB2\xB2\xB2\xB2\xB2 2. PASSWORD    :   ");
	char cus[200][20], checkFscanf2, name[20], pass[20], ch;
	int count = 0, k, isName = - 1;
	//read file customer
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanf2 = fscanf(fileCus, "%[^\n]%*c", cus[count]);
		count++;
		if(checkFscanf2 == EOF) break;
	} while(checkFscanf2 != EOF);
	fclose(fileCus);	
	//input name
	do{
		goToXY(53, 26);
		printf("                                        ");
		goToXY(53, 26);
		printf("\xB2\xB2\xB2\xB2\xB2 1. NAME        :   ");
		fflush(stdin);
		gets(name);
		for(k = 0; k < (count - 1) / 3; k++){
			if(strcmp(name, cus[3 * k]) == 0){
				isName = 3 * k;
			}
		}
		if(isName == - 1){
			goToXY(53, 27);
			printf("Name is not available...       ");
		}
		if(isName != - 1){
			goToXY(53, 27);
			printf("                               ");
		}
	} while(isName == - 1);
	//input password
	goToXY(53, 28);
	printf("\xB2\xB2\xB2\xB2\xB2 2. PASSWORD    :   ");
	k = 0;
	while(ch != 13){
		ch = getch();

		if(ch != 13 && ch != 8 && ch != 27){
			putch('*');
			pass[k] = ch;
			k++;
		}
		if(ch == 27){
			mainMenu();
		}
	}
	pass[k] = '\0';
	//check pass
	if(strcmp(pass, cus[isName + 1]) != 0){
		goToXY(53, 30);
		printf("\aPassword is incorrect!                  ");
		goToXY(53, 32);
		printf("Press any key to input again...");
		getch();
		passwordCustomer();
	}
	if(strcmp(pass, cus[isName + 1]) == 0){
		goToXY(53, 30);
		printf("HELLO   %s                             ", cus[isName]);
		goToXY(53, 32);
		printf("Press any key to go to customer menu");
		getch();
		FILE *writeAccount = fopen("account.txt", "w");
		for(k = 0; k < 3; k++){
			fprintf(writeAccount, cus[isName + k]);
			fprintf(writeAccount, "\n");
		}
		fclose(writeAccount);
	}
}
//print customer information
void printCus(){
	goToXY(170, 1);
	textColor(8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(170, 2);
	printf("\xB2");
	goToXY(170, 3);
	printf("\xB2");	
	goToXY(170, 4);
	printf("\xB2");
	goToXY(170, 5);
	printf("\xB2");
	goToXY(170, 6);
	printf("\xB2");	
	goToXY(170, 7);
	printf("\xB2");	
	goToXY(170, 8);
	printf("\xB2");	
	goToXY(170, 9);
	printf("\xB2");	
	goToXY(170, 10);
	printf("\xB2");	
	goToXY(170, 11);
	printf("\xB2");	
	goToXY(170, 12);
	printf("\xB2");	
	goToXY(170, 13);
	printf("\xB2");	
	goToXY(170, 14);
	printf("\xB2");	
	goToXY(203, 2);
	printf("\xB2");
	goToXY(203, 3);
	printf("\xB2");	
	goToXY(203, 4);
	printf("\xB2");
	goToXY(203, 5);
	printf("\xB2");
	goToXY(203, 6);
	printf("\xB2");	
	goToXY(203, 7);
	printf("\xB2");	
	goToXY(203, 8);
	printf("\xB2");	
	goToXY(203, 9);
	printf("\xB2");	
	goToXY(203, 10);
	printf("\xB2");	
	goToXY(203, 11);
	printf("\xB2");	
	goToXY(203, 12);
	printf("\xB2");	
	goToXY(203, 13);
	printf("\xB2");	
	goToXY(203, 14);
	printf("\xB2");	
	goToXY(170, 15);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(183, 2);
	textColor(10);
	printf("CUSTOMER");
	textColor(15);
	char account[200][20], checkFscanf;
	int i = 0, j;
	FILE *filePrintAcc = fopen("account.txt", "r");
	do{
		checkFscanf = fscanf(filePrintAcc, "%[^\n]%*c", account[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrintAcc);
	goToXY(173, 4);
	printf("NAME  : %s", account[0]);
	goToXY(173, 6);
	printf("MONEY : %s", account[2]);
}
//customer menu
void customerMenu(){
	int choice, numFormat;
	char endChar;
	system("cls");
	goToXY(0, 8);
	//time
	t();
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char product[200][20], checkFscanf;
	//read file
	int i = 0;
	FILE *file7 = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(file7, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file7);
	int j, k;
	//print list
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          PRICE                         QUANTITY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(53, 12 + j);
		printf("%s", product[4 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", product[4 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", product[4 * j + 2]);
		goToXY(53 + 30 * 3, 12 + j);
		printf("%s", product[4 * j + 3]);
		if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
			goToXY(65 + 30 * 3, 12 + j);
			printf("-20%% in Fri");
		}
	}
	//print customer information
	printCus();
	goToXY(0, 14 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 16 + j);
	textColor(10);
	printf("CUSTOMER MENU");
	textColor(15);
	goToXY(53, 18 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 20 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1. Look up products                   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5. Change Password                      \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 9. Log out");
	goToXY(53, 22 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2. Sort products                      \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6. Add money");
	goToXY(53, 24 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3. Buy products                       \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 7. Shopping cart");
	goToXY(53, 26 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4. Give feedback                      \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 8. Back to main menu");
	goToXY(53, 28 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 30 + j);
	printf("Get a choice: ");
	fflush(stdin);
	numFormat = scanf("%d%c", &choice, &endChar);
	if(numFormat != 2 || endChar != '\n' || choice < 1 || choice > 9){
		goToXY(53, 31 + j);
		printf("\aSorry! We don't have this choice. Please press any key to input a valid choice");
		if(getch()){
			customerMenu();
		}
	}
	if(choice == 5){
		changePass();
	}
	if(choice == 8){
		mainMenu();
	}
	if(choice == 9){
		passwordCustomer();
		customerMenu();
	}
	if(choice == 2){
		goToXY(0, 33 + (i - 1) / 4 - 1);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		goToXY(100, 35 + (i - 1) / 4 - 1);
		printf("SORT PRODUCT");
		goToXY(53, 38 + (i - 1) / 4 - 1);
		printf("1. Sort in Name");
		goToXY(53, 40 + (i - 1) / 4 - 1);
		printf("2. Sort in Price");
		switch(getch()){
			case '1':
				sortProductName();
				customerMenu();
				break;
			case '2': 
				sortProductPrice();
				customerMenu();
				break;
			default:
				{
				goToXY(53, 42 + (i - 1) / 4 - 1);
				printf("\aYour choice is invalid, please press any key and input again....");
				if(getch()){
					customerMenu();
				}
			}
		}
	}
	if(choice == 1){
		findProduct();
		fflush(stdin);
		getch();
		customerMenu();
	}
	if(choice == 3){
		buyProduct();
	}
	if(choice == 4){
		giveStar();
	}
	if(choice == 6){
		addMoney();
	}
	if(choice == 7){
		cart();
	}
}
//add money
void addMoney(){
	//display
	char product[200][20], checkFscanf, name[11], pass[11], ch, money[11];
	int i = 0, k, isName = - 1, isNumCorrect = 0;
	FILE *filePrint = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	textColor(10);
	printf("ADD MONEY");
	textColor(15);
	//read file customer
	char cus[200][20], checkFscanfCus;
	int count = 0;
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanfCus = fscanf(fileCus, "%[^\n]%*c", cus[count]);
		count++;
		if(checkFscanfCus == EOF) break;
	} while(checkFscanfCus != EOF);
	fclose(fileCus);
	//read file account
	char account[200][20], checkFscanfAccount;
	int c = 0;
	FILE *fileAccount = fopen("account.txt", "r");
	do{
		checkFscanfAccount = fscanf(fileAccount, "%[^\n]%*c", account[c]);
		c++;
		if(checkFscanfAccount == EOF) break;
	} while(checkFscanfAccount != EOF);
	fclose(fileAccount);
	strcpy(name, account[0]);
	for(k = 0; k < (count - 1) / 3; k++){
		if(strcmp(name, cus[3 * k]) == 0){
			isName = 3 * k;
			break;
		}
	}
	goToXY(53, 40 + (i - 1) / 4 - 1);
	printf("Hello %s!!! How much do you want to add?", name);
	do{
		isNumCorrect = 0;
		goToXY(53, 44 + (i - 1) / 4 - 1);
		printf("                       ");
		goToXY(53, 44 + (i - 1) / 4 - 1);
		printf("Money:     ");
		fflush(stdin);
		gets(money);
		for(k = 0; money[k] != '\0'; k++){
			if(money[k] < '0' || money[k] > '9'){
				isNumCorrect = - 1;
			}
		}
		if(strlen(money) > 10){
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("The money is too much...                   ");
		}
		if(strlen(money) == 0){
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("Please input...                          ");
		}
		if(money[0] == '0'){
			goToXY(93, 45 + (i - 1) / 4 - 1);
			printf("Not begin with 0...                    ");
		}
		if(isNumCorrect == - 1){
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("Money is a positive number...                  ");
		}
		if(!(money[0] == '0' || isNumCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10)){
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("                                              ");
		}
	} while(money[0] == '0' || isNumCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10);
	itoa(atoi(cus[isName + 2]) + atoi(money), cus[isName + 2], 10);
	FILE *addMoney = fopen("customer.txt", "w");
	for(k = 0; k < count - 1; k++){
		fprintf(addMoney, cus[k]);
		fprintf(addMoney, "\n");
	}
	fclose(addMoney);
	goToXY(53, 46 + (i - 1) / 4 - 1);
	printf("Data was saved...");
	goToXY(53, 47 + (i - 1) / 4 - 1);
	printf("Press any key to back to customer menu...");
	getch();
	FILE *write = fopen("account.txt", "w");
	for(k = 0; k < 3; k++){
		fprintf(write, cus[isName + k]);
		fprintf(write, "\n");
	}
	fclose(write);
	customerMenu();
}
//buy product
void buyProduct(){
	int money = 0, isName = 1, isQuantityCorrect = 1, price[50], size[50], sum = 0;
	char product[200][20], checkFscanf, name[20], quantity[20], charSum[10];
	int i = 0, j, k, choice;
	//read list
	FILE *fileDisplay = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(fileDisplay, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileDisplay);
	//display
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	printf("BUY PRODUCT");
	goToXY(53, 37 + (i - 1) / 4 - 1);
	printf("Name    :");
	goToXY(53, 39 + (i - 1) / 4 - 1);
	printf("Quantity:");
	textColor(15);
	//get name
	do{
		isName = 1;
		goToXY(70, 37 + (i - 1) / 4 - 1);
		printf("                              ");
		goToXY(70, 37 + (i - 1) / 4 - 1);
		fflush(stdin);
		gets(name);
		for(j = 0; j < (i - 1) / 4; j++){
			if(strcmp(strlwr(name), strlwr(product[4 * j])) != 0){
				isName = - 1;
			} else {
				isName = 4 * j ;
				break;
			}
		}
		if(isName == - 1){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("We don't have this product!!!                           ");
		}
		if(strlen(name) == 0){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("Input name of product, please!!!                       ");
		}
		if(strlen(name) >= 20){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("The legth of the name is so large!!!                   ");
		}
		if(!(isName == - 1 || strlen(name) == 0 || strlen(name) >= 20)){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("                                                       ");
		}
	} while(isName == - 1 || strlen(name) == 0 || strlen(name) >= 20);
	do{
		isQuantityCorrect = 1;
		goToXY(70, 39 + (i - 1) / 4 - 1);
		printf("                         ");
		goToXY(70, 39 + (i - 1) / 4 - 1);
		fflush(stdin);
		gets(quantity);
		if(atoi(quantity) > atoi(product[isName + 3])){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("We don't have enough products!!!                       ");
		}
		if(quantity[0] == '0'){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("Quantity don't begin with 0, please!!!                  ");
		}
		for(j = 0; quantity[j] != '\0'; j++){
			if(quantity[j] < '0' || quantity[j] > '9'){
				isQuantityCorrect = 0;
			}
		}
		if(isQuantityCorrect == 0){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("Quantity is a positive number!!!                     ");
		}
		if(strlen(quantity) == 0){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("Input quantity, please!!!                              ");
		}
		if(strlen(quantity) > 3){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("Product's quantity is always less than 1000!!!        ");
		}
		if(!(isQuantityCorrect == 0 || strlen(quantity) == 0 || strlen(quantity) > 3 || quantity[0] == '0' || atoi(quantity) > atoi(product[isName + 3]))){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("                                                            ");
		}
	} while(isQuantityCorrect == 0 || strlen(quantity) == 0 || strlen(quantity) > 3 || quantity[0] == '0' || atoi(quantity) > atoi(product[isName + 3]));
	goToXY(53, 41 + (i - 1) / 4 - 1);
	printf("Do you confirm to buy %s %s with price is %d?", quantity, product[isName], atoi(quantity) * atoi(product[isName + 2]));
	goToXY(53, 42 + (i - 1) / 4 - 1);
	printf("1. YES");
	goToXY(53, 43 + (i - 1) / 4 - 1);
	printf("2. NO");
	switch(getch()){
		case '1':
			goToXY(53, 41 + (i - 1) / 4 - 1);
			printf("                                                              ");
			goToXY(53, 42 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 43 + (i - 1) / 4 - 1);
			printf("                                      ");
			break;
		case '2':
			goToXY(53, 41 + (i - 1) / 4 - 1);
			printf("                                                              ");
			goToXY(53, 42 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 43 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                         ");
			buyProduct();
		default:
			goToXY(53, 44 + (i - 1) / 4 - 1);
			printf("Invalid input! Transaction failed! Input again");	
			getch();
			goToXY(53, 41 + (i - 1) / 4 - 1);
			printf("                                                              ");
			goToXY(53, 42 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 43 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                         ");
			goToXY(53, 44 + (i - 1) / 4 - 1);
			printf("                         ");
			buyProduct();
	}	
	textColor(10);
	goToXY(53, 45 + (i - 1) / 4 - 1);
	printf("1. Continue to buy");
	goToXY(53, 46 + (i - 1) / 4 - 1);
	printf("2. Finish to buy");
	textColor(15);
	FILE *fileBuy;
	FILE *fileWr;
	switch(getch()){
		case '1':
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 46 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                                      ");
			FILE *fileBuy = fopen("buyInformation.txt", "a");
			for(j = 0; j < 3; j++){
				fprintf(fileBuy, product[isName + j]);
				fprintf(fileBuy, "\n");
			}
			fprintf(fileBuy, quantity);
			fprintf(fileBuy, "\n");
			fclose(fileBuy);
			itoa(atoi(product[isName + 3]) - atoi(quantity), product[isName + 3], 10);
			FILE *fileWr = fopen("listProduct.txt", "w");
			for(j = 0; j < i - 1; j++){
			fprintf(fileWr, product[j]);
			fprintf(fileWr, "\n");
			}
			fclose(fileWr);
			buyProduct();
		case '2':
			fileBuy = fopen("buyInformation.txt", "a");
			for(j = 0; j < 3; j++){
				fprintf(fileBuy, product[isName + j]);
				fprintf(fileBuy, "\n");
			}
			fprintf(fileBuy, quantity);
			fprintf(fileBuy, "\n");
			fclose(fileBuy);
			itoa(atoi(product[isName + 3]) - atoi(quantity), product[isName + 3], 10);
			fileWr = fopen("listProduct.txt", "w");
			for(j = 0; j < i - 1; j++){
			fprintf(fileWr, product[j]);
			fprintf(fileWr, "\n");
			}
			fclose(fileWr);
			printBill();
		default:
			goToXY(53, 47 + (i - 1) / 4 - 1);
			printf("Invalid input! Transaction failed! Input again");
			getch();
			goToXY(53, 47 + (i - 1) / 4 - 1);
			printf("                                                  ");
			goToXY(53, 45 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 46 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 41 + (i - 1) / 4 - 1);
			printf("                                                              ");
			goToXY(53, 42 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(53, 43 + (i - 1) / 4 - 1);
			printf("                                      ");
			goToXY(70, 39 + (i - 1) / 4 - 1);
			printf("                                      ");
			buyProduct();
	}
}
//print bill
void printBill(){
	//read file product
	char product[200][20], checkFscanfProduct;
	int count3 = 0;
	FILE *fileProduct = fopen("listProduct.txt", "r"); 
	do{
		checkFscanfProduct = fscanf(fileProduct, "%[^\n]%*c", product[count3]); 
		count3++;
		if(checkFscanfProduct == EOF) break;
	} while(checkFscanfProduct != EOF);
	fclose(fileProduct);
	//read file customer
	char cus[200][20], checkFscanfCus;
	int count2 = 0;
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanfCus = fscanf(fileCus, "%[^\n]%*c", cus[count2]);
		count2++;
		if(checkFscanfCus == EOF) break;
	} while(checkFscanfCus != EOF);
	fclose(fileCus);
	//read file account
	char account[200][20], checkFscanfAccount;
	int count = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAccount = fscanf(fileAcc, "%[^\n]%*c", account[count]);
		count++;
		if(checkFscanfAccount == EOF) break;
	} while(checkFscanfAccount != EOF);
	fclose(fileAcc);
	//read file voucher
	char voucher[200][20], checkFscanf;
	int count1 = 0, isVoucher = -1, total, remainder = 0;
	FILE *filePrint = fopen("voucher.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", voucher[count1]);
		count1++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	//read file buy
	char bill[200][20], checkFscanfBill, charPay[10], ch, nameVou[11];
	int i = 0, j, sum = 0, k, random, h;
	FILE *fileBill = fopen("buyInformation.txt", "r");
	do{
		checkFscanfBill = fscanf(fileBill, "%[^\n]%*c", bill[i]);
		i++;
		if(checkFscanfBill == EOF) break;
	} while(checkFscanfBill != EOF);
	fclose(fileBill);
	//display
	system("cls");
	goToXY(0, 8);
	t();
	goToXY(73, 10);
	textColor(10);
	printf("YOUR CHOICE");	
	goToXY(53, 12);
	printf("NAME");
	goToXY(73, 12);
	printf("QUANTITY");
	goToXY(93, 12);
	printf("MONEY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(53, 14 + j);
		printf("%s", bill[4 * j]);
	}
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(73, 14 + j);
		printf("%s", bill[4 * j + 3]);
	}
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(93, 14 + j);
		printf("%d", atoi(bill[4 * j + 3]) * atoi(bill[4 * j + 2]));
	}
	goToXY(53, 16 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 17 + j);
	textColor(10);
	printf("MONEY:");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		sum = sum + atoi(bill[4 * j + 3]) * atoi(bill[4 * j + 2]);
	}
	goToXY(93, 17 + j);
	printf("%d", sum);
	goToXY(53, 18 + j);
	textColor(10);
	printf("VAT 10%%:");
	textColor(15);
	goToXY(94, 18 + j);
	printf("%d", sum / 10);
	goToXY(53, 20 + j);
	textColor(10);
	printf("TOTAL:");
	textColor(15);
	goToXY(93, 20 + j);
	printf("%d", sum + sum / 10);
	goToXY(53, 22 + j);
	printf("---------------------------------------------------------");
	//use voucher
	goToXY(53, 23 + j);
	printf("Do you want to use voucher?                ");	
	goToXY(53, 24 + j);
	printf("1. YES        2. NO                          ");
	switch(getch()){
		case '2':
			total = sum + sum / 10;
			break;
		case '1':
			goToXY(53, 25 + j);
			textColor(10);
			printf("Input name of voucher:    ");
			textColor(15);
			fflush(stdin);
			gets(nameVou);
			for(k = 0; k < (count1 - 1) / 3; k++){
				if(strcmp(nameVou, voucher[3 * k]) == 0){
					isVoucher = 3 * k;
					break;
				}
			}
			if(isVoucher == - 1){
				goToXY(53, 26 + j);
				printf("We don't have this voucher.... ");
				goToXY(53, 27 + j);
				printf("Press any key to return...");
				getch();
				printBill();
			}
			if(isVoucher != - 1){
				goToXY(53, 26 + j);
				printf("TOTAL : %d", (sum + sum / 10) - (sum + sum / 10) * atoi(voucher[isVoucher + 2]) / 100);
				total = (sum + sum / 10) - (sum + sum / 10) * atoi(product[isVoucher + 2]) / 100;
			}
			break;
		default:
			goToXY(53, 25 + j);
			printf("Invalid input!!!");
			goToXY(53, 26 + j);
			printf("Press any key to return...");
			getch();
			printBill();
	}
	goToXY(53, 28 + j);
	for(k = 0; k < (count2 - 1) / 3; k++){
		if(strcmp(account[0], cus[3 * k]) == 0){
			remainder = 3 * k + 2;
			break;
		}
	}
	
	if(atoi(cus[remainder]) - total < 0){
		goToXY(53, 28 + j);
		printf("You are not enough money to pay, press any key to add money into your account now!");
		getch();
		add();
	}
	goToXY(53, 28 + j);
	printf("Remainder: %d", atoi(cus[remainder]) - total);
	itoa(atoi(cus[remainder]) - total, cus[remainder], 10);
	FILE *wr = fopen("customer.txt", "w");
	for(k = 0; k < count2 - 1; k++){
		fprintf(wr, cus[k]);
		fprintf(wr, "\n");
	}
	fclose(wr);
	if(isVoucher != - 1){
		for(k = isVoucher; k < count1 - 1 - 3; k++){
			for(h = 0; h < 20; h++){
				voucher[k][h] = voucher[k + 3][h];
			}			
		}
		FILE *fileDelete = fopen("voucher.txt", "w");
			for(j = 0; j < count1 - 1 - 3; j++){
				fprintf(fileDelete, voucher[j]);
				fprintf(fileDelete, "\n");
			}
		fclose(fileDelete);
	}
	int del = - 1;
	for(k = 0; k < (count3 - 1) / 4; k++){
		if(atoi(product[4 * k + 3]) == 0){
			del = 4 * k;
		}
	}
	if(del != - 1){
		for(k = del; k < count3 - 1 - 4; k++){
			for(h = 0; h < 20; h++){
				product[k][h] = product[k + 4][h];
			}			
		}
		FILE *fileDelete = fopen("listProduct.txt", "w");
			for(k = 0; k < count3 - 1 - 4; k++){
				fprintf(fileDelete, product[k]);
				fprintf(fileDelete, "\n");
			}
		fclose(fileDelete);
	}
	goToXY(53, 30 + j);
	printf("---------------------------------------------------------");
	goToXY(53, 32 + j);
	printf("Bill is being printed!");
	goToXY(53, 34 + j);
	printf("Waiting for 5s...");
	Sleep(5000);
	FILE *fileDel = fopen("buyInformation.txt", "w");
	fprintf(fileDel, NULL);
	fclose(fileDel);
	//promotion
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if((sum + sum / 10) >= 200000 || tm.tm_wday == 0){
		textColor(10);
		goToXY(53, 36 + j);
		printf("Bill was printed...");
		goToXY(53, 38 + j);
		printf("CONGRATULATION!!! You got a lucky ticket...");
		goToXY(53, 39 + j);
		printf("Press any key to use it!");
		textColor(15);
		getch();
		luckyTicket();	
	} else {
		goToXY(53, 36 + j);
		printf("Bill was printed... Do you want to evaluate our shop's service?");
		goToXY(53, 37 + j);
		printf("1. YES                        2. NO");
		if(getch() == '1'){
			giveStar();
		}
		goToXY(53, 38 + j);
		printf("Press any key to back to customer menu.");
		getch();
		customerMenu();
	}	
}
//add money while buying
void add(){
	system("cls");
	char name[11], pass[11], ch, money[11];
	int i = 0, j, k, isName = - 1, isMoneyCorrect = 0;
	goToXY(45, 33 - 30);
	textColor(10);
	printf("PLEASE LOG IN AGAIN TO DEAL!");
	goToXY(0, 34 - 30);
	textColor(8);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 - 30);
	textColor(10);
	printf("ADD MONEY");
	textColor(15);
	goToXY(53, 37- 30);
	printf("NAME:       ");
	goToXY(53, 39 - 30);
	printf("PASSWORD:   ");
	char cus[200][20], checkFscanf;
	int count = 0;
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanf = fscanf(fileCus, "%[^\n]%*c", cus[count]);
		count++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileCus);
	do{
		goToXY(53, 37 - 30);
		printf("                            ");
		goToXY(53, 37 - 30);
		printf("NAME:       ");
		fflush(stdin);
		gets(name);
		for(k = 0; k < (count - 1) / 3; k++){
			if(strcmp(name, cus[3 * k]) == 0){
				isName = 3 * k;
			}
		}
		if(isName == - 1){
			goToXY(53, 38 - 30);
			printf("Name is not available...");
		}
		if(isName != - 1){
			goToXY(53, 38 - 30);
			printf("                               ");
		}
	} while(isName == - 1);
	goToXY(53, 39 - 30);
	printf("PASSWORD:   ");
	k = 0;
	while(ch != 13){
		ch = getch();

		if(ch != 13 && ch != 8){
			putch('*');
			pass[k] = ch;
			k++;
		}
	}
	pass[k] = '\0';
	if(strcmp(pass, cus[isName + 1]) != 0){
		goToXY(53, 41 - 30);
		printf("Password is wrong!");
		goToXY(53, 42 - 30);
		printf("Press any key to back");
		getch();
		add();
	}
	if(strcmp(pass, cus[isName + 1]) == 0){
		goToXY(53, 41 - 30);
		printf("Hello %s!!! How much do you want to add?", name);
		do{
			isMoneyCorrect = 0;
			goToXY(53, 44 - 30);
			printf("                           ");
			goToXY(53, 44 - 30);
			printf("Money:     ");
			fflush(stdin);
			gets(money);
			for(k = 0; money[k] != '\0'; k++){
				if(money[k] < '0' || money[k] > '9'){
					isMoneyCorrect = - 1;
				}
			}
			if(strlen(money) > 10){
				goToXY(53, 45 - 30);
				printf("The money is too much...                   ");
			}
			if(strlen(money) == 0){
				goToXY(53, 45 - 30);
				printf("Please input...                          ");
			}
			if(money[0] == '0'){
				goToXY(93, 45 - 30);
				printf("Not begin with 0...                    ");
			}
			if(isMoneyCorrect == - 1){
				goToXY(53, 45 - 30);
				printf("Money is a positive number...                  ");
			}
			if(!(money[0] == '0' || isMoneyCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10)){
				goToXY(53, 45 - 30);
				printf("                                              ");
			}
		} while(money[0] == '0' || isMoneyCorrect == - 1 || strlen(money) == 0 || strlen(money) > 10);
		itoa(atoi(cus[isName + 2]) + atoi(money), cus[isName + 2], 10);
		FILE *addMoney = fopen("customer.txt", "w");
		for(k = 0; k < count - 1; k++){
			fprintf(addMoney, cus[k]);
			fprintf(addMoney, "\n");
		}
		fclose(addMoney);
		goToXY(53, 46 - 30);
		printf("Data was saved...");
		goToXY(53, 47 - 30);
		printf("Press any key to back to customer menu...");
		getch();
		printBill();
	}	
}
//sweepstake
void luckyTicket(){
	system("cls");
	goToXY(0, 8);
	t();
	drawAnimation();
	char gift[200][20], checkFscanf;
	int i = 0, j, random;
	FILE *file = fopen("gift.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", gift[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	for(j = 0; j < (i - 1) / 2; j++){
		goToXY(53, 22 + j);
		printf("%d. %s", j + 1, gift[2 * j]);
	}
	goToXY(53, 24 + j);
	printf("Press any key to start...");
	getch();
	goToXY(53, 25 + j);
	printf("Wait for 3s...");
	Sleep(3000);
	random = rand() % 100;
	if(random <= 49){
		goToXY(53, 40 + j);
		textColor(10);
		printf("Good luck to you in the next time!!!");
		textColor(15);
		goodLuck();
	}
	if(random >= 50 && random <= 69){
		goToXY(53, 40 + j);
		textColor(10);
		printf("You get %s!!!", gift[0]);
		textColor(15);
		itoa(atoi(gift[1]) - 1, gift[1], 10);
		congratulation();
	}
	if(random >= 70 && random <= 84){
		goToXY(53, 40 + j);
		textColor(10);
		printf("You get %s!!!", gift[2]);
		textColor(15);
		itoa(atoi(gift[3]) - 1, gift[3], 10);
		congratulation();
	}
	if(random >= 85 && random <= 94){
		goToXY(53, 40 + j);
		textColor(10);
		printf("You get %s!!!", gift[4]);
		textColor(15);
		itoa(atoi(gift[5]) - 1, gift[5], 10);
		congratulation();
	}
	if(random >= 95 && random <= 99){
		goToXY(53, 40 + j);
		textColor(10);
		printf("You get %s!!!", gift[6]);
		textColor(15);
		itoa(atoi(gift[7]) - 1, gift[7], 10);
		congratulation();
	}
	FILE *fileEditGift = fopen("gift.txt", "w");
	for(j = 0; j < i - 1; j++){
		fprintf(fileEditGift, gift[j]);
		fprintf(fileEditGift, "\n");
	}
	fclose(fileEditGift);
	goToXY(53, 42 + j);
	printf("Thank for buying!!!");
	goToXY(53, 44 + j);
	printf("Do you want to avaluate our shop's service?");
	goToXY(53, 45 + j);
	printf("1. YES                 2. NO");
	switch(getch()){
		case '1':
			giveStar();
			break;
		case '2':
			goToXY(53, 46 + j);
			printf("Press any key to go to customer menu.");
			getch();
			break;
		default:
			goToXY(53, 46 + j);
			printf("\aInvalid input! Press any key to go to customer menu.");
			getch();
			break;
	}
	customerMenu();
}
//draw animation in sweepstake
void drawAnimation(){
	char strAnimation[13] = "SWEEPSTAKES ";
	int j;
	goToXY(53, 20);
	for(j = 0; j < 20; j++){
	Sleep(50);
	printf("_");
	}
	textColor(10);
	printf("\\\\ ");
	for(j = 0; j < 12; j++){
		Sleep(50);
		printf("%c", strAnimation[j]);
	}
	printf("//");
	textColor(15);
	for(j = 0; j < 20; j++){
		Sleep(50);
		printf("_");
	}
}
//congratulation
void congratulation(){
	int i;
	textColor(12);
	for(i = 0; i < 3; i++){
		Sleep(1000);
		goToXY(40, 30);
		printf("     ________   _________    _          ________      ________    ___    ________                               ___    ________    o   ________   _");
		goToXY(40, 31);
		printf("   /           /        /   / |    /   /             /       /   /   |      /       /         /    /           /   |      /       /   /       /  / |    /");
		goToXY(40, 32);
		printf("  /           /        /   /  |   /   /      ____   /_______/   /____|     /       /         /    /           /____|     /       /   /       /  /  |   /");
		goToXY(40, 33);
		printf(" /           /        /   /   |  /   /        /    /\\          /     |    /       /         /    /           /     |    /       /   /       /  /   |  /");
		goToXY(40, 34);
		printf("/________   /________/   /    |_/   /________/    /  \\        /      |   /       /_________/    /________   /      |   /       /   /_______/  /    |_/");	
		Sleep(1000);
		goToXY(40, 30);
		printf("                                                                                                                                                                  ");
		goToXY(40, 31);
		printf("                                                                                                                                                                  ");		
		goToXY(40, 32);
		printf("                                                                                                                                                                  ");		
		goToXY(40, 33);
		printf("                                                                                                                                                                  ");		
		goToXY(40, 34);
		printf("                                                                                                                                                                  ");	
	}
	goToXY(40, 30);
	printf("     ________   _________    _          ________      ________    ___    ________                               ___    ________    o   ________   _");
	goToXY(40, 31);
	printf("   /           /        /   / |    /   /             /       /   /   |      /       /         /    /           /   |      /       /   /       /  / |    /");
	goToXY(40, 32);
	printf("  /           /        /   /  |   /   /      ____   /_______/   /____|     /       /         /    /           /____|     /       /   /       /  /  |   /");
	goToXY(40, 33);
	printf(" /           /        /   /   |  /   /        /    /\\          /     |    /       /         /    /           /     |    /       /   /       /  /   |  /");
	goToXY(40, 34);
	printf("/________   /________/   /    |_/   /________/    /  \\        /      |   /       /_________/    /________   /      |   /       /   /_______/  /    |_/");	
	textColor(15);
}
//good luck the next time
void goodLuck(){
	int i;
	textColor(12);
	for(i = 0; i < 3; i++){
		Sleep(1000);
		goToXY(40, 30);
		printf("   ______     ______    ______   _                                ______    \n");
		goToXY(40, 31);
		printf("  /          /     /   /     /  /  \\        /        /     /     /         /____\n");
		goToXY(40, 32);
		printf(" /   ____   /     /   /     /  /    \\      /        /     /     /         /\\\n");
		goToXY(40, 33);
		printf("/_____/    /_____/   /_____/  /_____/     /_____   /_____/     /______   /  \\\n");
		Sleep(1000);
		goToXY(40, 30);
		printf("                                                                                                                                                                  ");
		goToXY(40, 31);
		printf("                                                                                                                                                                  ");		
		goToXY(40, 32);
		printf("                                                                                                                                                                  ");		
		goToXY(40, 33);
		printf("                                                                                                                                                                  ");		                                                                                                             	
	}
	goToXY(40, 30);
	goToXY(40, 30);
	printf("   ______     ______    ______   _                                ______    \n");
	goToXY(40, 31);
	printf("  /          /     /   /     /  /  \\        /        /     /     /         /____\n");
	goToXY(40, 32);
	printf(" /   ____   /     /   /     /  /    \\      /        /     /     /         /\\\n");
	goToXY(40, 33);
	printf("/_____/    /_____/   /_____/  /_____/     /_____   /_____/     /______   /  \\\n");
	textColor(15);
}
//give star
void giveStar(){
	system("cls");
	char star[5];
	int j = - 40;
	goToXY(70, 44 + j);
	textColor(10);
	printf("GIVE STARS");
	textColor(15);
	goToXY(53, 46 + j);
	printf("Please give shop stars...");
	goToXY(53, 47 + j);
	printf("5.	Very well                 2. Bad");
	goToXY(53, 48 + j);
	printf("4.	Well                      1. Very bad");
	goToXY(53, 49 + j);
	printf("3.	Normal                    ");
	do{
		goToXY(53, 51 + j);
		printf("                    ");
		goToXY(53, 51 + j);
		printf("You give: ");
		fflush(stdin);
		gets(star);
		if(star[0] < '1' || star[0] > '5' || strlen(star) != 1){
			goToXY(53, 52 + j);
			printf("Invalid input");
		}
		if(!(star[0] < '1' || star[0] > '5' || strlen(star) != 1)){
			goToXY(53, 52 + j);
			textColor(10);
			printf("Thank you very much!!!");
			textColor(15);
		} 
	} while(star[0] < '1' || star[0] > '5' || strlen(star) != 1);
	FILE *star1 = fopen("star.txt", "a");
	fprintf(star1, star);
	fprintf(star1, "\n");
	fclose(star1);
	goToXY(53, 54 + j);
	printf("Do you want to give feedback for shop?");
	goToXY(53, 55 + j);
	printf("1. YES            2. NO");
	switch(getch()){
		case '2':
			goToXY(53, 56 + j);
			printf("Press any key to back to customer menu");
			getch();
			break;
		case '1':
			feedback();
			break;
		default:
			goToXY(53, 56 + j);
			printf("Invalid input! Press any key to back to customer menu");
			getch();
			break;
	}
	customerMenu();
}
//feed back
void feedback(){
	char feedback[200];
	char account[200][20], checkFscanf;
	int i = 0, j, isFeed = - 1;
	goToXY(53, 17);
	textColor(10);
	printf("Input your feedback: ");
	textColor(15);
	fflush(stdin);
	gets(feedback);
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanf = fscanf(fileAcc, "%[^\n]%*c", account[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileAcc);
	FILE *star1 = fopen("feedback.txt", "a");
	fprintf(star1, feedback);
	fprintf(star1, "\n");
	fprintf(star1, account[0]);
	fprintf(star1, "\n");
	fclose(star1);
	goToXY(53, 20);
	textColor(10);
	printf("Thank for your feedback. Press any key to back to customer menu...");
	textColor(15);
	getch();
	customerMenu();
}
//change password
void changePass(){
	char product[200][20], checkFscanf, pass[20], newPass[20];
	//display
	int i = 0,j , k, isName = - 1;
	FILE *file7 = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(file7, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file7);
	goToXY(0, 33 + (i - 1) / 4 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 4 - 1);
	textColor(10);
	printf("CHANGE PASSWORD");
	textColor(15);
	//read file account
	char account[200][20], checkFscanfAcc;
	int a = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[a]);
		a++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	char cus[200][20], checkFscanfCus;
	int count2 = 0;
	//read file customer
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanfCus = fscanf(fileCus, "%[^\n]%*c", cus[count2]);
		count2++;
		if(checkFscanfCus == EOF) break;
	} while(checkFscanfCus != EOF);
	fclose(fileCus);
	for(k = 0; k < (count2 - 1) / 3; k++){
		if(strcmp(cus[3 * k], account[0]) == 0){
			isName = 3 * k;
		}
	}
	do{
		goToXY(53, 37 + (i - 1) / 4 - 1);
		printf("                             ");
		goToXY(53, 37 + (i - 1) / 4 - 1);
		printf("Pass     :    ");
		fflush(stdin);
		gets(pass);
		if(strcmp(pass, cus[isName + 1]) != 0){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("Pass is wrong!");
		}
		if(strcmp(pass, cus[isName + 1]) == 0){
			goToXY(53, 38 + (i - 1) / 4 - 1);
			printf("                    ");
		}
	} while(strcmp(pass, cus[isName + 1]) != 0);
	do{
		goToXY(53, 39 + (i - 1) / 4 - 1);
	    printf("                           ");
	    goToXY(53, 39 + (i - 1) / 4 - 1);
		printf("New pass :    ");
		fflush(stdin);
		gets(newPass);
		if(strlen(newPass) == 0){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("Please input!");
		}
		if(strlen(newPass) > 10){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("So long!");
		}
		if(!(strlen(newPass) == 0 || strlen(newPass) > 10)){
			goToXY(53, 40 + (i - 1) / 4 - 1);
			printf("                        ");
		}
	} while(strlen(newPass) == 0 || strlen(newPass) > 10);
	strcpy(cus[isName + 1], newPass);
	FILE *write = fopen("customer.txt", "w");
	for(k = 0; k < count2 - 1; k++){
		fprintf(write, cus[k]);
		fprintf(write, "\n");
	}
	fclose(write);
	goToXY(53, 44 + (i - 1) / 4 - 1);
	printf("Data was saved!!!");
	goToXY(53, 45 + (i - 1) / 4 - 1);
	printf("Press any key to back...");
	getch();
	customerMenu();
} 
//voucher
void voucher(){
	int choice, numFormat;
	char endChar;
	system("cls");
	char product[200][20], checkFscanf;
	int i = 0;
	FILE *filePrint = fopen("voucher.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	int j;
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          VOUCHER(%%)");
	textColor(15);
	for(j = 0; j < (i - 1) / 3; j++){
		goToXY(53, 12 + j);
		printf("%s", product[3 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", product[3 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", product[3 * j + 2]);
	}
	goToXY(0, 8);
	t();
	goToXY(0, 14 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 16 + j);
	textColor(10);
	printf("VOUCHER MENU");
	textColor(15);
	goToXY(53, 18 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 20 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1. Add vouchers                                                \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 5. Sort vouchers");
	goToXY(53, 22 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2. Delete vouchers                                             \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 6. Go to...");
	goToXY(53, 24 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3. Edit list                                                   \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 7. Exit");
	goToXY(53, 26 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 4. Look up vouchers                                            ");
	goToXY(53, 28 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 30 + j);
	printf("Get a choice: ");
	fflush(stdin);
	numFormat = scanf("%d%c", &choice, &endChar);
	if(numFormat != 2 || endChar != '\n' || choice < 1 || choice > 7){
		goToXY(53, 31 + j);
		printf("\aSorry! We don't have this choice. Please press any key to input a valid choice");
		if(getch()){
			voucher();
		}
	}
	if(choice == 6){
		goToXY(53, 34 + j);
		printf("1. Product menu");
		goToXY(53, 35 + j);
		printf("2. Customer menu");
		goToXY(53, 36 + j);
		printf("3. Main menu");
		switch(getch()){
			case '1':
				adminMenu();
				break;
			case '2':
				customer();
				break;
			case '3':
				mainMenu();
				break;
			default:
				printf("\a");
				voucher();
		}
	}
	if(choice == 7){
		finishProject();
	}
	if(choice == 1){
		addVoucher();
		voucher();
	}
	if(choice == 2){
		deleteVoucher();
	}
	if(choice == 3){
		editVoucher();
	}
	if(choice == 4){
		findVoucher();
		fflush(stdin);
		getch();
		voucher();
	}
	if(choice == 5){
		goToXY(0, 33 + (i - 1) / 3 - 1);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		goToXY(100, 35 + (i - 1) / 4 - 1);
		printf("SORT VOUCHER");
		goToXY(53, 38 + (i - 1) / 4 - 1);
		printf("1. Sort in Name");
		goToXY(53, 40 + (i - 1) / 4 - 1);
		printf("2. Sort in Voucher");
		switch(getch()){
			case '1':
				sortVoucherName();
				voucher();
			case '2': 
				sortVoucher();
				voucher();
			default:
				{
				goToXY(53, 42 + j);
				printf("\aYour choice is invalid, please press any key and input again....");
				if(getch()){
					voucher();
				}
			}
		}
	}
}
//add voucher
void addVoucher(){
	char voucher[5][20];
	//read file voucher
	int i, isNameCorrect = 1, isCodeCorrect = 1, coincide = 1, isVoucherCorrect = 1;
	char vou[200][20], checkFscanf;
	int count = 0;
	FILE *fileVoucher = fopen("voucher.txt", "r"); 
	do{
		checkFscanf = fscanf(fileVoucher, "%[^\n]%*c", vou[count]); 
		count++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileVoucher);
	goToXY(0, 33 + (count - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (count - 1) / 3 - 1);
	textColor(10);
	printf("ADD VOUCHER");
	goToXY(53, 37 + (count - 1) / 3 - 1);
	printf("Name    :                                                                           (Please input NAME don't have the special symbol and the length under 20)");
	goToXY(53, 39 + (count - 1) / 3 - 1);
	printf("Code    :                                                                           (CODE includes 2 numbers)");
	goToXY(53, 41 + (count - 1) / 3 - 1);
	printf("Voucher :                                                                           (Only include numbers, not begin with 0, 0 < price < 100)");      
	textColor(15);                                                                    
	//get name
	do{
		isNameCorrect = 1;
		goToXY(70, 37 + (count - 1) / 3 - 1);
		printf("                                                       ");
		goToXY(70, 37 + (count - 1) / 3 - 1);
		fflush(stdin);
		gets(voucher[0]);
		for(i = 0; voucher[0][i] != '\0'; i++){
			if((voucher[0][i] < 'A' || voucher[0][i] > 'Z') && (voucher[0][i] < 'a' || voucher[0][i] > 'z') && (voucher[0][i] < '0' || voucher[0][i] > '9')){
				isNameCorrect = 0;
			}
		}
		if(isNameCorrect == 0){
			goToXY(53, 38 + (count - 1) / 3 - 1);
			printf("Name only has lettes!!!                        ");      
		}
		if(strlen(voucher[0]) == 0){
			goToXY(53, 38 + (count - 1) / 3 - 1);
			printf("Input name, please!!!                          ");
		}
		if(strlen(voucher[0]) >= 20){
			goToXY(53, 38 + (count - 1) / 3 - 1);
			printf("The length of name unders 20 letters!!!        ");
		}
		if(!(isNameCorrect == 0 || strlen(voucher[0]) == 0 || strlen(voucher[0]) >= 20)){
			goToXY(53, 38 + (count - 1) / 3 - 1);
			printf("                                                               ");
		}
	} while(isNameCorrect == 0 || strlen(voucher[0]) == 0 || strlen(voucher[0]) >= 20);
	//get code
	do{
		isCodeCorrect = 1;
		coincide = 1;
		goToXY(70, 39 + (count - 1) / 3 - 1);
		printf("                 ");
		goToXY(70, 39 + (count - 1) / 3 - 1);
		fflush(stdin);
		gets(voucher[1]);
		for(i = 0; voucher[1][i] != '\0'; i++){
			if(voucher[1][i] < '0' || voucher[1][i] > '9'){
				isCodeCorrect = 0;
			}
		}
		for(i = 0; i < (count - 1) / 3; i++){
			if(strcmp(voucher[1], vou[3 * i + 1]) == 0){
				coincide = 0;
			}
		}
		if(isCodeCorrect == 0){
			goToXY(53, 40 + (count - 1) / 3 - 1);
			printf("CODE includes 2 numbers                                                               ");
		}
		if(coincide == 0){
			goToXY(53, 40 + (count - 1) / 3 - 1);
			printf("Code is available!!!                                                         ");
		}
		if(strlen(voucher[1]) == 0){
			goToXY(53, 40 + (count - 1) / 3 - 1);
			printf("Input code please...                                                                 ");
		}
		if(strlen(voucher[1]) == 1 || strlen(voucher[1]) > 2){
			goToXY(53, 40 + (count - 1) / 3 - 1);
			printf("The code includes 2 numbers                                                                                  ");
		}
		if(!(isCodeCorrect == 0 || coincide == 0 || strlen(voucher[1]) == 0 || strlen(voucher[1]) > 2 || strlen(voucher[1]) == 1)){
			goToXY(53, 40 + (count - 1) / 3 - 1);
			printf("                                                                                                    ");
		}
	} while(isCodeCorrect == 0 || coincide == 0 || strlen(voucher[1]) == 0 || strlen(voucher[1]) > 2 || strlen(voucher[1]) == 1);
	//get voucher
	do{
		isVoucherCorrect = 1;
		goToXY(70, 41 + (count - 1) / 3 - 1);
		printf("                                ");
		goToXY(70, 41 + (count - 1) / 3 - 1);
		fflush(stdin);
		gets(voucher[2]);
		for(i = 0; voucher[2][i] != '\0'; i++){
			if(voucher[2][i] < '0' || voucher[2][i] > '9'){
				isVoucherCorrect = 0;
			}
		}
		if(isVoucherCorrect == 0){
			goToXY(53, 42 + (count - 1) / 3 - 1);
			printf("Voucher is positive number < 100!!!                   ");
		}
		if(strlen(voucher[2]) == 0){
			goToXY(53, 42 + (count - 1) / 3 - 1);
			printf("Input voucher please!!!                            ");
		}
		if(strlen(voucher[2]) > 2){
			goToXY(53, 42 + (count - 1) / 3 - 1);
			printf("Voucher are less than 100!!!               ");
		}
		if(voucher[2][0] == '0'){
			goToXY(53, 42 + (count - 1) / 3 - 1);
			printf("Invalid if voucher begins with 0!!!                ");
		}
		if(!(voucher[2][0] == '0' || strlen(voucher[2]) > 2 || strlen(voucher[2]) == 0 || isVoucherCorrect == 0)){
			goToXY(53, 42 + (count - 1) / 3 - 1);
			printf("                                                     ");
		}
	} while(voucher[2][0] == '0' || strlen(voucher[2]) > 2 || strlen(voucher[2]) == 0 || isVoucherCorrect == 0);
	//add information into file
	FILE *fileAdd = fopen("voucher.txt", "a");
	for(i = 0; i < 3; i++){
		fprintf(fileAdd, voucher[i]);
		fprintf(fileAdd, "\n");
	}
	fclose(fileAdd);
	goToXY(53, 60 + (count - 1) / 3 - 1);
	printf("Data was saved !!!...");	
	goToXY(53, 61 + (count - 1) / 3 - 1);
	printf("Press any keys to display new product on screen...");
	getch();
}
//delete voucher
void deleteVoucher(){
	char vou[200][20], checkFscanf, code[10];
	int isCode = 0;
	int i = 0, j, k;
	FILE *file = fopen("voucher.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", vou[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 3 - 1);
	textColor(10);
	printf("DELETE VOUCHER");
	goToXY(53, 37 + (i - 1) / 3 - 1);
	printf("Please input code of voucher you want to delete: ");
	textColor(15);
	fflush(stdin);
	gets(code);
	for(j = 0; j < (i - 1) / 3; j++){
		if(strcmp(code, vou[3 * j + 1]) == 0){
			isCode = 3 * j + 1;
			break;
		}
	}
	if(isCode == 0){
		goToXY(53, 39 + (i - 1) / 3 - 1);
		printf("We don't have this code...");
		goToXY(53, 43 + (i - 1) / 3 - 1);
		printf("Wait for 3s...");	
		goToXY(53, 44 + (i - 1) / 3 - 1);
		printf("Back to admin menu");
		Sleep(3000);
		voucher();	
	}
	if(isCode != 0){
		for(j = isCode - 1; j < i - 1 - 3; j++){
			for(k = 0; k < 20; k++){
				vou[j][k] = vou[j + 3][k];
			}
			
		}
		FILE *fileDelete = fopen("voucher.txt", "w");
		for(j = 0; j < i - 1 - 3; j++){
			fprintf(fileDelete, vou[j]);
			fprintf(fileDelete, "\n");
		}
		fclose(fileDelete);
		goToXY(53, 43 + (i - 1) / 3 - 1);
		printf("Data was deleted...");	
		goToXY(53, 44 + (i - 1) / 3 - 1);
		printf("Press any key to edit information on screen...");
		getch();
		voucher();
	}
}
//edit voucher
void editVoucher(){
	char vou[200][20], checkFscanf;
	int i = 0, j, k;
	int isNameCorrect = 1, isVoucherCorrect = 1;
	FILE *file = fopen("voucher.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", vou[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 3 - 1);
	textColor(10);
	printf("EDIT VOUCHER");
	textColor(15);
	char newName[20], newVoucher[20], code[20];
	int isCode = 0;
	goToXY(53, 37 + (i - 1) / 3 - 1);
	printf("Please input code of voucher you want to edit: ");
	gets(code);
	for(j = 0; j < (i - 1) / 3; j++){
		if(strcmp(code, vou[3 * j + 1]) == 0){
			isCode = 3 * j + 1;
			break;
		}
	}
	if(isCode == 0){
		goToXY(53, 39 + (i - 1) / 3 - 1);
		printf("We don't have this code...");
		goToXY(53, 43 + (i - 1) / 3 - 1);
		printf("Waiting for 3s...");	
		goToXY(53, 44 + (i - 1) / 3 - 1);
		printf("Back to voucher menu...");
		Sleep(3000);
		voucher();
	}
	if(isCode != 0){
		textColor(10);
		goToXY(53, 39 + (i - 1) / 3 - 1);
		printf("New name   :");
		goToXY(53, 41 + (i - 1) / 3 - 1);
		printf("New voucher:");
		textColor(15);
		//get name
		do{
			isNameCorrect = 1;
			goToXY(70, 39 + (i - 1) / 3 - 1);
			printf("                                                                     ");
			goToXY(70, 39 + (i - 1) / 3 - 1);
			fflush(stdin);
			gets(newName);
			for(j = 0; newName[j] != '\0'; j++){
				if((newName[j] < 'A' || newName[j] > 'Z') && (newName[j] < 'a' || newName[j] > 'z') && newName[j] != ' ' && (newName[j] < '0' || newName[j] > '9')){
					isNameCorrect = 0;
				}
			}
			if(isNameCorrect == 0){
				goToXY(53, 40 + (i - 1) / 3 - 1);
				printf("Name only has lettes!!!                        ");      
			}
			if(strlen(newName) == 0){
				goToXY(53, 40 + (i - 1) / 3 - 1);
				printf("Input name, please!!!                          ");
			}
			if(strlen(newName) >= 20){
				goToXY(53, 40 + (i - 1) / 3 - 1);
				printf("The length of name unders 20 letters!!!        ");
			}
			if(!(isNameCorrect == 0 || strlen(newName) == 0 || strlen(newName) >= 20)){
				goToXY(53, 40 + (i - 1) / 3 - 1);
				printf("                                                               ");
			}
		} while(isNameCorrect == 0 || strlen(newName) == 0 || strlen(newName) >= 20);	
		//get voucher
		do{
			isVoucherCorrect = 1;
			goToXY(70, 41 + (i - 1) / 3 - 1);
			printf("                                                                     ");
			goToXY(70, 41 + (i - 1) / 3 - 1);
			fflush(stdin);
			gets(newVoucher);
			for(j = 0; newVoucher[j] != '\0'; j++){
				if(newVoucher[j] < '0' || newVoucher[j] > '9'){
					isVoucherCorrect = 0;
				}
			}
			if(isVoucherCorrect == 0){
				goToXY(53, 42 + (i - 1) / 3 - 1);
				printf("Voucher is a positive number!!!                   ");
			}
			if(strlen(newVoucher) == 0){
				goToXY(53, 42 + (i - 1) / 3 - 1);
				printf("Input voucher please!!!                            ");
			}
			if(strlen(newVoucher) > 2){
				goToXY(53, 42 + (i - 1) / 3 - 1);
				printf("Vouchers are less than 100!!!               ");
			}
			if(newVoucher[0] == '0'){
				goToXY(53, 42 + (i - 1) / 3 - 1);
				printf("Invalid if voucher begins with 0!!!                ");
			}
			if(!(newVoucher[0] == '0' || strlen(newVoucher) > 2 || strlen(newVoucher) == 0 || isVoucherCorrect == 0)){
				goToXY(53, 42 + (i - 1) / 3 - 1);
				printf("                                                     ");
			}
		} while(newVoucher[0] == '0' || strlen(newVoucher) > 2 || strlen(newVoucher) == 0 || isVoucherCorrect == 0);
		strcpy(vou[isCode - 1], newName);
		strcpy(vou[isCode + 1], newVoucher);
		FILE *fileEdit = fopen("voucher.txt", "w");
		for(j = 0; j < i - 1; j++){
			fprintf(fileEdit, vou[j]);
			fprintf(fileEdit, "\n");
		}
		fclose(fileEdit);
		goToXY(53, 45 + (i - 1) / 3 - 1);
		printf("Data was saved...");
		goToXY(53, 46 + (i - 1) / 3 - 1);
		printf("Press any keys to display new information on screen...");
		getch();
		voucher();	
	}
}
//find voucher
void findVoucher(){
	char vou[200][20], checkFscanf;
	int i = 0, j, k, height = 0, isFind = 0;
	FILE *file = fopen("voucher.txt", "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", vou[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(0, 33 + (i - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 3 - 1);
	textColor(10);
	printf("FIND VOUCHER");
	textColor(15);
	char letters[100];
	goToXY(53, 37 + (i - 1) / 3 - 1);
	printf("Letters to find: ");
	fflush(stdin);
	gets(letters);
	for(j = 0; j < (i - 1) / 3; j++){
		if(strstr(vou[3 * j], letters) != NULL){
			goToXY(53, 40 + (i - 1) / 3 - 1);
			textColor(10);
			printf("NAME                          CODE                          VOUCHER");
			textColor(15);
			for(k = 0; k < 3; k++){
				goToXY(53 + 30 * k, 42 + height + (i - 1) / 3 - 1);
				printf("%s", vou[3 * j + k]);
			}
			height++;
			isFind = 1;
		}
	}
	if(isFind == 0){
		goToXY(53, 42 + (i - 1) / 3 - 1);
		printf("No information!");
	}
	goToXY(53, 45 + height + (i - 1) / 3 - 1);
	printf("Press any key to come back to voucher menu");
}
//sort voucher name
void sortVoucherName(){
	system("cls");
	char copyChar, tmp0[20], tmp1[20], tmp2[20];
	FILE *fileSource = fopen("voucher.txt", "r");
	FILE *fileCopy = fopen("copy.txt", "w");
	do{
		copyChar = fgetc(fileSource);
		fputc(copyChar, fileCopy);
	} while(copyChar != EOF);
	fclose(fileSource);
	fclose(fileCopy);
	char vou[200][20], checkFscanf;
	int i = 0, j, k;
	FILE *fileSort = fopen("copy.txt", "r");
	do{
		checkFscanf = fscanf(fileSort, "%[^\n]%*c", vou[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileSort);
	for(j = 0; j < (i - 1) / 3; j++){
		for(k = 0; k < (i - 1) / 3 - j - 1; k++){
			if(strcmp(vou[3 * k], vou[3 * (k + 1)]) > 0){
				strcpy(tmp0, vou[3 * k]);
				strcpy(vou[3 * k], vou[3 * (k + 1)]);
				strcpy(vou[3 * (k + 1)], tmp0);
				strcpy(tmp1, vou[3 * k + 1]);
				strcpy(vou[3 * k + 1], vou[3 * (k + 1) + 1]);
				strcpy(vou[3 * (k + 1) + 1], tmp1);
				strcpy(tmp2, vou[3 * k + 2]);
				strcpy(vou[3 * k + 2], vou[3 * (k + 1) + 2]);
				strcpy(vou[3 * (k + 1) + 2], tmp2);
			}
		}
	}
	//print list
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          VOUCHER(%%)");
	textColor(15);
	for(j = 0; j < (i - 1) / 3; j++){
		goToXY(53, 12 + j);
		printf("%s", vou[3 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", vou[3 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", vou[3 * j + 2]);
	}
	goToXY(53, 16 + j);
	printf("Press any key to back");
	getch();
}
//sort voucher
void sortVoucher(){
	system("cls");
	char copyChar, tmp0[20], tmp1[20], tmp2[20];
	FILE *fileSource = fopen("voucher.txt", "r");
	FILE *fileCopy = fopen("copy.txt", "w");
	do{
		copyChar = fgetc(fileSource);
		fputc(copyChar, fileCopy);
	} while(copyChar != EOF);
	fclose(fileSource);
	fclose(fileCopy);
	char vou[200][20], checkFscanf;
	int i = 0, j, k;
	FILE *fileSort = fopen("copy.txt", "r");
	do{
		checkFscanf = fscanf(fileSort, "%[^\n]%*c", vou[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileSort);
	for(j = 0; j < (i - 1) / 3; j++){
		for(k = 0; k < (i - 1) / 3 - j - 1; k++){
			if(atoi(vou[3 * k + 2]) > atoi(vou[3 * (k + 1) + 2])){
				strcpy(tmp0, vou[3 * k]);
				strcpy(vou[3 * k], vou[3 * (k + 1)]);
				strcpy(vou[3 * (k + 1)], tmp0);
				strcpy(tmp1, vou[3 * k + 1]);
				strcpy(vou[3 * k + 1], vou[3 * (k + 1) + 1]);
				strcpy(vou[3 * (k + 1) + 1], tmp1);
				strcpy(tmp2, vou[3 * k + 2]);
				strcpy(vou[3 * k + 2], vou[3 * (k + 1) + 2]);
				strcpy(vou[3 * (k + 1) + 2], tmp2);
			}
		}
	}
	//print list
	goToXY(53, 10);
	textColor(10);
	printf("CODE                          NAME                          VOUCHER(%%)");
	textColor(15);
	for(j = 0; j < (i - 1) / 3; j++){
		goToXY(53, 12 + j);
		printf("%s", vou[3 * j + 1]);
		goToXY(53 + 30, 12 + j);
		printf("%s", vou[3 * j]);
		goToXY(53 + 30 * 2, 12 + j);
		printf("%s", vou[3 * j + 2]);
	}
	goToXY(53, 16 + j);
	printf("Press any key to back");
	getch();
}
//customer
void customer(){
	int choice, numFormat;
	char endChar;
	system("cls");
	char cus[200][20], checkFscanf;
	int i = 0;
	FILE *filePrint = fopen("customer.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", cus[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	int j, k;
	goToXY(53, 10);
	textColor(10);
	printf("NAME                                                        MONEY");
	textColor(15);
	for(j = 0; j < (i - 1) / 3; j++){
		goToXY(53, 12 + j);
		printf("%s", cus[3 * j]);
		goToXY(53 + 60, 12 + j);
		printf("%s", cus[3 * j + 2]);
	}
	goToXY(0, 8);
	t();
	goToXY(0, 14 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 16 + j);
	textColor(10);
	printf("CUSTOMER LIST");
	textColor(15);
	goToXY(53, 18 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 20 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 1. Read comment                                                \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 2. Go to...");
	goToXY(53, 22 + j);
	printf("\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB 3. Exit                                                ");
	goToXY(53, 24 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(53, 26 + j);
	printf("Get a choice: ");
	fflush(stdin);
	numFormat = scanf("%d%c", &choice, &endChar);
	if(numFormat != 2 || endChar != '\n' || choice < 1 || choice > 3){
		goToXY(53, 27 + j);
		printf("\aSorry! We don't have this choice. Please press any key to input a valid choice");
		if(getch()){
			customer();
		}
	}
	if(choice == 2){
		goToXY(53, 34 + j);
		printf("1. Voucher menu");
		goToXY(53, 35 + j);
		printf("2. Product menu");
		goToXY(53, 36 + j);
		printf("3. Main menu");
		switch(getch()){
			case '1':
				voucher();
				break;
			case '2':
				adminMenu();
				break;
			case '3':
				mainMenu();
				break;
			default:
				printf("\a");
				customer();
		}
	}
	if(choice == 1){
		readFeedback();
	}
	if(choice == 3){
		finishProject();
	}
}
//read feedback
void readFeedback(){
	//display
	char cus[200][20], checkFscanf;
	int i = 0, j, k;
	FILE *fileCus = fopen("customer.txt", "r");
	do{
		checkFscanf = fscanf(fileCus, "%[^\n]%*c", cus[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileCus);
	j = (i - 1) / 3 - 1;
	goToXY(0, 33 + (i - 1) / 3 - 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(100, 35 + (i - 1) / 3 - 1);
	textColor(10);
	printf("COMMENTS");
	textColor(15);
	char feed[20][200], checkFscanfFB;
	int count = 0;
	FILE *fileFB = fopen("feedback.txt", "r");
	do{
		checkFscanfFB = fscanf(fileFB, "%[^\n]%*c", feed[count]);
		count++;
		if(checkFscanfFB == EOF) break;
	} while(checkFscanfFB != EOF);
	fclose(fileFB);
	goToXY(0, 36 + j);
	textColor(10);
	printf("Press BACKSPACE to clean feedback");
	goToXY(0, 37 + j);
	printf("Press ESC to back");
	textColor(15);
	for(k = 0; k < (count - 1) / 2; k++){
		goToXY(53, 39 + j + k);
		printf("%s", feed[2 * k + 1]);
		goToXY(53 + 12, 39 + j + k);
		printf(":      ");
		printf("%s", feed[2 * k]);
	}
	switch(getch()){
		case 27:
			customer();
		case 8:
			remove("feedback.txt");
			customer();
		default:
			printf("\a");
			readFeedback();
	}
}
//cart 
void cart(){
	system("cls");
	goToXY(0, 2);
	t();
	mul();
	goToXY(0, 4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	goToXY(60, 13);
	textColor(10);
	printf("CART");
	textColor(15);
	goToXY(40, 15);
	printf("1. Add into cart                2. Edit quantity");
	goToXY(40, 16);
	printf("3. Delete                       4. Delete all");
	goToXY(40, 17);
	printf("5. Buy                          6. Back to customer menu");
	char account[200][20], checkFscanf, strFile[30];
	int i = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanf = fscanf(fileAcc, "%[^\n]%*c", account[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	goToXY(40, 40);
	char bill[200][20], checkFscanfBill;
	int count = 0, sum = 0, random, h, j;
	FILE *fileBill = fopen(strFile, "r");
	do{
		checkFscanfBill = fscanf(fileBill, "%[^\n]%*c", bill[count]);
		count++;
		if(checkFscanfBill == EOF) break;
	} while(checkFscanfBill != EOF);
	fclose(fileBill);
	goToXY(40, 40);
	textColor(10);
	printf("NAME");
	goToXY(60, 40);
	printf("QUANTITY");
	goToXY(80, 40);
	printf("MONEY");
	textColor(15);
	for(j = 0; j < (count - 1) / 4; j++){
		goToXY(40, 42 + j);
		printf("%s", bill[4 * j]);
	}
	for(j = 0; j < (count - 1) / 4; j++){
		goToXY(60, 42 + j);
		printf("%s", bill[4 * j + 3]);
	}
	for(j = 0; j < (count - 1) / 4; j++){
		goToXY(80, 42 + j);
		printf("%d", atoi(bill[4 * j + 3]) * atoi(bill[4 * j + 2]));
	}
	goToXY(40, 43 + j);
	textColor(10);
	printf("______________________________________________________");
	textColor(15);
	goToXY(40, 44 + j);
	textColor(10);
	printf("MONEY:");
	textColor(15);
	for(j = 0; j < (count - 1) / 4; j++){
		sum = sum + atoi(bill[4 * j + 3]) * atoi(bill[4 * j + 2]);
	}
	goToXY(80, 44 + j);
	printf("%d", sum);
	textColor(10);
	goToXY(40, 45 + j);
	printf("VAT 10%%:");
	textColor(15);
	goToXY(80, 45 + j);
	printf("%d", sum / 10);
	goToXY(40, 46 + j);
	textColor(10);
	printf("TOTAL:");
	textColor(15);
	goToXY(80, 46 + j);
	printf("%d", sum + sum / 10);
	switch(getch()){
		case '1':
			addCart();
			getch();
			cart();
		case '6':
			change();
			customerMenu();
		case '2':
			edit();
			cart();
		case'3':
			deleteCart();
			cart();
		case'5':
			confirm();
		case '4':
			deleteAll();
			cart();
		default:
			printf("\a");
			cart();
	}
}
//print list
void mul(){
	char account[200][20], checkFscanfAcc, strFile[30];
	int count1 = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[count1]);
		count1++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	char bill[200][20], checkFscanfBill;
	int count = 0, sum = 0, random, h, j;
	FILE *fileBill = fopen(strFile, "r");
	do{
		checkFscanfBill = fscanf(fileBill, "%[^\n]%*c", bill[count]);
		count++;
		if(checkFscanfBill == EOF) break;
	} while(checkFscanfBill != EOF);
	fclose(fileBill);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		for(h = 0; h < (count - 1) / 4; h++){
			itoa(atoi(bill[4 * h + 2]) * 80 / 100, bill[4 * h + 2], 10);
		}
	}
	FILE *wr = fopen(strFile, "w");
	for(h = 0 ; h < count - 1; h++){
		fprintf(wr, bill[h]);
		fprintf(wr, "\n");
	}
	fclose(wr);
	char product[200][20], checkFscanf;
	int i = 0;
	FILE *filePrint = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(filePrint, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(filePrint);
	goToXY(130, 5);
	printf("\xB2");
	goToXY(130, 6);
	printf("\xB2");
	goToXY(130, 7);
	printf("\xB2");
	textColor(10);
	goToXY(135, 6);
	printf("NAME");
	goToXY(165, 6);
	printf("PRICE");
	goToXY(195, 6);
	printf("QUANTITY");
	textColor(15);
	for(j = 0; j < (i - 1) / 4; j++){
		goToXY(130, 8 + j);
		printf("\xB2");
		goToXY(135, 8 + j);
		printf("%s", product[4 * j]);
		goToXY(165, 8 + j);
		printf("%s", product[4 * j + 2]);
		goToXY(195, 8 + j);
		printf("%s", product[4 * j + 3]);
	}
	goToXY(130, 9 + j);
	printf("\xB2");
	goToXY(130, 8 + j);
	printf("\xB2");
	goToXY(130, 10 + j);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
//add product to cart
void addCart(){
	int money = 0, isName = 1, isQuantityCorrect = 1, price[50];
	char product[200][20], checkFscanf, name[20], quantity[20], strFile[30];
	int i = 0, j, k, choice;
	FILE *fileRead = fopen("listProduct.txt", "r");
	do{
		checkFscanf = fscanf(fileRead, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(fileRead);
	goToXY(60, 20);
	textColor(10);
	printf("ADD INTO CART");
	textColor(15);
	goToXY(53, 22);
	printf("Name:");
	goToXY(53, 24);
	printf("Quantity:");
	do{
		isName = 1;
		goToXY(70, 22);
		printf("                              ");
		goToXY(70, 22);
		fflush(stdin);
		gets(name);
		for(j = 0; j < (i - 1) / 4; j++){
			if(strcmp(strlwr(name), strlwr(product[4 * j])) != 0){
				isName = - 1;
			} else {
				isName = 4 * j ;
				break;
			}
		}
		if(isName == - 1){
			goToXY(53, 23);
			printf("We don't have this product!!!                           ");
		}
		if(strlen(name) == 0){
			goToXY(53, 23);
			printf("Input name of product, please!!!                       ");
		}
		if(strlen(name) >= 20){
			goToXY(53, 23);
			printf("The legth of the name is so large!!!                   ");
		}
		if(!(isName == - 1 || strlen(name) == 0 || strlen(name) >= 20)){
			goToXY(53, 23);
			printf("                                                       ");
		}
	} while(isName == - 1 || strlen(name) == 0 || strlen(name) >= 20);
	do{
		isQuantityCorrect = 1;
		goToXY(70, 24);
		printf("                         ");
		goToXY(70, 24);
		fflush(stdin);
		gets(quantity);
		if(atoi(quantity) > atoi(product[isName + 3])){
			goToXY(53, 25);
			printf("We don't have enough products!!!                       ");
		}
		if(quantity[0] == '0'){
			goToXY(53, 25);
			printf("Minimum quantity is 1                                   ");
		}
		for(j = 0; quantity[j] != '\0'; j++){
			if(quantity[j] < '0' || quantity[j] > '9'){
				isQuantityCorrect = 0;
			}
		}
		if(isQuantityCorrect == 0){
			goToXY(53, 25);
			printf("Quantity is a positive number!!!                     ");
		}
		if(strlen(quantity) == 0){
			goToXY(53, 25);
			printf("Input quantity, please!!!                              ");
		}
		if(strlen(quantity) > 1){
			goToXY(53, 25);
			printf("Product's quantity < 10 & > 1                           ");
		}
		if(!(isQuantityCorrect == 0 || strlen(quantity) == 0 || strlen(quantity) > 1 || quantity[0] == '0' || atoi(quantity) > atoi(product[isName + 3]))){
			goToXY(53, 25);
			printf("                                                            ");
		}
	} while(isQuantityCorrect == 0 || strlen(quantity) == 0 || strlen(quantity) > 1 || quantity[0] == '0' || atoi(quantity) > atoi(product[isName + 3]));
	char account[200][20], checkFscanfAcc;
	int count = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[count]);
		count++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	FILE *fileBuy = fopen(strFile, "a");
	for(j = 0; j < 3; j++){
	fprintf(fileBuy, product[isName + j]);
	fprintf(fileBuy, "\n");
	}
	fprintf(fileBuy, quantity);
	fprintf(fileBuy, "\n");
	fclose(fileBuy);
	goToXY(40, 27);
	printf("Data was saved... Press any key to continue");
}
//edit cart
void edit(){
	char name[20], strFile[30], quantity[20];
	goToXY(60, 20);
	textColor(10);
	printf("EDIT QUANTITY");
	textColor(15);
	char voucher[200][20], checkFscanfVoucher;
	int count = 0, isName = - 1, validNum3 = 1;
	FILE *fileVou = fopen("account.txt", "r");
	do{
		checkFscanfVoucher = fscanf(fileVou, "%[^\n]%*c", voucher[count]);
		count++;
		if(checkFscanfVoucher == EOF) break;
	} while(checkFscanfVoucher != EOF);
	fclose(fileVou);
	strcpy(strFile, voucher[0]);
	strcat(strFile, ".txt");
	char product[200][20], checkFscanf;
	int i = 0, j, k;
	FILE *file = fopen(strFile, "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(40, 22);
	printf("Add name product do you want to edit: ");
	fflush(stdin);
	gets(name);
	for(j = 0; j < (i - 1) / 4; j++){
		if(strcmp(name, product[4 * j]) == 0){
			isName = 4 * j;
		}
	}
	if(isName == - 1){
		goToXY(40, 23);
		printf("Your cart don't have this product");
		goToXY(40, 24);
		printf("Wait for 3s to back...");
		Sleep(3000);
	}
	if(isName != - 1){
		goToXY(40, 23);
		printf("Your choice: +/-");
		switch(getch()){
			case '+':
				if(atoi(product[isName + 3]) == 9){
					goToXY(40, 25);
					printf("The maximum quantity is 1");
					goToXY(40, 27);
					printf("Wait for 3s to back...");
					Sleep(3000);
					cart();
				}
				itoa(atoi(product[isName + 3]) + 1, product[isName + 3], 10);
				break;
			case '-':
				if(atoi(product[isName + 3]) == 1){
					goToXY(40, 25);
					printf("The minimum quantity is 9");
					goToXY(40, 27);
					printf("Wait for 3s to back...");
					Sleep(3000);
					cart();
				}
				itoa(atoi(product[isName + 3]) - 1, product[isName + 3], 10);
				break;
			default:
				printf("\a");
				goToXY(40, 25);
				printf("Invalid input");
				goToXY(40, 27);
				printf("Wait for 3s to back...");
				Sleep(3000);
				cart();
				
		}
		FILE *wr = fopen(strFile, "w");
		for(k = 0; k < i - 1; k++){
			fprintf(wr, product[k]);
			fprintf(wr, "\n");
		}
		fclose(wr);
		cart();
	}
}
//delete one
void deleteCart(){
	char strFile[30], name[20];
	goToXY(60, 20);
	textColor(10);
	printf("DELETE");
	textColor(15);
	char account[200][20], checkFscanfAcc;
	int count = 0, isName = - 1, h;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[count]);
		count++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	char product[200][20], checkFscanf;
	int i = 0, j, k;
	FILE *file = fopen(strFile, "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file);
	goToXY(40, 22);
	printf("Add name product do you want to delete: ");
	fflush(stdin);
	gets(name);
	for(j = 0; j < (i - 1) / 4; j++){
		if(strcmp(name, product[4 * j]) == 0){
			isName = 4 * j;
		}
	}
	if(isName == - 1){
		goToXY(40, 23);
		printf("Your cart don't have this product");
		goToXY(40, 24);
		printf("Wait for 3s to back...");
		Sleep(3000);
	}
	if(isName != - 1){
		for(k = isName; k < i - 1 - 4; k++){
			for(h = 0; h < 20; h++){
				product[k][h] = product[k + 4][h];
			}			
		}
		FILE *fileDelete = fopen(strFile, "w");
			for(j = 0; j < i - 1 - 4; j++){
				fprintf(fileDelete, product[j]);
				fprintf(fileDelete, "\n");
			}
		fclose(fileDelete);
		goToXY(40, 23);
		printf("Data was deleted...");
		goToXY(40, 24);
		printf("Wait for 3s to back...");
		Sleep(3000);
	}
}
//delete all
void deleteAll(){
	goToXY(40, 20);
	textColor(10);
	printf("Do you want to delete all?");
	textColor(15);
	goToXY(40, 22);
	printf("1. YES             2. NO");
	switch(getch()){
		case '1':
			break;
		case '2':
			cart();
		default:
			printf("\a");
			cart();
	}
	
	char account[200][20], checkFscanfAcc, strFile[30];
	int count = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[count]);
		count++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	remove(strFile);
	cart();
}
//confirm 
void confirm(){
	int total = 0;
	char product1[200][20], checkFscanf1;
	int count = 0;
	FILE *file1 = fopen("listProduct.txt", "r"); 
	do{
		checkFscanf1 = fscanf(file1, "%[^\n]%*c", product1[count]); 
		count++;
		if(checkFscanf1 == EOF) break;
	} while(checkFscanf1 != EOF);
	fclose(file1);
	goToXY(40, 20);
	textColor(10);
	printf("Do you want to buy?");
	goToXY(40, 22);
	textColor(15);
	printf("1. YES             2. NO");
	switch(getch()){
		case '1':
			break;
		case '2':
			cart();
		default:
			printf("\a");
			cart();
	}
	char product3[200][20], checkFscanf3;
	int i3 = 0, h, e = - 1, sumTotal;
	FILE *file3 = fopen("customer.txt", "r");
	do{
		checkFscanf3 = fscanf(file3, "%[^\n]%*c", product3[i3]);
		i3++;
		if(checkFscanf3 == EOF) break;
	} while(checkFscanf3 != EOF);
	fclose(file3);
	char product2[200][20], checkFscanf2, strFile[30];
	int i2 = 0;
	FILE *file2 = fopen("account.txt", "r");
	do{
		checkFscanf2 = fscanf(file2, "%[^\n]%*c", product2[i2]);
		i2++;
		if(checkFscanf2 == EOF) break;
	} while(checkFscanf2 != EOF);
	fclose(file2);
	strcpy(strFile, product2[0]);
	strcat(strFile, ".txt");
	char product[200][20], checkFscanf;
	int i = 0, j, k, sum = 0, d = - 2;
	FILE *file = fopen(strFile, "r");
	do{
		checkFscanf = fscanf(file, "%[^\n]%*c", product[i]);
		i++;
		if(checkFscanf == EOF) break;
	} while(checkFscanf != EOF);
	fclose(file2);
	for(j = 0; j < (i - 1) / 4; j++){
		sum += (atoi(product[4 * j + 2])  * atoi(product[4 * j + 3]));
	}
	sumTotal = sum + sum / 10;
	for(j = 0; j < (i - 1) / 4; j++){
		for(k = 0; k < (count - 1) / 4; k++){
			if(strcmp(product[4 * j + 1], product1[4 * k + 1]) == 0){
				if(atoi(product[4 * j + 3]) > atoi(product1[4 * k + 3])){
					d = - 1;
				}
			}
		}
	}
	if(d == - 1){
		goToXY(40, 24);
		printf("Sorry!!! The product is not enough to buy...");
		goToXY(40, 25);
		printf("Press any key to back...");
		getch();
		cart();
	}
	char nameVou[20];
	int isVou = - 1;
	goToXY(40, 24);
	printf("Do you want to use voucher?");
	goToXY(40, 25);
	printf("1. YES       2. NO");
	char voucher[200][20], checkFscanfVoucher;
	int length = 0;
	FILE *fileVou = fopen("voucher.txt", "r");
	do{
		checkFscanfVoucher = fscanf(fileVou, "%[^\n]%*c", voucher[length]);
		length++;
		if(checkFscanfVoucher == EOF) break;
	} while(checkFscanfVoucher != EOF);
	fclose(fileVou);
	switch(getch()){
		case '1':
			goToXY(40, 26);
			textColor(10);
			printf("Input name of voucher:    ");
			textColor(15);
			fflush(stdin);
			gets(nameVou);
			for(k = 0; k < (length - 1) / 3; k++){
				if(strcmp(nameVou, voucher[3 * k]) == 0){
					isVou = 3 * k;
				}
			}
			if(isVou == - 1){
				goToXY(40, 26);
				printf("This voucher is not available!");
				goToXY(40, 27);
				printf("Press any key to back...");
				getch();
				cart();
			}
			if(isVou != - 1){
				total = sumTotal * (100 - atoi(voucher[isVou + 2])) / 100;
			}
		case '2':
			total = sumTotal;
			break;
		default:
			printf("\a");
			cart();
	}
	if(total > atoi(product2[2])){
		goToXY(40, 24);
		printf("Your money is not enough to pay, please add money into your account");
		goToXY(40, 25);
		printf("Press any key to back...");
		getch();
		cart();
	}
	for(h = 0; h < (i3 - 1) / 3; h++){
		if(strcmp(product2[0], product3[3 * h]) == 0){
			itoa(atoi(product3[3 * h + 2]) - total, product3[3 * h + 2], 10);
			e = 3 * h + 2;
		}
	}
	if(isVou != - 1){
		for(k = isVou; k < length - 1 - 3; k++){
			for(h = 0; h < 20; h++){
				voucher[k][h] = voucher[k + 3][h];
			}			
		}
		FILE *fileDel = fopen("voucher.txt", "w");
			for(j = 0; j < length - 1 - 3; j++){
				fprintf(fileDel, voucher[j]);
				fprintf(fileDel, "\n");
			}
		fclose(fileDel);
	}
	strcpy(product2[2], product3[e]);
	FILE *wr3 = fopen("account.txt", "w");
	fprintf(wr3, product2[0]);
	fprintf(wr3, "\n");
	fprintf(wr3, product2[1]);
	fprintf(wr3, "\n");
	fprintf(wr3, product2[2]);
	fprintf(wr3, "\n");
	fclose(wr3);
	FILE *wr = fopen("customer.txt", "w");
	for(h = 0; h < i3 - 1; h++){
		fprintf(wr, product3[h]);
		fprintf(wr, "\n");
	}
	fclose(wr);
	for(j = 0; j < (i - 1) / 4; j++){
		for(k = 0; k < (count - 1) / 4; k++){
			if(strcmp(product[4 * j + 1], product1[4 * k + 1]) == 0){
				itoa(atoi(product1[4 * k + 3]) - atoi(product[4 * j + 3]), product1[4 * k + 3], 10);
			}
		}
	}
	FILE *wr2 = fopen("listProduct.txt", "w");
	for(j = 0; j < count - 1; j++){
		fprintf(wr2, product1[j]);
		fprintf(wr2, "\n");
	}
	fclose(wr2);
	remove(strFile);
	int del = - 1;
	for(k = 0; k < (count - 1) / 4; k++){
		if(atoi(product1[4 * k + 3]) == 0){
			del = 4 * k;
		}
	}
	if(del != - 1){
		for(k = del; k < count - 1 - 4; k++){
			for(h = 0; h < 20; h++){
				product1[k][h] = product1[k + 4][h];
			}			
		}
		FILE *fileDelete = fopen("listProduct.txt", "w");
			for(j = 0; j < count - 1 - 4; j++){
				fprintf(fileDelete, product1[j]);
				fprintf(fileDelete, "\n");
			}
		fclose(fileDelete);
	}
	j = - 40;
	goToXY(40, 34);
	printf("Transaction is being made... Waiting for 5s...");
	Sleep(5000);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(sumTotal >= 200000 || tm.tm_wday == 0){
		system("cls");
		goToXY(53, 48 + j);
		textColor(10);
		printf("Successful transaction!!...");
		goToXY(53, 49 + j);
		printf("CONGRATULATION!!! You got a lucky ticket...");
		goToXY(53, 50 + j);
		printf("Press any key to use it!");
		textColor(15);
		getch();
		luckyTicket();	
	} else {
		goToXY(40, 36);
		printf("Successful transaction!!!... Do you want to evaluate our shop's service?");
		goToXY(40, 37);
		printf("1. YES                        2. NO");
		if(getch() == '1'){
			giveStar();
		}
		goToXY(40, 38);
		printf("Press any key to back to customer menu...");
		getch();
		customerMenu();
	}	
}
//print promotion into cart
void change(){
	char account[200][20], checkFscanfAcc, strFile[30];
	int count1 = 0;
	FILE *fileAcc = fopen("account.txt", "r");
	do{
		checkFscanfAcc = fscanf(fileAcc, "%[^\n]%*c", account[count1]);
		count1++;
		if(checkFscanfAcc == EOF) break;
	} while(checkFscanfAcc != EOF);
	fclose(fileAcc);
	strcpy(strFile, account[0]);
	strcat(strFile, ".txt");
	char bill[200][20], checkFscanfBill;
	int count = 0, sum = 0, random, h, j;
	FILE *fileBill = fopen(strFile, "r");
	do{
		checkFscanfBill = fscanf(fileBill, "%[^\n]%*c", bill[count]);
		count++;
		if(checkFscanfBill == EOF) break;
	} while(checkFscanfBill != EOF);
	fclose(fileBill);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if(tm.tm_wday + 1 == 6 && tm.tm_mday != 13){
		for(h = 0; h < (count - 1) / 4; h++){
			itoa(atoi(bill[4 * h + 2]) / 80 * 100, bill[4 * h + 2], 10);
		}
	}
	FILE *wr = fopen(strFile, "w");
	for(h = 0 ; h < count - 1; h++){
		fprintf(wr, bill[h]);
		fprintf(wr, "\n");
	}
	fclose(wr);
}

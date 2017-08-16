/*
 ============================================================================
 Name        : bank.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void fordelay(int j);
void new_account();
void menu();
void new_account();
void exit_system();
void update_info();
/*************************************************************************/
/**************************************************************************
 typedef enum accountType{
 saving , current , fixed_for_1_year ,fixed_for_2_years,fixed_for_3_years
 }accountType_t;
 *******************************************/
typedef struct date {
	int year;
	int month;
	int day;
} date_t;
/*******************************************/
typedef struct account {
	char name[20];
	date_t date_of_birth;
	char citizen_ship_number[15];
	char address[60];
	long phone_number;
	float deposit;
	char account_type[10];
	int account_number;
	int age;
	date_t deposit_date;
	date_t withdraw_date;

} account_t;

/*************************************************************************/

int main(void) {
	setbuf(stdout, NULL);
	char pass[10];
	char password[10] = "123456789";
	int i;
	printf("Enter The Login password :");
	scanf("%s", pass);
	while (strcmp(pass, password) != 0) {
		printf("Wrong password \n Please renter the password :");
		scanf("%s", pass);
	}
	if (strcmp(pass, password) == 0) {
		printf("Password match \n\n\t\t Loading");
		for (i = 0; i < 10; i++) {
			fordelay(100000000);
			printf(".");
		}
		menu();
	}

	return EXIT_SUCCESS;
}
/****************************************************************/
void fordelay(int j) {
	int i;
	for (i = 0; i < j; i++)
		;

}
/******************************************************************/
void menu() {
	int choice;
	system("color 9");
	printf(
			"\n\n\n\t\t\t\xB2\xB2\xB2 Bank Management System \xB2\xb2\t\t\t\n\n\n");
	printf("1- Create new account \n");
	printf("2- Update information of existing account \n");
	printf("3- For transaction \n");
	printf("4- Check the details of existing account \n");
	printf("5- Remove existing account \n");
	printf("6- View customer's list \n");
	printf("7- Exit \n");

	printf("\n\n\t\t Enter your choice :");
	scanf("%d", &choice);
	while (choice < 1 || choice > 7) {
		printf("Wrong Choice !! \n Please Enter your choice again :");
		scanf("%d", &choice);
	}
	switch (choice) {

	case 1:
		new_account();
		break;
	case 2:
		update_info();
		break;
	case 3:
		transact();
		break;

	}

}
/*******************************************************************************/
void new_account() {
	setbuf(stdout, NULL);
	FILE *ptr;
	int n = 1, x;
	account_t add, check;
	ptr = fopen("record.dat", "a+");
	printf("\n\n\n\t\t\t\xB2\xB2 ADD RECORD \xB2\xB2\t\t\t\n\n\n");

	a: rewind(ptr);
	printf("Enter account number : ");
	scanf("%d", &check.account_number);
	while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
			&add.account_number, add.name, &add.date_of_birth.year,
			&add.date_of_birth.month, &add.date_of_birth.day, &add.age,
			add.address, add.citizen_ship_number, &add.phone_number,
			add.account_type, &add.deposit, &add.deposit_date.year,
			&add.deposit_date.month, &add.deposit_date.day) == 14) {

		if (check.account_number == add.account_number) {
			goto a;
		}

	}

	add.account_number = check.account_number;
	printf("Enter name : ");
	scanf("%s", add.name);
	printf("Enter Date of Birth yyyy/mm/dd : ");
	scanf("%d/", &add.date_of_birth.year);
	scanf("%d/", &add.date_of_birth.month);
	scanf("%d", &add.date_of_birth.day);
	printf("Enter age : ");
	scanf("%d", &add.age);
	printf("Enter address : ");
	scanf("%s", add.address);
	printf("Enter Citizenship number : ");
	scanf("%s", add.citizen_ship_number);
	printf("Enter Phone : ");
	scanf("%ld", &add.phone_number);
	printf("Enter Account Type");
	printf("\n\n\t\t\xB2\xB2 Available acCount types \xB2\xB2\t\t\n\n");
	printf(
			"#saving \n#current \n#fixed_for_1_year\n#fixed_for_2_years\n#fixed_for_3_years\n");
	scanf("%s", add.account_type);
	printf("Enter deposit number : ");
	scanf("%f", &add.deposit);
	printf("Enter Today's date yyyy/mm/dd :");
	scanf("%d/%d/%d", &add.deposit_date.year, &add.deposit_date.month,
			&add.deposit_date.day);
	fprintf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
			add.account_number, add.name, add.date_of_birth.year,
			add.date_of_birth.month, add.date_of_birth.day, add.age,
			add.address, add.citizen_ship_number, add.phone_number,
			add.account_type, add.deposit, add.deposit_date.year,
			add.deposit_date.month, add.deposit_date.day);
	fclose(ptr);

	printf("\n\n\t\tEnter 1 to got to main window and 0 to exit");
	fflush(stdout);
	scanf("%d", &x);
	while (n == 1) {

		if (x == 0 || x == 1) {
			n = 0;
			break;
		} else {
			printf("Wrong choice \n Renter choice : ");
			scanf("%d", &x);
		}
	}
	if (x == 1)
		main();
	else if (x == 0)
		exit_system();
}
/*************************************************************************************/
void exit_system() {

}
/*******************************************/
void update_info() {
	FILE *ptr;
	int i;
	int x;
	int n;
	int acc_no;
	account_t add;
	printf("Enter account number : ");
	scanf("%d", &acc_no);
	ptr = fopen("record.dat", "w");
	for (i = 0; fscanf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
			&add.account_number, add.name, &add.date_of_birth.year,
			&add.date_of_birth.month, &add.date_of_birth.day, &add.age,
			add.address, add.citizen_ship_number, &add.phone_number,
			add.account_type, &add.deposit, &add.deposit_date.year,
			&add.deposit_date.month, &add.deposit_date.day) != 0; i++) {
		if (add.account_number == acc_no) {
			a: rewind(ptr);
			printf("Enter account number : ");
			scanf("%d", &acc_no);
			while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
					&add.account_number, add.name, &add.date_of_birth.year,
					&add.date_of_birth.month, &add.date_of_birth.day, &add.age,
					add.address, add.citizen_ship_number, &add.phone_number,
					add.account_type, &add.deposit, &add.deposit_date.year,
					&add.deposit_date.month, &add.deposit_date.day) == 14) {

				if (add.account_number == acc_no) {
					goto a;
				}

			}
		} else {
			add.account_number = acc_no;
			printf("Enter name : ");
			scanf("%s", add.name);
			printf("Enter Date of Birth yyyy/mm/dd : ");
			scanf("%d/", &add.date_of_birth.year);
			scanf("%d/", &add.date_of_birth.month);
			scanf("%d", &add.date_of_birth.day);
			printf("Enter age : ");
			scanf("%d", &add.age);
			printf("Enter address : ");
			scanf("%s", add.address);
			printf("Enter Citizenship number : ");
			scanf("%s", add.citizen_ship_number);
			printf("Enter Phone : ");
			scanf("%ld", &add.phone_number);
			printf("Enter Account Type");
			printf("\n\n\t\t\xB2\xB2 Available acCount types \xB2\xB2\t\t\n\n");
			printf(
					"#saving \n#current \n#fixed_for_1_year\n#fixed_for_2_years\n#fixed_for_3_years\n");
			scanf("%s", add.account_type);
			printf("Enter deposit number : ");
			scanf("%f", &add.deposit);
			printf("Enter Today's date yyyy/mm/dd :");
			scanf("%d/%d/%d", &add.deposit_date.year, &add.deposit_date.month,
					&add.deposit_date.day);
			fprintf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
					add.account_number, add.name, add.date_of_birth.year,
					add.date_of_birth.month, add.date_of_birth.day, add.age,
					add.address, add.citizen_ship_number, add.phone_number,
					add.account_type, add.deposit, add.deposit_date.year,
					add.deposit_date.month, add.deposit_date.day);
			fclose(ptr);

			printf("\n\n\t\tEnter 1 to got to main window and 0 to exit");
			fflush(stdout);
			scanf("%d", &x);
			while (n == 1) {

				if (x == 0 || x == 1) {
					n = 0;
					break;
				} else {
					printf("Wrong choice \n Renter choice : ");
					scanf("%d", &x);
				}
			}
			if (x == 1)
				main();
			else if (x == 0)
				exit_system();
		}
	}

}
/*******************************************************************************/

void transact() {
	FILE *ptr;
	int i;
	int x;
	int n;
	int acc_no;
	float transact;
	account_t add;
	printf("Enter account number : ");
	scanf("%d", &acc_no);
	ptr = fopen("record.dat", "w");
	for (i = 0; fscanf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
			&add.account_number, add.name, &add.date_of_birth.year,
			&add.date_of_birth.month, &add.date_of_birth.day, &add.age,
			add.address, add.citizen_ship_number, &add.phone_number,
			add.account_type, &add.deposit, &add.deposit_date.year,
			&add.deposit_date.month, &add.deposit_date.day) != 0; i++) {
		if (add.account_number == acc_no) {
			printf("To withdraw enter the amount with minus ,"
					"To deposite enter the amount as a positive value .\n");
			printf("Enter Your Transact : \n");
			scanf("%f",&transact);
            add.deposit = transact + add.deposit;
			fprintf(ptr, "%d %s %d/%d/%d %d %s %s %ld %s %f %d/%d/%d\n",
					add.account_number, add.name, add.date_of_birth.year,
					add.date_of_birth.month, add.date_of_birth.day, add.age,
					add.address, add.citizen_ship_number, add.phone_number,
					add.account_type, add.deposit, add.deposit_date.year,
					add.deposit_date.month, add.deposit_date.day);
			fclose(ptr);

			printf("\n\n\t\tEnter 1 to got to main window and 0 to exit");
			fflush(stdout);
			scanf("%d", &x);
			while (n == 1) {

						if (x == 0 || x == 1) {
							n = 0;
							break;
						} else {
							printf("Wrong choice \n Renter choice : ");
							scanf("%d", &x);
						}
					}
					if (x == 1)
						main();
					else if (x == 0)
						exit_system();
		}


	}
}

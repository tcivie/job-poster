#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"

void candidateMenu(char* name)
{
	int choice;
	printf("Hello dear %s\n", name);
	printf("what would you like to do?\n");
	printf("1-->Job search by parameters  \n2-->Submit a resume  \n3-->view all of submission's history  \n4-->Edit user profile  \n5-->Log out from system\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		/*function to Job search by parameters*/
		break;
	case 2:
		/*function to Submit a resume*/
		break;
	case 3:
		/*function to view all of submission's history*/
		break;
	case 4:
		/*function to Edit user profile*/
		break;
	case 5:
		/*function to Log out from system*/
		printf("goodbye %s!", name);
		return;
		break;

	default:
		break;
	}
}
void employerMenu(char* name)
{
	int choice;
	printf("Hello dear %s\nwhat would you like to do?\n1-->Post a new ad on the board\n", name);
	printf("2--> Delete an existing ad from the board\n");
	printf("3--> Update an existing ad on the board\n");
	printf("4--> View ads posted by the employer connected to the system\n");
	printf("5--> View profiles of candidates who have submitted resumes for the appropriate position\n");
	printf("6--> Job search by custom characteristics\n");
	printf("7--> Promotion of a job by means of payment\n");
	printf("8--> Changing the login password\n");
	printf("9--> Disconnecting from the system\n");

	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		/*function to Post a new ad on the board*/
		break;
	case 2:
		/*function to Delete an existing ad from the board*/
		break;
	case 3:
		/*function to Update an existing ad on the board*/
		break;
	case 4:
		/*function to View ads posted by the employer connected to the system*/
		break;
	case 5:
		/*function to View profiles of candidates who have submitted resumes for the appropriate position*/
		break;
	case 6:
		/*function to Job search by custom characteristics*/
		break;
	case 7:
		/*function to Promotion of a job by means of payment*/
		break;
	case 8:
		/*function to Changing the login password*/
		break;
	case 9:
		/*function to Disconnecting from the system*/
		printf("goodbye %c!", name);
		return;
		break;
	default:
		break;
	}
}


int main()
{
	char username[10], password[10], name[20];
	int option_menu1, age;
label1:
	printf("Hello! \n Enter what you want to do\n 1->connect as an employer\n 2-->connect as an candidate\n 3-->create a new employer\n 4-->create a new candidate\n ");
	scanf("%d", &option_menu1);

	switch (option_menu1)
	{
	case 1:
		printf("for login as an employer you need to enter the username and password:\n");
		printf("username:\n");
		scanf("%s", username);
		while (!(0/*השם של בדיקה פונקציית*/))
		{
			printf("this username is not agsist!\nplease enter a right username:\n");
			scanf("%s", username);
		}
		printf("enter a password:\n");
		gets(password);
		while (!(0/*function to check the password*/))
		{
			printf("please try again!\nenter a password:\n");
			gets(password);
		}
		printf("your login is succsess!\n");
		employerMenu(name);/*מעבר לתפריט של מעסיק פונקצייה-*/


		break;
	case 2:
		printf("for connect as an candidate you need to enter the username and password:\n");
		printf("username:\n");
		scanf("%s", username);
		while (!(0/*השם של בדיקה פונקציית*/))
		{
			printf("this username is not agsist!\nplease enter a right username:\n");
			scanf("%s", username);
		}
		printf("enter a password:\n");
		gets(password);
		while (!(0/*function to check the password*/))
		{
			printf("please try again!\nenter a password:\n");
			gets(password);
		}
		printf("your connect is succsess!\n");
		candidateMenu(name);/*transfer to candidate options menu.*/
		break;
	case 3:
		printf("for connect as an employer you need to enter the following details:\n");
		printf("enter username:\n");
		scanf("%s", username);
		while (!(0/*check function*/))
		{
			printf("this username is failed or allready agsist\nplease enter new username:\n");
			scanf("%s", username);
		}
		printf("enter name or business name:\n");
		scanf("%s", name);
		printf("enter password:\n");
		gets(password);
		while (!(0/*check function*/))
		{
			printf("this password is failed! \nplease enter new password:\n");
			gets(password);
		}
		printf("you have successfully registered!\n");
		employerMenu(name);/*transfered to employer options menu.*/

		break;
	case 4:
		printf("for connect as an candidate you need to enter the following details:\n");
		printf("enter username:\n");
		scanf("%s", username);
		/*chack the username.*/
		while (!username)
		{
			printf("this username is failed or allready agsist\nplease enter new username:\n");
			scanf("%s", username);
		}
		printf("enter name:\n");
		scanf("%s", name);
		printf("enter age:\n");
		scanf("%d", &age);
		printf("enter a phone number:\n");
		printf("enter a password:\n");
		gets(password);
		/*check the password and enter her again.*/
		while (!password)
		{
			printf("this password is failed! \nplease enter new password:\n");
			gets(password);
		}
		printf("you have successfully registered!\n");
		candidateMenu(name);/*transfer to candidate options menu.*/
		break;
	default:
		break;
	}
	goto label1;
}
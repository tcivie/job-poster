#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Check.h"
#include"connectF.h"
#include"Manager.h"

void candidateMenu(unsigned int *ID,char *name)
{
	char CV[MAX_DESCRIPTION]="";
	int choice=-1,size=-1,tempID=-1;
	Apply retValue[MAX_MANAGERS*MAX_POSTS];
	Post post;
	printf("\n------------------------------------------------------\n");
	printf("Hello dear %s\n", name);
	do {
		printf("What would you like to do?\n");
		printf("1-->Job search by parameters  \n2-->Submit a resume  \n3-->View all of submission's history  \n4-->Edit user profile  \n5-->Apply for job  \n6-->Log out from system\n");
		printf("------------------------------------------------------\n");
		yellow();
		printf("Choice:\t");
		scanf("%d", &choice);
		reset();
		system("cls");
		switch (choice)
		{
		case 1:
			/*function to Job search by parameters*/
			printPostsByCategory();
			break;
		case 2:
			/*function to Submit a resume*/
			strcpy(CV, "");
			enterCV(CV);
			updateUserData(ID, NULL, NULL, 0, 0, NULL, NULL, CV);
			break;
		case 3:
			/*function to view all of submission's history*/
			size = getAppliedByUser(&retValue, ID);
			if (size == 0)
				printf("You didnt apply for any job.\n");
			for (int i = 0; i < size; i++)
			{
				getPostData(&post, retValue[i].PostID);
				view_post(post);
			}
			break;
		case 4:
			/*function to Edit user profile*/
			editUserProfile(ID);
			break;
		case 5:
			printf("Enter the job application ID you would like to apply to ( enter 0 to go back to menu )\nID:\t");
			scanf("%d", &tempID);
			system("cls");
			if (ApplyJob(ID, tempID))
			{
				green();
				printf("Succesfuly applied\n");
				reset();
			}
			else
			{
				red();
				printf("Application error, please try again.\n");
				reset();
			}
			break;
		case 6:
			/*function to Log out from system*/
			printf("Goodbye %s!\n", name);
			return;
			break;

		default:
			break;
		}
	} while (1);
}
void employerMenu(unsigned int employerID,char *name)
{
	Post postsArray[MAX_POSTS];
	Post post = { 0 };
	for (int i = 0; i < MAX_POSTS; i++)
	{
		postsArray[i] = post;
	}
	
	char password[20], newpassword[20];
	int choice,size;

	do
	{

		printf("\n------------------------------------------------------\n");
		printf("Hello dear %s\nwhat would you like to do?\n 1--> Post a new ad on the board\n", name);
		printf(" 2--> Delete an existing ad from the board\n");
		printf(" 3--> Update an existing ad on the board\n");
		printf(" 4--> View ads posted by the employer connected to the system\n");
		printf(" 5--> View profiles of candidates who have submitted resumes for the appropriate position\n");
		printf(" 6--> Job search by custom characteristics\n");
		printf(" 7--> Promotion of a job by means of payment\n");
		printf(" 8--> Updating user profile\n");
		printf(" 9--> Disconnecting from the system\n");
		printf("10--> chat with a candidate\n");
		printf("------------------------------------------------------\n");
		yellow();
		printf("Choice:\t");
		scanf("%d", &choice);
		reset();
		system("cls");
		switch (choice)
		{
		case 1:
			/*function to Post a new ad on the board*/
			add_new_post(employerID);
			break;
		case 2:
			/*function to Delete an existing ad from the board*/
			delete_post(employerID);
			break;
		case 3:
			/*function to Update an existing ad on the board*/
			size = getPostsByManagerID(&postsArray, employerID);
			if (size == 0)
				printf("You have no posts yet.\n");
			for (int i = 0; i < size; i++)
			{
				view_post(postsArray[i]);
			}
			update_post(employerID);
			break;
		case 4:
			/*function to View ads posted by the employer connected to the system*/
			size =getPostsByManagerID(&postsArray, employerID);
			if (size == 0)
				printf("You have no posts yet.\n");
			for (int i = 0; i < size; i++)
			{
				view_post(postsArray[i]);
			}
			break;
		case 5:
			/*function to View profiles of candidates who have submitted resumes for the appropriate position*/
			view_profiles(employerID);
			break;
		case 6:
			printPostsByCategory();
			/*function to Job search by custom characteristics*/
			break;
		case 7:
			promotionAD(employerID);
			/*function to Promotion of a job by means of payment*/
			break;
		case 8:
			/*function to Changing the login password*/
			editManagerData(employerID);
			/*the password transfered to the  employer file and swich the old pass*/
			break;
		case 9:
			/*function to Disconnecting from the system*/
			printf("Goodbye %s!\n", name);
			return;
			break;
		case 10:
			printf("Who you want to speak with?");
			//not functional
		default:
			break;
		}
	} while (1);

}


int main()
{
	char username[10], password[20], name[20], newpassword[20], phoneNumber[20];
	int option_menu1, age;
	unsigned int userID;
	long ID;
	Manager manager;
	User user;
	initFiles();	// create missing files
label1:
	system("cls");
	printf("Hello! \n------------------------------------------------------");
	printf("\n Enter what you want to do:\n 1-->Connect as an employer\n 2-->Connect as an candidate\n 3-->Create a new employer\n 4-->Create a new candidate\n 5-->To close the program\n");
	printf("------------------------------------------------------\n");
	yellow();
	printf("Choice:\t");
	scanf("%d", &option_menu1);
	reset();
	system("cls");
	switch (option_menu1)
	{
	case 1:// #################################################################################
		printf("To login as an employer you have to enter the username and a password:\n");
		printf("Username:\t");
		while (getchar() != '\n');
		strcpy(username, "");
		scanf("%s", username);
		system("cls");
		while (!(checkManagerUserName(username)))
		{
			strcpy(username, "");
			while (getchar() != '\n');
			red();
			printf("This username does not exist!\nplease try again or 1 to exit:\n");
			reset();
			printf("Choice:\t");
			scanf("%s", username);
			system("cls");
			if (strcmp(username, "1") == 0)
				break;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		userID = checkManagerUserName(username);
		printf("Password:\t");
		getchar();
		gets(password);
		system("cls");
		while (!(checkPasswordManager(userID, password)))
		{
			red();
			printf("Wrong password! prees 1 to exit or try again!\nPassword:\t");
			reset();
			gets(password);
			system("cls");
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		green();
		printf("Your login is successful!\n");
		reset();
		getManagerData(&manager, userID);
		employerMenu(userID, manager.FullName);/*moved to employer menu*/
		break;
	case 2://#############################################################
		printf("To login as a candidate you need to enter username and password:\n");
		printf("Username:\t");
		getchar();
		gets( username);
		system("cls");
		while (!(checkUserName(username)))
		{
			red();
			printf("This username does not exist!\nplease try again or 1 to exit:\n");
			reset();
			printf("Username:\t");
			gets( username);
			if (strcmp(username, "1") == 0)
				goto label1;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		userID = checkUserName(username);
		printf("Password:\t");
		gets(password);
		while (!(checkPasswordUser(userID, password)))
		{
			red();
			printf("Wrong password! press 1 to exit or try again!\nPassword:\t");
			reset();
			gets(password);
			system("cls");
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		system("cls");
		green();
		printf("Successful login!\n");
		reset();
		getUserData(&user, userID);
		candidateMenu(userID, user.FullName);/*transfer to candidate options menu.*/
		break;
	case 3://############################################
		printf("To register as an employer you need to enter the following details:\n");
		printf("Username:\t");
		scanf("%s", username);
		system("cls");
		while (FullNameCheck(username) || checkManagerUserName(username))
		{
			red();
			printf("This username is incorrect or already exists\nplease enter new username or 1 to exit:\nUsername:\t");
			reset();
			scanf("%s", username);
			system("cls");
			if (strcmp(username, "1") == 0)
				break;
		}
		/*if (strcmp(username, '1') == 0)
			goto label1;*/	// ERROR: EXCEPTION - READ LOCATION VIOLATION
		while (getchar() != '\n');
		printf("Enter name or business name:\t");
		
		gets(name);
		system("cls");
		printf("Enter a password:\n1. At least 6 digits.\n2. English letters and numbers only.\n3. At least one capital letter and one small cap letter.\nPassword:\t");
		gets(password);
		system("cls");
		while (PasswordCheck(password))	// ERROR: SKIPPING FIRST PASSWORD CHECK
		{
			red();
			printf("Password failed! \nplease enter new password or 1 to exit:\nPassword:\t");
			reset();
			gets(password);
			system("cls");
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("To verify the password\nenter the password again\nPassword:\t");
		gets(newpassword);
		system("cls");
		while (strcmp(password, newpassword)!= 0)
		{
			red();
			printf("The verify failed\nenter the password again\nPassword:\t");
			reset();
			gets(newpassword);
			system("cls");
			if (strcmp(newpassword, "1") == 0)
				break;
		}
		if (strcmp(newpassword, "1") == 0)
			goto label1;
		userID = registerManager(username, name, password);
		if (userID == 0)
		{
			red();
			printf("Register failed!\nproblem with the file!");
			reset();
			goto label1;
		}
		green();
		printf("You have been successfully registered!\n");
		reset();
		employerMenu(userID,name);/*transfered to employer options menu.*/
		break;
	case 4:
		printf("To register as a candidate you need to enter the following details:\n");
		printf("Username:\t");
		scanf("%s", username);
		system("cls");
		while (FullNameCheck(username)|| checkUserName(username))
		{
			red();
			printf("This username is incorrect or alreadt exists\nplease enter new username or 1 to exit:\nUsername:\t");
			reset();
			scanf("%s", username);
			system("cls");
			if (strcmp(username, "1") == 0)
				break;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		printf("Full name:\t");
		getchar();
		gets(name);
		system("cls");
		printf("Enter ID:\t");
		scanf("%ld", &ID);
		system("cls");
		while (!(IDcheck(ID)))
		{
			red();
			printf("Not valid ID\nenter ID again or press 1 to exit:\nEnter ID:\t");
			reset();
			scanf("%ld", &ID);
			system("cls");
			if (ID == 1)
				break;
		}
		if (ID == 1)
			goto label1;
		printf("Enter age:\t");
		scanf("%d", &age);
		system("cls");
		while (AgeCheck(age))
		{
			red();
			printf("Wrong age!\nplease try again\nEnter age:\t");
			reset();
			scanf("%d", &age);
			system("cls");
		}
		printf("Enter a phone number:\t");
		getchar();
		gets(phoneNumber);
		system("cls");
		while (phoneNumberCheck(phoneNumber))
		{
			red();
			printf("not valid number!\npress 1 to exit or a correct phone number:\nEnter a phone number:\t");
			reset();
			gets(phoneNumber);
			system("cls");
			if (strcmp(phoneNumber, "1") == 0)
				break;
		}
		if (strcmp(phoneNumber, "1") == 0)
			goto label1;
		printf("Enter a password:\n1.At least 6 digits.\n2.English letters and numbers only.\n3.At least one capital letter and one small cap letter.\nPassword:\t");
		gets(password);
		system("cls");
		while (PasswordCheck(password))/*check the password and enter her again.*/
		{
			red();
			printf("This password is incorrect! \nplease enter new password or press 1 to exit:\nPassword:\t");
			reset();
			gets(password);
			system("cls");
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("To verify the password\nenter the password again\nPassword:\t");
		gets(newpassword);
		system("cls");
		while (strcmp(password, newpassword)!=0)
		{
			red();
			printf("The verify failed\nenter the password again or press 1 to exit:\nPassword:\t");
			reset();
			gets(newpassword);
			system("cls");
			if (strcmp(newpassword, "1") == 0)
				break;
		}
		if (strcmp(newpassword, "1") == 0)
			goto label1;
		/*send the ditails to the file--gleb*/
		userID=registerUser(username,name,ID,age,phoneNumber,password,"");
		if (userID == 0)
		{	
			red();
			printf("Register failed!\nproblem with the file!");
			reset();
			goto label1;
		}
		green();
		printf("You have successfully registered!\n");
		reset();
		candidateMenu(userID,name,ID,age,phoneNumber,password);/*transfer to candidate options menu.*/
		break;
	case 5:
		printf("Thank you!\ngoodbye");
		goto label2;
	default:
		red();
		printf("Error input! please try again\n");
		reset();
		goto label1;
		break;
	}
	goto label1;
label2:
	return 0;
}
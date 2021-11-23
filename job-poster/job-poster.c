#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Check.h"
#include"connectF.h"
#include"Manager.h"

void candidateMenu(unsigned int *ID,char *name,long id,int age,char *phoneNumber,char *password)
{
	char CV[MAX_DESCRIPTION]="";
	int choice,size;
	Apply retValue[MAX_MANAGERS*MAX_POSTS];
	Post post;
	printf("Hello dear %s\n", name);
	printf("what would you like to do?\n");
	printf("1-->Job search by parameters  \n2-->Submit a resume  \n3-->view all of submission's history  \n4-->Edit user profile  \n5-->Log out from system\n");
	scanf("%d", &choice);
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
		size=getAppliedByUser(&retValue, ID);
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
		/*function to Log out from system*/
		printf("goodbye %s!\n", name);
		return;
		break;

	default:
		break;
	}
}
void employerMenu(unsigned int employerID,char *name)
{
	Post postsArray[MAX_POSTS];
	char password[20], newpassword[20];
	int choice,size;
	printf("Hello dear %s\nwhat would you like to do?\n1-->Post a new ad on the board\n", name);
	printf("2--> Delete an existing ad from the board\n");
	printf("3--> Update an existing ad on the board\n");
	printf("4--> View ads posted by the employer connected to the system\n");
	printf("5--> View profiles of candidates who have submitted resumes for the appropriate position\n");
	printf("6--> Job search by custom characteristics\n");
	printf("7--> Promotion of a job by means of payment\n");
	printf("8--> Changing the login password\n");
	printf("9--> Disconnecting from the system\n");
	printf("10-->chat with a candidate\n");
	scanf("%d", &choice);
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
		update_post(employerID);
		break;
	case 4:
		/*function to View ads posted by the employer connected to the system*/
		size =getPostsByManagerID(&postsArray, employerID);
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
		printf("goodbye %c!\n", name);
		return;
		break;
	case 10:
		printf("who you want to speak with?");
		//not functional
	default:
		break;
	}
}


int main()
{
	char username[10], password[20], name[20], newpassword[20], phoneNumber[20];
	int option_menu1, age;
	unsigned int userID;
	long ID;
	initFiles();	// create missing files
label1:
	printf("Hello! \n Enter what you want to do\n 1->connect as an employer\n 2-->connect as an candidate\n 3-->create a new employer\n 4-->create a new candidate\n5-->to close the program");
	scanf("%d", &option_menu1);

	switch (option_menu1)
	{
	case 1:
		printf("to login as an employer you have to enter the username and a password:\n");
		printf("username:\n");
		scanf("%s", username);
		while (!(checkManagerUserName(username)))
		{
			printf("this username does not exist!\nplease try again or 1 to exit:\n");
			scanf("%s", username);
			if (strcmp(username, "1") == 0)
				break;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		userID = checkUserName(username);
		printf("enter a password:\n");
		gets(password);
		while (!(checkPasswordManager(userID, password)))
		{
			printf("prees 1 to exit or try again!\nenter a password:\n");
			gets(password);
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("your login is succsess!\n");
		employerMenu(userID, username);/*moved to employer menu*/
		break;
	case 2:
		printf("to login as a candidate you need to enter username and password:\n");
		printf("username:\n");
		scanf("%s", username);
		while (!(checkUserName(username)))
		{
			printf("this username does not exist!\nplease try again or 1 to exit:\n");
			scanf("%s", username);
			if (strcmp(username, "1") == 0)
				break;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		userID = checkUserName(username);
		printf("enter a password:\n");
		gets(password);
		while (!(checkPasswordUser(userID, password)))
		{
			printf("press 1 to exit or try again!\nenter a password:\n");
			gets(password);
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("successful login!\n");
		candidateMenu(userID, username,ID,age,phoneNumber,password);/*transfer to candidate options menu.*/
		break;
	case 3:
		printf("to login as an employer you need to enter the following details:\n");
		printf("enter username:\n");
		scanf("%s", username);
		while (FullNameCheck(username) || checkManagerUserName(username))
		{
			printf("this username is incorrect or already exists\nplease enter new username or 1 to exit:\n");
			scanf("%s", username);
			if (strcmp(username, "1") == 0)
				break;
		}
		/*if (strcmp(username, '1') == 0)
			goto label1;*/	// ERROR: EXCEPTION - READ LOCATION VIOLATION
		printf("enter name or business name:\n");
		scanf("%s", name);
		printf("enter a password:\n1.At least 6 digits.\n2.English letters and numbers only.\n3.At least one capital letter and one small cap letter.\n");
		getchar();	// clean buffer
		gets(password);
		while (PasswordCheck(password))	// ERROR: SKIPPING FIRST PASSWORD CHECK
		{
			printf("password failed! \nplease enter new password or 1 to exit:\n");
			gets(password);
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("to verify the password\nenter the password again\n");
		gets(newpassword);
		while (strcmp(password, newpassword)!= 0)
		{
			printf("the verify failed\nenter the password again\n");
			gets(newpassword);
			if (strcmp(newpassword, "1") == 0)
				break;
		}
		if (strcmp(newpassword, "1") == 0)
			goto label1;
		userID = registerManager(username, name, password);
		if (userID == 0)
		{
			printf("register failed!\nproblem with the file!");
			goto label1;
		}
		printf("you have successfully registered!\n");
		employerMenu(userID,name);/*transfered to employer options menu.*/
		break;
	case 4:
		printf("to connect as a candidate you need to enter the following details:\n");
		printf("enter username:\n");
		scanf("%s", username);
		while (!(FullNameCheck(username))&& !(checkUserName(username)))
		{
			printf("this username is incorrect or alreadt exists\nplease enter new username or 1 to exit:\n");
			scanf("%s", username);
			if (strcmp(username, "1") == 0)
				break;
		}
		if (strcmp(username, "1") == 0)
			goto label1;
		printf("enter name:\n");
		scanf("%s", name);
		printf("enter ID");
		scanf("%ld", &ID);
		while (!(IDcheck(ID)))
		{
			printf("not valid ID\nenter ID again or press 1 to exit:\n");
			scanf("%ld", &ID);
			if (ID == 1)
				break;
		}
		if (ID == 1)
			goto label1;
		printf("enter age:\n");
		scanf("%d", &age);
		while (!(AgeCheck(age)))
		{
			printf("wrong age!\nplease try again");
			scanf("%d", &age);
		}
		printf("enter a phone number:\n");
		gets(phoneNumber);
		while (!(phoneNumberCheck(phoneNumber)))
		{
			printf("not valid number!\npress 1 to exit or a correct phone number:\n");
			gets(phoneNumber);
			if (strcmp(phoneNumber, "1") == 0)
				break;
		}
		if (strcmp(phoneNumber, "1") == 0)
			goto label1;
		printf("enter a password:\n1.At least 6 digits.\n2.English letters and numbers only.\n3.At least one capital letter and one small cap letter.\n");
		gets(password);
		while (PasswordCheck(password))/*check the password and enter her again.*/
		{
			printf("this password is incorrect! \nplease enter new password or press 1 to exit:\n");
			gets(password);
			if (strcmp(password, "1") == 0)
				break;
		}
		if (strcmp(password, "1") == 0)
			goto label1;
		printf("to verify the password\nenter the password again\n");
		gets(newpassword);
		while (strcmp(password, newpassword)!=0)
		{
			printf("the verify failed\nenter the password again or press 1 to exit:\n");
			gets(newpassword);
			if (strcmp(newpassword, "1") == 0)
				break;
		}
		if (strcmp(newpassword, "1") == 0)
			goto label1;
		/*send the ditails to the file--gleb*/
		userID=registerUser(username,name,ID,age,phoneNumber,password,NULL);
		if (userID == 0)
		{
			printf("register failed!\nproblem with the file!");
			goto label1;
		}
		printf("you have successfully registered!\n");
		candidateMenu(userID,name,ID,age,phoneNumber,password);/*transfer to candidate options menu.*/
		break;
	case 5:
		printf("thank you!\ngoodbye");
		goto label2;
	default:
		printf("Error input! please try again\n");
		goto label1;
		break;
	}
	goto label1;
label2:
	return 0;
}
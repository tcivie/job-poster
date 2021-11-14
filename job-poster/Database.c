#include "Database.h"

int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE]) {
	FILE* infile;
	int userID = getLastIdUsers() + 1;
	User user = { userID };	// if got userID add user otherwise ID = 1
	// Append data to the created struct user
	strcpy(user.UserName, UserName);
	strcpy(user.FullName, FullName);
	user.ID = ID;
	user.age = age;
	strcpy(user.PhoneNumber, PhoneNumber);

	infile = fopen(USERS_FILENAME, "ab");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fwrite(&user, sizeof(User), 1, infile);
		fclose(infile);
		return userID;
	}
	return 0;
}

int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE]) {
	FILE* infile;
	int managerID = getLastIdManagers() + 1;
	Manager manager = { managerID };	// if got managerID add manager otherwise ID = 1
	// Append data to the created struct manager
	strcpy(manager.UserName, UserName);
	strcpy(manager.FullName, FullName);

	infile = fopen(MANAGERS_FILENAME, "ab");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fwrite(&manager, sizeof(Manager), 1, infile);
		fclose(infile);
		return managerID;
	}
	return 0;
}

int addPost(int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]) {
	// TODO
	return 0;
}

int getUserData(User* retValue, const unsigned int userID) {
	FILE* infile;
	infile = fopen(USERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(retValue, sizeof(User), 1, infile)) {	// read trough file
			if (retValue->UserID == userID) {	// check if equal
				fclose(infile);
				return 1;	// return 1
			}
		}
		fclose(infile);
		retValue = NULL;
		return 0;
	}
}

int getManagerData(Manager* retValue, const unsigned int managerID) {
	FILE* infile;
	infile = fopen(USERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(retValue, sizeof(Manager), 1, infile)) {	// read trough file
			if (retValue->ManagerID == managerID) {	// check if equal
				fclose(infile);
				return 1;	// return 1
			}
		}
		fclose(infile);
		retValue = NULL;
		return 0;
	}
}

int initFiles() {
	FILE* usersFile, * managersFile, * postsFile;
	usersFile = fopen(USERS_FILENAME, "ab");
	if (usersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING USERS FILE\n");
		exit(1);
	} else
		fclose(usersFile);
	managersFile = fopen(MANAGERS_FILENAME, "ab");
	if (managersFile == NULL) {
		fprintf(stderr, "\nERROR OPENING MANAGERS FILE\n");
		exit(1);
	} else
		fclose(managersFile);
	postsFile = fopen(POSTS_FILENAME, "ab");
	if (postsFile == NULL) {
		fprintf(stderr, "\nERROR OPENING POSTS FILE\n");
		exit(1);
	} else
		fclose(postsFile);
	return 1;
}

int checkUserName(char UserName[MAX_SIZE]) {
	FILE* infile;
	User input;
	infile = fopen(USERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(&input, sizeof(User), 1, infile)) {	// read trough file
			if (strcmp(input.UserName, UserName) == 0) {	// check if equal
				fclose(infile);
				return input.UserID;	// return user ID
			}
		}
		fclose(infile);
		return 0;
	}
}

int checkManagerUserName(char UserName[MAX_SIZE]) {
	FILE* infile;
	Manager input;
	infile = fopen(MANAGERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(&input, sizeof(Manager), 1, infile)) {	// read trough file
			if (strcmp(input.UserName, UserName) == 0) {	// check if equal
				fclose(infile);
				return input.ManagerID;	// return user ID
			}
		}
		fclose(infile);
		return 0;
	}
}

int getLastIdUsers() {
	FILE* infile;
	User input;
	infile = fopen(USERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fseek(infile, 0, SEEK_END);	// go to end of file
		if (ftell(infile)) {	// check if not empty
			fseek(infile, -(int)sizeof(User), SEEK_END);
			fread(&input, sizeof(User), 1, infile);	// read last user
			fclose(infile);
			return input.UserID;
		}
	}
	return 0;
}

int getLastIdManagers() {
	FILE* infile;
	Manager input;
	infile = fopen(MANAGERS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fseek(infile, 0, SEEK_END);	// go to end of file
		if (ftell(infile)) {	// check if not empty
			fseek(infile, -(int)sizeof(Manager), SEEK_END);
			fread(&input, sizeof(Manager), 1, infile);	// read last manager
			fclose(infile);
			return input.ManagerID;
		}
	}
	return 0;
}

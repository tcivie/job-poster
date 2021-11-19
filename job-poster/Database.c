#include "Database.h"

int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD]) {
	FILE* infile;
	int userID = getLastIdUsers() + 1;
	User user = { userID };	// if got userID add user otherwise ID = 1
	// Append data to the created struct user
	strcpy(user.UserName, UserName);
	strcpy(user.FullName, FullName);
	user.ID = ID;
	user.age = age;
	strcpy(user.PhoneNumber, PhoneNumber);
	strcpy(user.Password, Password);

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

int updateUserData(const unsigned int userID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD]) {
	User user, iterator;
	FILE* infile;
	if (getUserData(&user, userID)) {	// if user exists
		if (UserName != NULL)
			strcpy(user.UserName, UserName);
		if (FullName != NULL)
			strcpy(user.FullName, FullName);
		if (ID != 0)
			user.ID = ID;
		if (age != 0)
			user.age = age;
		if (PhoneNumber != NULL)
			strcpy(user.PhoneNumber, PhoneNumber);
		if (Password != NULL)
			strcpy(user.Password, Password);

		// Start reding the file to find the user and modify it
		infile = fopen(USERS_FILENAME, "wb");
		if (infile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			while (fread(&iterator, sizeof(User), 1, infile)) {	// read trough file
				if (iterator.UserID == userID)
					break;	// found the user and read it
			}
			fseek(infile, -(int)sizeof(User), SEEK_CUR);	// jump back one user
			fwrite(&user, sizeof(User), 1, infile);	// write the changes
			fclose(infile);
			return userID;
		}
	} else
		return 0;
}

int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]) {
	FILE* infile;
	int managerID = getLastIdManagers() + 1;
	Manager manager = { managerID };	// if got managerID add manager otherwise ID = 1
	// Append data to the created struct manager
	strcpy(manager.UserName, UserName);
	strcpy(manager.FullName, FullName);
	strcpy(manager.Password, Password);

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

int updateManagerData(const unsigned int managerID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]) {
	Manager manager, iterator;
	FILE* infile;
	if (getManagerData(&manager, managerID)) {	// if manager exists
		if (UserName != NULL)
			strcpy(manager.UserName, UserName);
		if (FullName != NULL)
			strcpy(manager.FullName, FullName);
		if (Password != NULL)
			strcpy(manager.Password, Password);

		// Start reding the file to find the manager and modify it
		infile = fopen(MANAGERS_FILENAME, "wb");
		if (infile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			while (fread(&iterator, sizeof(Manager), 1, infile)) {	// read trough file
				if (iterator.ManagerID == managerID)
					break;	// found the manager and read it
			}
			fseek(infile, -(int)sizeof(Manager), SEEK_CUR);	// jump back one manager
			fwrite(&manager, sizeof(Manager), 1, infile);	// write the changes
			fclose(infile);
			return managerID;
		}
	} else
		return 0;
}

int addPost(const unsigned int managerID, int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]) {
	FILE* infile;
	int postID = getLastIdPosts() + 1;
	Post post = { postID };
	// Append data to the created struct post
	post.Location = location;
	post.Type = type;
	post.Profession = profession;
	strcpy(post.Name, name);
	strcpy(post.Description, description);

	infile = fopen(POSTS_FILENAME, "ab");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fwrite(&post, sizeof(Post), 1, infile);
		fclose(infile);
		return postID;
	}
	return 0;
}

int registerApplication(const unsigned int PostID, const unsigned int UserID, char Description[MAX_DESCRIPTION]) {
	if (PostID != NULL && UserID != NULL) {
		FILE* infile;
		int applicationID = getLastIdApplications() + 1;
		Apply applied = { applicationID, PostID, UserID };	// if got managerID add manager otherwise ID = 1
		// Append data to the created struct manager
		strcpy(applied.Description, Description);

		infile = fopen(APPLIED_FILENAME, "ab");
		if (infile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			fwrite(&applied, sizeof(Apply), 1, infile);
			fclose(infile);
			return applicationID;
		}
	}
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
	return 0;
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
	return 0;
}

int getAllPosts(Post* postsArray[]) {
	FILE* infile;
	infile = fopen(POSTS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		int size = 0;
		while (fread(&postsArray[size], sizeof(Post), 1, infile)) {	// read trough file
			size++;
		}
		fclose(infile);
		return size;
	}
	return 0;
}

int checkPasswordUser(const unsigned int userID, char password[MAX_PASSWORD]) {
	User user;
	if (getUserData(&user, userID)) {
		if (!strcmp(user.Password, password))
			return 1;
	}
	return 0;
}

int checkPasswordManager(const unsigned int managerID, char password[MAX_PASSWORD]) {
	Manager manager;
	if (getManagerData(&manager, managerID)) {
		if (!strcmp(manager.Password, password))
			return 1;
	}
	return 0;
}

int initFiles() {
	FILE* usersFile, * managersFile, * postsFile, * appliedFile;
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
	appliedFile = fopen(APPLIED_FILENAME, "ab");
	if (appliedFile == NULL) {
		fprintf(stderr, "\nERROR OPENING APPLIED FILE\n");
		exit(1);
	} else
		fclose(appliedFile);
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
	return 0;
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
	return 0;
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

int getLastIdPosts() {
	FILE* infile;
	Post input;
	infile = fopen(POSTS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fseek(infile, 0, SEEK_END);	// go to end of file
		if (ftell(infile)) {	// check if not empty
			fseek(infile, -(int)sizeof(Post), SEEK_END);
			fread(&input, sizeof(Post), 1, infile);	// read last manager
			fclose(infile);
			return input.PostID;
		}
	}
	return 0;
}

int getLastIdApplications() {
	FILE* infile;
	Apply input;
	infile = fopen(APPLIED_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		fseek(infile, 0, SEEK_END);	// go to end of file
		if (ftell(infile)) {	// check if not empty
			fseek(infile, -(int)sizeof(Apply), SEEK_END);
			fread(&input, sizeof(Apply), 1, infile);	// read last manager
			fclose(infile);
			return input.AppliedId;
		}
	}
	return 0;
}

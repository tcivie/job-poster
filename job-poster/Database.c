#include "Database.h"

unsigned int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD], char Resume[MAX_DESCRIPTION]) {
	FILE* infile;
	unsigned int userID = getLastIdUsers() + 1;
	User user = { userID };	// if got userID add user otherwise ID = 1
	// Append data to the created struct user
	strcpy(user.UserName, UserName);
	strcpy(user.FullName, FullName);
	user.ID = ID;
	user.age = age;
	strcpy(user.PhoneNumber, PhoneNumber);
	strcpy(user.Password, Password);
	strcpy(user.Resume, Resume);

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

unsigned int updateUserData(const unsigned int userID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD], char Resume[MAX_DESCRIPTION]) {
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
		if (Resume != NULL)
			strcpy(user.Resume, Resume);

		// Start reding the file to find the user and modify it
		infile = fopen(USERS_FILENAME, "r+b");
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

unsigned int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]) {
	FILE* infile;
	unsigned int managerID = getLastIdManagers() + 1;
	Manager manager = { managerID };	// if got managerID add manager otherwise ID = 1
	// Append data to the created struct manager
	strcpy(manager.UserName, UserName);
	strcpy(manager.FullName, FullName);
	strcpy(manager.Password, Password);
	for (int i = 0; i < MAX_POSTS; i++)
	{
		manager.Posts[i] = 0;
	}
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

unsigned int updateManagerData(const unsigned int managerID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]) {
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
		infile = fopen(MANAGERS_FILENAME, "r+b");
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

unsigned int addPost(const unsigned int managerID, int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]) {
	FILE* infile, *managerfile;
	unsigned int postID = getLastIdPosts() + 1;
	Post post = { postID };
	Manager bufferManager;
	int i;
	// Append data to the created struct post
	post.Location = location;
	post.Type = type;
	post.Profession = profession;
	strcpy(post.Name, name);
	strcpy(post.Description, description);
	post.Promoted = 0;

	managerfile = fopen(MANAGERS_FILENAME, "r+b");
	if (managerfile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	else {	// Opened managers file
		while (fread(&bufferManager, sizeof(Manager), 1, managerfile)) {	// read trough file
			if (bufferManager.ManagerID == managerID) {	// check if equal
				i = 0;
				while (bufferManager.Posts[i]) i++;	// run till end of posts
				bufferManager.Posts[i] = postID;
				fseek(managerfile, -(int)sizeof(Manager), SEEK_CUR);	// jump back one manager
				fwrite(&bufferManager, sizeof(Manager), 1, managerfile);	// write the changes
				fclose(managerfile);
				
				infile = fopen(POSTS_FILENAME, "ab");
				if (infile == NULL) {
					fprintf(stderr, "\nERROR OPENING FILE\n");
					exit(1);
				} else {
					fwrite(&post, sizeof(Post), 1, infile);
					fclose(infile);
					return postID;
				}
			}
		}
		fclose(managerfile);
	}
	return 0;
}

unsigned int updatePost(const unsigned int postID, int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION], int Promoted) {
	Post post, iterator;
	FILE* infile;
	if (getPostData(&post, postID)) {	// if post exists
		if (location != 0)
			post.Location = location;
		if (type != 0)
			post.Type = type;
		if (profession != 0)
			post.Profession = profession;
		if (name != NULL)
			strcpy(post.Name, name);
		if (description != NULL)
			strcpy(post.Description, description);
		if (Promoted == 1)
			post.Promoted = Promoted;

		// Start reding the file to find the post and modify it
		infile = fopen(POSTS_FILENAME, "r+b");
		if (infile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			while (fread(&iterator, sizeof(Post), 1, infile)) {	// read trough file
				if (iterator.PostID == postID)
					break;	// found the post and read it
			}
			fseek(infile, -(int)sizeof(Post), SEEK_CUR);	// jump back one post
			fwrite(&post, sizeof(Post), 1, infile);	// write the changes
			fclose(infile);
			return postID;
		}
	} else
		return 0;
}

unsigned int registerApplication(const unsigned int PostID, const unsigned int UserID, char Description[MAX_DESCRIPTION]) {
	if (PostID != 0 && UserID != 0) {
		FILE* infile;
		unsigned int applicationID = getLastIdApplications() + 1;
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

unsigned int ApplyJob(const unsigned int UserID, const unsigned int PostID) {
	int applicationID;
	FILE* infile;
	User user;
	if (applicationID = checkUserApplication(PostID, UserID)) {	// Checks if the user already applied
		return applicationID;
	}
	if (checkPostID(PostID)) {
		infile = fopen(APPLIED_FILENAME, "ab");
		if (infile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			if (getUserData(&user, UserID)) {
				applicationID = getLastIdApplications() + 1;
				Apply application = {applicationID,PostID,UserID};
				strcpy(application.Description, user.Resume);	// copy the application
				fwrite(&application, sizeof(Apply), 1, infile);
				fclose(infile);
				return applicationID;
			}
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
	infile = fopen(MANAGERS_FILENAME, "rb");
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

int getPostData(Post* retValue, const unsigned int postID) {
	FILE* infile;
	infile = fopen(POSTS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(retValue, sizeof(Post), 1, infile)) {	// read trough file
			if (retValue->PostID == postID) {	// check if equal
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

int getAppliedByUser(Apply* retValue[], const unsigned int userID) {
	FILE* infile;
	Apply buffer;
	infile = fopen(APPLIED_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		int size = 0;
		while (fread(&buffer, sizeof(Apply), 1, infile)) {	// read trough file
			if (buffer.UserID == userID) {
				retValue[size++] = &buffer;	// copy value
			}
		}
		fclose(infile);
		return size;
	}
	return 0;
}

int getAppliedByPost(User retValue[MAX_MANAGERS], const unsigned int postID) {
	FILE* infile;
	Apply buffer;
	infile = fopen(APPLIED_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	else {
		int size = 0;
		while (fread(&buffer, sizeof(Apply), 1, infile)) {	// read trough file
			if (buffer.PostID == postID) {
				if (!getUserData(&retValue[size++], buffer.UserID))	// get the user
					return 0;	// ERROR
			}
		}
		fclose(infile);
		return size;
	}
	return 0;
}


int getAllPosts(Post postsArray[MAX_POSTS]) {
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

int getPostsByManagerID(Post* postsArray,const unsigned int ManagerID) {
	Manager manager;
	Post post;
	int i = 0;
	if (getManagerData(&manager, ManagerID)) {	// get manager data
		while (manager.Posts[i]!=0) 
		{	// run on all posts
			if (getPostData(&post,manager.Posts[i])) {	// get post by ID
				postsArray[i].PostID = post.PostID;
				strcpy(postsArray[i].Description, post.Description);
				strcpy(postsArray[i].Name, post.Name);
				postsArray[i].Location = post.Location;
				postsArray[i].Type = post.Type;
				postsArray[i].Profession = post.Type;
				postsArray[i].Promoted = post.Promoted;
			}
			i++;
		}
		return i;
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

unsigned int deletePost(const unsigned int postID, const unsigned int managerID) {
	FILE* infile, *outfile, *managerFile;
	Post toCopy;
	Manager manager,tempManager;
	infile = fopen(POSTS_FILENAME, "rb");
	outfile = fopen(TEMP_FILENAME, "wb");
	if (infile == NULL || outfile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	}
	else {
		while (fread(&toCopy, sizeof(Post), 1, infile)) {	// read trough file
			if (toCopy.PostID != postID)	// if found the post
				fwrite(&toCopy, sizeof(Post), 1, outfile);	// write to temp
		}
		fclose(infile);
		infile = NULL;
		fclose(outfile);
		outfile = NULL;
		infile = fopen(TEMP_FILENAME, "rb");
		outfile = fopen(POSTS_FILENAME, "wb");
		if (infile == NULL || outfile == NULL) {
			fprintf(stderr, "\nERROR OPENING FILE\n");
			exit(1);
		} else {
			while (fread(&toCopy, sizeof(Post), 1, infile)) {	// read trough file
				fwrite(&toCopy, sizeof(Post), 1, outfile);	// write to temp
			}
		}
		fclose(outfile);
		fclose(infile);

		//if (rename(TEMP_FILENAME, POSTS_FILENAME))
			//return 0;

		if (getManagerData(&manager, managerID)) {
			managerFile = fopen(MANAGERS_FILENAME, "r+b");
			if (managerFile == NULL) {
				fprintf(stderr, "\nERROR OPENING FILE\n");
				exit(1);
			} else {
				while (fread(&tempManager,sizeof(Manager),1,managerFile)) {
					if (tempManager.ManagerID == managerID) {
						int i = 0;
						while (manager.Posts[i] != postID) {	// FIRST SECTION
							tempManager.Posts[i] = manager.Posts[i];
							i++;
						}
						i++;
						while (i<MAX_POSTS) {	// SECOND SECTION
							tempManager.Posts[i - 1] = manager.Posts[i];
							i++;
						}
						tempManager.Posts[MAX_POSTS - 1] = 0;	// CLEAR LAST ONE
						fseek(infile, -(int)sizeof(Manager), SEEK_END);
						fwrite(&tempManager, sizeof(Manager), 1, managerFile);
						fclose(managerFile);
						return postID;
					}
				}
				fclose(managerFile);
				return postID;
			}
		}
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

unsigned int checkPostID(const unsigned int PostID) {
	FILE* infile;
	Post input;
	infile = fopen(POSTS_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(&input, sizeof(Post), 1, infile)) {	// read trough file
			if (input.PostID == PostID) {	// check if equal
				fclose(infile);
				return input.PostID;	// return post ID
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

int checkUserApplication(const unsigned int PostID, const unsigned int userID) {
	FILE* infile;
	Apply input;
	infile = fopen(APPLIED_FILENAME, "rb");
	if (infile == NULL) {
		fprintf(stderr, "\nERROR OPENING FILE\n");
		exit(1);
	} else {
		while (fread(&input, sizeof(Apply), 1, infile)) {	// read trough file
			if (input.PostID == PostID) {	// check if its the post
				if (input.UserID == userID) {
					fclose(infile);
					return input.AppliedID;	// return Application ID
				}
			}	// found application but not the user
		}
		fclose(infile);
		return 0;
	}
	return 0;
}

unsigned int getLastIdUsers() {
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

unsigned int getLastIdManagers() {
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

unsigned int getLastIdPosts() {
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

unsigned int getLastIdApplications() {
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
			return input.AppliedID;
		}
	}
	return 0;
}

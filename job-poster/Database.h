#ifndef DATABASE
#define DATABASE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_POSTS 50
#define MAX_DESCRIPTION 255

#define MANAGERS_FILENAME "Managers.bin"
#define USERS_FILENAME "Users.bin"
#define POSTS_FILENAME "Posts.bin"

typedef struct Users {
	const unsigned int UserID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	long ID;
	int age;
	char PhoneNumber[MAX_SIZE];
} User;

typedef struct Managers {
	const unsigned int ManagerID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	int Posts[MAX_POSTS];
} Manager;

typedef struct Posts {
	const unsigned int PostID;
	int location;
	int Type;
	int Profession;
	char Name[MAX_SIZE];
	char Description[MAX_DESCRIPTION];
	int Promoted;
} Post;

/// <summary>
/// Creates the nessecary files if are missing
///  - you can run it multiple times, nothing will break
/// </summary>
/// <returns>1 - On success | exit on failure</returns>
int initFiles();

/// <summary>
/// Checks if the username exists in the database
/// </summary>
/// <param name="UserName">User's username</param>
/// <returns>0 - If not found | UserID - if found</returns>
int checkUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Checks if the username of the manager exists in the database
/// </summary>
/// <param name="UserName">Manager's username</param>
/// <returns>0 - If not found | ManagerID - if found</returns>
int checkManagerUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Finds the last User ID
/// </summary>
/// <returns>UserID - of the user | 0 - If not found</returns>
int getLastIdUsers();

/// <summary>
/// Finds the last Manager ID
/// </summary>
/// <returns>ManagerID - of the user | 0 - If not found</returns>
int getLastIdManagers();

/// <summary>
/// Register a new user
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Full name</param>
/// <param name="ID">User ID (Teudat Zeut)</param>
/// <param name="age">User Age</param>
/// <param name="PhoneNumber">User phone number</param>
/// <returns>UserID - if registration successful | 0 - Otherwise</returns>
int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE]);

/// <summary>
/// Register a new manager
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Business name/ User Full name</param>
/// <returns>ManagerID - if registration successful | 0 - Otherwise</returns>
int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE]);

/// <summary>
/// Add new post
/// </summary>
/// <param name="location"></param>
/// <param name="type"></param>
/// <param name="profession"></param>
/// <param name="name"></param>
/// <param name="description"></param>
/// <returns>PostID - if posting successful | 0 - Otherwise</returns>
int addPost(int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]);

/// <summary>
/// Searches for the user with the given ID and returns the User
/// </summary>
/// <param name="retValue">Pointer to the found user</param>
/// <param name="userID">The user ID to look for</param>
/// <returns>1 - If found | 0 - If not</returns>
int getUserData(User* retValue,const unsigned int userID);

/// <summary>
/// Searches for the manager with the given ID and returnes the Manager
/// </summary>
/// <param name="retValue">Pointer to the found manager</param>
/// <param name="managerID">The manager ID to look for</param>
/// <returns>1 - If found | 0 - If not</returns>
int getManagerData(Manager* retValue, const unsigned int managerID);

#endif // !DATABASE

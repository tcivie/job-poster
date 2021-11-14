#ifndef DATABASE
#define DATABASE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_POSTS 50
#define MAX_DESCRIPTION 255

#define MANAGERS_FILENAME "Managers.dat"
#define USERS_FILENAME "Users.dat"

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
	int Proffesion;
	char Name[MAX_SIZE];
	char Description[MAX_DESCRIPTION];
} Post;

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

#endif // !DATABASE

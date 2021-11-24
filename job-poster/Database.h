#ifndef DATABASE
#define DATABASE

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_SIZE 100
#define MAX_POSTS 30
#define MAX_MANAGERS 30
#define MAX_DESCRIPTION 255
#define MAX_PASSWORD 20

#define MANAGERS_FILENAME "Managers.bin"
#define USERS_FILENAME "Users.bin"
#define POSTS_FILENAME "Posts.bin"
#define APPLIED_FILENAME "Applied.bin"
#define TEMP_FILENAME "Temp.bin"

typedef struct Users {
	const unsigned int UserID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	long ID;
	int age;
	char PhoneNumber[MAX_SIZE];
	char Password[MAX_PASSWORD];
	char Resume[MAX_DESCRIPTION];
} User;


typedef struct Managers {
	const unsigned int ManagerID;
	char UserName[MAX_SIZE];
	char FullName[MAX_SIZE];
	int Posts[MAX_POSTS];
	char Password[MAX_PASSWORD];
} Manager;

typedef struct Posts {
	unsigned int PostID;
	int Location;
	int Type;
	int Profession;
	char Name[MAX_SIZE];
	char Description[MAX_DESCRIPTION];
	int Promoted;
} Post;

typedef struct Applied {
	const unsigned int AppliedID;
	const unsigned int PostID;
	const unsigned int UserID;
	char Description[MAX_DESCRIPTION]; // Resume
} Apply;

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
unsigned int checkUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Checks if post exists in the database
/// </summary>
/// <param name="PostID">ID of the post</param>
/// <returns>Post ID if exists | 0 - Otherwise</returns>
unsigned int checkPostID(const unsigned int PostID);

/// <summary>
/// Checks if the username of the manager exists in the database
/// </summary>
/// <param name="UserName">Manager's username</param>
/// <returns>0 - If not found | ManagerID - if found</returns>
unsigned int checkManagerUserName(char UserName[MAX_SIZE]);

/// <summary>
/// Checks if the user has aleardy appied for the application
/// </summary>
/// <param name="PostID">ID of the post the user wants to apply to</param>
/// <param name="UserID">ID of the user</param>
/// <returns>ApplicationID - if found | 0 - Otherwise</returns>
unsigned int checkUserApplication(const unsigned int PostID, const unsigned int userID);

/// <summary>
/// Finds the last User ID
/// </summary>
/// <returns>UserID - of the user | 0 - If not found</returns>
unsigned int getLastIdUsers();

/// <summary>
/// Finds the last Manager ID
/// </summary>
/// <returns>ManagerID - of the user | 0 - If not found</returns>
unsigned int getLastIdManagers();

/// <summary>
/// Finds the last Post ID
/// </summary>
/// <returns>PostID - of the post | 0 - If not found</returns>
unsigned int getLastIdPosts();

/// <summary>
/// Finds the last Applied ID
/// </summary>
/// <returns>AppliedID - of the post | 0 - If not found</returns>
unsigned int getLastIdApplications();

/// <summary>
/// Register a new user
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Full name</param>
/// <param name="ID">User ID (Teudat Zeut)</param>
/// <param name="age">User Age</param>
/// <param name="PhoneNumber">User phone number</param>
/// <param name="Resume">Path to user resume</param>
/// <returns>UserID - if registration successful | 0 - Otherwise</returns>
unsigned int registerUser(char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD], char Resume[MAX_DESCRIPTION]);

/// <summary>
/// Update user data
/// </summary>
/// <param name="userID">Id of the updated user (Must)</param>
/// <param name="UserName">Optional (pass NULL if not updated)</param>
/// <param name="FullName">Optional (pass NULL if not updated)</param>
/// <param name="ID">Teudat Zeut (ID) Optional (pass 0 if not updated)</param>
/// <param name="age">Optional (pass 0 if not updated)</param>
/// <param name="PhoneNumber">Optional (pass NULL if not updated)</param>
/// <param name="Password">Optional (pass NULL if not updated)</param>
/// <param name="Resume">Optional (pass NULL if not updated)</param>
/// <returns>UserID on success | 0 - Otherwise</returns>
unsigned int updateUserData(const unsigned int userID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], long ID, int age, char PhoneNumber[MAX_SIZE], char Password[MAX_PASSWORD], char Resume[MAX_DESCRIPTION]);

/// <summary>
/// Register a new manager
/// </summary>
/// <param name="UserName">Username</param>
/// <param name="FullName">Business name/ User Full name</param>
/// <returns>ManagerID - if registration successful | 0 - Otherwise</returns>
unsigned int registerManager(char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Update manager data
/// </summary>
/// <param name="managerID">Optional (pass NULL if not updated)</param>
/// <param name="UserName">Optional (pass NULL if not updated)</param>
/// <param name="FullName">Optional (pass NULL if not updated)</param>
/// <param name="Password">Optional (pass NULL if not updated)</param>
/// <returns>ManagerID - if succeeded | 0 - Otherwise</returns>
unsigned int updateManagerData(const unsigned int managerID, char UserName[MAX_SIZE], char FullName[MAX_SIZE], char Password[MAX_PASSWORD]);

/// <summary>
/// Update post data
/// </summary>
/// <param name="postID">ID of the updated post</param>
/// <param name="location">Optional (pass 0 if not updated)</param>
/// <param name="type">Optional (pass 0 if not updated)</param>
/// <param name="profession">Optional (pass 0 if not updated)</param>
/// <param name="name">Optional (pass NULL if not updated)</param>
/// <param name="description">Optional (pass NULL if not updated)</param>
/// <param name="Promoted">Optional (pass 0 if not updated)</param>
/// <returns>PostID if succeeded | 0 - Otherwise</returns>
unsigned int updatePost(const unsigned int postID, int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION], int Promoted);

/// <summary>
/// Register application for user to a post
/// </summary>
/// <param name="PostID">ID of the post the user wants to apply to</param>
/// <param name="UserID">ID of the user</param>
/// <param name="Description">The application contents</param>
/// <returns>ApplicationID if succeeded | 0 otherwise</returns>
unsigned int registerApplication(const unsigned int PostID, const unsigned int UserID, char Description[MAX_DESCRIPTION]);

/// <summary>
/// Apply for a job - save in file apply the application
/// </summary>
/// <param name="UserID">ID of the user to appy</param>
/// <param name="PostID">ID of the post</param>
/// <returns>ApplicationID - If succeeded | 0 - Otherwise</returns>
unsigned int ApplyJob(const unsigned int UserID, const unsigned int PostID);

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

/// <summary>
/// Searches for a post with a given ID and returns it
/// </summary>
/// <param name="retValue">Pointer to the found post</param>
/// <param name="postID">The post ID to look for</param>
/// <returns>1 - If found | 0 - If not</returns>
int getPostData(Post* retValue, const unsigned int postID);

/// <summary>
/// Gets all the applications for the given user
/// </summary>
/// <param name="retValue">Pointer to array of applications</param>
/// <param name="userID">Id of the user</param>
/// <returns>Number of applications - If succeeded | 0 - If failed</returns>
int getAppliedByUser(Apply* retValue[], const unsigned int userID);

/// <summary>
/// Gets all the user profiles who applied for the job
/// </summary>
/// <param name="retValue">Pointer to array of users</param>
/// <param name="postID">Id of the post</param>
/// <returns>Number of applications - If succeeded | 0 - If failed</returns>
int getAppliedByPost(User retValue[MAX_MANAGERS], const unsigned int postID);

/// <summary>
/// Adds new post
/// </summary>
/// <param name="managerID">ID of the manager to add the post to</param>
/// <param name="location">value from 1 to 3 {North, Center, South}</param>
/// <param name="type">value 1 or 2 {Full time, Part time}</param>
/// <param name="profession">value from 1 to 8 {Security, Engineering, Medicine, Restaurants, Education, Public transportation, Factories, Economics}</param>
/// <param name="name">Job tittle</param>
/// <param name="description">Description of the job tittle</param>
/// <returns>1 - If post was added | 0 - If not"</returns>
int addPost(const unsigned int managerID ,int location, int type, int profession, char name[MAX_SIZE], char description[MAX_DESCRIPTION]);

/// <summary>
/// Get all posts from the database and save in the given pointer
/// </summary>
/// <param name="postsArray">The pointer to the posts array</param>
/// <returns>Number of posts in the array.</returns>
int getAllPosts(Post postsArray[MAX_POSTS]);

/// <summary>
/// Returns all the posts by the manager ID
/// </summary>
/// <param name="postsArray">Pointer to empty posts array</param>
/// <param name="ManagerID">Manager ID</param>
/// <returns>number of posts - If suceeded | 0 - otherwise</returns>
int getPostsByManagerID(Post* postsArray,const unsigned int ManagerID);

/// <summary>
/// Checks if the userID password matches the one in the database
/// </summary>
/// <param name="userID">User ID</param>
/// <returns>1 - If matches | 0 - Otherwise</returns>
int checkPasswordUser(const unsigned int userID, char password[MAX_PASSWORD]);

/// <summary>
/// Checks if the manaagerID password matches the one in the database
/// </summary>
/// <param name="userID">Manager ID</param>
/// <returns>1 - If matches | 0 - Otherwise</returns>
int checkPasswordManager(const unsigned int managerID, char password[MAX_PASSWORD]);

/// <summary>
/// Delete Post
/// </summary>
/// <param name="postID">ID of the post</param>
/// <param name="managerID">ID of the manager</param>
/// <returns>ID of the deleted post | NULL - Otherwise</returns>
unsigned int deletePost(const unsigned int postID, const unsigned int managerID);

#endif // !DATABASE

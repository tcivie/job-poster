#ifndef MANAGER
#define MANAGER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Colors.h"

/// <summary>
/// Helper function to print a specific job post
/// </summary>
/// <param name="post"></param>
void view_post(Post post);

/// <summary>
/// Requiremrnt 2.5 - Function of printing all the job posts
/// </summary>
/// <param name="manager">logged in manager</param>
void view_posts(Manager manager);

/// <summary>
/// Requiremrnt 2.2 - Function of adding a new job post
/// </summary>
/// <returns></returns>
int add_new_post(unsigned int managerID);

/// <summary>
/// Requirement 2.3 - Delete an existing ad from the board 
/// </summary>
/// <returns></returns>
int delete_post(int managerID);

/// <summary>
/// Requirement 2.4 - Update an existing ad on the board
/// </summary>
/// <param name="managerID">
/// <returns></returns>
int update_post(int managerID);

/// <summary>
/// Requirement 2.6 - View profiles of candidates who have submitted resumes for the appropriate position.
/// </summary>
/// <param name="manager">logged in manager</param>
/// <returns></returns>
void view_candidates_profiles(unsigned int managerID);
int view_profiles(unsigned int managerID);

#endif
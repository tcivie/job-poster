#ifndef MANAGER
#define MANAGER

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/// <summary>
/// Helper function to print a specific job post
/// </summary>
/// <param name="post"></param>
void view_post(Post post);

/// <summary>
/// Requiremrnt 2.4 - Function of printing all the job posts
/// </summary>
/// <param name="manager">logged in manager</param>
/// <param name="post"></param>
void view_posts(Manager manager, Post post);

/// <summary>
/// Requiremrnt 2.2 - Function of adding a new job post
/// </summary>
/// <returns></returns>
Post* add_new_post();






#endif


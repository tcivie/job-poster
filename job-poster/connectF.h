#pragma once
#ifndef Connect
#define Connect


///	<summary>
/// user will be able to edit his data by options - menu and input functions
/// </summary>
/// <param name="userID">gets user id ,goes to the files and change the data</param>
/// <returns>0 at the end</returns>
int editUserProfile(const unsigned int userID);
/// <summary>
/// manager will be able to edit his data by options
/// </summary>
/// <param name="userID">gets user id ,goes to the files and change the data</param>
/// <returns>0 at the end</returns>
int editManagerData(const unsigned int userID);
/// <summary>
/// funciton that gets input of the CV
/// </summary>
/// <param name="CV">char* to save the data entered by the user</param>
/// <returns>0 at the end</returns>
int enterCV(char* CV);
/// <summary>
/// opens menu, and prints according to the choises of the user
/// </summary>
/// <returns>0 at the end</returns>
int printPostsByCategory();
/// <summary>
/// function to promote an ad with payment inputs
/// </summary>
/// <param name="managerID"></param>
/// <returns>0 if succeded </returns>
int promotionAD(const unsigned int managerID);


#endif

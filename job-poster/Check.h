#ifndef CHECK
#define CHECK

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ZERO 48
#define NINE 57
#define L_A 65
#define L_Z 90
#define L_a 97
#define L_z 122

/// <summary>
/// function gets id and checks it according to luhns algorithm
/// </summary>
/// <param name="ID">the id to check</param>
/// <returns>0 if true</returns>
int IDcheck(long ID);
/// <summary>
/// gets a name and checks if all the chars are letters
/// </summary>
/// <param name="Fname">the char* to check</param>
/// <returns>0 if true</returns>
int FullNameCheck(char* Fname);
/// <summary>-
/// gets age and checks if its between 18-99
/// </summary>
/// <param name="age">age to check</param>
/// <returns>0 if true</returns>
int AgeCheck(int age);
/// <summary>
/// gets password and checks if there is 1cap letter, 1small letter and a number and length above 6
/// </summary>
/// <param name="pass">the password to check</param>
/// <returns>0 if good, 1 if string null, 2 if the size is not enough m 3 no small/big letter or no number</returns>
int PasswordCheck(char* pass);
/// <summary>
/// if between 1-365
/// </summary>
/// <param name="days">number of days to check</param>
/// <returns>0 if true</returns>
int numberOfDaysPayment(int days);
/// <summary>
/// checks credit card number
/// </summary>
/// <param name="credit">credit card number to check</param>
/// <returns>0 if good, 1 else </returns>
int creditNumberCheck(char* credit);
/// <summary>
/// checks validity of credit card (mm/yy)
/// </summary>
/// <param name="date"> date to check </param>
/// <returns>0 good,1-wrong month, 2 no slash in middle,3 wrong year,4 card is not valid,5-wrong length </returns>
int creditValidityCheck(char* date);
/// <summary>
/// checks last 3 digits of credit card
/// </summary>
/// <param name="number">3dig</param>
/// <returns>0 good</returns>
int last3DigitsCheck(char* number);
/// <summary>
/// checks if length is 10 and starts with 05
/// </summary>
/// <param name="number">phone number to check</param>
/// <returns>0 good, 1 length is not good,2 not start with 05..</returns>
int phoneNumberCheck(char* number);

#endif // !CHECK

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

int IDcheck(long ID);
int FullNameCheck(char* Fname);
int AgeCheck(int age);
int PasswordCheck(char* pass);
int numberOfDaysPayment(int days);
int creditNumberCheck(char* credit);
int creditValidityCheck(char* date); //mm / yy
int last3DigitsCheck(char* number);
int phoneNumberCheck(char* number);

#endif // !CHECK

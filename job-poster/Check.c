#include "Check.h"



//int main()
//{
//	printf("%d", last3DigitsCheck("00!"));
//}



int IDcheck(long ID)
{
	long temp = ID;
	int digits = 0, sum = 0, counter = 0, num, total = 0, tempsum;
	while (temp != 0)
	{
		digits++;
		temp /= 10;
	}
	if (digits < 8 || digits > 9)
	{
		printf("Ivalid ID number\n");
		return 0;
	}
	temp = ID % 10;
	ID /= 10;
	digits--;
	while (ID != 0)
	{
		if (counter % 2 == 0)
		{
			if (ID % 10 > 4)
			{
				num = (ID % 10) * 2;
				while (num != 0)
				{
					total = total + num % 10;
					num /= 10;
				}
				sum = sum + total;
				total = 0;
			}
			else
				sum = sum + (ID % 10 * 2);
		}
		else
			sum = sum + (ID % 10);
		ID /= 10;
		counter++;
	}
	if (sum % 10 == 0)
	{
		if (temp == 0)
			return 1;
	}
	else
	{
		tempsum = sum;
		sum /= 10;
		sum = (sum + 1) * 10;
		tempsum = sum - tempsum;
		if (tempsum == temp)
			return 1;
		else return 0;
	}
}


int FullNameCheck(char* Fname)
{
	int size = strlen(Fname);
	if (size == 0||Fname==NULL)
		return 1;//too short - not good
	for (int i = 0; i <size; i++)
	{
		if (!((Fname[i] >= L_A && Fname[i] <= L_Z)|| (Fname[i] >= L_a && Fname[i] <= L_z)|| (Fname[i] == 32)))
		{
			return 1;//if its not English letter ( FALSE )
		}
	}
	return 0;
}

int AgeCheck(int age)
{
	if (age >= 18 && age <= 99)
		return 0;
	return 1;
}

int PasswordCheck(char* pass)
{
	int size=0, bigLflag=0, smallLflag=0, numberflag=0;
	if (pass == NULL)
		return 1;//string is NULL
	size = strlen(pass);
	if (size <= 5)
		return 2;//Size is not enough
	for (int i = 0; i < size; i++)
	{
		if (pass[i] >= L_A && pass[i] <= L_Z)
			bigLflag = 1;
		if (pass[i] >= L_a && pass[i] <= L_z)
			smallLflag = 1;
		if (pass[i] >= ZERO && pass[i] <= NINE)
			numberflag = 1;
	}
	if (numberflag == 0 || bigLflag == 0 || smallLflag == 0)
		return 3;//no small/big letter or no number
	return 0;
}

int numberOfDaysPayment(int days)
{
	if (days >= 1 && days <= 365)
		return 0;
	return 1;
}

int creditNumberCheck(char* credit)
{
	if (credit == NULL)
		return 1;
	int size = strlen(credit);
	if (size != 16)
		return 1;
	for (int i = 0; i < 16; i++)
	{
		if (!(credit[i] >= ZERO && credit[i] <= NINE))
			return 1;
	}
	return 0;
}
int creditValidityCheck(char* date)// mm/yy   --- check until 11/21
{
	int month = 0,year=0;
	if (strlen(date) != 5)
		return 5;//wrong input
	if (date[0] == ZERO)// 0
	{
		if (date[1] >= 49 && date[1] <= NINE)
			month = date[1] - ZERO;
	}
	if (date[0] == 49)//1
	{
		if (date[1] == ZERO)
			month = 10;
		if (date[1] == (ZERO +1))
			month = 11;
		if (date[1] == (ZERO+2))
			month = 12;
	}
	if (month == 0)
		return 1;//wrong month
	if (date[2] != '/')
		return 2;//no slash in the middle (/)
	if (date[3] >= ZERO && date[3] <= NINE && date[4] >= ZERO && date[4] <= NINE)//if the year is numbers
	{
		year = (date[3] - ZERO) * 10 + date[4]-ZERO;
	}
	else
		return 3;//wrong year
	if ((year <= 21 && month <= 11)||year<21)
		return 4;//card is not valid
	return 0;
}

int last3DigitsCheck(char* number)//length = 3 and only digits
{
	if (strlen(number) != 3)
		return 1;//string in wrong size- wrong input
	for (int i = 0; i < 3; i++)
	{
		if (number[i] < ZERO || number[i] > NINE)
			return 2;//wrong input
	}
	return 0;
}

int phoneNumberCheck(char* number)
{
	if (strlen(number) != 10)
		return 1;//length is not good
	if (number[0] != '0' || number[1] != '5')
		return 2;//personal phone number starts with 05...
	return 0;
}
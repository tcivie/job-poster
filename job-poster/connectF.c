#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Manager.h"
#define POSTSNUM 200

int printPostsByCategory();
int printByCategories(Post* postsArray, int size, int category, int innerCategory);

int printPostsByCategory()
{
	int choose = -1;
	int innerChoose = 0;
	int sizeArray = 0;
	Post* postsArray[POSTSNUM];
	sizeArray = getAllPosts(postsArray);
	while (choose != 0)
	{
		printf("Choose search by category:\n1-->Location\n2-->Type (Full time job/Half time job)\n3-->Profession\n0-->Back");
		scanf_s("%d", &choose);
		while (choose > 3 || choose < 0)
		{
			printf("Wrong choose, try again");
			scanf_s("%d", &choose);
		}
		switch (choose)
		{
		case 1:
			printf("Choose location:\n1-->North\n2-->Center\n3-->South\n0-->Back");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 2:
			printf("Choose Type:\n1-->Full time job\n2-->Half time job\n0-->Back");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 3:
			printf("Choose proffetion:\n1-->Security\n2-->Engineering\n3-->Medicine\n4-->Restaurants\n5-->Education\n6-->Public transportation\n7-->Factories\n8-->Economics\n0-->Back");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		default:
			break;
		}
	}
	
}

int printByCategories(Post* postsArray, int size, int category, int innerCategory)
{
	for (int i = 0; i < size; i++)
	{
		switch (category)
		{
		case 1:
		{
			if (postsArray[i].Location == innerCategory)
			{
				view_post(postsArray[i]);
			}
		}
		break;
		case 2:
			if (postsArray[i].Type == innerCategory)
			{
				view_post(postsArray[i]);
			}
			break;
		case 3:
			if (postsArray[i].Profession == innerCategory)
			{
				view_post(postsArray[i]);
			}
			break;
		default:
			break;
		}
	}
}

	
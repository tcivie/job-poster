#define _CRT_SECURE_NO_WARNINGS
#include "Database.h"
#include "Manager.h"

int printPostsByCategory();
int printByCategories(Post* postsArray, int size, int category, int innerCategory);

int printPostsByCategory()
{
	int choose = -1;
	int innerChoose = 0;
	int sizeArray = 0;
	Post* postsArray = (Post*) malloc(MAX_POSTS * MAX_MANAGERS * sizeof(Post));
	sizeArray = getAllPosts(&postsArray);
	while (choose != 0)
	{
		printf("Choose search by category:\n1-->Location\n2-->Type (Full time job/Half time job)\n3-->Profession\n0-->Back\n");
		scanf_s("%d", &choose);
		while (choose > 3 || choose < 0)
		{
			printf("Wrong choose,please try again\n");
			scanf_s("%d", &choose);
		}
		switch (choose)
		{
		case 1:
			printf("Choose location:\n1-->North\n2-->Center\n3-->South\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 2:
			printf("Choose Type:\n1-->Full time job\n2-->Half time job\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		case 3:
			printf("Choose proffetion:\n1-->Security\n2-->Engineering\n3-->Medicine\n4-->Restaurants\n5-->Education\n6-->Public transportation\n7-->Factories\n8-->Economics\n0-->Back\n");
			scanf_s("%d", &innerChoose);
			printByCategories(postsArray, sizeArray, choose, innerChoose);
			break;
		default:
			break;
		}
	}
	free(postsArray);
	return 0;
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
	return 0;
}

int enterCV(char* CV)//gets char* to enter the data that the user entered
{
	int choose = -1;
	do {
		printf("1-->Enter CV\n 0-->Back\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 0:
			return 0;
		case 1:
			scanf("%s", CV);

		default:
			printf("Wrong number, please try again\n");
			break;
		}
	} while (choose != 0);

}

	
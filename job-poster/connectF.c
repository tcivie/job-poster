#include "Database.h"
#define POSTSNUM 200
int printPostsByCategory()
{
	int choose = -1;
	int innerChoose = 0;
	Post* postsArray = (Post*)malloc(sizeof(Post) * 200);
	if (postsArray == NULL)
		exit(1);
	while (choose != 0)
	{
		printf("Choose search by category:\n1-->Location\n2-->Type (Full time job/Half time job)\n3-->Profession\n0-->Back");
		scanf("%d", &choose);
		while (choose > 3 || choose < 0)
		{
			printf("Wrong choose, try again");
			scanf("%d", &choose);
		}
		switch (choose)
		{
		case 1:
			innerChoose = 0;
			printf("Choose location:\n1-->North\n2-->Center\n3-->South\n0-->Back");
			switch (innerChoose)
			{
			case 1:
				//print north posts
				break;
			case 2:
				//print center posts
				break;
			case 3:
				//print south posts
				break;
			default:
				break;
			}
			break;
		case 2:
			innerChoose = 0;
			printf("Choose Type:\n1-->Full time job\n2-->Half time job\n0-->Back");
			switch (innerChoose)
			{
			case 1:
				//print full time posts
				break;
			case 2:
				//print half time posts
				break;
			default:
				break;
			}
			break;
		case 3:
			innerChoose = 0;
			printf("Choose proffetion:\n1-->Security\n2-->Engineering\n3-->Medicine\n4-->Restaurants\n5-->Education\n6-->Public transportation\n7-->Factories\n8-->Economics\n0-->Back");
			switch (innerChoose)
			{
			case 1:
				//print north posts
				break;
			case 2:
				//print center posts
				break;
			case 3:
				//print south posts
				break;
			case 4:
				//print south posts
				break;
			case 5:
				//print south posts
				break;
			case 6:
				//print south posts
				break;
			case 7:
				//print south posts
				break;
			case 8:
				//print south posts
				break;
			default:
				break;
			}
			break;
		}
	}
	
}

int printByCategories(Post* postsArray, int size, int category, int innerCategory)
{
	switch (category)
	{
	case 1:
		for (int i = 0; i < size; i++)
		{
			if()
		}
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

	
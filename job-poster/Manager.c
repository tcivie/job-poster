#include "Database.h"
#include "Manager.h"

Post* add_new_post()
{
	Post new_post;
	new_post.location = new_post.Type = 0;
	do
	{
		printf("Select location from list:\n1. North\n2. Center\n 3.South\n");
		scanf("%d", &new_post.location);
	} while (new_post.location < 1 || new_post.location > 3);
	do
	{
		printf("Select type of job from list:\n1. Full-time\n2. Part-time\n");
		scanf("%d", &new_post.location);
	} while (new_post.Type < 1 || new_post.Type > 2);
	do
	{
		printf("Select relevant profession from list:\n1. Security\n2. Engineering\n3. Medicine\n4. Restaurants\n5. Education\n6. Public transportation\n7. Factories\n8. Economics\n0. Not relevant\n");
	} while (new_post.Profession < 0 || new_post.Profession > 8);
}

void view_post(Post post) // Helper
{
	printf("Name: %s\n", post.Name);	// הדפסת שם המודעה

	printf("Location: ");	// הדפסת מיקום העבודה
	if (post.location == 1)
		printf("North\n");
	if (post.location == 2)
		printf("Center\n");
	if (post.location == 3)
		printf("South\n");

	printf("Type of job: ");	// הדפסת סוג העבודה
	if (post.Type == 1)
		printf("Full-time\n");
	if (post.Type == 2)
		printf("Part-time\n");

	printf("Profession: ");		// הדפסת סוג המקצוע
	if (post.Profession == 1)
		printf("Security\n");
	if (post.Profession == 2)
		printf("Engineering\n");
	if (post.Profession == 3)
		printf("Medicine\n");
	if (post.Profession == 4)
		printf("Restaurants\n");
	if (post.Profession == 5)
		printf("Education\n");
	if (post.Profession == 6)
		printf("Public transportation\n");
	if (post.Profession == 7)
		printf("Factories\n");
	if (post.Profession == 8)
		printf("Economics\n");
	if (post.Profession == 0)
		printf("Not relevant\n");

	printf("Description:\n%s", post.Description);	// הדפסת תיאור המודעה
}


void view_posts(Manager manager, Post post) // Requiremrnt 2.4
{
	if (manager.Posts > 0)
	{
		for (int i = 0; i < manager.Posts; i++)
		{
			printf("%d. ", i + 1);	// הדפסת מזהה המודעה

			printf("Name: %s\n", post.Name);	// הדפסת שם המודעה

			printf("Location: ");	// הדפסת מיקום העבודה
			if (post.location == 1)
				printf("North\n");
			if (post.location == 2)
				printf("Center\n");
			if (post.location == 3)
				printf("South\n");

			printf("Type of job: ");	// הדפסת סוג העבודה
			if (post.Type == 1)
				printf("Full-time\n");
			if (post.Type == 2)
				printf("Part-time\n");

			printf("Profession: ");		// הדפסת סוג המקצוע
			if (post.Profession == 1)
				printf("Security\n");
			if (post.Profession == 2)
				printf("Engineering\n");
			if (post.Profession == 3)
				printf("Medicine\n");
			if (post.Profession == 4)
				printf("Restaurants\n");
			if (post.Profession == 5)
				printf("Education\n");
			if (post.Profession == 6)
				printf("Public transportation\n");
			if (post.Profession == 7)
				printf("Factories\n");
			if (post.Profession == 8)
				printf("Economics\n");
			if (post.Profession == 0)
				printf("Not relevant\n");

			printf("Description:\n%s", post.Description);	// הדפסת תיאור המודעה
		}
	}
	else printf("No ads exist!\n");
}
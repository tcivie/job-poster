#include "Database.h"
#include "Manager.h"

Post* add_new_post(Manager manager) // TODO: Update posts array and return it
{
	Post new_post;
	new_post.Location = new_post.Type = 0;
	strcpy(new_post.Name, "0"); strcpy(new_post.Description, "0");
	do
	{
		if (strlen(new_post.Name) > MAX_SIZE)
			printf("Title should be 100 characters or lower\n");
		printf("Please enter post title (Maximun: 100 characters)\n");
		gets(new_post.Name);
	} while (strlen(new_post.Name) > MAX_SIZE);
	do
	{
		printf("Select location from list:\n1. North\n2. Center\n 3.South\n");
		scanf("%d", &new_post.Location);
	} while (new_post.Location < 1 || new_post.Location > 3);
	do
	{
		printf("Select type of job from list:\n1. Full-time\n2. Part-time\n");
		scanf("%d", &new_post.Location);
	} while (new_post.Type < 1 || new_post.Type > 2);
	do
	{
		printf("Select relevant profession from list:\n1. Security\n2. Engineering\n3. Medicine\n4. Restaurants\n5. Education\n6. Public transportation\n7. Factories\n8. Economics\n0. Not relevant\n");
		scanf("%d", &new_post.Profession);
	} while (new_post.Profession < 0 || new_post.Profession > 8);
	do
	{
		if (strlen(new_post.Description) > MAX_DESCRIPTION)
			printf("Description should be 255 characters or lower\n");
		printf("Please enter post description (Maximun: 255 characters)\n");
		gets(new_post.Description);
	} while (strlen(new_post.Description) > MAX_DESCRIPTION);
	if (!addPost(manager.ManagerID, new_post.Location, new_post.Type, new_post.Profession, new_post.Name, new_post.Description))
		printf("Error! can't add post\n");
}

Post* delete_post(Manager manager, Post post)
{
	int del_val = (-1);
	int count = 0;
	view_posts(manager, post); // display posts
	while (del_val > manager.Posts || del_val < 0)
	{
		printf("Which post would you like to remove?\n");
		scanf("%d", &del_val); // delete value
	}
	del_val = del_val - 1;
	for (int i = 0; i < manager.Posts; i++)
	{
		if (del_val = i)
		{
			count--;
		}
		else 
		{
			manager.Posts[count] = count + 1;
		}
		count++;
	}
}

Post* update_post(Manager manager, Post post)
{
	Post up_post;
	int up_val = (-1), choose = 0, flag = 0;
	view_posts(manager, post);
	while (up_val > manager.Posts || up_val < 0)
	{
		printf("Which post would you like to update?\n");
		scanf("%d", &up_val); // update value
	}
	while (choose < 0 || choose > 6)
	{
		printf("What property would you like to change?\n 1. Location\n2. Type of job\n3. Profession\n4. Name of post\n5. Description\n6. None\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			do
			{
				printf("Select location from list:\n1. North\n2. Center\n 3.South\n");
				scanf("%d", &up_post.Location);
			} while (up_post.Location < 1 || up_post.Location > 3);
			break;
		case 2:
			do
			{
				printf("Select type of job from list:\n1. Full-time\n2. Part-time\n");
				scanf("%d", &up_post.Location);
			} while (up_post.Type < 1 || up_post.Type > 2);
			break;
		case 3:
			do
			{
				printf("Select relevant profession from list:\n1. Security\n2. Engineering\n3. Medicine\n4. Restaurants\n5. Education\n6. Public transportation\n7. Factories\n8. Economics\n0. Not relevant\n");
				scanf("%d", &up_post.Profession);
			} while (up_post.Profession < 0 || up_post.Profession > 8);
			break;
		case 4:
			do
			{
				if (strlen(up_post.Name) > MAX_SIZE)
					printf("Title should be 100 characters or lower\n");
				printf("Please enter post title (Maximun: 100 characters)\n");
				gets(up_post.Name);
			} while (strlen(up_post.Name) > MAX_SIZE);
			break;
		case 5:
			do
			{
				if (strlen(up_post.Description) > MAX_DESCRIPTION)
					printf("Description should be 255 characters or lower\n");
				printf("Please enter post description (Maximun: 255 characters)\n");
				gets(up_post.Description);
			} while (strlen(up_post.Description) > MAX_DESCRIPTION);
			break;
		case 6:
			break;
		default:
			break;
		}
	}
	

}

void view_post(Post post) // Helper
{
	printf("Name: %s\n", post.Name);	// Print name

	printf("Location: ");	// Print location
	if (post.Location == 1)
		printf("North\n");
	if (post.Location == 2)
		printf("Center\n");
	if (post.Location == 3)
		printf("South\n");

	printf("Type of job: ");	// Print type
	if (post.Type == 1)
		printf("Full-time\n");
	if (post.Type == 2)
		printf("Part-time\n");

	printf("Profession: ");		// Print profession
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

	printf("Description:\n%s", post.Description);	// Print description
}


void view_posts(Manager manager) // Requiremrnt 2.4
{

	if (sizeof(manager.Posts) / sizeof(int) > 0)
	{
		Post posts[MAX_POSTS * MAX_MANAGERS];
		int size = getAllPosts(&posts);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < sizeof(manager.Posts) / sizeof(int); j++)
			{
				if (posts[i].PostID == manager.Posts)
				{
					printf("%d. ", i + 1);	// Print post id

					printf("Name: %s\n", posts[i].Name);	// Print name

					printf("Location: ");	// Print location
					if (posts[i].Location == 1)
						printf("North\n");
					if (posts[i].Location == 2)
						printf("Center\n");
					if (posts[i].Location == 3)
						printf("South\n");

					printf("Type of job: ");	// Print type
					if (posts[i].Type == 1)
						printf("Full-time\n");
					if (posts[i].Type == 2)
						printf("Part-time\n");

					printf("Profession: ");		// Print profession
					if (posts[i].Profession == 1)
						printf("Security\n");
					if (posts[i].Profession == 2)
						printf("Engineering\n");
					if (posts[i].Profession == 3)
						printf("Medicine\n");
					if (posts[i].Profession == 4)
						printf("Restaurants\n");
					if (posts[i].Profession == 5)
						printf("Education\n");
					if (posts[i].Profession == 6)
						printf("Public transportation\n");
					if (posts[i].Profession == 7)
						printf("Factories\n");
					if (posts[i].Profession == 8)
						printf("Economics\n");
					if (posts[i].Profession == 0)
						printf("Not relevant\n");

					printf("Description:\n%s", posts[i].Description);	// Print description
				}
			}
		}
	}
	else printf("No ads exist!\n");
}
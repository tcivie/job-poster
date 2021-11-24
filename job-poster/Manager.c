#include "Database.h"
#include "Manager.h"
#include "Check.h"

int add_new_post(unsigned int managerID)
{
	Manager manager;
	Post new_post;
	new_post.Location = new_post.Type = 0;
	getManagerData(&manager, managerID);
	strcpy(new_post.Name, "0"); strcpy(new_post.Description, "0");
	do
	{
		if (strlen(new_post.Name) > MAX_SIZE)
			printf("Title should be 100 characters or lower\n");
		printf("Please enter post title (Maximun: 100 characters)\n");
		getchar();
		gets(new_post.Name);
		system("cls");
	} while (strlen(new_post.Name) > MAX_SIZE);
	do
	{
		printf("Select location from list:\n1. North\n2. Center\n3. South\n");
		scanf("%d", &new_post.Location);
		system("cls");
	} while (new_post.Location < 1 || new_post.Location > 3);
	do
	{
		printf("Select type of job from list:\n1. Full-time\n2. Part-time\n");
		scanf("%d", &new_post.Type);
		system("cls");
	} while (new_post.Type < 1 || new_post.Type > 2);
	do
	{
		printf("Select relevant profession from list:\n1. Security\n2. Engineering\n3. Medicine\n4. Restaurants\n5. Education\n6. Public transportation\n7. Factories\n8. Economics\n0. Not relevant\n");
		scanf("%d", &new_post.Profession);
		system("cls");
	} while (new_post.Profession < 0 || new_post.Profession > 8);
	do
	{
		if (strlen(new_post.Description) > MAX_DESCRIPTION)
			printf("Description should be 255 characters or lower\n");
		printf("Please enter post description (Maximun: 255 characters)\n");
		getchar();
		gets(new_post.Description);
		system("cls");
	} while (strlen(new_post.Description) > MAX_DESCRIPTION);
	if (!addPost(manager.ManagerID, new_post.Location, new_post.Type, new_post.Profession, new_post.Name, new_post.Description))
	{
		red();
		printf("Error! can't add post\n");
		reset();
		return 1;
	}
	green();
	printf("Successfuly added a new post!");
	reset();
	return 0;
}

int delete_post(int managerID)
{
	int del_val = -1;
	int count = 0;
	int flag = 0,i=0;
	Manager manager;
	if (getManagerData(&manager, managerID)) {
		view_posts(manager); // display posts

		printf("Which post would you like to remove?\n");
		scanf("%d", &del_val); // delete value
		system("cls");
		while(manager.Posts[i])
		{
			if (manager.Posts[i] == del_val)
			{
				deletePost(del_val,managerID);
				flag = 1;
				green();
				printf("Post has been deleted.\n");
				reset();
				return 0;
			}
			i++;
		}
		red();
		printf("Invalid post ID\n");
		reset();
		return 1;
	}
}

int update_post(int managerID)
{
	Manager temp_manager;
	int up_val = (-1), choose = 1, flag = 0, temp = 0, type_temp = 0;
	char temp_name[MAX_DESCRIPTION] = "";
	Post posts[MAX_POSTS];
	int size = getAllPosts(&posts);
	if (!(getManagerData(&temp_manager, managerID)))
		exit(1);
	do
	{
		printf("Which post would you like to update?\n");
		scanf("%d", &up_val); // update value
		for (int i = 0; i < sizeof(temp_manager.Posts) / sizeof(int); i++)
		{
			if (temp_manager.Posts[i] == up_val)
			{
				flag = 1;
				break;
			}
		}
	} while (flag == 0);
	while (choose > 0 && choose < 6)
	{
		printf("What property would you like to change?\n 1. Location\n 2. Type of job\n 3. Profession\n 4. Name of post\n 5. Description\n 6. None\n");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			temp = 0;
			do
			{
				printf("Select location from list:\n1. North\n2. Center\n 3.South\n");
				scanf("%d", &temp);
			} while (temp < 1 || temp > 3);
			updatePost(up_val, temp, 0, 0, NULL, NULL, 0);
			break;
		case 2:
			temp = 0;
			do
			{
				printf("Select type of job from list:\n1. Full-time\n2. Part-time\n");
				scanf("%d", &temp);
			} while (temp < 1 || temp > 2);
			updatePost(up_val, 0, temp, 0, NULL, NULL, 0);
			break;
		case 3:
			temp = 0;
			do
			{
				printf("Select relevant profession from list:\n1. Security\n2. Engineering\n3. Medicine\n4. Restaurants\n5. Education\n6. Public transportation\n7. Factories\n8. Economics\n0. Not relevant\n");
				scanf("%d", &temp);
			} while (temp < 0 || temp > 8);
			updatePost(up_val, 0, 0, temp, NULL, NULL, 0);
			break;
		case 4:
			strcpy(temp_name, "");
			do
			{
				printf("Please enter post title (Maximun: 100 characters)\n");
				scanf("%s", temp_name);
			} while (FullNameCheck(temp_name) != 0);
			updatePost(up_val, 0, 0, 0, temp_name, NULL, 0);
			break;
		case 5:
			strcpy(temp_name, "");
			printf("Please enter post description (Maximun: 255 characters)\n");
			scanf("%s", temp_name);
			updatePost(up_val, 0, 0, 0, NULL, temp_name, 0);
			break;
		default:
			break;
		}
	}
}

void view_post(Post post) // Helper
{
	if (post.Promoted == 1)
		yellow();	// Set color yellow
	printf("----------------------\n");
	printf("ID:\t\t %ld\nName:\t\t %s\n", post.PostID,post.Name);	// Print name
	
	printf("Location:\t ");	// Print location
	if (post.Location == 1)
		printf("North\n");
	if (post.Location == 2)
		printf("Center\n");
	if (post.Location == 3)
		printf("South\n");

	printf("Type of job:\t ");	// Print type
	if (post.Type == 1)
		printf("Full-time\n");
	if (post.Type == 2)
		printf("Part-time\n");

	printf("Profession:\t ");		// Print profession
	if (post.Profession== 1)
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

	printf("Description:\t %s\n", post.Description);	// Print description
	printf("----------------------\n");
	reset();	// reset color
}

void view_posts(Manager manager) {
	Post postsArray[MAX_POSTS];
	int size;
	size = getPostsByManagerID(&postsArray, manager.ManagerID);
	for (int i = 0; i < size; i++) {
		view_post(postsArray[i]);
	}
}

void view_candidates_profiles(unsigned int managerID) // Requiremrnt 2.4
{
	Manager manager;
	getManagerData(&manager, managerID);
	if (sizeof(manager.Posts) / sizeof(int) > 0)
	{
		Post posts[MAX_POSTS];
		int size = getAllPosts(&posts);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < sizeof(manager.Posts) / sizeof(int); j++)
			{
				if (posts[i].PostID == manager.Posts)
				{
					printf("%d. ", posts[i].PostID);	// Print post id

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

int view_profiles(unsigned int managerID)
{
	User users[MAX_MANAGERS];
	Manager temp_manager,manager;
	int post = (-1), qty,i=0;
	getManagerData(&temp_manager,managerID);
	view_posts(temp_manager); // display posts	
	i = 0;
	printf("Which post would you like to check for candidates?\n");
	scanf("%d", &post); // selection
	while(temp_manager.Posts[i])
	{
		if (temp_manager.Posts[i] == post)
		{
			qty = getAppliedByPost(&users, post);
			if (qty== 0)
			{
				printf("No candidated applied for this post\n");
				return 0;
			}
			// case: print all the users profiles that applied for this post
			for (int i = 0; i < qty; i++)
			{
				printf("Name: %s\n", users[i].FullName);
				printf("ID: %ld\n", users[i].ID);
				printf("Age: %d\n", users[i].age);
				printf("Phone number: %s\n", users[i].PhoneNumber);
				printf("Resume: %s\n\n", users[i].Resume);
			}
			return 1;
		}
		i++;
	}
	printf("Invalid post ID\n");
	return 1;
}
#include "Database.h"

int main() {
	printf("Test");
	User me;
	int userID = registerUser("tcivie", "Gleb Tcivie", 320488398, 24, "+972543276872");
	if (userID) {
		printf("\nRegistered user\n");
		if (getUserData(&me, userID)) {
			printf("%d\n %s\n %s\n %d\n %d\n %s",me.UserID,me.FullName,me.UserName,me.ID,me.age,me.PhoneNumber);
		}
	}
	return 1;
}
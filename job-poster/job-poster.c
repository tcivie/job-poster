#include "Database.h"

int main() {
	printf("Test");
	User me;
	int userID = registerUser("tcivie", "Gleb Tcivie", 320488398, 24, "+972543276872");
	if (userID) {
		printf("Registered user");
	}
	return 1;
}
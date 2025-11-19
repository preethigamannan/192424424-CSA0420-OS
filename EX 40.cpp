#include <stdio.h>

int main() {
    char user[4], group[4], other[4];

    printf("Enter User permissions (r w x): ");
    scanf("%s", user);

    printf("Enter Group permissions (r w x): ");
    scanf("%s", group);

    printf("Enter Other permissions (r w x): ");
    scanf("%s", other);

    printf("\n--- Linux File Access Permissions ---\n");
    printf("User  : %s\n", user);
    printf("Group : %s\n", group);
    printf("Other : %s\n", other);

    return 0;
}

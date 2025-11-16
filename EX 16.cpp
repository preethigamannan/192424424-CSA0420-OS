#include <stdio.h>
#include <string.h>

struct Dir {
    char dname[20];
    char fname[20][20];
    int fcount;
} dir[10];

int main() {
    int ndir = 0, choice, i, j;
    char d[20], f[20];

    while(1) {
        printf("\n1. Create Directory\n2. Create File\n3. Search File\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        switch(choice) {

        case 1:  // Create directory
            printf("Enter directory name: ");
            scanf("%s", dir[ndir].dname);
            dir[ndir].fcount = 0;
            ndir++;
            printf("Directory created.\n");
            break;

        case 2:  // Create file inside directory
            printf("Enter directory name: ");
            scanf("%s", d);

            for(i = 0; i < ndir; i++) {
                if(strcmp(d, dir[i].dname) == 0) {
                    printf("Enter file name: ");
                    scanf("%s", dir[i].fname[dir[i].fcount]);
                    dir[i].fcount++;
                    printf("File created.\n");
                    break;
                }
            }

            if(i == ndir)
                printf("Directory not found.\n");
            break;

        case 3:  // Search file
            printf("Enter directory name: ");
            scanf("%s", d);
            printf("Enter file name: ");
            scanf("%s", f);

            int found = 0;

            for(i = 0; i < ndir; i++) {
                if(strcmp(d, dir[i].dname) == 0) {
                    for(j = 0; j < dir[i].fcount; j++) {
                        if(strcmp(f, dir[i].fname[j]) == 0) {
                            printf("File found.\n");
                            found = 1;
                            break;
                        }
                    }
                }
            }

            if(!found)
                printf("File not found.\n");
            break;

        case 4:  // Display all
            printf("\n--- TWO LEVEL DIRECTORY STRUCTURE ---\n");
            for(i = 0; i < ndir; i++) {
                printf("\nDirectory: %s\n", dir[i].dname);
                for(j = 0; j < dir[i].fcount; j++)
                    printf("  %s\n", dir[i].fname[j]);
            }
            break;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

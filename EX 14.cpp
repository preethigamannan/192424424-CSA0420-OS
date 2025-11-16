#include <stdio.h>
#include <string.h>
#define MAX 20
struct {
    char dname[20];
    char fname[MAX][20];
    int fcount;
} dir;
int main() {
    int ch;
    char name[20];
    strcpy(dir.dname, "MAIN");
    dir.fcount = 0;
    do {
        printf("\n1.Create File\n2.Search File\n3.Display Files\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", dir.fname[dir.fcount]);
                dir.fcount++;
                printf("File created.\n");
                break;
            case 2:
                printf("Enter file name to search: ");
                scanf("%s", name);
                for(int i=0;i<dir.fcount;i++)
                    if(strcmp(name, dir.fname[i])==0) {
                        printf("File found.\n");
                        goto end;
                    }
                printf("File not found.\n");
                end: break;
            case 3:
                printf("\nDirectory: %s\n", dir.dname);
                for(int i=0;i<dir.fcount;i++)
                    printf("%s\n", dir.fname[i]);
                break;
        }
    } while(ch != 4);
    return 0;
}
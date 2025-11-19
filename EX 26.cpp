#include <stdio.h>

int main() {
    FILE *fp;
    char text[200];

    // Create & Write
    fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        printf("File creation failed!");
        return 1;
    }

    printf("Enter text to write into file: ");
    fgets(text, sizeof(text), stdin);
    fputs(text, fp);
    fclose(fp);

    // Read the File
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File open failed!");
        return 1;
    }

    printf("\nContent of file:\n");
    fgets(text, sizeof(text), fp);
    printf("%s", text);

    fclose(fp);
    return 0;
}

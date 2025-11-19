#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char fileline[200], word[50];
    
    fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
        return 1;
    }

    printf("Enter word to search: ");
    scanf("%s", word);

    printf("\nLines containing '%s':\n", word);
    while (fgets(fileline, sizeof(fileline), fp)) {
        if (strstr(fileline, word)) {
            printf("%s", fileline);
        }
    }

    fclose(fp);
    return 0;
}

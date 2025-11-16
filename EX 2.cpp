#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    int in = open("source.txt", O_RDONLY);
    int out = open("copy.txt", O_WRONLY | O_CREAT, 0644);
    char buf[100];
    int n;
    while ((n = read(in, buf, sizeof(buf))) > 0)
        write(out, buf, n);
    printf("File copied successfully!\n");
    close(in);
    close(out);
}

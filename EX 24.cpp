#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char writeData[] = "This is UNIX File System Call Demo.\n";
    char readData[100];

    // Create a file
    fd = creat("demo.txt", 0644);
    if (fd < 0) {
        printf("File creation failed!\n");
        return 1;
    }
    printf("File created successfully.\n");
    close(fd);

    // Open file for writing
    fd = open("demo.txt", O_WRONLY);
    write(fd, writeData, sizeof(writeData));
    printf("Data written to file.\n");
    close(fd);

    // Open file for reading
    fd = open("demo.txt", O_RDONLY);
    read(fd, readData, sizeof(readData));
    printf("Data read from file:\n%s\n", readData);
    close(fd);

    return 0;
}

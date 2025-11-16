#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    struct stat st;
    DIR *d;
    struct dirent *dir;

    // 1. open() - open or create file
    fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    // 2. fcntl() - get file status flags
    int flags = fcntl(fd,F_GETFL);
    if (flags == -1) {
        perror("fcntl failed");
    } else {
        printf("FCNTL: File flags = %d\n", flags);
    }

    // 3. lseek() - move file pointer
    if (lseek(fd, 0, SEEK_END) == -1) {
        perror("lseek failed");
    } else {
        write(fd, "Hello OS\n", 9);
    }

    // 4. stat() - get file information
    if (stat("sample.txt", &st) == -1) {
        perror("stat failed");
    } else {
        printf("STAT: File size = %ld bytes\n", st.st_size);
    }

    // 5. opendir() + readdir() - list directory

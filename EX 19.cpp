#include <stdio.h>

int mutex = 1;         // controls access to readcount
int wrt = 1;           // writer semaphore
int readcount = 0;     // number of readers

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void reader() {
    mutex = wait(mutex);          // lock readcount
    readcount++;

    if (readcount == 1)
        wrt = wait(wrt);          // if first reader ? block writer

    mutex = signal(mutex);        // release readcount

    printf("Reader is reading... (Readers active: %d)\n", readcount);

    mutex = wait(mutex);          // lock readcount
    readcount--;

    if (readcount == 0)
        wrt = signal(wrt);        // last reader ? allow writer

    mutex = signal(mutex);
}

void writer() {
    wrt = wait(wrt);              // wait until no reader or writer
    printf("Writer is writing...\n");
    wrt = signal(wrt);            // release writing
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Reader\n2. Writer\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (mutex == 1 || readcount > 0)
                reader();
            else
                printf("Reader must wait!\n");
            break;

        case 2:
            if (wrt == 1 && readcount == 0)
                writer();
            else
                printf("Writer must wait!\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}

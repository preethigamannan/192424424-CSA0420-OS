#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5; 
int buffer[5];
int item = 1;
int in = 0, out = 0;

int wait(int s) {
    return --s;
}

int signal(int s) {
    return ++s;
}

void produce() {
    mutex = wait(mutex);
    empty = wait(empty);

    buffer[in] = item;
    printf("Producer produced item %d\n", item);
    in = (in + 1) % 5;
    item++;

    full = signal(full);
    mutex = signal(mutex);
}

void consume() {
    mutex = wait(mutex);
    full = wait(full);

    int x = buffer[out];
    printf("Consumer consumed item %d\n", x);
    out = (out + 1) % 5;

    empty = signal(empty);
    mutex = signal(mutex);
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if ((mutex == 1) && (empty != 0))
                produce();
            else
                printf("Buffer is FULL!\n");
            break;

        case 2:
            if ((mutex == 1) && (full != 0))
                consume();
            else
                printf("Buffer is EMPTY!\n");
            break;

        case 3:
            return 0;

        default:
            printf("Invalid Choice!\n");
        }
    }
}

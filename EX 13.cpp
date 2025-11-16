#include <stdio.h>
void allocate(char *name, int block[], int m, int proc[], int n, int type) {
    int alloc[10], i, j, pos;
    for(i=0;i<n;i++) alloc[i] = -1;
    for(i=0;i<n;i++) {
        pos = -1;
        for(j=0;j<m;j++) {
            if(block[j] >= proc[i]) {
                if(type==0 && pos==-1) pos = j;
                if(type==1 && (pos==-1 || block[j] < block[pos])) pos = j;  
                if(type==2 && (pos==-1 || block[j] > block[pos])) pos = j;  
            }
        }
        if(pos != -1) {
            alloc[i] = pos;
            block[pos] -= proc[i];
        }
    }
    printf("\n%s:\n", name);
    for(i=0;i<n;i++)
        printf("Process %d -> Block %d\n", i, alloc[i]);
}
int main() {
    int block1[] = {100, 500, 200, 300, 600};
    int proc[]   = {212, 417, 112, 426};
    int block2[5], block3[5];
    for(int i=0;i<5;i++)
        block2[i] = block3[i] = block1[i];
    allocate("First Fit", block1, 5, proc, 4, 0);
    allocate("Best Fit",  block2, 5, proc, 4, 1);
    allocate("Worst Fit", block3, 5, proc, 4, 2);
    return 0;
}

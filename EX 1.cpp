#include <stdio.h>
#include <windows.h>
int main() {
    DWORD pid = GetCurrentProcessId();    
    DWORD ppid = GetCurrentProcessId();      
    printf("Process ID: %lu\n", pid);
    printf("Parent Process ID (simulated): %lu\n", ppid);
    return 0;
}

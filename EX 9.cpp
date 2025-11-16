#include <stdio.h>
#include <string.h>
#include <windows.h>
int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    char msg[100];
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    
        NULL,                    
        PAGE_READWRITE,          
        0,                       
        1024,                    
        TEXT("MySharedMemory")); 
    if (hMapFile == NULL) {
        printf("Could not create file mapping object.\n");
        return 1;
    }
    pBuf = (LPTSTR) MapViewOfFile(
        hMapFile,            
        FILE_MAP_ALL_ACCESS,
        0, 0, 1024);
    if (pBuf == NULL) {
        printf("Could not map view of file.\n");
        CloseHandle(hMapFile);
        return 1;
    }
    printf("Enter message to send: ");
    gets(msg);
    CopyMemory((PVOID)pBuf, msg, strlen(msg) + 1);
    printf("Message read from shared memory: %s\n", (char*)pBuf);
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 0;
}
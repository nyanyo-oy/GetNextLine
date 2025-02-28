#include <stdio.h>
#include <sys/select.h> 

int main() {
    printf("FD_SETSIZE = %d\n", FD_SETSIZE);
    return 0;
}
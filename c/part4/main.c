#include <stdio.h>
#include <string.h>

int main() {
    const char* str = "test_\0data";
    printf("%d\n", (int)strlen(str));
    return 0;
}
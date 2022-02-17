#include <stdio.h>
#include <string.h>
int main() {
    char x[] = {'a', 'b', 'c', 'd', '\0'};
    printf("%s\n", x);
    printf("%d, %d\n", strlen(x), sizeof(x));
    return 0;
}
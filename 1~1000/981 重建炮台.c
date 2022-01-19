#include <stdio.h>
int n, t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", (2 * n - 1) % 3 ? n : n - 1);
    }
}

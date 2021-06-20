#include<stdio.h>
#include<math.h>

int main()
{
    int i = 0, ans = 0;
    double wentai, data;
    scanf("%lf", &wentai);
    while (scanf("%lf", &data) != EOF)
    {
        i++;
        if (fabs(data - wentai) > 0.05 * wentai)
        {
            ans = i;
        }
    }
    printf("%.2lf\n", 0.03*ans);
    return 0;
}
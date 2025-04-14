#include<stdio.h>
#include<math.h>

int main()
{
int t;
    scanf("%d", &t);
    while(t--)
    {
        long long a1, a2, a3;
        scanf("%lld%lld%lld", &a1, &a2, &a3);
        long long tb=(a1+a2+a3)%3;
        while (a2!=tb)
        {
            if (a2<tb)
            {
                if (a1<a3) {a2+=a3-a2; a3-=a3-a2;}
                else if (a1>a3) {a2+=a1-a2; a1-=a1-a2;}
            }
            else if (a2>tb)
            {
                if (a1<a3) {a2-=a2-a1; a1+=a2-a1;}
                else if (a1>a3) {a2-=a2-a3; a3+=a2-a3;}
            }
        }
        printf("%lld\n", abs(a1+a3-2*a2));
    }
    return 0;
}

/*=====================================================================================
                Nothing is impossible, only you think it is impossible
                        Try, try, try again until you succeed
                           Pratice, practice, and practice
I hated every minute of training, but I said, ‘Don’t quit. Suffer now and live the rest of your life as a champion.' - Mohamed Ali
=====================================================================================*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dientich(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a=x2-x1;
    double b=y2-y1;
    double c=x3-x1;
    double d=y3-y1;       // printf("%lf  %lf  %lf  %lf  \n", a, b, c, d);
    return abs((a*d-b*c))/2;
}

double khoangcach(double x1, double y1, double x2, double y2, double x3, double y3)
{

    double a, b, c, d;
    a=x2-x1; b=y2-y1; c=x3-x1; d=y3-y1;
    if (a*c+b*d<0)
    {
        double kc=(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1);
        kc=sqrt(kc);
        return kc;
    }

    a=x1-x2; b=y1-y2; c=x3-x2; d=y3-y2;
    if (a*c+b*d<0)
    {
        double kc=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
        kc=sqrt(kc);
        return kc;
    }


    double kc=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    kc=sqrt(kc);      //     printf("khoang cach %lf\n", kc);
    return 2*dientich(x1, y1, x2, y2, x3, y3)/kc;
}

void solve()
{
    double x1, y1, x2, y2, x3, y3; cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double xm, ym; cin>>xm>>ym;
    //printf("%lf\n", dientich(x1, y1, x2, y2, x3, y3));
    //printf("%lf\n", khoangcach(x1, y1, x2, y2, x3, y3));
    //printf("%lf\n", khoangcach(x2, y2, x3, y3, xm, ym));
    //printf("%lf\n", khoangcach(x1, y1, x3, y3, xm, ym));



    double x, y, z;
    x=khoangcach(x1, y1, x2, y2, xm, ym);
    y=khoangcach(x2, y2, x3, y3, xm, ym);
    z=khoangcach(x1, y1, x3, y3, xm, ym);
    double ans=min(min(x, y), z);
    printf("%.1lf\n", ans);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("_input.txt", "r", stdin);
    freopen("_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}

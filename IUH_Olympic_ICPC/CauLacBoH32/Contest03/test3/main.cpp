#include<stdio.h>
#include<string.h>


char * donvi(int s)
{
    if (s==1) return "one";
    else if (s==2) return "two";
    else if (s==3) return "three";
    else if (s==4) return "four";
    else if (s==5) return "five";
    else if (s==6) return "six";
    else if (s==7) return "seven";
    else if (s==8) return "eight";
    else if (s==9) return "nine";
    return "zero";
}

char * muoi(int s)
{
    if (s==10) return "ten";
    else if (s==11) return "eleven";
    else if (s==12) return "twelve";
    else if (s==13) return "thirteen";
    else if (s==14) return "fourteen";
    else if (s==15) return "fifteen";
    else if (s==16) return "sixteen";
    else if (s==17) return "seventeen";
    else if (s==18) return "eighteen";
    return "nineteen";
}

char * chuc(int s)
{
    if (s==10) return "ten";
    else if (s==20) return "twenty";
    else if (s==30) return "thirty";
    else if (s==40) return "forty";
    else if (s==50) return "fifty";
    else if (s==60) return "sixty";
    else if (s==70) return "seventy";
    else if (s==80) return "eighty";
    return "ninety";
}

void xuli(int s)
{
    if (0<=s && s<=9) printf("%s", donvi(s));
    else if (10<=s && s<=19) printf("%s", muoi(s));
    else if (s%10==0) printf("%s", chuc(s));
    else printf("%s-%s", chuc((s/10)*10), donvi(s%10));
    return;
}


int main()
{
    int s;
    scanf("%d", &s);
    xuli(s);
    return 0;
}

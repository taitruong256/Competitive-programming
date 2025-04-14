    #include<stdio.h>

    void nhap(int &a, int& b)
    {
        int temp =  a;
         a = b;
         b = temp;
    }
    int main()
    {
        int a = 5,  b = 2;
        nhap(a,b);
        printf("%d %d",a,b);


    }   
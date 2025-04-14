#include<stdio.h>
typedef struct Node
{
    Node *pLeft;
    Node *pRight;
    int idata;
};
typedef Node *Tree;

Node *TaoNode(int x)
{
    Node *p = new Node();
    if (p==NULL) return NULL;
    p->pLeft=NULL;
    p->pRight=NULL;
    p->idata=x;
    return p;
}

Node *TimNode(Tree c, int value)
{
    if (c!=NULL)
    {
        if (c->pLeft!=NULL)
            return TimNode(c->pLeft, value);
        if (c->idata==value) return c;
        if (c->pRight!=NULL)
            return  TimNode(c->pRight, value);
    }
}

void ThemNodeVaoCay(Node *p, Tree &c)
{
    if (c==NULL) c=p;
    else 
    {
        if (p->idata<c->idata) ThemNodeVaoCay(p, c->pLeft);
        else if (p->idata>c->idata) ThemNodeVaoCay(p, c->pRight);
        else return;
    }
}

void Nhap(Tree &c)
{
    int x;
    do 
    { 
        printf("Nhap x (Nhap -1 de ket thuc): "); scanf("%d", &x);
        Node *p=TaoNode(x);
        if (x!=-1) ThemNodeVaoCay(p, c);
    }
    while (x!=-1);
}

void XuatLNR(Tree c)
{
    if (c!=NULL)
    {
        if (c->pLeft!=NULL)
            XuatLNR(c->pLeft);
        printf("%4d", c->idata);
        if (c->pRight!=NULL)
            XuatLNR(c->pRight);
    }
}

void XuatNLR(Tree c)
{
    if (c!=NULL)
    {
        printf("%4d", c->idata);
        if (c->pLeft!=NULL)
            XuatNLR(c->pLeft);
        if (c->pRight!=NULL)
            XuatNLR(c->pRight);
    }
}

void XuatLRN(Tree c)
{
    if (c!=NULL)
    {
        
        if (c->pLeft!=NULL)
            XuatLRN(c->pLeft);
        if (c->pRight!=NULL)
            XuatLRN(c->pRight);
        printf("%4d", c->idata);
    }
}

int DemNutLa(Tree c)
{
    if (c==NULL) return 0;
    if (c->pLeft==NULL && c->pRight==NULL) return 1;
    return DemNutLa(c->pLeft)+DemNutLa(c->pRight);
}

int ChieuCao(Tree c)
{
    if (c==NULL) return 0;
    int HL=ChieuCao(c->pLeft);
    int HR=ChieuCao(c->pRight);
    if (HL>HR) return 1+HL;
    return 1+HR;
}

int main()
{
    Tree c=NULL;
    Nhap(c);
    printf("Xuat cay LNR (Tang dan): ");
    XuatLNR(c);
    XuatLRN(c);
    XuatNLR(c);
    printf("\nSo nut la la: %d\n", DemNutLa(c));
}
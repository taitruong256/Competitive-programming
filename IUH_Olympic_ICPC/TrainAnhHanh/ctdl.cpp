#include<stdio.h>
#include<string.h>
typedef struct SinhVien
{
    char masv[10];
    char hoten[30];
    int gioitinh;
    float diem;
};

typedef struct NODE
{
    SinhVien data;
    NODE *pNext;
};

typedef struct List
{
    NODE *pHead, *pTail;
};

void KhoiTao(List &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}

NODE *TaoNode(SinhVien sv)
{
    NODE *p=new NODE;
    if (p==NULL) return NULL;
    p->data=sv;
    p->pNext=NULL;
    return p;
}

bool ThemCuoi(List &l, SinhVien sv)
{
    NODE *p=TaoNode(sv);
    if (p==NULL) return false;
    if (l.pHead==NULL) 
    {
        l.pHead=l.pTail=p;
        return true;
    }
    l.pTail->pNext=p;
    l.pTail=p;
    return true;
}

SinhVien Nhap_1_SinhVien()
{
    SinhVien sv;
    printf("Nhap ma so sinh vien (nhap rong de ket thuc): "); 
    fflush(stdin);
    gets(sv.masv);
    if (strcmp(sv.masv, "")==0) return sv;
    printf("Nhap ho ten: "); 
    fflush(stdin);
    gets(sv.hoten);
    printf("Nhap gioi tinh(Nam: 0, Nu: 1): "); 
    scanf("%d", &sv.gioitinh);
    printf("Nhap diem: "); 
    scanf("%f", &sv.diem);
    return sv;
}

void Xuat_1_Sinh_Vien(SinhVien sv)
{
    printf("%10s%30s%10s%10.2f\n", sv.masv, sv.hoten, sv.gioitinh==1?"Nam":"Nu", sv.diem);
}

void Nhap_n_Sinh_Vien(List &danhsach)
{
    while (true)
    {
        SinhVien sv=Nhap_1_SinhVien();
        if (strcmp(sv.masv, "")==0) break;
        ThemCuoi(danhsach, sv);
    }
}

void Xuat_n_Sinh_Vien(List danhsach)
{
    for (NODE *p=danhsach.pHead; p!=NULL; p=p->pNext) 
        Xuat_1_Sinh_Vien(p->data);
}

int main()
{
    List danhsach;
    KhoiTao(danhsach);
    Nhap_n_Sinh_Vien(danhsach);
    Xuat_n_Sinh_Vien(danhsach);
    return 0;
}
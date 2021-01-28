#include<stdio.h>
#include<conio.h>
#include<iostream>
struct NGAY
{
	int Ngay, Thang, Nam;	
};
struct SinhVien
{
	char Masv[8];
	char Hoten[15];
	int  Gioitinh;
 	NGAY Ngaysinh;
 	char Diachi[100];
 	char Lop[8];
 	char Khoa[7];
};
struct NODE
{
	SinhVien Data;
	NODE *Link;
};
struct LIST
{
	NODE *pHead,*pTail;
};

void Init(LIST &L)
{
	L.pHead=L.pTail=NULL;
	
}
NODE *GetNode(SinhVien x)
{
	NODE *p= new NODE ;
	if(p==NULL)
	return NULL;
	p->Data=x;
	p->Link=NULL;
	return p;
}
void AddLast(LIST &L,NODE *p)
{
	if(L.pHead==NULL)
	{
		L.pHead=L.pTail=p;
	}
	else
	{
		L.pTail->Link=p;
		L.pTail=p;
	}
}
void InsertAdd(LIST &L, SinhVien x)
{
	NODE *p= GetNode(x);
	if(p==NULL)
	return ;
	AddLast(L,p);
}
int NhapSV(SinhVien &x)
{
	printf("\nNhap ma SV:");
	fflush(stdin);
	gets(x.Masv);
	if(strcmp(x.Masv,"0")==0)
		return 0;
		
	printf("\nHo va ten:");
	fflush(stdin);
	gets(x.Hoten);
	
	printf("\nGioi tinh:");
	fflush(stdin);
	scanf("%d",&x.Gioitinh);
	
	printf("\nNgay thang nam sinh:");
	fflush(stdin);
	scanf("%d/%d/%d",&x.Ngaysinh.Ngay,&x.Ngaysinh.Thang,&x.Ngaysinh.Nam);
	
	printf("\nNhap dia chi:");
	fflush(stdin);
	gets(x.Diachi);
	
	printf("\nLop:");
	fflush(stdin);
	gets(x.Lop);
	
	printf("\nKhoa:");
	fflush(stdin);
	gets(x.Khoa);
	
	return 1;
}
void NhapDSSV(LIST &L)
{
	printf("\nBat dau nhap DSSV, Nhap MASV = 0 de dung\n:");
	SinhVien x;
	int flag= NhapSV(x);
	while(flag)
	{
		InsertAdd(L,x);
		flag=NhapSV(x);
	}
	printf("\nKet thuc nhap DSSV ");
}
void XuatSinhVien(SinhVien s)
{
	char gt[4];
	if(s.Gioitinh== 0)
		strcpy(gt,"NAM");
	else
		strcpy(gt,"NU");
		printf("\n%s \n%s \n%d/%d/%d %s %s %s %s\n %8s ",
			s.Masv,s.Hoten,s.Ngaysinh.Ngay,s.Ngaysinh.Thang,s.Ngaysinh.Nam,gt,s.Diachi,s.Khoa,s.Lop
			);
}
void XuatDSSV(LIST L)
{
	NODE *p=L.pHead;
	while(p)
	{
		XuatSinhVien(p->Data);
		p=p->Link;
	}	
}
int main()
{
	LIST L;
	Init(L);
	NhapDSSV(L);
	XuatDSSV(L);
	//_getch();
	return 0;	
}
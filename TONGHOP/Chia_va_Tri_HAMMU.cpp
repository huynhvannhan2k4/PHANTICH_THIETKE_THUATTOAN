/*
Cai Dat Ung Dung Su Dung Ky Thuat Chia Va Tri
	Viet CT su dung ky thuat chia va tri thuc hien cac CT sau
	1. Tinh gia tri X^n voi X la so thuc, n la so nguyen
	  a/ Su dung ky thuat vet can
	  b/ Su dung ky thuat chia va tri don gian (Do phuc tap la O(n))
	  c/ Su dung ky thuat chia va tri cai tien (Do phuc tap la O(log2(n))
	2. Nhap vao 1 mang a chua n so thuc. Tinh tong cac phan tu trong day so a:
	  a/ Dung ky thuat vet can
	  b/ Su dung ky thuat chia va tri don gian (Do phuc tap la O(n))
	  c/ Su dung ky thuat chia va tri cai tien (Do phuc tap la O(log2(n))
	3. Cai dat thuat toan nhan 2 so nguyen lon co n chu so X*Y dung ky thuat chia va tri da trinh bay trong bai giang.
*/
#include <stdio.h>
#include <conio.h>
//Danh sach ca CT con
//Vet can 1/a
float HamMu(float x, int n);
//Chia tri don gian 1/b
float HamMuQ1(float x, int n);
//Chia tri cai tien 1/c
float HamMuQ2(float x, int n);
//Nhap so thuc vao mang a
void Nhap(float a[], int n);
//Xuat so thuc trong mang a
void Xuat(float a[], int n);
//Tong (vet can) 2/a
float Tong(float a[],int n);
//Tong (chia tri don gian) 2/b
float TongQ1(float a[],int n);
//Tong (chia tri cai tien) 2/c
float TongQ2(float a[], int l, int r);
//
//Nhan so nguyen lon
int TichMax(
);









//CT Chinh
int main(){
	float x,a[20];
	int n,n1;
	printf("Nhap so nguyen n: "); scanf("%d",&n);
	printf("\nNhap so thuc x: "); scanf("%f",&x);
	printf("\nX^n=%.2f",HamMu(x,n));
	printf("\nX^n=%.2f (O(n))",HamMuQ1(x,n));
	printf("\nX^n=%.2f (O(log2(n))",HamMuQ2(x,n));
	
	printf("\nNhap n so luong phan tu trong mang: "); scanf("%d",&n1);
	Nhap(a,n1);
	printf("\nMang da nhap la:"); Xuat(a,n1);
	printf("\nTong=%.2f",Tong(a,n1));
	printf("\nTong=%.2f (O(n))",TongQ1(a,n1));
	printf("\nTong=%.2f (O(log2(n))",TongQ2(a,0,n1));
	
	
	
	
	
	
	
	getch();
	return 0;
}
//DS Noi Dung Cac CT con
//Vet can 1/a
float HamMu(float x, int n){
	float kq=1;
	for(int i=1;i<=n;i++){
		kq*=x;
	}
	return (kq);
}
//Chia tri don gian 1/b
float HamMuQ1(float x, int n){
	if(n==0) return 1;
	else return (x*HamMuQ1(x,n-1));
}
//Chia tri cai tien 1/c
float HamMuQ2(float x, int n){
	if(n==0) return 1;
	else{
		float kq=HamMuQ2(x,n/2);
		if(n%2==0) return (kq*kq);
		else return x*kq*kq;
	}
}
//Nhap so thuc vao mang a
void Nhap(float a[], int n){
	for(int i=0;i<n;i++){
		printf("\nSo Thuc thu A[%d]: ",i+1);
		scanf("%f",&a[i]);
	}
}
//Xuat so thuc trong mang a
void Xuat(float a[], int n){
	for(int i=0;i<n;i++)
		printf("\nSo Thuc thu A[%d]: %.2f",i+1,a[i]);
}
//Tong (vet can) 2/a
float Tong(float a[],int n){
	float kq=0;
	for(int i=0;i<n;i++){
		kq+=a[i];
	}
	return kq;
}
//Tong (chia tri don gian) 2/b
float TongQ1(float a[],int n){
	if(n==1) return a[0];
	else return TongQ1(a,n-1)+a[n-1];
}
//Tong (chia tri cai tien) 2/c
float TongQ2(float a[], int l, int r){
	if(l==r) return a[l];
	else{
		int m=(l+r)/2;
		float sl=TongQ2(a,l,m);
		float sr=TongQ2(a,m+1,r);
		return sl+sr;
	}
}
//Dem chu so
int DemSo(int X,int n){
	int dem=0;
		do{
			X/=10;
			dem++;
		}while(X!=0);
	return dem;
}
//Lay n chu so ben trai
int Left(int X, int n){
	int kq;
	
}
//Lay n chu so ben phai
//Nhan so nguyen lon
int TichMax(){
}














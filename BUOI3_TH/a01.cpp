#include <stdio.h>
#include <conio.h>
// Cac chuong trinh con
// vet can
float HamMu (float a, int n) {
	float kq = 1;
	for (int i=1; i<=n; i++)
		kq = kq*a;
	return (kq);
}
float HamMuDQ1 (float a, int n) {
	if(n==0)
		return (1);
	else
		return (a*HamMuDQ1(a,n-1));
}
float HamMuDQ2 (float a, int n) {
	if(n==0)
		return (1);
	else {
		float kq = HamMuDQ2(a,n/2);
		if(n%2==0)
			return (kq*kq);
		else
			return (a*kq*kq);
	}
}

void NhapArray(float b[],int p) {
	for(int i=0; i<p; i++) {
		printf("B[%d]: ",i+1);
		scanf("%f",&b[i]);
	}
}

void XuatArray(float b[],int p) {
	printf("\nSo phan tu vua nhap la: ");
	for(int i=0; i<p; i++) {
		printf("\nB[%d]: %.2f",i+1,b[i]);
	}
}

//Tong (vet can) 2/a
float TongArray(float b[],int p) {
	float Tong = 0;
	for(int i=0; i<p ; i++) {
		Tong += b[i];
	}
	return Tong;
}

//Tong (chia tri don gian) 2/b
float TongQ1(float b[],int p) {
	if(p==1) return b[0];
	else return TongQ1(b,p-1)+b[p-1];
}
//Tong (chia tri cai tien) 2/c
float TongQ2(float b[], int l, int r) {
	if(l==r) return b[l];
	else {
		int m=(l+r)/2;
		float sl=TongQ2(b,l,m);
		float sr=TongQ2(b,m+1,r);
		return sl+sr;
	}
}
//Dem chu so
int DemSo(int X,int n) {
	int dem=0;
	do {
		X/=10;
		dem++;
	} while(X!=0);
	return dem;
}
////Lay n chu so ben trai
//int Left(int X, int n) {
//	int kq;
//
//}
////Lay n chu so ben phai
////Nhan so nguyen lon
//int TichMax() {
//}
// chuong trinh chinh
int main() {
	float x,b[100];
	int n,p;
	// Cau 1:
//	printf("Nhap gia tri X: ");
//	scanf("%f",&x);
//	printf("Nhap gia tri N: ");
//	scanf("%d",&n);
//	printf("X:%.2f__N:%d ",x,n);
//	printf("\nThuat toan vet can:");
//	printf("\nX^N:%.2f",HamMu(x,n));
//	printf("\nThuat toan chia de tri don gian:");
//	printf("\nX^N:%.2f",HamMuDQ1(x,n));
//	printf("\nThuat toan chia de tri nang cao:");
//	printf("\nX^N:%.2f",HamMuDQ2(x,n));

	// Cau 2:
	printf("\nNhap so phan tu: ");
	scanf("%d",&p);
	NhapArray(b,p);
	XuatArray(b,p);
	printf("\nSum So phan tu vua nhap la: ");
	printf("\nTong=%.2f",TongArray(b,p));
	printf("\nTong=%.2f (O(n))",TongQ1(b,p));
	printf("\nTong=%.2f (O(log2(n))",TongQ2(b,0,p));

	return 0;
}

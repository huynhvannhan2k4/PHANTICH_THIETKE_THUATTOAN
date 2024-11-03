/*
	Cac thuat toan sap xep nang cao
	Viet chuong trinh thuc hien yeu cau sau:
	1. Nhap mot day n so thuc vao mang a[]
	in day da nhap ra man hinh
	2. sap xep day da nhap theo thu tu tang dan / giam dan su dung thuat toan:
		a. quick sort
		b. merge sort
		c.heap sort
	in day da sap xep ra man hinh
	3. Nhap vao mot so thuc X , tim xem X cos trong day a khong ?
		a. In vi tri xuat hien cua X neu x trong day a
		b. thong bao khong co X neu X khong co trong day a.
		
*/
#include <stdio.h>
#include <conio.h>
typedef float keytype;

// Khai bao cac chuong trinh con
void Nhap_Day(keytype a[],int n){
	for (int i=0; i<n;i++){
		printf("\nNhap phan tu thu[%d]: ", i+1);
		scanf("%f",&a[i]);
	}
}

void In_Day(keytype a[],int n){
	for (int i=0; i<n;i++){
		printf("\nPhan tu thu[%d]:%.2f ", i+1,a[i]);
	}
}




// Chuong trinh chinh
int main(){
	keytype a[20];
	int n;
	printf("Nhap so phan tu cua day so n= ");
	scanf("%d",&n);
	
	printf("Nhap cac phan tu cua day so: ");
	Nhap_Day(a,n);
	
	printf("Day so da nhap la: ");
	In_Day(a,n);
	
	
	return 0;
}

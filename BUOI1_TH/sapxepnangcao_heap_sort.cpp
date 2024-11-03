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
void Nhap_Day(keytype a[],int n);
void In_Day(keytype a[],int n);
void Swap(keytype *a, keytype *b);
void pushDown (keytype a[], int first, int last);
void HeapSort(keytype a[], int n);
int TimPT(keytype x ,keytype a[], int l, int r);
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
	HeapSort(a,n); // Note
	printf("\nDay sao khi da sap xep la: ");
	In_Day(a,n);
	float x;
	int vitri;
	printf("\nNhap phan tu can tim: ");
	scanf("%d",&x);
	vitri = TimPT(x,a,0,n-1);
	if (vitri==-1)
		printf("\nkhong tim duoc phan tu %.2f trong day: ",x);
	else
		printf("\nTim duoc phan tu %.2f tai vi tri %d cua day so: ",x,vitri+1);	
	getch();
	return 0;
}

// 
// Ham nhap
void Nhap_Day(keytype a[],int n){
	for (int i=0; i<n;i++){
		printf("\nNhap phan tu thu[%d]: ", i+1);
		scanf("%f",&a[i]);
	}
}
// Ham in
void In_Day(keytype a[],int n){
	for (int i=0; i<n;i++){
		printf("\t%.2f",a[i]);
	}
}
// Ham doi cho
void Swap(keytype *a, keytype *b){
	keytype Temp;
	Temp = *a;
	*a = *b;
	*b = Temp;
}

void pushDown (keytype a[], int first, int last){
	int r = first;
	while (r<=last/2)
	if (last==2*r){
		if (a[r] <= a[last]) // giam > ,, tang <=
			Swap(&a[r], &a[last]);
		r=last;//break
	}
	else
		if ((a[r] <= a[2*r]) && (a[2*r] > a[2*r+1])){  // l giam > , r <= ,, tang  l <= , r >
			Swap(&a[r],&a[2*r]);
			r=2*r;
		}
	else
		if ((a[r] <= a[2*r+1]) && (a[2*r+1] > a[2*r])){ //l giam > , r <= ,, tang  l <= , r >
			Swap(&a[r],&a[2*r+1]);
			r=2*r+1;
	}
	else 
		r=last; //break;
}


// Ham sap xep HeapSort
void HeapSort(keytype a[], int n){
	int i; 
	for(i = (n-1)/2; i>=0; i--) // DEM TU 0 , THI N-1/2;
		pushDown(a,i,n-1);
	for(i = n-1; i>=2; i--) {
		Swap(&a[0],&a[i]); 
		pushDown(a, 0,i-1);
	}
	Swap(&a[0],&a[1]);
}
int TimPT(keytype x ,keytype a[], int l, int r){
	if (l <= r){
		int m = (l+r)/2;
		if (a[m]==x)
			return(m);
		else 
			if (a[m]<x)
				return (TimPT(x,a,m+1,r));
			else
				return (TimPT(x,a,l,m-1));
			return (-1);	
	}
}

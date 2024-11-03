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
void In_Day_N(keytype a[],int n);
int findPivot_ind(keytype a[], int i, int j);
void Swap(keytype *a, keytype *b);
int partition(keytype a[], int i, int j, keytype pivot);
void Quick_Sort(keytype a[], int i, int j);

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
	printf("\nDay sao khi da sap xep la: ");
	Quick_Sort(a,0,n-1); // Note
	In_Day(a,n);

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

// Ham tim phan tu chot
int findPivot_ind(keytype a[], int i, int j){
	int k;
	for (k=i+1; (k<=j) && a[k]==a[i]; k++);
	//Không làm gì c?
	if (k>j)
	return -1;//không có ch?t
	else 
	if (a[k]>a[i])
		return k;
	else
		return i;
}
// Ham doi cho
void Swap(keytype *a, keytype *b){
	keytype Temp;
	Temp = *a;
	*a = *b;
	*b = Temp;
}
// Ham phan hoach day
int partition(keytype a[], int i, int j, keytype pivot){
	int l=i, r=j;
	while (l<=r) {
		while (a[l]>=pivot) l++; // doi dau tang dan ((a[l]<pivot)) va giam dan (a[l]>=pivot)
		while (a[r]<pivot) r--;// doi dau tang dan ((a[l]>=pivot)) va giam dan (a[r]<pivot)
		if (l<r)
			Swap(&a[l],&a[r]);
	}
	return l;
}
// Ham sap xep Quick_sort
void Quick_Sort(keytype a[], int i, int j){
	int
		pivot_ind=findPivot_ind(a,i,j);
	if (pivot_ind!=-1){
			keytype
	pivot=a[pivot_ind];
	int k=partition(a,i,j,pivot);
	Quick_Sort (a,i,k-1);
	Quick_Sort (a,k,j);
	}
}

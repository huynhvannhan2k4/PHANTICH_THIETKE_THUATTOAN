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
void Merge(keytype a[], int l, int m, int r);
void MergeSort(keytype a[], int left, int right);
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
	MergeSort(a,0,n-1); // Note
	printf("\nDay sao khi da sap xep la: ");
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
// Ham doi cho
void Swap(keytype *a, keytype *b){
	keytype Temp;
	Temp = *a;
	*a = *b;
	*b = Temp;
}

void Merge(keytype a[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
/* Tao các mang tam */
	float L[n1], R[n2];
/* Copy du lieu sang các mang tam */
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1+ j];
/* Gop hai mang tam vào mang arr*/
	i = 0; // Khoi tao chi so bat dau cua mang con dau tiên
	j = 0; // Khoi tao chi so bat dau cua mang con thu hai
	k = l; // Khoi tao chi so bat dau cua mang luu ket qua k = l
/*Khi c? 2 dãy con d?u còn ph?n t? */
	while (i < n1 && j < n2){
	if (L[i] <= R[j]){ // note tang giam <= tang , > giam dan
		a[k] = L[i];
		i++;
	}
	else{
		a[k] = R[j];
		j++;
	}
	k++;
}
/* Copy các phan tu con lai cua mang L vào mang ket qua arr neu co */
	while (i < n1){
		a[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2){
		a[k] = R[j];
		j++;
		k++;
	}

}


// Ham sap xep MergeSort
void MergeSort(keytype a[], int left, int right) {
	if(left < right) {
		int middle = (left + right) / 2;
		MergeSort(a, left, middle);
		MergeSort(a, middle + 1, right);
		Merge(a, left, middle, right); // chu y coi chung thieu
	}
}


/*
	img:
*/

#include <stdio.h>
#include <conio.h>
// Cac chuong trinh con
//void Nhap(float a, int n);
void Xuat(float a, int n);
float HamMu(float a, int n);
// chuong trinh chinh
int main() {
	float a;
	int n;
	printf("X: ");
	scanf("%f",&a);
	printf("N: ");
	scanf("%d",&n);
//	Nhap(a,n);
	Xuat(a,n);

	getch();
	return 0;
}

//void Nhap(float a, int n) {
//	
//}

void Xuat(float a, int n) {
	printf("%.2f",a);
	printf("%d",n);
	printf("KQ: %.2f",HamMu(a,n));
}

float HamMu (float a, int n){
	float kq = 1;
	for(int i=1; i<=n; i++){
		kq = kq*a;
	}
	return (kq);
}

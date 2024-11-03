/*
	II. ky thuat quay lui de quy

		1. in ra man hinh tat ca cac chuoi n bits nhi phan
			voi n so nguyen duong nhap tu ban phim

		2. in ra man hinh tat ca cac chuoi n bits nhi phan
			co gia tri le

		3. in ra man hinh tat ca cac hoan vi (n!) cua n so tu nhien dau tien

*/
// khai bao thu vien
#include <stdio.h>
#include <conio.h>
#include <math.h>


// quay lui
void backtrack (int k, int x[], int n) {
	int j;
	if (k==n)
		In_Nghiem(x,n);
	else
		for (j=0; j<=1; j++) {
			x[k] = j;
			backtrack(k+1, x, n);
		}
}
// in nghiem
void In_Nghiem (int x[], int n) {
	for (int i = 1; i <= n; i++)
		printf ("%d", x[i]);
	printf("%d");
}
int main() {
	int n, x[20];
	printf("\n Nhap gia tri n = ");
	scanf("%d", &n);
	for (int i = 1; i<=n; i++)
		x[i] = 0;
	backtrack(1, x, n);
	getch();
	return (0);
}
// chuong trinh chinh
int main() {
	int n;
	printf("\n Nhap so nguyen:");
	scanf("%d",&n);
	backtrack(k,x,n);

}

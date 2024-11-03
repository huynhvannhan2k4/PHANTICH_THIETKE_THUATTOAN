#include <stdio.h>
#include <conio.h>

// tinh to hop chap k cua n . nCk

long toHop(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return toHop(k - 1, n - 1) + toHop(k, n - 1);
}
// het

// tinh to hop chap k cua n su dung ky thuat vet can
long giaiThua(int n) {
	long S=1;
	for (int i = 1; i<=n; i++)
		S *= i;
	return S;
}

long C(int k, int n) {
	return giaiThua(n) / (giaiThua(k) * giaiThua(n-k));
}
// het phan ky thuat vet can

int main() {
	// tinh to hop chap k cua n su dung ky thuat vet can
	// khai bao bien
	int k,n;
	printf("\n NHAP K= ");
	scanf("%d",&k);
	printf("\n NHAP N= ");
	scanf("%d",&n);
	printf("\n 1) TO HOP CHAP %d CUA %d = %d",k,n,toHop(k,n));
	printf("\n A) TO HOP CHAP %d CUA %d = %d",k,n,C(k,n));

	getch();
	return 0;

}

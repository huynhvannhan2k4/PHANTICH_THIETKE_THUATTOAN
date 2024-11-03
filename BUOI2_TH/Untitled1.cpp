/*
	Ky thuat vet can va quay lui de quy
	
	I. ky thuat vet can
	
		1. tim tat ca cac so co 4 chu so abcd thoa cac dieu kien sau:
			+ abcd la so nguyen to và ab = C^2 + d^2
	
		2. tim tat ca cac bo 3 cac so (x,y,z) phan biet thoa:
			a. 1 <= a,b,c <= 10000 (a,b,c la cac hang so)
			b. x+y+z = a ; x*y*z = b; x^2 + y^2 + z^2 = c
		
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
// ham kiem tra so nguyen to
//int Kiem_tra_SNT(int n) {
//	int dem=0;
//	for (int i=2; i<=sqrt(n);i++)
//		if(n%i==0)
//			dem++;
//		if(dem==0)
//			return(1);
//		else
//			return(0);	
//}
// ham kiem tra so nguyen to
int Kiem_tra_SNT(int n) {
    // so nguyen n < 2 khong phai la so nguyen to
    if (n < 2) {
        return 0;
    }
    // check so nguyen to khi n >= 2
    int i;
    int squareRoot = (int) sqrt(n);
    for (i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
void InSo(){
	for (int a=1; a<=9; a++)
		for (int b=0; b<=9; b++)
			for (int c=0; c<=9; c++)
				for (int d=0; d<=9; d++)
						if(Kiem_tra_SNT(a*1000+b*100+c*10+d)==1 && (10*a+b == c*c+d*d)){
							printf("%d %d %d %d",a,b,c,d);
							printf("\n");
						}
}
// Chuong trinh chinh
int main(){
	InSo();
}

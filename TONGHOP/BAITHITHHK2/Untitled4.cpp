#include <stdio.h>
#include <conio.h>
typedef int TB[100][1000];
typedef struct {
	char tenDovat[20];
	float giaTri;
	int trongLuong, soLuong;
}doVat;

//Nhap thong tin cac loai do vat
void NhapLoaiDV(doVat LoaiDV[],int SoLoaiDV){
	printf("\n Nhap thong tin cho cac loai do vat: ");
	for(int i=0; i<SoLoaiDV; i++){
		printf("\n Nhap ten do vat thu %d la: ",i+1); gets(LoaiDV[i].tenDovat);
		printf("\n Nhap trong luong cua do vat thu %d la: ",i+1); scanf("%d",&LoaiDV[i].trongLuong);
		printf("\n Nhap gia tri cua do vat thu %d la: ",i+1); scanf("%f",&LoaiDV[i].giaTri);
		LoaiDV[i].soLuong = 0;  
		fflush(stdin);
	}
}


void Table(doVat LoaiDV[], int n, int w, TB f, TB x){
	int xk, yk, k, fmax, xmax, v;
	for (v = 0; v < w; v++) {
        x[0][v] = v / LoaiDV[0].trongLuong;
        f[0][v] = x[0][v] * LoaiDV[0].giaTri;
    }
	
	for (k = 1; k < n; k++) {
        for (v = 0; v < w; v++) {
            fmax = 0;
            yk = v / LoaiDV[k].trongLuong;
            for (xk = 0; xk <= yk; xk++) {
                if (f[k - 1][v - xk * LoaiDV[k].trongLuong] + xk * LoaiDV[k].giaTri > fmax) {
                    fmax = f[k - 1][v - xk * LoaiDV[k].trongLuong] + xk * LoaiDV[k].giaTri;
                    xmax = xk;
                }
            }
            x[k][v] = xmax;
            f[k][v] = fmax;
        }
    }
}


void KTTable(doVat LoaiDV[], int n, int w, TB x){
	int k;
    int v = w;
    int gtri = 0;
    int tluong = 0;
    for (k = n - 1; k >= 0; k--) {
        LoaiDV[k].soLuong = x[k][v];
        v = v - x[k][v] * LoaiDV[k].trongLuong;
        gtri += LoaiDV[k].soLuong * LoaiDV[k].giaTri;
        tluong += LoaiDV[k].soLuong * LoaiDV[k].trongLuong;
        printf("S? lu?ng d? v?t %s du?c l?y là %d s?n ph?m\n", LoaiDV[k].tenDovat, LoaiDV[k].soLuong);
    }
    printf("Ba lô có t?ng giá tr? là %d v?i kh?i lu?ng là %d\n", gtri, tluong);
}


int main(){
	//2. Bai toan cai balo
	int W, SoLoaiDV;
	doVat LoaiDV[10];
	TB f,x;
    printf("\n BAI TOAN CAI BALO.");
	printf("\n Nhap trong luong cua cai balo: "); scanf("%d",&W);
	printf("\n Nhap so loai do vat : "); scanf("%d",&SoLoaiDV);
	fflush(stdin);
	//Nhap thong tin cac loai do vat
	NhapLoaiDV(LoaiDV,SoLoaiDV);
	Table(LoaiDV,SoLoaiDV,W,f,x);
	KTTable(LoaiDV,SoLoaiDV,W,x);
	getch();
	return 0;
}

/*
	printf("");



*/


#include"stdio.h"
#include"conio.h"
#include"limits.h"

// CAU TRUC TO TIEN
typedef struct {
	char Ten[30];
	int TrongLuong;
	int GiaTri;
	float DonGia;
	int SoLuong;
} DoVat;

void NhapLoaiDoVat(DoVat LoaiDoVat[], int SoLoaiDoVat) {
	printf("\n NHAP THONG TIN CHO CAC LOAI DO VAT: ");
	for(int i=0 ; i<SoLoaiDoVat; i++) {
		fflush(stdin);
		printf("\n NHAP TEN DO VAT THU %d la: ",i+1);
		gets(LoaiDoVat[i].Ten);
		printf("\n NHAP TRONG LUONG DO VAT THU %d LA: ",i+1);
		scanf("%d",&LoaiDoVat[i].TrongLuong);
		printf("\n NHAP GIA TRI DO VAT THU %d LA: ",i+1);
		scanf("%d",&LoaiDoVat[i].GiaTri);
		LoaiDoVat[i].SoLuong = 0;
	}
}
void SapXepDoVat(DoVat LoaiDoVat[], int SoLoaiDoVat) {
	for (int i=0; i<SoLoaiDoVat - 1; i++)
		for (int j=i+1; j<SoLoaiDoVat; j++)
			if (LoaiDoVat[j].TrongLuong > LoaiDoVat[i].TrongLuong) {
				DoVat Tam;
				Tam = LoaiDoVat[i];
				LoaiDoVat[i] = LoaiDoVat[j];
				LoaiDoVat[j] = Tam;
			}
}
void CaiBaLo(long TRONGLUONG, int SoLoaiDoVat, DoVat LoaiDoVat[]) {
	float GTBalo = 0;
	// CAI BALO
	// TINH DON GIA CHO CAC LOAI DO VAT
	for (int i=0; i<SoLoaiDoVat; i++) {
		LoaiDoVat[i].DonGia = (float)(LoaiDoVat[i].GiaTri)/LoaiDoVat[i].TrongLuong;
	}
	// SAP XEP CAC LOAI DO VAT THEO TRONG LUONG GIAM DAN
	SapXepDoVat(LoaiDoVat,SoLoaiDoVat);
	// CHON DO VAT BO VAO BALO
	for (int i=0; i<SoLoaiDoVat; i++) {
		// SO LUONG DO VAT i DUOC CHON
		LoaiDoVat[i].SoLuong = TRONGLUONG/LoaiDoVat[i].TrongLuong;
		// CAP NHAT GIA TRI CUA BALO
		GTBalo = GTBalo + LoaiDoVat[i].SoLuong *LoaiDoVat[i].GiaTri;
		// CAP NHAT TRONG LUONG CON LAI CUA BALO
		TRONGLUONG = TRONGLUONG - LoaiDoVat[i].SoLuong * LoaiDoVat[i].TrongLuong;

	}
	// XUAT KET QUA CUA BAI TOAN CAI BALO
	for (int i=0; i<SoLoaiDoVat; i++)
		printf("\n SO LOAI DO VAT: %s CAN LAY LA: %d CAI ",LoaiDoVat[i].Ten,LoaiDoVat[i].SoLuong);

	printf("\n BALO CO GIA TRI LA %.2f VA TRONG LUONG CON LAI LA %d ",GTBalo,TRONGLUONG);
	printf("\n");

}



// CHUONG TRINH CHINH
int main() {
	long TRONGLUONG;
	DoVat LoaiDoVat[10];
	int SoLoaiDoVat;

	printf("\n BAI TOAN CAI BALO: ");
	printf("\n NHAP TRONG LUONG CUA BALO: ");
	scanf("%d",&TRONGLUONG);
	printf("\n NHAP SO LOAI DO VAT: ");
	scanf("%d",&SoLoaiDoVat);
	fflush(stdin);
	// NHAP THONG TIN CAC LOAI TO GIAY BAC
	NhapLoaiDoVat(LoaiDoVat, SoLoaiDoVat);
	// THUC HIEN DOI TIEN ATM
	CaiBaLo(TRONGLUONG, SoLoaiDoVat, LoaiDoVat);

}

/*
	printf("");



*/


#include"stdio.h"
#include"conio.h"
#include"limits.h"

// CAU TRUC TO TIEN
typedef struct {
	char Ten[30];
	int Gia;
	int SoTo;
} Tien;

void NhapLoaiTien(Tien LoaiTien[], int SoLoaiTien) {
	printf("\n NHAP THONG TIN CHO CAC LOAI TO GIAY BAC");
	for(int i=0 ; i<SoLoaiTien; i++) {
		fflush(stdin);
		printf("\n NHAP TEN TO TIEN THU %d la: ",i+1);
		gets(LoaiTien[i].Ten);
		printf("\n NHAP MENH GIA TIEN THU %d LA: ",i+1);
		scanf("%d",&LoaiTien[i].Gia);
		LoaiTien[i].SoTo = 0;
	}
}
void SapXepTien(Tien LoaiTien[], int SoLoaiTien) {
	for (int i=0; i<SoLoaiTien - 1; i++)
		for (int j=i+1; j<SoLoaiTien; j++)
			if (LoaiTien[j].Gia > LoaiTien[i].Gia) {
				Tien Tam;
				Tam = LoaiTien[i];
				LoaiTien[i] = LoaiTien[j];
				LoaiTien[j] = Tam;
			}
}
void RutTien_ATM(long SoTien, int SoLoaiTien, Tien LoaiTien[]) {
	// SAP XEP CAC LOAI TO GIAY BAC THEO MENH GIA GIAM DAN
	SapXepTien(LoaiTien,SoLoaiTien);

	// DOI TIEN ATM
	for (int i=0; i<SoLoaiTien; i++) {
		int STo = SoTien/LoaiTien[i].Gia;
		LoaiTien[i].SoTo = STo;
		SoTien = SoTien - STo*LoaiTien[i].Gia;
	}

	// XUAT KET QUA DOI TIEN
	for (int i=0; i<SoLoaiTien; i++)
		printf("\n SO TO TIEN %s CAN DOI LA %d TO ",LoaiTien[i].Ten,LoaiTien[i].SoTo);
	printf("\n");

}



// CHUONG TRINH CHINH
int main() {
	long SoTien;
	Tien LoaiTien[10];
	int SoLoaiTien;

	printf("\n BAI TOAN DOI TIEN ATM");
	printf("\n NHAP SO TIEN CAN DOI: ");
	scanf("%d",&SoTien);
	printf("\n NHAP SO LOAI TO GIAY BAC: ");
	scanf("%d",&SoLoaiTien);
	fflush(stdin);
	// NHAP THONG TIN CAC LOAI TO GIAY BAC
	NhapLoaiTien(LoaiTien,SoLoaiTien);
	// THUC HIEN DOI TIEN ATM
	RutTien_ATM(SoTien,SoLoaiTien,LoaiTien);

}

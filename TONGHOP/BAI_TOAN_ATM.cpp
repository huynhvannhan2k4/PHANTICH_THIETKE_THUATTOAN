#include <stdio.h>
#include <conio.h>
#include <limits.h>

//Cau truc to tien
typedef struct{
	 char Ten[30];
	 int Gia;
	 int SoTo;  
}Tien;


//Nhap thong tin cac loai to giay bac
void NhapLoaiTien(Tien LoaiTien[],int SoLoaiTien);
//Sap xep cac loai to giay bac theo menh gia giam dan
void SapXepTien(Tien LoaiTien[],int SoLoaiTien);
//Thuc hien doi tien ATM
void Greedy_ATM(long SoTien,int SoLoaiTien,Tien LoaiTien[]);

int main(){
	//1. Bai toan doi tien ATM
	long SoTien; 
	Tien LoaiTien[10];
	int SoLoaiTien;
	printf("\n BAI TOAN DOI TIEN ATM.");
	printf("\n Nhap so tien can doi : "); scanf("%d",&SoTien);
	printf("\n Nhap so loai to giay bac : "); scanf("%d",&SoLoaiTien);
	fflush(stdin);
	//Nhap thong tin cac loai to giay bac
	NhapLoaiTien(LoaiTien,SoLoaiTien);
	//Thuc hien doi tien ATM
	Greedy_ATM(SoTien,SoLoaiTien,LoaiTien); 
	
	getch();
	return 0;
}

//Cai dat cac CT con
//Nhap thong tin cac loai to giay bac
void NhapLoaiTien(Tien LoaiTien[],int SoLoaiTien){
	printf("\n Nhap thong tin cho cac loai to giay bac");
	for(int i=0; i<SoLoaiTien; i++){
		printf("\n Nhap ten to tien thu %d la: ",i+1); gets(LoaiTien[i].Ten);
		printf("\n Nhap menh gia tien thu %d la: ",i+1); scanf("%d",&LoaiTien[i].Gia);
		LoaiTien[i].SoTo = 0;
		fflush(stdin);
	}
}
//Sap xep cac loai to giay bac theo menh gia giam dan
void SapXepTien(Tien LoaiTien[],int SoLoaiTien){
	for(int i=0; i<SoLoaiTien-1; i++)
	   for(int j=i+1; j<SoLoaiTien; j++)
	      if(LoaiTien[j].Gia>LoaiTien[i].Gia){
	      	  Tien Tam;
			  Tam = LoaiTien[i];
			  LoaiTien[i] = LoaiTien[j];
			  LoaiTien[j] = Tam; 	 
	      }
}
//Thuc hien doi tien ATM
void Greedy_ATM(long SoTien,int SoLoaiTien,Tien LoaiTien[]){
	//1. Sap xep cac loai to giay bac theo menh gia giam dan
	SapXepTien(LoaiTien,SoLoaiTien);
	//2. Doi tien ATM
	for (int i=0; i<SoLoaiTien; i++){
		int STo = SoTien/LoaiTien[i].Gia;
		LoaiTien[i].SoTo = STo;
		SoTien = SoTien - STo*LoaiTien[i].Gia;
	}
	//3. Xuat ket qua doi tien
	for (int i=0; i<SoLoaiTien; i++)
		printf("\n So to tien %s can doi la %d to",LoaiTien[i].Ten,LoaiTien[i].SoTo);
	printf("\n");	
}
	

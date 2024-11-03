#include <stdio.h>
#include <conio.h>
#include <limits.h>

//Cau truc to tien
typedef struct{
	 char Ten[30];
	 int Gia;
	 int SoTo;  
}Tien;

//Cau truc do vat
typedef struct{
	 char Ten[30];
	 int GiaTri;
	 int TrongLuong;
	 int SoLuong;  
	 float DonGia;
}DoVat;

//Nhap thong tin cac loai to giay bac
void NhapLoaiTien(Tien LoaiTien[],int SoLoaiTien);
//Sap xep cac loai to giay bac theo menh gia giam dan
void SapXepTien(Tien LoaiTien[],int SoLoaiTien);
//Thuc hien doi tien ATM
void Greedy_ATM(long SoTien,int SoLoaiTien,Tien LoaiTien[]);
//Nhap thong tin cac loai do vat
void NhapLoaiDV(DoVat LoaiDV[],int SoLoaiDV);
//Sap xep cac loai do vat theo don gia giam dan
void SapXepDV(DoVat LoaiDV[],int SoLoaiDV);
//Thuc hien lay do vat
void Greedy_Balo(int W,int SoLoaiDV,DoVat LoaiDV[]);
//Thuat toan Greedy cho bai toan TSP
int Greedy_TSP(int C[][10], int n, int TOUR[]);
	
int main(){
	//1. Bai toan doi tien ATM
	/*long SoTien; 
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
	
	//2. Bai toan cai balo
	int W, SoLoaiDV;
	DoVat LoaiDV[10];
    printf("\n BAI TOAN CAI BALO.");
	printf("\n Nhap trong luong cua cai balo: "); scanf("%d",&W);
	printf("\n Nhap so loai do vat : "); scanf("%d",&SoLoaiDV);
	fflush(stdin);
	//Nhap thong tin cac loai do vat
	NhapLoaiDV(LoaiDV,SoLoaiDV);
	//Thuc hien lay do vat
	Greedy_Balo(W,SoLoaiDV,LoaiDV); */ 
	
	//Cau 3 - Thuat toan Greedy cho bai toan TSP
	int n, TOUR[10], C[10][10];	
	//Nhap thong tin cho bai toan - so dinh
	printf("Nhap so dinh can di qua cua chu trinh n ="); scanf("%d",&n);
	//Nhap ma tran trong so cua do thi
	printf("\n Nhap ma tran cuoc phi di chuyen giua cac dinh :");
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			printf("\n Nhap chi phi di chuyen tu dinh %d den dinh %d : ",i,j); scanf("%d",&C[i][j]);
		}
	//Tien hanh thuat toan Greedy cho bai toan TSP
	int Cost = Greedy_TSP(C, n, TOUR); 
	//Xuat chu trinh
	printf("\n Chu trinh co chi phi nho nhat la: ");
	printf("%d",TOUR[1]);
	for(int i=2; i<n; i++)
	   printf(" --- %d",TOUR[i]);
	printf(" --- %d \n",TOUR[1]);
	printf("Co tong chi phi la %d ",Cost);
	
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
	
//Nhap thong tin cac loai do vat
void NhapLoaiDV(DoVat LoaiDV[],int SoLoaiDV){
	printf("\n Nhap thong tin cho cac loai do vat: ");
	for(int i=0; i<SoLoaiDV; i++){
		printf("\n Nhap ten do vat thu %d la: ",i+1); gets(LoaiDV[i].Ten);
		printf("\n Nhap trong luong cua do vat thu %d la: ",i+1); scanf("%d",&LoaiDV[i].TrongLuong);
		printf("\n Nhap gia tri cua do vat thu %d la: ",i+1); scanf("%d",&LoaiDV[i].GiaTri);
		LoaiDV[i].SoLuong = 0;
		LoaiDV[i].DonGia = 0;  
		fflush(stdin);
	}
}

//Sap xep cac loai do vat theo don gia giam dan
void SapXepDV(DoVat LoaiDV[],int SoLoaiDV){
	for(int i=0; i<SoLoaiDV-1; i++)
	   for(int j=i+1; j<SoLoaiDV; j++)
	      if(LoaiDV[j].DonGia>LoaiDV[i].DonGia){
	      	  DoVat Tam;
			  Tam = LoaiDV[i];
			  LoaiDV[i] = LoaiDV[j];
			  LoaiDV[j] = Tam; 	 
	      }
}
//Thuc hien lay do vat
void Greedy_Balo(int W,int SoLoaiDV,DoVat LoaiDV[]){
	float GTBaLo = 0;
	//1. Tinh don gia cho cac loai do vat
	for(int i=0; i<SoLoaiDV; i++)
	   LoaiDV[i].DonGia = (float)(LoaiDV[i].GiaTri)/LoaiDV[i].TrongLuong;
	//2. Sap xep cac loai do vat theo don gia giam dan
	SapXepDV(LoaiDV,SoLoaiDV);
	//3. Chon do vat bo vao balo
	for(int i=0; i<SoLoaiDV; i++){
		//So luong do vat i duoc chon
		LoaiDV[i].SoLuong = W/LoaiDV[i].TrongLuong;
		//Cap nhat gia tri cua ba lo
		GTBaLo = GTBaLo + LoaiDV[i].SoLuong * LoaiDV[i].GiaTri;
		//Cap nhat trong luong con lai cua ba lo
		W = W - LoaiDV[i].SoLuong * LoaiDV[i].TrongLuong; 
	}
	//4. Xuat ket qua cua bai toan ba lo
	for (int i=0; i<SoLoaiDV; i++)
		printf("\n So loai do vat %s can lay la %d cai",LoaiDV[i].Ten,LoaiDV[i].SoLuong);
	printf("\n Ba lo co gia tri la %.2f va trong luong con lai la %d .",GTBaLo,W);	
	printf("\n");  
}

//Thuat toan Greedy cho bai toan TSP
int Greedy_TSP(int C[][10], int n, int TOUR[]){
   int KT[10]; //Danh dau cac dinh da duoc su dung
   int i; // Bien dem, dem tim du n dinh thi dung
   for(i = 1; i <= n; i++)
      KT[i] = 0; //Chua dinh nao duoc xet
      
   int COST = 0; //Luc dau, gia tri COST = 0
   i = 1;  //Dinh bat dau xuat phat
   int v = i; //Dinh dang xet va Chon dinh xuat phat la 1 
   
   while(i < n){
   	   TOUR[i] = v; //Dua v vao chu trinh KT[v] = 1; //Dinh v da duoc xet
   	   KT[v] = 1;   //Dinh v da di qua
       int CanhMin = INT_MAX; //Chon min cac canh(cung) trong moi buoc int COST; //Trong so nho nhat cua chu trinh
       int w; //Dinh duoc chon trong moi buoc   
       //Xet cac dinh co the di toi tu v
       for (int k = 1; k <= n; k++)
          if(KT[k]==0) //Neu dinh k chua duoc xet (chua di toi)
             if(CanhMin > C[v][k]){
               CanhMin = C[v][k];
               w = k;  // Cap nhat lai dinh co gia be nhat
            }
       v = w;  //Cap nhat lai dinh dang xet moi    
       COST = COST + CanhMin;   //Tinh lai chi phi cua chu trinh
       i++;  // tang bien lap 
   }
   COST = COST + C[v][1];  //Quay lai dinh dau tien
   return COST;
}

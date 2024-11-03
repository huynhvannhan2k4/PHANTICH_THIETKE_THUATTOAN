#include<conio.h>
#include<stdio.h>

//Khai bao cau truc do vat
typedef struct{
	char Ten[20];
	int TL, GT;
	int SL;
} DoVat;

//Khai bao cau truc bang de luu tru gia tri cua cac bai toan con
typedef int Bang [10][500];


//Ham tinh giai thua
long GThua (int n){
	long kq = 1;
	for (int i=1; i<=n; i++)
	   kq*= i;
	return (kq);
}   
//Tinh to hop chap k cua n theo vet can
int Comb_VetCan(int n, int k) {
	return (GThua(n)/(GThua(k)*GThua(n-k)));
}
//Tinh to hop chap k cua n theo de quy chia va tri
int Comb_ChiaTri(int n, int k) {
	if (k==0 || k==n)
		return 1;
	return Comb_ChiaTri(n-1, k-1) + Comb_ChiaTri(n-1,k);
}
//Tinh to hop chap k cua n theo quy hoach dong
int Comb_QHD(int n, int k){
   int C[10][10];
   int i,j;
   C[0][0]= 1;
   for(i=1;i<=n; i++){
      C[i][0] = 1;
      C[i][i] = 1;
      for(j=1;j<=i-1; j++)
         C[i][j] = C[i-1][j-1] + C[i-1][j];
      }
   return (C[n][k]);
}

//Ham nhap thong tin cho cac loai do vat
void Nhap_DoVat(DoVat SP[], int n){
	int i;
	for(i=0; i<n; i++){
		fflush(stdin);
		printf("\n Nhap ten cua Do vat:");gets(SP[i].Ten);
		printf("\n Nhap trong luong cua Do vat:");scanf("%d",&SP[i].TL);
		printf("\n Nhap gia tri cua Do vat:");scanf("%d",&SP[i].GT);
		SP[i].SL = 0;
	}
}
// Ham tao bang cho bai toan Ba lo
void TaoBang_BaLo(DoVat SP[], int n, int W, Bang F, Bang X){
	int xk, yk, k, FMax, XMax, V;
	//Dien gia tri cho dong dau tien
	for (V=0; V<=W; V++){
		X[0][V]=V/SP[0].TL;
		F[0][V]=X[0][V]*SP[0].GT;
	}
	//Dien gia tri cho cac dong con lai
	for (k=1; k<n; k++){
		// Tim xk va F[k][V]
	   for (V=0; V<=W; V++){
	      FMax = 0;
	      yk = V/SP[k].TL;
	      for (xk=0; xk<=yk; xk++)
	         if(F[k-1][V-xk*SP[k].TL]+xk*SP[k].GT > FMax){
	         	FMax = F[k-1][V-xk*SP[k].TL]+xk*SP[k].GT;
	         	XMax = xk;
	         }
	         X[k][V] = XMax;
			 F[k][V] = FMax; 
	   }
    }
}

// Ham tra bang cho bai toan Ba lo
void TraBang_BaLo(DoVat SP[], int n, int W, Bang X){
	int k;
	int V = W;  // Bat dau do tu cot W
	int GTri = 0;   //Gia tri cua balo sau khi chon cac do vat
	int TLuong = 0; //Trong luong cua balo sau khi chon cac do vat
	for (k=n-1; k>=0; k--){
		SP[k].SL = X[k][V];
		V = V - X[k][V]*SP[k].TL;
		GTri += SP[k].SL * SP[k].GT;
		TLuong += SP[k].SL * SP[k].TL;
		//Xuat ket qua
		printf("So luong do vat "); puts(SP[k].Ten);
		printf("duoc lay la %d san pham \n",SP[k].SL);
	}
	printf("\n Ba lo co tong gia tri la %d voi khoi luong la %d",GTri,TLuong);
}

// Ham tao bang cho bai toan doi tien ATM 
void TaoBang_ATM(int n, int a[],int M, Bang c){
   int i,j,k;
   for(j=1;j<=M;j++) 
      c[0][j]=M+1; //vo cung = M+1
   for(i=1;i<=n;i++) 
      c[i][0]=0; 
   for(i=1;i<=n;i++)
      for(j=1;j<=M;j++){
         c[i][j]=c[i-1][j];
         if(j>=a[i] && c[i][j]>c[i][j-a[i]]+1)
            c[i][j]=c[i][j-a[i]]+1;
      }
}
//Trinh bay ket qua cho bai toan doi tien ATM
void TraBang_ATM(int N,int a[],int M, Bang c){
   if(c[N][M]){
      if(c[N][M]==c[N-1][M]) 
         TraBang_ATM(N-1,a,M,c);
      else{
         TraBang_ATM(N,a,M-a[N],c);
         printf("%d + ",a[N]);
      }
   }
}



//CT chinh
int main(){
	int n, k;
	printf("\n Chuong trinh tinh to hop chap k cua n. ");
	printf("\n Nhap gia tri n = "); scanf("%d",&n);
	printf("\n Nhap gia tri k = "); scanf("%d",&k);
	printf("\n Gia tri to hop tinh theo vet can la %d ",Comb_VetCan(n,k));
	printf("\n Gia tri to hop tinh theo chia va tri la %d ",Comb_ChiaTri(n,k));
	printf("\n Gia tri to hop tinh theo Quy hoach dong la %d ",Comb_QHD(n,k));
	
   //2. Bai toan cai balo
   /*Cong thuc truy hoi: 
   X[1,V] = V/g1 va F[1,V] = X[1,V] * v1
   F[k,V] = Max (F[k-1,V-xk*gk] + xk*gk) voi xk = 0 den V/gk
   Sau khi tinh F[k,V] thi X[k,V] la xk ung voi 
   gia tri F[k,V] duoc chon trong cong thuc tren */
   int W;
   Bang F, X;
   DoVat DSDV[10];
   printf("\n");
   printf("\n Chuong trinh giai bai toan cai balo bang quy hoach dong.");	
   printf("\n Nhap trong luong cua balo W = "); scanf("%d", &W);
   printf("\n Nhap so loai do vat n = "); scanf("%d",&n);
   printf("\n Nhap thong tin cho cac loai do vat: \n");
   Nhap_DoVat(DSDV, n);
   // B1 - Tao bang quy hoach dong
   TaoBang_BaLo(DSDV, n, W, F, X);
   // B2 - Tra bang lay ket qua
   TraBang_BaLo(DSDV, n, W, X);
   
   //Bai toan doi tien theo quy hoach dong
   /*Y tuong Quy hoach dong:
   Dat C[i][j] la sô to tiên it nhât khi dôi j tiên su dung i mênh gia tu a1,a2… ai ta co:
   C[0][j] = vô cung (không doi duoc)
   C[i][0] = 0 // Khong can doi
   C[i][j] = C[i-1][j]: nêu j<ai thi su dung mênh gia ai vao không co tac dung gi ca
   C[i][j] = Min(C[i-1][j], 1+ C[i][j-ai]) min cua hai cach dôi môt la không su dung ai; 
   hai la co su dung ai thi sô to thêm môt va sô tiên bot di ai */
   
   int M, N, a[10];
   Bang C;
   
   printf("\n Giai bai toan doi tien bang ky thuat quy hoach dong :");
   printf("\n Nhap so tien can doi la M = "); scanf("%d",&M);
   printf("\n Nhap so loai tien can doi N = "); scanf("%d",&N);
   for (int i=1;i<=N;i++){
      printf("LoaiTien[%d]=",i); scanf("%d",&a[i]);
   }
   TaoBang_ATM(N,a,M,C);
   if(C[N][M]==M+1) 
      printf("\n Khong doi duoc");
   else{
      printf("\n So to tien it nhat la %d\n%d=",C[N][M],M);
      TraBang_ATM(N,a,M,C);
   } 
   // Ket thuc chuong trinh
	getch();
	return 0;
}

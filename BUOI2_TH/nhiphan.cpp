#include <stdio.h>
#include <conio.h>

void in(int N, int x[]){
    for (int i = 1; i <= N; i++)
        printf("%d", x[i]);
    printf("\n");
}

void deQuy(int N, int i, int x[]){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == N)
            in(N, x);
        else
            deQuy(N, i + 1, x);
    }
}

int main(){
    int N;
    int x[100];
    printf("\nNhap n=");
    scanf("%d", &N);
    deQuy(N, 1, x);
    return 0;
}

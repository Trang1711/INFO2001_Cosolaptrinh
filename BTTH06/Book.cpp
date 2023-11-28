
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char name[50];
    char namewriter[50];
    float price;
    
} B;


int main() {
    B*arr;
    int n, i;
    printf("Nhap so luong sach : ");
    scanf("%d", &n);
    // C?p ph�t b? nh? cho m?ng
    arr = (B*)malloc(n * sizeof(B));
    // Ki?m tra xem b? nh? c� du?c c?p ph�t th�nh c�ng kh�ng
    if (arr == NULL) {
        printf("Khong the cap phat bo nho.");
        exit(1);
    }
    // Nh?p gi� tr? cho m?ng
    for (i = 0; i < n; i++) {
        printf("Nhap ten sach thu %d: ", i + 1);
        fflush(stdin);
        gets(arr[i].name);
        printf("Nhap ten tac gia thu %d:", i+1);
        fflush(stdin);
        gets(arr[i].namewriter);
        printf("Nhap gia cua sach thu %d: ", i + 1);
        scanf("%f", &arr[i].price);
        
    }
    // Hi?n th? th�ng tin s�ch
    printf("\nThong tin cac sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Sach thu %d:\n", i + 1);
        printf("Ten: %s\n", arr[i].name);
        printf("Tac gia: %s\n", arr[i].namewriter);
        printf("Gia: %.2f\n", arr[i].price);
        printf("\n");
    }
    // Gi?i ph�ng b? nh? khi kh�ng c?n s? d?ng n?a
    free(arr);
    return 0;
}

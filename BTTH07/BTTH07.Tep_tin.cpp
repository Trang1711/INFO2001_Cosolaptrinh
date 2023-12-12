#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char ten[50], email[100];
    int maSV, sdt;
    float diem;
};

void themSinhVien(FILE *file) {
    struct SinhVien sv;
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(sv.ten, sizeof(sv.ten), stdin);
    printf("Nhap ma sinh vien: ");
    scanf("%d", &sv.maSV);
    printf("Nhap diem sinh vien: ");
    scanf("%f", &sv.diem);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%d", &sv.sdt);
    printf("Nhap email sinh vien: ");
    getchar();
    fgets(sv.email, sizeof(sv.email), stdin);

    // Ghi thông tin sinh vien vào tep tin
    fwrite(&sv, sizeof(sv), 1, file);
    printf("Them sinh vien thanh cong!\n");
}

void xoaSinhVien(FILE *file, int maSV) {
    struct SinhVien sv;
    FILE *tempFile = fopen("temp.dat", "wb");

    // Doc sv trong tep neu khong trung
    while (fread(&sv, sizeof(sv), 1, file) == 1) {
        if (sv.maSV != maSV) {
            fwrite(&sv, sizeof(sv), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("sinhvien.txt");
    rename("temp.dat", "sinhvien.txt");

    printf("Xoa sinh vien thanh cong!\n");
}

void capNhatSinhVien(FILE *file, int maSV) {
    struct SinhVien sv;
    int found = 0;

    while (fread(&sv, sizeof(sv), 1, file) == 1) {
        if (sv.maSV == maSV) {
            found = 1;
            printf("Nhap ten sinh vien moi: ");
            getchar();
            fgets(sv.ten, sizeof(sv.ten), stdin);

            printf("Nhap diem sinh vien moi: ");
            scanf("%f", &sv.diem);
            getchar();

            printf("Nhap so dien thoai sinh vien moi: ");
            scanf("%d", &sv.sdt);
            getchar();

            printf("Nhap email sinh vien moi: ");
            fgets(sv.email, sizeof(sv.email), stdin);

            fseek(file, -sizeof(sv), SEEK_CUR);
            fwrite(&sv, sizeof(sv), 1, file);

            printf("Cap nhat sinh vien thanh cong!\n");
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co maSV = %d\n", maSV);
    }
}

void hienThiSinhVien(FILE *file) {
    struct SinhVien sv;
    // Doc thong tin tep va hien thi
    while (fread(&sv, sizeof(sv), 1, file) == 1) {
        printf("Ten sinh vien: %s", sv.ten);
        printf("Ma sinh vien: %d\n", sv.maSV);
        printf("Diem sinh vien: %.2f\n", sv.diem);
        printf("So dien thoai sinh vien: %d\n", sv.sdt);
        printf("Email sinh vien: %s", sv.email);
        printf("--------------------------\n");
    }

    if (ftell(file) == 0) {
        printf("Danh sach sinh vien trong!\n");
    }
}

int main() {
    FILE *file = fopen("sinhvien.txt", "ab+");
    int choice, maSV;

    if (file == NULL) {
        printf("Khong the mo file sinhvien.txt\n");
        return 1;
    }

    do {
        printf("1. Them sinh vien\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Cap nhat sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getchar();  
                themSinhVien(file);
                break;
            case 2:
                printf("Nhap ma sinh vien can xoa: ");
                scanf("%d", &maSV);
                getchar(); 
                xoaSinhVien(file, maSV);
                break;
            case 3:
                printf("Nhap ma sinh vien can cap nhat: ");
                scanf("%d", &maSV);
                getchar();  
                capNhatSinhVien(file, maSV);
                break;
            case 4:
                hienThiSinhVien(file);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 5);

    fclose(file);

    return 0;
}


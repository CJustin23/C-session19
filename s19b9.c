#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char name[50];
    int age;
    char phoneNumber[15];
};

struct SinhVien danhSach[100];
int soLuongSinhVien = 0;

void hienThiDanhSach() {
    if (soLuongSinhVien == 0) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        printf("Danh sach sinh vien:\n");
        for (int i = 0; i < soLuongSinhVien; i++) {
            printf("Sinh vien %d: %s, %d tuoi, so dien thoai: %s\n", i+1, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
        }
    }
}

void themSinhVien() {
    if (soLuongSinhVien >= 100) {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    
    struct SinhVien sv;
    printf("Nhap ten sinh vien: ");
    scanf("%s", sv.name);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &sv.age);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", sv.phoneNumber);
    
    danhSach[soLuongSinhVien++] = sv;
    printf("Them sinh vien thanh cong!\n");
}

void suaThongTin() {
    int index;
    printf("Nhap chi so sinh vien can sua: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= soLuongSinhVien) {
        printf("Chi so khong hop le.\n");
        return;
    }

    printf("Nhap ten sinh vien moi: ");
    scanf("%s", danhSach[index].name);
    printf("Nhap tuoi sinh vien moi: ");
    scanf("%d", &danhSach[index].age);
    printf("Nhap so dien thoai sinh vien moi: ");
    scanf("%s", danhSach[index].phoneNumber);

    printf("Sua thong tin sinh vien thanh cong!\n");
}

void xoaSinhVien() {
    int index;
    printf("Nhap chi so sinh vien can xoa: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= soLuongSinhVien) {
        printf("Chi so khong hop le.\n");
        return;
    }

    for (int i = index; i < soLuongSinhVien - 1; i++) {
        danhSach[i] = danhSach[i + 1];
    }
    soLuongSinhVien--;
    printf("Xoa sinh vien thanh cong!\n");
}

void timKiemSinhVien() {
    char name[50];
    printf("Nhap ten sinh vien can tim: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < soLuongSinhVien; i++) {
        if (strcmp(danhSach[i].name, name) == 0) {
            printf("Sinh vien %d: %s, %d tuoi, so dien thoai: %s\n", i+1, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien.\n");
    }
}

void sapXepDanhSach() {
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = i + 1; j < soLuongSinhVien; j++) {
            if (strcmp(danhSach[i].name, danhSach[j].name) > 0) {
                struct SinhVien temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
    printf("Sap xep danh sach sinh vien thanh cong!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hienThiDanhSach();
                break;
            case 2:
                themSinhVien();
                break;
            case 3:
                suaThongTin();
                break;
            case 4:
                xoaSinhVien();
                break;
            case 5:
                timKiemSinhVien();
                break;
            case 6:
                sapXepDanhSach();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    }
}


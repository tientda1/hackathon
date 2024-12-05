#include <stdio.h>

int main() {
    int choose;
    int a, n, i;
    int arr[100];
    int check = -1;
    int count;
    int perfect[100];
    int numberPerfect = 0;
    int index, value;
    int size = 0;

    do {
        printf(
            "\n\tMENU\n"
            "1. Nhap so phan tu va gia tri cho mang\n"
            "2. In ra gia tri cac phan tu trong mang\n"
            "3. So luong cac so hoan hao co trong mang\n"
            "4. Gia tri nho thu 2 trong mang\n"
            "5. Them 1 phan tu vao vi tri ngau nhien trong mang\n"
            "6. Xoa phan tu tai vi tri cu the\n"
            "7. Sap xep mang theo thu tu tang dan\n"
            "8. Kiem tra xem phan tu co ton tai trong mang khong\n"
            "9. Thoat chuong trinh\n"
            "Lua chon: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Nhap so phan tu co trong mang: ");
                scanf("%d", &a);

                while (a <= 0) {
                    printf("Khong hop le! Moi ban nhap lai so phan tu: ");
                    scanf("%d", &a);
                }

                for (i = 0; i < a; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                size = a;
                check = 1;
                break;

            case 2:
                if (check != 1) {
                    printf("Mang hien tai chua co phan tu.\n");
                } else {
                    printf("Cac phan tu trong mang hien tai la:\n");
                    for (i = 0; i < size; i++) {
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;

            case 3:
                if (check != 1) {
                    printf("Mang hien tai chua co phan tu.\n");
                } else {
                    numberPerfect = 0;
                    for (i = 0; i < size; i++) {
                        int sum = 0;
                        for (int j = 1; j <= arr[i] / 2; j++) {
                            if (arr[i] % j == 0) {
                                sum += j;
                            }
                        }
                        if (sum == arr[i]) {
                            perfect[numberPerfect++] = arr[i];
                        }
                    }
                    if (numberPerfect == 0) {
                        printf("Khong co so hoan hao trong mang.\n");
                    } else {
                        printf("Cac so hoan hao co trong mang la: ");
                        for (i = 0; i < numberPerfect; i++) {
                            printf("%d ", perfect[i]);
                        }
                        printf("\n");
                    }
                }
                break;

            case 4:
                if (size < 2) {
                    printf("Mang can it nhat 2 phan tu!\n");
                } else {
                    int min1 = arr[0], min2 = -1;
                    for (i = 1; i < size; i++) {
                        if (arr[i] < min1) {
                            min2 = min1;
                            min1 = arr[i];
                        } else if ((arr[i] < min2 || min2 == -1) && arr[i] != min1) {
                            min2 = arr[i];
                        }
                    }
                    if (min2 == -1) {
                        printf("Mang khong co gia tri nho thu 2 khac nhau.\n");
                    } else {
                        printf("Gia tri nho thu 2 trong mang la: %d\n", min2);
                    }
                }
                break;

            case 5:
                if (check != 1) {
                    printf("Mang chua co phan tu.\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);

                    printf("Nhap vi tri can them (tu 0 den %d): ", size);
                    scanf("%d", &index);

                    if (index < 0 || index > size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (i = size; i > index; i--) {
                            arr[i] = arr[i - 1];
                        }
                        arr[index] = value;
                        size++;
                        printf("Them thanh cong.\n");
                    }
                }
                break;

            case 6:
                if (check != 1) {
                    printf("Mang chua co phan tu.\n");
                } else {
                    printf("Nhap vi tri can xoa (tu 0 den %d): ", size - 1);
                    scanf("%d", &index);

                    if (index < 0 || index >= size) {
                        printf("Vi tri khong hop le!\n");
                    } else {
                        for (i = index; i < size - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        size--;
                        printf("Xoa thanh cong.\n");
                    }
                }
                break;

            case 7:
                if (check != 1) {
                    printf("Mang chua co phan tu.\n");
                } else {
                    for (i = 0; i < size - 1; i++) {
                        for (int j = i + 1; j < size; j++) {
                            if (arr[i] > arr[j]) {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                            }
                        }
                    }
                    printf("Mang da duoc sap xep tang dan.\n");
                }
                break;

            case 8:
                if (check != 1) {
                    printf("Mang chua co phan tu.\n");
                } else {
                    int searchValue, found = 0;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &searchValue);

                    for (i = 0; i < size; i++) {
                        if (arr[i] == searchValue) {
                            printf("Gia tri %d ton tai trong mang o vi tri %d.\n", searchValue, i);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Gia tri khong ton tai trong mang.\n");
                    }
                }
                break;

            case 9:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choose != 9);

    return 0;
}


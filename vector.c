#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lichsu.h"

void menuVector2D();
void menuVector3D();

void menuVector() {
    int chon;
    do {
        system("cls");
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║                  CHẾ ĐỘ: VECTOR - PMB                ║\n");
        printf("╠══════════════════════════════════════════════════════╣\n");
        printf("║  1. Vector 2 chiều                                   ║\n");
        printf("║  2. Vector 3 chiều                                   ║\n");
        printf("║  0. Quay lại menu chính                              ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        printf("Nhập lựa chọn: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: menuVector2D(); break;
            case 2: menuVector3D(); break;
            case 0: return;
            default:
                printf(" Lựa chọn không hợp lệ!\n");
                getchar(); getchar();
        }
    } while (chon != 0);
}

/*====================== VECTOR 2D ======================*/
void menuVector2D() {
    int lc;
    double a[2], b[2], kq[2], dot, len;
    do {
        system("cls");
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║                VECTOR 2 CHIỀU - PMB                  ║\n");
        printf("╠══════════════════════════════════════════════════════╣\n");
        printf("║  1. Cộng hai vector                                  ║\n");
        printf("║  2. Trừ hai vector                                   ║\n");
        printf("║  3. Nhân vô hướng (dot product)                      ║\n");
        printf("║  4. Độ dài vector                                    ║\n");
        printf("║  0. Quay lại                                         ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        printf("Nhập lựa chọn: ");
        scanf("%d", &lc);

        if (lc == 0) return;

        if (lc == 4) {
            printf("\nNhập vector A (x y): ");
            scanf("%lf %lf", &a[0], &a[1]);
            len = sqrt(a[0]*a[0] + a[1]*a[1]);
            printf("|A| = %.3lf\n", len);
            char buf[100];
            snprintf(buf, sizeof(buf), "Vector2D: Do dai |A| = %.3lf", len);
            luuLichSu(buf);
        } else {
            printf("\nNhập vector A (x y): ");
            scanf("%lf %lf", &a[0], &a[1]);
            printf("Nhập vector B (x y): ");
            scanf("%lf %lf", &b[0], &b[1]);

            switch (lc) {
                case 1:
                    kq[0] = a[0] + b[0];
                    kq[1] = a[1] + b[1];
                    printf("A + B = (%.2lf, %.2lf)\n", kq[0], kq[1]);
                    break;
                case 2:
                    kq[0] = a[0] - b[0];
                    kq[1] = a[1] - b[1];
                    printf("A - B = (%.2lf, %.2lf)\n", kq[0], kq[1]);
                    break;
                case 3:
                    dot = a[0]*b[0] + a[1]*b[1];
                    printf("A ⋅ B = %.3lf\n", dot);
                    break;
                default: printf(" Lựa chọn không hợp lệ!\n");
            }

            char buf[150];
            snprintf(buf, sizeof(buf), "Vector2D: Thao tac %d thuc hien xong", lc);
            luuLichSu(buf);
        }
        printf("\nNhấn phím bất kỳ để tiếp tục...");
        getchar(); getchar();
    } while (lc != 0);
}

/*====================== VECTOR 3D ======================*/
void menuVector3D() {
    int lc;
    double a[3], b[3], kq[3], dot;
    do {
        system("cls");
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║                VECTOR 3 CHIỀU - PMB                  ║\n");
        printf("╠══════════════════════════════════════════════════════╣\n");
        printf("║  1. Cộng hai vector                                  ║\n");
        printf("║  2. Trừ hai vector                                   ║\n");
        printf("║  3. Nhân vô hướng (dot product)                      ║\n");
        printf("║  4. Tích có hướng (cross product)                    ║\n");
        printf("║  0. Quay lại                                         ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        printf("Nhập lựa chọn: ");
        scanf("%d", &lc);

        if (lc == 0) return;

        printf("\nNhập vector A (x y z): ");
        scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
        printf("Nhập vector B (x y z): ");
        scanf("%lf %lf %lf", &b[0], &b[1], &b[2]);

        switch (lc) {
            case 1:
                for (int i = 0; i < 3; i++) kq[i] = a[i] + b[i];
                printf("A + B = (%.2lf, %.2lf, %.2lf)\n", kq[0], kq[1], kq[2]);
                break;
            case 2:
                for (int i = 0; i < 3; i++) kq[i] = a[i] - b[i];
                printf("A - B = (%.2lf, %.2lf, %.2lf)\n", kq[0], kq[1], kq[2]);
                break;
            case 3:
                dot = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
                printf("A ⋅ B = %.3lf\n", dot);
                break;
            case 4:
                kq[0] = a[1]*b[2] - a[2]*b[1];
                kq[1] = a[2]*b[0] - a[0]*b[2];
                kq[2] = a[0]*b[1] - a[1]*b[0];
                printf("A × B = (%.2lf, %.2lf, %.2lf)\n", kq[0], kq[1], kq[2]);
                break;
            default:
                printf(" Lựa chọn không hợp lệ!\n");
        }

        char buf[150];
        snprintf(buf, sizeof(buf), "Vector3D: Thao tac %d thuc hien xong", lc);
        luuLichSu(buf);

        printf("\nNhấn phím bất kỳ để tiếp tục...");
        getchar(); getchar();
    } while (lc != 0);
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "trigonometry.h"
#include "lichsu.h"

#define PI 3.141592653589793

void menuTrigonometry() {
    int choice;
    double x, result;
    char buf[200];

    do {
        system("cls");
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║              CHẾ ĐỘ: LƯỢNG GIÁC - PMB                ║\n");
        printf("╠══════════════════════════════════════════════════════╣\n");
        printf("║  1. sin(x)                                           ║\n");
        printf("║  2. cos(x)                                           ║\n");
        printf("║  3. tan(x)                                           ║\n");
        printf("║  4. cot(x)                                           ║\n");
        printf("║  5. arcsin(x)                                        ║\n");
        printf("║  6. arccos(x)                                        ║\n");
        printf("║  7. arctan(x)                                        ║\n");
        printf("║  8. Độ  → Radian                                     ║\n");
        printf("║  9. Radian → Độ                                      ║\n");
        printf("║  0. Quay lại menu chính                              ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        printf(" Nhập lựa chọn: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9) {
            printf("Nhập giá trị x: ");
            scanf("%lf", &x);
        }

        switch (choice) {
            case 1:
                result = sin(x * PI / 180.0);
                printf("sin(%.2lf°) = %.4lf\n", x, result);
                sprintf(buf, "sin(%.2lf°) = %.4lf", x, result);
                break;
            case 2:
                result = cos(x * PI / 180.0);
                printf("cos(%.2lf°) = %.4lf\n", x, result);
                sprintf(buf, "cos(%.2lf°) = %.4lf", x, result);
                break;
            case 3:
                result = tan(x * PI / 180.0);
                printf("tan(%.2lf°) = %.4lf\n", x, result);
                sprintf(buf, "tan(%.2lf°) = %.4lf", x, result);
                break;
            case 4:
                if (tan(x * PI / 180.0) == 0) {
                    printf("cot(%.2lf°) = vô hạn (không xác định)\n", x);
                    sprintf(buf, "cot(%.2lf°) = vô hạn", x);
                } else {
                    result = 1.0 / tan(x * PI / 180.0);
                    printf("cot(%.2lf°) = %.4lf\n", x, result);
                    sprintf(buf, "cot(%.2lf°) = %.4lf", x, result);
                }
                break;
            case 5:
                if (x < -1 || x > 1) {
                    printf("Giá trị không hợp lệ cho arcsin(x)\n");
                    sprintf(buf, "arcsin(%.2lf) = lỗi", x);
                } else {
                    result = asin(x) * 180.0 / PI;
                    printf("arcsin(%.2lf) = %.4lf°\n", x, result);
                    sprintf(buf, "arcsin(%.2lf) = %.4lf°", x, result);
                }
                break;
            case 6:
                if (x < -1 || x > 1) {
                    printf("Giá trị không hợp lệ cho arccos(x)\n");
                    sprintf(buf, "arccos(%.2lf) = lỗi", x);
                } else {
                    result = acos(x) * 180.0 / PI;
                    printf("arccos(%.2lf) = %.4lf°\n", x, result);
                    sprintf(buf, "arccos(%.2lf) = %.4lf°", x, result);
                }
                break;
            case 7:
                result = atan(x) * 180.0 / PI;
                printf("arctan(%.2lf) = %.4lf°\n", x, result);
                sprintf(buf, "arctan(%.2lf) = %.4lf°", x, result);
                break;
            case 8:
                result = x * PI / 180.0;
                printf("%.4lf° = %.6lf radian\n", x, result);
                sprintf(buf, "%.4lf° = %.6lf radian", x, result);
                break;
            case 9:
                result = x * 180.0 / PI;
                printf("%.4lf radian = %.4lf°\n", x, result);
                sprintf(buf, "%.4lf radian = %.4lf°", x, result);
                break;
            case 0:
                printf("Quay lại menu chính...\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ!\n");
                sprintf(buf, "Lỗi lựa chọn menu lượng giác");
        }

        if (choice >= 1 && choice <= 9) {
            luuLichSu(buf);
            printf("\nNhấn Enter để tiếp tục...");
            getchar(); getchar();
        }

    } while (choice != 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lichsu.h"

// Hàm thực hiện phép toán cơ bản
double tinh(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 1e9; // tránh chia cho 0
        default: return 0;
    }
}

void phepTinhCoBan() {
    system("cls");
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║         CHẾ ĐỘ: MÁY TÍNH CƠ BẢN - PMB NÂNG CẤP       ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n\n");

    char expr[256];
    printf("Nhập biểu thức (VD: 2+3*4-6/2): ");
    getchar(); // xoá \n cũ
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    // Loại bỏ khoảng trắng
    char clean[256];
    int j = 0;
    for (int i = 0; expr[i]; i++)
        if (!isspace(expr[i])) clean[j++] = expr[i];
    clean[j] = '\0';

    // Mảng lưu giá trị số và toán tử
    double num[100];
    char op[100];
    int n = 0, o = 0;

    char *p = clean;
    while (*p) {
        char *end;
        double val = strtod(p, &end);
        if (p == end) {
            printf(" Lỗi: biểu thức không hợp lệ!\n");
            printf("\nNhấn phím bất kỳ để quay lại menu...");
            getchar();
            return;
        }
        num[n++] = val;
        p = end;
        if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
            op[o++] = *p;
            p++;
        } else if (*p != '\0') {
            printf(" Ký tự không hợp lệ: %c\n", *p);
            printf("\nNhấn phím bất kỳ để quay lại menu...");
            getchar();
            return;
        }
    }

    // Xử lý nhân chia trước
    for (int i = 0; i < o; i++) {
        if (op[i] == '*' || op[i] == '/') {
            num[i] = tinh(num[i], num[i+1], op[i]);
            for (int j = i+1; j < n-1; j++) num[j] = num[j+1];
            for (int j = i; j < o-1; j++) op[j] = op[j+1];
            n--; o--;
            i--;
        }
    }

    // Xử lý cộng trừ
    double kq = num[0];
    for (int i = 0; i < o; i++)
        kq = tinh(kq, num[i+1], op[i]);

    printf("\n╔══════════════════════════════════════════════════════╗\n");
    printf("  ║                    KẾT QUẢ TÍNH TOÁN                 ║\n");
    printf("  ╚══════════════════════════════════════════════════════╝\n");
    printf("Biểu thức: %s = %.6g\n", clean, kq);

    // Lưu lịch sử
    char buf[256];
    snprintf(buf, sizeof(buf), "Expr: %s = %.6g", clean, kq);
    luuLichSu(buf);

    printf("\n Kết quả đã được lưu vào lịch sử.\n");
    printf("Nhấn phím bất kỳ để quay lại menu...");
    getchar();
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "matrix.h"
#include "lichsu.h" 
#define MAXN 20
#define EPS 1e-9
static void nhapMaTran(double A[MAXN][MAXN], int *r, int *c, const char *name) {
    printf("Nhập số hàng của ma trận %s (1..%d): ", name, MAXN);
    if (scanf("%d", r) != 1) { while(getchar()!='\n'); *r = 0; return; }
    printf("Nhập số cột của ma trận %s (1..%d): ", name, MAXN);
    if (scanf("%d", c) != 1) { while(getchar()!='\n'); *c = 0; return; }
    if (*r < 1 || *r > MAXN || *c < 1 || *c > MAXN) {
        printf("Kích thước không hợp lệ.\n");
        *r = *c = 0;
        return;
    }
    printf("Nhập các phần tử (dạng số thực), theo hàng:\n");
    for (int i = 0; i < *r; ++i)
        for (int j = 0; j < *c; ++j)
            scanf("%lf", &A[i][j]);
}
static void inMaTran(double A[MAXN][MAXN], int r, int c) {
    for (int i = 0; i < r; ++i) {
        printf("| ");
        for (int j = 0; j < c; ++j) {
            printf("%10.4g ", A[i][j]);
        }
        printf("|\n");
    }
}
static void congMaTran() {
    double A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
    int ra, ca, rb, cb;
    nhapMaTran(A, &ra, &ca, "A");
    if (ra==0) return;
    nhapMaTran(B, &rb, &cb, "B");
    if (rb==0) return;
    if (ra != rb || ca != cb) {
        printf("Hai ma trận phải cùng kích thước để cộng/trừ.\n");
        return;
    }
    for (int i=0;i<ra;i++)
        for (int j=0;j<ca;j++)
            C[i][j] = A[i][j] + B[i][j];
    printf("Kết quả A + B =\n");
    inMaTran(C, ra, ca);

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: A+B (%dx%d) thực hiện", ra, ca);
    luuLichSu(buf);
}
static void truMaTran() {
    double A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
    int ra, ca, rb, cb;
    nhapMaTran(A, &ra, &ca, "A");
    if (ra==0) return;
    nhapMaTran(B, &rb, &cb, "B");
    if (rb==0) return;
    if (ra != rb || ca != cb) {
        printf("Hai ma trận phải cùng kích thước để cộng/trừ.\n");
        return;
    }
    for (int i=0;i<ra;i++)
        for (int j=0;j<ca;j++)
            C[i][j] = A[i][j] - B[i][j];
    printf("Kết quả A - B =\n");
    inMaTran(C, ra, ca);

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: A-B (%dx%d) thực hiện", ra, ca);
    luuLichSu(buf);
}
static void nhanMaTran() {
    double A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
    int ra, ca, rb, cb;
    nhapMaTran(A, &ra, &ca, "A");
    if (ra==0) return;
    nhapMaTran(B, &rb, &cb, "B");
    if (rb==0) return;
    if (ca != rb) {
        printf("Không thể nhân: số cột của A phải bằng số hàng của B.\n");
        return;
    }
    for (int i=0;i<ra;i++) for (int j=0;j<cb;j++) C[i][j]=0.0;
    for (int i=0;i<ra;i++)
        for (int j=0;j<cb;j++)
            for (int k=0;k<ca;k++)
                C[i][j] += A[i][k]*B[k][j];
    printf("Kết quả A * B =\n");
    inMaTran(C, ra, cb);

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: A*B (%dx%d x %dx%d) thực hiện", ra, ca, rb, cb);
    luuLichSu(buf);
}
static void chuyenVi() {
    double A[MAXN][MAXN], T[MAXN][MAXN];
    int r,c;
    nhapMaTran(A, &r, &c, "A");
    if (r==0) return;
    for (int i=0;i<r;i++) for (int j=0;j<c;j++) T[j][i] = A[i][j];
    printf("A^T =\n");
    inMaTran(T, c, r);

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: transpose (%dx%d) thực hiện", r, c);
    luuLichSu(buf);
}
static double detRec(double A[MAXN][MAXN], int n) {
    if (n == 1) return A[0][0];
    if (n == 2) return A[0][0]*A[1][1] - A[0][1]*A[1][0];
    double D = 0;
    double B[MAXN][MAXN];
    for (int col = 0; col < n; ++col) {
        int bi = 0;
        for (int i = 1; i < n; ++i) {
            int bj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == col) continue;
                B[bi][bj] = A[i][j];
                bj++;
            }
            bi++;
        }
        double sub = detRec(B, n-1);
        double sign = (col % 2 == 0) ? 1.0 : -1.0;
        D += sign * A[0][col] * sub;
    }
    return D;
}
static void tinhDet() {
    double A[MAXN][MAXN];
    int n, m;
    nhapMaTran(A, &n, &m, "A");
    if (n==0) return;
    if (n != m) {
        printf("Chỉ tính định thức cho ma trận vuông.\n");
        return;
    }
    if (n > 12) {
        printf("Cảnh báo: n lớn có thể chậm (n>%d). Vẫn tiếp tục? (1: có / 0: không): ", 12);
        int x; scanf("%d", &x);
        if (!x) return;
    }
    double D = detRec(A, n);
    printf("Determinant = %.6g\n", D);

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: det(%dx%d) = %.6g", n, n, D);
    luuLichSu(buf);
}
static int nghichDao(double A[MAXN][MAXN], double inv[MAXN][MAXN], int n) {
    // tạo ma trận mở rộng [A | I]
    double B[MAXN][2*MAXN];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) B[i][j] = A[i][j];
        for (int j=0;j<n;j++) B[i][n+j] = (i==j) ? 1.0 : 0.0;
    }
    for (int col=0; col<n; ++col) {
        // partial pivot
        int sel = col;
        for (int i=col; i<n; ++i)
            if (fabs(B[i][col]) > fabs(B[sel][col])) sel = i;
        if (fabs(B[sel][col]) < EPS) return 0; // không khả nghịch
        // swap
        if (sel != col)
            for (int j=0;j<2*n;j++) {
                double tmp = B[col][j]; B[col][j] = B[sel][j]; B[sel][j] = tmp;
            }
        // normalize row col
        double div = B[col][col];
        for (int j=0;j<2*n;j++) B[col][j] /= div;
        // eliminate other rows
        for (int i=0;i<n;i++) if (i!=col) {
            double factor = B[i][col];
            for (int j=0;j<2*n;j++) B[i][j] -= factor * B[col][j];
        }
    }
    // copy inverse
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) inv[i][j] = B[i][n+j];
    return 1;
}
static void tinhNghichDao() {
    double A[MAXN][MAXN], inv[MAXN][MAXN];
    int n,m;
    nhapMaTran(A, &n, &m, "A");
    if (n==0) return;
    if (n != m) {
        printf("Chỉ tính nghịch đảo cho ma trận vuông.\n");
        return;
    }
    int ok = nghichDao(A, inv, n);
    if (!ok) {
        printf("Ma trận không khả nghịch (det = 0 hoặc pivot = 0).\n");
        return;
    }
    printf("A^{-1} =\n");
    inMaTran(inv, n, n);

    char buf[256];
    snprintf(buf, sizeof(buf), "Tính ma trận nghịch đảo (%dx%d) thực hiện", n, n);
    luuLichSu(buf);
}
static void kiemTraDoiXung() {
    double A[MAXN][MAXN];
    int n,m;
    nhapMaTran(A, &n, &m, "A");
    if (n==0) return;
    if (n != m) {
        printf("Ma trận không vuông => không phải đối xứng.\n");
        return;
    }
    int ok = 1;
    for (int i=0;i<n && ok;i++)
        for (int j=0;j<n;j++)
            if (fabs(A[i][j]-A[j][i]) > 1e-8) { ok = 0; break; }
    if (ok) printf("Ma trận là đối xứng.\n"); else printf("Ma trận không đối xứng.\n");

    char buf[256];
    snprintf(buf, sizeof(buf), "Matrix: symmetric check (%dx%d) => %s", n, n, ok?"yes":"no");
    luuLichSu(buf);
}
void matrix() {
    int choice;
    do {
        system("cls");
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║                    CHẾ ĐỘ: MA TRẬN                   ║\n");
        printf("╠══════════════════════════════════════════════════════╣\n");
        printf("║ 1. Cộng hai ma trận                                  ║\n");
        printf("║ 2. Trừ hai ma trận                                   ║\n");
        printf("║ 3. Nhân hai ma trận                                  ║\n");
        printf("║ 4. Chuyển vị                                         ║\n");
        printf("║ 5. Định thức                                         ║\n");
        printf("║ 6. Nghịch đảo                                        ║\n");
        printf("║ 7. Kiểm tra đối xứng                                 ║\n");
        printf("║ 0. Quay lại menu chính                               ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        printf("Chọn (0..7): ");
        if (scanf("%d", &choice) != 1) { while(getchar()!='\n'); choice = -1; }

        switch (choice) {
            case 1: congMaTran(); break;
            case 2: truMaTran(); break;
            case 3: nhanMaTran(); break;
            case 4: chuyenVi(); break;
            case 5: tinhDet(); break;
            case 6: tinhNghichDao(); break;
            case 7: kiemTraDoiXung(); break;
            case 0: break;
            default: printf("Lựa chọn không hợp lệ!\n");
        }

        if (choice != 0) {
            printf("\nNhấn Enter để tiếp tục...");
            getchar(); getchar();
        }
    } while (choice != 0);
}

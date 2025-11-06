#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lichsu.h"

#define FILE_LICHSU "lichsu.txt"

void luuLichSu(const char *txt) {
    FILE *f = fopen(FILE_LICHSU, "a");
    if (!f) return;
    fprintf(f, "%s\n", txt);
    fclose(f);
}

void xemLichSu() {
    FILE *f = fopen(FILE_LICHSU, "r");
    if (!f) {
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║            CHƯA CÓ LỊCH SỬ TÍNH TOÁN NÀO          ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
        return;
    }

    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║                    LỊCH SỬ TÍNH TOÁN                 ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n\n");

    char buf[512];
    int empty = 1;
    while (fgets(buf, sizeof(buf), f)) {
        printf("👉 %s", buf);
        empty = 0;
    }

    if (empty)
        printf("(Trống)\n");

    printf("\n═══════════════════════════════════════════════════════\n");
    fclose(f);
}

void xoaLichSu() {
    FILE *f = fopen(FILE_LICHSU, "w");
    if (f) {
        fclose(f);
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║             ĐÃ XÓA TOÀN BỘ LỊCH SỬ TÍNH TOÁN       ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
    } else {
        printf("╔══════════════════════════════════════════════════════╗\n");
        printf("║            KHÔNG THỂ XÓA LỊCH SỬ TÍNH TOÁN         ║\n");
        printf("╚══════════════════════════════════════════════════════╝\n");
    }
}

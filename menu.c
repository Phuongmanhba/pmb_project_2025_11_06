#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "caculator.h"
#include "trigonometry.h"
#include "vector.h"
#include "matrix.h"
#include "lichsu.h"

void khungMenu()
{
    system("cls");
    printf("╔══════════════════════════════════════════════════════╗\n");
    printf("║                    MÁY TÍNH PMB - VER 2              ║\n");
    printf("║══════════════════════════════════════════════════════║\n");
    printf("║  1. Máy tính cơ bản                                  ║\n");
    printf("║  2. Lượng giác                                       ║\n");
    printf("║  3. Vector                                           ║\n");
    printf("║  4. Ma trận                                          ║\n");
    printf("║  5. Lịch sử tính toán                                ║\n");
    printf("║                                                      ║\n");
    printf("║  0. Thoát                                            ║\n");
    printf("╚══════════════════════════════════════════════════════╝\n");
}

void menuChinh()
{
    int chon;
    do
    {
        khungMenu();
        printf("\n Chọn chức năng: ");
        scanf("%d", &chon);
        system("cls");

        switch (chon)
        {
        case 1:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║                CHẾ ĐỘ: MÁY TÍNH CƠ BẢN               ║\n");
            printf("╚══════════════════════════════════════════════════════╝\n\n");
            phepTinhCoBan(); 
            break;

        case 2:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║                   CHẾ ĐỘ: LƯỢNG GIÁC                 ║\n");
            printf("╚══════════════════════════════════════════════════════╝\n\n");
            menuTrigonometry();
            break;

        case 3:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║                    CHẾ ĐỘ: VECTOR                    ║\n");
            printf("╚══════════════════════════════════════════════════════╝\n\n");
            menuVector();
            break;

        case 4:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║                    CHẾ ĐỘ: MA TRẬN                   ║\n");
            printf("╚══════════════════════════════════════════════════════╝\n\n");
            matrix();
            break;

        case 5:
            printf("╔══════════════════════════════════════════════════════╗\n");
            printf("║                 LỊCH SỬ TÍNH TOÁN                    ║\n");
            printf("╚══════════════════════════════════════════════════════╝\n\n");
            xemLichSu();
            break;

        case 0:
            printf("\nCảm ơn bạn đã dùng Máy tính PMB-Ver2 \n");
            break;

        default:
            printf("Lựa chọn không hợp lệ!\n");
        }

        if (chon != 0)
        {
            printf("\nNhấn Enter để quay lại menu...");
            getchar();
            getchar();
        }

    } while (chon != 0);
}

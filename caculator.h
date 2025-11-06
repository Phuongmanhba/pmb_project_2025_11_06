#ifndef CACULATOR_H
#define CACULATOR_H

struct PhepTinh {
    double *a;     // mảng các số
    int n;         // số lượng số
    char op;       // phép toán (+ - * /)
    double kq;     // kết quả
};
void phepTinhCoBan();
#endif

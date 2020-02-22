#include <stdio.h>

#include <stdlib.h>

//Demo bai toan Chia de tri

//De bai: tìm x^n và gia tri trung binh cua day so nguyen x1, x2,..., xm

//

int power(int x, int n) {

if (n <= 0) {

//kiem tra hop le cua n nhap vao

//...

}

//x^n cho j chay tu 1 den n roi tim x*x*....*x

int j=0;

int result=1;

for (j=0; j<n; j++) {

result = result*x;

}

return result;

}

float mean(int m) {

//ham tim trung binh cong cua m so tu nhien: result = (x1 + x2 + ... + xm)/m

//float: 4 bytes %f

//double: 8 bytes %lf

int k=0; //bien chay

int in; //bien de chua gia tri nhap vao

int total = 0; //bien de tim tong cac gia tri nhap vao

for (k=0; k<m; k++) {

printf("Moi ban nhap so thu %d:", k+1);

scanf("%d", &in);

total = total + in;

}

return 1. * total/m;

}

int main(int argc, char *argv[]) {

printf("Chuong trinh tim x^n và gia tri trung binh cua day so nguyen x1, x2,..., xm\n");

printf("Nhan phim 1 de tim x^n \n");

printf("Nhan phim 2 de tim trung binh cong cua x1, x2, ..., xm\n");

printf("Moi ban nhap lua chon: ");

int choice;

scanf("%d", &choice);

if (choice == 1) {

printf("Phan chuong trinh xu ly tim x^n\n");

printf("Moi ban nhap he so x: ");

int x = 0; //khoi tao gia tri cho bien

//vi neu khong khoi tao gia tri cho x, thi trong mot so truong hop

//gia tri se la ngau nhien

//khi ta yeu cau he thong cap phat mot bien de su dung

//thi he thong se tim trong bo nho mot memory cell con trong

//va cap phat cho bien do

//nen neu chang may o nho do (memory cell co gia tri san co)

//thi bien se nhan gia tri nay

scanf("%d", &x);

printf("Moi ban nhap so mu n: ");

int n = 0;

scanf("%d", &n);

int result = power(x, n);

printf("%d^%d = %d", x, n, result);

}

else if (choice == 2) {

printf("Phan chuong trinh xu ly tim trung binh cong cua x1, x2, .., xm\n");

printf("Moi ban nhap vao so phan tu cua day so nguyen: ");

int m = 0;

scanf("%d", &m);

float result = mean(m);

printf("Trung binh cong cua %d so nguyen nhap vao la: %f", m, result);

}

else { //con lai thi

printf("Chuong trinh chua ho tro option nay!");

}

return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//dinh nghia cau truc mot quyen sach: Book

//sau do tao mot mang nhieu phan tu, ma moi phan tu co kieu la Book,

//mang nay dat ten la Books

struct Book
{

    int BookID; //ma sach

    char Title[100]; //ten sach

    char Author[50]; //tac gia

    float Price; //gia

    int YearOfRelease; //nam xuat ban
};

void printBookInfo(struct Book b)
{

    printf("BookID: %d\n", b.BookID);

    printf("Title: %s\n", b.Title);

    printf("Author: %s\n", b.Author);

    printf("Price: %f\n", b.Price);

    printf("Year of release: %d\n", b.YearOfRelease);

    printf("-------------------------\n");
}

int main()
{

    struct Book cp; //khai bao bien cp thuoc kieu Book

    cp.BookID = 1000;

    //cp.Title = "Competitive Programming"; //wrong statement, we cannot assign array to array

    strcpy(cp.Title, "Competitive Programming");

    strcpy(cp.Author, "Halim");

    cp.Price = 12.5;

    cp.YearOfRelease = 2006;

    printBookInfo(cp);
}
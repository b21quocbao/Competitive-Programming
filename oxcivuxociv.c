#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <stdbool.h>

#include <time.h>

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

struct Book lstBooks[10000]; //array include 10000 Books

//chuyen lstBooks la mot global variable: bien toan cuc

//de su dung chung cho toan chuong trinh (chia se giua cac functions voi nhau)

int maxBook = 0; //bien luu tru so sach hien co

int startBookIndex = 10000; //chi so BookID bat dau tu con so nay

#define MAX_NUMBER_TITLES 1000

#define MAX_NUMBER_AUTHORS 1000

#define MAX_LENGTH_OF_TITLE 100

#define MAX_LENGTH_OF_AUTHOR 50

char lstTitles[MAX_NUMBER_TITLES][MAX_LENGTH_OF_TITLE];

char lstAuthors[MAX_NUMBER_AUTHORS][MAX_LENGTH_OF_AUTHOR];

//doan tren ta dang khai bao mang 2 chieu luu tru danh sach

//cac tieu de

//va cac tac gia

//de sinh du lieu ngau nhien

void printBookInfo(struct Book b)
{

    printf("BookID: %d\n", b.BookID);

    printf("Title: %s\n", b.Title);

    printf("Author: %s\n", b.Author);

    printf("Price: %f\n", b.Price);

    printf("Year of release: %d\n", b.YearOfRelease);

    printf("-------------------------\n");
}

// int random0_Upper(int upper);
// int randomLower_Upper(int lower, int upper);

void inputBookInfo()
{

    lstBooks[maxBook].BookID = startBookIndex + maxBook;

    strcpy(lstBooks[maxBook].Title, lstTitles[random0_Upper(11)]);

    strcpy(lstBooks[maxBook].Author, lstAuthors[random0_Upper(11)]);

    lstBooks[maxBook].Price = random0_Upper(50);

    lstBooks[maxBook].YearOfRelease = randomLower_Upper(1980, 2020);

    maxBook++; //moi lan them mot quyen sach thi tang chi so maxBook len 1 don vi
}

bool isCallSRand = false;

int random()
{

    if (isCallSRand != true)
    {

        srand(time(NULL)); // Initialization, should only be called once.

        isCallSRand = true;
    }

    int r = rand(); // Returns a pseudo-random integer between 0 and RAND_MAX.

    return r;
}

int random0_Upper(int upper)
{

    return (random() % (upper + 1));
}

int randomLower_Upper(int lower, int upper)
{

    //lower: can duoi cua dai so nguye

    //upper: can tran cua dai so nguyen

    int r = (random() % (upper - lower + 1)) + lower;

    return r;
}

//ham sinh so nguyen ngau nhien co rat nhieu ung dung trong thuc te

//nhu he thong generatedata.com gioi thieu trong buoi truoc

//thi no lay cac phan tu ngau nhien trong cac mang: Title[], Author[], Price, Email, City, Nation, Department,...

//roi ket hop lai thi thanh cac bo du lieu ngau nhien

//hoac la nhu hien tai khi thi cuoi ki, thi ben Khao thi se sinh ngau nhien

//mot bo 60 so nguyen, tuong ung voi no se la cau hoi nao trong QB de

//sinh thanh de thi FE

//sau do khi sv lam bai, thi lai sinh ngau nhien

//trat tu cac cau hoi, va trat tu cac phuong an tra loi

//de thanh nhieu de (tranh viec quay copy, trao doi, giup do nhau lam bai trong phong thi)

void initData()
{

    //khoi tao du lieu cho 2 mang ke tren

    strcpy(lstTitles[0], "C Programming Language");

    strcpy(lstTitles[1], "The C Programming Language 2nd Edition");

    strcpy(lstTitles[2], "C Programming: A Modern Approach, 2nd Edition 2nd Edition");

    strcpy(lstTitles[3], "Expert C Programming: Deep Secrets 1st Edition, Kindle Edition");

    strcpy(lstTitles[4], "C: The Complete Reference, 4th Ed. 4th Edition");

    strcpy(lstTitles[5], "Head First C 1/e Edition");

    strcpy(lstTitles[6], "Computer Fundamentals and Programming in C");

    strcpy(lstTitles[7], "Low-Level Programming: C, Assembly, and Program Execution");

    strcpy(lstTitles[8], "C in a Nutshell: The Definitive Reference 2nd Edition");

    strcpy(lstTitles[9], "Hands-on Network Programming with C: Learn socket programming in C and write secure and optimized network code");

    strcpy(lstTitles[10], "Data Structures Using C 2nd Edition");

    strcpy(lstAuthors[0], "James Gosling");

    strcpy(lstAuthors[1], "Peter Norton");

    strcpy(lstAuthors[2], "Marry Curry");

    strcpy(lstAuthors[3], "Tony Crawford");

    strcpy(lstAuthors[4], "Igor Zhirkov");

    strcpy(lstAuthors[5], "Peter Van der Linden");

    strcpy(lstAuthors[6], "Kernighan");

    strcpy(lstAuthors[7], "Adam Riches");

    strcpy(lstAuthors[8], "Dennis Ritchie");

    strcpy(lstAuthors[9], "Jonathan Payne");

    strcpy(lstAuthors[10], "John Smith");
}

int main(int argc, char *argv[])
{

    // struct Book cp; //khai bao bien cp thuoc kieu Book

    // cp.BookID = 1000;

    // //cp.Title = "Competitive Programming"; //wrong statement, we cannot assign array to array

    // strcpy(cp.Title, "Competitive Programming");

    // strcpy(cp.Author, "Halim");

    // cp.Price = 12.5;

    // cp.YearOfRelease = 2006;

    //

    // printBookInfo(cp);

    int j = 0;

    // for (j=0; j<10; j++)

    // printf("%d\n", randomLower_Upper(1000,2000));

    initData();

    for (j = 0; j < 10; j++)

        inputBookInfo();

    for (j = 0; j < 10; j++)

        printBookInfo(lstBooks[j]);

    //http://generatedata.com/

    return 0;
}
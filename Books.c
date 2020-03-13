#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Book;
typedef struct Book
{
    int BookID;
    char Title[100];
    char Author[50];
    float Price;
    int YearOfRelease;
} Book;
Book Books[1010];
int numBooks;

void printBookInfo(Book b)
{
    printf("BookID: %d\n", b.BookID);
    printf("Title: %s\n", b.Title);
    printf("Author: %s\n", b.Author);
    printf("Price: %f\n", b.Price);
    printf("Year of release: %d\n", b.YearOfRelease);
    printf("-------------------------\n");
}

void addBook(char t[100], char a[50], float p, int y)
{
    ++numBooks;
    Books[numBooks].BookID = numBooks;
    strncpy(Books[numBooks].Title, t, strlen(t));
    strncpy(Books[numBooks].Author, a, strlen(a));
    Books[numBooks].Price = p;
    Books[numBooks].YearOfRelease = y;
}

void initBooks()
{
    addBook("In an Instant", "Suzanne Redfearn", 4.99, 2020);
    addBook("Goodnight Moon", "Margaret Wise Brown", 7.59, 2007);
    addBook("Special Circumstances: Mike Daley/Rosie Fernandez Legal Thriller, Book 1", "Sheldon Siegel", 3.99, 2017);
    addBook("When We Believed in Mermaids: A Novel", "Barbara O'Neal", 1.99, 2019);
    addBook("Talking to Strangers: What We Should Know About the People We Don't Know", "Malcolm Gladwell", 15.29, 2019);
    addBook("The Fellowship of the Ring: Book One in The Lord of the Rings Trilogy", "J. R. R. Tolkien", 9.29, 2012);
    addBook("Girl, Stop Apologizing: A Shame-Free Plan for Embracing and Achieving Your Goals (Girl, Wash Your Face Book 2)", "Rachel", 11.4, 2019);
    addBook("The Last Sister (Columbia River Book 1)", "Kendra Elliot", 5.99, 2020);
    addBook("Can't Hurt Me: Master Your Mind and Defy the Odds", "David Goggins", 7.99, 2018);
    addBook("Never Split the Difference: Negotiating as if Your Life Depended on It", "Chris Voss", 8.44, 2016);
}

void findBooksbyTitle(char c[])
{
    int i;
    for (i = 0; i < numBooks; ++i)
    {
        if (strlen(Books[i].Title) < strlen(c))
            continue;
        bool ok = 1;
        int j;
        for (j = 0; j < strlen(c); ++ j)
        if (c[j] != Books[i].Title[j]) ok = 0;
        if (ok) printBookInfo(Books[i]);
    }
}

void findBooksbyPrice(float p)
{
    int i;
    for (i = 0; i < numBooks; ++i)
    {
        if (Books[i].Price < p)
            printBookInfo(Books[i]);
    }
}

void findBooksbyTitleandPrice(char c[], float p)
{
    int i;
    for (i = 0; i < numBooks; ++i)
    {
        if (strlen(Books[i].Title) < strlen(c))
            continue;
        bool ok = 1;
        int j;
        for (j = 0; j < strlen(c); ++ j)
        if (c[j] != Books[i].Title[j]) ok = false;
        if (ok == 1 && Books[i].Price < p) printBookInfo(Books[i]);
    }
}

bool Trim(char* s) {
    char* c = malloc(110 * sizeof (char));
    int n = 0, i = 0;
    for (i = 0; i < strlen(s); ++ i) {
        if (!isalpha(s[i]) && !isspace(s[i])) return 0;
        if (n && c[n - 1] == ' ') {
            if (isspace(s[i])) continue;
            else c[n ++] = toupper(s[i]);
        } else if (isspace(s[i])) c[n ++] = s[i];
        else if (!n) c[n ++] = toupper(s[i]);
        else c[n ++] = tolower(s[i]);
    }
    for (i = 0; i < n; ++ i)
    s[i] = c[i];
    s[n] = '\0';
    return 1;
}

void Process (int ch) {
    system("cls");
    if (ch == 1) {
        numBooks = 0;
        initBooks();
    }
    else if (ch == 2) {
        char s[110], t[110], Pr[110], Y[110];
        float pr = 0;
        int y = 0;
        while (1) {
            printf("Nhap vao ten sach:\n");
            fflush(stdin);
            gets(s);
            if (Trim(s)) break;
            printf("Nhap sai cu phap\n");
        }
        while (1) {
            printf("Nhap vao ten tac gia:\n");
            fflush(stdin);
            gets(t);
            if (Trim(t)) break;
            printf("Nhap sai cu phap\n");
        }
        while (1) {
            printf("Nhap gia tien:\n");
            fflush(stdin);
            gets(Pr);
            int i;
            bool val = 1;
            int cn = 0;
            for (i = 0; i < strlen(Pr); ++ i)
            if (Pr[i] == '.') ++ cn;
            else if (!isdigit(Pr[i])) val = 0;
            if (val && cn <= 1 && Pr[0] != '.') {
                pr = atof(Pr);
                break;
            }
            printf("Nhap sai cu phap\n");
        }
        while (1) {
            printf("Nhap nam:\n");
            fflush(stdin);
            gets(Y);
            int i;
            bool val = 1;
            for (i = 0; i < strlen(Y); ++ i)
            if (!isdigit(Y[i])) val = 0;
            if (val) {
                y = atoi(Y);
                break;
            }
            printf("Nhap sai cu phap\n");
        }
        addBook(s, t, pr, y);
    } else if (ch == 3) {
        char s[110];
        while (1) {
            printf("Nhap vao ten sach:\n");
            fflush(stdin);
            gets(s);
            if (Trim(s)) break;
            printf("Nhap sai cu phap\n");
        }
        findBooksbyTitle(s);
    } else if (ch == 4) {
        char Pr[110];
        float pr;
        while (1) {
            printf("Nhap gia tien:\n");
            fflush(stdin);
            gets(Pr);
            int i;
            bool val = 1;
            int cn = 0;
            for (i = 0; i < strlen(Pr); ++ i)
            if (Pr[i] == '.') ++ cn;
            else if (!isdigit(Pr[i])) val = 0;
            if (val && cn <= 1 && Pr[0] != '.') {
                pr = atof(Pr);
                break;
            }
            printf("Nhap sai cu phap\n");
        }
        findBooksbyPrice(pr);
        
    } else if (ch == 5) {
        int i;
        float s = 0;
        for (i = 1; i <= numBooks; ++ i)
        s += Books[i].Price;
        printf("Gia tien trung binh la %f\n", s / numBooks);
        
    } else if (ch == 6) {
        char Pr[110], s[110];
        float pr;
        while (1) {
            printf("Nhap vao ten sach:\n");
            fflush(stdin);
            gets(s);
            if (Trim(s)) break;
            printf("Nhap sai cu phap\n");
        }
        while (1) {
            printf("Nhap gia tien:\n");
            fflush(stdin);
            gets(Pr);
            int i;
            bool val = 1;
            int cn = 0;
            for (i = 0; i < strlen(Pr); ++ i)
            if (Pr[i] == '.') ++ cn;
            else if (!isdigit(Pr[i])) val = 0;
            if (val && cn <= 1 && Pr[0] != '.') {
                pr = atof(Pr);
                break;
            }
            printf("Nhap sai cu phap\n");
        }
        findBooksbyTitleandPrice(s, pr);
    } else {
        int i;
        for (i = 1; i <= numBooks; ++ i)
        printBookInfo(Books[i]);
    }
    printf("Action complete\n");
    printf("Press enter to continue:\n");
    getch();
}

char ch[100];

int main(int argc, char const *argv[])
{
    while (1) {
        system("cls");
        printf("1. Khoi tao danh sach gom 10 quyen sach ngau nhien\n");
        printf("2. Nhap them 1 quyen sach moi\n");
        printf("3. Tim kiem theo ten sach\n");
        printf("4. Tim kiem theo gia tien cua quyen sach\n");
        printf("5. In ra gia trung binh cua cac quyen sach dang co\n");
        printf("6. Tim kiem theo ten sach va gia tien cua quyen sach\n");
        printf("7. In ra tat ca cac quyen sach hien co\n");
        printf("Ban hay nhap vao so nguyen co gia tri tu 1-6 hoac nhap q de thoat khoi chuong trinh: ");
        scanf("%s", ch);
        if (strlen(ch) == 1 && ch[0] >= '1' && ch[0] <= '7') {
            Process (ch[0] - '0');
        } else if (strlen(ch) == 1 && ch[0] == 'q') break;
        else continue;
    }
    return 0;
}

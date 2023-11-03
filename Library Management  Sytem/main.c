#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>
#define RETURNTIME 15
char catagories[][15] = {"Computer", "Electronics", "Electrical", "Civil", "Mechnnical", "Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int getdata();
int checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();
FILE *fp, *ft, *fs;
COORD coord = {0, 0};
int s;
char findbook;
char password[10] = {"saikot"};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct meroDate
{
    int mm, dd, yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int main()
{
    Password();
    getch();
    return 0;
}
void mainmenu()
{
    system("cls");
    int i;
  printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    printf("\n\t\tMAIN MENU\t\t");
    printf("\n\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    printf("\n\t1. Add Books   ");
    printf("\n\t2. Delete books");
    printf("\n\t3. Search Books");
    printf("\n\t4. Issue Books");
    printf("\n\t5. View Book list");
    printf("\n\t6. Edit Book's Record");
    printf("\n\t7. Close Application");
     printf("\n\n");
    t();
    printf("Enter your choice:");
   
    switch (getch())
    {
    case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
    case '3':
        searchbooks();
        break;
    case '4':
        issuebooks();
        break;
    case '5':
        viewbooks();
        break;
    case '6':
        editbooks();
        break;
    case '7':
    {
        system("cls");
        printf("\tLibrary Management System");
        printf("\tMini Project in C");
        printf("******************************************");
        printf("*******************************************");
        printf("*******************************************");
        printf("********************************************");
        printf("Exiting in 3 second...........>");
        Sleep(3000);
        exit(0);
    }
    default:
    {
        printf("\aWrong Entry!!Please re-entered correct option");
        if (getch())
            mainmenu();
    }
    }
}
void addbooks(void)
{
    system("cls");
    int i;
    printf("\t\t\t+-+-+-+-+-+-+-+-+");
    printf("\n\t\t\tSELECT CATEGOIES");
    printf("\n\t\t\t+-+-+-+-+-+-+-+-+");
    printf("\n\t  1. Computer");
    printf("\n\t  2. Electronics");
    printf("\n\t  3. Electrical");
    printf("\n\t  4. Civil");
    printf("\n\t  5. Mechanical");
    printf("\n\t  6. Architecture");
    printf("\n\t  7. Back to main menu");
    printf("\n");
    printf("\n\tEnter your choice:");
    scanf("%d", &s);
    if (s == 7)
        mainmenu();
    system("cls");
    fp = fopen("Bibek.dat", "ab+");
    if (getdata() == 1)
    {
        a.cat = catagories[s - 1];
        fseek(fp, 0, SEEK_END);
        fwrite(&a, sizeof(a), 1, fp);
        fclose(fp);
        printf("\n\t The record is sucessfully saved");
        printf("\n\t Save any more?(Y / N):");
        if (getch() == 'n')
            mainmenu();
        else
            system("cls");
        addbooks();
    }
}
void deletebooks()
{
    system("cls");
    int d;
    char another = 'y';
    while (another == 'y')
    {
        system("cls");

        printf("\n\t Enter the Book ID to  delete:");
        scanf("%d", &d);
        fp = fopen("Bibek.dat", "rb+");
        rewind(fp);
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                printf("\n\t The book record is available");
                printf("\n\t Book name is %s", a.name);
                printf("\n\t Rack No. is %d", a.rackno);
                findbook = 't';
            }
        }
        if (findbook != 't')
        {
            gotoxy(10, 10);
            printf("\n\t No record is found modify the search");
            if (getch())
                mainmenu();
        }
        if (findbook == 't')
        {
            printf("\n\t Do you want to delete it?(Y/N):");
            if (getch() == 'y')
            {
                ft = fopen("test.dat", "wb+");
                rewind(fp);
                while (fread(&a, sizeof(a), 1, fp) == 1)
                {
                    if (a.id != d)
                    {
                        fseek(ft, 0, SEEK_CUR);
                        fwrite(&a, sizeof(a), 1, ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("Bibek.dat");
                rename("test.dat", "Bibek.dat");
                fp = fopen("Bibek.dat", "rb+");
                if (findbook == 't')
                {
                    printf("\n\t The record is sucessfully deleted");
                    printf("\n\t Delete another record?(Y/N)");
                }
            }
            else
                mainmenu();
            fflush(stdin);
            another = getch();
        }
    }
    mainmenu();
}
void searchbooks()
{
    system("cls");
    int d;
    printf("*****************************Search Books*********************************");
    printf("\n\t  1. Search By ID");
    printf("\n\t 2. Search By Name");
    printf("\n\t Enter Your Choice");
    fp = fopen("Bibek.dat", "rb+");
    rewind(fp);
    switch (getch())
    {
    case '1':
    {
        system("cls");
        printf("\n\t ****Search Books By Id****");
        printf("\n\t Enter the book id:");
        scanf("%d", &d);
        printf("\n\t Searching........");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (a.id == d)
            {
                Sleep(2);
                printf("\n\t The Book is available");
                printf("\n\t ID:%d", a.id);
                printf("\n\t  Name:%s", a.name);
                printf("\n\t Author:%s ", a.Author);
                printf("\n\t  Qantity:%d ", a.quantity);
                printf("\xB2");
                printf("\n\t  Price:Rs.%.2f", a.Price);
                printf("\xB2");
                printf("\n\t  Rack No:%d ", a.rackno);
                printf("\xB2");
                findbook = 't';
            }
        }
        if (findbook != 't')
        {
            printf("\n\t ");
            printf("\a\n\t No Record Found");
        }
        printf("\n\t Try another search?(Y/N)");
        if (getch() == 'y')
            searchbooks();
        else
            mainmenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        printf("\n\t ****Search Books By Name****");
        printf("\n\t Enter Book Name:");
        scanf("%s", s);
        int d = 0;
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (strcmp(a.name, (s)) == 0)
            {
                printf("\n\t The Book is available");
                printf("\n\t  ID:%d", a.id);
                printf("\n\t ");
                printf("\n\t Name:%s", a.name);
                printf("\n\t");
                printf("\n\t Author:%s", a.Author);
                printf("\n\t");
                printf("\n\t Qantity:%d", a.quantity);
                printf("\n\t");
                printf("\n\t Price:Rs.%.2f", a.Price);
                printf("\n\t");
                printf("\n\t Rack No:%d ", a.rackno);
                printf("\n\t");
                d++;
            }
        }
        if (d == 0)
        {
            printf("\n\t");
            printf("\n\t");
            printf("\a\n\tNo Record Found");
        }
        printf("\n\tTry another search?(Y/N)");
        if (getch() == 'y')
            searchbooks();
        else
            mainmenu();
        break;
    }
    default:
        getch();
        searchbooks();
    }
    fclose(fp);
}
void issuebooks(void)
{
    int t;
    system("cls");
    printf("\n\t********************************ISSUE SECTION**************************");
    printf("\n\t 1. Issue a Book");
    printf("\n\t 2. View Issued Book");
    printf("\n\t 3. Search Issued Book");
    printf("\n\t 4. Remove Issued Book");
    printf("\n\tEnter a Choice:");
    switch (getch())
    {
    case '1':
    {
        system("cls");
        int c = 0;
        char another = 'y';
        while (another == 'y')
        {
            system("cls");
            printf("\n\t***Issue Book section***");
            printf("\n\tEnter the Book Id:");
            scanf("%d", &t);
            fp = fopen("Bibek.dat", "rb");
            fs = fopen("Issue.dat", "ab+");
            if (checkid(t) == 0)
            {
                printf("\n\tThe book record is available");
                printf("\n\tThere are %d unissued books in library ", a.quantity);
                printf("\n\tThe name of book is %s", a.name);
                printf("\n\tEnter student name:");
                scanf("%s", a.stname);
                printf("\n\tIssued date=%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
                printf("The BOOK of ID %d is issued", a.id);
                a.duedate.dd = a.issued.dd + RETURNTIME;
                a.duedate.mm = a.issued.mm;
                a.duedate.yy = a.issued.yy;
                if (a.duedate.dd > 30)
                {
                    a.duedate.mm += a.duedate.dd / 30;
                    a.duedate.dd -= 30;
                }
                if (a.duedate.mm > 12)
                {
                    a.duedate.yy += a.duedate.mm / 12;
                    a.duedate.mm -= 12;
                }
                printf("\n\tTo be return:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
                fseek(fs, sizeof(a), SEEK_END);
                fwrite(&a, sizeof(a), 1, fs);
                fclose(fs);
                c = 1;
            }
            if (c == 0)
            {
                printf("\n\tNo record found");
            }

            printf("\n\tIssue any more(Y/N):");
            fflush(stdin);
            another = getche();
            fclose(fp);
        }
        break;
    }
    case '2':
    {
        system("cls");
        int j = 4;
        printf("\n\t*******************************Issued book list*******************************\n");
        printf("\n\tSTUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
        fs = fopen("Issue.dat", "rb");
        while (fread(&a, sizeof(a), 1, fs) == 1)
        {
            printf("\n\t%s", a.stname);
            printf("\n\t%s", a.cat);
            printf("\n\t%d", a.id);
            printf("\n\t%s", a.name);
            printf("\n\t%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
            printf("\n\t%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
            j++;
        }
        fclose(fs);
        gotoxy(1, 25);
        returnfunc();
    }
    break;
    case '3':
    {
        system("cls");
        printf("\n\tEnter Book ID:");
        int p, c = 0;
        char another = 'y';
        while (another == 'y')
        {
            scanf("%d", &p);
            fs = fopen("Issue.dat", "rb");
            while (fread(&a, sizeof(a), 1, fs) == 1)
            {
                if (a.id == p)
                {
                    issuerecord();
                    gotoxy(10, 12);
                    printf("Press any key.......");
                    getch();
                    issuerecord();
                    c = 1;
                }
            }
            fflush(stdin);
            fclose(fs);
            if (c == 0)
            {
                printf("\n\tNo Record Found");
            }
            printf("\n\tTry Another Search?(Y/N)");
            another = getch();
        }
    }
    break;
    case '4':
    {
        system("cls");
        int b;
        FILE *fg;
        char another = 'y';
        while (another == 'y')
        {
            printf("\n\tEnter book id to remove:");
            scanf("%d", &b);
            fs = fopen("Issue.dat", "rb+");
            while (fread(&a, sizeof(a), 1, fs) == 1)
            {
                if (a.id == b)
                {
                    issuerecord();
                    findbook = 't';
                }
                if (findbook == 't')
                {
                    printf("\n\tDo You Want to Remove it?(Y/N)");
                    if (getch() == 'y')
                    {
                        fg = fopen("record.dat", "wb+");
                        rewind(fs);
                        while (fread(&a, sizeof(a), 1, fs) == 1)
                        {
                            if (a.id != b)
                            {
                                fseek(fs, 0, SEEK_CUR);
                                fwrite(&a, sizeof(a), 1, fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.dat");
                        rename("record.dat", "Issue.dat");
                        printf("\n\tThe issued book is removed from list");
                    }
                }
                if (findbook != 't')
                {
                    printf("\n\tNo Record Found");
                }
            }
            printf("\n\tDelete any more?(Y/N)");
            another = getch();
        }
    }
    default:
        gotoxy(10, 18);
        printf("\aWrong Entry!!");
        getch();
        issuebooks();
        break;
    }
    printf("\n\t");
    returnfunc();
}
void viewbooks(void)
{
    int i = 0, j;
    system("cls");
    printf("\n\t*********************************Book List*****************************");
    printf(" \n\tCATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j = 4;
    fp = fopen("Bibek.dat", "rb");
    while (fread(&a, sizeof(a), 1, fp) == 1)
    {
        printf("\n\t%s", a.cat);
        printf("\n\t%d", a.id);
        printf("\n\t%s", a.name);
        printf("\n\t%s", a.Author);
        printf("\n\t%d", a.quantity);
        printf("\n\t%.2f", a.Price);
        printf("\n\t%d", a.rackno);
        printf("\n\n");
        j++;
        i = i + a.quantity;
    }
    printf("\n\tTotal Books =%d", i);
    fclose(fp);
    printf("\n\t");
    returnfunc();
}
void editbooks(void)
{
    system("cls");
    int c = 0;
    int d, e;
    printf("\n\t****Edit Books Section****");
    char another = 'y';
    while (another == 'y')
    {
        system("cls");
        printf("\n\tEnter Book Id to be edited:");
        scanf("%d", &d);
        fp = fopen("Bibek.dat", "rb+");
        while (fread(&a, sizeof(a), 1, fp) == 1)
        {
            if (checkid(d) == 0)
            {
                printf("\n\tThe book is availble");
                printf("\n\tThe Book ID:%d", a.id);
                printf("\n\tEnter new name:");
                scanf("%s", a.name);
                printf("\n\tEnter new Author:");
                scanf("%s", a.Author);
                printf("\n\tEnter new quantity:");
                scanf("%d", &a.quantity);
                printf("\n\tEnter new price:");
                scanf("%f", &a.Price);
                printf("\n\tEnter new rackno:");
                scanf("%d", &a.rackno);
                printf("\n\tThe record is modified");
                fseek(fp, ftell(fp) - sizeof(a), 0);
                fwrite(&a, sizeof(a), 1, fp);
                fclose(fp);
                c = 1;
            }
            if (c == 0)
            {
                printf("\n\tNo record found");
            }
        }
        printf("\n\tModify another Record?(Y/N)");
        fflush(stdin);
        another = getch();
    }
    returnfunc();
}
void returnfunc(void)
{
    {
        printf("\n\tPress ENTER to return to main menu");
    }
a:
    if (getch() == 13)
        mainmenu();
    else
        goto a;
}
int getdata()
{
    int t;
    printf("\n\tEnter the Information Below");
    printf("\n\tCategory:");
    printf("%s", catagories[s - 1]);
    printf("\n\tBook ID:\t");
    scanf("\n\t%d", &t);
    if (checkid(t) == 0)
    {
        printf("\a\n\tThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id = t;
    printf("\n\tBook Name:");
    scanf("%s", a.name);
    printf("\n\tAuthor:");
    scanf("%s", a.Author);
    printf("\n\tQuantity:");
    scanf("%d", &a.quantity);
    printf("\n\tPrice:");
    scanf("%f", &a.Price);
    printf("\n\tRack No:");
    scanf("%d", &a.rackno);
    return 1;
}
int checkid(int t)
{
    rewind(fp);
    while (fread(&a, sizeof(a), 1, fp) == 1)
        if (a.id == t)
            return 0;
    return 1;
}
int t(void)
{
    time_t t;
    time(&t);
    printf("\n\tDate and time:%s\n", ctime(&t));

    return 0;
}
void Password(void)
{
    mainmenu();
}
void issuerecord()
{
    system("cls");
    printf("\n\tThe Book has taken by Mr. %s", a.stname);
    printf("\n\tIssued Date:%d-%d-%d", a.issued.dd, a.issued.mm, a.issued.yy);
    printf("\n\tReturning Date:%d-%d-%d", a.duedate.dd, a.duedate.mm, a.duedate.yy);
}

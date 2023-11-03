#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Function Declarations
void returnfunc();
void mainmenu();
void addbooks();
void deletebooks();
void editbooks();
void searchbooks();
void issuebooks();
void viewbooks();
void closeapplication();
int getdata();
int checkid(int);
int t();
void Password();
void issuerecord();
void loaderanim();
void gotoxy(int x, int y);

// Global Variables
COORD coord = {0, 0};
int s;
char findbook;
string password = "saikot";

// Date Structure
class meroDate
{
public:
    int mm, dd, yy;
};

// Book Structure
class books
{
public:
    int id;
    string stname;
    string catagories;
    string name;
    string author;
    int quantity;
    float price;
    int count;
    int rackno;
    string cat;
    meroDate issued;
    meroDate duedate;
};

books book;
fstream fp, ft, fs;

// Function to set the position of cursor in console
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to display the main menu
void mainmenu()
{
    system("cls");
    int i;
    gotoxy(20, 3);
    cout << "******* MAIN MENU *******" << endl;
    gotoxy(20, 5);
    cout << "1. Add Books" << endl;
    gotoxy(20, 7);
    cout << "2. Delete Books" << endl;
    gotoxy(20, 9);
    cout << "3. Search Books" << endl;
    gotoxy(20, 11);
    cout << "4. Issue Books" << endl;
    gotoxy(20, 13);
    cout << "5. View Book list" << endl;
    gotoxy(20, 15);
    cout << "6. Edit Book's Record" << endl;
    gotoxy(20, 17);
    cout << "7. Close Application" << endl;
    gotoxy(20, 19);
    cout << "*******************" << endl;
    gotoxy(20, 20);
    t();
    gotoxy(20, 21);
    cout << "Enter your choice: ";
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
            gotoxy(16, 3);
            cout << "\tLibrary Management System" << endl;
            gotoxy(16, 4);
            cout << "\tMini Project in C++" << endl;
            gotoxy(16, 5);
            cout << "**************" << endl;
            gotoxy(16, 10);
            cout << "***************" << endl;
            gotoxy(16, 11);
            cout << "***************" << endl;
            gotoxy(16, 13);
            cout << "****************" << endl;
            gotoxy(10, 17);
            cout << "Exiting in 3 seconds...>";
            Sleep(3000);
            exit(0);
        }
        break;
    default:
        {
            gotoxy(10, 23);
            cout << "\aWrong Entry!! Please re-enter the correct option" << endl;
            if (getch())
                mainmenu();
        }
    }
}

// Function to add books
void addbooks()
{
    system("cls");
    int i;
    gotoxy(20, 5);
    cout << "SELECT CATEGORIES" << endl;
    gotoxy(20, 7);
    cout << "1. Computer" << endl;
    gotoxy(20, 9);
    cout << "2. Electronics" << endl;
    gotoxy(20, 11);
    cout << "3. Electrical" << endl;
    gotoxy(20, 13);
    cout << "4. Civil" << endl;
    gotoxy(20, 15);
    cout << "5. Mechanical" << endl;
    gotoxy(20, 17);
    cout << "6. Architecture" << endl;
    gotoxy(20, 19);
    cout << "7. Back to Main Menu" << endl;
    gotoxy(20, 21);
    cout << "Enter your choice: ";
    cin >> s;
    if (s == 7)
        mainmenu();
    system("cls");
    fp.open("book.dat", ios::in | ios::out | ios::app);
    int found = 0;
    while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
    {
        if (book.id == t())
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        gotoxy(20, 5);
        cout << "The book id already exists" << endl;
        getch();
        mainmenu();
        return;
    }
    string catagories;
    book.cat =  catagories[s - 1];
    gotoxy(20, 4);
    cout << "Enter the Book ID: ";
    cin >> book.id;
    gotoxy(20, 6);
    cout << "Enter the Book Name: ";
    cin.ignore();
    getline(cin, book.name);
    gotoxy(20, 8);
    cout << "Enter the Author's Name: ";
    getline(cin, book.author);
    gotoxy(20, 10);
    cout << "Enter the Price of the Book: ";
    cin >> book.price;
    gotoxy(20, 12);
    cout << "Enter the Quantity: ";
    cin >> book.quantity;
    gotoxy(20, 14);
    cout << "Enter the Rack No: ";
    cin >> book.rackno;
    fp.write(reinterpret_cast<char *>(&book), sizeof(books));
    gotoxy(20, 16);
    cout << "The book has been successfully added" << endl;
    fp.close();
    getch();
    mainmenu();
}

// Function to delete books
void deletebooks()
{
    system("cls");
    int d;
    gotoxy(10, 5);
    cout << "Delete Books" << endl;
    gotoxy(10, 7);
    cout << "Enter the Book ID to delete: ";
    cin >> d;
    fp.open("book.dat", ios::in | ios::out);
    ft.open("Temp.dat", ios::out);
    while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
    {
        if (book.id != d)
        {
            ft.write(reinterpret_cast<char *>(&book), sizeof(books));
        }
    }
    ft.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    gotoxy(10, 10);
    cout << "The book has been successfully deleted" << endl;
    getch();
    mainmenu();
}

// Function to search books
void searchbooks()
{
    system("cls");
    int d, found = 0;
    cout << "Search Books" << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "Enter your choice: ";
    cin >> s;
    if (s == 1)
    {
        cout << "Enter the Book ID: ";
        cin >> d;
        fp.open("book.dat", ios::in | ios::out);
        while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
        {
            if (book.id == d)
            {
                gotoxy(20, 4);
                cout << "The Book is available" << endl;
                gotoxy(20, 6);
                cout << "Book ID: " << book.id << endl;
                gotoxy(20, 7);
                cout << "Book Name: " << book.name << endl;
                gotoxy(20, 8);
                cout << "Author Name: " << book.author << endl;
                gotoxy(20, 9);
                cout << "Book Price: " << book.price << endl;
                gotoxy(20, 10);
                cout << "Book Quantity: " << book.quantity << endl;
                gotoxy(20, 11);
                cout << "Rack No: " << book.rackno << endl;
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            gotoxy(20, 4);
            cout << "No such book found" << endl;
        }
        getch();
        fp.close();
        mainmenu();
    }
    else if (s == 2)
    {
        string bname;
        cout << "Enter the Book Name: ";
        cin.ignore();
        getline(cin, bname);
        fp.open("book.dat", ios::in | ios::out);
        while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
        {
            if (book.name == bname)
            {
                gotoxy(20, 4);
                cout << "The Book is available" << endl;
                gotoxy(20, 6);
                cout << "Book ID: " << book.id << endl;
                gotoxy(20, 7);
                cout << "Book Name: " << book.name << endl;
                gotoxy(20, 8);
                cout << "Author Name: " << book.author << endl;
                gotoxy(20, 9);
                cout << "Book Price: " << book.price << endl;
                gotoxy(20, 10);
                cout << "Book Quantity: " << book.quantity << endl;
                gotoxy(20, 11);
                cout << "Rack No: " << book.rackno << endl;
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            gotoxy(20, 4);
            cout << "No such book found" << endl;
        }
        getch();
        fp.close();
        mainmenu();
    }
    else
    {
        gotoxy(10, 4);
        cout << "\aWrong Entry!! Please re-enter the correct option" << endl;
        getch();
        searchbooks();
    }
}

// Function to issue books
void issuebooks()
{
    system("cls");
    int t, found = 0;
    cout << "Issue Books" << endl;
    cout << "Enter the Book ID: ";
    cin >> t;
    fp.open("book.dat", ios::in | ios::out);
    ft.open("Issue.dat", ios::out | ios::app);
    while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
    {
        if (book.id == t)
        {
            found = 1;
            if (book.quantity == 0)
            {
                cout << "The book is out of stock" << endl;
                getch();
                mainmenu();
            }
            else
            {
                gotoxy(20, 4);
                cout << "The Book is available" << endl;
                gotoxy(20, 6);
                cout << "Book ID: " << book.id << endl;
                gotoxy(20, 7);
                cout << "Book Name: " << book.name << endl;
                gotoxy(20, 8);
                cout << "Author Name: " << book.author << endl;
                gotoxy(20, 9);
                cout << "Book Price: " << book.price << endl;
                gotoxy(20, 10);
                cout << "Book Quantity: " << book.quantity << endl;
                gotoxy(20, 11);
                cout << "Rack No: " << book.rackno << endl;
                gotoxy(20, 13);
                cout << "Enter Student Name: ";
                cin.ignore();
                getline(cin, book.stname);
                ft.write(reinterpret_cast<char *>(&book), sizeof(books));
                fp.write(reinterpret_cast<char *>(&book), sizeof(books));
                gotoxy(20, 15);
                cout << "Book issued successfully" << endl;
                found = 1;
                break;
            }
        }
    }
    if (found == 0)
    {
        gotoxy(20, 4);
        cout << "No such book found" << endl;
    }
    getch();
    fp.close();
    ft.close();
    mainmenu();
}

// Function to view the list of books
void viewbooks()
{
    system("cls");
    int i;
    gotoxy(1, 1);
    cout << "***************************" << endl;
    gotoxy(1, 2);
    cout << "ID   "  << "NAME   "  << "AUTHOR   " << "PRICE   "  << "QUANTITY   " << "RACKNO   " << endl;
    gotoxy(1, 3);
    cout << "***************************" << endl;
    fp.open("book.dat", ios::in);
    while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
    {
        gotoxy(1, i);
        cout << book.id << book.name << book.author  << book.price  << book.quantity  << book.rackno << endl;
        i++;
    }
    fp.close();
    getch();
    mainmenu();
}

// Function to edit book records
void editbooks()
{
    system("cls");
    int t, found = 0;
    cout << "Edit Books" << endl;
    cout << "Enter the Book ID: ";
    cin >> t;
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read(reinterpret_cast<char *>(&book), sizeof(books)))
    {
        if (book.id == t)
        {
            gotoxy(20, 4);
            cout << "The Book is available" << endl;
            gotoxy(20, 6);
            cout << "Book ID: " << book.id << endl;
            gotoxy(20, 7);
            cout << "Book Name: " << book.name << endl;
            gotoxy(20, 8);
            cout << "Author Name: " << book.author << endl;
            gotoxy(20, 9);
            cout << "Book Price: " << book.price << endl;
            gotoxy(20, 10);
            cout << "Book Quantity: " << book.quantity << endl;
            gotoxy(20, 11);
            cout << "Rack No: " << book.rackno << endl;
            gotoxy(20, 13);
            cout << "Enter the new details of the book" << endl;
            gotoxy(20, 14);
            cout << "Book Name: ";
            cin.ignore();
            getline(cin, book.name);
            gotoxy(20, 15);
            cout << "Author Name: ";
            getline(cin, book.author);
            gotoxy(20, 16);
            cout << "Book Price: ";
            cin >> book.price;
            gotoxy(20, 17);
            cout << "Book Quantity: ";
            cin >> book.quantity;
            gotoxy(20, 18);
            cout << "Rack No: ";
            cin >> book.rackno;
            int pos = -1 * static_cast<int>(sizeof(book));
            fp.seekp(pos, ios::cur);
            fp.write(reinterpret_cast<char *>(&book), sizeof(books));
            gotoxy(20, 20);
            cout << "Record has been updated" << endl;
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        gotoxy(20, 4);
        cout << "No such book found/n" << endl;
    }
    fp.close();
    getch();
    mainmenu();
}

// Function to generate unique book ID
int t()
{
    int id;
    fp.open("book.dat", ios::in);
    if (!fp)
    {
        return 1;
    }
    else
    {
        fp.seekg(0, ios::end);
        fp.seekg(-1 * static_cast<int>(sizeof(book)), ios::cur);
        fp.read(reinterpret_cast<char *>(&book), sizeof(books));
        id = book.id;
        id++;
        return id;
    }
    fp.close();
}

// Function to display password input screen
void Password()
{
    system("cls");
    char ch, pass[32];
    int i = 0, j;
    cout << "Enter Password: ";
    while (ch != 13)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            cout << "*";
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if (strcmp(pass, password.c_str()) == 0)
    {
        gotoxy(20, 8);
        cout << "Password Matched" << endl;
        gotoxy(20, 10);
        cout << "Press any key to continue..." << endl;
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(20, 8);
        cout << "Password Incorrect" << endl;
        gotoxy(20, 10);
        cout << "Press any key to exit..." << endl;
        getch();
        exit(0);
    }
}

// Function to display loading animation
void loaderanim()
{
    system("cls");
    int loader;
    gotoxy(20, 10);
    cout << "Loading..." << endl;
    gotoxy(22, 11);
    for (loader = 1; loader <= 20; loader++)
    {
        Sleep(100);
        cout << char(219);
    }
}

// Function to initialize the program
void intro()
{
    system("cls");
    gotoxy(35, 10);
    cout << "Library Management System" << endl;
    gotoxy(35, 11);
    cout << "Mini Project in C++" << endl;
    gotoxy(35, 13);
    cout << "Loading..." << endl;
    loaderanim();
    Password();
}

// Main function
int main()
{
    intro();
    mainmenu();
    return 0;
}

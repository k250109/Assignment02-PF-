#include <stdio.h>

void add_new_book(int isbns[], char titles[][50], float prices[], int quantities[], int *index);
void process_sales(int isbns[], char titles[][50], float prices[], int quantities[], int index);
void generate_Low_StockReport(int isbns[], char titles[][50], float prices[], int quantities[], int index);

int main()
{
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int choice;
    int index = 0; // number of books

    printf("\nLiberty Books Inventory System\n");
    printf("      option       \n");
    printf("1.add new book\n");
    printf("2.Process a Sale\n");
    printf("3.Generate Low-Stock Report\n");
    printf("4. existing");

    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            add_new_book(isbns, titles, prices, quantities, &index);
            break;
        case 2:
            process_sales(isbns, titles, prices, quantities, index);
            break;
        case 3:
            generate_Low_StockReport(isbns, titles, prices, quantities, index);
            break;
        case 4:
            printf("thanku you");
            break;
        default:
            printf("invalid input please select correct option ");
        }

    } while (choice != 4);
    return 0;
}

void add_new_book(int isbns[], char titles[][50], float prices[], int quantities[], int *index)
{
    int max_books = 100;
    if (*index >= max_books)
    {
        printf("Inventory full Cannot add more books\n");
        return;
    }

    int newisbn;
    printf("enter the isbn for add the book: ");
    scanf("%d", &newisbn);

    for (int i = 0; i < *index; i++)
        if (isbns[i] == newisbn)
        {
            printf("you enter a duplicate  book isbn ");
            return;
        }
    isbns[*index] = newisbn;
    printf("enter the book title: ");
    scanf(" %[^\n]", titles[*index]);   // %[^\n] use for allow space in title

    printf("enter the prices of book: ");
    scanf("%f", &prices[*index]);

    printf("enter the quantity of book: ");
    scanf("%d", &quantities[*index]);

    (*index)++;
    printf("books are added successfully\n ");
}

void process_sales(int isbns[], char titles[][50], float prices[], int quantities[], int index)
{
    if (index == 0)
    {
        printf("No books in inventory!\n ");
        return;
    }

    int sold_isbn;
    int copies;
    int count = 0;

    printf("enter the isbn number:");
    scanf("%d", &sold_isbn);

    for (int i = 0; i < index; i++)
    {

        if (isbns[i] == sold_isbn)
        {
            count++;
            printf("Book: %s\n", titles[i]);
            printf("enter the number of copies sold: ");
            scanf("%d", &copies);

            if (copies > quantities[i])
            {
                printf("Not enough stock! Only %d copies available.\n", quantities[i]);
            }
            else
            {
                quantities[i] -= copies;
                printf("Sale successful Remaining stock: %d\n", quantities[i]);
            }
            break;
        }
    }

    if (count == 0)
    {
        printf("this book not present in inventory isbn %d\n ", sold_isbn);
    }
}

void generate_Low_StockReport(int isbns[], char titles[][50], float prices[], int quantities[], int index)
{
    if (index == 0)
    {
        printf("No books in inventory!\n ");
        return;
    }
    int count = 0;
    for (int i = 0; i < index; i++)
    {

        if (quantities[i] < 5)
        {

            count++;
            printf("ISBN: %d | Titles: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
        }
    }
    if (count == 0)
    {
        printf("all books quantites greaterthan have a 5 ");
    }
}
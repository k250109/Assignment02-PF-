#include <stdio.h>

void coustomer_information(char name[], char CNIC[]);
void displayInventory(int codes[], int quantities[], float prices[], int count);
void addToCart(int codes[], int quantities[], float prices[], int cartCode[], int cartQty[], int count, int *cartCount);
float Total(int cartCode[], int cartQty[], int codes[], float prices[], int cartCount, int count);
void updateInventory(int codes[], int quantities[], int cartCode[], int cartQty[], int cartCount, int count);
void showInvoice(char name[], char cnic[], int codes[], float prices[], int cartCode[], int cartQty[], int cartCount, float total, float finaltotal, int count);

int main()
{

    int codes[] = {1, 2, 3, 4};
    int quantities[100] = {50, 10, 20, 8};
    float prices[100] = {100, 200, 300, 150};
    int itemCount = 4;

    int cartCode[100];
    int cartQty[100];
    int cartCount = 0;

    char name[30], CNIC[20];
    int choice;
    float total = 0, finaltotal = 0;
    int promo;

    printf("Supermarket Inventory System\n");

    do
    {
        printf("\nMenu:\n");
        printf("1.Enter Customer Information\n");
        printf("2.Display Inventory\n");
        printf("3.Add Item to Cart\n");
        printf("4.Display Total Bill\n");
        printf("5.Apply Promo Code (Eid2025)\n");
        printf("6.Show Invoice\n");
        printf("7.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            coustomer_information(name, CNIC);
            break;
        case 2:
            displayInventory(codes, quantities, prices, itemCount);
            break;
        case 3:
            addToCart(codes, quantities, prices, cartCode, cartQty, itemCount, &cartCount);
            break;

        case 4:
            total = Total(cartCode, cartQty, codes, prices, cartCount, itemCount);
            printf("Total Bill: Rs. %.2f\n", total);
            break;
        case 5:
            printf("Enter Promo Code:\n 1.eid2025\n2.other event  ");
            scanf("%d", promo);
            if (promo = 1)
            {
                finaltotal = total * 0.75;
                printf("Promo applied! You got 25%% off. Final Total: Rs. %.2f\n", finaltotal);
            }
            else
            {
                finaltotal = total;
                printf("Invalid or no promo code. No discount applied.\n");
            }
            break;

        case 6:
            showInvoice(name, CNIC, codes, prices, cartCode, cartQty, cartCount, total, finaltotal, itemCount);
            updateInventory(codes, quantities, cartCode, cartQty, cartCount, itemCount);
            break;
        case 7:
            printf("thanku you");
            break;
        default:
            printf("invalid input please select correct option ");
        }
    } while (choice != 7);

    return 0;
}

void coustomer_information(char name[], char CNIC[])
{

    printf(" enter the  name of the customer ");
    scanf(" %[^\n]", name);

    printf(" enter the CNIC of the customer ");
    scanf(" %s", CNIC);
    printf("Customer info saved successfully!\n");
}

void displayInventory(int codes[], int quantities[], float prices[], int count)
{

    printf("Code\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d\t %d\t %.2f\n", codes[i], quantities[i], prices[i]);
    }
}

void addToCart(int codes[], int quantities[], float prices[], int cartCode[], int cartQty[], int count, int *cartCount)
{

    displayInventory(codes, quantities, prices, count);
    int code, quantity;

    printf(" enter the product code for items add into cart ");
    scanf(" %d", &code);
    int found = 0;
    for (int x = 0; x < count; x++)
    {
        if (codes[x] == code)
        {
            found = 1;
            printf(" enter the  quantity ");
            scanf(" %d", &quantity);

            if (quantity > quantities[x])
            {
                printf("Not enough stock Only %d available\n", quantities[x]);
                return;
            }
            cartCode[*cartCount] = code;
            cartQty[*cartCount] = quantity;
            (*cartCount)++;
            printf("%d of product %d added to cart.\n", quantity, code);
            break;
        }
    }
    if (found == 0)
    {
        printf(" you enter Invalid product code\n");
    }
}
float Total(int cartCode[], int cartQty[], int codes[], float prices[], int cartCount, int count)
{
    float total = 0;
    for (int i = 0; i < cartCount; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (cartCode[i] == codes[j])
            {
                total += prices[j] * cartQty[i];
            }
        }
    }
    return total;
}

void updateInventory(int codes[], int quantities[], int cartCode[], int cartQty[], int cartCount, int count)
{
    for (int i = 0; i < cartCount; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (cartCode[i] == codes[j])
            {
                quantities[j] -= cartQty[i];
            }
        }
    }
}

void showInvoice(char name[], char CNIC[], int codes[], float prices[], int cartCode[], int cartQty[], int cartCount, float total, float finaltotal, int count)
{
    printf("\nshow invoice\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", CNIC);
    printf("Code\tQty\tPrice\tSubtotal\n");

    for (int i = 0; i < cartCount; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (cartCode[i] == codes[j])
            {
                float subtotal = prices[j] * cartQty[i];
                printf("%d\t %d\t %.2f\t %.2f\n", codes[j], cartQty[i], prices[j], subtotal);
            }
        }
    }
    printf("\nTotal No Discount: Rs. %.2f\n", total);
    if (finaltotal < total)
    {
        printf(" Discount Applied Final Total: Rs. %.2f \n", finaltotal);
    }
    else
    {
        printf("Final Total: Rs. %.2f\n", total);
    }
}
#include <stdio.h>
#include <string.h>
#define LENGTH 255

void string_reversal(char str[])
{
    int len = strlen(str);
    int end = len - 1;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[end - i];
        str[end - i] = temp;
    }
}
void bit_toggle(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        int ascii = str[i];
        ascii = ascii ^ 18;
        str[i] = ascii;
    }
}

void encodeMessage(char msg[])
{
    string_reversal(msg);
    bit_toggle(msg);
    printf("\nYour encoded message is: %s\n\n", msg);
}
void decodeMessage(char msg[])
{
    bit_toggle(msg);
    string_reversal(msg);
    printf("\nYour decoded message is: %s\n\n", msg);
}
int main()
{
    char msg[LENGTH];
    int choice;
    do
    {
        printf("\n--- Welcome to TCS Message Cryptographer ---\n\n");
        printf("[1]. Encode Message\n");
        printf("[2]. Decode Message\n");
        printf("[3]. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        while (getchar() != '\n')
            ;
        switch (choice)
        {
        case 1:
            printf("Enter your message to encode: ");
            scanf("%[^\n]s", msg);
            encodeMessage(msg);
            break;
        case 2:
            printf("Enter your message to decode: ");
            scanf("%[^\n]s", msg);
            decodeMessage(msg);
            break;
        case 3:
            printf("\nThank you for using this cli tool!\n");
            break;
        default:
            printf("\nInvalid Input! Please try again\n");
            continue;
        }
    } while (choice != 3);

    return 0;
}
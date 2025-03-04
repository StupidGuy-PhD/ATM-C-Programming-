#include <stdio.h>


void bl(int balance)
{
    printf("\nBalance: %d\n", balance);
}

int main() {
    int pin1, pin[4] = {1, 4, 3, 4}, c = 1;
    int sh, balance = 5000;
    int correctPin = 0;

    printf("----Welcome To GCash----\n");

    while (c <= 3) {
        printf("\nInput Pin: ");
        scanf("%d", &pin1);

        correctPin = 1;
        for (int i = 0; i < 4; i++) {
            if (pin1 % 10 != pin[3 - i]) {
                correctPin = 0;
                break;
            }
            pin1 /= 10;
        }

        if (correctPin) {
            while (1) {
                printf("----------MENU----------\n");
                printf("1. Check Balance\n");
                printf("2. Withdraw Cash\n");
                printf("3. Deposit Cash\n");
                printf("4. Quit\n");
                printf("Enter your choice: ");
                scanf("%d", &sh);

                switch (sh) {
                case 1:
                    bl(balance);
                    break;
                case 2:
                    printf("\nEnter Amount to Withdraw: ");
                    scanf("%d", &sh);
                    if (sh >= balance) {
                        printf("Insufficient Balance\n");
                    } else {
                        balance -= sh;
                        printf("Remaining balance: %d\n", balance);
                    }
                    break;
                case 3:
                    printf("\nEnter Amount to Deposit: ");
                    scanf("%d", &sh);
                    balance += sh;
                    printf("Balance: %d\n", balance);
                    break;
                case 4:
                    printf("\nThank You For Using\n");
                    return 0;
                default:
                    printf("Invalid choice.\n");
                    break;
                }
            }
        } else {
            printf("Wrong pin\n");
            c++;
            if (c > 3) {
                printf("Access Denied\n");
                return 0;
            }
        }
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pin = 1234, enteredPin, choice;
    float balance = 10000.00, deposit, withdraw;
    int attempts = 0;

    // PIN verification
    do {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        attempts++;

        if (enteredPin == pin) {
            printf("\nPIN verified successfully!\n");
            break;
        } else {
            printf("Incorrect PIN! Attempts left: %d\n", 3 - attempts);
        }

        if (attempts == 3) {
            printf("\nToo many incorrect attempts. Card blocked!\n");
            return 0;
        }

    } while (enteredPin != pin);

    do {
        printf("\n===============================\n");
        printf("        ATM MAIN MENU\n");
        printf("===============================\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour Current Balance: ₹%.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ₹");
                scanf("%f", &deposit);
                if (deposit > 0) {
                    balance += deposit;
                    printf("₹%.2f deposited successfully!\n", deposit);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ₹");
                scanf("%f", &withdraw);
                if (withdraw > balance) {
                    printf("Insufficient balance!\n");
                } else if (withdraw <= 0) {
                    printf("Invalid withdrawal amount.\n");
                } else {
                    balance -= withdraw;
                    printf("₹%.2f withdrawn successfully!\n", withdraw);
                }
                break;

            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
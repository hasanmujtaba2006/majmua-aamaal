#include <stdio.h>
#include <stdlib.h> // Required for the exit() function

// Function to handle the PIN entry and verification process
void pin_entry_process(int correctPin, int* pinVerified) {
    int enteredPin;
    int pinRetries = 0;
    
    // Step 2: Enter your PIN - using a do-while loop for attempts
    do {
        printf("\n==================================\n");
        printf("       ATM PIN VERIFICATION       \n");
        printf("==================================\n");
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == correctPin) {
            *pinVerified = 1; // Set the flag to indicate successful verification
            printf("\nPIN accepted! Welcome to your account.\n");
            break; // Exit the do-while loop
        } else {
            pinRetries++;
            if (pinRetries < 3) {
                printf("Incorrect PIN. Please try again. (%d attempt(s) remaining)\n", 3 - pinRetries);
            } else {
                printf("\n==================================\n");
                printf("Card blocked. You have exceeded 3 incorrect attempts. Exiting.\n");
                printf("==================================\n");
                *pinVerified = 0; // Ensure the flag is 0 if blocking
                exit(0); // Exit the program entirely
            }
        }
    } while (pinRetries < 3); // Loop until 3 retries are used or PIN is correct
}


int main() {
    // --- Initial Account Setup ---
    // Use double for balance to handle precise monetary values
    double balance = 50000.00;
    const int correctPin = 1234;
    int pinVerified = 0;
    int choice = 0; // Variable to store the user's menu choice
    
    printf("==================================\n");
    printf("     Welcome to the Hasan's ATM   \n");
    printf("==================================\n");

    // Step 1: Insert Your Card (Simulated)
    printf("\n* Simulating Card Insertion... *\n");
    pin_entry_process(correctPin, &pinVerified);

    // Only proceed to transactions if the PIN was successfully verified
    if (pinVerified) {
        
        // Main Transaction Loop: Use a while loop to keep the session running 
        // until the user chooses to exit (choice 5)
        while (choice != 5) {
            
            // --- Step 3: Select the desired transaction ---
            printf("\n----------------------------------\n");
            printf("       ATM TRANSACTION MENU       \n");
            printf("----------------------------------\n");
            printf("1. Cash Withdrawal\n");
            printf("2. Deposit\n");
            printf("3. Balance Inquiry\n");
            printf("4. Fund Transfer\n");
            printf("5. Exit / End Session\n");
            printf("Enter your choice (1-5): ");
            
            // Read the user's choice
            if (scanf("%d", &choice) != 1) {
                // Simple input validation to prevent infinite loops on bad input
                printf("Invalid input. Please enter a number.\n");
                // Clear input buffer (important in C)
                while(getchar() != '\n'); 
                continue; // Skip the rest of the loop iteration
            }

            // --- Transaction Logic using Nested If-Else Statements ---

            if (choice == 1) {
                // 1. Cash Withdrawal
                double withdrawalAmount;
                printf("\n--- Cash Withdrawal ---\n");
                printf("Enter amount to withdraw: ");
                scanf("%lf", &withdrawalAmount); // %lf for double

                // Check 1: Is the withdrawal amount valid (positive)?
                if (withdrawalAmount > 0) {
                    // Check 2: Is there sufficient balance?
                    if (withdrawalAmount <= balance) {
                        balance -= withdrawalAmount; // Update balance
                        printf("\nTransaction Successful!\n");
                        printf("Collect your cash: %.2lf\n", withdrawalAmount); // Collect cash message
                    } else {
                        // Insufficient funds
                        printf("\nTransaction Failed: Insufficient balance. Current balance is $%.2lf.\n", balance);
                    }
                } else {
                    // Invalid amount entered
                    printf("\nTransaction Failed: Invalid amount entered. Amount must be positive.\n");
                }

            } else if (choice == 2) {
                // 2. Deposit
                double depositAmount;
                printf("\n--- Deposit ---\n");
                printf("Insert your cash/checks into the slot (Enter amount): ");
                scanf("%lf", &depositAmount);

                // Check if the deposit amount is valid
                if (depositAmount > 0) {
                    // Simulate step 2 & 3: Verify and Confirm
                    printf("Verifying deposit amount: $%.2lf.\n", depositAmount);
                    printf("Deposit confirmed.\n");

                    balance += depositAmount; // Update balance
                    printf("\nDeposit Successful! New balance is $%.2lf.\n", balance);
                } else {
                    printf("\nTransaction Failed: Deposit amount must be positive.\n");
                }

            } else if (choice == 3) {
                // 3. Balance Inquiry
                printf("\n--- Balance Inquiry ---\n");
                printf("Your current account balance is: $%.2lf\n", balance); // Balance appears on screen

            } else if (choice == 4) {
                // 4. Fund Transfer
                double transferAmount;
                int destinationAccount = 0; // Simple placeholder for destination

                printf("\n--- Fund Transfer ---\n");
                printf("Enter destination account number (e.g., 987654): ");
                scanf("%d", &destinationAccount);
                printf("Enter amount to transfer (Source account is current account): ");
                scanf("%lf", &transferAmount);

                // Check 1: Is the transfer amount valid (positive)?
                if (transferAmount > 0) {
                    // Check 2: Is there sufficient balance?
                    if (transferAmount <= balance) {
                        balance -= transferAmount; // Update source balance
                        printf("\nTransfer Successful!\n");
                        printf("$%.2lf has been transferred to account %d.\n", transferAmount, destinationAccount);
                        printf("Your remaining balance is $%.2lf.\n", balance);
                    } else {
                        // Insufficient funds
                        printf("\nTransaction Failed: Insufficient balance for transfer. Current balance is $%.2lf.\n", balance);
                    }
                } else {
                    // Invalid amount entered
                    printf("\nTransaction Failed: Transfer amount must be positive.\n");
                }
                

            } else if (choice == 5) {
                // Exit choice is handled by the 'while (choice != 5)' condition, 
                // but we print the final message here.
                printf("\n----------------------------------\n");
                printf("Thank you for using the ATM. Goodbye!\n");
                printf("----------------------------------\n");

            } else {
                // Invalid menu choice
                printf("\nInvalid choice. Please select a number from 1 to 5.\n");
            }
        } // End of while loop (main transaction session)

    } // End of if (pinVerified)
    
    return 0;
}
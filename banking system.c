#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char name[50];
    double balance;
};

struct Bank {
    struct Account accounts[MAX_ACCOUNTS];
    int totalAccounts;
};

void createAccount(struct Bank *bank) {
    if (bank->totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Bank full.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);

    bank->accounts[bank->totalAccounts++] = newAccount;
    printf("Account created successfully.\n");
}

void deposit(struct Bank *bank, int accountNumber, double amount) {
    for (int i = 0; i < bank->totalAccounts; i++) {
        if (bank->accounts[i].accountNumber == accountNumber) {
            bank->accounts[i].balance += amount;
            printf("Deposit successful. New balance: %.2lf\n", bank->accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw(struct Bank *bank, int accountNumber, double amount) {
    for (int i = 0; i < bank->totalAccounts; i++) {
        if (bank->accounts[i].accountNumber == accountNumber) {
            if (bank->accounts[i].balance >= amount) {
                bank->accounts[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2lf\n", bank->accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void checkBalance(struct Bank *bank, int accountNumber) {
    for (int i = 0; i < bank->totalAccounts; i++) {
        if (bank->accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2lf\n", bank->accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct Bank bank;
    bank.totalAccounts = 0;

    int choice, accountNumber;
    double amount;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&bank);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(&bank, accountNumber, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(&bank, accountNumber, amount);
                break;
            case 4:
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                checkBalance(&bank, accountNumber);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

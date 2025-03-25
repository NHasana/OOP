#include <iostream>
#include <string>
using namespace std;

// Parent class Payment
class Payment {
public:
    int id;
    double amount;
    string date;
    string status;
    static double balance;

    Payment(int i, double a, string d, string s) {
        id = i;
        amount = a;
        date = d;
        status = s;
    }

    virtual void processPayment() {
        if (amount <= balance) {
            balance -= amount;
            cout << "1. Processing payment...\n";
            cout << "Current Balance: " << balance << "\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    virtual bool validatePayment() {
        return true;
    }

    virtual void refundPayment() {
        balance += amount;
        cout << "2. Refunding payment...\n";
        cout << "Current Balance after refund: " << balance << "\n";
    }
};

// Initialize balance
double Payment::balance = 500.0;

// Child class CreditCardPayment
class CreditCardPayment : public Payment {
public:
    string cardNumber;
    string expiryDate;
    int cvv;

    CreditCardPayment(int i, double a, string d, string s, string cn, string ed, int c)
        : Payment(i, a, d, s), cardNumber(cn), expiryDate(ed), cvv(c) {}

    void processPayment() override {
        Payment::processPayment();
        cout << "3. Processing Credit Card Payment...\n";
    }
};

// Child class BankTransfer
class BankTransfer : public Payment {
public:
    string accountNumber;
    string bankName;

    BankTransfer(int i, double a, string d, string s, string an, string bn)
        : Payment(i, a, d, s), accountNumber(an), bankName(bn) {}

    void processPayment() override {
        Payment::processPayment();
        cout << "4. Processing Bank Transfer Payment...\n";
    }
};

// Child class DigitalWallet
class DigitalWallet : public Payment {
public:
    string walletId;
    string provider;

    DigitalWallet(int i, double a, string d, string s, string wid, string p)
        : Payment(i, a, d, s), walletId(wid), provider(p) {}

    void processPayment() override {
        Payment::processPayment();
        cout << "5. Processing Digital Wallet Payment...\n";
    }
};

int main() {
    cout << "Initial Balance: " << Payment::balance << "\n";
    
    CreditCardPayment ccp(1, 100.5, "2025-03-26", "Pending", "1234567812345678", "12/27", 123);
    ccp.processPayment();

    BankTransfer bt(2, 200.75, "2025-03-26", "Pending", "9876543210", "Bank ABC");
    bt.processPayment();

    DigitalWallet dw(3, 50.25, "2025-03-26", "Pending", "WALLET123", "E-Wallet XYZ");
    dw.processPayment();
    
    return 0;
}

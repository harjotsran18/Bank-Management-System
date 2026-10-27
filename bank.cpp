#include<iostream>
#include<fstream> 
using namespace std;

class account {
    int s, t;
    char n;
    int acc_no;
    char name[20];
public:
    void getdata(void) {
        cout << "\nDo you have an account in this bank?\n(y/n) : ";
        cin >> n;
    }

    void putdata(void) {
        if (n == 'y') {
            cout << "You already having account in this bank.";
            cout << "\nAccount number : ";
            cin >> acc_no;
            cout << "Name : ";
            cin >> name;
        } else if (n == 'n') {
            cout << "You don't having account in this bank.";
        } else {
            cout << "Select correct option..";
        }
    }

    void display(void) {
        if (n == 'y') {
            cout << "\n     ACCESS GRANTED";
            cout << "\nAccount number : " << acc_no;
            cout << "\nAccount holder name : " << name;
            char response[10];
            int balance = 2000;
            int x, y;
            int bill;

            do {
                cout << "\n\n1.Withdraw\n2.Deposit\n3.Check balance\n4.Bill pay\n5.Exit";
                cout << "\n\nWhat you would like to do :";
                cin >> s;
                switch (s) {
                    case 1:
                        cout << "\n      Withdraw money..";
                        cout << "\nCurrent balance : " << balance;
                        cout << "\nEnter your withdraw amount : ";
                        cin >> x;
                        if (x <= balance) {
                            cout << "Withdrawn successfully....";
                            balance = balance - x;
                            cout << "\nBalance now : " << balance;
                        } else
                            cout << "Not sufficient account balance";
                        break;

                    case 2:
                        cout << "\n      Deposit money.. ";
                        cout << "\nCurrent balance : " << balance;
                        cout << "\nEnter deposit amount : ";
                        cin >> y;
                        cout << "Deposit successfully..";
                        balance = balance + y;
                        cout << "\nBalance now : " << balance;
                        break;

                    case 3:
                        cout << "\nYour account balance is : " << balance;
                        break;

                    case 4:
                        cout << "\nPay your bill ";
                        cout << "\n1.Electricity\n2.Water\n3.Wifi";
                        cout << "\nWhich bill you want to pay : ";
                        cin >> bill;
                        char b[10], e[10], f[10];
                        switch (bill) {
                            case 1:
                                cout << "\n         ELECTRICITY BILL";
                                cout << "\nYour account balance : " << balance;
                                cout << "\nYour remaining electricity bill : 3600";
                                if (3600 < balance) {
                                    cout << "\nDo you want to pay bill?(yes/no) : ";
                                    cin >> b;
                                    if (b[0] == 'y') {
                                        cout << "\nBill paid successfully..";
                                        balance = balance - 3600;
                                        cout << "\nAccount balance now : " << balance;
                                    } else
                                        cout << "Thanks";
                                } else
                                    cout << "\nYou don't have sufficient balance to pay.";
                                break;

                            case 2:
                                cout << "\n         WATER BILL";
                                cout << "\nYour account balance : " << balance;
                                cout << "\nYour remaining water bill : 1600";
                                if (1600 < balance) {
                                    cout << "\nDo you want to pay bill?(yes/no) : ";
                                    cin >> e;
                                    if (e[0] == 'y') {
                                        cout << "\nBill paid successfully..";
                                        balance = balance - 1600;
                                        cout << "\nAccount balance now : " << balance;
                                    } else
                                        cout << "Thanks";
                                } else
                                    cout << "\nYou don't have sufficient balance to pay.";
                                break;

                            case 3:
                                cout << "\n         WIFI BILL";
                                cout << "\nYour account balance : " << balance;
                                cout << "\nYour remaining wifi bill : 800";
                                if (800 < balance) {
                                    cout << "\nDo you want to pay bill?(yes/no) : ";
                                    cin >> f;
                                    if (f[0] == 'y') {
                                        cout << "\nBill paid successfully..";
                                        balance = balance - 800;
                                        cout << "\nAccount balance now : " << balance;
                                    } else
                                        cout << "Thanks";
                                } else
                                    cout << "\nYou don't have sufficient balance to pay.";
                                break;

                            default:
                                cout << "\nChoose correct option..";
                                break;
                        }
                        break;

                    case 5:
                        cout << "Thanks..";
                        break;
                }

                if (s <= 4) {
                    cout << "\nDo you want to do anything else?(yes/no) : ";
                    cin >> response;
                }

            } while (response[0] == 'Y' || response[0] == 'y');

            cout << "\nThanks..Hope you like our service...\n";

            //File handling
            ofstream fout("existing_account.txt");
            fout << "Account number: " << acc_no << endl;
            fout << "Name: " << name << endl;
            fout << "Final balance: " << balance << endl;
            fout.close();
           
        }

        else if (n == 'n') {
            char name[50], add[50], fathername[50], email[100];
            long int phone, adhaar, a, d;
            cout << "\n       Access granted";
            cout << "\n1.Open account\n2.Exit";
            cout << "\nWhat would you like to do : ";
            cin >> t;

            if (t == 1) {
                cout << "\nWhich account do you want to create";
                cout << "\n1.Minimum balance account\n2.Zero balance account \n : ";
                cin >> a;

                if (a == 1) {
                    cout << "\nEnter your information to create account:";
                    cout << "\nName : ";
                    cin >> name;
                    cout << "Father's name : ";
                    cin >> fathername;
                    cout << "Address : ";
                    cin >> add;
                    cout << "E-mail id : ";
                    cin >> email;
                    cout << "Phone number : ";
                    cin >> phone;
                    cout << "Aadhaar card number : ";
                    cin >> adhaar;
                    cout << "To create account, minimum deposit amount is 2000.";

                    do {
                        cout << "\nYour deposit amount : ";
                        cin >> d;
                        if (d >= 2000) {
                            cout << "\n\n     Account created successfully ";
                            cout << "\nYour account number : 5678";
                            cout << "\nAccount holder's name : " << name;
                            cout << "\nFather's name : " << fathername;
                            cout << "\nAddress : " << add;
                            cout << "\nE-mail id :" << email;
                            cout << "\nPhone number : " << phone;
                            cout << "\nAadhaar card number : " << adhaar;
                            cout << "\nYour account balance : " << d;

                            //File handling
                            ofstream fout("minimum_balance_account.txt");
                            fout << "Name: " << name << endl;
                            fout << "Father's Name: " << fathername << endl;
                            fout << "Address: " << add << endl;
                            fout << "Email: " << email << endl;
                            fout << "Phone: " << phone << endl;
                            fout << "Aadhaar: " << adhaar << endl;
                            fout << "Balance: " << d << endl;
                            fout.close();
                            cout << "\n(Account data saved to 'new_account.txt')\n";
                        } else {
                            cout << "Deposit more than 2000";
                        }
                    } while (d < 2000);
                }

                else if (a == 2) {
                    cout << "\nEnter your information to open zero balance account:";
                    cout << "\nName : ";
                    cin >> name;
                    cout << "Father's name : ";
                    cin >> fathername;
                    cout << "Address : ";
                    cin >> add;
                    cout << "E-mail id : ";
                    cin >> email;
                    cout << "Phone number : ";
                    cin >> phone;
                    cout << "Aadhaar card number : ";
                    cin >> adhaar;

                    cout << "\n\n     Zero balance account created successfully ";
                    cout << "\nYour account number : 9876";
                    cout << "\nAccount holder's name : " << name;
                    cout << "\nFather's name : " << fathername;
                    cout << "\nAddress : " << add;
                    cout << "\nE-mail id :" << email;
                    cout << "\nPhone number : " << phone;
                    cout << "\nAadhaar card number : " << adhaar;

                    //File handling
                    ofstream fout("zero_balance_account");
                    fout << "Name: " << name << endl;
                    fout << "Father's Name: " << fathername << endl;
                    fout << "Address: " << add << endl;
                    fout << "Email: " << email << endl;
                    fout << "Phone: " << phone << endl;
                    fout << "Aadhaar: " << adhaar << endl;
                    fout << "Balance: 0" << endl;
                    fout.close();
                    cout << "\n(Account data saved to 'zero_balance_account.txt')\n";
                }

                cout << "\n\nNow your account is created successfully.";
            } else if (t == 2) {
                cout << "Thanks..";
            }
        }
    }
};

int main() {
    account a1;
    cout << "========================\n          BANK        \n======================== ";
    a1.getdata();
    a1.putdata();
    a1.display();
    return 0;
}
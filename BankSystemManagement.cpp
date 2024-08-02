#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

class Account
{
public:

    int accountNumber;
    string name;
    string password;
    string phoneNumber;
    double balance;

    Account(int accNum, string nm, double bl, string phone, string pwd)
    {
        accountNumber = accNum;
        name = nm;
        balance = bl;
        phoneNumber = phone;
        password = pwd;
    }

    void Balance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Phone Number: +880" << phoneNumber << endl;
        cout<<endl;
    }
};


class BankManagementSystem
{

public:

    vector<Account>accounts;

    int loggedInAccountNumber;

    BankManagementSystem()
    {
        loggedInAccountNumber = -1;
    }


    void createAccount()
    {
        int accNum;
        string nm;
        double initialDeposit;

        cout<<"Enter Account Number: ";
        cin>>accNum;

        cin.ignore();

        // Check if account number already exists
        for (const auto& account : accounts)
        {
            if (account.accountNumber == accNum)
            {
                cout << "Account number already exists. Please use a different account number." << endl << endl;
                return;
            }
        }

        cout<<"Enter Name: ";
        //cin>>nm;
        getline(cin,nm);

        string phone;
        cout << "Enter Phone Number: +880";
        cin >> phone;

        cout<<"Enter initial Deposit (minimum 500) : ";
        cin>>initialDeposit;

        if(initialDeposit < 500)
        {
            cout<<"Minimum deposit amount 500"<<endl<<endl;
            return;
        }

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        if(initialDeposit >= 500)
        {
            accounts.emplace_back(Account(accNum,nm,initialDeposit,phone,pwd));
            cout<<"Account created successfully."<<endl;
            cout<<endl;
            //accounts.back().display();
        }

    }



    // newly added this method
    bool login(int accNum, string pwd)
    {
        for(auto &account : accounts)
        {
            if(account.accountNumber == accNum && account.password == pwd)
            {
                cout<<"Login Successful !"<<endl<<endl;
                loggedInAccountNumber = accNum;
                return true;
            }
        }

        cout<<"Invalid Account Number or Password"<<endl<<endl;
        return false;
    }


    void logout()
    {
        loggedInAccountNumber = -1;
        cout << "Logged out successfully." << endl << endl;

    }


    void closeAccount()
    {

        if (loggedInAccountNumber == -1)
        {
            cout << "No account is currently logged in." << endl << endl;
            return;
        }

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        for(size_t i = 0; i < accounts.size(); i++)
        {
            if(accounts[i].accountNumber == loggedInAccountNumber && accounts[i].password == pwd)
            {
                accounts.erase(accounts.begin() + i);
                cout<<"Account closed successfully."<<endl<<endl;
                loggedInAccountNumber = -1;
                return ;
            }
        }

        cout << "Wrong password." << endl << endl;
    }

    void deposit()
    {

        if (loggedInAccountNumber == -1)
        {
            cout << "No account is currently logged in." << endl << endl;
            return;
        }

        double amount;
        cout<<"Enter amount to deposit: ";
        cin>>amount;

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        for(auto& account : accounts)
        {
            if(account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                if(amount  > 0)
                {
                    account.balance = amount + account.balance;
                    cout<<"Deposited " << amount << "tk Successfully." <<endl<<endl;
                    account.display();
                }
                else
                {
                    cout<<"Invalid deposit amount."<<endl<<endl;
                }
                return;
            }
        }

        cout<<"wrong password."<<endl<<endl;


    }

    void withdraw()
    {

        if (loggedInAccountNumber == -1)
        {
            cout << "No account is currently logged in." << endl << endl;
            return;
        }

        double amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        for(auto& account : accounts)
        {
            if(account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                if(amount > account.balance)
                {
                    cout<<"Insufficient balance to withdraw."<<endl<<endl;
                    return;
                }

                else if(amount  > 0)
                {
                    account.balance = account.balance - amount;
                    cout<<"Withdraw "<<amount<<"tk Successfully."<<endl<<endl;
                    account.display();
                }

                else
                {
                    cout<<"Invalid withdraw amount."<<endl<<endl;
                }

                return;
            }
        }

        cout<<"Wrong password."<<endl<<endl;
    }



    void balanceInquiry()
    {

        if (loggedInAccountNumber == -1)
        {
            cout << "No account is currently logged in." << endl << endl;
            return;
        }

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        for(const auto& account : accounts)
        {
            if (account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                cout<<"Balance : Tk ";
                cout<< account.balance <<endl;
                cout<<endl<<endl;
                //displayAccount(accNum);
                return;
            }
        }

        cout<<"Wrong Password."<<endl<<endl;
        cout<<endl;

    }



    // Not complete this function


    void fundTransfer()
    {
        int receiverAccNum;
        double amount;


        if (loggedInAccountNumber == -1)
        {
            cout << "No account is currently logged in." << endl << endl;
            return;
        }

        cout << "Enter receiver account number: ";
        cin >> receiverAccNum;

        cout << "Enter amount to transfer: ";
        cin >> amount;

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        int senderIndex = -1, receiverIndex = -1;

        // Find sender and receiver accounts by their indexes
        for (size_t i = 0; i < accounts.size(); ++i)
        {
            if (accounts[i].accountNumber == loggedInAccountNumber && accounts[i].password == pwd )
            {
                senderIndex = i;
            }
            if (accounts[i].accountNumber == receiverAccNum)
            {
                receiverIndex = i;
            }

        }


        // Check if sender account was not found
        if (senderIndex == -1)
        {
            cout << "Wrong Password." << endl << endl;
            return;
        }

        // Check if receiver account was not found
        if (receiverIndex == -1)
        {
            cout << "Receiver account not found." << endl << endl;
            return;
        }

        // Check for invalid amount
        if (amount <= 0)
        {
            cout << "Invalid transfer amount." << endl << endl;
            return;
        }

        // Check if sender has enough balance
        if (accounts[senderIndex].balance < amount)
        {
            cout << "Insufficient balance to transfer." << endl << endl;
            return;
        }

        // Perform the transfer
        accounts[senderIndex].balance = accounts[senderIndex].balance - amount;

        accounts[receiverIndex].balance = accounts[receiverIndex].balance + amount;


        cout << "Transaction Successful." << endl << endl;

        cout << "Sender's New Balance:" << endl;
        accounts[senderIndex].Balance();


        cout<<endl;
    }


};

int main()
{
    BankManagementSystem bms;

    cout << "\t\t\t=========================================" << endl;
    cout << "\t\t\t||    Welcome to Secure Bank System    ||" << endl;
    cout << "\t\t\t=========================================" << endl << endl;

    while(true)
    {
        cout<<"1. Login"<<endl;
        cout<<"2. Create New Account"<<endl;
        cout<<"3. Exit"<<endl;

        cout<<endl;
        int choice;
        cout<<"\t\t\t\tEnter your choice: ";
        cin>>choice;

        if(choice == 1)
        {
            int accNum;
            string pwd;
            cout << "Enter Account Number: ";
            cin >> accNum;
            cout << "Enter Password: ";
            cin >> pwd;
            if (bms.login(accNum, pwd))
            {
                while(true)
                {
                    cout<<"1. Deposit"<<endl;
                    cout<<"2. Withdraw"<<endl;
                    cout<<"3. Balance Inquiry"<<endl;
                    cout<<"4. Fund Transfer"<<endl;
                    cout<<"5. Delete Account"<<endl;
                    cout<<"6. Logout"<<endl;

                    cout<<endl;
                    int subChoice;
                    cout<<"\t\t\t\tEnter your choice: ";
                    cin>>subChoice;

                    if(subChoice == 1)
                    {
                        bms.deposit();
                    }
                    else if(subChoice == 2)
                    {
                        bms.withdraw();
                    }
                    else if(subChoice == 3)
                    {
                        bms.balanceInquiry();
                    }
                    else if(subChoice == 4)
                    {
                        bms.fundTransfer();
                    }
                    else if(subChoice == 5)
                    {
                        bms.closeAccount();
                    }
                    else if(subChoice == 6)
                    {
                        // cout<<"Logging out......."<<endl<<endl;
                        bms.logout();
                        break;
                    }
                    else
                    {
                        cout<<"Please enter correct option"<<endl<<endl;
                    }

                }

            }

        }

        else if (choice == 2)
        {
            bms.createAccount();
        }
        else if (choice == 3)
        {
            cout << "Exiting......." << endl<< endl;

            break;
        }
        else
        {
            cout << "Please enter a correct option" << endl;
            cout << endl;
        }

    }

    return 0;

}

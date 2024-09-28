#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    //constraction call
    Transaction(const string& type, double amount)
    {
        this->type = type;
        this->amount = amount;
    }

};

class Account
{
public:

    int accountNumber;
    string name;
    string password;
    string phoneNumber;
    double balance;

    double loanAmount = 0;
    double loanInterestRate = 0;
    double loanDueAmount = 0;

    vector<Transaction> transactionHistory;


    //constructor call
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


    //Display Account information
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Phone Number: +880" << phoneNumber << endl;
        cout<<endl;
    }

    void addTransaction(const string& type, double amount)
    {
        transactionHistory.emplace_back(Transaction(type,amount));
    }

    void viewTrans_history()
    {
        if(transactionHistory.empty())
        {
            cout<<"No transaction found."<<endl;
            return;
        }

        cout<<"Transaction History: "<<endl;
        for(const auto& transaction : transactionHistory)
        {
            cout<<transaction.type<<" : "<<transaction.amount<<"TK"<<endl;
        }
        cout<<endl;
    }
};


class BankManagementSystem
{

public:

    vector<Account>accounts;

    int loggedInAccountNumber;


    //constructor call
    BankManagementSystem()
    {
        loggedInAccountNumber = -1;
    }


    //create new account

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
            cout<<endl;
            cout<<"Account created successfully."<<endl;
            cout<<endl;
        }

    }


    // newly added this method
    //To login your account this function will work

    bool login(int accNum, string pwd)
    {
        cout<<endl;

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


    //Exit from your account
    void logout()
    {
        loggedInAccountNumber = -1;
        cout << "Logged out successfully." << endl << endl;

    }

    // Delete Account Function
    void closeAccount()
    {

        if (loggedInAccountNumber == -1)
        {
            cout << endl<<"No account is currently logged in." << endl << endl;
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

    // when we want to add money in my account
    void deposit()
    {
        cout<<endl;
        if (loggedInAccountNumber == -1)
        {
            cout <<endl<< "No account is currently logged in." << endl << endl;
            return;
        }

        double amount;
        cout<<"Enter amount to deposit (or enter  0  to cancel): ";
        cin>>amount;

        if(amount == 0)
        {
            cout<<"Deposit canceled. Returning the main menu......."<<endl<<endl;
            return;
        }

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
                    account.addTransaction("Deposit", amount);
                    cout<<"Deposited " << amount << "Tk Successfully." <<endl<<endl;

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

    // if we need to withdraw money then call this function
    void withdraw()
    {
        cout<<endl;
        if (loggedInAccountNumber == -1)
        {
            cout <<endl<< "No account is currently logged in." << endl << endl;
            return;
        }

        double amount;
        cout<<"Enter amount to withdraw (or enter  0  to cancel): ";
        cin>>amount;

         if(amount == 0)
        {
            cout<<"Withdraw canceled. Returning the main menu......."<<endl<<endl;
            return;
        }

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
                    account.addTransaction("Withdraw", amount);

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



    // if we want to check balance then call this function
    void balanceInquiry()
    {


        if (loggedInAccountNumber == -1)
        {
            cout << endl<<"No account is currently logged in." << endl << endl;
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
                cout<<" Current balance Tk ";
                cout<< account.balance <<endl;
                cout<<endl<<endl;
                return;
            }
        }

        cout<<"Wrong Password."<<endl<<endl;
        cout<<endl;

    }

    void  accountDetails()
    {


        if (loggedInAccountNumber == -1)
        {
            cout <<endl<< "No account is currently logged in." << endl << endl;
            return;
        }

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        for(auto& account : accounts)
        {
            if (account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                account.display();
                cout<<endl<<endl;
                return;
            }
        }

        cout<<"Wrong Password."<<endl<<endl;
        cout<<endl;

    }

    void Transaction_history()
    {
        if (loggedInAccountNumber == -1)
        {
            cout << endl<<"No account is currently logged in." << endl << endl;
            return;
        }

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;

        cout<<endl;

        for(auto& account : accounts)
        {
            if(account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                account.viewTrans_history();
                cout<<endl<<endl;
                return;
            }

        }
        cout<<"Wrong password."<<endl<<endl;
    }




    // send money from one account to another account

    void fundTransfer()
    {

        int receiverAccNum;
        double amount;


        if (loggedInAccountNumber == -1)
        {
            cout <<endl<< "No account is currently logged in." << endl << endl;
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



    void applyForLoan()
    {
        double loanAmount;
        double interestRate;
        int loanDurationMonths;

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;
        for(auto& account: accounts)
        {
            if(account.password != pwd)
            {
                cout<<endl;
                cout<<"Wrong password."<<endl;
                return;
            }
        }

        cout<<endl;

        cout << "Enter the loan amount: ";
        cin >> loanAmount;



        if (loanAmount <= 0)
        {
            cout << "Invalid loan amount." << endl << endl;
            return;
        }

        cout << "Enter the interest rate (in %): ";
        cin >> interestRate;

        cout << "Enter loan duration (in months): ";
        cin >> loanDurationMonths;

        double total_interest = loanAmount * (interestRate / 100) * loanDurationMonths / 12;
        double total_due = loanAmount + total_interest;

        for (auto& account : accounts)
        {
            if (account.accountNumber == loggedInAccountNumber && account.password == pwd)
            {
                if (account.loanAmount > 0)
                {
                    cout << "You already have an active loan. Please repay the existing loan first." << endl << endl;
                    return;
                }

                account.loanAmount = loanAmount;
                account.loanInterestRate = interestRate;
                account.loanDueAmount = total_due;

                account.addTransaction("Loan",account.loanAmount);



                cout <<endl<< "Loan approved!" << endl;
                cout << "Loan Amount: " << account.loanAmount << endl;
                cout << "Interest Rate: " << account.loanInterestRate << "%" << endl;
                cout << "Total Loan Due: " << account.loanDueAmount << " (including interest)" << endl << endl;
                return;


            }
        }


    }


    void repayLoan()
    {

        string pwd;
        cout << "Enter Password: ";
        cin >> pwd;
        for(auto& account: accounts)
        {
            if(account.password != pwd)
            {
                cout<<endl;
                cout<<"Wrong password."<<endl;
                return;
            }
        }

        double repaymentAmount;

        cout<<"Enter the amount to repay: ";
        cin>>repaymentAmount;

        for (auto& account : accounts)
        {
            if (account.accountNumber == loggedInAccountNumber)

                if (account.loanDueAmount == 0)
                {
                    cout << "No active loans to repay." << endl << endl;
                    return;
                }



            if(repaymentAmount > account.balance)
            {
                cout<<"Insufficient balance to repay the loan."<<endl<<endl;
                return;
            }

            if(repaymentAmount > account.loanDueAmount)
            {
                repaymentAmount = account.loanDueAmount; //just pay only due amount
            }

            account.balance = account.balance - repaymentAmount;
            account.loanDueAmount = account.loanDueAmount - repaymentAmount;

            account.addTransaction("Loan repayment", repaymentAmount);


            cout<<endl<<"Loan repayment successful !!"<<endl;
            cout<<"Remaining loan due: "<<account.loanDueAmount<<endl;

            if(account.loanDueAmount == 0)
            {
                account.loanAmount = 0;
                account.loanInterestRate = 0;
                cout<<"Loan fully repaid."<<endl;
            }

            cout<<"Remaining balance: "<<account.balance<<endl<<endl;
            return;
        }
    }


    void viewLoanDetails()
    {
        cout<<endl;
        for(const auto& account : accounts)
        {
            if(account.accountNumber == loggedInAccountNumber)
            {
                if(account.loanAmount > 0)
                {
                    cout<<"Loan Amount : "<<account.loanAmount<<endl;
                    cout<<"Loan Interest Rate: "<<account.loanInterestRate<<"%"<<endl;
                    cout<<"Total Loan Due (including interest): "<<account.loanDueAmount<<endl;

                }
                else
                {
                    cout<<"No active loans."<<endl;
                }
                return;
            }
        }
    }



    void loan()
    {
        if(loggedInAccountNumber == -1)
        {
            cout<<"No account is currently logged in."<<endl<<endl;
            return;
        }

        while(true)
        {
            cout << "1. Apply for Loan" << endl;
            cout << "2. Repay Loan" << endl;
            cout << "3. View Loan Details" << endl;
            cout << "4. Back to Main Menu" << endl;

            int loanChoice;
            cout<<"\t\t\tEnter your choice: ";
            cin>>loanChoice;

            if(loanChoice == 1)
            {
                applyForLoan();
                break;
            }
            else if(loanChoice == 2)
            {
                repayLoan();
                break;
            }
            else if(loanChoice == 3)
            {
                viewLoanDetails();
            }
            else if(loanChoice == 4)
            {
                return;
            }
            else
            {
                cout<<"Invalid option. Please try again."<<endl;
            }
        }

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

                    cout<<"\t\t[1]--> Deposit"<<endl;
                    cout<<"\t\t[2]--> Withdraw"<<endl;
                    cout<<"\t\t[3]--> Loan"<<endl;
                    cout<<"\t\t[4]--> Balance Inquiry"<<endl;
                    cout<<"\t\t[5]--> Fund Transfer"<<endl;
                    cout<<"\t\t[6]--> Delete Account"<<endl;
                    cout<<"\t\t[7]--> My Account Details"<<endl;
                    cout<<"\t\t[8]--> Transaction History"<<endl;
                    cout<<"\t\t[9]--> Logout"<<endl;

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
                        bms.loan();
                    }
                    else if(subChoice == 4)
                    {

                        bms.balanceInquiry();
                    }
                    else if(subChoice == 5)
                    {

                        bms.fundTransfer();
                    }
                    else if(subChoice == 6)
                    {

                        bms.closeAccount();
                    }

                    else if(subChoice == 7)
                    {
                        bms.accountDetails();
                    }

                    else if(subChoice == 8)
                    {
                        bms.Transaction_history();
                    }
                    else if(subChoice == 9)
                    {
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

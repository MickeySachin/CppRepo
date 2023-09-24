// 25th September 2020
// Simple Banking Transaction System
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class account
{
     protected:
          string name;
          int accNo;
          string accType;
          double balance;
     public:
          account()
          {
               cout << "Enter the name of account holder = ";
               cin >> name;
               cout << "Enter the account number = ";
               cin >> accNo;
               cout << "Enter the type of account (savings/current) = ";
               cin >> accType;
               cout << "Enter the amount in account = ";
               cin >> balance;
          }
          void deposit()
          {
               double tempBalance;
               cout << "Enter the amount to be deposited = ";
               cin >> tempBalance;
               balance += tempBalance;
               cout << "Amount deposited successfully! Your available Balance = " << balance << "\n\n";
          }
          void withdrawl()
          {
               double withdrawlBalance;
               cout << "Enter the amount to be withdrawn = ";
               cin >> withdrawlBalance;
               balance -= withdrawlBalance;
               cout << "Amount withdrawn successfully! Your available Balance = " << balance << "\n\n";
          }
          void putBalance()
          {
               cout << "Available Balance = " << balance << " INR\n\n";
          }
          void putInfo()
          {
               cout << "Name of Account Holder = " << name << endl;
               cout << "Account Number = " << accNo << endl;
               cout << "Type of Account = " << accType << endl;
               cout << "Available Balance = " << balance << " INR\n\n";
          }
};
class savingsAcc : public account
{
     protected:
          float rate, n, t, cmpndInt;
     public:
          savingsAcc() { }
          savingsAcc(string a, int b, string c, float d)
          {
               name = a;
               accNo = b;
               accType = c;
               balance = d;
          }
          float compoundInt()
          {
               cout << "\nEnter the Rate, number of times interest applied per unit time and time = ";
               cin >> rate >> n >> t;
               rate = rate/100;
               float x = 1.0 + (rate/n);
               cmpndInt = balance * pow(x,n*t);
               balance += cmpndInt;
               return balance;
          }
          void putCmpnd()
          {
               cout << "Compound Interest applied on your Balance = " << cmpndInt << endl;
          }
          void isSavingsAcc()
          {
               int y;
               while(y != 6)
               {
                    cout << "*********************************************************************\n";
                    cout << "Enter the following number for operations you want to perform" << endl;
                    cout << "1. To display account holder information" << endl;
                    cout << "2. To deposit money\n";
                    cout << "3. To comply compound interest\n";
                    cout << "4. To withdraw money\n";
                    cout << "5. To inquiry of available amount\n";
                    cout << "6. To exit\nEnter the desired number = ";
                    cin >> y;
                    cout << "*********************************************************************\n";
                    switch(y)
                    {
                         case 1:
                         {
                              putInfo();
                              break;
                         }
                         case 2:
                         {
                              deposit();
                              break;
                         }
                         case 3:
                         {
                              compoundInt();
                              putCmpnd();
                              putBalance();
                              break;
                         }
                         case 4:
                         {
                              withdrawl();
                              break;
                         }
                         case 5:
                         {
                              putBalance();
                              break;
                         }
                         case 6:
                         {
                              cout << "Thank you for using our Banking Services...\n\n";
                              exit(0);
                              break;
                         }
                         default:
                         {
                              cout << "Invalid Choice!\n\n";
                         }
                    }
               }
          }

};
class currentAcc : public account
{
     protected:
          int chequeNo;
     public:
          currentAcc() { }
          currentAcc(string a, int b, string c, float d)
          {
               name = a;
               accNo = b;
               accType = c;
               balance = d;
          }
          void chequeWithdrawl()
          {
               float withdrawlBalance;
               cout << "Enter your cheque number = ";
               cin >> chequeNo;
               cout << "Enter amount to be withdrawn = ";
               cin >> withdrawlBalance;
               balance -= withdrawlBalance;
               cout << "Amount withdrawn successfully! Your available Balance = " << balance << "\n\n";
          }
          float MaB()
          {
               if(balance >=2500 && balance < 5000)
                    return balance -= 100;
               else if(balance >= 1000 && balance < 2500)
                    return balance -= 150;
               else if(balance >=500 && balance < 1000)
                    return balance -= 200;
               else if(balance >=100 && balance < 500)
                    return balance -= 250;
               else if(balance >=0 && balance < 100)
                    return balance -= 350;
               else
                    return balance;
          }
          void putMaB()
          {
               cout << "Your Monthly Average Balance = 5000 INR" << endl;
               cout << "You're available balance after penalty = " << MaB() << endl;
          }
          void isCurrent()
          {
               int y;
               while(y != 7)
               {
                    cout << "*********************************************************************\n";
                    cout << "Enter the following number for operations you want to perform" << endl;
                    cout << "1. To display account holder information" << endl;
                    cout << "2. To deposit money\n";
                    cout << "3. To withdraw money\n";
                    cout << "4. To withdraw money by cheque\n";
                    cout << "5. To inquiry of available amount\n";
                    cout << "6. To check Monthly Average Balance\n";
                    cout << "7. To exit\nEnter the desired number = ";
                    cin >> y;
                    cout << "*********************************************************************\n";
                    switch(y)
                    {
                         case 1 :
                         {
                              putInfo();
                              break;
                         }
                         case 2:
                         {
                              deposit();
                              break;
                         }
                         case 3:
                         {
                              withdrawl();
                              break;
                         }
                         case 4:
                         {
                              chequeWithdrawl();
                              break;
                         }
                         case 5:
                         {
                              putBalance();
                              break;
                         }
                         case 6:
                         {
                              MaB();
                              putMaB();
                              break;
                         }
                         case 7:
                         {
                              exit(0);
                              break;
                         }
                         default:
                         {
                              cout << "Invalid Choice!\n\n";
                         }
                    }
               }
          }
};
int main()
{
     char x;
     savingsAcc a1();
     currentAcc a2();
     cout << "What's your Account type? Enter 's' for Savings while 'c' for Current Account = ";
     cin >> x;
     cout << "\n";
     if(x == 's')
     {
          a1.isSavingsAcc();
     }
     else if(x == 'c')
     {
          a2.isCurrent();
     }
     else
     {
          cout << "Invalid character!\n\n";
     }
     return 0;
}

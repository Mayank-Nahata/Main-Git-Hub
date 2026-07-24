/*
v.push_back(x)      Adds element at end         v.push_back(acc) 
v.size()            Returns number of elements  v.size()
v[i]                Access element at index i   v[0].getName()
v.erase(v.begin()+i)Removes element at index i  v.erase(v.begin() + 2)
*/
#include<iostream>
#include<vector>
#include<string>
#include<functional>
using namespace std ;
class Bank
{
    private :

    int account_number ;
    double balance ;
    string name ;
    int pin ;

    public : 
    Bank()
    {
        account_number = 0;
        balance = 0;
        pin = 0;
        name = "";
    }
    int pin_()
    {
        return pin ;
    }
    int ac()
    {
        return account_number ;
    }
    void bal_setter()
    {
        cout << endl << " Enter Initial Balance :-- ";
        cin >> balance ;
    }
    void pin_setter()
    {
        cout << endl << " Enter The Pin Between ( 1000 - 9999 ) :-- ";
        cin >> pin ;
        if(pin < 1000 || pin > 9999)
        {
            cout << endl <<  pin << " Is Invalid ! " << endl ;
            pin_setter();
        }
    }
    void name_setter()
    {
        cin.ignore(); 
        cout << endl << " Enter Name :-- ";
        getline(cin,name);
    }
    void acc_setter(int acc)
    {
        account_number = acc + 1001 ;
    }
    void show()
    {
        cout << endl << "-------------------------";
        cout << endl << " Account Number : " << account_number;
        cout << endl << " Name           : " << name;
        cout << endl << " Balance        : " << balance;
        cout << endl << "-------------------------" << endl;
    }
    int getAccountNumber()
    {
        return account_number;
    }
    void deposit(double amount)
    {
        if(amount <= 0)
            cout << endl << " Invalid Amount !";
        else
        {
            balance += amount;
            cout << endl << " Deposit Successful ! New Balance : " << balance;
        }
    }
    bool checkPin(int p)
    {
        return pin == p;
    }
    void withdraw(double amount)
    {
        if(amount <= 0)
            cout << endl << " Invalid Amount !";
        else if(amount > balance)
            cout << endl << " Insufficient Balance !";
        else
        {
            balance -= amount;
            cout << endl << " Withdrawal Successful ! New Balance : " << balance;
        }   
    }
    void changePin(int newPin)
    {
        if(newPin < 1000 || newPin > 9999)
            cout << endl << " Invalid PIN !";
        else
        {
            pin = newPin;
            cout << endl << " PIN Changed Successfully !";
        }
    }
};
int main()
{
    int tot_acc ;

    string u_password ;
    cout << " Enter The System's  Password :-- ";
    cin >> u_password ;
    size_t hashed_input = hash<string>{}(u_password);
    size_t correct_hash = hash<string>{}("Mayank_Bank");

    if (hashed_input == correct_hash) 
    {
        cout << "Access Granted!" << endl;
        cout << endl <<" Welcome To Banking Software Of Mayank !!" << endl ;
        cout << " Enter The Total Account's You Have :--  " ;
        cin >> tot_acc ;
        vector <Bank> v ;

        for(int i = 0 ; i < tot_acc ; i++)
        {
            Bank b;
            cout << endl << "Enter Account No. " << i+1 << " Detail !! " << endl ;
            b.acc_setter(i);
            b.name_setter();
            b.pin_setter();
            b.bal_setter();
            v.push_back(b);
            cout << endl <<" Account No." << i+1 << " Detail Over !" << endl ;
        }
        int choice;
        do
        {

            cout << endl << "--------- MENU ---------";
            cout << endl << "1. Show All Accounts";
            cout << endl << "2. Deposit";
            cout << endl << "3. Withdraw";
            cout << endl << "4. Change PIN";
            cout << endl << "5. Add Account";
            cout << endl << "6. Remove Account";
            cout << endl << "0. Exit";
            cout << endl << "Enter Choice :-- ";
            cin >> choice;
            switch(choice)
            {
                case 1 :
                {
                    cout << endl << " Showing All Accounts ... ";
                    for(int i = 0 ; i < v.size() ; i++)
                    {
                        v[i].show();
                    }
                    break ;
                }
                case 2:
                {
                    int acc_no;
                    double amount;
                    cout << endl << " Enter Account Number :-- ";
                    cin >> acc_no;

                    bool found = false;
                    for(int i = 0; i < v.size(); i++)
                    {
                        if(v[i].getAccountNumber() == acc_no)
                        {
                            cout << endl << " Enter Amount To Deposit :-- ";
                            cin >> amount;
                            v[i].deposit(amount);
                            found = true;
                            break;
                        }
                    }
                    if(!found)
                        cout << endl << " Account Not Found !";
                    break;
                }
                case 3:
                {
                    int acc_no, u_pin;
                    double amount;
                    cout << endl << " Enter Account Number :-- ";
                    cin >> acc_no;

                    bool found = false;
                    for(int i = 0; i < v.size(); i++)
                    {
                        if(v[i].getAccountNumber() == acc_no)
                        {
                            found = true;
                            cout << endl << " Enter PIN :-- ";
                            cin >> u_pin;
                            if(v[i].checkPin(u_pin))
                            {
                                cout << endl << " Enter Amount To Withdraw :-- ";
                                cin >> amount;
                                v[i].withdraw(amount);
                            }
                            else
                                cout << endl << " Wrong PIN !";
                            break;

                        }
                    }
                    if(!found)
                        cout << endl << " Account Not Found !";
                    break;
                }
                case 4:
                {
                    int acc_no, old_pin, new_pin;
                    cout << endl << " Enter Account Number :-- ";
                    cin >> acc_no;

                    bool found = false;
                    for(int i = 0; i < v.size(); i++)
                    {
                        if(v[i].getAccountNumber() == acc_no)
                        {
                            found = true;
                            cout << endl << " Enter Old PIN :-- ";
                            cin >> old_pin;
                            if(v[i].checkPin(old_pin))
                            {
                                cout << endl << " Enter New PIN :-- ";
                                cin >> new_pin;
                                v[i].changePin(new_pin);
                            }
                            else
                                cout << endl << " Wrong PIN !";
                            break;
                        }
                    }
                    if(!found)
                        cout << endl << " Account Not Found !";
                    break;

                }
                case 5 : 
                {
                    Bank c ;
                    c.acc_setter(v.size());
                    c.name_setter();
                    c.pin_setter();
                    c.bal_setter();
                    v.push_back(c);
                    break ;
                }
                case 6 :
                {


                    int acc_no, u_pin;
                    cout << endl << " Enter Account Number :-- ";
                    cin >> acc_no;

                    bool found = false;
                    for(int i = 0; i < v.size(); i++)
                    {
                        if(v[i].getAccountNumber() == acc_no)
                        {
                            found = true;
                            cout << endl << " Enter PIN :-- ";
                            cin >> u_pin;
                            if(v[i].checkPin(u_pin))
                            {
                                v.erase(v.begin() + i);
                                cout << endl << " Account Removed Successfully !";
                                
                            }
                            else
                                cout << endl << " Wrong PIN !";
                            break;
                        }
                    }
                    if(!found)
                        cout << endl << " Account Not Found !";
                break;

                }
            }
        } while(choice != 0);
    }
    else    
        cout << endl <<" Wrong Password !! ";

    return 0 ;
}
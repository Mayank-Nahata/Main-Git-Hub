#include<iostream>
using namespace std ;
bool E_O(int num) 
{
    if(num % 2 == 0)
    {
        return false ;
    }
    else
    {
        return true ; 
    }
}
int main()
{
    int num ;
    cout << " Enter A Number :-- " ;
    cin >> num  ; 
    if(E_O(num))
    {
        cout << endl << num << " Is A Odd Number ! "; 
    }
    else
    {
        cout << endl << num << " Is A Even Number !" ;
    }
    return 0 ;
}
#include<iostream>
#include<typeinfo>

using namespace std ;
float S(float a , float d , float n)
{
    float Sum ;
    Sum = ((n/2) * ((2*a) + ((n-1) * d )) ) ;
    return Sum ;
}
float AN(float a , float d , float n)
{
    float ANN ;
    ANN =  a + (n - 1) * d ;
    return ANN ;
}
float A_AN(float An , float d , float n)
{
    float a ;
    a = An - (n-1)*d ;
    return a ;
}
float A_S(float Sn, float d, float n)
{
    float a ;
    a = (2*Sn/n - (n-1)*d) / 2 ;
    return a  ;
}
int N(float a, float d ,float An)
{   
    int n; 
    n = (An - a)/d + 1  ;
    return n ;
}
float D(float a ,float n , float An)
{   
    float d ;
    d = (An - a)/(n-1) ;
    return d ;
}
int main()
{
    float a=0,An=0,Sn=0,d=0 ;
    int n = 0 ;
    int ch = 1 ;
    cout << endl <<" Welcome To Arthmetic Progression World !!!  " << endl ;
    while(ch != 0 )
    {
        cout << endl << endl << " What Do You Want To Find ! " << endl ;
        cout << " 1 --> Sum Of AP " << endl ;
        cout << " 2 --> Find A'n (nth Term Value)  Of AP " << endl ;
        cout << " 3 --> Find a (Starting Number Of AP) Of AP " << endl ;
        cout << " 4 --> Find Nth Term " << endl;
        cout << " 5 --> Find Difference (d) Of AP " << endl ;
        cout << " 0 --> For Exit " << endl ;
        cout << " What Do You Want To Do Enter In Number ( 1 - 5 ) :-- ";
        cin >> ch ;
        switch(ch)
        {
            case 1 :
            {
                cout << endl <<" Enter The First Term (a) :-- " ;
                cin >> a ;
                cout << " Enter The Difference (d) :-- " ;
                cin >> d ;
                cout << " Enter The Nth Term You Want The Sum (n) :-- " ;
                cin >> n ;
                Sn =  S(a,d,n) ;
                cout << endl << " The Sum Of AP From 1 To " << n << "th Term Is :--  " << Sn << endl ;
                break ; 
            }
            case 2 :
            {
                cout << endl <<" Enter The First Term (a) :-- " ;
                cin >> a ;
                cout << " Enter The Difference (d) :-- " ;
                cin >> d ;
                cout << " Enter The Nth Term (n) :-- " ;
                cin >> n ; 
                An = AN(a,d,n) ;
                cout << endl << " The "  << n << "th Term Of AP Is :-- " << An ;
                break ;
            }
            case 3 :
            {
                int sub_ch ;
                cout << endl << " How Would You Want To Find a  " << endl;
                cout << " 1 --> By A'n " << endl ; 
                cout << " 2 --> By S'n " << endl ; 
                cout << " Enter Your Choice :--  " ;
                cin >> sub_ch ; 
                if(sub_ch == 1)
                {
                    cout << endl <<" Enter The A'n :-- " ;
                    cin >> An ;
                    cout << " Enter The Difference (d) :-- " ;
                    cin >> d ;
                    cout << " Enter The Nth Term (n) :-- " ;
                    cin >> n ;  
                    a = A_AN(An,d,n);
                    cout << endl << " The First Term Of AP Is :-- " << a ;
                }
                else if(sub_ch == 2)   
                {
                    cout << endl << " Enter The Sum Of Your AP :--  " << endl ;
                    cin >> Sn ;
                    cout << " Enter The Difference (d) :-- " ;
                    cin >> d ;
                    cout << " Enter The Nth Term (n) :-- " ;
                    cin >> n ;  
                    a = A_S(Sn,d,n);
                    cout << endl << " The First Term Of AP IS :--  " << a ;
                }
                else
                    cerr << endl << " Wrong Option Is Done !! " << endl ;

                break ;
            }
            case 4 :
            {
                cout << endl <<" Enter The A'n :-- " ;
                cin >> An ;
                cout << " Enter The Difference (d) :-- " ;
                cin >> d ;
                cout << " Enter The First Term Of AP :-- " ;
                cin >> a ; 
                n = N(a,d,An);
                cout << endl << " The Nth Term Of AP Is :-- " << n << endl ;
                break ;
            }
            case 5 :
            {
                cout << endl <<" Enter The A'n :-- " ;
                cin >> An ;
                cout << " Enter The Nth Term :-- " ;
                cin >> n ;
                cout << " Enter The First Term Of AP :-- " ;
                cin >> a ; 
                d = D(a,n,An);
                cout << endl << " The Difference Of AP Is :-- " << d << endl ;
                break ;
            }
            default :
            {
                cout << endl << " Wrong Option Is Pressed " ;
                cout << endl << " Enter Right Option " ;
            }
        }
        
    }

    return 0 ;
}
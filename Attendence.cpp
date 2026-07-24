#include<iostream>
#include<string>
#include<cctype>
using namespace std ;
    // Function Start

int c_a(char a_p[],int absent,int student )
{   
    absent = 0  ;
    for(int i = 0 ; i < student ; i++)
    {
        if(a_p[i] == 'A' || a_p[i] == 'a')
        {
            absent++ ;
        }
    }
    return absent ;
}

int c_p(char a_p[],int present,int student )
{
    
    present = 0 ;
    for(int i = 0 ; i < student ; i++)
    {
        if(a_p[i] == 'p' || a_p[i] == 'P')
        {
            present++ ;
        }
    }
    return present ;
}


void show_all_student(string name[], char a_p[], int roll[], int student)
{
    cout << "\n\n ----- FULL STUDENT LIST ----- \n";

    cout << "\nRoll No.\tName\t\tStatus\n";

    for(int i = 0 ; i < student ; i++)
    {
        cout << roll[i] << "\t\t" << name[i] << "\t\t";

        if(a_p[i] == 'P' || a_p[i] == 'p')
        {
            cout << "Present";
        }
        else
        {
            cout << "Absent";
        }

        cout << endl;
    }
}

void show_absent(string name[],char a_p[],int student,int absent,int roll[])
{
    cout << "\n\n ----- The Absent Students Are As Follow ----- " << endl;
    cout << "\n Roll No.  Name\n" ;
    for(int i = 0 ; i < student ; i++)
    {        
        if(a_p[i] == 'a' || a_p[i] == 'A')
        { 
            cout << " " <<roll[i] << "       " << name[i] << "\n" ;
        }
    }
    cout << "\n\n So " << absent << " Student Are Absent "<< endl  ;
}



void show_present(string name[],char a_p[],int student,int present,int roll[])
{
    cout << "\n\n ----- The Present Students Are As Follow ----- " << endl;
    cout << "\n Roll No.  Name\n" ;
    for(int i = 0 ; i < student ; i++)
    {
        if(a_p[i] == 'p' || a_p[i] == 'P')
        {
            cout << " " <<roll[i] << "       " << name[i] << "\n" ;
        }
    }
    cout << "\n So " << present << " Student Are Present << endl " ;
}



void search(string uppername[],int student,char a_p[])
{
    bool flag = false;
    int s_n;
    string search ;
    cout << "\n Tell The Name Of The Student That You Want To Search " << endl ; 
    cin.ignore();
    getline(cin , search) ;

    for(int i = 0 ; i < search.length() ; i++)
    {
        search[i] = toupper(search[i]) ;
    }

    for(int i = 0 ; i < student ; i++)
    {
        if(uppername[i] == search )
        {
            if(a_p[i] == 'a' || a_p[i] == 'A' || a_p[i] == 'p' || a_p[i] == 'P')
            {
                flag = true ;
                s_n = i ;
            }  
        }      
    }
    if(flag)
        {
            if(a_p[s_n] == 'a' || a_p[s_n] == 'A')
            {
                cout << "\n" << search <<" Is Absent " << endl ;
            }  
            else  
            {
                cout << "\n " << search <<" Is Present " << endl ;
            }                       
        }
    else
    {
        cout << "\n No Such Student " << endl ;
    }
    

}


void edit_attendence(string uppername[],char a_p[],int student,int absent,int present)
{

    string att_c_n ;
    cout << "\n Enter The Name Of Student Whose Attendance You Want To Change :-- ";
    cin.ignore();
    getline(cin , att_c_n );
    bool flag = false ;
    int a_c;
    
    for(int i = 0 ; i < att_c_n.length() ; i++)
    {
        att_c_n[i] = toupper(att_c_n[i]) ;
    }
    for(int i = 0 ; i < student ; i++)
    {
        if(uppername[i] == att_c_n )
        {
            flag = true ;
            a_c = i ;
            break ;
        }
    }
    if(flag)
    {
        if(a_p[a_c] == 'a' || a_p[a_c] == 'A' )
        {
            a_p[a_c] = 'P' ;
            cout << "\n\n Attendence Is Changed " ;
            cout << "\n At First "<< att_c_n << " Was Absent " ;
            cout << " \n "<< att_c_n << " Is Now Present \n" ;
        }  
        else if( a_p[a_c] == 'p' || a_p[a_c] == 'P')
        {
             a_p[a_c] = 'A' ;
            cout << "\n\n Attendence Is Changed " ;
            cout << "\n At First "<< att_c_n << " Was Present " ;
            cout << " \n "<< att_c_n << " Is Now Absent \n" ;
        }
    }
    else
    {
        cout << "\n\n No Such Student Found " ; 
    }
    
    absent =  c_a(a_p,absent,student);
    present = c_p(a_p,present,student);
    
    cout << "\n\n Now Total Present :--  " << present ;
    cout << "\n Now Total Absent :--  " << absent ;
    
}




    // Main Program start 

int main()
{
    string password = "i@love@c++" ;

    string userpassword ;

    cout << "\n Enter Password Please :--  " ;
    cin >> userpassword ;


    if(password == userpassword)

    {

    cout << "\n\n Correct Password !! \n" ;

    string name[67] ;
    char a_p[67] ;
    int roll[67];
    int present=0,absent=0 ;
    int student ;
    
    
    cout << " \n Enter The Number Of Student You Have :-- "; 
    cin >> student ;
    cin.ignore();

    //      Input taking frm user 

    for(int i = 0 ; i < student ; i++)
    {
        cout << "\n Name Of Student " << i+1 << " :-- " ;
        getline(cin,name[i]);
        while(1)
        {
            cout << "\n A -- Absent And P -- Present " << endl;
            cout << "\n Is " << name[i] << " Present Or Absent :-- " ;
            cin >> a_p[i];
            cin.ignore();
            
            if(a_p[i] == 'a' || a_p[i] == 'p' || a_p[i] == 'A'|| a_p[i] == 'P' )
            {
                break ;
            }
            else
            {
                cout << "\n Please Enter A Valid Character  " << endl ;
            }

        }

    }


    absent =  c_a(a_p,absent,student);

    present = c_p(a_p,present,student);


        // Counting of Absent and Present Student 

    //  Attendence Report

    cout << "\n ********* Attendence Report ********* " << endl; 
    cout << " Total Student Present :--  " << present << endl;
    cout << " Total Student Absent :--  " << absent << endl ;
    cout << " Total Number Of Student :--  " << student << endl ;
    cout << "  Percent Of Absent Student :-- " << (float(absent)/student)*100<< "%" << endl;
    cout << "  Percent Of Present Student :-- " << (float(present)/student)*100 << "% " << endl;



    //              Copying Sting 


    string uppername[67] ;

    for( int i = 0 ; i < student ; i++)
    {
        uppername[i] = name[i] ;
    }

    //              Conver To Uppercase

    for( int i = 0 ; i < student ; i++)
    {
        for(int j = 0 ; j < uppername[i].length() ; j++)
        {
            uppername[i][j] = toupper(uppername[i][j]) ;
        }
    }


    // Giving Roll Number ****


    for(int i = 0  ; i < student ; i++)
    {
        roll[i] = 1+i ;
    }


    bool choice_n = true ;
    int choice ;


    do
    {
        
        cout << "\n ***** SCHOOL ATTENDENCE SYSTEM ***** " << endl ;
        cout << "\n 1 --> Want To Know How Many Students Are Absent  ";
        cout << "\n 2 --> Want To Know How Many Students Are Present ";
        cout << "\n 3 --> Search The Student  ";
        cout << "\n 4 --> Edit Attendence " ;
        cout << "\n 5 --> Want To See Full Data " ;
        cout << "\n 6 --> Exit " ;
        cout << "\n What You Want To do -->   ";
        cin >> choice ;

        switch(choice)
        {
            case 1:
            {
                show_absent(name , a_p ,student,absent,roll);
                cout << "\n\n If You Do Not Want To Continue ";
                cout << "\n 1 -- No  " ;
                cout << "\n Enter Your Choice :--  " ;
                cin >> choice ;
                if(choice == 1)
                {
                    choice_n = false ;
                }
            }
            break ;
            case 2 :
            {
                 show_present(name , a_p ,student,present,roll);
                 cout << "\n\n If You Do Not Want To Continue ";
                cout << "\n 1 -- No  " ;
                cout << "\n Enter Your Choice :--  " ;
                cin >> choice ;
                if(choice == 1)
                {
                    choice_n = false ;
                }
            }
            break ;
            case 3 :
            {
                search(uppername,student,a_p);
                cout << "\n\n If You Do Not Want To Continue ";
                cout << "\n 1 -- No  " ;
                cout << "\n Enter Your Choice :--  " ;
                cin >> choice ;
                if(choice == 1)
                {
                    choice_n = false ;
                }
            }
            break ;
            case 4:
            {
                edit_attendence(uppername,a_p, student,absent,present);
                absent =  c_a(a_p,absent,student);
                present = c_p(a_p,present,student);
                cout << "\n\n If You Do Not Want To Continue ";
                cout << "\n 1 -- No  " ;
                cout << "\n Enter Your Choice :--  " ;
                cin >> choice ;
                if(choice == 1)
                {
                    choice_n = false ;
                }
            }
            break ;
            case 5:
            {
                show_all_student(name, a_p, roll, student);
                cout << "\n\n If You Do Not Want To Continue ";
                cout << "\n 1 -- No  " ;
                cout << "\n Enter Your Choice :--  " ;
                cin >> choice ;
                if(choice == 1)
                {
                    choice_n = false ;
                }
            }
            break ;
            case 6 :
            {
                choice_n = false ;
            }
            break ;
            default :
            {
                cout << "\n Enter Valid Number Please !! \n" ;
                continue ;
            }
        }
        
    }while (choice_n);
    }   

    else
    {
        cout << "\n\n You Are Not Authorised Person " ;
        cout << "\n First Take Permission And Enter The Password Then You Can Use The Code  " ;
    }

    
    return 0 ; 
}
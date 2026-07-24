#include<iostream>
#include<vector>
#include<string>
using namespace std ;
class Employe
{
    protected :
    string name ;
    double base_salary ;
    int id ;
    public :
    Employe(string n , int id , double bs)
    {
        name = n ;
        base_salary = bs ;
        this -> id = id ; 
    }
    void show()
    {
        cout << " Name Of Employe :-- " << name << endl ;
        cout << " Base Salary :-- " << base_salary << endl ;
        cout << " ID Number :-- " << id << endl ;
    }
};
class Manager : public Employe
{
    protected :
    int team_size ;
    public :
    Manager(int ts,string n , int id , double bs) : Employe(n , id , bs)
    {
        team_size = ts ;
    }
    double tot_sal()
    {
        return base_salary + ( team_size * 5000 ) ;
    }
};
class Developer : public Employe
{
    protected :
    int project_completed ;
    public :
    Developer(int pc , string n , int id , double bs) : Employe(n , id , bs) 
    {
        project_completed = pc; 
    }
    double tot_sal()
    {
        return base_salary + ( project_completed * 2000 ) ;
    }
};
class Intern : public Employe 
{
    protected :
    double stipend ;
    public :
    Intern(double s , string n , int id ) : Employe(n , id , 0 )  
    {
        stipend = s ;
    }
    double tot_sal()
    {
        return stipend ;
    }
};
int main()
{
    vector<Manager> M ;
    vector<Developer> D ;
    vector<Intern> I ;
    
    int choice;
    cout << " Welcome To Employee Management System !! " << endl;

    do
    {
        cout << endl << endl << "--------- MENU ---------";
        cout << endl << "1. Add Manager";
        cout << endl << "2. Add Developer";
        cout << endl << "3. Add Intern";
        cout << endl << "4. Show All Employees";
        cout << endl << "5. Calculate Total Payroll";
        cout << endl << "0. Exit";
        cout << endl << "Enter Choice :-- ";
        cin >> choice;
        
        switch(choice)
        {
            case 1 :
            {
                string name;
                int id, team_size;
                double base_salary;

                cout << " Enter Your Name :-- ";
                cin.ignore();
                getline(cin, name);
                
                cout << " Enter ID :-- ";
                cin >> id;
                
                cout << " Enter Base Salary :-- ";
                cin >> base_salary;
    
                cout << " Enter Team Size :-- ";
                cin >> team_size;
    
                Manager m(team_size, name, id, base_salary);
                M.push_back(m);
    
                cout << " Manager Added Successfully!";
                break;
            }
            case 2 :
            {
                string name;
                int id, project_completed;
                double base_salary;

                cout << " Enter Your Name :-- ";
                cin.ignore();
                getline(cin, name);
                
                cout << " Enter ID :-- ";
                cin >> id;
                
                cout << " Enter Base Salary :-- ";
                cin >> base_salary;
    
                cout << " How Many Project Had You Done :-- ";
                cin >> project_completed;
    
                Developer d(project_completed, name, id, base_salary);
                D.push_back(d);
    
                cout << " Developer Added Successfully!";
                break;
            }
            case 3 :
            {
                string name ;
                int id ;
                double stipend; 
                cout << " Enter Your Name :-- ";
                cin.ignore();
                getline(cin, name);
                
                cout << " Enter ID :-- ";
                cin >> id;
                
                cout << " Enter Stipend :-- ";
                cin >> stipend;

                Intern i(stipend,name,id) ;
                I.push_back(i) ;

                cout << " Intern Added Successfully!";
                break;
            }
            case 4:
            {
                cout << endl << "--- Managers --- " << endl ;
                for(int i = 0; i < M.size(); i++)
                {
                    M[i].show();
                    cout << " Total Salary :-- " << M[i].tot_sal() << endl;
                }
                cout << endl << "--- Developer --- " << endl ;
                for(int i = 0; i < D.size(); i++)
                {
                    D[i].show();
                    cout << " Total Salary :-- " << D[i].tot_sal() << endl;
                }
                cout << endl << "--- Intern --- " << endl;
                for(int i = 0; i < I.size(); i++)
                {
                    I[i].show();
                    cout << " Total Salary :-- " << I[i].tot_sal() << endl;
                }
    
                break;
            }
        }
        
    } while(choice != 0);
    
    return 0;
}

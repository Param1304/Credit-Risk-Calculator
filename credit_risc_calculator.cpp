#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
class applicant
{
    private:
    string address, name;
    int age;
    int m_sal, home_loan, ht, p_loan, pt, chq_bounce, company_tier;
    float Rh = 5.65, Rp = 6.55;
    float ham,h_emi,pam,p_emi;
    int size =20;
    char house, s_working, dep_parents;
    float score = 0;
    public:
    void collect_data();
    void calculate_risc();
    void result();
};
int main()
{
    char flag='f';
    applicant a;
    char ch;
    while(1)
    {
        system("cls");
        gotoxy(45,10);
        cout<<"Credit Risc Calculator";
        gotoxy(40,12);
        cout<<"1- Enter loan applicant's details";
        gotoxy(40,13);
        cout<<"2- Calculate and Display Credit Score ";
        gotoxy(40,14);
        cout<<"3- Exit";
        gotoxy(40,15);
        cout<<"Select an option by entering numeric code :"<<endl;
        gotoxy(40,16);
        cin>>ch;
        switch(ch)
        {
            case('1'):
            {
               a.collect_data();
               flag='t';
               break;
            }
            case('2'):
            {
                if(flag=='f')
                {
                    gotoxy(22,19);
                    cout<<"Loan applicant's details not entered yet.\nPress any key to continue.";
                    getchar();
                }
                else
                {
                    a.calculate_risc();
                    a.result();
                }
                break;
            }
            case('3'):
            {
                exit(1);
                break;
            }
            default:
            {
                gotoxy(22,19);
                cout<<"Invalid choice code.\nPress any key to continue";
                getchar();
            }
        }
    }
}
void applicant::collect_data()
{
    system("cls");
    cout<<"Full Name of applicant : ";
    getline(cin,name);
    cout<<endl;
    cout<<"Age:";
    cin>>age;
    cout<<endl;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Address:";
    getline(cin,address);
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<endl;
    cout<<"Monthly Salary (after tax deductions in INR) = ";
    cin>>m_sal;
    cout<<endl;
    cout<<"Home loan and Time period ";
    cin>>home_loan>>ht;
    cout<<endl;
    ham = (home_loan*ht*Rh)/100;
    h_emi = (ham/(Rh*12));
    cout<<"home loan amount = "<<ham<<" and monthly EMI = "<<h_emi<<endl;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Personal loan and Time period ";
    cin>>p_loan>>pt;
    cout<<endl;
    pam = (p_loan*pt*Rp)/100;
    p_emi = (pam/(Rp*12));
    cout<<"personal loan amount = "<<pam<<" and monthly EMI = "<<p_emi<<endl;;
    cout<<"No. of cheque bounces in last 6 months ";
    cin>>chq_bounce;
    cout<<"\nHouse owned (y or n) ?";
    cin>>house;
    cout<<"\nSpouse working (y or n) ?";
    cin>>s_working;
    cout<<"\nDependent parents (y or n) ?";
    cin>>dep_parents;
    cout<<"\nCompany Tier (1,2,3) ?";
    cin>>company_tier;
}
void applicant::calculate_risc()
{
    float h = (h_emi*100)/m_sal;
    float p = (p_emi*100)/m_sal;
    float l =h+p;
    if(l>0 && l<=25)
    {
        score+=3;
    }
    if(l>25 && l<=50)
    {
        score+=1.5;
    }
    if(l>50)
    {
        score-=1;
    }
    if(age>22 && age<=30)
    {
        score+=2;
    }
    if(age>30 && age<=40)
    {
        score+=0.5;
    }
    if(age>40)
    {
        score-=1.5;
    }
    if(chq_bounce>1)
    {
        score-= 2;
    }
    if(chq_bounce==1)
    {
        score-= 1;
    }
    if(chq_bounce==0)
    {
        score+= 1;
    }
    if(house=='y')
    {
        score+=2;
    }
    else
    {
        score-=3.5;
    }
    if(s_working=='y')
    {
        score+=2.5;
    }
    else
    {
        score-=1.5;
    }
    if(company_tier==1)
    {
        score+=3;
    }
    if(company_tier==2)
    {
        score+=2;
    }
    if(company_tier==1)
    {
        score+=0.5;
    }
    if(dep_parents=='y')
    {
        score-=2.5;
    }
    else
    {
        score+=1.5;
    }
}
void applicant::result()
{
    gotoxy(40,18);
    if(score>=9)
    {
        cout<<"\nThe applicant "<<name<<" is at LOW risk !";
        cout<<"\n score = "<<score;
        getchar();
    }
    if(score>=5 && score<9)
    {
        cout<<"\nThe applicant "<<name<<" is at MODERATE risk ";
        cout<<"\n score = "<<score;
        getchar();
    }
    if(score<5)
    {
        cout<<"\nThe applicant "<<name<<" is at HIGH risk !!!";
        cout<<"\n score = "<<score;
        getchar();
    }
}

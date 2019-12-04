#include <iostream>		//// input output stream access header file
#include <conio.h>		//// using getch()
#include <cstdlib> // system("cls")
#include <string>


using namespace std;		//// access to the std namespace, like cout. another way without isung this line . std::cout both are same.


class Greetings
{


public:
    void intro(string);     // initialization of intro function
    int login();
    char option();          // chose option function
    char backBtn();         // return to fast page
    void close();

};

class Student : public Greetings{

    char name[100];
    float mid=-1,final=-1,assessment=-1;
public:
    char admission(int);            // initialization of admission function
    char viewDetails(int);         // initialization of viewDetails function
    char examination(int);        // initialization of examination function
};


main (void)
{
  Student in, st[50];
  char c;
  int ad_id=0,s_id;
  in.intro("Vesper School Management System");
  in.login();

do{
    c=in.backBtn();


  switch(c){
        case '1':
            ad_id++;
            c=st[ad_id].admission(ad_id);
            break;

        case '2':
            search:
                cout<<"Enter student id between (1-"<<ad_id<<") :";
            cin>>s_id;

            if(s_id>ad_id || s_id <=0){
                char chose;
                cout<<"\nNo student data found\n\n";
                cout<<"1) Go back"<<endl;
                cout<<"2) Search again"<<endl;
                cout<<"Enter your choice :  ";
                cin>>chose;
                    if(chose=='1'){
                        break;
                        }
                    else if(chose=='2'){
                        goto search;
                        }
            }else{
                c=st[s_id].viewDetails(s_id);
            }
            break;

        case '3':
            search2:
                cout<<"Enter student id between (1-"<<ad_id<<") :";
            cin>>s_id;

            if(s_id>ad_id || s_id <=0){
                cout<<"\nNo student data found\n\n";
                goto search2;
            }else{
                c=st[s_id].examination(s_id);
            }
            break;

        case '4':
            in.close();
            break;
        default:
            cout<<"default  value";
  }
}while(c);
  getch ();
  return 0;
}


///// Intro function

void Greetings :: intro (string intro)
  {
    int i, j;

    for (i = 1; i <= 5; i++)
      {
	    for (j = 0; j <= intro.length () + 15; j++)
	        {
	            if (i == 1 || i == 5)
	                {
		                cout << "*";
	                }

	            else if (i != 1 || i != 5)
	                {
		               if (j == 0 || j == intro.length ()+15)
		                {
		                    cout << "*";
		                }
		                else if(i==3 && j==8){
	                        cout<<intro;
	                        j=intro.length ()+7;
	                    }
		               else
		                {
		                 cout <<" ";
		                }
	                }
	        }
	        cout << "\n";
      }

      cout <<"\n\n\n";

  }     ///// End of intro function

            //// Login System

    int Greetings::login(){

        string  username,password="";
        login:
        int ch;
        cout<<"\n\n\t\t\t\t\t Login System\n\n\n";
        cout<<"\t\t\tUsername: ";
        cin.ignore();
        getline(cin,username);
        cout<<"\n\t\t\t\Password: ";

        while(ch=getch())
            {
                if(ch==13)   //// Enter ascii value 13
                {
                    cout<<"\n"<<username<<" " <<password;
                   if(username=="vesper" && password == "admin"){
                        break;
                   }else{
                       int c;
                        Greetings in;
                        cout<<"\n\n\t\tWrong username or password\n\n";

                        cout<<"\t\t1) Try again\n";
                        cout<<"\t\t2) Exit (Any key)\n";
                        cout<<"Enter your choice : ";
                        cin >>c;
                        if(c==1){
                            system("cls");
                            in.intro("Vesper School Management System");
                            password="";
                            goto login;
                        }
                        else{
                            in.close();
                        }
                   }
                }
                else if(ch==8)  //// backspace ascii value 13
                {
                    if(password.length()>0)
                    {
                        cout<<"\b \b";
                        password.erase(password.length()-1);
                    }
                }
                else if(ch==32 || ch == 9)  //// space & tab ascii value 13
                {
                    continue;
                }
                else
                {
                    cout<<"*";
                    password +=ch;
                }
            }
    }


            ////End login system




    //// option function

    char Greetings::option(){

        char ch;

        cout << "1)  Admission" << endl;
        cout << "2)  Student details" << endl;
        cout << "3)  Examination" << endl;
        cout << "4)  Exit" << endl;

      cout <<"\n";

        cout<<"Enter your choice: ";
        cin>>ch;

        return ch;

    }   ////  end of option function

    //// option function

    char Greetings::backBtn(){

        char ch;

        system("cls");
        Student obj;
        obj.intro("Vesper School Management System");
        ch = obj.option();

        return ch;
    }   ////  end of option function

    void Greetings::close(){

        system("cls");
        cout<<"\n\n\t\t\tThank you (^_^)\n\n\n";
            exit(1);
    }

  ///// admission function

char Student :: admission (int id){
    char op;
    system("cls");
    Student obj;
    obj.intro("Add student data");

    cout<<"\n New student id:";
    cout<<id;

    cout<<"\n Enter name:";
    cin.ignore();
    cin.getline(name,100);

    cout<<"\n\n Record insert successfully"<<endl<<endl;

    cout<<"1) Go back"<<endl;
    cout<<"2) Exit"<<endl;
    cout<<"Enter your choice :  ";
    cin>>op;

    if(op=='1'){
            return op;
    }
    else if(op=='2'){
        obj.close();
    }
}

char Student :: viewDetails(int id){

    char op;
    float total=0;
    system("cls");
    Student obj;
    obj.intro("Student Details");

    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<"\n"<<endl;
    if(mid!=-1){
        cout<<"Mid marks (30): "<<mid<<endl;
        total+=mid;
    }else{
        cout<<"Mid mark not inserted "<<endl;
    }
    if(final!=-1){
    cout<<"Final marks (30): "<<final<<endl;
        total+=final;
    }else{
        cout<<"Final mark not inserted "<<endl;
    }
    if(assessment!=-1){
    cout<<"Assessment marks (40): "<<assessment<<endl<<endl;
        total+=assessment;
    }else{
        cout<<"Assessment mark not inserted "<<endl;
    }

    cout<<"\nTotal marks: "<<total<<endl<<endl;

    cout<<"1) Go back"<<endl;
    cout<<"2) Exit"<<endl;
    cout<<"Enter your choice :  ";
    cin>>op;

    if(op=='1'){
            return op;
    }
    else if(op=='2'){
        obj.close();
    }

}

char Student :: examination(int id){

    char op;
    system("cls");
    Student obj;
    obj.intro("Insert marks");

    cout<<"Id: "<<id<<endl;
    cout<<"Name: "<<name<<"\n"<<endl;

    cout<<"\n Enter mid marks (30): ";
    cin>>mid;
    cout<<"\n Enter Final marks (30): ";
    cin>>final;
    cout<<"\n Enter assessment  marks (40): ";
    cin>>assessment;

    cout<<"\n1) Go back"<<endl;
    cout<<"2) Exit"<<endl;
    cout<<"Enter your choice :  ";
    cin>>op;

    if(op=='1'){
            return op;
    }
    else if(op=='2'){
        obj.close();
    }

}

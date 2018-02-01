#include<iostream>
using namespace std;
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define SIZE 5
//-------------class
class book
{

public:
//-------------tavabe
book();
void enter();
char getState();
void print();
//-------------khososiat
int id;
int price;
long date;

char name[10];
char author[10];
char category[10];
//---------------------------
};

book::book()
{
id=0;
price=0;
date=0;
name[0]='\0';
author[0]='\0';
category[0]='\0';
}
//-------------------------------------

void book::enter()
{
  system("cls");

  cout <<"Name : ";
  cin >>name;

  cout<< "id : ";
  cin >>id;

  cout<<"author : ";
  cin >>author;

  cout<<"category : ";
  cin >>category;

  cout<<"date : ";
  cin>>date;

  cout<<"price : ";
  cin>>price;
}
//-------------------------------------

void book::print()
{
   cout << id<<"\t"<< name<<"\t\t"<< author<<"\t\t"<<category<<"\t\t"<<price<<"\t"<<date<<endl;
}
//-------------------------------------

char book::getState()
{
  return name[0];
}
//--------------------------------------

//*******************************************************************************************
book b[SIZE];
int menu();
int FindIndex();
void report();
int reportid(long id);
void editid(long id);
void deleteid(long id);
void reportname(char name[10]);
void reportcategory(char catname[10]);
void reportdate(long start,long end);

//--------------program
int main()
{
int i,c,id;
long s,e;
char catname[10],name[10];
   for(;;) {
      system("cls");
      c = menu();
      switch (c) {
	    case 1 :
					i=FindIndex();
					if (i!=-1 )
					{
					b[i].enter();
					}
					else
					{
						cout << "\n List is full. press a key...";
                        getch();
					}
	    break;
		case 2 :
	    system("cls");
		cout<<"Enter ID : ";
		cin>>id;
	    reportid(id);

	        break;
	    case 3 :
	    system("cls");
		cout<<"Enter Name : ";
		cin>>name;
	    reportname(name);
	        break;
	    case 4 :
		 system("cls");
		 cout<<"Enter Category : ";
			cin>>catname;
	        reportcategory(catname);
	        break;
	    case 5 :
	        report();
	        break;
	    case 6 :
		 system("cls");
		 cout<<"Enter Start Of Period : ";
			cin>>s;
			cout<<"Enter End Of Period : ";
			cin>>e;
	        reportdate(s,e);
			case 7 :
	    system("cls");
		cout<<"Enter ID For Edit : ";
		cin>>id;
	    editid(id);

	        break;
		case 8 :
	    system("cls");
		cout<<"Enter ID  For Delete From List : ";
		cin>>id;
	    deleteid(id);
		break;
			case 9 :
	        exit(0) ;
		} // end of switch
   } //end of for(;;)
system("cls");
cout<<"----";


getch();
getch();
}
//----------------tavabe program
int menu()
{
  int c;
  cout << "1) Enter a Book.\n";
  cout << "2) Search By ID.\n";
  cout << "3) Search By Name.\n";
  cout << "4) Search By Category.\n";
  cout << "5) Report list.\n";
  cout << "6) Caculate Total Price In Period.\n";
  cout << "7) Edit Book.\n";
  cout << "8) Delete Book.\n";
  cout << "9) Exit.\n";

  do {
     cout << "Enter your select(1 - 9) : ";
     cin >> c;
  } while (c < 1 && c >9 );
  return c;
}

//------------------get index
int FindIndex()
{
  int index;
  for(index = 0; index < SIZE && b[index].getState(); index++);
  if(index == SIZE)
    return -1;
  return index;
}
//----------------------------

void report()
{
  int i;
  system("cls");
  cout <<"id"<<"\t"<<"name"<<"\t\t"<<"author"<<"\t\t"<<"category"<<"\t"<<"price"<<"\t"<<"date"<<endl;
  for(i = 0; i < SIZE; i ++) {
    if(b[i].getState())
       b[i].print();
  }
  getch();
}
//-------------------------------

void reportcategory(char catname[10])
{
  int i;
  system("cls");
  cout <<"id"<<"\t"<<"name"<<"\t\t"<<"author"<<"\t\t"<<"category"<<"\t"<<"price"<<"\t"<<"date"<<endl;
  for(i = 0; i < SIZE; i ++) {
    if(b[i].getState())
	if( strcmp(b[i].category,catname)==0)
       b[i].print();
  }
  getch();
}
//----------------------------------------

void reportname(char name[10])
{
  int i;
  system("cls");
  cout <<"id"<<"\t"<<"name"<<"\t\t"<<"author"<<"\t\t"<<"category"<<"\t"<<"price"<<"\t"<<"date"<<endl;
  for(i = 0; i < SIZE; i ++) {
    if(b[i].getState())
	if( strcmp(b[i].name,name)==0)
       b[i].print();
  }
  getch();
}
//---------------------------------------------
void editid(long id)
{
  int i;
  system("cls");
  if ( reportid(id)==-1)
  return ;

  for(i = 0; i < SIZE; i ++) {
    if(b[i].getState())
	if(b[i].id==id)
       b[i].enter();
  }
  getch();
}

//---------------------------------------------
void deleteid(long id)
{
  int i;
  system("cls");
  if ( reportid(id)==-1)
  return ;

    b[i].name[0]='\0';
  getch();
}

//---------------------------------------------
int reportid(long id)
{
  int i;
  system("cls");
  cout <<"id"<<"\t"<<"name"<<"\t\t"<<"author"<<"\t\t"<<"category"<<"\t"<<"price"<<"\t"<<"date"<<endl;
  for(i = 0; i < SIZE; i ++)
  {
    if(b[i].getState())
	if(b[i].id==id)
       b[i].print();

	   if(i==SIZE)
	   {
	   system("cls");
	   cout <<"Not Found";
	   return -1;

	   }

  }
  getch();
  return 1;
}
//------------------------------------------------

void reportdate(long start,long end)
{
  int i;
  long total=0;
  system("cls");
  cout <<"id"<<"\t"<<"name"<<"\t\t"<<"author"<<"\t\t"<<"category"<<"\t"<<"price"<<"\t"<<"date"<<endl;
  for(i = 0; i < SIZE; i ++) {
    if(b[i].getState())
	if( b[i].date>=start && b[i].date<=end)
       {
	   b[i].print();
	   total+=b[i].price;
	   }
  }
  cout <<"Total Cost From "<<start<<" To "<<end<<" : "<<total<<endl;
  getch();
}

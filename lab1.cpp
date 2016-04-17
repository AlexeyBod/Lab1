#include <cstdlib>
#include <iostream>
#include<locale.h>

using namespace std;

class Books
{
      string nameBook;
      string nameAutor;
      int flag;
      int ID;
public:
      Books();
      ~Books();
      void newBooks();
      void viewBook();
};
Books::Books()
	{
	}
Books::~Books()
	{
	}
void Books::newBooks()
    {
    fflush(stdin); 
    cout<<"\n";
    cout<<"������� ����������"<<endl; 
    cout<<"������� ID: "<<endl;
    cin>>ID;   
    fflush(stdin); 
    cout<<"������� �������� �����: "<<endl;
    getline(cin,nameBook);
    cout<<"������� ��� ������:     "<<endl;
    getline(cin,nameAutor); 
    cout<<"������� ������� ����� � ��������� 1- � ������, 0 - ����������: "<<endl;
    cin>>flag;
    cout<<"\n";
    }
void Books::viewBook()
    {
    cout<<"\n";
    cout<<"ID:"<<ID<<endl;	
    cout<<"�������� �����: "<<nameBook<<endl;
    cout<<"��� ������:     "<<nameAutor<<endl;
    cout<<"������� ����� � ��������� 1- � ������, 0 - ����������: "<<flag<<endl;
    cout<<"\n";
    }     


void menu(Books *p);                                        
void showmenu();                                   
void addBook(Books *p);
void viewBook(Books *p,int i);


int main()
{
    setlocale(LC_ALL,"RUS");
    Books book[10];
    menu(book);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void addBook(Books *p)
{
    p->newBooks();

}

void viewBook(Books *p,int i)
{
    int j;	
	for(j=0;j<i;j++)
    {
    p->viewBook();
    p++;
    }
}

void menu(Books *p)
{
	int i=0;
	Books *view;
	view=p;

	char ch = 0;
	while (ch != '0')
	{
	showmenu();
		fflush(stdin);
		cin>>ch;
		switch (ch)
		{
		case '1':
			viewBook(view,i);
			break;
		case '2':
		   i++;
           addBook(p);
           	p++;
			break;			
		case '0':
			cout<<"\nGoodbay!\n\n";
			break;
		default:
			cout<<"\n����\n\n";
			break;
		}
	}
}
void showmenu()
{
	cout<<"����:\n";
	cout<<"������� 1 ����� ������� ��� �������� �� ����� \n";
	cout<<"������� 2 ������� ����� ��������\n";
	cout<<"������� 0 ����� �����\n";
}



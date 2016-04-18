#include <cstdlib>
#include <iostream>
#include<locale.h>

using namespace std;

class Books
  {
        string nameBook;
        string nameAutor;
  public:
        int ID;
        int flag;                                                    //Флаг наличия на руках или в библиотеке
        Books();
        ~Books();
        void newBooks(int currentNumberBook);
        void viewBook();
  };
Books::Books()
	{
	}
Books::~Books()
	{
	}
void Books::newBooks(int currentNumberBook)
    {
    fflush(stdin); 
    cout<<"\n";
    cout<<"Вводите латинницей"<<endl; 
    ID=currentNumberBook;   
    fflush(stdin); 
    cout<<"Введите название книги: "<<endl;
    getline(cin,nameBook);
    cout<<"Введите имя автора:     "<<endl;
    getline(cin,nameAutor); 
    cout<<"Укажите наличие книги в билиотеке 1- в наличие, 0 - отсуствует: "<<endl;
    cin>>flag;
    cout<<"\n";
    }
void Books::viewBook()
  {
      cout<<"\n";
      cout<<"ID:"<<ID<<endl;  
      cout<<"Название книги: "<<nameBook<<endl;
      cout<<"Имя автора:     "<<nameAutor<<endl;
      cout<<"Наличие книги в билиотеке 1- в налчие, 0 - отсуствует: "<<flag<<endl;
      cout<<"\n";
  }   


void menu(Books *pointerOnFirstBook);                                        
void showmenu();                                   
void addBook(Books *currentPointer,int currentNumberBook);
void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks);



int main()
  {
      setlocale(LC_ALL,"RUS");
      Books book[10];
      menu(book);
      system("PAUSE");
      return EXIT_SUCCESS;
  }

void addBook(Books *currentPointer,int currentNumberBook)             //Добавление нового объекта класса Book
  {
      currentPointer->newBooks(currentNumberBook);

  }       

void viewBook(Books *pointerOnFirstBook,int tmpSumAllBooks)           //Вывод на экран всех объектов класса Book
  {
    for(int j=0;j<tmpSumAllBooks;j++)
      {
      pointerOnFirstBook->viewBook();
      pointerOnFirstBook++;
      }
  }      
void menu(Books *pointerOnFirstBook)
  {
    int tmpSumAllBooks=0;
    Books *currentPointer;
    currentPointer=pointerOnFirstBook;

    char ch = 0;
    while (ch != '0')
    {
    showmenu();
      fflush(stdin);
      cin>>ch;
      switch (ch)
      {
      case '1':
        viewBook(pointerOnFirstBook,tmpSumAllBooks);
        break;
      case '2':
        tmpSumAllBooks++;
        addBook(currentPointer,tmpSumAllBooks);
        currentPointer++;
        break;
      case '0':
        cout<<"\nGoodbay!\n\n";
        break;
      default:
        cout<<"\nМимо\n\n";
        break;
      }
    }
  }
void showmenu()
  {
 	cout<<"Меню:\n";
 	cout<<"Введите 1 чтобы вывести все карточки на экран \n";
 	cout<<"Введите 2 создать новую карточку\n";
 	cout<<"Введите 0 чтобы выйти\n";
  }

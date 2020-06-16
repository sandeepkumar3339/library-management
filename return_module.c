#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void end();
void view_borrow();
void new_book();
void check();
void gotoxy(short x,short y);
void general_menu();
void open_screen();

void return_book1();

void suggest();
void fmenu();
void faculty_delete();
void cre_acc_faculty();
void faculty_login();
void faculty_menu();

void view_suggest();
void smenu();
void student_delete();
void cre_acc_student();
void student_login();
void student_menu();

void lent();
void borrow();
void delete_book();
void delete_account();
void read_book();
void lmenu();
void cre_acc_librarian();
void librarian_login();
void librarian_menu();

void return_book1()
{
    system("cls");
    printf("\t\t\t\t\t\tLIBRARY SYSTEM\n");
    printf("\t\t\t\t\t  ************************\n\n\n");
    struct book
    {
        int book_id;
        char book_name[100];
        char author_name[50];
        int no_of_copy;
        int ca;
        int cna;
    }b;

   int bookid,id,d,m,y;
   FILE *fp, *temp1,*temp2,*ek;

   fp=fopen("book.txt","r");
   temp1=fopen("copy1.txt","w+");

   printf("Enter date:\n");
   printf("Enter day:");
   scanf("%d",&d);
   printf("Enter month:");
   scanf("%d",&m);
   printf("Enter year:");
   scanf("%d",&y);

  printf("Enter the person's ID  : ");
  scanf("%d",&id);
  printf("Enter Book ID to return : ");
  scanf("%d",&bookid);
  while(fscanf(fp,"%d %s %s %d %d %d\n", &b.book_id, b.book_name, b.author_name, &b.no_of_copy, &b.ca,&b.cna)!=EOF)
  {
      if(bookid!=b.book_id)
      {
        fprintf(temp1,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
      else
      {

            b.no_of_copy++;
            b.ca--;
            fprintf(temp1,"%d %s %s %d %d %d\n", b.book_id, b.book_name, b.author_name, b.no_of_copy, b.ca,b.cna);
      }
    }
    fclose(fp);
    fclose(temp1);
    remove("book.txt");
    rename("copy1.txt","book.txt");





  int flag=0,dd,mm,yy;

  ek=fopen("borrowed.txt","r");
  temp2=fopen("cpy1.txt","w");
  while(fscanf(ek,"%d %d %s %s %d %d %d\n", &id,&b.book_id, b.book_name, b.author_name,&dd,&mm,&yy)!=EOF)
  {
    if(bookid!=b.book_id)
    {
       fprintf(temp2,"%d %d %s %s %d %d %d\n", id,b.book_id, b.book_name, b.author_name,dd,mm,yy);
    }
    else
    {
      flag=1;
    }
  }
  fclose(ek);
  fclose(temp2);
  if(flag==1)
  {
    remove("borrowed.txt");
    rename("cpy1.txt","borrowed.txt");
  }
  printf("\nSUCCESSFUL");
  lmenu();
}




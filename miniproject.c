//BOOK STORE MANAGEMENT
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
void add_book();
void read_books();
void modify_quantity();
void delete_item();
int option();
struct store
      {
            char name[30];
            float price;
            int quantity;
            int code;
      };
void main()
{
      int c;
      char con='Y';
      while(con=='Y')
      {
            c=option();
            switch(c)
            {
                  case 1:
                  add_book();
                  break;
                  case 2:
                  read_books();
                  break;
                  case 3:
                  modify_quantity();
                  break;
                  case 4:
                  delete_item();
                  break;
            }
            printf("\nType 'Y' to continue with operations:");
            scanf("\n%c",&con);
      }
}
int option()
{
      int ch;
      printf("\nOptions available:");
      printf("\n1 to add book to store \n2 to read books from store \n3 to modify book quantity \n4 to remove book from the store");
      printf("\nEnter choice: ");
      scanf("%d",&ch);
      return ch;
}
void add_book()
{
      struct store book;
      FILE *ft;
      char x='Y';
      ft=fopen("book store","a+");
      do
      {
            char ch;
            printf("\nEnter book name,code,price,quantity to be stored: ");
            scanf("%s %d %f %d",book.name,&book.code,&book.price,&book.quantity);
            fprintf(ft,"%-6s    %d    %8.2f    %7d\n",book.name,book.code,book.price,book.quantity);
            printf("Type 'Y' to repeat the operation\n");
            scanf("\n%c",&ch);
            x=ch;
      }while(x=='Y');
      fclose(ft);
}
void read_books()
{
      struct store book;
      FILE *ft;
      ft=fopen("book store","r");
      printf("NAME      CODE      PRICE     QUANTITY");
      while(feof(ft)==0)
      {
            fscanf(ft,"%s     %d     %f     %d\n",book.name,&book.code,&book.price,&book.quantity);
            printf("\n%-6s      %d    %8.2f    %7d",book.name,book.code,book.price,book.quantity);
      }
      fclose(ft);
}
void modify_quantity()
{
      struct store book;
      FILE *ft,*fp;
      ft=fopen("book store","r");
      fp=fopen("temp","w+");
      int code;
      int quant;
      printf("\nenter the book code who's quantity is to be modified and the new quantity:\n");
      scanf("%d %d",&code,&quant);
      while(!feof(ft))
      {
            fscanf(ft,"%s     %d     %f     %d\n",book.name,&book.code,&book.price,&book.quantity);
            if(book.code!=code)
            fprintf(fp,"%-8s    %d    %8.2f    %7d\n",book.name,book.code,book.price,book.quantity);
            else
            {
                  book.quantity=quant;
                  fprintf(fp,"%-8s    %d    %8.2f    %7d\n",book.name,book.code,book.price,book.quantity);
            }
      }
      fclose(ft);
      fclose(fp);
      remove("book store");
      rename("temp","book store");
}
void delete_item()
{
      struct store book;
      FILE *ft,*fp;
      int code;
      ft=fopen("book store","r");
      fp=fopen("temp","w+");
      printf("\nenter the code of book to be deleted:\n");
      scanf("%d",&code);
      while (!feof(ft))
      {
            fscanf(ft,"%s     %d     %f     %d\n",book.name,&book.code,&book.price,&book.quantity);
            if(code!=book.code)
            fprintf(fp,"%-8s    %d    %8.2f    %7d\n",book.name,book.code,book.price,book.quantity);
      }
      fclose(ft);
      fclose(fp);
      remove("book store");
      rename("temp","book store");
}
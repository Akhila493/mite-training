#include<stdio.h>
struct Fiction_t {
    char title[258];
    char author[128];
    float price;
};
typedef struct Fiction_t Fiction;

struct NonFiction_t {
    char title[258];
    char subject[128];
    float price;
};
typedef struct NonFiction_t NonFiction;

union BookType_t{
    Fiction fiction;
    NonFiction nonFiction;
};
typedef union BookType_t BookType;

struct Book_t{
    int type;
    BookType booktype;
};
typedef struct Book_t Book;

Book books[1000];
int bookCount;

void addBooks();
void displayBooks();
int main() {
    addBooks();
    displayBooks();
    return 0;
}
void addBooks(){
    printf("enter number of books:");
    scanf("%d",&bookCount);

    for(int i=0;i<bookCount;i++){
        printf("type of book(1-fiction,2-non fiction):");
        scanf("%d",&books[i].type);

        switch(books[i].type) {
            case 1:{
                printf("enter fiction book details(title,author,price)\n");
                scanf("%s%s%f",books[i].booktype.fiction.title,books[i].booktype.fiction.author,&books[i].booktype.fiction.price);
                
            } break;
            case 2: {
                printf("enter non fiction book details(title,subject,price)\n");
                scanf("%s%s%f",books[i].booktype.nonFiction.title,books[i].booktype.nonFiction.subject,&books[i].booktype.nonFiction.price);

            }break;
        }
    }
}
void displayBooks() {
    for(int i=0;i<bookCount;i++) {
        switch(books[i].type) {
            case 1: {
                printf("fiction book:%s,Author:%s,Price:$%.2f\n",books[i].booktype.fiction.title,
                    books[i].booktype.fiction.author,&books[i].booktype.fiction.price);
            }break;
            case 2: {
                printf("non fiction book:%s,Subject:%s,Price:$%.2f\n",books[i].booktype.nonFiction.title,
                    books[i].booktype.nonFiction.subject,&books[i].booktype.nonFiction.price);
            }break;
        }

    }
}

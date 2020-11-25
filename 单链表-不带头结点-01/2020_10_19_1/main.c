//
//  main.c
//  2020_10_19_1
//
//  Created by dulei on 2020/10/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[50];
    char auther[50];
    struct Book *next;
};


void getInput(struct Book *book);
void addBookFromHead(struct Book **library);
void addBookFromTail(struct Book **library);
struct Book *searchBook(struct Book *library, const char *target);
void inserBookV2(struct Book **library, const char *title);
void printBook(struct Book *book);
void printLibrary(struct Book *library);
void releseLibrary(struct Book **library);
void addBookFromTailV2(struct Book **library);


void getInput(struct Book *book) {
    printf("请输入书的名称:\n");
    scanf("%s", book->title);
    printf("请输入作者的名称:\n");
    scanf("%s", book->auther);
}


/// 不带头结点单链表---头插法
/// @param library library description
void addBookFromHead(struct Book **library) {
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }
    getInput(book);
    
    if (*library != NULL) {
        book->next = *library;
        *library = book;
    } else {
        *library = book;
        book->next = NULL;
    }
}


/// 不带头结点单链表---尾插法
/// @param library library description
void addBookFromTail(struct Book **library)
{
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }
    getInput(book);
    
    if (*library != NULL) {
        struct Book *temp = *library;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = book;
        book->next = NULL;
    } else {
        *library = book;
        book->next = NULL;
    }
}

void addBookFromTailV2(struct Book **library)
{
    static struct Book *tailBook = NULL;
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }
    getInput(book);
    
    if (*library != NULL) {
        tailBook->next = book;
        book->next = NULL;
    } else {
        *library = book;
        book->next = NULL;
    }
    
    tailBook = book;
}

struct Book *searchBook(struct Book *library, const char *target)
{
    struct Book *book = NULL;
    while (library != NULL) {
        if (strcmp(library->title, target) == 0) {
            book = library;
            break;
        }
        library = library->next;
    }
    return book;
}

void insertBook(struct Book **library, const char *title)
{
    struct Book *previous = NULL;
    struct Book *current = NULL;
    current = *library;
    
    while (current != NULL && strcmp(current->title, title) < 0) {
        previous = current;
        current = current->next;
    }
    
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(book->title, title);
    
    if (previous == NULL) {
        *library = book;
        book->next = current;
    } else {
        previous->next = book;
        book->next = current;
    }
}

void inserBookV2(struct Book **library, const char *title)
{
    struct Book **p_book = library;
    while ((*p_book) != NULL && strcmp((*p_book)->title, title) < 0) {
        p_book = &(*p_book)->next;
    }
    
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        exit(EXIT_FAILURE);
    }
    strcpy(book->title, title);
    strcpy(book->auther, "");
    
    book->next = *p_book;
    *p_book = book;
}

void removeBook(struct Book **library, const char *title)
{
    struct Book *previous = NULL;
    struct Book *current = NULL;
    current = *library;
    while (current != NULL && strcmp(current->title, title) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("未找到\n");
        return;
    } else {
        if (previous == NULL) {
            *library = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

void removeBookV2(struct Book **library, const char *title)
{
    struct Book **linkp = library;
    while (*linkp != NULL && strcmp((*linkp)->title, title) != 0) {
        linkp = &(*linkp)->next;
    }
    
    if (*linkp == NULL) {
        printf("未找到\n");
        return;
    } else {
        struct Book *temp = *linkp;
        *linkp = (*linkp)->next;
        free(temp);
    }
}

void printLibrary(struct Book *library)
{
    while (library != NULL) {
        
        printf("Book=>title:%s,auther:%s\n", library->title, library->auther);
        library = library->next;
    }
    printf("ok");
}

void printBook(struct Book *book)
{
    printf("\n#### book=>%s,%s\n", book->title, book->auther);
}

void releseLibrary(struct Book **library)
{
    while (*library != NULL) {
        struct Book *temp = *library;
        *library = (*library)->next;
        free(temp);
    }
}

int main(int argc, const char * argv[]) {
    
    struct Book *library = NULL;
    char ch;
    
    addBookFromTailV2(&library);
    addBookFromTailV2(&library);
    addBookFromTailV2(&library);
    removeBookV2(&library, "d");
    
    while (1) {
        printf("请问是否需要录入书籍信息?(Y/N):");
        
        do {
            ch = getchar();
        } while (ch != 'Y' && ch != 'N');
        
        if (ch == 'Y') {
//            insertBook(&library, "c");
//            inserBookV2(&library, "c");
        } else {
            break;;
        }
    }
    
    printf("请问是否需要打印书籍?(Y/N)");
    do {
        ch = getchar();
    } while (ch != 'Y' && ch != 'N');
    
    if (ch == 'Y') {
        printLibrary(library);
    }
    
    char *target = "abc";
    struct Book *book = searchBook(library, target);
    if (book != NULL) {
        printBook(book);
    }
    
    releseLibrary(&library);
    
    return 0;
}

//
//  main.c
//  2020_10_27_1
//
//  Created by dulei on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K_NAME_SIZE 50
#define K_PHONE_SIZE 11

struct Person {
    char name[K_NAME_SIZE];
    char phone[K_PHONE_SIZE];
    struct Person *next;
};

void getInput(struct Person *person);
void printPerson(struct Person *person);
void addPerson(struct Person **contacts);
void deletePerson(struct Person **contacts);
void changePerson(struct Person *contacts);
struct Person *findPerson(struct Person *contacts);
void displayContacts(struct Person *contacts);
void displayContactsMid(struct Person *contact, struct Person **midContact);
void releaseContacts(struct Person **contacts);

void getInput(struct Person *person)
{
    printf("请输入联系人的姓名:\n");
    scanf("%s", person->name);
    printf("请输入联系人手机号码:\n");
    scanf("%s", person->phone);
}

void printPerson(struct Person *person)
{
    printf("-------------------------------\n");
    printf("姓名：%s\n", person->name);
    printf("手机号码：%s\n", person->phone);
    printf("-------------------------------\n");
}

void addPerson(struct Person **contacts)
{
    struct Person *person = (struct Person *)malloc(sizeof(struct Person));
    if (person == NULL) {
        exit(EXIT_FAILURE);
    }
    getInput(person);
    
    if (*contacts == NULL) {
        person->next = NULL;
        *contacts = person;
    } else {
        struct Person *temp = *contacts;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        temp->next = person;
        person->next = NULL;
    }
}

void deletePerson(struct Person **contacts)
{
    printf("请输入删除的联系人姓名\n");
    char name[K_NAME_SIZE];
    scanf("%s", name);
    
    while (*contacts != NULL && strcmp((*contacts)->name, name) != 0) {
        contacts = &(*contacts)->next;
    }
    if (*contacts != NULL) {
        struct Person *person = *contacts;
        *contacts = (*contacts)->next;
        free(person);
    }
}

struct Person *findPerson(struct Person *contacts)
{
    printf("输入查询的姓名：\n");
    char name[K_NAME_SIZE];
    scanf("%s", name);
    
    struct Person *person = NULL;
    while (contacts != NULL) {
        if (strcmp(contacts->name, name) == 0) {
            person = contacts;
            break;
        }
        contacts = contacts->next;
    }
    return person;
}

void changePerson(struct Person *contacts)
{
    struct Person *person = findPerson(contacts);
    if (person == NULL) {
        printf("联系人未找到\n");
        return;
    }
    
    char phone[K_PHONE_SIZE];
    printf("请输入新的电话号码：\n");
    scanf("%s", phone);
    
    strcpy(person->phone, phone);
}

void displayContacts(struct Person *contacts)
{
    printf("*******************************************\n");
    while (contacts != NULL) {
        printf("联系人姓名:%s\n", contacts->name);
        printf("联系人手机号码:%s\n", contacts-> phone);
        contacts = contacts->next;
    }
    printf("*******************************************\n");
}

void displayContactsMid(struct Person *contact, struct Person **midContact)
{
    struct Person *fast;
    struct Person *mid;
    mid = fast = contact;
    
    while (fast->next != NULL) {
        if (fast->next->next != NULL) {
            fast = fast->next->next;
            mid = mid->next;
        } else {
            fast = fast->next;
        }
    }
    
    *midContact = mid;
}

void releaseContacts(struct Person **contacts)
{
    while (*contacts != NULL) {
        struct Person *temp = *contacts;
        *contacts = (*contacts)->next;
        free(temp);
    }
}

int main(int argc, const char * argv[]) {
    
    printf("*******************************************\n");
    printf("|- 欢迎使用通讯录管理程序 —|\n");
    printf("|--- 1:增加新的联系人 ---|\n");
    printf("|--- 2:查找已有联系人 ---|\n");
    printf("|--- 3:更改已有联系人 ---|\n");
    printf("|--- 4:删除已有联系人 ---|\n");
    printf("|--- 5:显示当前通讯录 ---|\n");
    printf("|--- 6:显示中间结点联系人 ---|\n");
    printf("|--- 7:退出当前程序 ---|\n");
    printf("*******************************************\n");
    
    struct Person *contacts = NULL;
    while (1) {
        printf("请输入指令代码:\n");
        int input = 0;
        scanf("%d", &input);
        switch (input) {
            case 1:
                addPerson(&contacts);
                break;
            case 2:
            {
                struct Person *person =  findPerson(contacts);
                if (person == NULL) {
                    printf("*****通讯录中未找到联系人\n");
                } else {
                    printf("*****找到联系人\n");
                    printPerson(person);
                }
            }
                break;
            case 3:
                changePerson(contacts);
                break;
            case 4:
                deletePerson(&contacts);
                break;
            case 5:
                displayContacts(contacts);
                break;
            case 6:
            {
                struct Person *midPerson = NULL;
                displayContactsMid(contacts, &midPerson);
                if (midPerson != NULL) {
                    printf("%s", midPerson->name);
                }
            }
                break;
            default:
                releaseContacts(&contacts);
                return 0;
        }
        printf("操作成功\n");
    }
    return 0;
}

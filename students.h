#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 5
typedef struct student{
   char s_num[20];
   char name[20];
   int room;
   char password[20];
   int delivery;
  }T_Record;

int m_is_available();
int m_first_available();
int m_count();
void m_create(char *sn, char *n,int r,char*pw,int d);
T_Record* m_search_by_num(char* sn);
int s_num_size(char* sn);
int m_same_password(char* sn, char* pw);
void  m_init();
char* m_getname(T_Record* p);
char* m_getsnum(T_Record* p);
int m_getroom(T_Record* p);
char* m_getpassword(T_Record* p);
int m_getdelivery(T_Record* p);
int m_get_all_by_room(T_Record*a[], int r);
char* m_to_string(T_Record*p);
char* m_to_string2(T_Record*p);
int m_get_onemore(T_Record*a[]);
char* m_to_ad_string(T_Record* p);
void m_get_all(T_Record* a[]);
int m_get_admin_password(char*ad_pw);
void m_update_delivery(T_Record*p,int d);
void m_get_all2(T_Record* a[]);
void sort_by_num();
void swap(T_Record * a,T_Record * b);
char* m_to_string_save(T_Record*p);
void m_delete(T_Record* p);
void m_delete_empty_space();
int find_num(T_Record* p);
int find_delivery(T_Record* p);
void sort_by_name();
void sort_by_room();
int check_password(T_Record*p,char*pw);
void m_update(T_Record*p,char *n,int r,char*pw);

#include "students.h"
T_Record* students[MAX_MEMBERS];
int _count = 0 ;

int m_is_available(){
   int i=0;
   for(i=0;i<MAX_MEMBERS;i++){
     if(students[i] ==NULL) return 1;
   }
  return 0;
}

int m_first_available(){
   int i;
   for(i=0; i<MAX_MEMBERS; i++){
     if(students[i]==NULL) return i;
     }
   return -1;
}

int m_count(){
   return _count;
}
void current_time(){
 time_t ct;
 struct tm *t;
 ct = time(NULL);
 t = localtime(&ct);
 printf("%d-%d-%d %d:%d:%d\n",t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
}
void m_create(char*sn, char*n, int r, char*pw,int d){
   int index= m_first_available();
   students[index] = (T_Record*)malloc(sizeof(T_Record));
   T_Record* p = students[index];
   strcpy(p->s_num,sn);
   strcpy(p->name, n);
   p->room = r;
   strcpy(p->password, pw);
   p->delivery = d;
   _count++;
#ifdef DEBUG
printf("[NEW MEMBER]  %s\n",p->name);
#endif
}

T_Record* m_search_by_num(char* sn){
  int i;
  for(i=0; i<_count; i++){
   if(students[i]!=NULL && strcmp(students[i]->s_num, sn) ==0) return students[i];
  }
 return NULL;
}

int s_num_size(char* sn){
  if(strlen(sn)!=8) return 0;
  return 1;
}

int m_same_password(char* sn, char* pw){
  char new_sn[3]={0};
  for(int i=0;i<3;i++){
   new_sn[i] = sn[i+5];
  }
 new_sn[4]='\0';
#ifdef DEBUG
printf("[Same password cheking : NEW NUMBER] %s\n",new_sn);
#endif
 char new_pw[3]={0};
for(int j=0;j<8;j++){
 for(int i=0;i<3;i++){
  new_pw[i]=pw[i+j];
}
if(strcmp(new_pw,new_sn)==0) return 0;
}
#ifdef DEBUG
printf("[Same password chaking : NEW PW] %s\n",new_pw);
#endif
return 1;
}

void m_init(){
  int i=0;
  for(i=0; i<MAX_MEMBERS; i++){
    if(students[i]!=NULL) {
        free(students[i]);
     }
   students[i] = NULL;
  }
 _count = 0;
}

char* m_getname(T_Record* p){
  return p->name;
}

char* m_getsnum(T_Record* p){
  return p->s_num;
}

int  m_getroom(T_Record* p){
  return p->room;
}

char* m_getpassword(T_Record* p){
  return p->password;
}
int  m_getdelivery(T_Record* p){
  return p->delivery;
}

int m_get_all_by_room(T_Record* a[], int r){
  int i, count =0;
  for(i=0; i<_count;i++){
   if(students[i]!=NULL && (students[i]->room==r)){
     a[count]=students[i];
     count++;
    }
   }
  return count;
}

char* m_to_string(T_Record*p){
   static char str[80];
   sprintf(str,"[%d] %s / %s / %d", p->room, p->s_num, p->name, p->delivery);
   return str;
 }

char* m_to_string2(T_Record*p){
   static char str[80];
   sprintf(str,"[%d] %s %s *%d delivery is arrived.",p->room, p->s_num, p->name, p->delivery);
   return str;
}

int m_get_onemore(T_Record*a[]){
  int i, c=0;
  for(i=0;i<_count;i++){
   if(students[i]!=NULL && (students[i]->delivery>=1)) {
    #ifdef DEBUG
    printf("[One more] %s's delivery : %d\n",students[i]->s_num,students[i]->delivery);
    #endif
      a[c]=students[i];
      c++;
    }
   }
  return c;
}

char* m_to_ad_string(T_Record* p){
  static char str[80];
  sprintf(str,"%s / %s / %d/ %s / %d", p->s_num, p->name,p->room,p->password, p->delivery);
   return str;
}
void m_get_all(T_Record* a[]){
  int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(students[i]!=NULL){
            a[c]=students[i];
            c++;
        }
#ifdef DEBUG
if(students[i]==NULL) printf("[Get all] %d is null\n",i);
#endif
    }

}
int m_get_admin_password(char*ad_pw){
    char admin_password[20]="vision00"; 
    if(strcmp(ad_pw,admin_password)==0) return 1;
    return 0;
}

void m_update_delivery(T_Record*p,int d){
  p->delivery+=d;
}

void sort_by_num(){
#ifdef DEBUG
 printf("[Before]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
  for(int i=0;i<_count;i++){
   for(int j=0;j<_count-1-i;j++){
    int num1=atoi(students[j]->s_num);
    int num2=atoi(students[j+1]->s_num);
   if(num1>num2){
     swap(students[j],students[j+1]);
    }
  }
 }
#ifdef DEBUG
 printf("[After]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
}

void swap(T_Record* s1, T_Record* s2){
#ifdef DEBUG
printf("[sort] %s is s1, %s is s2\n",s1->s_num,s2->s_num);
#endif
  T_Record s3;
  s3=*s1;
  *s1=*s2;
  *s2=s3;
#ifdef DEBUG
printf("[sort] %s is s1, %s is s2\n",s1->s_num,s2->s_num);
#endif

}

char* m_to_string_save(T_Record* p){
  static char str[80];
  sprintf(str,"%s %s %d %s %d", p->s_num,p->name,p->room,p->password,p->delivery);
  return str;
}

void m_delete(T_Record* p){
  int i, index;
  for(i=0;i<MAX_MEMBERS; i++){
    if(students[i]==p) {
      index =i;
      break;
     }
   }
  free(p);
  students[index] =NULL;
  _count--;
#ifdef DEBUG
printf("[Delete check] %s\n",students[index]->s_num);
#endif
}

void m_delete_empty_space(){
#ifdef DEBUG
 printf("[before]\n");
 for(int i=0;i<MAX_MEMBERS;i++){
 if(students[i]!=NULL){
 printf("%d. %s\n",i+1,students[i]->s_num);
 }
 else{
  printf("%d. %s\n",i+1,"No members");

}
}
#endif
 T_Record* temp;
 for(int i=0;i<MAX_MEMBERS-1;i++){
  if(students[i]==NULL){
   for(int j=i;j<MAX_MEMBERS;j++){
    if(students[j]!=NULL){
   temp=students[i];
   students[i]=students[j];
   students[j]=temp;
   break;
 }
   }
 } 
}
#ifdef DEBUG
printf("[After]\n");
 for(int i=0;i<MAX_MEMBERS;i++){
 if(students[i]!=NULL){
 printf("%d. %s\n",i+1,students[i]->s_num);
 }
 else{
  printf("%d. %s\n",i+1,"No members");

}
}
#endif
}

int find_num(T_Record*p){
 char s_num[20];
 strcpy(s_num,p->s_num);
 char s1[3];
 for(int i=1;i<3;i++){
  s1[i-1]=s_num[i];
 }
 s1[2]='\0';
#ifdef DEBUG
printf("[School number(string)] %s\n",s1);
#endif
int num= atoi(s1);
#ifdef DEBUG
printf("[School number (int)] %d\n",num);
#endif
return num;
}

int find_delivery(T_Record* p){
#ifdef DEBUG
printf("%d\n",p->delivery);
#endif 
 return p->delivery;
}

void sort_by_name(){
#ifdef DEBUG
 printf("[Before]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
 for(int i=0;i<_count;i++){
   for(int j=0;j<_count-1-i;j++){
   if(strcmp(students[j]->name,students[j+1]->name)>0){
    swap(students[j],students[j+1]);
    }
  }
 }
#ifdef DEBUG
 printf("[After]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
}

void sort_by_room(){
#ifdef DEBUG
 printf("[Before]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
 for(int i=0;i<_count;i++){
  for(int j=0;j<_count-1-i;j++){
    if(students[j]->room>students[j+1]->room){
    swap(students[j],students[j+1]);
  }
}
}
#ifdef DEBUG
 printf("[After]\n");
for(int i=0;i<_count;i++){
 printf("%d. %s\n",i+1,students[i]->s_num);
}
#endif
}

int check_password(T_Record*p,char * pw){
  if(strcmp(p->password,pw)==0) return 1;
return 0;
}

void m_update(T_Record*p,char*n,int r,char*pw){
  strcpy(p->name,n);
  p->room=r;
  strcpy(p->password,pw);
}
int take_delivery(T_Record*p,int d){
 #ifdef DEBUG
  printf("[BEFORE :find delivery]\n");
  printf("delivery :%d\n",p->delivery);
 #endif
if(d>p->delivery) return 0;

 if(d==0){
  p->delivery=0;
  }
 else{
  p->delivery-=d;
 }
 #ifdef DEBUG
  printf("[AFTER :find delivery]\n");
  printf("delivery :%d\n",p->delivery);
 #endif
 return 1;
}

void print_delivery_box(T_Record*p,int b){
  p->d_lo=b;
  int box[3][5]={0}; 
  int row = change_row(b);
  int col = change_col(b);
  box[row][col]=p->delivery;
  printf("--------------------------------------------------\n");
  printf("|         |         |         |         |         |\n");
  printf("|   (%d)   |   (%d)   |   (%d)   |   (%d)   |   (%d)   |\n",1,2,3,4,5);
  printf("|         |         |         |         |         |\n");
  printf("--------------------------------------------------\n");
  printf("|         |         |         |         |         |\n");
  printf("|   (%d)   |   (%d)   |   (%d)   |   (%d)   |   (%d)   |\n",6,7,8,9,10);
  printf("|         |         |         |         |         |\n");
  printf("--------------------------------------------------\n");
  printf("|         |         |         |         |         |\n");
  printf("|   (%d)  |   (%d)  |   (%d)  |   (%d)  |   (%d)  |\n",11,12,13,14,15);
  printf("|         |         |         |         |         |\n");
  printf("--------------------------------------------------\n");
}

int change_row(int b){
 if(b>=1&&b<=5){
   return 0;
  }
 else if(b>=6&&b<=10){
   return 1;
   }
 else return 2;
}

int change_col(int b){
 if(b%5==1){
   return 0;
  }
 else if(b%5==2){
   return 1;
  }
 else if(b%5==3){
   return 2;
  }
else if(b%5==4){
   return 3;
  }
else return 4;
}

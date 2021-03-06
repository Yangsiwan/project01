#include "students.h"
void create_record();
void search_student();
void search_room();
void delivery_list();
void all_list(); //관리자가 비밀번호를 쳐야만 들어갈 수 있음.(비밀번호: vision00 )
void update_delivery();
void load_file();//file loading
void save_backup_file();
void sort();//sorting
void delete_record();
void delete_empty_space();
void save_statics();
void update_record();
void f_delivery();
void back_up();
int main(){
   m_init();
   int menu;
   while(1){
     printf("======================[DELIVERY SYSTEM]========================\n");
     printf("1.Create          2.Search(number)      3.Search(room)\n");
     printf("4.Delivery List   5.All List            6.Update Delivery\n");
     printf("7.Load            8.Save(backup)        9.Sort\n");
     printf("10.Delete         11.Delete empty space 12.save (statics)\n");
     printf("13.Update         14.Find delivery      15.Backup\n");
     printf("0.Quit\n");
     printf("=============================================================\n");
     scanf("%d",&menu);
     printf("\n");
     switch(menu){
        case 1:
           create_record();
           break;
        case 2:
           search_student();
           break;
        case 3:
           search_room();
           break;
        case 4:
           delivery_list();
           break;
        case 5:
           all_list();
           break;
        case 6:
           update_delivery();
           break; 
	case 7:
	   load_file();
	   break;
	case 8:
	   save_backup_file();
	   break;
	case 9:
	   sort();
	   break;
	case 10:
	   delete_record();
	   break;
	case 11:
	   delete_empty_space();
	   break;
	case 12:
	   save_statics();
	   break;
	case 13:
	   update_record();
	   break;
	case 14:
	   f_delivery();
	   break;
	case 15:
	   back_up();
	   break;
        default:
        case 0:
           return 0;
      }
    }
  return 0;
  }

void create_record(){
  if(!m_is_available()){
      printf("There is no space!\n");
      return;
    }
  char s_num[20], name[20], password[20];
  int room;
  printf("====================[CREATE NEW RECORD]====================\n");
  printf("Enter a new student's info.\n");
  while(1){
  printf("Student number > ");
  scanf("%s",s_num);
  if(!s_num_size(s_num)){
    printf("[ERROR]Student number's size must 8.\n");
   }
  else break;
 }
 if(m_search_by_num(s_num)){
   printf("[ERROR]Duplicated student number!\n");
   printf("=========================================================\n");
   return;
  }
 printf("Name > ");
 scanf("%s",name);
 printf("Room > ");
 scanf("%d",&room);
 while(1){
 printf("Password > ");
 scanf("%s",password);
 if(!m_same_password(s_num, password)){
    printf("[ERROR]Enter the password again.\n");
   }
 else break;
 }
 m_create(s_num, name, room, password,0);
   printf("=========================================================\n");
}

void search_student(){
  char s_num[20];
  printf("=============[SEARCH STUDENT:STUDENT NUMBER]==============\n");
  printf("Enter a student number > ");
  scanf("%s", s_num);
  T_Record* p = m_search_by_num(s_num);
  if(p) {
   printf("Students info.\n");
   printf("Student number : %s\n", m_getsnum(p));
   printf("Name : %s\n", m_getname(p));
   printf("Room : %d\n", m_getroom(p));
   printf("Delivery : %d\n", m_getdelivery(p));
  }
 else {
  printf("No such member!\n");
 }
   printf("=========================================================\n");
}

void search_room(){
 int room;
 printf("==================[SEARCH STUDENT:ROOM]===================\n");
 printf("Enter a room > ");
 scanf("%d",&room);
 T_Record* records[MAX_MEMBERS];
 int size = m_get_all_by_room(records,room);
 if(size==0){
 printf("Room %d didn't exist.\n",room);
 return;
}
 printf("No.%d has %d students\n",room,size);
 for(int i=0;i<size;i++){
    T_Record* p = records[i];
    printf("%d. %s\n", i+1 , m_to_string(p));
  }
   printf("============================================================\n");
}

void delivery_list(){
 printf("=======================[DELIVERY LIST]========================\n");
 T_Record* records[MAX_MEMBERS];
 if(!m_get_onemore(records)){
   printf("No student has more than one delivery\n");
   return;
 }
 int size=m_get_onemore(records);
 for(int i=0; i<size; i++){
   T_Record* p = records[i];
   printf("%d. %s\n", i+1, m_to_string2(p));
  }
  printf("==============================================================\n");
}

void all_list(){
  printf("=========================[ALL LIST]===========================\n");
  char ad_pw[20];
  printf("Please enter the administration password to get access.\n");
  printf("Password > ");
  scanf("%s",ad_pw);
  if(!m_get_admin_password(ad_pw)){
    printf("Wrong password!\n");
    return;
   }
  int size =m_count();
  if(size==0) printf("No records.\n");
  else printf("All records.\n");
  T_Record* records[MAX_MEMBERS];
  m_get_all(records);
  for(int i=0;i<size;i++){
    T_Record* p = records[i];
    printf("%d. %s\n", i+1,m_to_ad_string(p));
   }
  printf("==============================================================\n");
}
 

void update_delivery(){
  char s_num[20];
  int delivery;
  int box;
  printf("======================[UPDATE DELIVERY]========================\n");
  printf("Enter a student number > ");
  scanf("%s",s_num);
  T_Record* p = m_search_by_num(s_num);
  if(p){
    while(1){  
    printf("Enter the number of delivery > ");
    scanf("%d",&delivery);
    if(delivery<1){
     printf("Enter again.\n");
     }
    else break;
   }
   printf("Choose the delivery box.\n");
   scanf("%s",box);
   print_delivery_box(p,box); 
   m_update_delivery(p,delivery);
   printf("Delivery time is "); current_time();
   printf("Updated!\n");
  }
  else{
    printf("No such member!\n");
   }
  printf("==============================================================\n");
}

void load_file(){
  printf("=========================[LOAD FILE]==========================\n");
printf("All data will be delete and new records will be reloaded.\n");
printf("1.Yes 0.No >");
int choose;
scanf("%d",&choose);
if(choose==0) return;
m_init();

FILE* f =fopen("students.txt","r");
char s_num[20], name[20], password[20];
int room, delivery;
while(!feof(f)){
   if(!m_is_available()) {
       printf("[Load] There is no space!\n");
        break;
    }
int n = fscanf(f,"%s %s %d %s %d",s_num, name, &room,password,&delivery);
if(n<5) break;
if(m_search_by_num(s_num)!=NULL) {
    printf("[Load] Duplicated student number(%s)!\n",s_num);
    continue;
  }
m_create(s_num,name,room,password,delivery);
}
printf("%d records are read from file!\n",m_count());
fclose(f);
  printf("==============================================================\n");
}

void save_backup_file(){
  printf("=====================[SAVE BACKUP FILE]=======================\n");
  FILE * f = fopen("backup.txt","w");
  printf("Do you want to sort students by student number?(1.Yes 2.No) > ");
  int yesno;
  scanf("%d",&yesno);
  if(f==NULL){
   printf("Please delete empty space.\n");
   return;
  }
  if(yesno==1){
  sort_by_num(); 
  printf("All \'sorted\' backup records saved.\n");
  }
  else printf("All \'unsorted\'backup records saved.\n");
  int size = m_count();
  T_Record* records[MAX_MEMBERS];
  m_get_all(records);
  for(int i=0;i<size;i++){
    T_Record *p = records[i];
    fprintf(f,"%s\n", m_to_string_save(p));
   }
  fclose(f);
  printf("==============================================================\n");
}

void sort(){
  printf("======================[SORT RECORD]===========================\n");
 printf("[SORT] 1.Student number 2.Name 3.Room > ");
 int choice;
 scanf("%d",&choice);
 switch(choice){
  case 1 :
    sort_by_num();
    break;
  case 2 :
    sort_by_name();
    break;
  case 3 :
    sort_by_room();
    break;
  default :
    printf("Sorting quit\n");
    return;
}
  printf("Sorting complete.\n");
  printf("==============================================================\n");
}

void delete_record(){
 char s_num[20];
 printf("=======================[DELETE RECORD]=========================\n");
 printf("Enter a student number > ");
 scanf("%s",s_num);
 T_Record* p =m_search_by_num(s_num);
 if(p){
   m_delete(p);
   printf("The record is deleted!\n");
  }
 else{
   printf("No such member!\n");
  }
  printf("==============================================================\n");
}
void delete_empty_space(){
 m_delete_empty_space();
 printf("Delete empty space complete.\n");
}

void save_statics(){
 float ratio[10]={0}; //비율
 int count[10]={0};
 int size=m_count();
 int n1=0;
 FILE * f = fopen("statics.txt","w");
 T_Record*records[MAX_MEMBERS];
 m_get_all(records);
 for(int i=0;i<size;i++){
 T_Record *p = records[i];
 int c=find_num(p);
 int d=find_delivery(p);
 count[c-11]+=d;
 }
for(int i=0;i<10;i++){
 n1+=count[i];
}
for(int i=0;i<10;i++){
  if(count[i]==0) ratio[i]=0;
  else{
  ratio[i]=count[i]*100.0;
  ratio[i]/=n1*1.0;
}
}
fprintf(f,"[Courier utilization statistics by school number]\n");
for(int i=0;i<10;i++){
if(ratio[i]!=0){
fprintf(f,"[S.Num %d] %.1f %%\n",i+11,ratio[i]);
}
}
printf("All statics on delivery system by student number saved.\n");
}

void update_record(){
  char s_num[20], name[20], password[20];
  int room;
printf("Enter a student number > ");
scanf("%s",s_num);

T_Record*p = m_search_by_num(s_num);
if(p){
   printf("Enter a password > ");
   scanf("%s",password);
  if(!check_password(p,password)){
     printf("Wrong password!\n");
     return;
     }
   printf("Enter a updated info.\n");
   printf("Name > ");
   scanf("%s", name);
   printf("Room > ");
   scanf("%d",&room);
 while(1){
 printf("Password > ");
 scanf("%s",password);
 if(!m_same_password(s_num, password)){
    printf("Enter the password again.\n");
   }
 else break;
 }
   m_update(p,name,room,password);

  }
else{
 printf("No such member!\n");
}
}

void f_delivery(){
  char s_num[20],password[20];
  int delivery, d_num;
  printf("Enter a student number > ");
  scanf("%s",s_num);

T_Record* p = m_search_by_num(s_num);
if(p){
  if(m_getdelivery(p)==0){
    printf("You don't have delivery.\n");
    return;
    }
  printf("Enter a password > ");
  scanf("%s",password);
  if(!check_password(p,password)){
     printf("Wrong password!\n");
     return;
    }
  printf("Your delivery : %d\n",m_getdelivery(p));
  printf("Enter the number of delivery you take out(0:All)\n");
while(1){
  scanf("%d",&d_num);
  delivery=take_delivery(p,d_num);
  if(delivery==0){
   printf("Enter again.\nYour delivery: %d\n",m_getdelivery(p));
}

 else break;
}
  if(d_num!=0)printf("Take out your \"%d\" delivery\n",d_num);
  else printf("Take out your ALL delivery\n");
  printf("Your delivery : %d\n",m_getdelivery(p));
}
else{
 printf("No such member!\n");
}
}

void back_up(){
 printf("==========================[BACK UP]==========================\n");
 printf("All data will be delete and records will be backed up.\n");
printf("1.Yes 0.No >");
int choose;
scanf("%d",&choose);
if(choose==0) return;
m_init();

FILE* f =fopen("backup.txt","r");
char s_num[20], name[20], password[20];
int room, delivery;
if(f==NULL){
 printf("No backup file\n");
 return;
}
while(!feof(f)){
   if(!m_is_available()) {
        printf("[Load] There is no space!\n");
        break;
    }
int n = fscanf(f,"%s %s %d %s %d",s_num, name, &room,password,&delivery);
if(n<5) break;
if(m_search_by_num(s_num)!=NULL) {
    printf("[Load] Duplicated student number(%s)!\n",s_num);
    continue;
  }
m_create(s_num,name,room,password,delivery);
}
printf("%d backup records are read from file!\n",m_count());
fclose(f);
}

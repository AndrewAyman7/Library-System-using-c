#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE*f2;
struct book {int id; char name[20]; int quantity;};
struct book b[5];
struct book sorted[4];


void fun1 (struct book x[]){
int d, quant;  char nam[20];
f2=fopen("books.txt","a");
 printf("enter your id : ");
 scanf("%d",&x[4].id);
 printf("enter your name : ");
 getchar(); //3shan yestna
 gets(x[4].name);
 printf("enter your q : ");
 scanf("%d",&x[4].quantity);
fprintf(f2,"\n%d %d %s",x[4].id,x[4].quantity,x[4].name);
fclose(f2);
}


// ###################################################################


void fun2 (){
FILE* f2=fopen("books.txt","r");
struct book b[5];
for (int i=0; i<5; i++){
     fscanf(f2,"%d %d%[^\n]s",&b[i].id,&b[i].quantity,b[i].name);
}
fclose(f2);

int t;
int n; printf("\nenter id to delete : "); scanf("%d",&n);
for (int i=0; i<4; i++){
    if (n==b[i].id)
        t=i;
}
for (int i=t;i<5;i++){
    strcpy(b[i].name,b[i+1].name);
    b[i].id=b[i+1].id;
    b[i].quantity=b[i+1].quantity;
}

f2=fopen("books.txt","w");
for (int i=0;i<4;i++)
{
     fprintf(f2,"%d %d %s\n",b[i].id,b[i].quantity,b[i].name);

}
fclose(f2);
}

// ##################################################################


int fun3 (int s,int n){
struct book del[4];
f2=fopen("books.txt","r");
for (int i=0; i<4; i++){
     fscanf(f2,"%d %d%[^\n]s",&del[i].id,&del[i].quantity,del[i].name);
}
fclose(f2);

if (s > 3)
    return -1 ;
if (n==del[s].id)
    return s;

return fun3(++s,n);

}


//####################################################################


void fun4 (){
f2=fopen("books.txt","r");
for (int i=0; i<4; i++){
    fscanf(f2,"%d %d %[^\n]s",&sorted[i].id,&sorted[i].quantity,sorted[i].name);
}
fclose(f2);

 char t[20];  int d,q ;
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++)
    {
        if (strcmp(sorted[j].name,sorted[j+1].name) > 0) {
            strcpy(t,sorted[j].name);                 d = sorted[j].id;                q = sorted[j].quantity;
            strcpy(sorted[j].name,sorted[j+1].name);       sorted[j].id=sorted[j+1].id;          sorted[j].quantity = sorted[j+1].quantity;
            strcpy(sorted[j+1].name,t);               sorted[j+1].id = d;              sorted[j+1].quantity = q ;              }
    }       // swap el name                      swap el id                  swap el quantity
         }

for (int i=0; i<4; i++)
    printf("%d\t\t%s\t\t%d\n",sorted[i].id,sorted[i].name,sorted[i].quantity);

char n[15]; printf("enter name book to search : ");  getchar();  gets(n);
int l=0,h=3; int m;
while (l<=h){
m=(l+h)/2;
if (strcmp(n,sorted[m].name)== 0){
    printf("%d\t\t%s\t\t%d\n",sorted[m].id,sorted[m].name,sorted[m].quantity);
    break;
    }
if (strcmp(n,sorted[m].name) < 0)
    h=m-1;
if (strcmp(n,sorted[m].name) > 0)
    l=m+1;
}

if (l>h)
    printf("not found");
}


// #################################################################


void fun5(){
struct book x[4];
f2=fopen("books.txt","r");
for (int i=0; i<4; i++){
    fscanf(f2,"%d %d %[^\n]s",&x[i].id,&x[i].quantity,x[i].name);
}
fclose(f2);

char t[20];  int d,q ;
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++)
    {
        if (strcmp(x[j].name,x[j+1].name) > 0) {
            strcpy(t,x[j].name);                 d = x[j].id;                q = x[j].quantity;
            strcpy(x[j].name,x[j+1].name);       x[j].id=x[j+1].id;          x[j].quantity = x[j+1].quantity;
            strcpy(x[j+1].name,t);               x[j+1].id = d;              x[j+1].quantity = q ;              }
    }       // swap el name                      swap el id                  swap el quantity
         }
      // 3shan kol id yro7 lel esm bta3o .. lw 3mlt swap lel names bs --> elasma2 hatb2a sorted bs hta5od el id bta3 ely 2blha ;


for (int i=0; i<4; i++)
    printf("%d\t\t%s\t\t%d\n",x[i].id,x[i].name,x[i].quantity);

}


// #############################################################


void fun6(struct book h[]){
for (int i=0; i<4; i++)
    printf("%d\t\t%s\t\t%d\n",h[i].id,h[i].name,h[i].quantity);
}

// #################################################################

int main()
{

f2=fopen("books.txt","r");               // to be stored ( "without changes" )
struct book stored[4];
for (int i=0; i<4; i++)
     fscanf(f2,"%d %d %s",&stored[i].id,&stored[i].quantity,stored[i].name);
fclose(f2);



f2=fopen("books.txt","r");               // to use it
struct book a[5];
if (f2==NULL)
    printf("error to get the file !!");
else
    {   for (int i=0; i<4; i++){
             fscanf(f2,"%d %d%[^\n]s",&a[i].id,&a[i].quantity,a[i].name);
             printf("%d\t\t%s\t\t%d\n",a[i].id,a[i].name,a[i].quantity);
 }
    }
fclose(f2);


int x;
while (x!=7){
printf("\n\n\nenter operation num : "); scanf("%d",&x);
if (x==1)
    fun1(a);
if (x==2)
    fun2();
if (x==3) {
    int n; printf("enter id to search : "); scanf("%d",&n);
    int index=fun3(0,n);
    if (index !=-1)
        printf("id = %d   name = %s   quantity = %d ",a[index].id,a[index].name,a[index].quantity);
    if (index==-1) // 8lt .. el 11 elindex bta3ha b 0;
        printf("not exist");
}
if (x==4){
    fun4();
}
if (x==5)
    fun5();
if (x==6)
    fun6(stored);
}
  return 0;
}

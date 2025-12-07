#include <stdio.h>
#include <string.h>
void add(){
int n1,n2,res;

    printf("\nEnter the number1: ");scanf("%d",&n1);
    printf("\nEnter the number2: ");scanf("%d",&n2);
    res=n1+n2;
    printf("\n%d + %d = %d",n1,n2,res);
}

void sub(){
int n1,n2,res;

    printf("\nEnter the number1: ");scanf("%d",&n1);
    printf("\nEnter the number2: ");scanf("%d",&n2);
    res=n1-n2;
    printf("\n%d - %d = %d",n1,n2,res);
}

void mult(){
int n1,n2,res;

    printf("\nEnter the number1: ");scanf("%d",&n1);
    printf("\nEnter the number2: ");scanf("%d",&n2);
    res=n1*n2;
    printf("\n%d * %d = %d",n1,n2,res);
}

void div(){
int n1,n2;
float res;
    printf("\nEnter the number1: ");scanf("%d",&n1);
    printf("\nEnter the number2: ");scanf("%d",&n2);
    res=(float)n1/n2;
    if(n2==0){
        printf("\n%d / %d = Infinitive",n1,n2);
    }
    else{
    printf("\n%d / %d = %f",n1,n2,res);
}}

void mod(){
int n1,n2,res;

    printf("\nEnter the number1: ");scanf("%d",&n1);
    printf("\nEnter the number2: ");scanf("%d",&n2);
 
    if(n2==0){
        printf("\n%d remanider %d = The number is not divide by 0\n",n1,n2);
    }
    else{
           res=n1%n2;
    printf("\n%d remainder %d = %d\n",n1,n2,res);
}
}

int main(){
char name[50];
int choice;
printf("Enter your name:  ");
fgets(name,sizeof(name),stdin);

printf("\nHello %s",name);

printf("\nWelcome to the Calculator Application using C\n");
while(1)
{
char yes[20];
  printf("\n\nEnter 0 to display the Operation list\n");
    printf("\nEnter your choice : "); scanf("%d",&choice);  
  
switch(choice){  

case 0:
printf("\n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5.Remainder \n 6.Exit");
break;

    case 1:
    printf("ADDITION \n");
add();break;

case 2:
printf("SUBTRACTION \n");
sub();break;

case 3:
printf("MULTIPLICATION \n");
mult();break;

case 4:
printf("DIVISION \n");
div();break;

case 5:
printf("REMAINDER \n");
mod();break;


case 6:
printf("Are you confirm to exit from the Calculator Application??  (Yes/No)  : ");
scanf("%s",yes);

    if(strcmp(yes,"yes")==0 || strcmp(yes,"YES")==0 || strcmp(yes,"Yes")==0)
{printf("OK %s \n I hope this is useful for you.\n Thank u for using the Calculator Application.\n " ,name);return 0;
}
else{
    printf("OK %s. Return back to the aplication\n",name);
}

break;

default:
printf("Invalid!!!\nEnter the choice correctly\n");
break;
}}
return 0;
}
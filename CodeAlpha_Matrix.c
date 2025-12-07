#include <stdio.h>
#include <string.h>

void get(int arr1[100][100],int n1,int n2){

for(int i=1;i<=n1;i++)
{
    for(int j=1;j<=n2;j++){
    printf("a[%d][%d]: ",i,j);
    scanf("%d",&arr1[i][j]);
}
}
}


void display(int arr1[100][100], int n1, int n2) {

    printf("[\n");
    for (int i = 1; i <= n1; i++) {
        printf(" ");  // indentation for rows
        for (int j = 1; j <= n2; j++) {
            printf(" %d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("]\n"); 
}

void add(int a[100][100],int b[100][100],int res[100][100],int n1,int n2)
{
for(int i=1;i<=n1;i++)
{
    for(int j=1;j<=n2;j++){
        res[i][j]=a[i][j]+b[i][j];
    }
}
}



void mult(int a[100][100],int b[100][100],int res[100][100],int r1,int c1,int c2)
{
for(int i=1;i<=r1;i++)
{
    for(int j=1;j<=c2;j++){
        res[i][j]=0;
        for(int k=1;k<=c1;k++)
    {    res[i][j]+=a[i][k]*b[k][j];
    }}
}
}


void sub(int a[100][100],int b[100][100],int res[100][100],int n1,int n2)
{
for(int i=1;i<=n1;i++)
{
    for(int j=1;j<=n2;j++){
        res[i][j]=a[i][j]-b[i][j];
    }
}
}


void tra(int a[100][100],int res[100][100],int n1,int n2)
{
for(int i=1;i<=n1;i++)
{
    for(int j=1;j<=n2;j++){
        res[j][i]=a[i][j];
    }
}
}


void main(){
    int n1,n2,n11,n22;
char name[50];
printf("What is your name?? ");

fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")] = '\0';
printf("Hello %s Welcome to the Matrix Operations\n",name);

int res[100][100],arr1[100][100],arr2[100][100];
printf("\nMATRIX 1\n\n");
printf("Enter the values for Matrix 1\n");
printf("Enter the rows : ");
scanf("%d",&n1);
printf("Enter the column : ");
scanf("%d",&n2);
get(arr1,n1,n2);


printf("\nMATRIX 2\n\n");
printf("Enter the values for Matrix 2\n");
printf("Enter the rows : ");
scanf("%d",&n11);
printf("Enter the column : ");
scanf("%d",&n22);
get(arr2,n11,n22);



printf("\n MATRIX 1: \n");
display(arr1,n1,n2);
printf("\n MATRIX 2: \n");
display(arr2,n11,n22);


printf("\nADDITION\n");

if(n1!=n11 ||n2!=n22){
printf("Addition is not possible.\n Dimensions are not support,Dimension must be same.\n\n");
}
else{
add(arr1,arr2,res,n1,n2);
display(res,n1,n2);
}

printf("\nSUBTRACTION\n");
if(n1!=n11 ||n2!=n22){
printf("Subtraction is not possible.\n Dimensions are not support,Dimension must be same.\n\n");
}
else{
sub(arr1,arr2,res,n1,n2);
display(res,n1,n2);
}
printf("\nMULTTIPLICATION\n");
if(n2!=n11){
  printf("Multiplication is not possible.\n Dimensions are not support\n");  
}
else{
mult(arr1,arr2,res,n1,n2,n22);
display(res,n1,n22);
}


printf("\nTRANSPOSE\n");
printf("\n\n Transpose of Matix1:\n");
tra(arr1,res,n1,n2);
display(res,n2,n1);


printf("\n\n Transpose of Matix2:\n");
tra(arr2,res,n11,n22);
display(res,n22,n11);

printf("\nOk %s. We hope this is useful for u.\n",name);
}
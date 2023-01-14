#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void printarray(int **A,int **B,int sizea,int row,int col);
void max_min (int **A, int sizea, int max, int min);
int transpose_b (int **B, int row, int col, int trow, int tcol, int **T);
int mult_a_b(int**B, int col, int**A, int sizea, int**C);
int sort1(int **A,int sizea);
int sort2(int **A,int sizea);
int sumAB (int **A, int **B, int row, int col, int sizea);


int main()
{
    int **A, **B, **T, **C;
    int row,col,trow,tcol,sizea;
    int i,j;
    int answer0,answer1,answer2,answer3;
    int max, min;
    srand(time(NULL));



    while(1)
    {
    printf("Row=");
    scanf("%d", &row);
    printf("Col=");
    scanf("%d", &col);
    trow=col;
    tcol=row;
    printf("Size A=");
    scanf("%d", &sizea);
    system("cls");
    printf("Matrix filling method\n");
    printf("1)by user\n2)randomly(from 1 to 25)\n3)by formula\n");
    scanf("%d",&answer0);
    system("cls");
    while(answer0!=1&&answer0!=2&&answer0!=3)
    {
        printf("Matrix filling method\n");
        printf("1)by user\n2)randomly\n3)by formula\n");
        scanf("%d",&answer0);
        system("cls");
    }



    A = (int**)calloc(sizea, sizeof(int*));
    if(A == NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    for(i=0;i<sizea;i++)
    {
            A[i]=(int*)calloc(sizea,sizeof(int));
                if(A[i] == NULL)
                {
                    printf("\nOops...something wrong.FIX ME");
                    getche();
                    exit(1);
                }
    }

    B = (int**)calloc(row,sizeof(int*));
    if(B == NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    for (int i=0; i<row; i++)
    {
            B[i]=(int *)calloc(col,sizeof(int));
                if(B[i] == NULL)
                {
                    printf("\nOops...something wrong.FIX ME");
                    getche();
                    exit(1);
                }
    }

    T = (int**)calloc(trow, sizeof(int*));
    if(T == NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    for(i=0;i<trow;i++)
    {
            T[i]=(int*)calloc(tcol,sizeof(int));
                if(T[i] == NULL)
                {
                    printf("\nOops...something wrong.FIX ME");
                    getche();
                    exit(1);
                }
    }

    C = (int**)calloc(row, sizeof(int*));
    if(C == NULL)
    {
        printf("\nOops...something wrong.FIX ME");
        getche();
        exit(1);
    }
    for(i=0;i<row;i++)
    {
            C[i]=(int*)calloc(sizea,sizeof(int));
                if(C[i] == NULL)
                {
                    printf("\nOops...something wrong.FIX ME");
                    getche();
                    exit(1);
                }
    }



    if(answer0==1)
    {
        for(i=0; i<sizea; i++)
                for(int j=0;j<sizea;j++)
                    {
                        printf("Enter value for A[%d][%d]: ", i, j);
                        scanf("%d", &A[i][j]);
                    }
        for(int i=0; i<row; i++)
            {
                for(int j=0;j<col;j++)
                    {
                        printf("Enter value for B[%d][%d]: ", i, j);
                        scanf("%d", &B[i][j]);
                    }
            }
    }
    if(answer0==2)
    {
        for (int i=0;i<sizea;i++)
            for (int j=0;j<sizea;j++)
                A[i][j]=1+rand()%25;

        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                B[i][j]=1+rand()%25;
    }
    if(answer0==3)
    {
        for (int i=0;i<sizea;i++)
            for (int j=0;j<sizea;j++)
                A[i][j]= 3*i+2*j-1;

        for (int i=0;i<row;i++)
            for (int j=0;j<col;j++)
                B[i][j]= 3*i-2*j-1;
    }



    printf("1)The maximum and minimum values above the main diagonal of matrix A");
    printf("\n2)Transponate matrix B");
    printf("\n3)Multiplication of matrices A and B");
    printf("\n4)Sort from smallest to largest");
    printf("\n5)The sum of the rows of the matrix A and the sum of the columns of the matrix B\n");
    scanf("%d",&answer1);
    system("cls");
    while(answer1!=1&&answer1!=2&&answer1!=3&&answer1!=4&&answer1!=5)
    {
        printf("1)The maximum and minimum values above the main diagonal of matrix A");
        printf("\n2)Transponate matrix B");
        printf("\n3)Multiplication of matrices A and B");
        printf("\n4)Sort from smallest to largest");
        printf("\n5)The sum of the rows of the matrix A and the sum of the columns of the matrix B\n");
        scanf("%d",&answer1);
        system("cls");
    }


    printarray(A,B,sizea,row,col);


    if(answer1==1)
    {
        max_min (A,sizea,max,min);
    }
    if(answer1==2)
    {
        transpose_b (B,row,col,trow,tcol,T);
    }
    if(answer1==3)
    {
        if(sizea!=row)
        {
            system("cls");
            printf("\n\t\tInvalid value!!!");
            exit(0);
        }
        mult_a_b(B,col,A,sizea,C);
    }

    if(answer1==4)
    {
        printf("\n1)Sort matrix A\n2)Sort on line\n");
        scanf("%d",&answer3);
        while (answer3!=1&&answer3!=2)
        {
            printf("1)Sort matrix A\n2)Sort on line\n");
            scanf("%d",&answer3);
            system("cls");
        }
    if(answer3==1)
        sort1(A,sizea);
    if(answer3==2)
        sort2(A,sizea);
    }

    if(answer1==5)
    {
        sumAB (A, B, row, col, sizea);
    }


    getche();
    system("cls");
    printf("1)Continue\n2)Exit\n");
    scanf("%d",&answer2);
    if(answer2==2)
        exit(0);
    if(answer2==1)
    {
        system("cls");
        printf("Another try\n");
    }
}
return 0;
}
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void printarray(int **A, int **B,int sizea, int row, int col)
{
    printf("Matrix A:\n");
    for(int i=0; i<sizea; i++)
        {
            for(int j=0;j<sizea;j++)
                {
                    printf("%2d ", A[i][j]);
                }
            printf("\n");
        }
    printf("\n");
    printf("Matrix B:\n");
    for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
                {
                    printf("%2d ", B[i][j]);
                }
            printf("\n");
        }
}

void max_min (int **A, int sizea, int max, int min)
{
    max=A[0][1];
    min=A[0][1];
    int n,m;
    n=0;
    m=1;
    int i,j;
    for(i=0;i<sizea;i++)
            for(int j=i+1;j<sizea;j++)
                if (A[i][j]>max)
                    {
                        max = A[i][j];
                        n=i;
                        m=j;
                    }
    printf("\n\nmax[%d][%d]=%d\n",n,m,max);
    n=0;
    m=1;
    for(i=0;i<sizea;i++)
            for(int j=i+1;j<sizea;j++)
                if (A[i][j]<min)
                    {
                        min = A[i][j];
                        n=i;
                        m=j;
                    }
    printf("min[%d][%d]=%d\n",n,m,min);
}

int transpose_b (int **B, int row, int col, int trow, int tcol, int **T)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
                T[j][i] = B[i][j];
    printf("\nMatrix T:\n");
    for (int i=0; i<col; i++)
    {
        for (int j=0; j<row; j++)
                printf("%2d ", T[i][j]);
        printf("\n");
    }
}

int mult_a_b(int**B, int col, int**A, int sizea, int**C)
{
    int i,j,l;
    printf("\nMatrix C:\n");
    for(i=0;i<sizea;i++)
        for(j=0;j<col;j++)
    {
        C[i][j]=0;
        for(l=0;l<sizea;l++)
            C[i][j]=C[i][j]+A[i][l]*B[l][j];
    }
    for(i=0;i<sizea;i++)
    {
        for(j=0;j<col;j++)
            printf("%5d", C[i][j]);
        printf("\n");
    }
}

int sort1(int **A,int sizea)
{
        for (int i=0; i<sizea; i++)
    {
        for (int j=0; j<sizea; j++)
        {
        int min=A[i][j];
        int m=i;
        int n=j;
        int w=j;
        for (int k = i; k < sizea; k++)
            {
                for (w; w < sizea; w++)
                {
                    if (A[k][w] <min)
                    {
                        min=A[k][w];
                        m=k;
                        n=w;
                    }
                }
            w = 0;
            }
        int temp = A[i][j];
        A[i][j] = A[m][n];
        A[m][n] = temp;
        }
    }
    printf("\nSorted matrix A:\n");
    for (int i=0;i<sizea;i++)
        {
            for (int j=0;j<sizea;j++)
                    printf("%2d ", A[i][j]);
            printf("\n");
        }

}

int sort2(int **A,int sizea)
{
    int line,l,j,temp;
    printf("Line=");
    scanf("%d",&line);
    if(line>=sizea)
    {
        system("cls");
        printf("\n\t\tInvalid values!!!");
        exit(0);
    }
    printf("\nSorted on line matrix A:\n");
        for(l=1;l<sizea;l++)
    {
        for(j=0;j<sizea-l;j++)
        {
            if(A[line][j]>A[line][j+1])
            {
                temp = A[line][j];
                A[line][j] = A[line][j+1];
                A[line][j+1] = temp;
            }
        }
    }

    for(int j=0;j<sizea;j++){
        printf("%2d ",A[line][j]);
    }
}

int sumAB (int **A, int **B, int row, int col, int sizea)
{
    int sum;
    for(int i=0;i<sizea;i++)
        {
            sum=0;
            for(int j=0;j<sizea;j++)
                    sum=sum+A[i][j];
            printf("\nRow-%d__________SUMA=%d",i+1,sum);
        }
    printf("\n");

    for(int j=0;j<col;j++)
    {
        sum=0;
        for(int i=0;i<row;i++)
                sum=sum+B[i][j];
        printf("\nColumn-%d__________SUMB=%d",j+1,sum);
    }
    printf("\n");
}

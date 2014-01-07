/* this Program is calculating fibonacci(n)  in only O(lg n) time complexity.
	using the matrix base and bit pattern of n
	p=0;q=1;
	for(i=0;i<n;i++){a=q;	q=p+q; p=a; }
	printf("fib(%d)=%d\n",n,p); 
*/
#include<stdio.h>
void mat_multiply( double a[][2], double b[][2], double c[][2] )
{
	register int i,j,k;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			a[i][j]=0;
			for(k=0;k<2;k++)	a[i][j]+=b[i][k] * c[k][j];
		}
}
void print_mat(int a[][2])
{
	register int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++)	printf("%5d",a[i][j]);
	puts("");
	}
}
void copy_matrix(double a[][2],double b[][2]){
	register int i,j;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)	a[i][j]=b[i][j];
}
int main()
{
	double base[2][2]={ {0,1},{1,1} };
    double temp[2][2];
    double result[2][2]={ {0,1},{1,1} };
    int a,n;
    printf("Enter the value of n:  ");
	scanf("%d",&n);
    a=n-1;
	do{
		if(a%2 > 0){
                mat_multiply(temp,result,base);
				copy_matrix(result,temp);
		}
		a=a/2;
		mat_multiply(temp,base,base);
		copy_matrix(base,temp);
	}while(a> 0);
    printf("fib(%d)=%-500.0lf\n",n,result[0][1] );
return 0;
}

#include <stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char divisor[100]={},dividend[100]={},quotient[100]={},rem[100]={},temp[100]={},temp1[100]={};
	int len_divisor=0,len_dividend=0,i=0;
	printf("Enter the Dividend\n");
	scanf("%s",&dividend);
	printf("dividend=%s\n",dividend);
	printf("Enter the divisor\n");
	scanf("%s",&divisor);
	printf("divisor=%s\n",divisor);
	len_divisor=strlen(divisor);
	len_dividend=strlen(dividend);
	strcpy(temp,divisor);
	for(i=0;i<len_divisor;i++)
	{
		temp1[i]='0';
	}
	for(i=0;i<len_divisor-1;i++)
	{

		dividend[len_dividend]='0';
		len_dividend++;
	}
	printf("dividend=%s\n",dividend );
	printf("temp=%s\n",temp);
	printf("temp1=%s\n",temp1 );
	for(int j=0;j<len_dividend-1;j++)
	{
		printf("j=%d\n", j);
		if(dividend[j]=='1')
		{
			int n=j;
             for(int k=0;k<len_divisor;k++)
             {
             	/*printf("dividend=%d  ",(dividend[k]-'0'));
             	printf("temp=%d  ",(temp[k]-'0'));*/
             	rem[k]=((dividend[n]-'0')^(temp[k]-'0'))+'0';
             	/*printf("%d\n", (dividend[k]-'0')^(temp[k]-'0'));
             	printf("%c\n",rem[k] );
             	printf("\n");*/
             	n++;
             }
             printf("rem=%s\n",rem );
             int m=j;
             for(int l=0;l<strlen(rem);l++)
             {
             	dividend[m]=rem[l];
             	m++;
             }
             /*for(int l=0;l<len_dividend-1;l++)
             {
             	dividend[l]=dividend[l+1];
             }*/
             printf("dividend=%s\n",dividend );
		}
		else if(dividend[j]=='0')
		{
			int n=j;
             for(int k=0;k<len_divisor;k++)
             {
             	/*printf("dividend=%d  ",(dividend[k]-'0'));
             	printf("temp=%d  ",(temp[k]-'0'));*/
             	rem[k]=((dividend[n]-'0')^(temp1[k]-'0'))+'0';
             	/*printf("%d\n", (dividend[k]-'0')^(temp[k]-'0'));
             	printf("%c\n",rem[k] );
             	printf("\n");*/
             	n++;
             }
             printf("rem=%s\n",rem );
             int m=j;
             for(int l=0;l<strlen(rem);l++)
             {
             	dividend[m]=rem[l];
             	m++;
             }
             /*for(int l=0;l<len_dividend-1;l++)
             {
             	dividend[l]=dividend[l+1];
             }*/
             printf("dividend=%s\n",dividend );
		}
		printf("len_rem=%d\n",strlen(rem) );
		if(strlen(rem)==(len_divisor-1))
		{
			printf("Crc=%s\n", rem);
			break;
		}
		printf("\n");
	}


}
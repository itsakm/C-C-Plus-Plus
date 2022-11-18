#include <stdio.h>

int main() {
	int n=0,a[50]={0},t=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d",&n);
	    for(int j=0;j<n;j++)
	    {
	        scanf("%d",&a[j]);
	        if(a[j]==j+1)
	        {
	            printf("%d ",a[j]);
	        }
	    }
	}
	return 0;
}
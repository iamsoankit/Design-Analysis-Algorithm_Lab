#include<stdio.h>
void main()
{
  int i,n,k;
  printf("enter arrayy size");
  scanf("%d",&n);
  int a[n];
  printf("enter array number");
  
  for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
  
  for(i=1;i<=n;i++)
  {
     for(int j=i+1;j<=n;j++)
     {
        if(a[i]==a[j])
        {  
           k++;
           printf("%d/t",a[i]);
        }
     }
     printf("for %d-%d",a[i],k);
     k=0;
  }
}

#include<stdio.h>
void main()
{
  int i,n;
  printf("enter arrayy size");
  scanf("%d",&n);
  
  int a[n];
  printf("enter array number");
  
  for(i=1;i<=n;i++)
  scanf("%d",&a[i]);

   
  for(i=1;i<n;i++)
  a[i+1]=a[i]+a[i+1];
   
  printf("updated array");
   
  for(i=1;i<=n;i++)
  printf("%d",a[i]);
  
  
}

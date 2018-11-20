#include<bits/stdc++.h>
using namespace std;
int main()
{
    int count=0,i=0,j,l,k=0,bits=0,n;
    printf("ENTER THE MAXIMUM FRAME LENGTH : ");
    scanf("%s",n);
    char a[n];
    printf("\nENTER THE FRAME DATA : ");
    scanf("%s",a);
    l=strlen(a);
    for(i=0;i<l;i++)
        if(a[i]=='1')
        {
            k=i;
            count=0;
            while(a[k]=='1')
            {
                count+=1;
                k++;
                if(count==5)
                {
                    for(j=l+1;j>k;j--)
                    {
                        a[j]=a[j-1];
                    }
                    a[k]='0';
                    bits++;
                    l++;
                    break;
                }
                i=k;
            }
        }
    printf("\nSENDING FRAME : %s",a);
    printf("\nNUMBER OF BITS STUFFED : %d",bits);
    k=0;
    for(i=0;i<=l;i++)
    {
        if(a[i]=='1')
        {
            k=i;
            count=0;
            while(a[k]=='1')
            {
                count+=1;
                k++;
                if(count==5)
                {
                    for(j=k;j<l+1;j++)
                    {
                        a[j]=a[j+1];
                    }
                    l--;
                    a[l+1]='0';
                    break;
                }
            }
            i=k-1;
        }
    }
    printf("\nRECEIVED DATA : %s\n",a);
    return 0;
}
#include <stdio.h>

int main()
{
    int a[100],b[2]={0,},i=0,j=0,k,tot;
    char an[100];
    while(1)
    {
        an[i]=getchar();
        if(an[i]=='=') break;
        else if(an[i]=='+')
        {
            j++;
            k=1;
        }
        else if(an[i]=='-')
        {
            j++;
            k=2;
        }
        else if(an[i]=='*')
        {
            //wrong?
            j++;
            k=3;
        }
        else if(an[i]=='/')
        {
            j++;
            k=4;
        }
        else if(an[i]=='\n');
        else{

            b[j]*=10;
            b[j]=b[j]+an[i]-'0';
        }
        i++;
    }
    switch(k)
    {
        case 1:tot=b[0]+b[1];
        break;
        case 2:tot=b[0]-b[1];
        break;
        case 3:tot=b[0]*b[1];
        break;
        case 4:tot=b[0]/b[1];
        break;
    }
    printf("%d",tot);
}

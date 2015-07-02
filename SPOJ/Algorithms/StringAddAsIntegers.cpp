#include<stdio.h>
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<math.h>
#include<algorithm>

#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define sgn(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))


int rev(char str[]){
            char temp;
            int j=strlen(str)-1;
            int i=0;
            while(i<j){
                temp=str[i];
                str[i]=str[j];
                str[j]=temp;
                i++;
                j--;
            }


}

int add(char *num1,char *num2,char *res){
        long long int i,j,cy=0,temp;
        rev(num1);
        rev(num2);
        int len1=strlen(num1),len2=strlen(num2);
        /*making remaining space as zero*/
        for(i=len1;i<100;i++)
            num1[i]='0';
        for(i=len2;i<100;i++)
            num2[i]='0';
        /*core algorithm*/
        for(i=0;num1[i]!='0'  || num2[i]!='0' || cy !=0 || i<len1 || i<len2;i++){
            temp=num1[i]+num2[i]-'0'-'0'+cy;
            res[i]=temp%10+'0';
            cy=temp/10;
        }
        /*core algoritham ends*/
        res[i]=0;
        rev(res);
        
        
}

int subtract(char *num1,char *num2,char *res){
        long long int i,j,cy=0,temp;
        
        int big=strcmp(num1,num2);
        printf("big=%d\n",big );
        if(big<0){
            char *p=num1;
            num1=num2;
            num2=p;
        }
        rev(num1);
        rev(num2);
        int len1=strlen(num1),len2=strlen(num2);
        /*making remaining space as zero*/
        for(i=len1;i<100;i++)
            num1[i]='0';
        for(i=len2;i<100;i++)
            num2[i]='0';
        /*core algorithm*/
        for(i=0;num1[i]!='0'  || num2[i]!='0' || i<len1 || i<len2;i++){
            temp=num1[i]-num2[i]+cy;
            cy=0;
            if(temp<0){
                cy=-1;
                temp+=10;
            }
            res[i]=temp+'0';
         //   printf("hey dude subtraction prgress\n");
            
            
        }
        if(big<0)
            res[i++]='-';
        res[i]=0;
               
        /*core algoritham ends*/
        
        rev(res);
        
        
}


int main()
{
    using namespace std;
    char  num1[100],num2[100],res[100];
    int t;
 	
    cin>>t;
    while(t--)
    {	
    	cin>>num1>>num2;
        subtract(num1,num2,res);
        printf("%s",res);
    	
    }

    return 0;
}

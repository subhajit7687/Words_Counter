#include<stdio.h>
#include<conio.h>
void main()
{
    char c1,c2=NULL;
    char file_name[20];
    int cnt=0;
    printf("Enter your file name: ");
    gets(file_name);
    FILE *ptr;
    ptr=fopen(file_name,"r");
    if(ptr==NULL)
        printf("\nNo such file found\n");
    else
    {
        while(1)
        {
            c1=fgetc(ptr);
            if(c1==EOF)
            {
                if(c2==NULL)
                    break;
                else if(c2==' '||c2=='\n')
                    break;
                else
                {
                    cnt++;
                    break;
                }
            }
            else
            {
                if(c1==' ')
                {
                    if(c2!=' '&&c2!='\n'&&c2!=NULL)
                        cnt++;
                }
                else if(c1=='\n')
                {
                    if(c2!=' '&&c2!='\n'&&c2!=NULL)
                        cnt++;
                }
            }
            c2=c1;
        }
        fclose(ptr);
        printf("\nTotal word(s) in your file is: %d\n",cnt);
    }
    getch();
}

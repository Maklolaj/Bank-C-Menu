#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int i,j;
int main_exit;
void menu();

struct {

    char name[60];
    char acc_no[60];
    int nom;
    float amt;


    }add,upd,check,rem,transaction;



void new_acc()

{
    int choice;
    FILE *ptr;


    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");

    printf("\nEnter the account number:");
    scanf("%s",check.acc_no);
    while(fscanf(ptr,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
    {
        if(strcmpi(add.acc_no,check.acc_no)==0)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    memcpy(add.acc_no,check.acc_no, sizeof(check.acc_no));
    //add.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter a number of months:");
    scanf("%d",&add.nom);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);


    fprintf(ptr,"%s %s %d %f\n",add.acc_no,add.name,add.nom,add.amt);


    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tMONTHS\t\n");

    while(fscanf(view,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
       {
           printf("\n%10s\t %10s\t\t\t%d\t\t",add.acc_no,add.name,add.nom);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%s",rem.acc_no);
    while (fscanf(old,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
   {
        //if(add.acc_no!=rem.acc_no)
        if(strcmpi(add.acc_no,rem.acc_no)!=0)
            fprintf(newrec,"%s %s %d %f\n",add.acc_no,add.name,add.nom,add.amt);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see_rich()
{
    FILE *seer;

    seer=fopen("record.dat","r");
    float average=0.0;
    float sum=0.0;
    float clients=0.0;

    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ Show the richest  \xB2\xB2\xB2\xB2");


    while(fscanf(seer,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
    {

        sum=sum+add.amt;
        clients = clients + 1.0;

    }

    fclose(seer);

    average = sum / clients;
    //printf("\n %f \n",average);


    FILE *shw;

    shw=fopen("record.dat","r");

    while(fscanf(shw,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
    {

        if(average <= add.amt)
        {
            printf("\n%10s\t %10s\t\t\t%f\t\t",add.acc_no,add.name,add.amt);
        }

    }

    fclose(shw);

    //fprintf(seer,"%s %s %d %f\n",add.acc_no,add.name,add.nom,add.amt);




    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%s",check.acc_no);

        while (fscanf(ptr,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
        {
            //if(add.acc_no==check.acc_no)
            if(strcmpi(add.acc_no,check.acc_no)==0)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%s\nName:%s \n \nMonths:%d \n \nAmount deposited:$ %.2f \n \n",add.acc_no,add.name,add.nom,add.amt);


            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%s %s %d %f\n",add.acc_no,add.name,&add.nom,&add.amt)!=EOF)
        {
            if(strcmpi(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount NO.:%s\nName:%s \n \nMonths:%d \n \nAmount deposited:$ %.2f \n \n",add.acc_no,add.name,add.nom,add.amt);


            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void close(void)
{
    printf("\n\n\n\nThis C Project is developed by TU Sofia students!");
    }


void menu(void)
{   int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2. Blank \n\t\t3.Show the richest \n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:view_list();
        break;
        case 3:see_rich();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }



}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int main()
{
    char pass[10],password[10]="admin1";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);

    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}


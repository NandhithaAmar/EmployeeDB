    #include <stdio.h>

    typedef struct Employee
    {
        char fname[20];
        char lname[20];
        char sub_taken[20];
        char last_edu[20];
        char join_date[20];
        int id;
        int age;
        float bsal;
    }Employee;

    int main(void)
    {

        int id;
        FILE *fp,*ft;
        char another,choice;
        Employee emp;
        char fname[20];
        char lname[20];
        long int recsize;

        fp=fopen("EMP.DAT","rb+");
        if(fp==NULL)
        {
            fp=fopen( "EMP.DAT","wb+");
            if(fp==NULL)
            {
                printf("Can't Open File");

            }
        }
        recsize=sizeof(emp);
        while(1)
        {
            printf("1.Add Records 2.Delete Records 3.Modify Records 4.ListRecords 5.Exit");
            printf("Enter your choice");
            fflush(stdin);
            scanf("%c",&choice);
            switch(choice)
            {
                case'1':
                    fseek(fp,0,SEEK_END);
                    another='Y';
                    while(another=='Y'|| another=='y')
                    {
                        printf("Enter the first name,last name,age and basic salary : ");
                        scanf("%s %d %f",emp.fname,&emp.age,&emp.bsal);
                        printf("Enter joining date,id,last education,subject taken");
                        scanf("%s %d %s %s",emp.join_date,&emp.id,emp.last_edu,emp.sub_taken);
                        fwrite(&emp,recsize,1,fp);
                        printf("Add another Record (Y/N): ");
                        fflush(stdin);
                        another=getchar();
                    }

                    break;
                case '2':
                    another='Y';
                    while(another=='Y'|| another=='y')
                    {
                        printf("Enter the id of the employee to be deleted : ");
                        scanf("%d",&id);
                        ft=fopen("TEMP.DAT","wb");
                        rewind(fp);
                        while(fread(&emp,recsize,1,fp)==1)
                        {
                            if(strcmp(emp.id,id)!=0)
                            fwrite(&emp,recsize,1,ft);
                        }
                        fclose(fp);
                        fclose(ft);
                        remove("EMP.DAT");
                        rename("TEMP.DAT","EMP.DAT");
                        fp=fopen("EMP.DAT","rb+");
                        printf("Delete another Record(Y/N): ");
                        fflush(stdin);
                        another=getchar();
                    }

                    break;
                 case '3':
                    another='Y';
                    while(another=='Y'|| another=='y')
                    {
                        printf("Enter name of employee to modify : ");
                        scanf("%s",emp.fname);
                        rewind(fp);
                        while(fread(&emp,recsize,1,fp)==1)
                        {
                            if(strcmp(emp.id,id)==0)
                            {
                                printf("Enter new fname,new lname,age,basicsalary,joining_date,subject taken and last education : ");

    scanf("%s%s%d%f%s%s%s",emp.fname,emp.lname,&emp.age,&emp.bsal,emp.join_date,emp.sub_taken,emp.last_edu);
                                fseek(fp,-recsize,SEEK_CUR);
                                fwrite(&emp,recsize,1,fp);
                                break;
                             }
                         }
                         printf("Want to Modify another record(Y/N): ");
                         fflush(stdin);
                         another=getchar();
                     }

                     break;

                  case '4':

                       rewind(fp);
                       while(fread(&emp,recsize,1,fp)==1)
                       printf("%s %s %d%g",emp.fname,emp.lname,emp.age,emp.bsal,emp.join_date,emp.last_edu,emp.sub_taken);
                       break;

                 case '5':
                    fclose(fp);


            }
        }
     }

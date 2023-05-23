#include"studentdataimpl.h"
void manipulate()
{
    while(1)
    {
        printf("\n");
        printf("Enter 1 to add data of student\n");
        printf("Enter 2 to display the data's of student\n");
        printf("Enter 3 to update data of student\n");
        printf("Enter 4 to delete data of student\n");
        printf("Enter 5 to calculate memory\n");
        printf("Enter 6 to exit\n");
        printf("\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case addstudentdata:countstudents();
            adddata();
            break;
        case displaystudentdata:displaydata();
            break;
        case modifystudentdata:displaydata();
            Updatedata();
            break;
        case deletestudentdata:displaydata();
            deletedata();
            break;
        case memoryconsume:memorydata();
            break;
        case exitfromdata:printf("Exited from the loop\n");
            exit(1);
            break;
        default:printf("Enter the proper choice\n");
        }
    }
}
void countstudents()
{
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    fseek(fe,0,0);
    count=0;
    while(fgets(str,79,fe)!=NULL)
    {
        count++;
    }
    printf("Data of student present in file =%d\n",count);
    fclose(fe);
}

void adddata()
{
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    fseek(fe,0,2);
    if(fe==NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }
    if(count<=100)
    {
        stud.studentid=count+1000;
        printf("Enter the student name\n");
        fflush(stdin);
        gets(stud.studentname);
        printf("Enter the student usn\n");
        scanf("%s",stud.studentusn);
        printf("Enter the student phone no\n");
        scanf("%s",stud.studentphno);
        fprintf(fe,"%d %s %s %s\n",stud.studentid,stud.studentname,stud.studentphno,stud.studentusn);
        printf("Student data entered successfully\n");
    }
    fclose(fe);
}


void displaydata()
{
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    fseek(fe,0,0);
    if(fe==NULL)
    {
        printf("Cannot open file\n");
    }
    fflush(stdin);

    while(fgets(str,79,fe)!=NULL)
    {
        puts(str);
    }
    fclose(fe);
}


void Updatedata()
{
    printf("Enter the Student id\n");
    fflush(stdin);
    scanf("%d",&id);
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    ft=fopen("C:\\Qt Programs\\Student_data\\datasheettemp.txt","w");
    if(fe==NULL)
    {
        printf("Cannot open file\n");
    }
    if(ft==NULL)
    {
        printf("Cannot open file\n");
    }
    fseek(fe,0,0);
    while(fscanf(fe,"%d %s %s %s",&stud.studentid,&stud.studentname,&stud.studentphno,&stud.studentusn)!=EOF)
    {
        if(stud.studentid==id)
        {
            printf("Student id found\n");
            printf("Enter the student name\n");
            scanf("%s",stud.studentname);
            printf("Enter the student phno\n");
            scanf("%s",stud.studentphno);
            printf("Enter the student usn\n");
            scanf("%s",stud.studentusn);
            printf("Data Modified successfully");
        }
        fprintf(ft,"%d %s %s %s\n",stud.studentid,stud.studentname,stud.studentphno,stud.studentusn);
    }
    fclose(ft);
    fclose(fe);
    remove("C:\\Qt Programs\\Student_data\\datasheet.txt");
    rename("C:\\Qt Programs\\Student_data\\datasheettemp.txt","C:\\Qt Programs\\Student_data\\datasheet.txt");
}

void deletedata()
{
    printf("Enter the Student id\n");
    fflush(stdin);
    scanf("%d",&id);
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    ft=fopen("C:\\Qt Programs\\Student_data\\datasheettemp.txt","w");
    if(fe==NULL)
    {
        printf("Cannot open file\n");
    }
    if(ft==NULL)
    {
        printf("Cannot open file\n");
    }
    fseek(fe,0,0);
    while(fscanf(fe,"%d %s %s %s",&stud.studentid,&stud.studentname,&stud.studentphno,&stud.studentusn)!=EOF)
    {
        if(stud.studentid==id)
        {
            printf("Data deleted successfully\n");
            continue;
        }
        else
        {
            fprintf(ft,"%d %s %s %s\n",stud.studentid,stud.studentname,stud.studentphno,stud.studentusn);
        }
    }
    fclose(fe);
    fclose(ft);
    remove("C:\\Qt Programs\\Student_data\\datasheet.txt");
    rename("C:\\Qt Programs\\Student_data\\datasheettemp.txt","C:\\Qt Programs\\Student_data\\datasheet.txt");
}

void memorydata()
{
    char ch;
    bytes=0;
    fe=fopen("C:\\Qt Programs\\Student_data\\datasheet.txt","r+");
    fseek(fe,0,0);
    while(1)
    {
        ch=getc(fe);
        if(ch==EOF)
        {
            break;
        }
        else
        {
            bytes++;
        }
    }
    printf("The memory consumed:%d bytes\n",bytes);
}

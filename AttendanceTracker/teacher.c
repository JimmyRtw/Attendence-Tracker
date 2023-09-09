
#include <stdio.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

int StdAttendance();
int teacherView();
int teacherlogin();

int teacherlogin()
{
    system("clear");
    printf("\n -------------------- Teacher Login ----------------------");

    char username[20];
    char password[20];

    printf("\n Enter username : ");
    scanf("%s", username);

    printf("\n Enter password : ");
    scanf("%s", password);

    if (!strcmp(username, "teacher") && !strcmp(password, "teacher"))
    {
        teacherView();
        getchar();
    }
    else
    {
        printf("\n Error ! Invalid Credintials..");
        printf("\n Press any key for main menu ");
        getchar();
        getchar();
    }

    return 0;
}

int StdAttendence()
{

    FILE *read = fopen("db.txt", "r");

    if (read)
    {
        int recordFound = 0;
        char line[20];

        while (fscanf(read,"%s",line)==1)
        {

            char name[10];
            
            strcpy(name, line);
	    
		
            FILE *read = fopen(name, "r");


            for(int i=0; i<strlen(name)-4; ++i)
            	printf("%c",name[i]);
            printf("\n");
		
	    fclose(read);
		
            int c;

            printf("1: present: \nO : absent:\n");
            printf("enter choice:\n");

            scanf("%d", &c);

            switch (c)
            {

            case 1:
            {

                char line[20];
                
                FILE* read1 = fopen(name,"r");
                
                
                if (read1)
                {

                    int line_no = 0;
                    
                     FILE* ftemp = fopen("tmp.txt","w+");
                    while (line_no != 18 && fscanf(read1,"%s", line)==1)
                    {
                       if(line_no!=17)
                       {
                       fprintf(ftemp,"%s ",line);
                        if((line_no+1)%3==0)  
                        {fprintf(ftemp, "\n");}
                       }
                        ++line_no;
                    }
		     
		     fclose(read1);
		     
                    if (line_no == 18)
                    {
                        int i = atoi(line);

                        i++;


                        fprintf(ftemp, "%d", i);

                        

                        fclose(ftemp);
                       
                        remove(name);
                        rename("tmp.txt",name);
                    } 
                }
  
                break;
            }

            case 0:

                break;
            }

        }
    }


    getchar();

    getchar();

    return 0;
}

int teacherView()
{
    int goBack = 0;

    while (1)
    {

	system("clear");
        printf("\n 1 Mark Attendence");
        printf("\n 0. Go Back <- \n");

        int choice;

        printf("\n Enter you choice: ");
        scanf("%d", &choice);

        switch (choice)

        {

        case 1:
            StdAttendence();
            break;

        case 0:
            goBack = 1;
            break;

        default:
            printf("\n Invalid choice. Enter again ");

            getchar();
        }

        if (goBack == 1)

        {

            break;
        }
    }

    return 0;
}

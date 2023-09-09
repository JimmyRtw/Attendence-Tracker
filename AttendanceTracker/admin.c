#include <stdio.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

int adminView();

int deleteAllStudents();

void checkListOfStudentsRegistered();

int adminLogin();

int registerStudent();

int m = 0;

int k = 0;

int adminLogin()
{
    system("clear");
    printf("\n -------------------- Admin Login --------------------");

    char username[20];
    char password[20];

    printf("\n Enter username : ");
    scanf("%s", username);

    printf("\n Enter password : ");
    scanf("%s", password);

    if (!strcmp(username, "admin") && !strcmp(password, "admin"))
    {
        adminView();
        getchar();
    }
    else
    {
        printf("\n Error ! Invalid Credintials..");
        printf("\n Press any key for menu ");
        getchar();
        getchar();
    }

    return 0;
}

int adminView()
{
    int goBack = 0;

    while (1)
    {
    	system("clear");
        printf("\n 1 Register a Student");
        printf("\n 2 Delete All students name registered");
        printf("\n 3 Check List of Student registered by username");
        printf("\n 0. Go Back <- \n");

        int choice;
        printf("\n Enter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerStudent();
            break;

        case 2:
            deleteAllStudents();
            break;

        case 3:
            checkListOfStudentsRegistered();
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

int deleteAllStudents()
{
   if (remove("db.txt") == 0)
      printf("Deleted successfully\n");
   else
      printf("Unable to delete the file\n");

    printf("\n Please any key to continue..");
    getchar();
    getchar();

    return 0;
}

void checkListOfStudentsRegistered()
{ 
    system("clear");
    printf("\n ---------- Check List of Student Registered by Username-----------\n");
    
    FILE *read = fopen("db.txt", "r");
       
    if (read)
    {

        int recordFound = 0;
        char line[100];
	int total_lines = 0;
        while (fscanf(read, "%s", line)==1)
        {
            char filename[20];
            strcpy(filename, line);
            for(int i=0; i<strlen(filename)-4; ++i)
            	printf("%c", filename[i]);
            printf("\n");
        }
        fclose(read);
    }
    else
    {

        printf("\n No Record found :(");
    }

    printf("\n Please any key to continue..");

    getchar();

    getchar();

    return;
}

int registerStudent()
{
    
    system("clear");
    printf("\n ----- Form to Register Student ---- \n");

    char name[20], username[20], password[20], rollno[20], branch[20];

    int total;

    printf("\n Enter Name : ");
    scanf("%s", name);

    printf("\n Enter Username : ");
    scanf("%s", username);

    printf("\n Enter password : ");
    scanf("%s", password);

    printf("\n Enter rollno : ");
    scanf("%s", rollno);

    getchar();

    printf("\n Enter branch : ");
    scanf("%s", branch);

    printf("\n Enter initial number of presents :");
    scanf("%d", &m);

   

    FILE *out = fopen("db.txt", "a");

    fprintf(out, "%s\n", strcat(username, ".txt"));

    fclose(out);

    char temp[20];

    strcpy(temp,username);

    FILE *out1 = fopen(temp, "a+");

    fprintf(out1, "name = %s\n", name);
    fprintf(out1, "username = %s\n", username);
    fprintf(out1, "password = %s\n", password);
    fprintf(out1, "roll_no = %s\n", rollno);
    fprintf(out1, "branch = %s\n", branch);
    fprintf(out1, "initial_attendence = %d\n", m);

    fclose(out1);

    printf("\n Student Registered Successfully !!");
    printf("\n Please any key to continue..");

    getchar();
    getchar();

    return 0;
}

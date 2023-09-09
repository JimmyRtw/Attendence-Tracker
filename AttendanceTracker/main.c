#include <stdio.h>

#include <string.h>

#include <time.h>

#include <stdlib.h>

char username[20], password[20];
void studentView();
int checkStudentCredentials(char username[20], char password[20]);
int Attendance(char username[20]);
int sendLeaveApplication(char username[20]);
void studentView();
void studentLogin();
int checkStudentCredentials(char userName[20], char password[20]);
int adminLogin();
int teacherlogin();
int Attendance(char username[20]);
int sendLeaveApplication(char username[20]);

int total = 265;

void studentView()
{
    system("clear");
    printf("\n Enter username : ");
    scanf("%s", username);

    printf("\n Enter password : ");
    scanf("%s", password);

    int res = checkStudentCredentials(username, password);

    if (res == 0)
    {
        printf("\n Invalid Credentials !!");
        printf("\n Press any key for Main Menu..");

        getchar();
        getchar();

        return;
    }

    int goBack = 0;

    while (1)
    {
    	system("clear");
        printf("\n 1 Count my Attendance");
        printf("\n 2 Send a leave application");
        printf("\n 0. Go Back <- \n");

        int choice;

        printf("\n Enter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            Attendance(username);
            break;

        case 2:
            sendLeaveApplication(username);
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
}

void studentLogin()
{
    system("clear");
    printf("\n -------------------- Student Login ----------------------");
    studentView();
}

int checkStudentCredentials(char username[20], char password[20])
{
    FILE *read = fopen("db.txt", "r");

    int recordFound = 0;
	
    char temp[20];
	
    if (read)
    {
        char line[20];
        

        strcpy(temp,strcat(username,".txt"));

        while (fscanf(read, "%s", line)==1)
        {
            if (!strcmp(line, temp))
            {
                recordFound = 1;
                break;
            }
        }
    }

    fclose(read);

    if (recordFound == 1)
    {
        FILE *read = fopen(temp, "r");

        int line_number = 0;

        char line[100];

        while ((line_number != 3)&& (fscanf(read, "%s", line)==1))
        {
            ++line_number;
        }

        fclose(read);

        if (!strcmp(password, line))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int Attendance(char username[20])
{

    int total_lines = 0;
    char filename[20];

    printf("username = %s\n",username);

    FILE *read1 = fopen(username, "r");
    

    if (read1)
    {
        char line[100];
    	
        int line_no = 0;

        while (line_no!=18 && (fscanf(read1, "%s", line)==1))
        {
            // printf("%s\n", line);
            ++line_no;
        }
        if (line_no == 18)
        {
            printf("\nTotal Attendance: ");
            printf("%s\n",line);
            int i = atoi(line);

            printf("\nPercentage of attendance : %d %%", i * 100 / total);
        }
    }

    printf("\n Please any key to continue..");
    getchar();
    getchar();

    return 0;
}

int sendLeaveApplication(char username[20])
{

    char add[1000];
    printf("\n Write your application here: ");

    getchar();
    scanf("%s", add);

    time_t now = time(0);
    struct tm *ltm = localtime(&now);

    FILE *out = fopen("application.txt", "a");
    fprintf(out, add, ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year, username);

    fclose(out);
    printf("\n Application successfully sent !!");
    printf("\n Please any key to continue..");

    getchar();

    return 0;
}

int main()
{
    while (1)
    {
	system("clear");
        printf("\t\t\t\t\t Attendance Management System \n");
        printf("-------------------------------------------------------------------------\n\n");

        printf("1. Student Login\n");
        printf("2. Admin Login\n");
        printf("3. teacher Login\n");
        printf("0. Exit\n");

        int choice;

        printf("\n Enter you choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            studentLogin();
            break;

        case 2:
            adminLogin();
            break;

        case 3:
            teacherlogin();
            break;

        case 0:

            while (1)
            {
            	system("clear");
                printf("\n Are you sure, you want to exit? y | n \n");

                char ex;
                scanf("%c", &ex);

                if (ex == 'y' || ex == 'Y')
                    exit(0);

                else if (ex == 'n' || ex == 'N')
                {
                    break;
                }

                else
                {
                    printf("\n Invalid choice !!!");
                    getchar();
                }
            }
            break;

        default:
            printf("\n Invalid choice. Enter again ");
            getchar();
        }
    }

    return 0;
}

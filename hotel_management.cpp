#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hotel
{
    char fname[30];
    char lname[30];
    long int contact[20];
    long int cnic[20];
    char membership[20];
    char checkin[20];
    char checkout[20];
    int roomNo;
    int days;
};

int main()
{
    int pas;
    char user;
    char inp = 'y';

    printf("Note: The project not covered user management, in this regards the project only single user management system\n");
    printf("user name is comsats and password is 123\n\n");
    printf("Please enter 1st character of your username:");
    scanf("%c", &user);
    printf("Please enter your password:");
    scanf("%d", &pas);

    if (user == 'c' & pas == 123)
        {
            printf("\n\nWELCOME TO THE ** COMSATS HOTEL MANAGEMENT SYSTEM ***\n");
            struct Hotel h;
    FILE *fp;


    // Open file in write mode
    fp = fopen("hotel.txt", "wb");

    while (inp == 'y')
    {
        printf("\nPlease Enter Record \n\n");

        printf("Enter First Name: ");
        scanf(" %s", h.fname);

        printf("Enter Last Name: ");
        scanf(" %s", h.lname);

        printf("Enter Contact: ");
        scanf("%s", &h.contact);

        printf("Enter CNIC without dash: ");
        scanf("%s", h.cnic);

        printf("Enter Membership Level <gold/silver/bronze>: ");
        scanf("%s", h.membership);

        printf("Enter Check-in Date <dd-mm-yyyy>: ");
        scanf("%s", h.checkin);

        printf("Enter Check-out Date <dd-mm-yyyy>: ");
        scanf("%s", h.checkout);

        printf("Enter Room Number: ");
        scanf("%d", &h.roomNo);

        printf("Enter Total Days: ");
        scanf("%d", &h.days);


        fwrite(&h, sizeof(h), 1, fp);

        printf("\nDo you want to enter another record (y/n):");
        scanf("%s", &inp);

    }

    fclose(fp);

    /* Open file in read mode */
    fp = fopen("hotel.txt", "rb");

    printf("\n\n===== STORED HOTEL RECORDS =====\n");

    printf("\nFirst Name\tLast Name\tContact\t\tCNIC\t\tMembership\tRoom\tDays\n");

    // Read and display records
    while(fread(&h, sizeof(h), 1, fp))
    {
        printf("%s\t\t%s\t\t%s\t%s\t%s\t\t%d\t%d\n",
               h.fname,
               h.lname,
               h.contact,
               h.cnic,
               h.membership,
               h.roomNo,
               h.days);
    }

    fclose(fp);


        }
    else
        {
            printf("\nInvalid username or password\n");

        }


return 0;
}

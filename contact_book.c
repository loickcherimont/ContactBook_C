#include <stdio.h>
#include <string.h>

// Define what is a contact
struct Contact
{
    char phone_number[11];
    char first_name[256];
    char last_name[256];
    char address[256];
    char email[256];
};

// To use "Contact" instead of "struct Contact"
typedef struct Contact Contact;

Contact contact_book[10];

// Function prototypes
void display_options();
int get_user_option(int option);
// void add_contact_to(Contact *contact_book, int counter);
// void remove_contact();
// void modify_contact();
// void show_contacts(Contact *contact_book);
// size_t get_current_size(Contact *contact_book);

// ************************** MAIN FUNCTION **************************
int main(void)
{
    int target_option;
    int contact_counter = 1;

    // Default contact ever in Contact Book
    strcpy(contact_book[0].phone_number, "0123456789");
    strcpy(contact_book[0].first_name, "John");
    strcpy(contact_book[0].last_name, "DOE");
    strcpy(contact_book[0].address, "37 street of test, Test city 84632, Imaginary Country");
    strcpy(contact_book[0].email, "john.doe@gmail.com");

    display_options();
    target_option = get_user_option(target_option);

    switch (target_option)
    {
    case 1: // TODO
        // Add a new contact using user inputs
        char new_phone_number[11];
        char new_first_name[256];
        char new_last_name[256];
        char new_address[256];
        char new_email[256];

        printf("***************** CREATE A NEW CONTACT *****************\n\n");

        printf("Enter the firstname: ");
        scanf("%s", &new_first_name);
        strcpy(contact_book[contact_counter].first_name, new_first_name);

        printf("Enter the lastname: ");
        scanf("%s", &new_last_name);
        strcpy(contact_book[contact_counter].last_name, new_last_name);

        printf("Enter the phone number: ");
        scanf("%s", &new_phone_number);
        strcpy(contact_book[contact_counter].phone_number, new_phone_number);

        printf("Enter the address: ");
        scanf("%s", &new_address);
        strcpy(contact_book[contact_counter].address, new_address);

        printf("Enter the email: ");
        scanf("%s", &new_address);
        strcpy(contact_book[contact_counter].email, new_email);

        contact_counter++;

        printf("\nNEW CONTACT ADDED!\n");

        // Display all contacts
        // size_t current_size = sizeof(contact_book) / sizeof(Contact);

        printf("***************** ALL YOUR CONTACTS *****************\n");

        printf("\nYOU HAVE ACTUALLY %d CONTACTS\n", contact_counter);

        for (int i = 0; i < contact_counter; i++)
        {
            printf("==================================================================\n");
            printf("Phone number: %s\n", contact_book[i].phone_number);
            printf("First name: %s\n", contact_book[i].first_name);
            printf("Last name: %s\n", contact_book[i].last_name);
            printf("Address: %s\n", contact_book[i].address);
            printf("Email: %s\n", contact_book[i].email);
            printf("==================================================================\n");
        }
        break;

    case 2: // TODO
        puts("***************** REMOVE A CONTACT *****************\n");
        break;

    case 3: // TODO
        puts("***************** MODIFY A CONTACT *****************\n");
        break;

    case 4: // OK
        // Display all contacts
        // current_size = sizeof(contact_book) / sizeof(Contact);

        printf("***************** ALL YOUR CONTACTS *****************\n");

        printf("\nYOU HAVE ACTUALLY %d CONTACTS\n", contact_counter);

        for (int i = 0; i < contact_counter; i++)
        {
            printf("==================================================================\n");
            printf("Phone number: %s\n", contact_book[i].phone_number);
            printf("First name: %s\n", contact_book[i].first_name);
            printf("Last name: %s\n", contact_book[i].last_name);
            printf("Address: %s\n", contact_book[i].address);
            printf("Email: %s\n", contact_book[i].email);
            printf("==================================================================\n");
        }
        break;

    default:
        // TODO: ERROR HANDLING
        puts("Sorry, this option is not available!");
        break;
    }

    return 0;
}

// ************************** END MAIN FUNCTION **************************

// Functions
void display_options()
{

    printf("MY CONTACT BOOK\n");
    printf("\n1. Create a contact\n2. Remove a contact\n3. Modify a contact\n4. Show all contacts\n");
}

int get_user_option(int option)
{
    // Ask user to enter the target option
    printf("Type the option that you want : ");

    // Get and save the input
    scanf("%d", &option);

    return option;
}

// Options
// void add_contact_to(Contact *contact_book, int counter)
// {
//     char new_phone_number[11];
//     char new_first_name[256];
//     char new_last_name[256];
//     char new_address[256];
//     char new_email[256];

//     // TODO : Debug
//     int last_index = counter;

//     printf("***************** CREATE A NEW CONTACT *****************\n\n");

//     printf("Enter the firstname: ");
//     scanf("%s", &new_first_name);
//     strcpy(contact_book[last_index].first_name, new_first_name);

//     printf("Enter the lastname: ");
//     scanf("%s", &new_last_name);
//     strcpy(contact_book[last_index].last_name, new_last_name);

//     printf("Enter the phone number: ");
//     scanf("%s", &new_phone_number);
//     strcpy(contact_book[last_index].phone_number, new_phone_number);

//     printf("Enter the address: ");
//     scanf("%s", &new_address);
//     strcpy(contact_book[last_index].address, new_address);

//     printf("Enter the email: ");
//     scanf("%s", &new_address);
//     strcpy(contact_book[last_index].email, new_email);

//     counter++;

//     printf("\nNEW CONTACT ADDED!\n");
//     printf("CONTACTS: %d", counter);
// }

// void remove_contact()
// {
//     printf();
// }

// void modify_contact()
// {
//     printf("***************** REMOVE A CONTACT *****************\n");
// }

// Show all current contact
// Recorded in the Contact book
// void show_contacts(Contact *contact_book)
// {
//     size_t current_size = get_current_size(contact_book);

//     printf("***************** ALL YOUR CONTACTS *****************\n");

//     printf("\nYOU HAVE ACTUALLY %d CONTACTS\n", current_size);

//     for (int i = 0; i < current_size; i++)
//     {
//         printf("==================================================================\n");
//         printf("Phone number: %s\n", contact_book[i].phone_number);
//         printf("First name: %s\n", contact_book[i].first_name);
//         printf("Last name: %s\n", contact_book[i].last_name);
//         printf("Address: %s\n", contact_book[i].address);
//         printf("Email: %s\n", contact_book[i].email);
//         printf("==================================================================\n");
//     }
// }

// size_t get_current_size(Contact *contact_book)
// {
//     printf("sizeof: %d", sizeof(*contact_book) / sizeof(Contact));

//     return sizeof(*contact_book) / sizeof(Contact);
// }

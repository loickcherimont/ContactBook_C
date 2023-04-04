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

// Function prototypes
void display_options();
int get_user_option(int option);
void create_contact();
void remove_contact();
void modify_contact();
void show_contacts(Contact *contact_book);

// ************************** MAIN FUNCTION **************************
int main(void)
{
    int target_option;
    Contact contact_book[10];

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
        create_contact();
        break;

    case 2: // TODO
        remove_contact();
        break;

    case 3: // TODO
        modify_contact();
        break;

    case 4: // OK
        show_contacts(contact_book);
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
void create_contact()
{
    printf("***************** CREATE A NEW CONTACT *****************\n");
}

void remove_contact()
{
    printf("***************** REMOVE A CONTACT *****************\n");
}

void modify_contact()
{
    printf("***************** REMOVE A CONTACT *****************\n");
}

// Show all current contact
// Recorded in the Contact book
void show_contacts(Contact *contact_book)
{
    int total_contacts = sizeof(*contact_book) / sizeof(contact_book[0]);

    printf("***************** ALL YOUR CONTACTS *****************\n");

    for (int i = 0; i < total_contacts; i++)
    {
        printf("==================================================================\n");
        printf("Phone number: %s\n", contact_book[i].phone_number);
        printf("First name: %s\n", contact_book[i].first_name);
        printf("Last name: %s\n", contact_book[i].last_name);
        printf("Address: %s\n", contact_book[i].address);
        printf("Email: %s\n", contact_book[i].email);
        printf("==================================================================\n");
    }
}

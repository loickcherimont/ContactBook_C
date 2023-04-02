#include <stdio.h>
#include <string.h>

// Function prototypes
void display_options();
int get_user_option(int option);
void run_option(int option);
void create_contact();
void remove_contact();
void modify_contact();
void show_contacts(struct Contact contact_book);

// Define what is a contact
struct Contact {
    char phone_number[11];
    char first_number[256];
    char last_number[256];
    char address[256];
    char email[256];
} test_contact, contacts[3];

int main(void)
{
    int target_option;

    // A sample array of contacts**********************************
    strcpy(test_contact.phone_number, "0123456789");
    strcpy(test_contact.first_number, "John");
    strcpy(test_contact.last_number, "Doe");
    strcpy(test_contact.address, "11 Test Street, Coding City XXXXX");
    strcpy(test_contact.email, "johndoe@gmail.com");

    contacts[0] = test_contact;
    //*********************************************************

    display_options();
    target_option = get_user_option(target_option);
    // run_option(target_option);
    show_contacts(contacts);

    return 0;
}

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

void run_option(int option) {
    switch (option)
    {
    case 1:
        create_contact();
        break;
    
    case 2:
        remove_contact();
        break;
    
    case 3:
        modify_contact();
        break;
    
    case 4:
        // show_contacts();
        puts("SHOW CONTACTS");
        break;
    
    default:
    // TODO: ERROR HANDLING
        puts("Sorry, this option is not available!");
        break;
    }
}

// Options
void create_contact() 
{
    puts("Create a contact");
}

void remove_contact() 
{
    puts("Remove a contact");
}

void modify_contact() 
{
    puts("Modify a contact");
}

// To Debug
void show_contacts(struct Contact contact_book)
{
    size_t total_contacts = sizeof(contact_book)/sizeof(contact_book[0]);

    for(int i = 0; i < sizeof(contact_book); i++) 
    {
        printf("%d\n", contact_book[i]);
    }
}

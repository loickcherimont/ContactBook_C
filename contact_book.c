#include <stdio.h>
#include <string.h>

// Define what is a contact
// ************************** STRUCTS **************************
typedef struct
{
    int id;
    char phone_number[11];
    char first_name[20];
    char last_name[20];
    char address[30];
    char email[30];
} Contact;

Contact contact_book[10];

// ************************** FUNCTIONS **************************
// Fill by default contact book
void init_book(Contact contact_book[], int book_capacity, int contact_counter)
{
    for (int i = 0; i < book_capacity; i++)
    {
        contact_book[i].id = i + 1;
    }
    strcpy(contact_book[0].phone_number, "0123456789");
    strcpy(contact_book[0].first_name, "John");
    strcpy(contact_book[0].last_name, "DOE");
    strcpy(contact_book[0].address, "test_Adress");
    strcpy(contact_book[0].email, "john.doe@gmail.com");

    contact_counter = 1;
}

void display_contacts(Contact contact_book[], int book_capacity)
{
    printf("\n***************** ALL YOUR CONTACTS *****************\n");

    // printf("\nTOTAL CONTACTS: %d\n", contact_counter);

    for (int i = 0; i < book_capacity; i++)
    {
        printf("==================================================================\n");
        printf("*** CONTACT No. %d ***\n", contact_book[i].id);
        printf("Phone number: %s\n", contact_book[i].phone_number);
        printf("First name: %s\n", contact_book[i].first_name);
        printf("Last name: %s\n", contact_book[i].last_name);
        printf("Address: %s\n", contact_book[i].address);
        printf("Email: %s\n", contact_book[i].email);
        printf("==================================================================\n");
    }
}

void display_options()
{

    printf("CONTACT BOOK - MENU\n");
    printf("\n1. Create a contact\n2. Remove a contact\n3. Modify a contact\n4. Show all contacts\n");
}

int get_user_option()
{
    int user_option;
    // Ask user to enter the target option
    printf("Type the option that you want : ");

    // Get and save the input
    scanf("%d", &user_option);

    return user_option;
}

// void user_complete_inputs(char phone_number[], char first_name[], char last_name[], char address[], char email[])
// {
//     printf("Enter the firstname: ");
//     scanf("%s", first_name);
//     strcpy(contact_book[contact_counter].first_name, first_name);

//     printf("Enter the lastname: ");
//     scanf("%s", new_last_name);
//     strcpy(contact_book[contact_counter].last_name, new_last_name);

//     printf("Enter the phone number: ");
//     scanf("%s", phone_number);
//     strcpy(contact_book[contact_counter].phone_number, phone_number);

//     printf("Enter the address: ");
//     scanf("%s", new_address);
//     strcpy(contact_book[contact_counter].address, new_address);

//     printf("Enter the email: ");
//     scanf("%s", new_email);
//     strcpy(contact_book[contact_counter].email, new_email);
// }

// ************************** MAIN FUNCTION **************************
int main(void)
{
    int book_capacity = 10;
    int contact_counter;

    init_book(contact_book, book_capacity, contact_counter); // By default

    printf("AFTER INCREMENT: %d",contact_counter);

    // App loop
    /*while (1)
    {
        display_options();

        switch (get_user_option())
        {
        case 1:
            // Add a new contact using user inputs
            // int id;
            char new_phone_number[11];
            char new_first_name[20];
            char new_last_name[20];
            char new_address[30];
            char new_email[30];

            printf("***************** CREATE A NEW CONTACT *****************\n\n");

            user_complete_inputs(new_phone_number, new_first_name, new_last_name, new_address, new_email);

            printf("Enter the firstname: ");
            scanf("%s", new_first_name);
            strcpy(contact_book[contact_counter].first_name, new_first_name);

            printf("Enter the lastname: ");
            scanf("%s", new_last_name);
            strcpy(contact_book[contact_counter].last_name, new_last_name);

            printf("Enter the phone number: ");
            scanf("%s", new_phone_number);
            strcpy(contact_book[contact_counter].phone_number, new_phone_number);

            printf("Enter the address: ");
            scanf("%s", new_address);
            strcpy(contact_book[contact_counter].address, new_address);

            printf("Enter the email: ");
            scanf("%s", new_email);
            strcpy(contact_book[contact_counter].email, new_email);

            contact_counter++;

            printf("\nNEW CONTACT ADDED!\n");

            // Display all contacts
            display_contacts(contact_book, 10);

            break;

        case 2: // To Debug!!!
            int id_to_remove;
            char user_validation[2];

            printf("***************** REMOVE A CONTACT *****************\n");
            display_contacts(contact_book, 10);
            // char phone_number_to_remove[11];
            printf("Enter the contact rank (1, 2, ...) to remove: ");
            scanf("%d", &id_to_remove);

            id_to_remove -= id_to_remove;

            // TODO: Confirm the contact to remove

            printf("\nYOU WANT TO REMOVE THIS CONTACT:\n");
            printf("\n==================================================================\n");
            printf("*** CONTACT No. %d ***\n", contact_book[id_to_remove].id);
            printf("Phone number: %s\n", contact_book[id_to_remove].phone_number);
            printf("First name: %s\n", contact_book[id_to_remove].first_name);
            printf("Last name: %s\n", contact_book[id_to_remove].last_name);
            printf("Address: %s\n", contact_book[id_to_remove].address);
            printf("Email: %s\n", contact_book[id_to_remove].email);
            printf("\n==================================================================\n");
            printf("Are you sure to delete it (Y/N)? :");
            scanf("%s", user_validation);

            if (strcmp("Y", user_validation) == 0)
            {
                strcpy(contact_book[id_to_remove].phone_number, "");
                strcpy(contact_book[id_to_remove].first_name, "");
                strcpy(contact_book[id_to_remove].last_name, "");
                strcpy(contact_book[id_to_remove].address, "");
                strcpy(contact_book[id_to_remove].email, "");

                contact_counter--;

                printf("\nCONTACT DELETED!\n");

                // Display updated list
                display_contacts(contact_book, 10);
            }
            else
            {
                printf("\nDELETION CANCELLED!\n");
            }
            break;

        case 3: // OK
            int id_to_modify;

            printf("***************** MODIFY A CONTACT *****************\n");
            display_contacts(contact_book, 10);

            printf("Enter the contact rank (1, 2, ...) to modify: ");
            scanf("%d", &id_to_modify);

            // Adapt to array indexation
            id_to_modify -= 1;

            // Display the target
            printf("\nYOU WANT TO MODIFY THIS CONTACT:\n");
            printf("\n==================================================================\n");
            printf("*** CONTACT No. %d ***\n", contact_book[id_to_modify].id);
            printf("Phone number: %s\n", contact_book[id_to_modify].phone_number);
            printf("First name: %s\n", contact_book[id_to_modify].first_name);
            printf("Last name: %s\n", contact_book[id_to_modify].last_name);
            printf("Address: %s\n", contact_book[id_to_modify].address);
            printf("Email: %s\n", contact_book[id_to_modify].email);
            printf("\n==================================================================\n");

            // printf("\n***************** MODIFY THE INFOS *****************\n");
            char updated_firstname[20];
            char updated_lastname[20];
            char updated_phonenumber[11];
            char updated_address[30];
            char updated_email[30];

            printf("Enter the firstname: ");
            scanf("%s", updated_firstname);
            strcpy(contact_book[id_to_modify].first_name, updated_firstname);

            printf("Enter the lastname: ");
            scanf("%s", updated_lastname);
            strcpy(contact_book[id_to_modify].last_name, updated_lastname);

            printf("Enter the phone number: ");
            scanf("%s", updated_phonenumber);
            strcpy(contact_book[id_to_modify].phone_number, updated_phonenumber);

            printf("Enter the address: ");
            scanf("%s", updated_address);
            strcpy(contact_book[id_to_modify].address, updated_address);

            printf("Enter the email: ");
            scanf("%s", updated_email);
            strcpy(contact_book[id_to_modify].email, updated_email);

            printf("\nCONTACT MODIFIED!\n");

            // Display updated list
            display_contacts(contact_book, 10);

            break;

        case 4:
            // Show user all the contacts
            display_contacts(contact_book, 10);
            break;

        default:
            // TODO: ERROR HANDLING
            puts("Sorry, this option is not available!");
            break;
        }
    }
    */
    return 0;
}

// ************************** BACKGROUND **************************

// size_t all_contacts = sizeof(contact_book) / sizeof(contact_book[0]);

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

//     printf("\nTOTAL CONTACTS: %d\n", current_size);

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

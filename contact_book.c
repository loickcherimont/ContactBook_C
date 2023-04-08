#include <stdio.h>
#include <string.h>


// ************************** STRUCTS **************************
// Define what is a contact
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
// Returns updated contact_counter
int init_book(Contact contact_book[], int book_capacity, int contact_counter)
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
    return contact_counter;
}

// Display ID, Phone Number, Firstname, Lastname, Address and Email
void display_contacts(Contact contact_book[], int book_capacity)
{
    printf("\n***************** ALL YOUR CONTACTS *****************\n");

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

// Display user selection
void display_target_contact(Contact contact_book[], int target_id) {
    printf("\n==================================================================\n");
        printf("*** CONTACT No. %d ***\n", contact_book[target_id].id);
        printf("Phone number: %s\n", contact_book[target_id].phone_number);
        printf("First name: %s\n", contact_book[target_id].first_name);
        printf("Last name: %s\n", contact_book[target_id].last_name);
        printf("Address: %s\n", contact_book[target_id].address);
        printf("Email: %s\n", contact_book[target_id].email);
    printf("\n==================================================================\n");
}

// Display all available options in App
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

void user_complete_inputs(char phone_number[], char first_name[], char last_name[], char address[], char email[], int contact_counter)
{
    printf("Enter the firstname: ");
    scanf("%s", first_name);
    strcpy(contact_book[contact_counter].first_name, first_name);

    printf("Enter the lastname: ");
    scanf("%s", last_name);
    strcpy(contact_book[contact_counter].last_name, last_name);

    printf("Enter the phone number: ");
    scanf("%s", phone_number);
    strcpy(contact_book[contact_counter].phone_number, phone_number);

    printf("Enter the address: ");
    scanf("%s", address);
    strcpy(contact_book[contact_counter].address, address);

    printf("Enter the email: ");
    scanf("%s", email);
    strcpy(contact_book[contact_counter].email, email);
}

// ************************** MAIN FUNCTION **************************
int main(void)
{
    // Set default values
    int book_capacity = 10;
    int contact_counter = 0;

    contact_counter = init_book(contact_book, book_capacity, contact_counter);

    // App loop
    while (1)
    {
        display_options();

        // Process in function of user option
        switch (get_user_option())
        {
        case 1: // Add a new contact using user inputs
            char new_phone_number[11];
            char new_first_name[20];
            char new_last_name[20];
            char new_address[30];
            char new_email[30];

            printf("***************** CREATE A NEW CONTACT *****************\n\n");

            user_complete_inputs(new_phone_number, new_first_name, new_last_name, new_address, new_email, contact_counter);

            contact_counter++;

            printf("\n *** NEW CONTACT ADDED! *** \n");

            break;

        case 2: // Remove a contact selected by user
            int id_to_remove;
            char user_validation[2];

            printf("***************** REMOVE A CONTACT *****************\n");
            
            display_contacts(contact_book, 10); // To them all
            printf("Enter the contact rank (1, 2, ...) to remove: ");
            scanf("%d", &id_to_remove);

            // Transform id into index
            // To fetch the corresponding contact in contact_book
            id_to_remove--;

            printf("\nYOU WANT TO REMOVE THIS CONTACT:\n");
            display_target_contact(contact_book, id_to_remove);

            // Confirm user request for "REMOVE A CONTACT" option
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

                printf("\n *** CONTACT DELETED! *** \n");
            }
            else
                printf("\n *** DELETION CANCELLED! *** \n");
            break;

        case 3: // Modify a contact
            int id_to_modify;
            char updated_firstname[20];
            char updated_lastname[20];
            char updated_phonenumber[11];
            char updated_address[30];
            char updated_email[30];

            printf("***************** MODIFY A CONTACT *****************\n");
            display_contacts(contact_book, 10);

            printf("Enter the contact rank (1, 2, ...) to modify: ");
            scanf("%d", &id_to_modify);

            // Transform id into index
            // To fetch the corresponding contact in contact_book
            id_to_modify--;

            // Display the target
            printf("\nYOU WANT TO MODIFY THIS CONTACT:\n");
            display_target_contact(contact_book, id_to_modify);
            
            user_complete_inputs(updated_phonenumber, updated_firstname, updated_lastname, updated_address, updated_email, id_to_modify);

            printf("\n *** CONTACT MODIFIED! *** \n");

            break;

        case 4: // Show all the contacts
            display_contacts(contact_book, 10);
            break;

        default: // FEATURES: HIGH ERROR HANDLING
            puts("Sorry, this option is not available!");
            break;
        }
    }
    return 0;
}
/* -------------------------------
Name:Navid Vadsariya
Student number: 136884186
Email: nnvadsariya@myseneca.ca
Section:SHH
Date:22 July 2019
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contactHelpers.h"

// define MAXCONTACTS for sizing contacts array (5)
#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+


// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int value=0;
	char NL= '\0';
	while (NL != '\n')
	{
		scanf("%d%c", &value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else
		{
			return value;
		}
	}
	return value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int value=0;
	int done=0;
	
	while (done != 1)
	{
		value = getInt();
		if (value >= min && value <= max)
		{
			done = 1; 
		}
		else
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	}
	return value;
}

// yes: Empty function definition goes here:
int yes()
{	
	int rv=-1;  //rv is return value and 0 is for no and 1 is for yes
	char response = '\0';
	char NL = '\0';
	while (NL != '\n')
	{
		
		scanf("%c%c", &response, &NL);

		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if (NL == '\n')
		{	
			if (response == 'Y' || response == 'y')
			{	
				rv = 1;
				
			}
			else if(response == 'N' || response == 'n')
			{
				rv = 0;
			
			}
			else
			{
				NL = '\0';
				printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			}
		}
		
	}
	return rv;
}


// menu: Empty function definition goes here:
int menu(void)
{	
	int value=0;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	value=getIntInRange(0,6);
	return value;
}


void contactManagerSystem(void)
{
	int done = 0;
	
	struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes"},{ 11, "Trailer Park", 0, "A7A 2J2", "King City"},{ "4161112222", "4162223333", "4163334444"} },{ { "Maggie", "R.", "Greene"},{ 55, "Hightop House", 0, "A9A 3K3", "Bolton"},{ "9051112222", "9052223333", "9053334444"} },{ { "Morgan", "A.", "Jones"},{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},{ "7051112222", "7052223333", "7053334444"} },{ { "Sasha", {'\0'}, "Williams"},{ 55, "Hightop House", 0, "A9A 3K3", "Bolton"},{ "9052223333", "9052223333", "9054445555"} }, };
		
		while (done == 0)
		{
			int option = menu();
			
			if (option == 0)
			{
				printf("\nExit the program? (Y)es/(N)o: ");
			
				if (yes())
				{
					printf("\nContact Management System: terminated\n");
					done = 1;
				}
				else
				{
					printf("\n");
				}
			}
			else {
				if (option == 1)
				{
					displayContacts(contacts, MAXCONTACTS);
				}
				else if (option == 2)
				{
					addContact(contacts, MAXCONTACTS);
				}
				else if (option == 3)
				{
					updateContact(contacts, MAXCONTACTS);
							}
				else if (option == 4)
				{
					deleteContact(contacts, MAXCONTACTS);
				}
				else if (option == 5)
				{
					searchContacts(contacts, MAXCONTACTS);
				}
				else if (option == 6)
				{
					sortContacts(contacts, MAXCONTACTS);
				}
				printf("\n\n");
				pause();
				printf("\n");
			}
		}	
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	
	while (needInput == 1) {
		scanf("%10s", phoneNum);
		
		clearKeyboard();

		int isValid = 1;  // 1: input is valid, 0: input is invalid
		
		if (strlen(phoneNum) == 10) {
			for (int i = 0; i < 10 && isValid; i++)
			{
				if (!isdigit(phoneNum[i])) {
					isValid = 0;
				}
			}
		}
		else {
			isValid = 0;
		}

		if (!isValid){
			printf("Enter a 10-digit phone number: ");
		}
		else {
			needInput = 0;
		}
	}
}

int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int rv = -1; //return value
	for (int i = 0; i < size && rv == -1; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum)== 0)
		{
			rv = i;
		}
	}
	return rv;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	printf(" %s", contact->name.firstName);
	if (contact->name.middleInitial != '\0')
	{
		printf(" %s", contact->name.middleInitial);
	}
	printf(" %s\n", contact->name.lastName);
		
	printf("    C: %-10s   H: %-10s   B: %-10s\n",contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ",contact->address.streetNumber,contact->address.street);

	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ",contact->address.apartmentNumber);
	}
	printf("%s, %s\n",contact->address.city,contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i = 0;
	int entries = 0;
	displayContactHeader();
	for (i = 0;i < size;i++)
	{
		if (atoi(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			entries += 1;
		}
	}
	displayContactFooter(entries);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char number[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	int rv = findContactIndex(contacts, size, number);
	
	if (rv == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		displayContact(&contacts[rv]);
		printf("\n");
	}

}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int slot = findContactIndex(contacts, size, "");

	if (slot == -1)
	{
		printf("\n*** ERROR: The contact list is full! ***");
	}
	else
	{
		printf("\n");
		getContact(&contacts[slot]);
		printf("---New contact added! ---");
	}
}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char number[11];

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	int slot=findContactIndex(contacts, size, number);

	if (slot == -1)
	{
		printf("*** Contact NOT FOUND ***");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[slot]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[slot].name);
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[slot].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[slot].numbers);

		}

		printf("---Contact Updated! ---");

	}

}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char number[11];
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(number);

	int slot = findContactIndex(contacts, size, number);

	if (slot == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[slot]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		
		if (yes())
		{
			contacts[slot].numbers.cell[0] = '\0';
			printf("---Contact deleted! ---\n");
		}
	}

}

// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j, m;

	for (i = 0; i < size; i++) {
		m = i;
		for (j = i + 1; j < size; j++) {
			if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell) < 0) {
				m = j;
			}
		}
		if (m != i) {
			struct Contact temp = contacts[i];
			contacts[i] = contacts[m];
			contacts[m] = temp;
		}
	}
	printf("--- Contacts sorted! ---\n");

}
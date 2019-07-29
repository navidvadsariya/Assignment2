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

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )
// getName:
void getName(struct Name* name)
{
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	
	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();

}

// getAddress:
void getAddress(struct Address* address)
{
	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	
	while (address->streetNumber < 0)
	{							
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			address->streetNumber = getInt();				
	} 

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	
	if (yes())
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();

		while (address->apartmentNumber < 0)
		{
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			address->apartmentNumber = getInt();
		}
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	clearKeyboard();
	
	printf("Please enter the contact's city: ");
	scanf("%40[^\n]%*c", address->city);
	
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	printf("Please enter the contact's cell phone number: ");
	//scanf("%10[^\n]%*c", numbers->cell);
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	
	if (yes())
	{
		printf("Please enter the contact's home phone number: ");
		//scanf("%10[^\n]%*c", numbers->home);
		getTenDigitPhone(numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");

	if (yes())
	{
		printf("Please enter the contact's business phone number: ");
		//scanf("%10[^\n]%*c", numbers->business);
		getTenDigitPhone(numbers->business);
	}
}




// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

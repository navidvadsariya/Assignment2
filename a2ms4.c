
/* -------------------------------
Name:Navid Vadsariya
Student number: 136884186
Email: nnvadsariya@myseneca.ca
Section:SHH
Date:22 July 2019
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- 
/*
+--------------------------------------------------------*
|           2  0  1  9  ~  S  U  M  M  E  R
|                 I  P  C  :  B  T  P
|                 1  4  4  :  1  0  0
|                 ASSIGNMENT #2 MS# 4
|
|   S  E  N  E  C  A               C  O  L  L  E  G  E
|   ========  =======  =====  ========  ======  ======
|      ==     ==      ==        ==     ==      ==   ==
|     ==     ====     ====     ==     ====    ======
|    ==     ==          ==    ==     ==      == ==
|   ==     ======  =====     ==     ======  ==   ==
|
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
|  !!!   DO NOT ALTER THE CONTENTS OF THIS FILE   !!!
|  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
+--------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

void printSectionHeader(const char* testName);

int main(void)
{
	printSectionHeader("Final A#2-Milestone #4");

	contactManagerSystem();

	return 0;
}

// Display specified test section header
void printSectionHeader(const char* testName)
{
	printf("\n");
	printf("------------------------------------------\n");
	printf("Testing: %s\n", testName);
	printf("------------------------------------------\n");
}
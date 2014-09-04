#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/* 
 * Initializes the arrayList.  Sets the size to 4,
 *  the number of elements to 0, the type to the parameter
 *  type, and allocates space for the array
 */
arrayList * initialize(primitiveType type)
{
   arrayList * newList = malloc(sizeof(arrayList));
   newList->numElements = 0;
   newList->arraySize = 4;
   newList->type = type;
   newList->elementSize = getSize(type);
   newList->array = malloc(sizeof(getSize(type)*4));

   return newList;
}

/*
 * Returns the size (in bytes) of the given primitive type
 */
int getSize(primitiveType type)
{
   if (type == charType)
       return sizeof(char);
   else if (type == shortType)
       return sizeof(short);
   else
       return sizeof(int);
}

/*
 * Adds an element to the end of the list.
 *
 * If the list is full, the list will be doubled in size before
 * adding the new element
 */
void addElement(arrayList * arrListPtr, void * element)
{
   if (arrListPtr->numElements == arrListPtr->arraySize) { //if array is full, resize and copy
       void * newArray = malloc((arrListPtr->arraySize)*(arrListPtr->elementSize)*2);
       int i;
       for (i = 0; i < arrListPtr->numElements; i++)
           //error line
       free(arrListPtr->array);
       arrListPtr->array = newArray;
       arrListPtr->arraySize *= 2;
   }
   //error line
   (arrListPtr->numElements)++;
}

void removeElement(arrayList * arrListPtr, int index)
{
   return;
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}


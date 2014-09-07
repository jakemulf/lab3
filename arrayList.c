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
       for (i = 0; i < ((arrListPtr->numElements))*(arrListPtr->elementSize); i++) {
           ((char *)newArray)[i] = ((char *)(arrListPtr->array))[i];
       }
       free(arrListPtr->array);
       arrListPtr->array = newArray;
       arrListPtr->arraySize *= 2;
   }
   int i;
   for (i = 0; i < (arrListPtr->elementSize); i++) {
       ((char *)(arrListPtr->array))[i + ((arrListPtr->numElements)*(arrListPtr->elementSize))] = ((char * )(element))[i];
   }
   (arrListPtr->numElements)++;
}

void removeElement(arrayList * arrListPtr, int index)
{ 
   int i;
   if (arrListPtr->type == charType) {
       for (i = index; i < (arrListPtr->numElements) - 1; i++)
           ((char *)(arrListPtr->array))[i] = ((char *)(arrListPtr->array))[i+1];
   }
   else if (arrListPtr->type == shortType) {
       for (i = index; i < (arrListPtr->numElements) - 1; i++)
           ((short *)(arrListPtr->array))[i] = ((short *)(arrListPtr->array))[i+1];
   }
   else { //if arrListPtr->type == intType
       for (i = index; i < (arrListPtr->numElements) - 1; i++)
           ((int *)(arrListPtr->array))[i] = ((int *)(arrListPtr->array))[i+1];
   }
   (arrListPtr->numElements)--; 
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         printf("%x ", ((char *)(arylstP->array))[i] & 0xff);
      else if (arylstP->type == shortType)
         printf("%x ", ((short *)(arylstP->array))[i] & 0xffff);
      else if (arylstP->type == intType)
         printf("%x ", ((int *)(arylstP->array))[i] & 0xffffffff);
   }
   printf("\n");
}


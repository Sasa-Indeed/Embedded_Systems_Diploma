/*
 * main.c
 *
 *  Created on: 2 Aug 2022
 *      Author: Ahmed
 */
#include <stdio.h>

int main(){

	int arr[15], size = 0,i =0;
	int *ptr = NULL;

	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &size);

	printf("Input %d number of elements in the array :\n",size);

	for(i = 0 ; i < size; ++i){
		printf("element -%d : ",i+1);
			fflush(stdout);fflush(stdin);
			scanf("%d", &arr[i]);
	}

	ptr = arr + (size - 1);

	printf("\n\nThe elements of array in reverse order are :\n");
	while(1){
		printf("element -%d : %d\n",i,*ptr);
			ptr--;
			i--;
			if(ptr == arr){
				printf("element -%d : %d",i,*ptr);
				break;
			}
		}

	return 0;
}


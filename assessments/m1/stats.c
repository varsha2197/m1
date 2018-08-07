/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/

/**
 * @file stats 
 * @brief Analyzes and prints statistical data like mean, medium, maximum 
 * and minimum number present in a char array, followed by sorting the 
 * array in descending order.
 *
 * This program analyzes an array of unsigned char data items and   
 * reports analytics on the maximum, minimum, mean, and median of the 
 * data set. In addition, the array is also reorderedin descnding order, 
 * i.e., from large to small. All statistics are rounded down to the 
 * nearest integer.
 * 
 * @author Varsha Srinivasan
 * @date 3rd August 2018
 * 
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */

#define SIZE 40

int ma,mi;
int mea,med, pos1,pos2,pos3;

void print_array(unsigned char *,  unsigned int);
int find_maximum(unsigned char *, unsigned int);
int find_minimum(unsigned char *, unsigned int);
int find_mean(unsigned char *,  unsigned int);
int find_median(unsigned char *,  unsigned int);
void sort_array(unsigned char *, const unsigned int);
void print_statistics();


void main() {

	  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
		                                114, 88,   45,  76, 123,  87,  25,  23,
						                              200, 122, 150, 90,   92,  87, 177, 244,
									                                    201,   6,  12,  60,   8,   2,   5,  67,
													                                    7,  87, 250, 230,  99,   3, 100,  90}; 
	    
	    print_array(test,SIZE);
	      ma= find_maximum(test,SIZE);
	        mi= find_minimum(test,SIZE); 
		  mea= find_mean(test,SIZE);
		    med= find_median(test,SIZE);
		      print_statistics();
		        sort_array(test,SIZE);
			    
			  /* Other Variable Declarations Go Here */
			  /* Statistics and Printing Functions Go Here */

}

void print_array(unsigned char *t, unsigned int size)
{ 
int i;
  printf("\nThe array now is-");
    for(i=0;i<size;i++)
	       printf("%d,",t[i]);
      printf("\n");
}

int find_maximum(unsigned char *t,  unsigned int size)
{ int i;
	  int max;
	    max= t[0];
	      for(i=1; i<size;i++)
		       {  if(max<=t[i])
			             {max= t[i];
					           pos1=i+1;}
				      }
	      return max;
}   
   
int find_minimum(unsigned char *t, unsigned int size)
{ int i;
	  int min;
	    min= t[0];
	      for(i=0; i<size;i++)
		       {  if(min>=t[i])
			             {min= t[i]; pos2=i+1;}
				      }
	      return min;
}   
 
int find_mean(unsigned char *t,unsigned int size)
{ int i,tot=0;
	  int me=0;
	    for(i=0; i<size;i++)
		     {  tot+=t[i];
			           
			      }
	      me=tot/size;
	      return me;
}   

int find_median(unsigned char *T, unsigned int size)
{  int me,i,j,c;
	  for(i=0;i<size-1;i++)
		   { for(j=i+1;j<size;j++)
			       { if(T[j]<T[i])
				              { c=T[j];
						      	 T[j]=T[i];
							 	 T[i]=c;
								        }
					          }
			        }
	   me=(T[size/2]+T[size/2-1])/2;
	   return me;
}

void sort_array(unsigned char *T, unsigned int size)
{ int i,j,c;
	  for(i=0;i<size-1;i++)
		   { for(j=i+1;j<size;j++)
			       { if(T[j]>T[i])
				              { c=T[j];
						      	 T[j]=T[i];
							 	 T[i]=c;
								        }
					          }
			        }
	  printf("\nNow,sorting the array in descending order...\n");
	  print_array(T,size);
}
 
void print_statistics()
{
	  printf("\n The statistics of the array are as follows:");
	    printf("\n Maximum:%d, position:%d\n Minimum:%d, position:%d\n Mean:%d\n Median:%d (Array sorted in ascending order to find median)\n",ma,pos1,mi,pos2,mea,med);
}
/* Add other Implementation File Code Here */


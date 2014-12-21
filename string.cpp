#include<iostream>
using namespace std;
void reverseseach(char *str);

void reverses(char *str)
{
    int length=0;
    char *end = str;
    cout<<"\n start endl valude  :"<<str;
    while(*end != '\0')
    {
        length++;
        end++;
    }
    cout<<"\n length : "<<length<<endl;
    end--;
   // char *end1 = str;
   // cout<<"\n endl valude  :"<<end1;
 //int len=strlen(str);
    while(str < end)
    {

        char temp = *str;
        *str++ = *end;
        *end-- = temp;


    }
    cout<<"in 1: "<<str<<endl;
    reverseseach(str);

}

void reverseseach(char *str)
{
	char *end=str;
	while(*str==' ')
	{
		str++;

	}
	while(end < str)
	    {

	        char temp = *end;
	        *end++ = *str;
	        *str-- = temp;


	    }
	 cout<<"in 2: "<<str<<endl;
}

void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
void reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s; /* temp is for word boundry */

    /*STEP 1 of the above algorithm */
    while( *temp )
    {
        /*This condition is to make sure that the string start with
          valid character (not space) only*/
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } /* End of while */

    /*STEP 2 of the above algorithm */
    reverse(s, temp-1);
}
void rev(char *a);
void reve(char * , char *);
//int repeat(char *a);

#include<stdlib.h>
#include<stdio.h>
#define NO_OF_CHARS 256

int *getCharCountArray(char *str)
{
   int *count = (int *)calloc(sizeof(int), NO_OF_CHARS);
   int i;
   for (i = 0; *(str+i);  i++)
   {
	   cout<<"  "<<*(str+i);

      count[*(str+i)]++;
      cout<<"   "<<count[*(str+i)];
      //count++;
   }
   return count;
}

/* The function returns index of first non-repeating
   character in a string. If all characters are repeating
   then returns -1 */
int firstNonRepeating(char *str)
{
  int *count = getCharCountArray(str);
  int index = -1, i;

  for (i = 0; *(str+i);  i++)
  {
    if (count[*(str+i)] == 1)
    {
      index = i;
      break;
    }
  }

  free(count); // To avoid memory leak
  return index;
}

/* Driver program to test above function */
/*int main()
{
  char str[] = "raju nyathani";
  int index =  firstNonRepeating(str);
  if (index == -1)
    printf("Either all characters are repeating or string is empty");
  else
   printf("First non-repeating character is %c", str[index]);
  getchar();
  return 0;
}
*/



void rev(char *s)
{
	char *word_begin = s;
	  char *temp = s; /* temp is for word boundry */

	  /*STEP 1 of the above algorithm */
	  while( *temp )
	  {
	    temp++;
	    if (*temp == '\0')
	    {
	      reverse(word_begin, temp-1);
	    }
	    else if(*temp == ' ')
	    {
	      reverse(word_begin, temp-1);
	      word_begin = temp+1;
	    }
	  } /* End of while */

	   /*STEP 2 of the above algorithm */
	  reve(s, temp-1);
}
void reve(char *a, char *b)
{
	char temp;
	while(a<b)
	{
		temp=*a;
		*a=*b;
		*b=temp;
		a++;
		b--;
	}

}

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "mobydick.h"

/*
 Author: Shovik Shyamsundar
 Filename: mobydick.c
 Description: Your implementation of the mobydick anagram finder. Add comments whenever possible.
 */

//Global variables
char _input[1243540];
int c = 0; //multipurpose counter
int i = 0; //multipurpose counter
int j = 0; //multipurpose counter
int k = 0; 
int linecount = 1;
short notfound = 1;
short strlength = 0;

/* Removes blanks from char* array */
                   

char* deblank(char* input)	{
	  int i, j;
	  char *output=input;
	  for (i = 0, j = 0; i<strlen(input); i++,j++)
	    {
	      if (!(isblank(input[i])))
		output[j]=input[i];
	      else
		j--;
	    }
	  output[j]=0;
	  return output;
	

}
/* Load stdin */
void load_input() {
	while ((_input[i]=getchar()) !=EOF) i++;
   	_input[i]=0;
}

/*
 _unsolved_anagram: 
 _lineno:
 _solved_anagram:
 */ 
void find_anagram(char *_unsolved_anagram, int *_lineno, char *_solved_anagram){
        //Removes whitespace from _unsolved_anagram
         _unsolved_anagram =  deblank(_unsolved_anagram);
	// finding length of anagram
	k=1;
	strlength=0;
	while (_unsolved_anagram[strlength] != '\0') {
	   if (isupper(_unsolved_anagram[strlength]))
	     _unsolved_anagram[strlength]+=32;
	 strlength++;
	}
	char _ana_arr[strlength]; // anagram clone
	char _compare_arr[strlength]; // moby dick snippet array
	// populating the anagram clone
	for(i=0; i<=strlength; i++) {_ana_arr[i] = _unsolved_anagram[i];}
	// populating the moby dick snippet array
	for(j=0, k=0; j<=strlength; j++, k++) {
	  while (!(isalpha(_input[k]))) {
			k++;
		}
		//if (j==strlength)
		//	_compare_arr[j] = '\0';
		if (isupper(_input[k]))
			_compare_arr[j] = _input[k]+32;				
		else if (islower(_input[k])||isspace(_input[k]))
			_compare_arr[j] = _input[k];
	}
	i=0; // _compare_array index counter
	j=0; // _ana_array index counter
	k=1; // _input index counter for the starting index of _compare_array
	int templength = strlength;
	while(notfound==1) {
		i=0;
		j=0;
		while(_ana_arr[j]!='\0' && i<strlength){
			if(_compare_arr[i]==_ana_arr[j]){
				j++;
				_compare_arr[i]='#';
				i=0;
			}
			else i++;
		}
		if(i>=strlength){
			k++;
			// repopulate _compare_arr
			for(i=0, j=0; i<strlength; i++, j++) {
			  while (!(isalpha(_input[k+j]))){
					templength++;
					j++;
				}
				if (isupper(_input[k+j]))
					_compare_arr[i] = _input[k+j]+32;
				else if(islower(_input[k+j])||isspace(_input[k+j]))
					_compare_arr[i] = _input[k+j];
			}
		}
		else notfound=0;
	}
	notfound=1;
	linecount=1;
	char endstring[64] = {};
	for(i=0, j=0; i<strlength; i++, j++) {
	  while (!(isalpha(_input[k+j]))){
			endstring[i] = _input[k+j];
			j++;
			i++;
			strlength++;
		}
		endstring[i] = _input[k+j];
	}
	for(i=0; endstring[i]!='\0'; i++) {
		_solved_anagram[i] = endstring[i];
	}
	while (k>=0) {
		if (_input[k] == '\n')
			linecount++;
		k--;
	}	
	*_lineno=linecount;
}

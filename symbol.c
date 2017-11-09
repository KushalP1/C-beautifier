#define MAXSYMBOLS 200
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct entry{
	char *lexptr;
	int token;
};

char* keywords[] = {"auto","break","case","char","const","continue","default","do",
					"double","else","enum","extern","float","for","goto","if","int",
					"long","register","return","short","signed","sizeof","static",
					"struct","switch","typedef","union","unsigned","void","volatile",
					"while"}; 

struct entry symtable[MAXSYMBOLS+1];

int lookup(char *lexeme){
	int i = 0;
	for(i = 0;i<MAXSYMBOLS;i++){
		if(strcmp(symtable[i].lexptr,lexeme)==0){
			return symtable[i].token;
		}
	}
	return -1;
}

int insert(char *a, int token){
	int i = 31;
	while(symtable[++i].token != -1);
	if(i >= MAXSYMBOLS){
		return -1;
	}
	else{
		strncpy(symtable[i].lexptr,a,strlen(a));
		symtable[i].token = token;
		return 0;
	}	
}

void print_sym(){
	int i;
	for(i = 0;i<MAXSYMBOLS;i++){
		printf("string is %s and token is %d\n",symtable[i].lexptr,symtable[i].token);
	}
}

void init(){
	int i=0;
	for(i = 0;i<=MAXSYMBOLS;i++){
		symtable[i].lexptr = malloc(100*sizeof(char));
		symtable[i].token = -1;
	}
	for(i = 0;i<32;i++){
		symtable[i].lexptr = keywords[i];
		symtable[i].token = 0;
	}
}

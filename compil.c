//convert abstract machine code into model language
//S::=x:=e | skip | S;S | if b then S else S | while b do S
#include <stdio.h>
#include <stdlib.h>
//needed for split function
#include <string.h>
#include <assert.h>
//needed for regex
#include <regex.h> 

//try to split what we get in entrance
char** str_split(char *a_str, const char a_delim);
int parseAtom();
int parseInstr(); //Instr = Atom | LOOP(Prog, Prog) | BRANCH(Prog, Prog)
int parseProg(char *assembleur); //Prog = (Intsr)*

int *pile;

int main() //write the code in assembler and call parseProg()
{
	char *assembleur = "TeSt";
	printf("Enter your instructions in assembler\n");
	printf("Please do not use space\n");
	//scanf("%s",assembleur);
	parseProg(assembleur);
    //printf("%s",assembleur);
    return 0;
}

//split a string calling str_split(string you want to split, delimiter/spliter)
char** str_split(char *a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    // Count how many elements will be extracted
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    // Add space for trailing token
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}


int parseAtom(char *trans) //Atom = PUSH-n | ADD | SUB | MULT | TRUE | FALSE | EQ | LE | AND | NEG | FETCH-x | STORE-x | NOOP
{
	//transform the initial code into our model code
		//S::=x:=e | skip | S;S | if b then S else S | while b do S
	//gets from parseInstr() : *trans = "STORE-x"
	//return model code to main 

	//if we have code inside trans who need to be transform
		//we change the code following the rules
	if(/*trans match with "PUSH-n" using regex */) 
	{
		//int x = n from "PUSH-n"
		*pile = x; //global
		&pile += 1;
		return 0;
	}
	if(/*trans match with "FETCH-x" using regex */) 
	{
		//int x = x from "FETCH-x"
		return 0;
	}
	if(/*trans match with "ADD" using regex */) 
	{
		return (*pile + *(pile - 1));
	}
	if(/*trans match with "SUB" using regex */) 
	{
		return (*pile - *(pile - 1)); //*pile = a1 ; *(pile - 1)= a2  ; return a1 - a2
	}
	//do it for others ...

	return 1;
}

int parseInstr(char *code) //Instr = Atom | LOOP(Prog, Prog) | BRANCH(Prog, Prog)
{
	//call parseAtom() in case of simple atom and call back parseProg() in we are inside a LOOP or a BRANCH

	//gets from parseProg() char code[]= "PUSH-1","STORE-Y","LOOP(FETCH-x:PUSH-0:LE,PUSH-1:FETCH-x:SUB:STORE-x)"
	//gives to parseAtom() : *trans = "PUSH-1"
	while(*code) //while we do not have \0
	{
		//if LOOP or BRANCH
			//executes the LOOP/BRANCH
			//calls parseProg() for the 2 arguments inside
		//if simple atom
			//calls parseAtom()
	}
	return 0;
}

int parseProg(char *assembleur) //Prog = (Intsr)*
{
	//split the code with the ":"
	//only outside () //meaning outside LOOP or BRANCH

	//gets from main : char *assembleur = "PUSH-1:STORE-y:LOOP(FETCH-x:PUSH-0:LE,PUSH-1:FETCH-x:SUB:STORE-x)"
	//gives to parseInstr : char code[]= "PUSH-1","STORE-Y","LOOP(FETCH-x:PUSH-0:LE,PUSH-1:FETCH-x:SUB:STORE-x)"
	
	regex_t regex;
	int reti;
	char msgbuf[100];
	size_t nmatch;
	regmatch_t *pmatch[100];

	/* Compile regular expression */
	reti = regcomp(&regex, *assembleur, 0);
	if (reti) {
	    fprintf(stderr, "Could not compile regex\n");
	    exit(1);
	}
	else
	{
		printf("GOOD FOR NOW\n");
	}

	/* Execute regular expression */
	reti = regexec(&regex, "[A-Z]", 0, NULL, 0);
	if (!reti) {
	    puts("Match");
	}
	else if (reti == REG_NOMATCH) {
	    puts("No match");
	}
	else {
	    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
	    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
	    exit(1);
	}

	/* Free memory allocated to the pattern buffer by regcomp() */
	regfree(&regex);




	//TRY WITH THE SPLIT ONLY --> NOT WORKING FOR INSIDE THE "()"
	//char**tokens;
	/*while(assembleur!="(")
	{
		//tokens = str_split(assembleur,":");
		
	}
	char* tokens = str_split(assembleur, ":");
	printf("assembleur=[%s]\n\n", assembleur);
	printf("tokens=[%s]\n", *(tokens));
	printf("tokens=[%s]\n", *(tokens + 1));

	*/
	return 0;
	/* 
	USE IT TO KNOW HOW THE STR_SPLIT WORKS
	char tok[] = "GEEK:FOR:GEEKS";
    char** tokens;
	printf("tok=[%s]\n\n", tok);

    tokens = str_split(tok, ':');

    if (tokens)
    {
        int i;
        for (i = 0; *(tokens + i); i++)
        {
            printf("tok=[%s]\n", *(tokens + i));
            free(*(tokens + i));
        }
        printf("\n");
        free(tokens);
    }
    */
}
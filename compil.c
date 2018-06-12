//convert abstract machine code into model language
//S::=x:=e | skip | S;S | if b then S else S | while b do S
#include <stdio.h>
#include <stdlib.h>
//needed for split function
#include <string.h>
#include <assert.h>


//split a string calling str_split(string,delimiter)
char** str_split(char* a_str, const char a_delim)
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
    	//BEGIN MODIF - do not look inside ()
    	while (*tmp == "(")
    	{
    		while(*tmp != ")")
	    	{
	    		tmp++;
	    	}
    	}
    	//END - do not look inside ()
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


int parseAtom()
{
	//Atom = PUSH-n | ADD | SUB | MULT | TRUE | FALSE | EQ | LE | AND | NEG | FETCH-x | STORE-x | NOOP

	//gérer les cas par cas pour faire correspondre suivant la nomenclature p70

	return 0;
}

int parseInstr() //Instr = Atom | LOOP(Prog, Prog) | BRANCH(Prog, Prog)
{
	//gérer les cas Atom en appelant parseAtom()

	//gérer les cas LOOP et BRANCH suivant nomenclature p71

	return 0;
}

int parseProg(char assembleur[100]) //Prog = (Intsr)*
{
	//séparer le code avec le ":" hors des "()" et le rentrer dans un tableau
	char**tokens;
	while(assembleur!="(")
	{
		tokens = str_split(assembleur,":");
	}


	return 0;
	/* 
	KNOW HOW THE STR_SPLIT WORKS
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

int main()
{
    //saisie du code en assembleur et appelle de parseProg()
	char assembleur[100];
	printf("Please, enter your instructions in assembler and split them with ':' as explain in the book 'semantics with application'\n");
	printf("Please do not use space");
	scanf("%s",assembleur);
	parseProg(assembleur);
    //printf("%s",assembleur);
    return 0;
}
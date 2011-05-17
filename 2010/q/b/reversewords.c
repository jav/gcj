#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void read_line_to_buff(FILE *file, char **in_string){
	int size = 1, read_chars = 0, i = 1;
	char *curr_pos = *in_string;
	char *half;
	char *tmp_in_string;
	char *last_char;

	*in_string = (char*) malloc(size * sizeof(char));
	do{
		(*in_string)[read_chars] = getc(stdin);
		last_char = &(*in_string)[read_chars];
		read_chars += 1;
	}while ( '\n' != *last_char && EOF != *last_char);

	*last_char = '\0';
	
	fprintf(stderr, "read_line_to_buff(): returning %s\n", *in_string);

	return;
}


char* reverse_word(char* word){
	int len = 0;
	int j = 0, i = 0;
	char l;

	//fprintf(stderr, "reverse_word( %s )\n", word);	
	
	if( 0 == word) return 0;
	
	while( ' ' != word[i] && '\0' != word[i] ) {
		i++;
	}
	if('\0' == word[i]) word[i] = ' ';
	len = i-1;
	i -= 1;
	
	for(i; i > len/2; i--){
		//fprintf(stderr, "reverse_word() (inloop) : i:%d, len:%d, len/2:%d\n", i, len, len/2);	
		//fprintf(stderr, "reverse_char word[%d] %c <=> word[%d] %c\n", i, word[i], len-i, word[len-i]);	
		l = word[i];
		word[i] = word[len-i];
		word[len-i] = l;
	}

	//fprintf(stderr, "reverse_word(): return %s\n", word);		
	return word;
}

char* reverse_words_in_buff(char **in_string){
	char *string;
	char *word;
	char *word_end;
	char tmp_char;
	int i;
	int len;
	// Reverse string

	string = *in_string;
	fprintf(stderr, "reverse_words_in_buff( %s );\n", string);
	
	fprintf(stderr, "string_start: %c, string_end: %c, string: %s\n", string[0], string[strlen(string)-1],string);
	len =  strlen(*in_string);
	for(i = 0; i < len/2; i++) {
		tmp_char = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = tmp_char;
	}
	fprintf(stderr, "string_start: %c, string_end: %c, string: %s\n", string[0], string[strlen(string)-1],string);

	// Reverse words
	word = 0;
	word = strtok(string, " ");
	while( 0 != reverse_word(word) ){
		word = strtok(0, " ");
	}
	
	string[strlen(string)-1] = '\0';	
	fprintf(stderr, "string_start (%p): %c, string_end (%p): %c, string: \"%s\"\n", string, string[0], &string[strlen(string)-1], string[strlen(string)-1],string);

	fprintf(stderr, "reverse_words_in_buff(): return %s\n", string);
	fprintf(stderr, "reverse_words_in_buff(): return %s\n", *in_string);

	return *in_string;
}

int main(int argc, char *argv[])
{
	
	int no_test_cases, i;
	char in_string[1001];
       
	if(argc != 1) {
		printf("Usage:   %s > <out-file>  < <in-file> \n" , argv[0]);
		return;
	}

	fscanf(stdin, "%d\n", &no_test_cases);
	
	for(i = 0; i < no_test_cases; i++) {
		memset(in_string, 0, sizeof(in_string));
//		fprintf(stderr, "in_string: %p, *in_string: %p, **in_string: %s\n", in_string, *in_string, **in_string);
		read_line_to_buff(stdin, &in_string);
//		fprintf(stderr, "in_string: %p, *in_string: %p, **in_string: %s\n", in_string, *in_string, **in_string);
		printf("Case #%d: %s\n" , i+1,reverse_words_in_buff(&in_string) );
//		fprintf(stderr, "in_string: %p, *in_string: %p, **in_string: %s\n", in_string, *in_string, **in_string);

	}
	
	
	
}

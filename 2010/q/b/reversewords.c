#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void double_buff(int *size, char **buff, char **half) {
	char *tmp;
	*size *= 2;
	tmp = (char *)realloc(*buff, *size);
	*buff = tmp;
	*half = *buff + *size/2;
	return;
}

void read_line_to_buff(FILE *file, char **in_string){
	int size = 1, read_chars = 0, i = 1;
	char *curr_pos = *in_string;
	char *half;
	char *tmp_in_string;
	char *last_char;

	*in_string = (char*) malloc(size * sizeof(char));
	do {
		double_buff(&size, in_string, &half);
		do{
			(*in_string)[read_chars] = getc(stdin);
			last_char = &(*in_string)[read_chars];
			read_chars += 1;
		}while (read_chars < size && '\n' != *last_char && EOF != *last_char);

	} while( '\n' != *last_char && EOF != *last_char);
	*last_char = '\0';
	
	fprintf(stderr, "read: %s\n", *in_string);

	return;
}

void reverse_words_in_buff(char **in_string){
	char *string = *in_string;
	char **words;
	char *word;
	int words_size = 1 , i = 0;
	char **tmp_words ;
	char *wrt_pointer = 0, *str_out;
	fprintf(stderr, "string: %s\n", string);
	fprintf(stderr, "string: %p, wrt_pointer: %p\n", string, wrt_pointer);
	words = malloc( words_size * sizeof(char*));
	wrt_pointer = string;

	word = strtok(string, " ");
	fprintf(stderr, "word (%p): %s\n", word, word);
	words[i] = word;

	i += 1;
	words_size += sizeof(char*);;
	tmp_words = realloc(words, words_size);
	words = tmp_words;

	words[i] = word;
	while (0 != word){
		word = strtok(0, " ");
		
		fprintf(stderr, "word (%p): %s\n", word, word);
		words[i] = word;
		i += 1;

		words_size += sizeof(char*);		
		tmp_words = realloc(words, words_size);
		words = tmp_words;
	}
	i -= 2;
	fprintf(stderr, "in conclusion\n");
	str_out = wrt_pointer = malloc(strlen(string));
	for(i  ; i >= 0 ; i--) {
		fprintf(stderr, "word (%p): %s\n", words[i], words[i]);
		sprintf(wrt_pointer, "%s", words[i]);
		wrt_pointer += strlen(words[i]);
		if(0 < i) {
			fprintf(stderr, "space <= %s\n", wrt_pointer);
			sprintf(wrt_pointer, " ");
			wrt_pointer += 1;
		}


	}
	*(wrt_pointer+1) = '\0';

	fprintf(stderr, "out: %s\n", str_out);
	*in_string = str_out;

	free(words);
	return;
}

int main(int argc, char *argv[])
{
	
	int no_test_cases, i;
	char* in_string;
       
	if(argc != 1) {
		printf("Usage:   %s > <out-file>  < <in-file> \n" , argv[0]);
		return;
	}

	fscanf(stdin, "%d\n", &no_test_cases);
	
	for(i = 0; i < no_test_cases; i++) {
		in_string = malloc(1);
		fprintf(stderr, "******** Case #%d: \n" , i+1);
		read_line_to_buff(stdin, &in_string);
		reverse_words_in_buff(&in_string);
		printf("Case #%d: %s\n" , i+1, in_string);
		free(in_string);
	}
	
	
	
}

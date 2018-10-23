#include <stdio.h>
#include <cstring>
#include "catch.hpp"
const char EXIT[] = "exit";

unsigned spaceCount(char *line){
	unsigned count = 0;
	for(int i = 0; i < std::strlen(line); i++){
		if(line[i] == ' '){
			++count;
		}
	}
	return count;
}

//Shift num_chars characters start at *start by shift_amt to the right
void shift(char *start, int num_chars, int shift_amt){
	std::strncpy(start + shift_amt, start, num_chars);
}

void URLify(char input[]){
	unsigned spaces = spaceCount(input);
	char output_buf[std::strlen(input) + (spaces*2) + 1];
	std::strcpy(output_buf, input);
	// printf("input is:%s\n", input);
	// printf("input length is:%d\n", std::strlen(input));
	// printf("output_buf is:%s\n", output_buf);
	// printf("output_buf size is:%d\n",std::strlen(input) + (spaces*2) + 1);
	int remaining_spaces = spaces;
	int char_to_shift = 0;
	char replacement[] = "%20";
	for(int i = std::strlen(output_buf); i >=0; i--){
		if(output_buf[i] == ' '){
			printf("copying %d chars\n", char_to_shift);
			std::memcpy(output_buf + i + 1 + 2 * remaining_spaces, output_buf + i + 1, char_to_shift);
			--remaining_spaces;
			std::memcpy(output_buf + i + 2 * remaining_spaces,replacement,std::strlen(replacement));
			char_to_shift = 0;
			printf("output_buf is:%s\n", output_buf);
		}
		else{
			++char_to_shift;
		}
	}
}

int main(){
	char input[100];
	bool done = false;
	printf("Enter \"exit\" to exit\n");
	while(true){
		printf("Input a string :");
		gets(input);

		if(std::strcmp(EXIT, input) == 0) break;

		//printf("\nYou entered: %s\n", input);
		if(spaceCount(input) == 0){
			printf("Please enter a string with at least one space character\n");	
		}
		else{
			URLify(input);
		}
	}

}
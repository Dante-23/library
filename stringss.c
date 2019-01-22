#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define string char*
#define string_array char**
int length(char* str){
	return strlen(str);
}
int compareTo(char* str1, char* str2){
	return strcmp(str1, str2);
}
char* concat(char* str1, char* str2){
	return strcat(str1, str2);
}
bool isempty(char* str){
	if(str == NULL || str[0] == '\0')
		return true;
	else return false;
}
char* substring(char* str, int start, int end){
	char* char_node = (char*) malloc((end-start)*sizeof(char));
	int node_index = 0;
	for(int index = start; index < end; index ++){
		char_node[node_index] = str[index];
		node_index++;
	}
	return char_node;
}
char* trim(char* str){
	int start = 0;
	while(str[start] == ' ')
		start++;
	int end = strlen(str)-1;
	while(str[end] == ' ')
		end--;
	str = substring(str, start, end+1);
	return str;
}
void replace(char* str, char first, char second){
	for(int index = 0; index < strlen(str); index ++){
		if(*(str+index) == first)
			*(str+index) = second;
	}
}
int* check_prefix_suffix(char* pattern){
	int* arr = (int*) malloc(strlen(pattern)*sizeof(int));
	arr[0] = 0;
	int i = 1, j = 0;
	while(i < strlen(pattern)){
		if(pattern[i] == pattern[j]){
			arr[i] = j+1;
			i++;j++;
		}
		else if(pattern[i] != pattern[j] && pattern[i-1] == pattern[j-1])
			j = arr[arr[j-1]];
		else if(j == 0 && pattern[i] != pattern[j])
			i++;
		else
			j--;
	}
	return arr;
}
int contains(char* text, char* pattern, int search_from){
	if(search_from > strlen(text)) return -1;
	int* arr = check_prefix_suffix(pattern);
	int start = 0;
	int j = 0, i = search_from;
	while(i < strlen(text) && j < strlen(pattern)){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else if(j > 0 && text[i] != pattern[j]){
			j = arr[j-1];
			start = i-j;
		}
		else if(j == 0 && text[i] != pattern[j]){
			i++;
			start = i;
		}
	}
	return start;
}
bool startsWith(char* str, char* start){
	if(strlen(start) > strlen(str))
		return false;
	bool status = true;
	for(int index = 0; index < strlen(start); index ++){
		if(str[index] != start[index]){
			status = false;
			break;
		}
	}
	return status;
}
bool endsWith(char* str, char* end){
	if(strlen(end) > strlen(str)) return false;
	bool status = true;
	int i = strlen(str) - 1, j = strlen(end) - 1;
	while(j >= 0){
		if(str[i] != end[j]){
			status = false;
			break;
		}
		i--;j--;
	}
	return status;
}
void delete_string(char* str){
	if(str != NULL)
		free(str);
	else return;
}
void delete_string_array(char** arr, int size_of_array){
	for(int index = 0; index < size_of_array; index ++)
		free(arr[index]);
	free(arr);
}
char* remove_nextline(char* str){
	str[strlen(str)-1] = '\0';
}
char* input_string(){
	char* str = (char*) malloc(100000*sizeof(char));
	fgets(str, 100000, stdin);
	remove_nextline(str);
	return str;
}
char** input_string_array(int size_of_array){
	char** arr = (char**) malloc(size_of_array*sizeof(char*));
	for(int index = 0; index < size_of_array; index ++){
		char* char_node = (char*) malloc(100000*sizeof(char));
		fgets(char_node, 100000, stdin);
		remove_nextline(char_node);
		arr[index] = char_node;
	}
	return arr;
}
char* create_empty_string(){
	char* str = (char*) malloc(100000*sizeof(char));
	return str;
}
char** create_empty_string_array(int size_of_array){
	char** arr = (char**) malloc(size_of_array*sizeof(char*));
	return arr;
}

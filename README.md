# library

How to use the library:-
(1) First include the library by writing the following statement:-
    If needed, one can create a header file and use it.
    #include "stringss.c"

(2) Declaring a string:-
    String can be declared by using the keyword string followed by variable name.
    Example:- string variable_name;

(3) Assigning values:-
    Values can be either constant or user input.
    Example:- string varible_name = "a constant";
    For user input, input_string() function should be used.
    Example:- string varible_name = input_string();

(4) Declaring a string array:-
    String array can be declared by using the keyword string_array followed by a varible name:-
    Example:- string_array varible_name;

(5)Assigning values:-
   After declaring string array, one need to dynamically create it:-
   String array can be dynamically created by:-
        (a) Using constant values:- 
            Example:- string_array arr = create_empty_string_array(int size_of_array);
            where size_of_array = the maximum number of strings to be stored in the array.
            After that values can be assigned like below:-
            arr[0] = "value1";
            arr[0] = "value2";
            .
            .
            .
            .
            arr[size_of_array-1] = "value";

        (b) By taking user input:-
            Example:- string_array arr = input_string_array(int size_of_array);

(6) String functions:-
    (a) length(char* str) = returns the length of string str.

    (b) compareTo(char* str1, char* str2) = compared str1 and str2. Returns 1 if both are same. Return -1 
        if str1 < str2 or return 1 if str1 > str2.

    (c) concat(char* str1, char* str2) = concatenates str1 and str2, stores the value in str1 and then returns str1.

    (d) isempty(char* str) = returns true if string is empty else return false;

    (e) substring(char* str, int start, int end) = returns the substring of the string str from index
        start to end-1.

    (f) trim(char* str) = removes the leading and trailing spaces of string str and returns it.

    (g) replace(char* str, char first, char second) = replaces every 'first' with 'second' character.

    (h) contains(char* text, char* pattern, int search_from) = searches for a substring in a string and returns the index.

    (i) startsWith(char* str, char* start) = return true if str starts with start else returns false.

    (j) endsWith(char* str, char* end) = return true if str ends with end else returns false.

    (k) delete_string(char* str) = deletes the dynamically created string.

    (l) delete_string_array(char** arr, int size_of_array) = deletes the dynamically created array.

    (m) input_string() = creates a string, stores the user input in it and returns it.

    (n) input_string_array(int size_of_array) = creates a string array of size "size_of_array", stores user input in it and returns it.

    (o) create_empty_string() = creates a empty string and returns it.

    (p) create_empty_string_array(int size_of_array) = creates empty string array and returns it.

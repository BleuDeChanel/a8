#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

// trunc - no loops

// stackoverflow - intptr_t is a signed integer type that guaranteed to can hold a void* type.

// step 2 - produce a new list of numbers that processes each string to determie if it's a number
void is_int(element_t* etp, element_t et){
  intptr_t* intp = (intptr_t*) etp;
  char* elem = (char*) et;
  char* ptr;
  *intp = strtol(elem, &ptr, 10);
  if (*ptr) {
    *intp = -1;
  }
}

// step 3 - set all numbers to NULL
void null_Numbers(element_t* etp, element_t et, element_t av){
  intptr_t numList = (intptr_t) et;
  char** rv = (char**) etp;
  char* argList = (char*) av;
  if (numList == -1){
    *rv = argList;
  }
  else{
    *rv = NULL;
  }
}

// step 4 - filter out the negative numbers
int pos(element_t et){
  int res = 1;
  if (et < 0) {
      res = 0;
  }
  return res;
}

// step 5 - filter out the NULLs
int filter_null(element_t et) {
  int res = 1;
  if (et == NULL){
    res = 0;
  }
  return res;
}

// step 6 - trucate each string according to the index
void truncate(element_t* etp, element_t numlist, element_t strlist){
  intptr_t index = (intptr_t) numlist;
  char* trunc = (char*) strndup(strlist, index);
  *etp = trunc;
}

// step 7 - print truncated list of strings in each line
void print_element (element_t ev) {
  printf ("%s\n", (char*)ev);
}

// step 8
void print_together (element_t ev) {
  char* s = (char*) ev;
  if (strlen(s) == 0) {
    printf("");
  }
  printf ("%s" " ", s);
}

// step 9 - compute the maximum value
void maximum(element_t* output, element_t current, element_t listval) {
   intptr_t* res = (intptr_t*) output;
   intptr_t current1 = (intptr_t) current;
   intptr_t listval1 = (intptr_t) listval;
   
   int current_number = (int) current1;
   int list_number = (int) listval1;

   if (list_number >= current_number) {
     *res = listval1;
   }
}


int main(int argc, char** argv) {
  if (argc > 1) {
    struct list* ori_list = list_create();
    for (int i=1; i < argc; i++) {
      list_append(ori_list, argv[i]);
    }
    
    struct list* int_flag_list = list_create();
    list_map1(is_int, int_flag_list, ori_list);

    struct list* int_null_list = list_create();
    list_map2(null_Numbers, int_null_list, int_flag_list, ori_list);

    struct list* pos_list = list_create();
    list_filter(pos, pos_list, int_flag_list);

    struct list* no_null_list = list_create();
    list_filter(filter_null, no_null_list, int_null_list);

    struct list* trunc_list = list_create();
    list_map2(truncate, trunc_list, pos_list, no_null_list);

    list_foreach(print_element,trunc_list);
    list_foreach(print_together,trunc_list);
    
    element_t max = 0;
    list_foldl(maximum, &max, pos_list);
    printf("\n%d\n", max);

    list_destroy(ori_list);
    list_destroy(int_flag_list);
    list_destroy(int_null_list);
    list_destroy(pos_list);
    list_destroy(no_null_list);
    for (int i = 0; i < list_len(trunc_list); i++){
      element_t t = list_get(trunc_list,i);
      free(t);
    }
    list_destroy(trunc_list);
  }
  return 0;
}
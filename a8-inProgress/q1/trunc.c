#include <stdlib.h>
#include "list.h"

// trunc - no loops

int main(int argc, char** argv) {
  if (argc > 1) {
    struct list* str_list = list_create();
    struct list* int_list = list_create();

    for (int i=1; i < argc; i++) {
      list_append(str_list, argv[i]);
    }
    // strtol(argc, &l, 10); // look at the str(argc) and cut off the first 'number' and return - return 0 if there's just string.
    // how do we distinguish if it's the 0 as the consequence, or an actual 0?
  }
}


// step 2 - produce a new list of numbers that processes each string to determie if it's a number
void only_ints(struct list* in_list, struct list* out_list) {
  // void list_map1 (void (*f) (element_t*, element_t), struct list* out_list, struct list* in_list)
  list_map1(is_int, out_list, in_list);
}

// processes each string to determine if it is a number
// if it's not a number return -1
void is_int(element_t* etp, element_t et) {
  // et is the element we want to put into etp?
  // etp is an int*
  (int**) intp = (int**) etp;
  char* elem = et;
  char* ptr;

  *intp = malloc(sizeof(*int));
  **intp = strtol(elem, ptr, 10);
  if (*ptr != null) {
    **intp = -1;
  }
}

// we deal with 'each' substring
// so if it's a number, ptr points to null
// if it's a string, ptr points to some string 
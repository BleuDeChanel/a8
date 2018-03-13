#include <stdlib.h>
#include "list.h"

// trunc - no loops

int main(int argc, char** argv) {
  if (argc > 1) {
    struct list* l = list_create();

    for (int i=1; i < argc; i++) {
    	// are we assuming the argc <= 10 or do we expand as well?
      	l->data[i] = argv[i];
    }

    // where is a-1 coming from?
    strtol(argc, &l, 10); // look at the str(argc) and cut off the first 'number' and return - return 0 if there's just string.
    // how do we distinguish if it's the 0 as the consequence, or an actual 0?
   }
}

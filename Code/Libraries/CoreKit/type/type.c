//
// Created by Willow Bracker on 06/06/2023.
//

#include "type.h"
#include "memory/memory.h"
#include "utils/strings.h"
#include "utils/memory.h"

// Heap object that contains all needed things for a TypeRecord.

typedef struct _MemTypeRecord {
  TypeRecord type_record;
  char* type_name;
} MemTypeRecord;

void initialize_type(TypeRecord type_record, char* type_name) {
  // Allocate.

  char* new_type_name = memalloc(strlen(type_name));
  MemTypeRecord* new_record = memalloc_alligned(sizeof(MemTypeRecord));

  // Copy.

  strcpy(type_name, new_type_name);
  memcpy(&type_record, new_record, sizeof(TypeRecord));

  // Assign.
};

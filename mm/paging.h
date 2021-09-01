typedef struct paget{
  uint32_t present            : 1;
  uint32_t readwrite          : 1;
  uint32_t usersupervisor     : 1;
  uint32_t writethrough       : 1;
  uint32_t cachedisabled      : 1;
  uint32_t accessed           : 1;
  uint32_t dirty              : 1;
  uint32_t pat                : 1;
  uint32_t global             : 1;
  uint32_t available          : 3;
  uint32_t pbadress           : 20;
} page_t;

typedef struct page_table {
   page_t pages[1024];
} page_table_t;

typedef struct page_dir {
  page_table_t *tables[1024];
  uint32_t tablesPhysical[1024];
  uint32_t pysicalAdress;
} page_directory_t;

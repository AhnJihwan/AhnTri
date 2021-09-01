typedef struct paget{
  uint32_t present;
  uint32_t readwrite;
  uint32_t usersupervisor;
  uint32_t writethrough;
  uint32_t cachedisabled;
  uint32_t accessed;
  uint32_t dirty;
  uint32_t pat;
  uint32_t global;
  uint32_t available;
  uint32_t pbadress;
} page_t;

typedef struct page_table {
   page_t pages[1024];
} page_table_t;

typedef struct page_dir {
  page_table_t *tables[1024];
  uint32_t tablesPhysical[1024];
  uint32_t pysicalAdress;
} page_directory_t;

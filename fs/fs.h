/*I'm tring to understand James Molloy's tutorial and make my fs driver.*/

typedef struct fs_node
{
  char name[128];
  u32int flags;
  read_type_t read;
  write_type_t write;
  open_type_t open;
  close_type_t close;
  readdir_type_t readdir;
  finddir_type_t finddir;
} fs_node_t;

typedef struct fs_node
{
   char name[128];     // Name of the file as char
   uint32 mask;        // The mask is uint32
   uint32 uid;         // The owning user ID
   u32int gid;         // The owning group ID
   u32int flags;       // Includes the node type.
   u32int length;      // Size of the file stored as bytes
   read_type_t read;
   write_type_t write;
   open_type_t open;
   close_type_t close;
   readdir_type_t readdir;
   finddir_type_t finddir;
} fs_node_t;
//That's long as I can do tonight.

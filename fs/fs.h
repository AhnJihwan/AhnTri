typedef struct fs_node
{
  char name[128];     // The filename.
  u32int flags;       // Includes the node type (Directory, file etc).
  read_type_t read;   // These typedefs are just function pointers. We'll define them later!
  write_type_t write;
  open_type_t open;
  close_type_t close;
  readdir_type_t readdir; // Returns the n'th child of a directory.
  finddir_type_t finddir; // Try to find a child in a directory by name.
} fs_node_t;

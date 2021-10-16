#include "../libc/atclib.h"

#define FS_FILE        0x01
#define FS_DIRECTORY   0x02
#define FS_CHARDEVICE  0x03
#define FS_BLOCKDEVICE 0x04
#define FS_PIPE        0x05
#define FS_SYMLINK     0x06
#define FS_MOUNTPOINT  0x08

typedef u32int (*read_type_t)(struct fs_node*,u32int,u32int,u8int*);
typedef u32int (*write_type_t)(struct fs_node*,u32int,u32int,u8int*);
typedef void (*open_type_t)(struct fs_node*);
typedef void (*close_type_t)(struct fs_node*);
typedef struct dirent * (*readdir_type_t)(struct fs_node*,u32int);
typedef struct fs_node * (*finddir_type_t)(struct fs_node*,char *name);

typedef struct fs_node {
   char name[256];          // The filename.
   uint32_t mask;           // Permission mask
   uint32_t uid;            // Owner of file.
   uint32_t gid;            // Owning group.
   uint32_t flags;          // Including the node type.
   uint32_t inode;          // Device specific, filesystems to identify the files in the filesystem.
   uint32_t length;         // Bytes of the size of the file in the filesystem.
   read_type_t read;        // Read 
   write_type_t write;      // Write
   open_type_t open;        // Open
   close_type_t close;      // Close
   readdir_type_t readdir;  // Read dir
   finddir_type_t finddir;  // Find dir
} fs_node_t;

struct dirent {
  char name[256];
  uint32_t ino;
};


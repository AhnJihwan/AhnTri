/*I'm tring to understand James Molloy's tutorial and make my fs driver.*/
#define FS_FILE        0x01
#define FS_DIRECTORY   0x02
#define FS_CHARDEVICE  0x03
#define FS_BLOCKDEVICE 0x04
#define FS_PIPE        0x05
#define FS_SYMLINK     0x06
#define FS_MOUNTPOINT  0x08

//Defining Types
typedef u32int (*read_type_t)(struct fs_node*,u32int,u32int,u8int*);
typedef u32int (*write_type_t)(struct fs_node*,u32int,u32int,u8int*);
typedef void (*open_type_t)(struct fs_node*);
typedef void (*close_type_t)(struct fs_node*);
typedef struct dirent * (*readdir_type_t)(struct fs_node*,u32int);
typedef struct fs_node * (*finddir_type_t)(struct fs_node*,char *name); 

typedef struct fs_node
{
  char name[128];     // Name of the file as char
  uint32 mask;        // The mask is uint32
  uint32 uid;         // The owning user ID
  u32int gid;         // The owning group ID
  u32int flags;       // Includes the node type.
  u32int length;      // Size of the file stored as bytes
  uint32 implmnt;     //Implement defined num.
  read_type_t read;
  write_type_t write;
  open_type_t open;
  close_type_t close;
  readdir_type_t readdir;
  finddir_type_t finddir;
  struct fs_node *ptr;
} fs_node_t;

struct dirent{
  char name[128]; //2^7=Filename size
  uint32 ino;     //Internal Node Number
};

extern fs_node_t *fs_root;

u32int read_fs(fs_node_t *node, u32int offset, u32int size, u8int *buffer);
u32int write_fs(fs_node_t *node, u32int offset, u32int size, u8int *buffer);
void open_fs(fs_node_t *node, u8int read, u8int write);
void close_fs(fs_node_t *node);
struct dirent *readdir_fs(fs_node_t *node, u32int index);
fs_node_t *finddir_fs(fs_node_t *node, char *name);

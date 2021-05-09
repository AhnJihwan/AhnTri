#include "fs.h"

fs_node_t *fs_root = 0; // The root of the filesystem.

u32int read_fs(fs_node_t *node, u32int offset, u32int size, u8int *buffer){
  if (node->read != 0)
    return node->read(node, offset, size, buffer);
  else
    return 0;
} 

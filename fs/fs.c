#include "fs.h"

fs_node_t *fs_root 0;

uint32_t read_fs(fs_node_t *node, uint32_t size, uint32_t offset, uint32_t *buffer){
        if(nod->read!=NULL){
                return node->read(node, offset, size, buffer);
        }else{
                return 0;
        }
}

uint32_t write_fs(fs_node_t *node, uint32_t size, uint32_t offset, uint32_t *buffer){
        if(node->write!=NULL){
                return node->write(node, offset, size, buffer);
        }else{
                return 0;
        }
}

uint32_t open_fs(fs_node_t *node, uint8_t read, uint8_t write){
        if(node->open!=NULL){
                return node->open(node);
        }
}

uint32_t close_fs(fs_node_t *node, uint8_t read, uint8_t write){
        if(node->close!=NULL){
                return node->close(node);
        }
}

struct dirent readdir_fs(fs_node_t *node, uint32_t index){
        if ((node->flags&0x7) == FS_DIRECTORY && node->readdir != 0 ){
                return node->readdir(node, index);
        }else{
                return 0;
        }
]


fs_node_t *finddir_fs(fs_node_t *node, char *name){
        if ((node->flags&0x7) == FS_DIRECTORY && node->readdir != 0 ){
                return node->finddir(node, name);
        }else{
                return 0;
        }
}

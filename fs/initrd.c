#include "initrd.h"

//------------------------------
#define FILE_NAME_LEN 100
#define OWNER_NUMERIC_ID 8
#define GROUP_NUMERIC_ID 8
#define FILESIZE_LEN 12
#define SECTOR_SIZE 512
#define OWNER_USER_NAME_SIZE 32
#define OWNER_GROUP_NAME_SIZE 32
//-------------------------------

initrd_header_t initrd_header;
initrd_file_header_t *file_headers;
fs_node_t *root_nodes[9];
int nroot_nodes;

struct dirent dirent;

enum tar_file_types{
  norfilei = 0,
  norfileii = '0',
  hardlink = '1',
  symlink = '2',
  chardev = '3',
  blockdev = '4',
  dir = '5',
  namedpipefifo = '6',
};

typedef struct tarheader{
        uint32_t filename[FILE_NAME_LEN];
        uint32_t filmode;
        uint32_t owneruid[OWNER_NUMERIC_ID];
        uint32_t groupuid[GROUP_NUMERIC_ID];
        uint32_t fsize[FILESIZE_LEN];
        uint32_t modt[12];
        uint32_t checksum[8];
        uint8_t type;
        uint8_t linkedfile[100]
        uint8_t sign[6];        // Which is gonna be ustar\0
        uint8_t ver[2];         // Gotta be 00
        uint8_t owneruname[OWNER_USER_NAME_SIZE];
        uint8_t ownergname[OWNER_GROUP_NAME_SIZE];
        uint32_t devmajornum[8];
        uint32_t devminornum[8];
        uint32_t filenameprefix[155];
} tar_header_t;

//Borrowed from osdev.org (like many did)
int oct2bin(unsigned char *str, int size) {
    int n = 0;
    unsigned char *c = str;
    while (size-- > 0) {
        n *= 8;
        n += *c - '0';
        c++;
    }
    return n;
}

extern char _binary_ahntri_initrd_kerneldisk_start;
extern char _binary_ahntri_initrd_kerneldisk_size;
extern char _binary_ahntri_initrd_kerneldisk_end;

void initinitrd(){
  uint8_t initrd_start = (uint8_t)&_binary_ahntri_initrd_kerneldisk_start;
  uint8_t initrd_size = (uint8_t)&_binary_ahntri_initrd_kerneldisk_size;
  uint8_t initrd_end = (uint8_t)&_binary_ahntri_initrd_kerneldisk_end;
}

// tar lookup(returns the file size
// tar 안에서 찾기
int tar_lookup(unsigned char *ptr, char *filename, char **out) {
    while (!memcmp(ptr + 257, "ustar", 5)) {
        int filesize = oct2bin(ptr + 0x7c, 11);
        if (!memcmp(ptr, filename, strlen(filename) + 1)) {
            *out = ptr + 512;
            return filesize;
        }
        ptr += (((filesize + 511) / 512) + 1) * 512;
    }
    return filesize;
}

bool getfiledata(char *filename, void **start, void **end, uint8_t size){
  void *scanptr = initrd_start;
	tar_header_t *scan = (tar_header_t*)scanptr;
  
  while((uin8_t)scan < _binary_ahntri_initrd_kerneldisk_end){
		uint8_t lenofthefilename = strlen((char *)scan->filename);
    uint8_t lenoffilename = strlen(filename);
    //If the length of the filename givn is smaller than the length of the file name in it make it equal.
		if (lenoffilename < lenofthefilename){
			lenofthefilename = lenoffilename;
    }
    //When filename matched
		if (memcmp(scan->filename, filename, lenofthefilename) == 0){																	//Is filename.Data() filename?
      return true;
    }
    uint8_t fsize				= OctalToUseful(scan->fileSize, USTAR_FILESIZE_LENGTH - 1);
    uint8_t remainder		= USTAR_SECTOR_SIZE - (fileSize % USTAR_SECTOR_SIZE);
    if (remainder == USTAR_SECTOR_SIZE){
      remainder = 0;
    }
    scanptr += USTAR_SECTOR_SIZE + fileSize + remainder;
    scan = (tar_header_t*)scanptr;
  }
  *start = *end = size = NULL;
  return false;
}

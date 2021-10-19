//------------------------------
#define FILE_NAME_LEN 100
#define OWNER_NUMERIC_ID 8
#define GROUP_NUMERIC_ID 8
#define FILESIZE_LEN 12
#define SECTOR_SIZE 512
#define OWNER_USER_NAME_SIZE 32
#define OWNER_GROUP_NAME_SIZE 32
//-------------------------------

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


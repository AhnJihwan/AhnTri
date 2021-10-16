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

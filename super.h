#ifndef SUPER_H
#define SUPER_H

#include <linux/fs.h>

/* Testfs superblock read from disk */
struct testfs_superblock {
	__le32 magic;		/* Magic number */
	__le32 block_size;	/* Block size */
	__le32 block_count;	/* Number of blocks. Max is 32768 blocks */
	__le32 itable;		/* Block number of inode table */
	__le32 itable_size;	/* Size in blocks of inode table */
	__le32 block_bitmap;	/* Location of block usage bitmap */
	__le32 inode_bitmap;	/* Location of inode bitmap */
	__le32 rootdir_inode;	/* Inode number of the root directory */
};

/* Testfs in-memory structure */
struct testfs_info {
	struct testfs_superblock *sb;	/* Pointer to on disk structure */
	struct buffer_head *bh;		/* Pointer to sb buffer head */
	struct inode *root;		/* Root directory inode */
	char *block_bitmap;		/* Pointer to on disk block bitmap */
	char *inode_bitmap;		/* Pointer to on disk inode bitmap */
};

struct dentry *super_mount(struct file_system_type *fs_type,
	int flags, const char *dev_name, void *data);
	
	
#endif /* SUPER_H */

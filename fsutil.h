#ifndef FSUTIL_H
#define FSUTIL_H
/*
 * List files and directories within a directory.
 */
char* list_directory (const char *dirname);

/*
 * Scan files and directories within a directory.
 */
void scan_directory (const char *dirname);

/*
 * Find files and subdirectories recursively
 */
int find_directory (const char *dirname);

/*
 * Return size of input file name
 */
int file_size(const char *file_name);

void removeDir(const char *path);


#endif // FSUTIL_H

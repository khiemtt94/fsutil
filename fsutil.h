#ifndef FSUTIL_H
#define FSUTIL_H
/*
 * List files and directories within a directory.
 */
void list_directory (const char *dirname);

/*
 * Scan files and directories within a directory.
 */
void scan_directory (const char *dirname);

/*
 * Find files and subdirectories recursively
 */
int find_directory (const char *dirname);

long file_size(const char *file_name);


#endif // FSUTIL_H

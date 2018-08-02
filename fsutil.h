#ifndef FSUTIL_H
#define FSUTIL_H


/*
 * List files and directories within a directory.
 */
static void list_directory (const char *dirname);

/*
 * Scan files and directories within a directory.
 */
static void scan_directory (const char *dirname);

/*
 * Find files and subdirectories recursively
 */
static int find_directory (const char *dirname);




#endif // FSUTIL_H

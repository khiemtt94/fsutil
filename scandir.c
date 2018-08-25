/*
 * Example program demonstrating the use of scandir function.
 *
 * Compile this file with Visual Studio and run the produced command in
 * console with a directory name argument.  For example, command
 *
 *     scandir "c:\Program Files"
 *
 * might output something like
 *
 *     ./
 *     ../
 *     7-Zip/
 *     Internet Explorer/
 *     Microsoft Visual Studio 9.0/
 *     Microsoft.NET/
 *     Mozilla Firefox/
 *
 * Copyright (C) 2006-2012 Toni Ronkko
 * This file is part of dirent.  Dirent may be freely distributed
 * under the MIT license.  For all details and documentation, see
 * https://github.com/tronkko/dirent
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "fsutil.h"




void scan_directory(const char *dirname)
{
    struct dirent **files;
    int i;
    int n;

    /* Scan files in directory */
    n = scandir (dirname, &files, NULL, alphasort);
    if (n >= 0) {

        /* Loop through file names */
        for (i = 0; i < n; i++) {
            struct dirent *ent;

            /* Get pointer to file entry */
            ent = files[i];

            /* Output file name */
            switch (ent->d_type) {
            case DT_REG:
                printf ("%s\n", ent->d_name);
                break;

            case DT_DIR:
                printf ("%s/\n", ent->d_name);
                break;

            case DT_LNK:
                printf ("%s@\n", ent->d_name);
                break;

            default:
                printf ("%s*\n", ent->d_name);
            }

        }

        /* Release file names */
        for (i = 0; i < n; i++) {
            free (files[i]);
        }
        free (files);

    } else {
        printf ("Cannot open directory %s\n", dirname);
    }
}



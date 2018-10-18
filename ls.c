/*
 * An example demonstrating basic directory listing.
 *
 * Compile this file with Visual Studio and run the produced command in
 * console with a directory name argument.  For example, command
 *
 *     ls "c:\Program Files"
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
 * The ls command provided by this file is only an example: the command does
 * not have any fancy options like "ls -al" in Linux and the command does not
 * support file name matching like "ls *.c".
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
#include "uart.h"

char* list_directory( const char *dirname) {
    DIR *dir;
    char* buffer = (char *) malloc(10000);
    struct dirent *ent;

    /* Open directory stream */
    dir = opendir (dirname);
    if (dir != NULL) {

        /* Print all files and directories within the directory */
        while ((ent = readdir (dir)) != NULL) {
            switch (ent->d_type) {
            case DT_REG:
                strcat(buffer,ent->d_name);
                strcat(buffer,"\r\n");
                break;

            case DT_DIR:
                strcat(buffer,"/");
                strcat(buffer,ent->d_name);
                strcat(buffer,"\r\n");
                break;

            case DT_LNK:
                strcat(buffer,"@");
                strcat(buffer,ent->d_name);
                strcat(buffer,"\r\n");
                break;

            default:
                strcat(buffer,"*");
                strcat(buffer,ent->d_name);
                strcat(buffer,"\r\n");


            }
        }

        closedir (dir);
        return buffer;

    } else {
        /* Could not open directory */
        printf ("Cannot open directory %s\n", dirname);
        //        exit (EXIT_FAILURE);
        closedir (dir);
    }
}


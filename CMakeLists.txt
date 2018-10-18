cmake_minimum_required(VERSION 2.8)

project(fsutil)

add_library(${PROJECT_NAME} SHARED "find.c" "scandir.c" "ls.c" "filesize.c" "remove.c")

set(HEADERS fsutil.h)

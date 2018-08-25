#include <sys/types.h>
#include <sys/stat.h>
#include "fsutil.h"

long file_size(const char *file_name) {
  struct stat fileStat;
  int err = stat( file_name, &fileStat );
  if (0 != err) return 0;
  return fileStat.st_size;
}

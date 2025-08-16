#include "hb_semjson.h"
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

// ensure directory exists (simple)
static void hb_semjson_mkdirs(const char *path)
{
    char buf[1024];
    strncpy(buf, path, sizeof(buf));
    buf[sizeof(buf) - 1] = '\0';

    char *p = strrchr(buf, '/');
    if (p)
    {
        *p = '\0';
        mkdir(buf, 0777); // POSIX, no recursion
    }
}

int hb_semjson_write_file(const char *path, const char *content)
{
    hb_semjson_mkdirs(path);
    FILE *f = fopen(path, "w");
    if (!f)
        return 0;
    fputs(content, f);
    fclose(f);
    return 1;
}

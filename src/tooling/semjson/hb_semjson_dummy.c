// runnable smoke test
#include "hb_semjson.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv; // ignore args for now
    hb_semjson_write_file(".harboursems/project.json",
                          "{ \"kind\": \"dummy\", \"ok\": true }\n");
    printf("Wrote dummy .harboursems/project.json\n");
    return 0;
}

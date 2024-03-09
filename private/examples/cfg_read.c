#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

int main(int argc, char* argv[]) {

    config_t cfg;
    const char *file, *path;

    config_init(&cfg);

    if(!config_read_file(&cfg, "config/test.cfg")) {
        fprintf(stderr, "Error reading file.\n");
        config_destroy(&cfg);
        return(EXIT_FAILURE);
    }

    if(!config_lookup_string(&cfg, "file", &file) || !config_lookup_string(&cfg, "path", &path)) {
        fprintf(stderr, "Could not find %s\n", file);
        return(EXIT_FAILURE);
    }

    printf("%s\n", file);
    printf("%s\n", path);

    config_destroy(&cfg);

    return 0;
}

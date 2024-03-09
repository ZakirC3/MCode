#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

int main() {
    config_t cfg;
    config_setting_t *setting;
    const char *new_path = "/usr/bin";

    config_init(&cfg);

    if(!config_read_file(&cfg, "config/test.cfg")) {
        fprintf(stderr, "Error reading configuration file.\n");
        config_destroy(&cfg);
        return(EXIT_FAILURE);
    }

    setting = config_lookup(&cfg, "path");

    if(setting == NULL) {
        fprintf(stderr, "Error setting configuration file.\n");
        config_destroy(&cfg);
        return(EXIT_FAILURE);
    }

    config_setting_set_string(setting, new_path);

    if(!config_write_file(&cfg, "config/test.cfg")) {
        fprintf(stderr, "Error writing configuration file.\n");
        config_destroy(&cfg);
        return(EXIT_FAILURE);
    }

    config_destroy(&cfg);

    return 0;
}

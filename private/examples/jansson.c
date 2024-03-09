#include <stdio.h>
#include <jansson.h>

int main(int argc, char **argv) {

	json_t *root, *dat, *extensions, *value;
	json_error_t err;
	size_t index;

	root = json_load_file("/home/zakir/Documents/Code/assets/json/test.json", 0, &err);
	NotError(root, "root failed");

	// variables
	dat = json_object_get(root, "dat");
	const char *var = json_string_value(dat);

	// array
	extensions = json_object_get(root, "file-extensions");
	value = json_array_get(extensions, 0);

    const char *extension = json_string_value(value);
    printf("First Extension: %s\n", extension);

	json_decref(root);

    return 0;
}

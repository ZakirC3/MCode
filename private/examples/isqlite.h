#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef char* sqlerr;

typedef struct {
    sqlite3 *conn;
    char *path;
    int rc;
    sqlerr err;
    char *query;
} imysqlite;

imysqlite imysqlite_all(char *path, char *query, int (*callback)(imysqlite *)) {
    imysqlite ret = {
        .conn = NULL,
        .path = path,
        .rc = sqlite3_open(path, &ret.conn),
        .err = NULL,
        .query = query
    };

    if(ret.rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(ret.conn));
        sqlite3_close(ret.conn);
        exit(1);
    }

    callback(&ret);

    sqlite3_close(ret.conn);

    return ret;
}
/*

static int callback(void *data, int argc, char **argv, char **azColName){

    company *info = (company *)data;

    if (argv[1] != NULL) {
        strncpy(info->name, argv[1], 99);
        info->name[99] = '\0';
    }

    return 0;
}

int imysqlite_exec(imysqlite *i) {
    info.name = malloc(100 * sizeof(char));

    i->rc = sqlite3_exec(i->conn, i->query, callback, (void *)&info, &i->err);

    if(i->rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", i->err);
        sqlite3_free(i->err);
        return 1;
    }

    return 0;
}

*/
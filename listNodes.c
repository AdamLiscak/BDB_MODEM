#include <stdio.h>
#include <string.h>
#include <db.h>
#include "networkNode.h"

int main()
{
    DBT key, data;
    DBC *cursor;
    DB *dbp;
    int err;
    networkNode netNode;

    err = db_create(&dbp, NULL, 0);
    if (err)
    {
        perror("db_create(): ");
    }
    else
    {
        err = dbp->open(dbp, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
        if (err)
        {
            perror("dbp->open(): ");
        }
        else
        {
            err = dbp->cursor(dbp, NULL, &cursor, 0);
            if (err)
            {
                perror("dbp->cursor(): ");
            }
            else
            {
                memset(&key, 0, sizeof(DBT));
                memset(&data, 0, sizeof(DBT));

                while (!(err = cursor->c_get(cursor, &key, &data, DB_NEXT)))
                {
                    memcpy(&netNode, data.data, sizeof(netNode));
                    printf("%d - %s,%s\n", netNode.id, netNode.name, netNode.mac_addr);
                }

                cursor->c_close(cursor);
            }

            dbp->close(dbp, 0);
        }
    }
    return err;
}

#include <stdio.h>
#include <string.h>
#include <db.h>
#include "networkNode.h"

int main()
{
   DBT key;
   DB *dbp;
   int ret;
   networkNode netNode;

   ret = db_create(&dbp, NULL, 0);
   if (ret != 0)
   {
      perror("create");
      return 1;
   }

   ret = dbp->open(dbp, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
   if (ret != 0)
   {
      perror("open: ");
      return 1;
   }

      netNode.id=3;
      memset(&key, 0, sizeof(DBT));
      key.data = &(netNode.id);
      key.size = sizeof(netNode.id);

      ret = dbp->del(dbp, NULL, &key, 0);
      if (ret != 0)
      {
         printf("Iface non existent\n");
      } else
      {
         printf("  Iface deleted.\n");
      }

   dbp->close(dbp, 0);
   return 0;
}

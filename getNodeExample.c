#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <db.h>

#include "networkNode.h"

int main()
{
   DBT key, data;
   DB *db; // DB handle
   int ret;
   networkNode netNode;

   // Initialize our DB handle
   ret = db_create(&db, NULL, 0);
   if (ret != 0)
   {
      fprintf(stderr, "Failed to initialize the database handle: %s\n", db_strerror(ret));
      return 1;
   }

   // Open the existing DATABASE file in read-only mode. If it doesn't exist, report an error message.
   ret = db->open(db, NULL, DATABASE, NULL, DB_BTREE, DB_RDONLY, 0);
   if (ret != 0)
   {
      fprintf(stderr, "Failed to open database file %s: %s\n", DATABASE, db_strerror(ret));
      return 1;
   }


      netNode.id=2;
      memset(&key, 0, sizeof(DBT));
      memset(&data, 0, sizeof(DBT));
      key.data = &(netNode.id);
      key.size = sizeof(netNode.id);
      data.data = &netNode;
      data.ulen = sizeof(netNode);
      data.flags = DB_DBT_USERMEM;
      ret = db->get(db, NULL, &key, &data, 0);
      if (ret != 0)
      {
         printf("Iface non Existent\n");
      } else
      {
         printf("  Netnode: %d - %s,%s\n", netNode.id, netNode.name, netNode.mac_addr);
      }

   db->close(db, 0);
   return 0;
}

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

   // Open the existing DATABASE file or create a new one if it doesn't exist.
   ret = db->open(db, NULL, DATABASE, NULL, DB_BTREE, DB_CREATE, 0);
   if (ret != 0)
   {
      fprintf(stderr, "Failed to open database file %s: %s\n", DATABASE, db_strerror(ret));
      return 1;
   }

   while(1)
   {
      printf("Enter ID: ");
      scanf("%d", &netNode.id);
      if (netNode.id == 0)
         break;
      printf("Enter name: ");
      scanf("%s", &netNode.name);
      printf("Enter mac adddress: ");
      scanf("%s", &netNode.mac_addr);
      memset(&key, 0, sizeof(DBT));
      memset(&data, 0, sizeof(DBT));

      key.data = &(netNode.id);
      key.size = sizeof(netNode.id);
      data.data = &netNode;
      data.size = sizeof(netNode);

      ret = db->put(db, NULL, &key, &data, DB_NOOVERWRITE);
      if (ret != 0)
      {
         printf("Node exists\n");
      }
   }

   db->close(db, 0);
   return 0;
}

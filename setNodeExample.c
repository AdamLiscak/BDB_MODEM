#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <db.h>
#include <string.h>
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
    printf("Created linked list\n"); 
       netNode.id=50;
       strcpy(netNode.tags,"Blacklisted:0,WPS:0,DataTransferred:23345,Type:Ntb"); 
	strcpy(netNode.name,"Lenovo-U310");
	strcpy(netNode.mac_addr,"kj:88939:2");
      memset(&key, 0, sizeof(DBT));
      memset(&data, 0, sizeof(DBT)); 	
      key.data = &(netNode.id);
      key.size = sizeof(netNode.id);
      data.data = &netNode;
      data.size = sizeof(netNode);

      ret = db->put(db, NULL, &key, &data, DB_NOOVERWRITE);
      if (ret != 0)
      {
         printf("Diese ID existiert schon\n");
      }

   db->close(db, 0);
   return 0;
}

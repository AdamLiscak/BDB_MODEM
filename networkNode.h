#pragma once
#define DATABASE "network.db"
typedef struct
{
int id;
char mac_addr[12];
char name[30];
char tags[255];
} networkNode;
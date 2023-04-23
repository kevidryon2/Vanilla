#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "raylib.h"

#pragma once
#define NUM_ASSETS 3

Texture pictrelLogo;
Texture vanillaLogo;

struct {
  void *dest;
  enum {
    TYPE_TEXT,
    TYPE_PNG_TEXTURE,
    TYPE_FONT
  } type;
} assetdata[] = {
    {0, TYPE_TEXT},
    {&pictrelLogo, TYPE_PNG_TEXTURE},
    {&vanillaLogo, TYPE_PNG_TEXTURE},
  
};

void loadAsset(int n, FILE *fp) {
  printf("\nLoading asset %d\n", n);
  fseek(fp, 4, SEEK_SET);
  unsigned char *data;
  unsigned char *cdata = malloc(1); //dummy
  unsigned int cdlen;
  unsigned int dlen;
  for (int i=0; i<=n; i++) {
    free(cdata);
    if (i == n) printf("Reading compressed data length\n");
    fread(&cdlen, sizeof(int), 1, fp);
    if (i == n) printf("Allocating space for compressed data (size: %08x)\n", cdlen);
    cdata = malloc(cdlen);
    if (i == n) printf("Reading compressed data\n");
    fread(cdata, cdlen, 1, fp);
    if (i == n) printf("Decompressing data\n");
    data = DecompressData(cdata, cdlen, &dlen);
    if (i == n) printf("Decompressed data\n");
  }
  if (assetdata[n].dest) {
    switch (assetdata[n].type) {
      case TYPE_PNG_TEXTURE:
        *(Texture*)assetdata[n].dest = LoadTextureFromImage(LoadImageFromMemory(".png", data, dlen));
        break;
    }
  }
  /*for (int i=0; i<dlen; i++) {
    if (!(i%12)) puts("");
    printf("%02x ", (unsigned)data[i]);
  }*/
  
}

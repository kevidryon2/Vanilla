#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "raylib.h"

#pragma once
#define NUM_ASSETS 12

Texture pictrelLogo;
Texture vanillaLogo;

Font mono_bold;
Font mono_italic;
Font mono_light;
Font mono_medium;
Font mono_regular;

Font normal_bold;
Font normal_italic;
Font normal_light;
Font normal_regular;

struct {
  void *dest;
  enum {
    TYPE_TEXT,
    TYPE_PNG_TEXTURE,
    TYPE_TTF_FONT
  } type;
} assetdata[] = {
    {&pictrelLogo, TYPE_PNG_TEXTURE},
    {&mono_bold, TYPE_TTF_FONT},
    {&mono_italic, TYPE_TTF_FONT},
    {&mono_light, TYPE_TTF_FONT},
    {&mono_medium, TYPE_TTF_FONT},
    {&mono_regular, TYPE_TTF_FONT},
  
    {&normal_bold, TYPE_TTF_FONT},
    {&normal_italic, TYPE_TTF_FONT},
    {&normal_light, TYPE_TTF_FONT},
    {&normal_regular, TYPE_TTF_FONT},
    {&vanillaLogo, TYPE_PNG_TEXTURE},
    {NULL, TYPE_TEXT}
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
      case TYPE_TTF_FONT:
        *(Font*)assetdata[n].dest = LoadFontFromMemory(".ttf", data, dlen, 100, 0, 200);
        break;
    }
  }
  /*for (int i=0; i<dlen; i++) {
    if (!(i%12)) puts("");
    printf("%02x ", (unsigned)data[i]);
  }*/
  
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_image_write.h"
#include "stb_truetype.h"

#define error(msg) do { fprintf(stderr, msg "\n"); return 1; } while(0);
#define crash(msg) do { fprintf(stderr, msg "\n"); exit(1); } while(0);

typedef unsigned char *byte;

unsigned char *read_whole_file(const char *fname) {
    FILE *f;
    long size;
    unsigned char *buf;
    
    f = fopen(fname, "rb");
    if(!f) 
        crash("couldn't open file");
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    buf = malloc(size);
    if(!buf)
        crash("couldn't allocate buffer");
    fread(buf, size, 1, f);
    fclose(f);

    return buf;
}

char ttf_buffer[1<<25];

int main(int argc, char **argv)
{
   stbtt_fontinfo font;
   unsigned char *bitmap;
   int width, height;
   int character = 'a'; 
   int s = 32;

   fread(ttf_buffer, 1, 1<<25, fopen("../fonts/pokemon_fire_red.ttf", "rb"));

   stbtt_InitFont(&font, ttf_buffer, stbtt_GetFontOffsetForIndex(ttf_buffer,0));
   float scale = stbtt_ScaleForPixelHeight(&font, s);
   bitmap = stbtt_GetCodepointBitmap(&font, 0.f , scale, character, &width, &height, 0,0);

   stbi_write_png("output2.png", width, height, 1, bitmap, width);

   for (int y = 0; y < height; ++y) {
      for (int x = 0; x < width; ++x)
         putchar(" .:ioVM@"[bitmap[y * width + x]>>5]);
      putchar('\n');
   }
   return 0;
}
/*
int main(int argc, char **argv) {
    if(argc != 4)
        error("usage: <cmd> inp_tff_file out_png_file size");
    printf("-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    const char *input = argv[1];
    const char *output = argv[2];
    int height = atoi(argv[3]);

    unsigned char *fontbuf = read_whole_file(input);
    
    stbtt_fontinfo info;
    if(!stbtt_InitFont(&info, fontbuf, 0))
        error("couldn't initialize font");

    float scale = stbtt_ScaleForPixelHeight(&info, 16);
    printf("height: %f\n", scale);

    int ww, hh, xo, yo;
    byte d = stbtt_GetCodepointBitmap(&info, scale, scale, 'a', &ww, &hh, &xo, &yo);
    printf("%d %d %d %d\n", ww, hh, xo, yo);

    int ow = 500;
    int oh = 500;
    byte bitmap = calloc(ow * oh, sizeof(unsigned char));

    stbtt_MakeCodepointBitmap(&info, bitmap, ow, oh, 0, scale, scale, 'a');

    stbi_write_png(output, ow, oh, 1, bitmap, ow);
    free(fontbuf);
    free(bitmap);
    */

    /*
    int bw = 512; // bitmap width
    int bh = 512; // bitmap height
    int lh = 32;  // line height

    unsigned char *bitmap = calloc(bw * bh, sizeof(unsigned char));
    float scale = stbtt_ScaleForPixelHeight(&info, lh);
    printf("scale: %f\n", scale);

    char *word = "the quick brown fox";
    int x = 0;
    int ascent, descent, linegap;
    stbtt_GetFontVMetrics(&info, &ascent, &descent, &linegap);

    ascent = roundf(ascent * scale);
    descent = roundf(descent * scale);

    int len = strlen(word);
    for(int i=0; i<len; i++) {
        int ax, lsb;
        stbtt_GetCodepointHMetrics(&info, word[i], &ax, &lsb);

        int cx1, cy1, cx2, cy2;
        stbtt_GetCodepointBitmapBox(&info, word[i], scale, scale, &cx1, &cy1, &cx2, &cy2);

        int y = ascent + cy1;
        int byte_offset = x + roundf(lsb  * scale) + (y * bw);
        stbtt_MakeCodepointBitmap(&info, bitmap + byte_offset, cx2 - cx1, cy2 - cy1, bw, scale, scale, word[i]);

        x += roundf(ax * scale);

        int kern;
        kern = stbtt_GetCodepointKernAdvance(&info, word[i], word[i + 1]);
        x += roundf(kern * scale);
    }

    stbi_write_png(output, bw, bh, 1, bitmap, bw);
   
    free(fontbuf);
    free(bitmap);
    */
   /*
}
*/
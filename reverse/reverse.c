#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if(argc!=3){
        printf("Usage:two filename\n");
        return 1;
    }
    FILE *in=fopen(argv[1],"rb");
    if(in==NULL){
        printf("wrong file\n");
        return 1;
    }
    WAVHEADER buffer;
    fread(&buffer,sizeof(WAVHEADER),1,in);
    if(check_format(buffer)==0){
        printf("INPUT IS NOT A WAV");
            return 1;
    }
    FILE *out=fopen(argv[2],"wb");
    fwrite(&buffer,sizeof(WAVHEADER),1,out);
    int block_size=get_block_size(buffer);
    BYTE block[block_size];
    for(long i=buffer.subchunk2Size-block_size;i>=0;i-=block_size){
        fseek(in,sizeof(WAVHEADER)+i,SEEK_SET);
        fread(block,block_size,1,in);
        fwrite(block,block_size,1,out);
    }
    fclose(in);
    fclose(out);
    return 0;
}

int check_format(WAVHEADER header)
{
    if(memcmp(header.format,"WAVE",4)!=0){
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels *(header.bitsPerSample/8);
}

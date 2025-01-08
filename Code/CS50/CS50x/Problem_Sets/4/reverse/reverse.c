#include <stdint.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>
#include <stdbool.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("You are bad\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile = *(argv[optind~])

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", &infile);
        return 4;
    }

    // Read header
    // TODO #3
    WAVHEADER wavHeader;
    fread(&wavHeader, sizeof(WAVHEADER), 1, inptr);
    long fvalue = ftell(inptr);

    printf("fvalue is: %li\n", fvalue);

    // Use check_format to ensure WAV format
    // TODO #4
    /*
    if(!check_format(wavHeader))
    {
        printf("Not a WAV file.\n");
        return 1;
    }
    */

    // Open output file for writing
    // TODO #5
    char outfile = *(argv[optind + 1]);
    FILE *outptr = fopen(&outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not open %s.\n", &outfile);
        return 4;
    }

    // Write header to file
    // TODO #6
    fwrite(&wavHeader, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int size = get_block_size(wavHeader);

    // TODO #8
    // Write reversed audio to file
    // Scan the data in backwards using pointers
    // write to an array, reading wave file array backwards
    // copy array to fwrite ouput file

    // read in each block of auditory data
    // starting from the very end of the input file moving backwards
    // Simultaneously writing each block to the output file so they are written in reverse order

    // Declare an array to store each block we read in.
    // Iterate through the input file audio data.
    // maintain the order of the channels

    // fseek: sets a file pointer to a given offset.  negative offset values to move a file pointer backwards.
    // ftell: returns the current position of a file pointer
    BYTE blockArray[size];

    // byte* myptr = NULL
    // fseek()  - blockArray, size * sizeof(BYTE);
    // FILE* fp; fp = fopen("test.txt", "r"); // inptr

    // Moving pointer to end
    if(fseek(inptr, size, SEEK_END))// if (fseek(inptr, dataBlockSize, SEEK_END))
    {
        fclose(inptr);
        fclose(outptr);
        return 1;
    }

    while ( (ftell(inptr) - size) >  sizeof(WAVHEADER) )
    {
        // Move back 2 blocks at a time - saving the current position with seek curr
        if (fseek(inptr, -2 * size, SEEK_CUR))
        {
            fclose(inptr);
            fclose(outptr);
            return 1;
        }

        // read the data backwards into the buffer, 2xblock size - (1) at a time, from input file
        // write the data forwards into the buffer
        fread(blockArray, size, 1, inptr);
        fwrite(blockArray, size, 1, outptr);
    }

    // infile + outfile close
    fclose(inptr);
    fclose(outptr);

}

int check_format(WAVHEADER header)
{
    bool isWavHeader = true;
    int subChunk2Size = round((double)header.sampleRate * (double)header.numChannels * (double)(header.bitsPerSample / 8.0));
    int ChunkSize = 36 + header.subchunk2Size;

    // ChunkID = 0x52494646 "RIFF"
    if(!(strcmp("RIFF", (char*)header.chunkID) == 0))
    {
        isWavHeader = false;
    }

    if( (ChunkSize != header.chunkSize) || (subChunk2Size != header.subchunk2Size) )
    {
        isWavHeader = false;
    }

     if( !(strcmp("WAVE", (char*)header.format) == 0) )
    {
        isWavHeader = false;
    }

    return isWavHeader;
}

int get_block_size(WAVHEADER header)
{
    int blockSize = 0;

    blockSize = header.subchunk2Size;

    return blockSize;
}
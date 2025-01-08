#include <stdint.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{

    // TODO #1
    // Ensure proper usage
    if (argc != optind + 2)
    {
        printf("Improper Usage.  Please submit two valid command line arguments.\n");
        return 1;
    }

    // TODO #2
    // Open input file for reading
    // Remember filenames
    char *infile = *(argv[optn + 1]);
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }
    // TODO #3
    // Read the header from the input file - use WAVHEADER struct
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, inptr);

    // TODO #4
    // Complete the check_format function
    // Check if a file is of the WAV format
    // Compare the elements from the input file header to those we would expect from a WAV file
    // WAVE marker characters are found in the format member
    //bool bIsWavFormat = ;

    if (check_format(wh) == 0)
    {
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    char *outfile = argv[optind + 1];
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fclose(outptr);
        printf("Could not create %s.\n", outfile);
        return 1;
    }

    // Write the header to the output file.
    // Copy the header we read in from the input file
    // TODO #6
    fwrite(&wh, sizeof(WAVHEADER), 1, outptr);

    // Get Audio Data's block size
    // Subchunk2Size == SampleRate * NumChannels * BitsPerSample/8
    // SampleRate is 8000, 44100, etc.
    // TODO #7
    int dataBlockSize = 0;
    dataBlockSize = get_block_size(wh);

    // TODO #8
    // Read in each block of auditory data starting from the very end of the input file and moving backwards
    // Simultaneously writing each block to the output file so they are written in reverse order
    // Declare an array to store each block we read in - Iterate through the input file audio data

    BYTE buffer[dataBlockSize];

    // Set the pointer to where we are going to start reading file - find last pointer
    if (fseek(inptr, dataBlockSize, SEEK_END))
    {
        fclose(inptr);
        fclose(outptr);
        return 1;
    }

    // Header is 44 Byes long
    // Continue reading file backwards until the pointer reaches the start, then exit loop
    while ( (ftell(inptr) - dataBlockSize) >  sizeof(wh) )
    {
        // Move back 2 blocks at a time - saving the current position with seek curr
        if (fseek(inptr, -2 * dataBlockSize, SEEK_CUR))
        {
            fclose(inptr);
            fclose(outptr);
            return 1;
        }

        // read the data backwards into the buffer, 2xblock size - (1) at a time, from input file
        // write the data forwards into the buffer
        fread(buffer, dataBlockSize, 1, inptr);
        fwrite(buffer, dataBlockSize, 1, outptr);
    }

    // infile + outfile close
    fclose(inptr);
    fclose(outptr);
    return 0;
}



int check_format(WAVHEADER header)
{
    if (strstr((char *)header.format, "WAVE") != NULL || strstr((char *)header.chunkID, "RIFF") != NULL ||
        header.chunkSize != 36 + header.subchunk2Size || strstr((char *)header.subchunk1ID, "fmt") != NULL ||
        strstr((char *)header.subchunk2ID, "data") != NULL)
    {
        return 1;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    int subChunkTwoSize = 0;
    subChunkTwoSize = header.numChannels * (header.bitsPerSample / 8);
    /*
    DWORD sampleRate = header.sampleRate;
    WORD channels = header.numChannels;
    WORD bitsPerSample = header.bitsPerSample/8;
    subChunkTwoSize = sampleRate * channels * bitsPerSample;
    */

    return subChunkTwoSize;
}

/*
Read in each block of auditory data starting from the very end of the input file and moving backwards
Simultaneously writing each block to the output file so they are written in reverse order
Declare an array to store each block we read in - Iterate through the input file audio data - don't copy header info
copy array in reverse order
Maintain the order of the channels for each audio block

fread: reads from a file to a buffer
fwrite: writes from a buffer to a file.
fseek: sets a file pointer to a given offset
ftell: returns the current position of a file pointer

fseek(inptr, 0, SEEK_END);
int size = ftell(inptr) - sizeof(WAVHEADER);

int audioBlockSize = (int)size / dataBlockSize;

Iterate through the input file audio data
for (int i = audioBlockSize - 1; i >= 0; i--)
{
    // Starting From End of the File (Block by Block Transferring)
    fseek(inptr, sizeof(WAVHEADER) + i * dataBlockSize, SEEK_SET);
    fread(buffer, dataBlockSize, 1, inptr);
    fwrite(buffer, dataBlockSize, 1, outptr);
}

BYTE buffer[dataBlockSize];

Move Pointer to the End
fseek(inptr, 0, SEEK_END);

Buffer Size
long audio_size = ftell(inptr) - sizeof(WAVHEADER);
int audio_block = (int) audio_size / dataBlockSize;

Iterate through the input file audio data
Maintain the order of the channels for each audio block (Reversed)
for (int i = audio_block - 1; i >= 0; i--)
{
    BYTE *value = NULL;
    // Starting From End of the File (Block by Block Transferring)
    fseek(inptr, sizeof(WAVHEADER) + i * dataBlockSize, SEEK_SET);
    fread(buffer, dataBlockSize, 1, inptr);
    fwrite(buffer, dataBlockSize, 1, outptr);
    //buffer[i] = *value;
}
*/
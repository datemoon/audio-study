
#include <stdio.h>
#include <stdlib.h>
#include "opusdec_api.h"

int main(int argc, char *argv[])
{
	//struct OggOpusDec ogg_opus_dec;
	void *handle = CreateOpusDec();
	char *inFile = argv[1];
	char *outFile = argv[2];
	// init
	InitOggOpusDec(handle, outFile);
	FILE *fout = fopen("abc","wb");
	FILE *fin = fopen(inFile,"rb");
	/*Main decoding loop*/
	int npkg = 0;
	while(1)
	{
		char data[200];
		int outdata_len;
		int nb_read = fread(data, sizeof(char), 200, fin);
		char *outdata = NULL;
		if(nb_read == 0)
		{
			printf("----------read end -----");
			break;
		}
		int ret = ProcessDec(handle,
				data, nb_read, &outdata, &outdata_len);
		if(outdata_len > 0)	
			fwrite(outdata, sizeof(char), outdata_len, fout);
		if (outdata != NULL)
		{
			free(outdata);
		}
		printf("%d: output len %d\n",npkg, outdata_len);
		npkg++;
		if(ret == 1)
		{
			printf("--------convert end--------");
			break;
		}
	}

	DestoryOggOpusDec(handle);
	fclose(fin);
	fclose(fout);

	return 0;
}

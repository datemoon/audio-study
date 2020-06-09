#ifndef __OPUSDEC_API_H__
#define __OPUSDEC_API_H__

#ifdef   __cplusplus
extern   "C"
{
#endif


void *CreateOpusDec();


void InitOggOpusDec(void * dec_handle, char *outfile);


/*
 * parametet:
 *  ogg_opus_dec : ogg opus dec point
 *  in_data      : input data point
 *  in_data_len  : input data length
 *  out_data     : output data point , need free .
 *  out_data_len : output data length
 *
 * return   :  end flag 1 is end.
 * */
int ProcessDec(void * dec_handle, char *in_data, int in_data_len, char **out_data, int *out_data_len);


void DestoryOggOpusDec(void * dec_handle);
#ifdef   __cplusplus
}
#endif

#endif

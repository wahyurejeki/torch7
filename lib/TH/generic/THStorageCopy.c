#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THStorageCopy.c"
#else
#include <stdio.h>

void THStorage_(rawCopy)(THStorage *storage, real *src)
{
  long i;
  if( THStorage_traceOn) printf("THStorage_(rawCopy)\n");
  for(i = 0; i < storage->size; i++)
    storage->data[i] = src[i];
}

void THStorage_(copy)(THStorage *storage, THStorage *src)
{
  if( THStorage_traceOn) printf("THStorage_(copy)\n");
  THArgCheck(storage->size == src->size, 2, "size mismatch");
  THStorage_(rawCopy)(storage, src->data);
}


#define IMPLEMENT_THStorage_COPY(TYPENAMESRC) \
void THStorage_(copy##TYPENAMESRC)(THStorage *storage, TH##TYPENAMESRC##Storage *src) \
{ \
  long i; \
  THArgCheck(storage->size == src->size, 2, "size mismatch"); \
  for(i = 0; i < storage->size; i++) \
    storage->data[i] = (real)src->data[i]; \
}

IMPLEMENT_THStorage_COPY(Byte)
IMPLEMENT_THStorage_COPY(Char)
IMPLEMENT_THStorage_COPY(Short)
IMPLEMENT_THStorage_COPY(Int)
IMPLEMENT_THStorage_COPY(Long)
IMPLEMENT_THStorage_COPY(Float)
IMPLEMENT_THStorage_COPY(Double)

#endif

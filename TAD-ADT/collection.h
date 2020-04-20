#ifndef collection_h
#define collection_h

typedef struct _collection_ Col;

//there are 10 functions for this collection.
#ifdef collection_c
	int cmp(void* a, void* b);
	Col* colCreate(int n);
	int colInsert(Col* c, void* elm);
	void* colQuery(Col* c, void* key, int (*cmp)(void*,void*));
	void* colGetFirst(Col* c);
	void* colGetNext(Col* c);
	void* colRemoveLast(Col* c);
	void* colRemoveFirst(Col* c);
	void* colRemoveSpec(Col* c, void* key, int (*cmp)(void*,void*));
	int colDestroy(Col* c);

#else
	int cmp(void* a, void* b);
	extern Col* colCreate(int n);
	extern int colInsert(Col* c, void* elm);
	extern void* colQuery(Col* c, void* key, int (*cmp)(void*,void*));
	extern void* colGetFirst(Col* c);
	extern void* colGetNext(Col* c);
	extern void* colRemoveLast(Col* c);
	extern void* colRemoveFirst(Col* c);
	extern void* colRemoveSpec(Col* c, void* key, int (*cmp)(void*,void*));
	extern int colDestroy(Col* c);
#endif
#endif
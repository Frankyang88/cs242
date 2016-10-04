
typedef struct htablerec *htable;

extern htable htable_new(int size);
extern void htable_insert(htable h, char *str);
extern void htable_free(htable h);
extern void htable_print(htable h,FILE* stream);

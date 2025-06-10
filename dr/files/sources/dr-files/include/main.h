#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>
#include<sys/stat.h>
/* REQUIRED MARCOS */
//#define MAXLINE 1000

/* DR Module 1 functions */
void hello();
void fahr_cel();
void cel_fahr(float cel);
void cel_fahr1();
void verify_getchar();
void verify_EOF();
void cnt_all();
void rm_spaces();
void visible();
void cnt_word();
void print_word();
void histogram_hor();
void histogram_f();
int valid_input();
int my_getline(int8_t *s, int32_t lim);
void copy(int8_t to[], int8_t from[]);
void longest();
void get_strbyline(int8_t line[][1000],int32_t i_row,int32_t len[]);
void manual_copy(int8_t *dest, int8_t *src, int32_t max_size);
void limit();
void remove_check();
void remove_trail_blanks(int8_t line[],int32_t l);
void reverse(int8_t line[], int32_t l);
void rev_check();
void replace_tab2space();
void remove_space2tab();
void folding();
void open_file();
void error_check();

/* DR Module 2 functions */
void all_range();
void for_wo_andor();

/* EX_2_3 */
void call_htoi();
int32_t htoi (int8_t *s);
int32_t strtoint(int8_t c);

/* EX_2_4 */
int32_t lowercase(int8_t s[]);
void squeeze(int8_t str1[], int8_t str2[]);
void call_squeez();

/* EX_2_5 */
int32_t any(int8_t s1[],int8_t s2[]);
void call_any();

/* EX_2_5 */
int32_t setbits(int16_t x,int16_t p,int16_t n,int16_t y);
void call_setbits();

/* EX_2_7 */
int32_t invert(int32_t x,int32_t p,int32_t n);
void call_invert();

/* EX_2_8 */
uint32_t rightrot(int32_t x, uint32_t n);
void call_rightrot();

/* EX_2_9 */
int32_t bitcnt(uint32_t x);
void call_bitcnt();

/* EX_2_10 */
int32_t lower_wo_if(int8_t c[]);
void call_lower_wo_if();

/* DR Module 3 functions */
/* EX_3_1 */
int32_t binsearch(int32_t x, int32_t v[], int32_t n);
void call_binsearch();
int binsearch_old();
int32_t arr_sort(int32_t arr[],int32_t n);


/* EX_3_2 */
int32_t unescape(int8_t s[],int8_t t[]);
int32_t escape(int8_t s[],int8_t t[]);
void call_escape();

/* EX_3_3 */
void expand(int8_t s1[],int8_t s2[]);
void call_expand();


/* EX_3_4 */
void itoa(int32_t n, int8_t s[]);
void call_itoa();
/* EX_3_5 */
void itob(int32_t n,int8_t s[],int32_t b);
void reverses(int8_t s[]);
void call_itob();

/* EX_3_6 */
void itoapad(int32_t n, int8_t s[],int32_t w);
void call_itoapad();

/* DR Module 3 functions */
int32_t strindex(int8_t s[],int8_t t[]);
void call_index();

/* EX_4_2  */
double _atof(int8_t s[]);
void call_atof();

/* EX_4_3  */
int32_t getop(int8_t []);
void push(double);
double pop(void);
int32_t getch(void);
void ungetch(int32_t);
void cal_stack();

/* EX_4_4 */
void Dup();
void swap();
void clear();
void print_stack();


/* EX_4_7 */
void ungets(int8_t s[]);
void call_ungets();

/* EX_4_8 */
void one_getch();

/* EX_4_9 */
void handleEOF();

/* EX_4_10 */
int32_t getop_mygetline(int8_t s[]);

/* EX_4_12 */
void recursive_itoa(int32_t n,int8_t s[]);
void call_recursive_itoa();

/* EX_4_13 */
void recursive_reverse(int8_t s[],int8_t rev[],int32_t iIndex);
void call_recursive_rev();
/* EX_4_14 */
void call_swap();

/*-------------------------------------------YPK MODULE 3--------------------------*/
/* YKP_3_1*/
char * xstrchr(char *string,char ch);
void call_xstrchr();


/* YKP_3_2*/
char * xstrstr(char *string1,char *string2);
void call_xstrstr();

/* YKP_3_3*/
void sort_string();

/* YKP_3_4*/
void decompress(int8_t string_compress[],int8_t recover[],int32_t SpaceCount[]);
void compress(int8_t string[],int8_t string_compress[],int32_t SpaceCount[]);
void call_com_decom();

/* YKP_3_5*/
void call_encode_decode();
void decode(int8_t Encode[],int8_t Decode[]);
void encode(int8_t string[],int8_t Encode[]);

/*  YKP_4_1*/
void display_matrix(int32_t *matrix,int32_t size);
void user_matrix(int32_t **matrix,int32_t size);
void call_determinant();
int32_t determinant(int32_t *matrix,int32_t size);

/*  YKP_4_2 */
void print_file_attributes();
void change_permission(char* path);
void print_file_type(mode_t mode);
void print_permissions(mode_t mode);

/* YKP_4_3*/
void call_list_dir();
void list_dir(char *path);
void sort_linklist(char *file_name);
void display_linked_list();

/* YKP_4_4*/
void bootsector_read();
void dir_file_read();

/* YKP_4_5*/
void display_partition_table();
void Dir_table();
const char *Dir_type(int32_t type);
/*-----------------------------------------DR MODULE 5-----------------------------------*/

/* DR_5_1 */
int32_t _getch(void);
void un_getch(int32_t c);
void call_getint();
int32_t getint(int32_t *pn);

/* DR_5_2 */
int32_t getfloat(float *pn);
void call_getfloat();

/* DR_5_3 */
void call_strcat();
void Strcat(char *s,char *t);

/* DR_5_4 */
int32_t Strend(int8_t *s,int8_t *t);
void call_strend();

/* DR_5_5 */
int32_t strncmp(const char *str1, const char *str2, size_t n);
char *strncat(char *dest,const char *src,size_t n);
char *strncpy(char *dest,const char *src,size_t n);
void call_str_library();

/* DR_5_6 */
void test_ptr_function();

/* DR_5_7 */
void call_readlines();
int getLine(char *, int);
char *alloc(int);
int readlines(char *lineptr[],char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);
void Qsort(char *lineptr[], int left, int right);
void Swap(char *v[], int i, int j);

/* DR_5_8 */
void month_day(int year, int yearday, int *pmonth, int *pday);
int32_t day_of_year(int32_t year, int32_t month, int32_t day);
void call_month_day();
void call_day_of_year();


/* DR_5_9 */
void call_day_of_year_ptr();
void call_month_day_ptr();
int32_t day_of_year_ptr(int32_t year, int32_t month, int32_t day);
void month_day_ptr(int year, int yearday, int *pmonth, int *pday);


/* DR_5_10 */
void expr(int32_t argc, char *argv[]);
void argv_to_string(int argc, char *argv[], char *result, size_t size);

/* DR_5_11 */
void replace_tab2space_a(char TAB);
void remove_space2tab_a(char TAB);


/* DR_5_12 */
void replace_tab2space_a_mn(char TAB, char m);
void remove_space2tab_a_mn(char TAB,char m);

/* DR_5_13 */
int call_13(int argc, char *argv[]);

/* DR_5_14 */
int numcmp(char *, char *);
void QSort(void *lineptr[], int left, int right, int (*comp)(void *, void *),_Bool reverse,_Bool directory);
void sort_arg(int32_t argc,char *argv[]);
void Lowercase(char *lines[], int nlines);
int dircmp(char *s1, char *s2);
void extract_field(char *dest,char *line,int32_t field);

/* DR_5_18 */
#define MAXTOKEN 1000
extern int tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out[1000];




int gettoken(void);
void dcl(void);
void dirdcl(void);
void call_dcl(void);


/* DR_5_19 */
void undcl();

/*-----------------------------------------DR MODULE 6-----------------------------------*/
void call_getword();
int getword(char *word, int lim,FILE *fp);



/* DR_6_2 */
/*typedef struct tnode{
        char *word;
        int32_t count;
        struct tnode *left;
        struct tnode *right;

}tnode;

*/
void call_main(FILE *fp,int32_t n );
/*
tnode *addtree(tnode *p, char *w);
void treeprint();
tnode *talloc(void);
*/
/* DR_6_3 */

//void call_xref(int argc, char *argv[]);
void Word_Count_line(int argc , char * argv[]);
int32_t is_noise(char *word);
int32_t getword_read_file(char *word, int lim, FILE *fp);

/* DR_6_4 */
void Word_Count_line_sort(int argc , char * argv[]);

/* DR_6_5 */
void call_hashTable();


/* DR_6_6 */
void call_hash_define();
/*-----------------------------------------DR MODULE 7-----------------------------------*/


/* DR_7_1 */
void uppertolower_arg(int32_t argc,char *argv[]);


/* DR_7_2 */
void non_graphic();


/* DR_7_3 */

void call_minprintf();
void minprintf(char *fmt, ...);
/* DR_7_4 */
void call_minscanf();
void minscanf(char *fmt, ...);


/* DR_7_5 */
int32_t getop_scanf(char s[]);
void calc_scanf();

/* DR_7_6 */
void cmpFile(FILE* Src,FILE *Dest);
void call_fileCmp(int32_t argc,char *argv[]);


/* DR_7_7 */
void call_pattern(int argc, char *argv[]);
void find_pattern(FILE *fp, const char *filename, const char *pattern);


/* DR_7_8 */
void call_print_file(int argc, char *argv[]);
void print_file(FILE *fp, const char *filename);

/* DR_7_9 */
int32_t isUpperTime(char c );
int32_t isUpperSpace(char c);
void time_space_isupper();


/*------------------------------------------MODULE - 8------------------------------*/


/* DR_8_1 */
void cat(int argc, char *argv[]);
void filecopy(int32_t ifp, int32_t ofp);

/* DR_8_2 */
void call_fopen_bitfield();


/* DR_8_3 */
void call_flush();

/* DR_8_4 */
void call_Fseek();

/* DR_8_5 */
void dirwalk(char *dir, void (*fcn)(char *));
void fsize(char *name);


/* DR_8_6 */
void *Calloc(uint32_t n,uint32_t size);
void call_Calloc();


/* DR_8_7 */
int custom_malloc();


/* DR_8_8 */
void call_bfree();


#endif


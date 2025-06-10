#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include "main.h"

/* REQUIRED MARCOS */
#define MAXLINE 1000


/* MAIN PROGRAM */

int main(int32_t argc, char *argv[]) {
    int module, option;
    
    //while (1) {
        printf("\nSelect a module:\n");
        printf("1. Module 1\n2. Module 2\n3. Module 3\n4. Module 4\n5. Module 5\n6. Module 6\n7. Module 7\n8. Module 8\n9. YPK Module 3\n10. YPK Module 4\n");
        printf("Enter choice: ");
        scanf("%d", &module);
        
        //if (module == 9) {
          //  printf("Exiting program...\n");
         //   break;
       // }
        
        switch (module) {
      	case 1:
                printf("\nSelect a function from Module 1:\n");
                printf("1. hello\n2. fahr_cel\n3. cel_fahr\n4. cel_fahr1\n5. verify_getchar\n6. verify_EOF\n7. cnt_all\n8. rm_spaces\n9. visible\n10. cnt_word\n11. print_word\n12. histogram_hor\n13. histogram_f\n14. valid_input\n15. longest\n16. limit\n17. remove_check\n18. rev_check\n19. replace_tab2space\n20. remove_space2tab\n21. folding\n22. open_file\n23. error_check\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
                    case 1: hello(); break;
                    case 2: fahr_cel(); break;
                    case 3: {
                        float cel;
                        printf("Enter temperature in Celsius: ");
                        scanf("%f", &cel);
                        cel_fahr(cel);
                    } break;
                    case 4: cel_fahr1(); break;
                    case 5: verify_getchar(); break;
                    case 6: verify_EOF(); break;
                    case 7: cnt_all(); break;
                    case 8: rm_spaces(); break;
                    case 9: visible(); break;
                    case 10: cnt_word(); break;
                    case 11: print_word(); break;
                    case 12: histogram_hor(); break;
                    case 13: histogram_f(); break;
                    case 14: valid_input(); break;
                    case 15: longest(); break;
                    case 16: limit(); break;
                    case 17: remove_check(); break;
                    case 18: rev_check(); break;
                    case 19: replace_tab2space(); break;
                    case 20: remove_space2tab(); break;
                    case 21: folding(); break;
                    case 22: open_file(); break;
                    case 23: error_check(); break;
                    default: printf("Invalid option!\n");
                }
                break;
                
     	case 2:
                printf("\nSelect a function from Module 2:\n");
                printf("1. all_range\n2. for_wo_andor\n3. call_htoi\n4. call_squeez\n5. call_any\n6. call_setbits\n7. call_invert\n8. call_rightrot\n9. call_bitcnt\n10. call_lower_wo_if\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
                    case 1: all_range(); break;
                    case 2: for_wo_andor(); break;
                    case 3: call_htoi(); break;
                    case 4: call_squeez(); break;
                    case 5: call_any(); break;
                    case 6: call_setbits(); break;
                    case 7: call_invert(); break;
                    case 8: call_rightrot(); break;
                    case 9: call_bitcnt(); break;
                    case 10: call_lower_wo_if(); break;
                    default: printf("Invalid option!\n");
                }
                break;
                
    	case 3:
                
		printf("\nSelect a function from Module 3:\n");
                printf("1. call_binsearch\n2. call_escape\n3.call_expand \n4. call_itoa\n5. call_itob\n6. call_itoapad ");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
		
                 	case 1: call_binsearch(); break;
		
			case 2: call_escape(); 	break;
		
			case 3:	call_expand();	break;
		
			case 4: call_itoa();	break;
				
			case 5: call_itob(); 	break;
			
			case 6: call_itoapad();	break;

               		default: printf("Invalid option!\n");
                }
                break;
	case 4:
		printf("\nSelect a function from Module 4:\n");
                printf("1. str_index\n2. atof\n3.Stack calculator\n4.swap,clear,duplicate and top element display\n5. math library\n6. add variables\n7. call_ungets\n8. one_getch\n9. handleEOF\n10. cal_using_getline\n11.cal_without_ungetch \n12.recursive_itoa \n13.recursive reverse \n14.swap using macro \n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
			
			
                        case 1: call_index(); break;

                        case 2: call_atof(); break;
			
			case 3: cal_stack(); break;
			
			case 4: cal_stack(); break;
			
			case 5: cal_stack(); break;

                        case 6: ; cal_stack(); break;
			
			case 7:  call_ungets(); break;
			
			case 8: one_getch() ; break;

			case 9: handleEOF() ; break;
			
			case 10:cal_stack() ; break;
			
			case 11:cal_stack() ; break;
			
			case 12: call_recursive_itoa(); break;	
			case 13: call_recursive_rev() ;break;
			case 14: call_swap(); break;	
			default: printf("Invalid option!\n");
                }
		break;

	case 5:
		printf("\nSelect a function from DR Module 5:\n");
                printf("1.getint \n2.getfloat \n3.strcat \n4.strend \n5.String Functions \n6.Changed functions with pointer \n7.readlines \n8.day of year\n9.above using pointers \n10.calc using command line argument \n11.entab detab using commandline argument\n12.entab detab using commandline argument \n13.print tails \n14.sort in reverse if -r is passed \n15.use -f to fold to upper to lower \n16.use -d to compare directory type \n17. field seprate \n18. dcl \n19.Undcl \n20. DCL\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
                        case 1: call_getint(); break;
			case 2: call_getfloat(); break;
                        
			case 3: call_strcat(); break;
			case 4:call_strend() ; break;
                        case 5:call_str_library() ; break;
                        case 6:test_ptr_function() ; break;
                        case 7: call_readlines(); break;
                        case 8:call_day_of_year();call_month_day() ; break;
                        case 9: call_day_of_year_ptr();call_month_day_ptr(); break;
                        case 10:expr(argc,argv);break;
			case 11:{
				char TAB;
				TAB = atoi(argv[1]);

				printf("Detab\n");
				replace_tab2space_a(TAB);
				/*
				printf("Entab\n");
			       	remove_space2tab_a(TAB);
				*/
				break;}
                        case 12:
				{char TAB1,m;
				TAB1 = atoi(argv[1]);
				m = atoi(argv[2]);
				//printf("Detab\n");
                                //replace_tab2space_a_mn(TAB1,m);
                                printf("Entab\n");
                                remove_space2tab_a_mn(TAB1,m);
			       	break;}
                        case 13: call_13(argc,argv); break;
			/*case 14: sort_arg(argc,argv); break;
			case 15:sort_arg(argc,argv);break;
			case 16:sort_arg(argc,argv);break;
			case 17:sort_arg(argc,argv);break;*/
			case 18: call_dcl();break;
			case 19:
				 undcl();
				 break;
			case 20:call_dcl();break;

                }
                break;
	case 6:
		printf("\nSelect a function from DR Module 6:\n");
                printf("1. getword\n2. word count upto n \n3. getword count and line number\n4. getword in decreasing word count \n5. hashtable\n6. hashtable of #define\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {
                        case 1: call_getword(); break;
                        case 2:{
				int32_t n =atoi(argv[1]);
				FILE *fp = fopen(argv[2],"r");
				if (!fp) {
        				printf("Error opening file");
        				return 1;
    				}

				call_main(fp,n) ;
			       	fclose(fp);
				break;}
                        case 3: Word_Count_line(argc,argv); break;
                        case 4: Word_Count_line_sort(argc,argv); break;
                        case 5: call_hashTable(); break;
                        case 6:call_hash_define() ; break;
		}

		break;
	case 7:
		printf("\nSelect a function from DR Module 7:\n");
		printf("1. upper to lower and viseversa\n2. non graphic\n3. minprintf \n4. minscanf  \n5. calc using scanf \n6. file comparison \n7. pattern match in given file\n8. New paging after certain lines\n9. time and space of isupper\n");
		printf("Enter function number: ");
		scanf("%d", &option);
		switch (option) {
                        case 1: uppertolower_arg(argc,argv); break;
                        case 2: non_graphic();break;
                        case 3: call_minprintf();break;
                        case 4: call_minscanf();break;
                        case 5: calc_scanf();break;
                        case 6: 
				call_fileCmp(argc,argv);
				break;
                        case 7:call_pattern(argc,argv) ;break;
                        case 8: call_print_file(argc,argv);break;
                        case 9: time_space_isupper();break;

		}
		break;
	case 8:

		
		printf("\nSelect a function from DR Module 8:\n");
		printf("1. Cat\n2. fopen using field\n3. flush \n4. fseek  \n5. fsize \n6. calloc using malloc \n7. custom malloc\n8. bfree\n");
		printf("Enter function number: ");
		scanf("%d", &option);
		switch (option) {
			case 1: cat(argc,argv); break;
			case 2:call_fopen_bitfield() ; break;
			case 3:call_flush() ; break;
			case 4:call_Fseek() ; break;
			case 5: fsize("/home/bhavik_23/c_task/testcode.c"); break;
			case 6:call_Calloc() ; break;
			case 7: custom_malloc(); break;
			case 8: call_bfree(); break;
		}			
		break;
	case 9:
		printf("\nSelect a function from YPK Module 3:\n");
                printf("1. xstrchr \n2. xstrstr \n3. sort string \n4. Compress/Decompress \n5. Encode/Decode\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {

			case 1: call_xstrchr(); break;
			
			case 2: call_xstrstr(); break;
			
			case 3: sort_string(); break;
			
			case 4:call_com_decom(); break;
			
			case 5:call_encode_decode(); break;
			
		}
                break;
        case 10:
		printf("\nSelect a function from YPK Module 4:\n");
                printf("1.Determinant \n2.File Attributes \n3.linklist of given path directory display \n4.BootSector read from hard disk \n5. Display hard disk partition\n");
                printf("Enter function number: ");
                scanf("%d", &option);
                switch (option) {

                        case 1: call_determinant(); break;
			case 2:print_file_attributes(); break;
			case 3:call_list_dir() ; break;
                        
			case 4:dir_file_read(); break;
                        
			case 5: Dir_table(); break;
                }
                break;

 	default:
                printf("Invalid module selection!\n");
        }
    //}
    return 0;
}



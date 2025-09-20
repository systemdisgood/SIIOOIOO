#include <stdlib.h>
#include <stdio.h>

#define MAX_STR_LEN 83
#define DBYTE unsigned short
#define SBYTE unsigned char
#define SICPU_DBYTES_QUANTITY 0x8000
#define CPU_SBYTES_QUANTITY 0x10000

DBYTE sicpu_dbytes[SICPU_DBYTES_QUANTITY];
SBYTE cpu_sbytes[CPU_SBYTES_QUANTITY];

int check_dbyte(void)
{
	int is_not_ok = 0;
	DBYTE a = 0;
	a -= 1;
	if(0xFFFF != a) return -1;
	return 0;
}

int check_sbyte(void)
{
	int is_not_ok = 0;
	SBYTE a = 0;
	a -= 1;
	if(0xFF != a) return -1;
	return 0;
}

int print_if_ok(char* check_name, int error_code)
{
	if(error_code != 0) printf("ERROR WITH %s ERROR CODE %d\n", check_name, error_code);
	return 0;
}

typedef struct
{
	DBYTE* sicpu_mem;
	DBYTE cur_word;
	int is_addr;
	SBYTE cpu_mem;
	DBYTE cpu_addr;
	SBYTE cpu_data;

} Sicpu;

int main(int argc, char* argv[])
{
	FILE* sicpu_init_ihex = NULL; /*for binary translating single instruction CPU initial memory*/
	FILE* cpu_init_ihex = NULL; /*for binary translated CPU initial memory*/
	FILE* mut_ihex = NULL; /*for state of both memories*/
	int input_character = 0; /*for characters IO operations in main*/
	
	print_if_ok("double byte", check_dbyte()); /*we need to check bitwidth of 16 bit type*/
	print_if_ok("single byte", check_sbyte()); /*we need to check bitwidth of single 8 bit byte*/
	switch(argc)
	{
		case 1:
			printf("Use argument \"help\" to get help.\n");
			break;
		case 2:
			printf("I think you need help. This is a help for you.\n");
			printf("Some help... (will be later)\n");
			break;
		case 4:
			
			break;
		default:
			fprintf(stderr, "Wrong arguments quantity!\n");
			break;
	}

	return 0;
}

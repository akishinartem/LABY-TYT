#include <stdio.h>
#include <stdlib.h>
#define YES	1
#define NO	0
#define MAXLINE	1000
void process_line (char buffer []);

void main (void)
{
	char line [MAXLINE];
	gets (line); 
	process_line (line);
	puts (line);
	system("pause"); 
}

void process_line (char buffer [])
{
 	char *buf_ptr;
	char *end;
	char *begin;
	char c;
	int flag;
	int found;

	flag = NO;
	found = NO;
	c = ' ';

	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
    
	do
    {
        c = *buf_ptr;
        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
		{
			if (flag == YES)
			{
				end = buf_ptr - 1;
				if (found)
				{
					char *src = end + 1;
					char *dst = begin;
					while( (*dst++ = *src++ ) != '\0' );
					buf_ptr = begin;
				}				
			}
			flag = NO;
			found = NO;
		}
		else
		{
			if( flag == NO)
			{
				begin = buf_ptr;
				flag = YES;
				if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u' || c == 'Y' || c == 'y')
				{
					found = YES;
				}
			}
			if (c >= '0' && c <= '9')
			{
				found = NO;
			}		
		}
		buf_ptr++;
	}
	while (c != '\0');
}
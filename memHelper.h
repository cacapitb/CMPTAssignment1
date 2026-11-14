/* memHelper.h
 *
 * The API can NOT be modified.
 * All helper and/or debugging methods must go here.
 *
 * Author:
 * ID:
 * Lab instructor:
 * Lecture instructor:
 */


#ifndef MEMHELPER_H
#define MEMHELPER_H

#include "memManager.h"

Footer * get_footer_pos(Header * header);

Header * get_next_header(Header * header);

int alignment(unsigned int sz);

Footer * get_prev_footer(Header * header);

Header * get_prev_header(Header * header);

void print_break_line();

void print_title();

void print_info_line(int i,unsigned int status, Header * start, unsigned int size, Footer * end);

#endif // !MEMHELPER_H

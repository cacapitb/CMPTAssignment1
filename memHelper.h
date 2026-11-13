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
#endif // !MEMHELPER_H

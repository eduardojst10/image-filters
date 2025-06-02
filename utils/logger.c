#include "include/logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

void logger(const char* tag, const char* message) {
   time_t now;
   time(&now);

   // remove newline do ctime()
   char* ts = ctime(&now);
   ts[strcspn(ts,"\n")] = '\0';
   printf("%s [%s]: %s\n", ts, tag, message);
}

void logger_detail(const char* tag, const char* format, ...) {
   time_t now;
   time(&now);
   
   // remove newline do ctime()
   char* ts = ctime(&now);
   ts[strcspn(ts,"\n")] = '\0';

   va_list args;
   va_start(args,format);

   printf("%s [%s]: ", ts, tag);
   vprintf(format, args);
   //printf("\n");

   va_end(args);
}
#ifndef _RUN_H_
#define _RUN_H_

//notes: memcopy() exp: memcpy(&aniche, &mauricio, sizeof(CONTATO)); As the name says, it copies what is in memory. Her signature is very similar to that of strcpy (), with the difference that, in addition to passing the destination and the source, we also need to pass the number of bytes we want to copy.
//notes2: memset() exp: // 0 means NULL -> memset(&marcelo, 0, sizeof(CONTATO)); We usually use it to initialize structs or arrays with some default value (usually "null"). This is especially useful, as many C compilers do not clear memory regions before releasing it to the programmer. So it is common to have "trash".

void wellcomeMessage();
void lose();
void winMessage();

int finish();

#endif
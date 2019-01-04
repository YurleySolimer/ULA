#ifndef QS_MESSAGE
#define QS_MESSAGE
#include <qs_connection.h>

QS_CREATE_MESSAGE(SendFromServer){
	bool z0,z1,z2,z3,z4,z5,z6;
};


QS_CREATE_MESSAGE(SendFromClient){
int number;
};

#endif

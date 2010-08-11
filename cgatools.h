#ifndef __CGA_TOOLS_H
#define __CGA_TOOLS_H

#define _BINARY_HIGH	'#'
#define _BINARY_LOW		'.'

#define __DOS_EOL		"\r\n"
#define __UNIX_EOL		"\n"

#ifdef __DOS
#define __EOL	__DOS_EOL
#else
#define __EOL	__UNIX_EOL
#endif

#endif


#ifndef STDBOOL_H_
#define STDBOOL_H_

// I copied this from LLVM
// and didnt include some stuff
// Let's pray this is correct

#define bool _Bool
#define true 1
#define false 0
#elif defined(__GNUC__) && !defined(__STRICT_ANSI__)
/* Define _Bool as a GNU extension. */
#define _Bool bool
#if defined(__cplusplus) && __cplusplus < 201103L
/* For C++98, define bool, false, true as a GNU extension. */
#define bool bool
#define false false
#define true true
#endif
#endif

#endif /* __MVS__ */

#endif // STDBOOL_H_

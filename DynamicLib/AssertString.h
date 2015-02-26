#ifndef Assert_String_H
#define Assert_String_H

#include <assert.h>

/**
 * 修改assert宏，提供源代码和运行时级别的友好的错误信息
 */
#ifdef NDEBUG

#define ASSERT_STRING(_Expression, _String)	\
	(void)((!!(_Expression)) || (printf("Assertion failed: %s, function: %s, file %s, line %d\n", #_String, __FUNCSIG__, __FILE__, __LINE__), 0))

#else

#define ASSERT_STRING(_Expression, _String) \
	(void)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_String)##_CRT_WIDE(", function: ")##_CRT_WIDE(__FUNCSIG__), _CRT_WIDE(__FILE__), __LINE__), 0));

#endif

#endif /* Assert_String_H */
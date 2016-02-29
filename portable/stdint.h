#pragma once 


#ifdef __WINDOWS_OS__

typedef char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;



typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;


typedef int8_t int_fast8_t;
typedef uint8_t uint_fast8_t;
typedef int16_t int_fast16_t;
typedef uint16_t uint_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast32_t;
typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;

#define INT8_MAX   0x7f
#define INT8_MIN   (-INT8_MAX - 1)
#define UINT8_MAX   (INT8_MAX * 2 + 1)
#define INT16_MAX   0x7fff
#define INT16_MIN   (-INT16_MAX - 1)
#define UINT16_MAX   (__CONCAT(INT16_MAX, U) * 2U + 1U)
#define INT32_MAX   0x7fffffffL
#define INT32_MIN   (-INT32_MAX - 1L)
#define UINT32_MAX   (__CONCAT(INT32_MAX, U) * 2UL + 1UL)
#define INT64_MAX   0x7fffffffffffffffLL
#define INT64_MIN   (-INT64_MAX - 1LL)
#define UINT64_MAX   (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)

#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST8_MIN   INT8_MIN
#define UINT_LEAST8_MAX   UINT8_MAX
#define INT_LEAST16_MAX   INT16_MAX
#define INT_LEAST16_MIN   INT16_MIN
#define UINT_LEAST16_MAX   UINT16_MAX
#define INT_LEAST32_MAX   INT32_MAX
#define INT_LEAST32_MIN   INT32_MIN
#define UINT_LEAST32_MAX   UINT32_MAX
#define INT_LEAST64_MAX   INT64_MAX
#define INT_LEAST64_MIN   INT64_MIN
#define UINT_LEAST64_MAX   UINT64_MAX

#define INT_FAST8_MAX   INT8_MAX
#define INT_FAST8_MIN   INT8_MIN
#define UINT_FAST8_MAX   UINT8_MAX
#define INT_FAST16_MAX   INT16_MAX
#define INT_FAST16_MIN   INT16_MIN
#define UINT_FAST16_MAX   UINT16_MAX
#define INT_FAST32_MAX   INT32_MAX
#define INT_FAST32_MIN   INT32_MIN
#define UINT_FAST32_MAX   UINT32_MAX
#define INT_FAST64_MAX   INT64_MAX
#define INT_FAST64_MIN   INT64_MIN
#define UINT_FAST64_MAX   UINT64_MAX


#ifdef __HAS_INT128__
typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;
#endif

#endif

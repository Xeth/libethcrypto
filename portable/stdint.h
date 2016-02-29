#ifdef __WINDOWS_OS__

typedef char int8_t;
typedef unsigned char uint8_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

#if HAVE___INT128
typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;
#endif

#endif

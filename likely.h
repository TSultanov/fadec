#ifdef __GNUC__
#ifndef _WIN32
#define LIKELY(x) __builtin_expect((x), 1)
#define UNLIKELY(x) __builtin_expect((x), 0)
#else
#define LIKELY(x) _Generic((x), \
    long long: (x), \
    unsigned long long: (x), \
    default: __builtin_expect((x), 1))
#define UNLIKELY(x) _Generic((x), \
    long long: (x), \
    unsigned long long: (x), \
    default: __builtin_expect((x), 0))
#endif
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

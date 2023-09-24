// 扩容优化，使用素数扩容
size_t GetNextPrime(size_t prime) {
    // SGI
    static const int __stl_num_primes = 28;
    static const unsigned long __stl_prime_list[__stl_num_primes] = {
            53, 97, 193, 389, 769, 1543,
            3079, 6151, 12289, 24593, 49157, 98317,
            196613, 393241, 786433, 1572869, 3145739, 6291469,
            12582917, 25165843, 50331653, 100663319, 201326611, 402653189,
            805306457, 1610612741, 3221225473, 4294967291};

    size_t i = 0;
    for (; i < __stl_num_primes; ++i) {
        if (__stl_prime_list[i] > prime)
            return __stl_prime_list[i];
    }

    return __stl_prime_list[i];
}
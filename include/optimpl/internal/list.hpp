template<typename T>

unsigned int pLen(T* p) {
    return sizeof(p)/sizeof(p[0]);
}
#include <vector>
#include <semaphore>
#include <mutex>

template <typename T>
class BoundedBuffer {
    private: 
        int size;
        std::vector<T> buffer;
        std::counting_semaphore slots_full;
        std::counting_semaphore slots_empty;
    public:
        BoundedBuffer(int size);
        void put(T value);
        T pop();
};
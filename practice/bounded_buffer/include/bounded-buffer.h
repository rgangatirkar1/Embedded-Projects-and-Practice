#include <vector>
#include <semaphore>
#include <mutex>

template <typename T>
class BoundedBuffer {
    private: 
        int size;
        std::vector<T> buffer;
        std::counting_semaphore<int> slots_full;
        std::counting_semaphore<int> slots_empty;
    public:
        BoundedBuffer(int size);
        void put(T value);
        T pop();
};

template <typename T>
BoundedBuffer<T>::BoundedBuffer(int size)
    : size(size),
      buffer(size),
      emptySlots(size),
      fullSlots(0)
{
}
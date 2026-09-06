#include <vector>

class CustomBitset {
    private:
        std::vector<char> my_bitset;
        int bitset_size;
        
    public:
        CustomBitset(int size);
        void clear_bit(int bit_no);
        void set_bit(int bit_no);
        int find_earliest_set(int bit_no) const;
        int extract_bit(int bit_no) const;
        int size() const;
        void flip();
        void clear();
        void set();
};


    
        

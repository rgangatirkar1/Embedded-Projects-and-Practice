#include <vector>

class CustomBitset {
    private:
        std::vector<char> my_bitset;
        int bitset_size;
        
    public:
        using iterator = std::vector<char>::iterator;
        using const_iterator = std::vector<char>::const_iterator;

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

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

void check_valid_bit_index(int bit_no, int bitset_size);

    
        

    #include <iostream>
    
    using namespace std;

    struct uchar4{
        unsigned char _1; unsigned char _2; unsigned char _3; unsigned char _4;
    };
        uint32_t to_uint32_t(uchar4* const uc4)
        {
            uint32_t res;
            void *s = static_cast<void *>(&res);
            uint8_t *sum = static_cast<uint8_t *>(s); // две строки == uint8_t * sum = reinterpret_cast<uint8_t*>(&r);
            *sum++ = uc4->_4;
            *sum++ = uc4->_3;
            *sum++ = uc4->_2;
            *sum++ = uc4->_1;
            return res;
    }
    
    int main(int args_count, char** args)
    {
        uchar4 test = {'0', '0', '0', '0'};
        cout << to_uint32_t(&test);

        return 0;
    }
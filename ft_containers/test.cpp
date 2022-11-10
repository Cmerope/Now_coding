#include <iostream>

class A
{
    private:
        std::string s;
    public:
        explicit A(const std::string& S)
        {
            std::cout << S << std::endl;
        }
};

int main()
{
    std::string s = "sdfasdf";
    A a(s);

}
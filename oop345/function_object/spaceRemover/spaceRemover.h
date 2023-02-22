// Create a functor (a function object) that removes the spaces from the beginning/end of any string. An instance should be able to keep track of how many strings were cleared and how many spaces were removed; and provide these values to a client through a query.
#include<string>
class spaceRemover{
    public:
    int timesCalled{};
    int space_removed{};
    std::string operator()(std::string);
};
std::string spaceRemover::operator()(std::string str){
    int Actualsize = str.length();
    int startIndex = str.find_first_not_of(" ");
    int lastIndex = str.find_last_not_of(" ");
    str = str.substr(startIndex, lastIndex-startIndex+1);
    timesCalled++;
    space_removed += Actualsize-str.length();
    return str;
}
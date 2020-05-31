#include <memory>
class A{

};
template <class T>
std::enable_if_t<std::is_base_of<A, T>::value, void> function(){

}


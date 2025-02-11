#include "codes.hpp"

std::string Codes::to_string(Module module){
    return std::string(magic_enum::enum_name(module));
}

std::string Codes::to_string(Instance instance){
    return std::string(magic_enum::enum_name(instance));
}

std::string Codes::to_string(Component component){
    return std::string(magic_enum::enum_name(component));
}

std::string Codes::to_string(Message_type message){
    return std::string(magic_enum::enum_name(message));
}

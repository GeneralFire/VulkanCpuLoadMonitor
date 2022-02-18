#pragma once

#include <stdexcept>
#include <sstream>

class e_runtime_error : public std::runtime_error
{
private:
    std::string msg;

public:
    e_runtime_error(const std::string& arg, const char* file, int line) :
        std::runtime_error(arg) {
        std::ostringstream o;
        o << file << ":" << line << ": " << arg;
        msg = o.str();
    }
    ~e_runtime_error() throw() {}
    const char* what() const throw() {
        return msg.c_str();
    }
};

#define throw_e_runtime_error(arg) throw e_runtime_error(arg, __FILE__, __LINE__);
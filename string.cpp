#include "string.h"


// Constructeur par défaut
string::string() {
    size_ = 11;
    my_string_ = new char[size_];
    my_string_[0] = 'H';
    my_string_[1] = 'e';
    my_string_[2] = 'l';
    my_string_[3] = 'l';
    my_string_[4] = 'o';
    my_string_[5] = ' ';
    my_string_[6] = 'W';
    my_string_[7] = 'o';
    my_string_[8] = 'r';
    my_string_[9] = 'l';
    my_string_[10] = 'd';
    my_string_[11] = '\0';  
}

// Constructeur de copie
string::string(const string& other) {
    size_ = other.size_;
    my_string_ = new char[size_ + 1]; 
    for (int i = 0; i < size_; ++i) {
        my_string_[i] = other.my_string_[i];
    }
    my_string_[size_] = '\0';
}

// c_str()
const char* string::c_str() const {
    return my_string_;
}

// size()
int string::size() const {
    return size_;
}

// clear()
void string::clear() {
    for (int i = 0; i < size_; ++i) {
        my_string_[i] = '\0';
    }
    size_ = 0;
}

// operator=(char)
string& string::operator=(char c) {
    delete[] my_string_;
    my_string_ = new char[2];
    my_string_[0] = c;
    my_string_[1] = '\0';
    size_ = 1;
    return *this;
}

// operator+(const char*)
string string::operator+(const char* ajout) {
    int base_size = size_;
    int ajout_size = 0;
    while (ajout[ajout_size] != '\0') {
        ++ajout_size;
    }
    int res_size = base_size + ajout_size;
    if (res_size > size_max) {
        throw "La taille dépasse la limite de 100 caractères";
    }
    char* res = new char[res_size + 1];
    for (int i = 0; i < base_size; ++i) {
        res[i] = my_string_[i];
    }
    for (int i = 0; i < ajout_size; ++i) {
        res[base_size + i] = ajout[i];
    }
    res[res_size] = '\0';
    string result(res);
    delete[] res;
    return result;
}

// Constructeur à partir d'une chaîne C
string::string(const char* str) {
    size_ = 0;
    while (str[size_] != '\0' && size_ < size_max) {
        ++size_;
    }
    my_string_ = new char[size_ + 1];
    for (int i = 0; i < size_; ++i) {
        my_string_[i] = str[i];
    }
    my_string_[size_] = '\0';
}

// length()
int string::length() const {
    return size_;
}

// max_size()
int string::max_size() const {
    return size_max;
}

//resize(size_t, char)
void string::resize(int new_size, char c) {
    if (new_size > size_) {
        for (int i = size_; i < new_size; ++i) {
            my_string_[i] = c;
        }
    } else if (new_size < size_) {
        my_string_[new_size] = '\0';
    }
    size_ = new_size;
}


void string::resize(int new_size) {
    if (new_size > size_) {
        for (int i = size_; i < new_size; ++i) {
            my_string_[i] = '-';
        }
    } else if (new_size < size_) {
        my_string_[new_size] = '\0';
    }
    size_ = new_size;
}

// operator=(const string&)
string& string::operator=(const string& str) {
    delete[] my_string_;
    size_ = str.size();
    my_string_ = new char[size_ + 1];
    for (int i = 0; i < size_; ++i) {
        my_string_[i] = str.my_string_[i];
    }
    my_string_[size_] = '\0';
    return *this;
}

// operator+(const char)
string string::operator+(const char c) {
    int base_size = size_;
    int res_size = base_size + 1;
    if (res_size > size_max) {
        throw "La taille dépasse la limite de 100 caractères";
    }
    char* res = new char[res_size + 1];
    for (int i = 0; i < base_size; ++i) {
        res[i] = my_string_[i];
    }
    res[base_size] = c;
    res[res_size] = '\0';
    string result(res);
    delete[] res;
    return result;
}

// Destructeur
string::~string() {
    delete[] my_string_;
    my_string_ = nullptr;
}


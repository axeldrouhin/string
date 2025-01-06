
#ifndef STRING_H
#define STRING_H


class string {

public:
    string();                                                        // Constructeur par défaut
    string(const string& other);                                     // Constructeur de copie
    const char* c_str() const;                                       // c_str
    int size() const;                                                // size
    void clear();                                                    // clear
    string& operator=(char c);                                       // operator=(char)
    string operator+(const char* ajout);                             // operator+(const string&, const char*)
    string(const char* str);                                         // Constructeur à partir d'une chaîne C
    int length() const;                                              // length
    int max_size() const;                                            // max_size
    void resize(int new_size, char c);                               // resize(int, char)
    void resize(int new_size);                                       // resize(int)
    string& operator=(const string& str);                            // operator=(const string&)
    string operator+(const char c);                                  // operator+(const string&, char)

    ~string();                                                       // Destructeur

protected:
    char* my_string_;                                                // Attributs
    int size_;                                                       
    static const int size_max = 100;                                 
};

#endif


#ifndef SIMPLE_GRAPHS_ELEMENT_H
#define SIMPLE_GRAPHS_ELEMENT_H


class Element {
private:
    int value;

public:
    Element &operator=(int newValue);
    void operator+=(int addValue);
    [[nodiscard]] bool hasValue() const;
    [[nodiscard]] int getValue() const;
};


#endif //SIMPLE_GRAPHS_ELEMENT_H

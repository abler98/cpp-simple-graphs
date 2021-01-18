#include "Element.h"

Element &Element::operator=(int newValue) {
    this->value = newValue;

    return *this;
}

void Element::operator+=(int addValue) {
    this->value += addValue;
}

bool Element::hasValue() const {
    return this->value > 0;
}

int Element::getValue() const {
    return this->value;
}

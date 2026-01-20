#include "dot.hpp"
#include <stdexcept>
top::Dot::Dot(p_t dd):
 IDraw(),
 d{dd}
{}

top::p_t top::Dot::begin() const {
	return d;
}

top::p_t top::Dot::next(p_t prev) const {
	if (prev != d){
		throw std::logic_error("bad prev");
	}
	return d;
}

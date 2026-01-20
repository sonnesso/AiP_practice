#include "frect.hpp"
#include <stdexcept>
top::FRect::FRect(p_t pos, int w, int h) : rect{pos, {pos.x + w, pos.y + h}}, IDraw()
{
	if (w <= 0 or h <= 0){
		throw std::logic_error("bad filled rect");
	}
}

top::FRect::FRect(p_t a, p_t b) : FRect(a, b.x - a.x, b.y - a.y)
{}
top::p_t top::FRect::begin() const {
	return rect.aa;
}

top::p_t top::FRect::next(p_t prev) const
{
	if (prev.x < rect.bb.x){
		return {prev.x + 1, prev.y};
	}
	if (prev.x == rect.bb.x && prev.y < rect.bb.y){
		return {rect.aa.x, prev.y + 1};
	}
	if (prev == rect.bb){
		return rect.aa;
	}
	throw std::logic_error("bad filled impl");
}

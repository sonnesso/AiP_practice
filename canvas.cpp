#include "canvas.hpp"
#include <iostream>
void top::paint(p_t p, char * cnv, f_t fr, char fill)
{
	size_t dx = p.x - fr.aa.x;
	size_t dy = fr.bb.y - p.y;
	cnv[dy * cols(fr) + dx] = fill;
}

void top::flush(std::ostream& os, const char * cnv, f_t fr)
{
	for (size_t i = 0; i < rows(fr); ++i){
		for (size_t j = 0; j < cols(fr); ++j){
			os << cnv[i * cols(fr) + j];
		}
		os << '\n';
	}
}

char * top::canvas(f_t fr, char fill)
{
	size_t s = rows(fr) * cols(fr);
	char * c = new char [s];
	for (size_t i = 0; i < s; ++i){
		c[i] = fill;
	}
	return c;
}

top::Layers::Layers():
	points_{0},
	pts_(nullptr),
	layers_{0},
	sizes_{nullptr}
{}

top::Layers::~Layers()
{
	delete[] pts_;
	delete[] sizes_;
}

void top::Layers::append(const IDraw& dr){
	size_t * ext_sizes = new size_t[layers_ + 1];
	try {
		top::append(&dr, &pts_, points_);
	} catch (...) {
		delete [] ext_sizes;
		throw;
	}
	for (size_t i = 0; i < layers_; ++i){
		ext_sizes[i] = sizes_[i];
	}
	ext_sizes[layers_] = points_;
	delete[] sizes_;
	sizes_ = ext_sizes;
	++layers_;
}

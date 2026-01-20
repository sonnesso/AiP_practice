#ifndef CANVAS_HPP
#define CANVAS_HPP
#include "idraw.hpp"
#include <iosfwd>
namespace top
{
    void flush(std::ostream& os, const char * cnv, f_t fr);
    void paint(p_t p, char * cnv, f_t fr, char fill);
    char * canvas(f_t fr, char fill);
    struct Layers;
    struct Layers {
    	Layers();
    	~Layers();
    	Layers(const Layers&) = delete;
    	Layers& operator=(const Layers&) = delete;
    	Layers(Layers&&) = delete;
    	Layers& operator=(Layers&&) = delete;
    	
    	void append(const IDraw & dr);
    	f_t frame() const {
    		return top::frame(pts_, points_);
    	}
    	size_t points() const{
    		return points_;
    	}
    	size_t layers() const{
    		return layers_;
    	}
    	p_t point(size_t i) const{
    		return pts_[i];
    	}
    	size_t start(size_t i) const{
    		return !i ? 0 : sizes_[i-1];
    	}
    	size_t end(size_t i) const{
    		return sizes_[i];
    	}
      	private:
    		size_t points_;
    		p_t * pts_;
    		size_t layers_;
    		size_t * sizes_;
    };
}
#endif

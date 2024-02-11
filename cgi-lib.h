#ifndef __CGI_LIB_H
#define __CGI_LIB_H

// Important: Link with the library with -lcjacobcgi -static

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>

namespace CJacob314 {
namespace HTTP {

typedef uint16_t HttpCode;
enum ContentType {
	HTML,
	JSON,
	XML,
	TEXT,
	CSS,
	JAVASCRIPT,
	JPEG,
	PNG,
	GIF,
	SVG,
	ICO,
	MP4,
	WEBM,
	OGG,
	UNKNOWN
};

void send_page(HttpCode, ContentType, const std::string&);
void send_page(ContentType, const std::string&);
void send_page(const std::string&);

} // namespace HTTP
} // namespace CJacob314

// Global namespace class for $("variable-name-here") to get environment variables
class $ {
	std::string var_data;
	public:
	// Constructors to create class which coerces into `std::string` of environment variable
	template<std::size_t N>
	$(const char (&s)[N]){
		char* ptr = std::getenv(s);
		if(ptr) {
			var_data = ptr;
		} else {
			var_data = "";
		}
	}
	template<std::size_t N>
	$(const std::string& s){
		char* ptr = std::getenv(s.c_str());
		if(ptr) {
			var_data = ptr;
		} else {
			var_data = "";
		}
	}
	// Default destructor
	~$() = default;

	// Coerce into `std::string` of environment variable
	operator std::string() const {
		return var_data;
	}
};
#endif // __CGI_LIB_H

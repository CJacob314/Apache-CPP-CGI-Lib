#ifndef __CGI_LIB_H
#define __CGI_LIB_H

// Important: Link with the library with -lcjacobcgi -static

#include <iostream>
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
#endif // __CGI_LIB_H

#include "cgi-lib.h"

void CJacob314::HTTP::send_page(HttpCode httpCode, ContentType contentType, const std::string& content) {
    std::cout << "Status: " << httpCode << "\r\n";
    switch (contentType) {
    case HTML:
        std::cout << "Content-Type: text/html\r\n\r\n";
        break;
    case JSON:
        std::cout << "Content-Type: application/json\r\n\r\n";
        break;
    case XML:
        std::cout << "Content-Type: application/xml\r\n\r\n";
        break;
    case TEXT:
        std::cout << "Content-Type: text/plain\r\n\r\n";
        break;
    case CSS:
        std::cout << "Content-Type: text/css\r\n\r\n";
        break;
    case JAVASCRIPT:
        std::cout << "Content-Type: application/javascript\r\n\r\n";
        break;
    case JPEG:
        std::cout << "Content-Type: image/jpeg\r\n\r\n";
        break;
    case PNG:
        std::cout << "Content-Type: image/png\r\n\r\n";
        break;
    case GIF:
        std::cout << "Content-Type: image/gif\r\n\r\n";
        break;
    case SVG:
        std::cout << "Content-Type: image/svg+xml\r\n\r\n";
        break;
    case ICO:
        std::cout << "Content-Type: image/x-icon\r\n\r\n";
        break;
    case MP4:
        std::cout << "Content-Type: video/mp4\r\n\r\n";
        break;
    case WEBM:
        std::cout << "Content-Type: video/webm\r\n\r\n";
        break;
    case OGG:
        std::cout << "Content-Type: audio/ogg\r\n\r\n";
        break;
    case UNKNOWN:
    default:
        std::cout << "Content-Type: application/octet-stream\r\n\r\n";
        break;
    }

    std::cout << content;
}

void CJacob314::HTTP::send_page(ContentType contentType, const std::string& content) {
    send_page(200, contentType, content);
}

void CJacob314::HTTP::send_page(const std::string& content) {
    send_page(200, HTML, content);
}

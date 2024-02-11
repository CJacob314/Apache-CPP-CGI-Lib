# HTTP CGI Lib
This project was mostly made as a personal side-project to familiarize myself more with how Makefiles interact with Linux library/header file directories.

The idea is to compile C++ scripts with a command like the following (and configure your CGI-compliant server-hosting program accordingly) to have it serve your content through a compiled script (as opposed to, say,  interpreting PHP).

`g++ -O3 -o /path/to/live/server/dir/script.cgi src-file1.cpp src-file2.cpp -lcjacobcgi -static`

If you want easier-to-use speed, probably look to something like [HHVM](https://hhvm.com/).

## Installation
Clone the git repo, then, in the cloned directory, run `make` followed by `sudo make install`.

## Example Usage
```cpp
#include <string>
#include <cstdlib>
#include <cgi-lib.h>

using namespace CJacob314::HTTP;

int main(void) {
    std::string ipAddr = $("REMOTE_ADDR");
    std::string userAgent = $("HTTP_USER_AGENT");
    std::string title = "<head><title>IP and User-Agent Info</title></head>";

    send_page(200, HTML, title + "<body><h1>IP and User-Agent Info</h1><p>Your IP address is: " + ipAddr + "</p><p>Your User-Agent is: " + userAgent + "</p></body>");

    return 0;
}
```

### Uninstall
Go to your cloned directory (or clone again) and run `sudo make uninstall`.

#### Supported Content-Type Headers
 - HTML
 - JSON
 - XML
 - TEXT
 - CSS
 - JAVASCRIPT
 - JPEG
 - PNG
 - GIF
 - SVG
 - ICO
 - MP4
 - WEBM
 - OGG
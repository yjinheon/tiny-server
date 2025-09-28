#include "utils/http_utils.h"
#include <fstream>
#include <string>

using namespace std;

// ate : 파일 끝
// tellg : get current read position
// seekg : change the current read position
string read_file(const std::string &path) {
  ifstream file(path, ios::binary | ios::ate);
  if (!file) {
    return "";
  }
  auto size = file.tellg();
  file.seekg(0);
  string content(size, '\0');
  file.read(&content[0], size);
  return content;
}

string get_content_type(const std::string &path) {

  // find last of given separator
  string extension = path.substr(path.find_last_of(".") + 1);

  if (extension == "html")
    return "text/html";
  if (extension == "css")
    return "text/css";
  if (extension == "js")
    return "application/javascript";
  // Add more types if needed
  return "text/plain";
}

string create_response(const string &body, const string &content_type) {
  string header = "HTTP/1.1 200 OK\r\nContent-Type: " + content_type +
                  "\r\nContent-Length: ";
  header += to_string(body.size()) + "\r\n\r\n";
  return header + body;
}

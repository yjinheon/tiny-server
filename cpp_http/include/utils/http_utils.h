#ifdef HTTP_UTILS_H
#define HTTP_UTILS_H

#include <string>

std::string read_file(const std::string &path);
std::string create_response(const std::string &body,
                            const std::string &content_type);
std::string get_content_type(const std::string &path);

#endif

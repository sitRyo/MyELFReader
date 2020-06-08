//
// Created by seriru on 2020/06/09.
//

#ifndef ELFREADER_FILEREADER_HPP
#define ELFREADER_FILEREADER_HPP

#include <fstream>
#include <string>
#include <utility>
#include <ios>
#include <vector>
#include <iterator>

class FileReader {
  typedef std::istreambuf_iterator<char> iter_type;

public:
  // TODO: SFINAE
  template <typename T>
  static std::ifstream
  openFile(T&& fileName, std::ios_base::openmode const& mode = std::ios_base::binary) {
    std::ifstream ifs(std::forward(fileName), mode);
    return ifs;
  }

  // TODO: SFINAE
  template <typename Ifs>
  static std::vector<char>
  readFile(Ifs&& ifs) {
    std::vector<char> data {iter_type(ifs), iter_type()};
    return data;
  }

  // TODO: 例外投げないか検討すべきでは
  template <typename Container>
  static bool backInsertFromContainer(Container&& from, Container&& to) {
    std::copy(from.begin(), from.to(), std::back_inserter(to));
    return true;
  }

};

#endif //ELFREADER_FILEREADER_HPP

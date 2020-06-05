//
// Created by seriru on 2020/06/05.
//

#ifndef ELFREADER_COMMANDLINEPARSERINTERFACE_HPP
#define ELFREADER_COMMANDLINEPARSERINTERFACE_HPP

#include <unordered_map>
#include <string>

#include "CmdOptionData.hpp"

namespace myelf {

  using CmdOptionMap = std::unordered_map<std::string, std::string>;

  /**
   * @brief Parser Interface
   */
  class CommandLineParserInterface {
  protected:
    std::vector<CmdOptionData> cmdOptionMap;
  public:
    virtual void setCmdOption(std::vector<CmdOptionData> const&) = 0;
    virtual CmdOptionMap parserCmdOption(int, char**) = 0;
  };

} // namespace myelf


#endif //ELFREADER_COMMANDLINEPARSERINTERFACE_HPP

//
// Created by seriru on 2020/06/05.
//

#ifndef ELFREADER_CMDPARSER_HPP
#define ELFREADER_CMDPARSER_HPP

#include "CommandLineParserInterface.hpp"
#include "cmdline.h"

namespace myelf {

  class CmdParser : public CommandLineParserInterface {
  private:
    cmdline::parser option_register;

    inline void
    setCmdlineOption() {
      // コマンドラインオプションをセットする。
      for (auto& option : this->cmdOptionMap) {
        option_register.add(option.longOption_, option.shortOption_, option.helpDescription_);
      }
    }

  public:
    void
    setCmdOption(std::vector<CmdOptionData> const& cmdOptionMap) override {
      this->cmdOptionMap = cmdOptionMap;
    }

    CmdOptionMap
    parserCmdOption(int argc, char** argv) override {
      // parser run
      option_register.parse_check(argc, argv);

      // オプションが存在すれば "in"
      CmdOptionMap cmdOptionMap;
      for (auto& option : this->cmdOptionMap) {
        cmdOptionMap.insert({option.longOption_, "in"});
      }

      return cmdOptionMap;
    }
  };

}

#endif //ELFREADER_CMDPARSER_HPP

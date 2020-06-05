//
// Created by seriru on 2020/06/04.
//

#ifndef ELFREADER_ELFPARSER_HPP
#define ELFREADER_ELFPARSER_HPP

#include <elf.h>
#include <memory>
#include <vector>
#include <fstream>

#include "CommandLineParserInterface.hpp"
#include "CmdParser.hpp"
#include "CmdOptionData.hpp"

namespace myelf {

  class ELFParser {
    std::unique_ptr<CommandLineParserInterface> cmdParser_;

    CmdOptionMap cmdOptionMap_;
    std::vector<CmdOptionData> cmdOptionData_;

    std::ifstream ifs;

    /**
     * @brief parserの生成
     * @param argc
     * @param argv
     * @param cmdOptionData
     * @return parser
     */
    std::unique_ptr<CommandLineParserInterface>
    cmdParserFactory() {
      std::unique_ptr<CommandLineParserInterface> cmdlineParser;
      cmdlineParser.reset(new CmdParser);
      cmdlineParser->setCmdOption(cmdOptionData_);
      return cmdlineParser;
    }

    void
    process() {
      for (const auto& option : cmdOptionData_) {
        if (option.longOption_ == "header") {
          readHeader();
        } else if (option.longOption_ == "file") {
          ifs.open();
        }
      }
    }

    void
    readHeader() const noexcept {

    }

    void
    readELFFile() noexcept {

    }

  public:

    /**
     * @brief Constructor
     * @param cmdOptionData optionのデータ
     * @param argc
     * @param argv
     */
    ELFParser(std::vector<CmdOptionData> const& cmdOptionData, int argc, char** argv)
    : cmdOptionData_(cmdOptionData) {
      this->cmdParser_ = cmdParserFactory();
      cmdOptionMap_ = this->cmdParser_->parserCmdOption(argc, argv);
    }

    ~ELFParser() = default;

    void
    run() {
      this->process();
    }
  };
}



#endif //ELFREADER_ELFPARSER_HPP

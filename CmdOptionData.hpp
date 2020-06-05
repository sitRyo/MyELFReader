//
// Created by seriru on 2020/06/05.
//

#ifndef ELFREADER_CMDOPTIONDATA_HPP
#define ELFREADER_CMDOPTIONDATA_HPP

#include <string>

namespace myelf {

  /**
   * @brief commandLineに与えるオプションの情報
   */
  struct CmdOptionData {
    std::string longOption_; /// 2文字以上のオプション名
    char shortOption_; /// 1文字のオプション名 (char or null)
    std::string helpDescription_; /// helpのときに出現するデータ

    /// Constructor
    CmdOptionData(std::string longOption, char shortOption, std::string helpDescription)
    : longOption_(longOption), shortOption_(shortOption), helpDescription_(helpDescription) {}

    /// Destructor
    ~CmdOptionData() = default;

    /// Copy Constructor
    CmdOptionData& operator=(CmdOptionData const&) = default;
    CmdOptionData(CmdOptionData const&) = default;

    /// Move Constructor
    CmdOptionData& operator=(CmdOptionData&&) = default;
    CmdOptionData(CmdOptionData&&) = default;
  };

}

#endif //ELFREADER_CMDOPTIONDATA_HPP

//
// Created by seriru on 2020/06/04.
//

#include "ELFParser.hpp"
#include "CmdOptionData.hpp"

using namespace myelf;

int main(int argc, char** argv) {
  std::vector<CmdOptionData> optionData;
  optionData.push_back({"file", 'f', "読み込むファイルを指定."});
  optionData.push_back({"header", 'h', "elf headerを表示する."});
  optionData.push_back({"help", '?', "このメッセージを表示."});

  ELFParser parser {optionData, argc, argv};
}
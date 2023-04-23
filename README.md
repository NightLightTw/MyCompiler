# MyCompiler
A simple C compiler.

## 第一次會議記錄
平台: ubuntu、github協作做版本管理，保證流程正確、保存編輯紀錄
- 工具: LLVM、Flex、Bison
- 語言: c++編譯器
- 目標: 完整性>速度>額外擴充 (可參考 https://github.com/AnjaneyaTripathi/c-compiler)
- 分工:
    - 凱毅: 詞法分析器(Lexer)和語法分析器(Parser)
    - 紀如: 語義分析、LLVM中間碼生成
    - 子中: 優化和代碼生成、版本管理、統整(ppt、word、github，若工作量太大可再討論如何分工)
- 日程分配:
    1. 預計5/22報告
    2. 第三個禮拜(5/7-5/13那週)要有成品
    3. 5/12第一次測試 (PM 8:00線上討論測試)
    4. 5/19第二次測試加最後確認(PM 8:00線上討論測試)
    5. 5/20、5/21做ppt和word
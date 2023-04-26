# MyCompiler
A simple C compiler.
## 實作架構
![](https://i.imgur.com/UNZYE8c.png)

- 平台: ubuntu、github協作做版本管理，保證流程正確、保存編輯紀錄
- 工具: LLVM、Flex、Bison
- 語言: c++編譯器
- 目標: 完整性>速度>額外擴充 (可參考 https://github.com/AnjaneyaTripathi/c-compiler, https://medium.com/@zetavg/%E7%B7%A8%E8%AD%AF%E5%99%A8-llvm-%E6%B7%BA%E6%B7%BA%E7%8E%A9-42a58c7a7309#1000)
## 分工
### 凱毅: 
詞法分析器(Lexer)和語法分析器(Parser) 工具：Yacc、Lex/FLex、Bison
- 詞法分析器，將源代碼分解為 tokens 的規則和實現。
- 語法分析器，將 tokens 組織成抽象語法樹（AST）的規則和實現。
- 錯誤報告機制，用於處理語法錯誤和提示。
### 紀如: 
語義分析、LLVM中間碼生成 工具:LLVM
- 型別檢查和語義檢查的實現，以確保代碼的合法性。
- 符號表（Symbol Table），用於存儲變量和函數的信息。
- 將AST轉換為中間表示（IR）的方法，轉換為LLVM IR。
### 子中:
優化和代碼生成、版本管理、統整(ppt、word、github、協調分工) 工具:LLVM
- 選擇和實現針對IR的優化方法，如常量傳播、死代碼消除等。
- 將優化後的IR轉換為目標平台的機器碼或組合語言的方法。  
## 日程分配
1. 預計5/22報告
2. 第三個禮拜(5/7-5/13那週)要有成品
3. 5/12第一次測試 (PM 8:00線上討論測試)
4. 5/19第二次測試加最後確認(PM 8:00線上討論測試)
5. 5/20、5/21做ppt和word

## Implementation (LEX + YACC)
### Requirement
```
sudo apt-get install flex bison
```

### Commands
```
lex lexer.l
yacc -d parser.y
cc lex.yy.c y.tab.c
./a.out < input1.c
```

For more information, please visit [here](https://github.com/AnjaneyaTripathi/c-compiler/blob/a1818231840cea321e701957ff0a0dfa2472a159/README.md).

## Implementation (LLVM + CLANG)
### Requirement
```
sudo apt-get install clang llvm
```

### Commands
```
clang -S -emit-llvm -Xclang -disable-O0-optnone input4.c
opt -S -mem2reg input4.ll -o input4_opt.ll
llc input4.ll -o input4_llvm.s
llc input4_opt.ll -o input4_opt_llvm.s
gcc -S input4.c -o input_gcc.s
```

For more information, please visit below links: 
* [LLVM-Clang编译器安装和使用](https://blog.csdn.net/rikeyone/article/details/100020145)
* [編譯器 LLVM 淺淺玩](https://medium.com/@zetavg/%E7%B7%A8%E8%AD%AF%E5%99%A8-llvm-%E6%B7%BA%E6%B7%BA%E7%8E%A9-42a58c7a7309)
* [LLVM opt mem2reg has no effect](https://stackoverflow.com/questions/46513801/llvm-opt-mem2reg-has-no-effect)

#!/bin/bash

# 运行测试用例example.mem
echo "run testcase"
./build/egp01_simulator --verbose --load-file example.mem

# 编译依赖库
echo "compiler dependency package"
gcc -c src/instructions.c

# 确认代码是否为最新状态
echo "make sure the code up-to-date"
git status | grep clean

# 赋予权限
echo "Grant permissions to scripts"
chmod +x automatic.sh
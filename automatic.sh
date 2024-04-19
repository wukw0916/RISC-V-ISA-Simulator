#!/bin/bash

# 运行测试用例example.mem
echo "run testcase"
./build/egp01_simulator --verbose --load-file example.mem

# 下载运行opcode_generator工具的相关依赖库
echo "install yq"
pip3 install --user yq
echo "set envirment path"
curl -L 'https://github.com/stedolan/jq/releases/download/jq-1.6/jq-linux64' > $HOME/.local/bin/jq
echo "echo "Grant permissions to scripts""
chmod +x $HOME/.local/bin/jq
# Regenerate the opcodes
PATH="$HOME/.local/bin:$PATH" bash ./tools/opcode_generator

# 编译依赖库
echo "compiler dependency package"
gcc -c src/instructions.c

# 确认代码是否为最新状态
echo "make sure the code up-to-date"
git status | grep clean

# 赋予权限
echo "Grant permissions to scripts"
chmod +x automatic.sh
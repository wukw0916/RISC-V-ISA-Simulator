# #!/bin/bash

# # 运行测试用例example.mem
# echo "run testcase"
# ./build/egp01_simulator --verbose --load-file example.mem

# # 下载运行opcode_generator工具的相关依赖库
# echo "install yq"
# pip3 install --user yq
# echo "set envirment path"
# # curl -L 'https://github.com/stedolan/jq/releases/download/jq-1.6/jq-linux64' > $HOME/.local/bin/jq
# echo "echo "Grant permissions to scripts""
# chmod +x $HOME/.local/bin/jq
# # Regenerate the opcodes
# PATH="$HOME/.local/bin:$PATH" bash ./tools/opcode_generator

# # 编译依赖库
# echo "compiler dependency package"
# gcc -c src/instructions.c

# # 确认代码是否为最新状态
# echo "make sure the code up-to-date"
# git status | grep clean

# # 赋予权限
# echo "Grant permissions to scripts"
# chmod +x automatic.sh


#!/bin/bash

# Define a function for failure
FAIL() {
    echo "$@" >&2
    exit 1
}

# Compile the program
compile_program() {
    make
}

# Run example
run_example() {
    ./build/egp01_simulator --verbose --load-file example.mem
}

# build instruction_tests
build_instruction(){
    ./tools/run_all_instruction_tests build
}

# run instruction_tests
run_instruction(){
    ./tools/run_all_instruction_tests run
}

# Regenerate the code
run_generate_code(){
    ./tools/opcode_generator
}

# Compile generated code
compile_generated_code() {
    gcc -c src/instructions.c
}

# Fail if not up-to-date
fail_if_not_up_to_date() {
    git status | grep clean
}

# Compile instruction tests and run them
run_all_instruction_tests() {
    for i in tests/instructions/*.c ; do
        make "${i/.c}" || true
    done

    FAILING=0
    for i in tests/instructions/*.c ; do
        EXECUTABLE="${i/.c}"
        if [ -x "$EXECUTABLE" ] ; then
            if "$EXECUTABLE" ; then
                echo "$EXECUTABLE: SUCCESS" >&2
            else
                echo "$EXECUTABLE: FAILURE" >&2
                FAILING="$((FAILING+1))"
            fi
        else
            echo "$EXECUTABLE: DOES NOT EXIST" >&2
            FAILING="$((FAILING+1))"
        fi
    done
    exit "$((FAILING>0))"
}

# Main entry point
main() {
    compile_program
    run_example
    build_instruction
    run_instruction
    # run_generate_code
    compile_generated_code
    fail_if_not_up_to_date
    run_all_instruction_tests
}

# Execute the main function
main

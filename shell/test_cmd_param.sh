#!/bin/bash


#!/bin/bash

# 定义选项和对应操作
OPTSTRING=":ahv"

# 初始化变量
opt_a=0
opt_h=0
opt_v=0

# 使用 getopts 处理命令行参数
while getopts "$OPTSTRING" opt; do
    case $opt in
        a)
            opt_a=1
            ;;
        h)
            opt_h=1
            ;;
        v)
            opt_v=1
            ;;
        :)
            echo "Invalid option: -$OPTARG"
            exit 1
            ;;
    esac
done

# 处理普通参数
shift $((OPTIND-1))
for arg; do
    echo "普通参数:$arg"
done

# 根据选项设置执行相应操作
if [ $opt_a -eq 1 ]; then
    echo "选项 a 被设置"
fi

if [ $opt_h -eq 1 ]; then
    echo "选项 h 被设置"
fi

if [ $opt_v -eq 1 ]; then
    echo "选项 v 被设置"
fi

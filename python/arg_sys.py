import sys

if len(sys.argv) > 1:
    filename = sys.argv[1]
    print("读取的文件名是:", filename)
else:
    print("请提供文件名作为命令行参数")
